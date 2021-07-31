
// Generated from Kotlin.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "KotlinParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by KotlinParser.
 */
class  KotlinVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by KotlinParser.
   */
    virtual antlrcpp::Any visitProg(KotlinParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitFun(KotlinParser::FunContext *context) = 0;

    virtual antlrcpp::Any visitStatement(KotlinParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitState(KotlinParser::StateContext *context) = 0;

    virtual antlrcpp::Any visitExpr(KotlinParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitPack(KotlinParser::PackContext *context) = 0;

    virtual antlrcpp::Any visitImp(KotlinParser::ImpContext *context) = 0;

    virtual antlrcpp::Any visitIfs(KotlinParser::IfsContext *context) = 0;

    virtual antlrcpp::Any visitFors(KotlinParser::ForsContext *context) = 0;

    virtual antlrcpp::Any visitWhiles(KotlinParser::WhilesContext *context) = 0;

    virtual antlrcpp::Any visitClasss(KotlinParser::ClasssContext *context) = 0;

    virtual antlrcpp::Any visitClasses(KotlinParser::ClassesContext *context) = 0;

    virtual antlrcpp::Any visitInter(KotlinParser::InterContext *context) = 0;

    virtual antlrcpp::Any visitString(KotlinParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitAssn(KotlinParser::AssnContext *context) = 0;

    virtual antlrcpp::Any visitType(KotlinParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitComment(KotlinParser::CommentContext *context) = 0;

    virtual antlrcpp::Any visitNum(KotlinParser::NumContext *context) = 0;

    virtual antlrcpp::Any visitRange(KotlinParser::RangeContext *context) = 0;


};

