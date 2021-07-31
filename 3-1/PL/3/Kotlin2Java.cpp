#include <iostream>
#include <queue>
#include <cstring>
#include "antlr4-cpp/KotlinBaseVisitor.h"
#include "antlr4-cpp/KotlinLexer.h"
#include "antlr4-cpp/KotlinParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;
using namespace antlrcpp;


class EvalVisitor : public KotlinBaseVisitor {
	public:
		int i=0;
		Any visitProg(KotlinParser::ProgContext *ctx){
			cout << ctx->getText() << " " << i++  << endl;		
	}

		Any visitFun(KotlinParser::FunContext *ctx){
			cout << "fun" << endl;
		}
		Any visitStatement(KotlinParser::StatementContext *ctx){

		}

		Any visitState(KotlinParser::StateContext *ctx){

		}

		Any visitExpr(KotlinParser::ExprContext *context){
		}

		Any visitPack(KotlinParser::PackContext *context){
		}


		Any visitImp(KotlinParser::ImpContext *context){
		}

		Any visitIfs(KotlinParser::IfsContext *context){
		}


		Any visitFors(KotlinParser::ForsContext *context){
		}

		Any visitWhiles(KotlinParser::WhilesContext *context){
		}

		Any visitClasss(KotlinParser::ClasssContext *context){
		}

		Any visitClasses(KotlinParser::ClassesContext *context){
		}


		Any visitInter(KotlinParser::InterContext *context){
		}

		Any visitString(KotlinParser::StringContext *context){
		}


		Any visitAssn(KotlinParser::AssnContext *context){
		}

		Any visitType(KotlinParser::TypeContext *context){
		}

		Any visitComment(KotlinParser::CommentContext *context){
		}

		Any visitNum(KotlinParser::NumContext *context){
		}

		Any visitRange(KotlinParser::RangeContext *context){
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

	cout << "---Kotlinession Evaluation with ANTLR listener---\n";
	ANTLRInputStream input(stream);
	KotlinLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	KotlinParser parser(&tokens);	

	stream.close();
//	KotlinParser::ProgContext* tree = parser.prog();  // Get parse tree
	// Print tree in Lisp style
//	cout<< tree->toStringTree(&parser) << endl; // Walk parse-tree and attach our listener

	tree::ParseTree *tree = parser.prog();

	//ParseTreeVisitor *a;
	EvalVisitor visitor;	
	visitor.visit(tree);
	//a->visit(tree);
	return 0;
}
