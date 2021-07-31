
// Generated from Kotlin.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "KotlinVisitor.h"


/**
 * This class provides an empty implementation of KotlinVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  KotlinBaseVisitor : public KotlinVisitor {
public:

  virtual antlrcpp::Any visitProg(KotlinParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun(KotlinParser::FunContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(KotlinParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitState(KotlinParser::StateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(KotlinParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPack(KotlinParser::PackContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImp(KotlinParser::ImpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfs(KotlinParser::IfsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFors(KotlinParser::ForsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhiles(KotlinParser::WhilesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClasss(KotlinParser::ClasssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClasses(KotlinParser::ClassesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInter(KotlinParser::InterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(KotlinParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssn(KotlinParser::AssnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(KotlinParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComment(KotlinParser::CommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNum(KotlinParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange(KotlinParser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }


};

