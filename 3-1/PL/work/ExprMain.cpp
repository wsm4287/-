#include <iostream>
#include <queue>
#include <cstring>
#include "antlr4-cpp/ExprBaseListener.h"
#include "antlr4-cpp/ExprLexer.h"
#include "antlr4-cpp/ExprParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

int wait;
string va;

class EvalListener : public ExprBaseListener {
	map<string, string> vars; // C++ STL stack for expression tree evaluation
	queue<string> q;
	stack<string> op;
	stack<double> evalStack;
	public:
		/*void exitProg(ExprParser::ProgContext *ctx) {
			cout<< "exitProg: " << endl; 
		}
		void exitExpr(ExprParser::ExprContext *ctx) {
			cout<< "exitExpr: " << endl; 
		}*/
		void visitTerminal(tree::TerminalNode *node) {
			cout <<"Terminal : " << node->getText() << endl;
			if(node->getSymbol() -> getType() == ExprLexer::ID){
				if(vars.find(node->getText().c_str()) == vars.end()){
					q.push(node->getText().c_str());
					vars.insert({node->getText().c_str(),"0"});
					va = node->getText();
				}
				else{
					auto iter = vars.find(node->getText().c_str());
					q.push(iter->second);
				}				
			}
			else if (node->getSymbol() -> getType() == ExprLexer::INT || node->getSymbol() -> getType() == ExprLexer::REAL){
				if(wait){
					auto iter = vars.find(va);
					iter -> second = node->getText().c_str();
				}
				else{
					q.push(node->getText().c_str());
				}
			}
			else{
				if(*node->getText().c_str() == ')'){
					while(*op.top().c_str() != '('){
						if(*op.top().c_str() != '(' && *op.top().c_str() != ')') {
							q.push(op.top());
							op.pop();
						}
					}
					op.pop();
				}
				if(*node->getText().c_str() == '+'){
					if(!op.empty()){
						if(*op.top().c_str() == '+' || *op.top().c_str() == '-' || *op.top().c_str() == '*' || *op.top().c_str() == '/'){
							q.push(op.top());
							op.pop();
						}
					}
					op.push(node->getText().c_str());
				}
				if(*node->getText().c_str() == '-'){
					if(!op.empty()){
						if(*op.top().c_str() == '+' || *op.top().c_str() == '-' || *op.top().c_str() == '*' || *op.top().c_str() == '/'){
							q.push(op.top());
							op.pop();
						}
					}
					op.push(node->getText().c_str());
				}
				if(*node->getText().c_str() =='*'){
					if(!op.empty()){
						if(*op.top().c_str() == '*' || *op.top().c_str() == '/'){
							q.push(op.top());
							op.pop();
						}
					}
					op.push(node->getText().c_str());
				}
				if(*node->getText().c_str() == '/'){
					if(!op.empty()){
						if(*op.top().c_str() == '*' || *op.top().c_str() == '/'){
							q.push(op.top());
							op.pop();
						}
					}
					op.push(node->getText().c_str());
				}
				if(*node->getText().c_str() == '('){
					op.push(node->getText().c_str());
				}
				if(*node->getText().c_str() == ';'){
					if(!wait){
						while(!op.empty()){
							q.push(op.top());
							op.pop();
						}
					}
					else{
						while(!q.empty()) q.pop();
						auto iter = vars.find(va);
						q.push(iter->second);
					}
				}
				if(*node->getText().c_str() == '='){
					if(!q.empty()) q.pop();
					wait = 1;
				}
				if(node->getSymbol() -> getType() == ExprLexer::NEWLINE){
					if(!wait){
						while(!q.empty()){
							const char *p;
							p = q.front().c_str();
							if(*p == '+' || *p == '-' || *p == '*' || *p == '/'){
								if(p[1] == NULL){
									double a = evalStack.top();
									evalStack.pop();
									double b = evalStack.top();
									evalStack.pop();
									if(*p == '+' ) evalStack.push(a+b);
									if(*p == '-' ) evalStack.push(b-a);
									if(*p == '*' ) evalStack.push(a*b);
									if(*p == '/' ) evalStack.push(b/a);
									q.pop();
								}
								else{
									double v = atof(p);
									evalStack.push(v);
									q.pop();
								}
							}
							else{
								double v =atof(p);
								evalStack.push(v);
								q.pop();
							}
						}
						cout << evalStack.top() << endl;
						evalStack.pop();
					}
					wait = 0;
				}		
			}
		}
	
};

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		cerr << "[Usage] " << argv[0] << "  <input-file>\n";
		exit(0);
	}
	std::ifstream stream;
	stream.open(argv[1]);
	if (stream.fail()) {
		cerr << argv[1] << " : file open fail\n";
		exit(0);
	}

	cout << "---Expression Evaluation with ANTLR listener---\n";
	ANTLRInputStream input(stream);
	ExprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ExprParser parser(&tokens);	

	ParseTree *tree = parser.prog();  // Get parse tree
	// Print tree in Lisp style
	cout<< tree->toStringTree(&parser) << endl; // Walk parse-tree and attach our listener

	//ParseTreeWalker walker;
	//EvalListener listener;	

	//walker.walk(&listener, parser.prog());
	stream.close();
}
