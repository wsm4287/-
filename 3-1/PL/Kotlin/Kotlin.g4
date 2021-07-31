grammar Kotlin;

// parser rules
prog : NEWLINE* (fun NEWLINE* | assn NEWLINE* | expr NEWLINE*)*;

fun:  'fun' assn statement
	| 'fun' assn '=' expr
	| 'abstract fun' assn
	;
statement: '{' NEWLINE* (state (NEWLINE* state)*)? NEWLINE* '}'
	;
state: expr
	| '{' state '}'
	| fun
	;
expr : expr ('*'|'/') ('=')* expr
	| expr ('+'|'-') ('=')* expr
	| expr ('>'|'<'|'!'|'=') ('=')* expr
	| expr ('++'|'--') 
	| num
	| ID
	| '(' expr? ')'
	| '<' expr '>'
	| '(' string (',' string)* ')'
	| expr '=' expr
	| expr '.' expr
	| expr '.*'
	| expr expr
	| comment
	| expr assn
	| assn
	| 'return' expr?
	| expr fun
	| ',' expr
	| 'if' ifs
	| 'else' ifs
	| 'else if' ifs
	| '&&' expr
	| '||' expr
	| 'null'
	| 'println' expr
	| 'for' fors
	| 'while' whiles
	| expr '!'? 'in' range
	| 'abstract'? 'class' classs
	| 'interface' inter
	| type
	| 'package' pack
	| 'import' imp
	;
pack: expr
	;
imp: expr
	;
ifs: '(' expr ')' statement
	| '(' expr ')' state
	| statement
	;
fors: '(' expr ')' statement
	| '(' expr ')' state
	| statement
	;
whiles: '(' expr ')' statement
	| '(' expr ')' state
	| statement
	;
classs: classs ':' classs
	| ID '(' expr ')' (',' ID)* classes 
	| ID classes
	;
classes:  '{' NEWLINE* (state (NEWLINE* state)*)? NEWLINE* '}'
	| '(' NEWLINE* (state (',' NEWLINE* state)*)? NEWLINE* ')'
	;

inter: ID statement
	;
string: STRING
	;
assn: ID '=' num (comment)?
	| ID ':' expr
	| ID ':' expr
	| 'var' expr
	| 'val' expr
	| ID expr
	| ID expr ':' expr ('?')?
	| ID '(' expr ')'
	;
type : TYPE
	| TYPE '<' TYPE '>'
	;
comment : Decom
	| Com
	;
num  : INT
	| REAL
	;
range : range '..' range
	| range 'step' range
	| range 'downTo' range
	| expr
	;
// lexerrules
NEWLINE: [\r\n]+ ;
INT: ('+'|'-')?[0-9]+ ;          
REAL: ('+'|'-')?[0-9]+'.'[0-9]* ; 
ID: [a-zA-Z0-9]+ ;
Decom: ('/*' (Decom | .)*? '*/');
Com : ('//' ~[\r\n]+); 
WS: [ \t\r]+ -> skip ;
TYPE: 'Int'|'String'|'Float'|'Any'|'List'|'Double'|'Boolean';
STRING
   : '"' (ESC | ~ ["\\])*  '"'
   ;

ESC
   : '\\' (["\\/bfnrt] | UNICODE)
   ;
UNICODE
   : 'u' HEX HEX HEX HEX
   ;
HEX
   : [0-9a-fA-F]
   ;
