# makefile for Expr Evaluation in C++
PROG=Kotlin2Java
G4=Kotlin.g4

ANTLR4=java -jar /usr/local/lib/antlr-4.8-complete.jar -Dlanguage=Cpp -no-listener -visitor -o antlr4-cpp
ANTLR4_RUNTIME=/usr/local/include/antlr4-runtime
CFLAGS=-I. -I$(ANTLR4_RUNTIME)
LIBS=-lantlr4-runtime

ANTLR4DIR=antlr4-cpp
OBJ=Kotlin2Java.o $(ANTLR4DIR)/KotlinBaseVisitor.o $(ANTLR4DIR)/KotlinLexer.o $(ANTLR4DIR)/KotlinVisitor.o $(ANTLR4DIR)/KotlinParser.o

default: antlr $(PROG)
	
$(PROG): $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

%.o:	%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

antlr: $(G4)
	$(ANTLR4) $<

.PHONY: clean

clean:
	rm -f $(PROG) *.o $(ANTLR4DIR)/*.o *~ core

wipe:	clean
	rm -rf $(ANTLR4DIR)
	
