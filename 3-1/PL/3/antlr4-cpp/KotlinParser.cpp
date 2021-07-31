
// Generated from Kotlin.g4 by ANTLR 4.8


#include "KotlinVisitor.h"

#include "KotlinParser.h"


using namespace antlrcpp;
using namespace antlr4;

KotlinParser::KotlinParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

KotlinParser::~KotlinParser() {
  delete _interpreter;
}

std::string KotlinParser::getGrammarFileName() const {
  return "Kotlin.g4";
}

const std::vector<std::string>& KotlinParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& KotlinParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

KotlinParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KotlinParser::ProgContext::NEWLINE() {
  return getTokens(KotlinParser::NEWLINE);
}

tree::TerminalNode* KotlinParser::ProgContext::NEWLINE(size_t i) {
  return getToken(KotlinParser::NEWLINE, i);
}

std::vector<KotlinParser::FunContext *> KotlinParser::ProgContext::fun() {
  return getRuleContexts<KotlinParser::FunContext>();
}

KotlinParser::FunContext* KotlinParser::ProgContext::fun(size_t i) {
  return getRuleContext<KotlinParser::FunContext>(i);
}

std::vector<KotlinParser::AssnContext *> KotlinParser::ProgContext::assn() {
  return getRuleContexts<KotlinParser::AssnContext>();
}

KotlinParser::AssnContext* KotlinParser::ProgContext::assn(size_t i) {
  return getRuleContext<KotlinParser::AssnContext>(i);
}

std::vector<KotlinParser::ExprContext *> KotlinParser::ProgContext::expr() {
  return getRuleContexts<KotlinParser::ExprContext>();
}

KotlinParser::ExprContext* KotlinParser::ProgContext::expr(size_t i) {
  return getRuleContext<KotlinParser::ExprContext>(i);
}


size_t KotlinParser::ProgContext::getRuleIndex() const {
  return KotlinParser::RuleProg;
}


antlrcpp::Any KotlinParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::ProgContext* KotlinParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, KotlinParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KotlinParser::NEWLINE) {
      setState(38);
      match(KotlinParser::NEWLINE);
      setState(43);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KotlinParser::T__0)
      | (1ULL << KotlinParser::T__2)
      | (1ULL << KotlinParser::T__10)
      | (1ULL << KotlinParser::T__14)
      | (1ULL << KotlinParser::T__16)
      | (1ULL << KotlinParser::T__19)
      | (1ULL << KotlinParser::T__20)
      | (1ULL << KotlinParser::T__21)
      | (1ULL << KotlinParser::T__22)
      | (1ULL << KotlinParser::T__23)
      | (1ULL << KotlinParser::T__24)
      | (1ULL << KotlinParser::T__25)
      | (1ULL << KotlinParser::T__26)
      | (1ULL << KotlinParser::T__27)
      | (1ULL << KotlinParser::T__28)
      | (1ULL << KotlinParser::T__30)
      | (1ULL << KotlinParser::T__31)
      | (1ULL << KotlinParser::T__32)
      | (1ULL << KotlinParser::T__33)
      | (1ULL << KotlinParser::T__34)
      | (1ULL << KotlinParser::T__36)
      | (1ULL << KotlinParser::T__37)
      | (1ULL << KotlinParser::INT)
      | (1ULL << KotlinParser::REAL)
      | (1ULL << KotlinParser::ID)
      | (1ULL << KotlinParser::Decom)
      | (1ULL << KotlinParser::Com)
      | (1ULL << KotlinParser::TYPE))) != 0)) {
      setState(65);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(44);
        fun();
        setState(48);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == KotlinParser::NEWLINE) {
          setState(45);
          match(KotlinParser::NEWLINE);
          setState(50);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(51);
        assn();
        setState(55);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == KotlinParser::NEWLINE) {
          setState(52);
          match(KotlinParser::NEWLINE);
          setState(57);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 3: {
        setState(58);
        expr(0);
        setState(62);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == KotlinParser::NEWLINE) {
          setState(59);
          match(KotlinParser::NEWLINE);
          setState(64);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      }
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunContext ------------------------------------------------------------------

KotlinParser::FunContext::FunContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::AssnContext* KotlinParser::FunContext::assn() {
  return getRuleContext<KotlinParser::AssnContext>(0);
}

KotlinParser::StatementContext* KotlinParser::FunContext::statement() {
  return getRuleContext<KotlinParser::StatementContext>(0);
}

KotlinParser::ExprContext* KotlinParser::FunContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}


size_t KotlinParser::FunContext::getRuleIndex() const {
  return KotlinParser::RuleFun;
}


antlrcpp::Any KotlinParser::FunContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitFun(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::FunContext* KotlinParser::fun() {
  FunContext *_localctx = _tracker.createInstance<FunContext>(_ctx, getState());
  enterRule(_localctx, 2, KotlinParser::RuleFun);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(70);
      match(KotlinParser::T__0);
      setState(71);
      assn();
      setState(72);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(74);
      match(KotlinParser::T__0);
      setState(75);
      assn();
      setState(76);
      match(KotlinParser::T__1);
      setState(77);
      expr(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(79);
      match(KotlinParser::T__2);
      setState(80);
      assn();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

KotlinParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KotlinParser::StatementContext::NEWLINE() {
  return getTokens(KotlinParser::NEWLINE);
}

tree::TerminalNode* KotlinParser::StatementContext::NEWLINE(size_t i) {
  return getToken(KotlinParser::NEWLINE, i);
}

std::vector<KotlinParser::StateContext *> KotlinParser::StatementContext::state() {
  return getRuleContexts<KotlinParser::StateContext>();
}

KotlinParser::StateContext* KotlinParser::StatementContext::state(size_t i) {
  return getRuleContext<KotlinParser::StateContext>(i);
}


size_t KotlinParser::StatementContext::getRuleIndex() const {
  return KotlinParser::RuleStatement;
}


antlrcpp::Any KotlinParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::StatementContext* KotlinParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, KotlinParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(KotlinParser::T__3);
    setState(87);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(84);
        match(KotlinParser::NEWLINE); 
      }
      setState(89);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KotlinParser::T__0)
      | (1ULL << KotlinParser::T__2)
      | (1ULL << KotlinParser::T__3)
      | (1ULL << KotlinParser::T__10)
      | (1ULL << KotlinParser::T__14)
      | (1ULL << KotlinParser::T__16)
      | (1ULL << KotlinParser::T__19)
      | (1ULL << KotlinParser::T__20)
      | (1ULL << KotlinParser::T__21)
      | (1ULL << KotlinParser::T__22)
      | (1ULL << KotlinParser::T__23)
      | (1ULL << KotlinParser::T__24)
      | (1ULL << KotlinParser::T__25)
      | (1ULL << KotlinParser::T__26)
      | (1ULL << KotlinParser::T__27)
      | (1ULL << KotlinParser::T__28)
      | (1ULL << KotlinParser::T__30)
      | (1ULL << KotlinParser::T__31)
      | (1ULL << KotlinParser::T__32)
      | (1ULL << KotlinParser::T__33)
      | (1ULL << KotlinParser::T__34)
      | (1ULL << KotlinParser::T__36)
      | (1ULL << KotlinParser::T__37)
      | (1ULL << KotlinParser::INT)
      | (1ULL << KotlinParser::REAL)
      | (1ULL << KotlinParser::ID)
      | (1ULL << KotlinParser::Decom)
      | (1ULL << KotlinParser::Com)
      | (1ULL << KotlinParser::TYPE))) != 0)) {
      setState(90);
      state();
      setState(100);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(94);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KotlinParser::NEWLINE) {
            setState(91);
            match(KotlinParser::NEWLINE);
            setState(96);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(97);
          state(); 
        }
        setState(102);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
    }
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KotlinParser::NEWLINE) {
      setState(105);
      match(KotlinParser::NEWLINE);
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(111);
    match(KotlinParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateContext ------------------------------------------------------------------

KotlinParser::StateContext::StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::ExprContext* KotlinParser::StateContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}

KotlinParser::StateContext* KotlinParser::StateContext::state() {
  return getRuleContext<KotlinParser::StateContext>(0);
}

KotlinParser::FunContext* KotlinParser::StateContext::fun() {
  return getRuleContext<KotlinParser::FunContext>(0);
}


size_t KotlinParser::StateContext::getRuleIndex() const {
  return KotlinParser::RuleState;
}


antlrcpp::Any KotlinParser::StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitState(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::StateContext* KotlinParser::state() {
  StateContext *_localctx = _tracker.createInstance<StateContext>(_ctx, getState());
  enterRule(_localctx, 6, KotlinParser::RuleState);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KotlinParser::T__10:
      case KotlinParser::T__14:
      case KotlinParser::T__16:
      case KotlinParser::T__19:
      case KotlinParser::T__20:
      case KotlinParser::T__21:
      case KotlinParser::T__22:
      case KotlinParser::T__23:
      case KotlinParser::T__24:
      case KotlinParser::T__25:
      case KotlinParser::T__26:
      case KotlinParser::T__27:
      case KotlinParser::T__28:
      case KotlinParser::T__30:
      case KotlinParser::T__31:
      case KotlinParser::T__32:
      case KotlinParser::T__33:
      case KotlinParser::T__34:
      case KotlinParser::T__36:
      case KotlinParser::T__37:
      case KotlinParser::INT:
      case KotlinParser::REAL:
      case KotlinParser::ID:
      case KotlinParser::Decom:
      case KotlinParser::Com:
      case KotlinParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        expr(0);
        break;
      }

      case KotlinParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(114);
        match(KotlinParser::T__3);
        setState(115);
        state();
        setState(116);
        match(KotlinParser::T__4);
        break;
      }

      case KotlinParser::T__0:
      case KotlinParser::T__2: {
        enterOuterAlt(_localctx, 3);
        setState(118);
        fun();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

KotlinParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::NumContext* KotlinParser::ExprContext::num() {
  return getRuleContext<KotlinParser::NumContext>(0);
}

tree::TerminalNode* KotlinParser::ExprContext::ID() {
  return getToken(KotlinParser::ID, 0);
}

std::vector<KotlinParser::ExprContext *> KotlinParser::ExprContext::expr() {
  return getRuleContexts<KotlinParser::ExprContext>();
}

KotlinParser::ExprContext* KotlinParser::ExprContext::expr(size_t i) {
  return getRuleContext<KotlinParser::ExprContext>(i);
}

std::vector<KotlinParser::StringContext *> KotlinParser::ExprContext::string() {
  return getRuleContexts<KotlinParser::StringContext>();
}

KotlinParser::StringContext* KotlinParser::ExprContext::string(size_t i) {
  return getRuleContext<KotlinParser::StringContext>(i);
}

KotlinParser::CommentContext* KotlinParser::ExprContext::comment() {
  return getRuleContext<KotlinParser::CommentContext>(0);
}

KotlinParser::AssnContext* KotlinParser::ExprContext::assn() {
  return getRuleContext<KotlinParser::AssnContext>(0);
}

KotlinParser::IfsContext* KotlinParser::ExprContext::ifs() {
  return getRuleContext<KotlinParser::IfsContext>(0);
}

KotlinParser::ForsContext* KotlinParser::ExprContext::fors() {
  return getRuleContext<KotlinParser::ForsContext>(0);
}

KotlinParser::WhilesContext* KotlinParser::ExprContext::whiles() {
  return getRuleContext<KotlinParser::WhilesContext>(0);
}

KotlinParser::ClasssContext* KotlinParser::ExprContext::classs() {
  return getRuleContext<KotlinParser::ClasssContext>(0);
}

KotlinParser::InterContext* KotlinParser::ExprContext::inter() {
  return getRuleContext<KotlinParser::InterContext>(0);
}

KotlinParser::TypeContext* KotlinParser::ExprContext::type() {
  return getRuleContext<KotlinParser::TypeContext>(0);
}

KotlinParser::PackContext* KotlinParser::ExprContext::pack() {
  return getRuleContext<KotlinParser::PackContext>(0);
}

KotlinParser::ImpContext* KotlinParser::ExprContext::imp() {
  return getRuleContext<KotlinParser::ImpContext>(0);
}

KotlinParser::FunContext* KotlinParser::ExprContext::fun() {
  return getRuleContext<KotlinParser::FunContext>(0);
}

KotlinParser::RangeContext* KotlinParser::ExprContext::range() {
  return getRuleContext<KotlinParser::RangeContext>(0);
}


size_t KotlinParser::ExprContext::getRuleIndex() const {
  return KotlinParser::RuleExpr;
}


antlrcpp::Any KotlinParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


KotlinParser::ExprContext* KotlinParser::expr() {
   return expr(0);
}

KotlinParser::ExprContext* KotlinParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KotlinParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  KotlinParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, KotlinParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(181);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(122);
      num();
      break;
    }

    case 2: {
      setState(123);
      match(KotlinParser::ID);
      break;
    }

    case 3: {
      setState(124);
      match(KotlinParser::T__14);
      setState(126);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << KotlinParser::T__10)
        | (1ULL << KotlinParser::T__14)
        | (1ULL << KotlinParser::T__16)
        | (1ULL << KotlinParser::T__19)
        | (1ULL << KotlinParser::T__20)
        | (1ULL << KotlinParser::T__21)
        | (1ULL << KotlinParser::T__22)
        | (1ULL << KotlinParser::T__23)
        | (1ULL << KotlinParser::T__24)
        | (1ULL << KotlinParser::T__25)
        | (1ULL << KotlinParser::T__26)
        | (1ULL << KotlinParser::T__27)
        | (1ULL << KotlinParser::T__28)
        | (1ULL << KotlinParser::T__30)
        | (1ULL << KotlinParser::T__31)
        | (1ULL << KotlinParser::T__32)
        | (1ULL << KotlinParser::T__33)
        | (1ULL << KotlinParser::T__34)
        | (1ULL << KotlinParser::T__36)
        | (1ULL << KotlinParser::T__37)
        | (1ULL << KotlinParser::INT)
        | (1ULL << KotlinParser::REAL)
        | (1ULL << KotlinParser::ID)
        | (1ULL << KotlinParser::Decom)
        | (1ULL << KotlinParser::Com)
        | (1ULL << KotlinParser::TYPE))) != 0)) {
        setState(125);
        expr(0);
      }
      setState(128);
      match(KotlinParser::T__15);
      break;
    }

    case 4: {
      setState(129);
      match(KotlinParser::T__10);
      setState(130);
      expr(0);
      setState(131);
      match(KotlinParser::T__9);
      break;
    }

    case 5: {
      setState(133);
      match(KotlinParser::T__14);
      setState(134);
      string();
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KotlinParser::T__16) {
        setState(135);
        match(KotlinParser::T__16);
        setState(136);
        string();
        setState(141);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(142);
      match(KotlinParser::T__15);
      break;
    }

    case 6: {
      setState(144);
      comment();
      break;
    }

    case 7: {
      setState(145);
      assn();
      break;
    }

    case 8: {
      setState(146);
      match(KotlinParser::T__19);
      setState(148);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(147);
        expr(0);
        break;
      }

      }
      break;
    }

    case 9: {
      setState(150);
      match(KotlinParser::T__16);
      setState(151);
      expr(16);
      break;
    }

    case 10: {
      setState(152);
      match(KotlinParser::T__20);
      setState(153);
      ifs();
      break;
    }

    case 11: {
      setState(154);
      match(KotlinParser::T__21);
      setState(155);
      ifs();
      break;
    }

    case 12: {
      setState(156);
      match(KotlinParser::T__22);
      setState(157);
      ifs();
      break;
    }

    case 13: {
      setState(158);
      match(KotlinParser::T__23);
      setState(159);
      expr(12);
      break;
    }

    case 14: {
      setState(160);
      match(KotlinParser::T__24);
      setState(161);
      expr(11);
      break;
    }

    case 15: {
      setState(162);
      match(KotlinParser::T__25);
      break;
    }

    case 16: {
      setState(163);
      match(KotlinParser::T__26);
      setState(164);
      expr(9);
      break;
    }

    case 17: {
      setState(165);
      match(KotlinParser::T__27);
      setState(166);
      fors();
      break;
    }

    case 18: {
      setState(167);
      match(KotlinParser::T__28);
      setState(168);
      whiles();
      break;
    }

    case 19: {
      setState(170);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KotlinParser::T__30) {
        setState(169);
        match(KotlinParser::T__30);
      }
      setState(172);
      match(KotlinParser::T__31);
      setState(173);
      classs(0);
      break;
    }

    case 20: {
      setState(174);
      match(KotlinParser::T__32);
      setState(175);
      inter();
      break;
    }

    case 21: {
      setState(176);
      type();
      break;
    }

    case 22: {
      setState(177);
      match(KotlinParser::T__33);
      setState(178);
      pack();
      break;
    }

    case 23: {
      setState(179);
      match(KotlinParser::T__34);
      setState(180);
      imp();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(232);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(183);

          if (!(precpred(_ctx, 34))) throw FailedPredicateException(this, "precpred(_ctx, 34)");
          setState(184);
          _la = _input->LA(1);
          if (!(_la == KotlinParser::T__5

          || _la == KotlinParser::T__6)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(188);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KotlinParser::T__1) {
            setState(185);
            match(KotlinParser::T__1);
            setState(190);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(191);
          expr(35);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(192);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(193);
          _la = _input->LA(1);
          if (!(_la == KotlinParser::T__7

          || _la == KotlinParser::T__8)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(197);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KotlinParser::T__1) {
            setState(194);
            match(KotlinParser::T__1);
            setState(199);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(200);
          expr(34);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(201);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(202);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << KotlinParser::T__1)
            | (1ULL << KotlinParser::T__9)
            | (1ULL << KotlinParser::T__10)
            | (1ULL << KotlinParser::T__11))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(206);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KotlinParser::T__1) {
            setState(203);
            match(KotlinParser::T__1);
            setState(208);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(209);
          expr(33);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(210);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(211);
          match(KotlinParser::T__1);
          setState(212);
          expr(26);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(213);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(214);
          match(KotlinParser::T__17);
          setState(215);
          expr(25);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(216);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(217);
          expr(23);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(218);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(219);
          _la = _input->LA(1);
          if (!(_la == KotlinParser::T__12

          || _la == KotlinParser::T__13)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(220);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(221);
          match(KotlinParser::T__18);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(222);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(223);
          assn();
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(224);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(225);
          fun();
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(226);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(228);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == KotlinParser::T__11) {
            setState(227);
            match(KotlinParser::T__11);
          }
          setState(230);
          match(KotlinParser::T__29);
          setState(231);
          range(0);
          break;
        }

        } 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PackContext ------------------------------------------------------------------

KotlinParser::PackContext::PackContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::ExprContext* KotlinParser::PackContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}


size_t KotlinParser::PackContext::getRuleIndex() const {
  return KotlinParser::RulePack;
}


antlrcpp::Any KotlinParser::PackContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitPack(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::PackContext* KotlinParser::pack() {
  PackContext *_localctx = _tracker.createInstance<PackContext>(_ctx, getState());
  enterRule(_localctx, 10, KotlinParser::RulePack);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImpContext ------------------------------------------------------------------

KotlinParser::ImpContext::ImpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::ExprContext* KotlinParser::ImpContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}


size_t KotlinParser::ImpContext::getRuleIndex() const {
  return KotlinParser::RuleImp;
}


antlrcpp::Any KotlinParser::ImpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitImp(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::ImpContext* KotlinParser::imp() {
  ImpContext *_localctx = _tracker.createInstance<ImpContext>(_ctx, getState());
  enterRule(_localctx, 12, KotlinParser::RuleImp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfsContext ------------------------------------------------------------------

KotlinParser::IfsContext::IfsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::ExprContext* KotlinParser::IfsContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}

KotlinParser::StatementContext* KotlinParser::IfsContext::statement() {
  return getRuleContext<KotlinParser::StatementContext>(0);
}

KotlinParser::StateContext* KotlinParser::IfsContext::state() {
  return getRuleContext<KotlinParser::StateContext>(0);
}


size_t KotlinParser::IfsContext::getRuleIndex() const {
  return KotlinParser::RuleIfs;
}


antlrcpp::Any KotlinParser::IfsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitIfs(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::IfsContext* KotlinParser::ifs() {
  IfsContext *_localctx = _tracker.createInstance<IfsContext>(_ctx, getState());
  enterRule(_localctx, 14, KotlinParser::RuleIfs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(252);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(241);
      match(KotlinParser::T__14);
      setState(242);
      expr(0);
      setState(243);
      match(KotlinParser::T__15);
      setState(244);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(246);
      match(KotlinParser::T__14);
      setState(247);
      expr(0);
      setState(248);
      match(KotlinParser::T__15);
      setState(249);
      state();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(251);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForsContext ------------------------------------------------------------------

KotlinParser::ForsContext::ForsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::ExprContext* KotlinParser::ForsContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}

KotlinParser::StatementContext* KotlinParser::ForsContext::statement() {
  return getRuleContext<KotlinParser::StatementContext>(0);
}

KotlinParser::StateContext* KotlinParser::ForsContext::state() {
  return getRuleContext<KotlinParser::StateContext>(0);
}


size_t KotlinParser::ForsContext::getRuleIndex() const {
  return KotlinParser::RuleFors;
}


antlrcpp::Any KotlinParser::ForsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitFors(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::ForsContext* KotlinParser::fors() {
  ForsContext *_localctx = _tracker.createInstance<ForsContext>(_ctx, getState());
  enterRule(_localctx, 16, KotlinParser::RuleFors);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(254);
      match(KotlinParser::T__14);
      setState(255);
      expr(0);
      setState(256);
      match(KotlinParser::T__15);
      setState(257);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(259);
      match(KotlinParser::T__14);
      setState(260);
      expr(0);
      setState(261);
      match(KotlinParser::T__15);
      setState(262);
      state();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(264);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhilesContext ------------------------------------------------------------------

KotlinParser::WhilesContext::WhilesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::ExprContext* KotlinParser::WhilesContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}

KotlinParser::StatementContext* KotlinParser::WhilesContext::statement() {
  return getRuleContext<KotlinParser::StatementContext>(0);
}

KotlinParser::StateContext* KotlinParser::WhilesContext::state() {
  return getRuleContext<KotlinParser::StateContext>(0);
}


size_t KotlinParser::WhilesContext::getRuleIndex() const {
  return KotlinParser::RuleWhiles;
}


antlrcpp::Any KotlinParser::WhilesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitWhiles(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::WhilesContext* KotlinParser::whiles() {
  WhilesContext *_localctx = _tracker.createInstance<WhilesContext>(_ctx, getState());
  enterRule(_localctx, 18, KotlinParser::RuleWhiles);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(267);
      match(KotlinParser::T__14);
      setState(268);
      expr(0);
      setState(269);
      match(KotlinParser::T__15);
      setState(270);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(272);
      match(KotlinParser::T__14);
      setState(273);
      expr(0);
      setState(274);
      match(KotlinParser::T__15);
      setState(275);
      state();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(277);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClasssContext ------------------------------------------------------------------

KotlinParser::ClasssContext::ClasssContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KotlinParser::ClasssContext::ID() {
  return getTokens(KotlinParser::ID);
}

tree::TerminalNode* KotlinParser::ClasssContext::ID(size_t i) {
  return getToken(KotlinParser::ID, i);
}

KotlinParser::ExprContext* KotlinParser::ClasssContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}

KotlinParser::ClassesContext* KotlinParser::ClasssContext::classes() {
  return getRuleContext<KotlinParser::ClassesContext>(0);
}

std::vector<KotlinParser::ClasssContext *> KotlinParser::ClasssContext::classs() {
  return getRuleContexts<KotlinParser::ClasssContext>();
}

KotlinParser::ClasssContext* KotlinParser::ClasssContext::classs(size_t i) {
  return getRuleContext<KotlinParser::ClasssContext>(i);
}


size_t KotlinParser::ClasssContext::getRuleIndex() const {
  return KotlinParser::RuleClasss;
}


antlrcpp::Any KotlinParser::ClasssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitClasss(this);
  else
    return visitor->visitChildren(this);
}


KotlinParser::ClasssContext* KotlinParser::classs() {
   return classs(0);
}

KotlinParser::ClasssContext* KotlinParser::classs(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KotlinParser::ClasssContext *_localctx = _tracker.createInstance<ClasssContext>(_ctx, parentState);
  KotlinParser::ClasssContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, KotlinParser::RuleClasss, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(296);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(281);
      match(KotlinParser::ID);
      setState(282);
      match(KotlinParser::T__14);
      setState(283);
      expr(0);
      setState(284);
      match(KotlinParser::T__15);
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KotlinParser::T__16) {
        setState(285);
        match(KotlinParser::T__16);
        setState(286);
        match(KotlinParser::ID);
        setState(291);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(292);
      classes();
      break;
    }

    case 2: {
      setState(294);
      match(KotlinParser::ID);
      setState(295);
      classes();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(303);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ClasssContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleClasss);
        setState(298);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(299);
        match(KotlinParser::T__35);
        setState(300);
        classs(4); 
      }
      setState(305);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ClassesContext ------------------------------------------------------------------

KotlinParser::ClassesContext::ClassesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KotlinParser::ClassesContext::NEWLINE() {
  return getTokens(KotlinParser::NEWLINE);
}

tree::TerminalNode* KotlinParser::ClassesContext::NEWLINE(size_t i) {
  return getToken(KotlinParser::NEWLINE, i);
}

std::vector<KotlinParser::StateContext *> KotlinParser::ClassesContext::state() {
  return getRuleContexts<KotlinParser::StateContext>();
}

KotlinParser::StateContext* KotlinParser::ClassesContext::state(size_t i) {
  return getRuleContext<KotlinParser::StateContext>(i);
}


size_t KotlinParser::ClassesContext::getRuleIndex() const {
  return KotlinParser::RuleClasses;
}


antlrcpp::Any KotlinParser::ClassesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitClasses(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::ClassesContext* KotlinParser::classes() {
  ClassesContext *_localctx = _tracker.createInstance<ClassesContext>(_ctx, getState());
  enterRule(_localctx, 22, KotlinParser::RuleClasses);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(365);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KotlinParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(306);
        match(KotlinParser::T__3);
        setState(310);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(307);
            match(KotlinParser::NEWLINE); 
          }
          setState(312);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
        }
        setState(326);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << KotlinParser::T__0)
          | (1ULL << KotlinParser::T__2)
          | (1ULL << KotlinParser::T__3)
          | (1ULL << KotlinParser::T__10)
          | (1ULL << KotlinParser::T__14)
          | (1ULL << KotlinParser::T__16)
          | (1ULL << KotlinParser::T__19)
          | (1ULL << KotlinParser::T__20)
          | (1ULL << KotlinParser::T__21)
          | (1ULL << KotlinParser::T__22)
          | (1ULL << KotlinParser::T__23)
          | (1ULL << KotlinParser::T__24)
          | (1ULL << KotlinParser::T__25)
          | (1ULL << KotlinParser::T__26)
          | (1ULL << KotlinParser::T__27)
          | (1ULL << KotlinParser::T__28)
          | (1ULL << KotlinParser::T__30)
          | (1ULL << KotlinParser::T__31)
          | (1ULL << KotlinParser::T__32)
          | (1ULL << KotlinParser::T__33)
          | (1ULL << KotlinParser::T__34)
          | (1ULL << KotlinParser::T__36)
          | (1ULL << KotlinParser::T__37)
          | (1ULL << KotlinParser::INT)
          | (1ULL << KotlinParser::REAL)
          | (1ULL << KotlinParser::ID)
          | (1ULL << KotlinParser::Decom)
          | (1ULL << KotlinParser::Com)
          | (1ULL << KotlinParser::TYPE))) != 0)) {
          setState(313);
          state();
          setState(323);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(317);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == KotlinParser::NEWLINE) {
                setState(314);
                match(KotlinParser::NEWLINE);
                setState(319);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
              setState(320);
              state(); 
            }
            setState(325);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
          }
        }
        setState(331);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == KotlinParser::NEWLINE) {
          setState(328);
          match(KotlinParser::NEWLINE);
          setState(333);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(334);
        match(KotlinParser::T__4);
        break;
      }

      case KotlinParser::T__14: {
        enterOuterAlt(_localctx, 2);
        setState(335);
        match(KotlinParser::T__14);
        setState(339);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(336);
            match(KotlinParser::NEWLINE); 
          }
          setState(341);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        }
        setState(356);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << KotlinParser::T__0)
          | (1ULL << KotlinParser::T__2)
          | (1ULL << KotlinParser::T__3)
          | (1ULL << KotlinParser::T__10)
          | (1ULL << KotlinParser::T__14)
          | (1ULL << KotlinParser::T__16)
          | (1ULL << KotlinParser::T__19)
          | (1ULL << KotlinParser::T__20)
          | (1ULL << KotlinParser::T__21)
          | (1ULL << KotlinParser::T__22)
          | (1ULL << KotlinParser::T__23)
          | (1ULL << KotlinParser::T__24)
          | (1ULL << KotlinParser::T__25)
          | (1ULL << KotlinParser::T__26)
          | (1ULL << KotlinParser::T__27)
          | (1ULL << KotlinParser::T__28)
          | (1ULL << KotlinParser::T__30)
          | (1ULL << KotlinParser::T__31)
          | (1ULL << KotlinParser::T__32)
          | (1ULL << KotlinParser::T__33)
          | (1ULL << KotlinParser::T__34)
          | (1ULL << KotlinParser::T__36)
          | (1ULL << KotlinParser::T__37)
          | (1ULL << KotlinParser::INT)
          | (1ULL << KotlinParser::REAL)
          | (1ULL << KotlinParser::ID)
          | (1ULL << KotlinParser::Decom)
          | (1ULL << KotlinParser::Com)
          | (1ULL << KotlinParser::TYPE))) != 0)) {
          setState(342);
          state();
          setState(353);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KotlinParser::T__16) {
            setState(343);
            match(KotlinParser::T__16);
            setState(347);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == KotlinParser::NEWLINE) {
              setState(344);
              match(KotlinParser::NEWLINE);
              setState(349);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(350);
            state();
            setState(355);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(361);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == KotlinParser::NEWLINE) {
          setState(358);
          match(KotlinParser::NEWLINE);
          setState(363);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(364);
        match(KotlinParser::T__15);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterContext ------------------------------------------------------------------

KotlinParser::InterContext::InterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KotlinParser::InterContext::ID() {
  return getToken(KotlinParser::ID, 0);
}

KotlinParser::StatementContext* KotlinParser::InterContext::statement() {
  return getRuleContext<KotlinParser::StatementContext>(0);
}


size_t KotlinParser::InterContext::getRuleIndex() const {
  return KotlinParser::RuleInter;
}


antlrcpp::Any KotlinParser::InterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitInter(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::InterContext* KotlinParser::inter() {
  InterContext *_localctx = _tracker.createInstance<InterContext>(_ctx, getState());
  enterRule(_localctx, 24, KotlinParser::RuleInter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(KotlinParser::ID);
    setState(368);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

KotlinParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KotlinParser::StringContext::STRING() {
  return getToken(KotlinParser::STRING, 0);
}


size_t KotlinParser::StringContext::getRuleIndex() const {
  return KotlinParser::RuleString;
}


antlrcpp::Any KotlinParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::StringContext* KotlinParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 26, KotlinParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    match(KotlinParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssnContext ------------------------------------------------------------------

KotlinParser::AssnContext::AssnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KotlinParser::AssnContext::ID() {
  return getToken(KotlinParser::ID, 0);
}

KotlinParser::NumContext* KotlinParser::AssnContext::num() {
  return getRuleContext<KotlinParser::NumContext>(0);
}

KotlinParser::CommentContext* KotlinParser::AssnContext::comment() {
  return getRuleContext<KotlinParser::CommentContext>(0);
}

std::vector<KotlinParser::ExprContext *> KotlinParser::AssnContext::expr() {
  return getRuleContexts<KotlinParser::ExprContext>();
}

KotlinParser::ExprContext* KotlinParser::AssnContext::expr(size_t i) {
  return getRuleContext<KotlinParser::ExprContext>(i);
}


size_t KotlinParser::AssnContext::getRuleIndex() const {
  return KotlinParser::RuleAssn;
}


antlrcpp::Any KotlinParser::AssnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitAssn(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::AssnContext* KotlinParser::assn() {
  AssnContext *_localctx = _tracker.createInstance<AssnContext>(_ctx, getState());
  enterRule(_localctx, 28, KotlinParser::RuleAssn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(402);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(372);
      match(KotlinParser::ID);
      setState(373);
      match(KotlinParser::T__1);
      setState(374);
      num();
      setState(376);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
      case 1: {
        setState(375);
        comment();
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(378);
      match(KotlinParser::ID);
      setState(379);
      match(KotlinParser::T__35);
      setState(380);
      expr(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(381);
      match(KotlinParser::ID);
      setState(382);
      match(KotlinParser::T__35);
      setState(383);
      expr(0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(384);
      match(KotlinParser::T__36);
      setState(385);
      expr(0);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(386);
      match(KotlinParser::T__37);
      setState(387);
      expr(0);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(388);
      match(KotlinParser::ID);
      setState(389);
      expr(0);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(390);
      match(KotlinParser::ID);
      setState(391);
      expr(0);
      setState(392);
      match(KotlinParser::T__35);
      setState(393);
      expr(0);
      setState(395);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
      case 1: {
        setState(394);
        match(KotlinParser::T__38);
        break;
      }

      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(397);
      match(KotlinParser::ID);
      setState(398);
      match(KotlinParser::T__14);
      setState(399);
      expr(0);
      setState(400);
      match(KotlinParser::T__15);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

KotlinParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KotlinParser::TypeContext::TYPE() {
  return getTokens(KotlinParser::TYPE);
}

tree::TerminalNode* KotlinParser::TypeContext::TYPE(size_t i) {
  return getToken(KotlinParser::TYPE, i);
}


size_t KotlinParser::TypeContext::getRuleIndex() const {
  return KotlinParser::RuleType;
}


antlrcpp::Any KotlinParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::TypeContext* KotlinParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 30, KotlinParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(404);
      match(KotlinParser::TYPE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(405);
      match(KotlinParser::TYPE);
      setState(406);
      match(KotlinParser::T__10);
      setState(407);
      match(KotlinParser::TYPE);
      setState(408);
      match(KotlinParser::T__9);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

KotlinParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KotlinParser::CommentContext::Decom() {
  return getToken(KotlinParser::Decom, 0);
}

tree::TerminalNode* KotlinParser::CommentContext::Com() {
  return getToken(KotlinParser::Com, 0);
}


size_t KotlinParser::CommentContext::getRuleIndex() const {
  return KotlinParser::RuleComment;
}


antlrcpp::Any KotlinParser::CommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitComment(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::CommentContext* KotlinParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 32, KotlinParser::RuleComment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    _la = _input->LA(1);
    if (!(_la == KotlinParser::Decom

    || _la == KotlinParser::Com)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

KotlinParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KotlinParser::NumContext::INT() {
  return getToken(KotlinParser::INT, 0);
}

tree::TerminalNode* KotlinParser::NumContext::REAL() {
  return getToken(KotlinParser::REAL, 0);
}


size_t KotlinParser::NumContext::getRuleIndex() const {
  return KotlinParser::RuleNum;
}


antlrcpp::Any KotlinParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}

KotlinParser::NumContext* KotlinParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 34, KotlinParser::RuleNum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    _la = _input->LA(1);
    if (!(_la == KotlinParser::INT

    || _la == KotlinParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

KotlinParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KotlinParser::ExprContext* KotlinParser::RangeContext::expr() {
  return getRuleContext<KotlinParser::ExprContext>(0);
}

std::vector<KotlinParser::RangeContext *> KotlinParser::RangeContext::range() {
  return getRuleContexts<KotlinParser::RangeContext>();
}

KotlinParser::RangeContext* KotlinParser::RangeContext::range(size_t i) {
  return getRuleContext<KotlinParser::RangeContext>(i);
}


size_t KotlinParser::RangeContext::getRuleIndex() const {
  return KotlinParser::RuleRange;
}


antlrcpp::Any KotlinParser::RangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KotlinVisitor*>(visitor))
    return parserVisitor->visitRange(this);
  else
    return visitor->visitChildren(this);
}


KotlinParser::RangeContext* KotlinParser::range() {
   return range(0);
}

KotlinParser::RangeContext* KotlinParser::range(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KotlinParser::RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, parentState);
  KotlinParser::RangeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, KotlinParser::RuleRange, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(416);
    expr(0);
    _ctx->stop = _input->LT(-1);
    setState(429);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(427);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RangeContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRange);
          setState(418);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(419);
          match(KotlinParser::T__39);
          setState(420);
          range(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RangeContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRange);
          setState(421);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(422);
          match(KotlinParser::T__40);
          setState(423);
          range(4);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RangeContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRange);
          setState(424);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(425);
          match(KotlinParser::T__41);
          setState(426);
          range(3);
          break;
        }

        } 
      }
      setState(431);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool KotlinParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);
    case 10: return classsSempred(dynamic_cast<ClasssContext *>(context), predicateIndex);
    case 18: return rangeSempred(dynamic_cast<RangeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool KotlinParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 34);
    case 1: return precpred(_ctx, 33);
    case 2: return precpred(_ctx, 32);
    case 3: return precpred(_ctx, 25);
    case 4: return precpred(_ctx, 24);
    case 5: return precpred(_ctx, 22);
    case 6: return precpred(_ctx, 31);
    case 7: return precpred(_ctx, 23);
    case 8: return precpred(_ctx, 20);
    case 9: return precpred(_ctx, 17);
    case 10: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

bool KotlinParser::classsSempred(ClasssContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool KotlinParser::rangeSempred(RangeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 3);
    case 14: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> KotlinParser::_decisionToDFA;
atn::PredictionContextCache KotlinParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN KotlinParser::_atn;
std::vector<uint16_t> KotlinParser::_serializedATN;

std::vector<std::string> KotlinParser::_ruleNames = {
  "prog", "fun", "statement", "state", "expr", "pack", "imp", "ifs", "fors", 
  "whiles", "classs", "classes", "inter", "string", "assn", "type", "comment", 
  "num", "range"
};

std::vector<std::string> KotlinParser::_literalNames = {
  "", "'fun'", "'='", "'abstract fun'", "'{'", "'}'", "'*'", "'/'", "'+'", 
  "'-'", "'>'", "'<'", "'!'", "'++'", "'--'", "'('", "')'", "','", "'.'", 
  "'.*'", "'return'", "'if'", "'else'", "'else if'", "'&&'", "'||'", "'null'", 
  "'println'", "'for'", "'while'", "'in'", "'abstract'", "'class'", "'interface'", 
  "'package'", "'import'", "':'", "'var'", "'val'", "'?'", "'..'", "'step'", 
  "'downTo'"
};

std::vector<std::string> KotlinParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "NEWLINE", "INT", "REAL", "ID", "Decom", "Com", 
  "WS", "TYPE", "STRING", "ESC", "UNICODE", "HEX"
};

dfa::Vocabulary KotlinParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> KotlinParser::_tokenNames;

KotlinParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x38, 0x1b3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x3, 0x2, 
    0x7, 0x2, 0x2a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2d, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x31, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x34, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x38, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x3b, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3f, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x42, 0xb, 0x2, 0x7, 0x2, 0x44, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x47, 
    0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x54, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x58, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x5b, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x5f, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x62, 0xb, 0x4, 0x3, 0x4, 0x7, 0x4, 0x65, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x68, 0xb, 0x4, 0x5, 0x4, 0x6a, 0xa, 0x4, 0x3, 0x4, 0x7, 0x4, 
    0x6d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x70, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x7a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x81, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x8c, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x8f, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x97, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xad, 0xa, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0xb8, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0xbd, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xc0, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xc6, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0xc9, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xcf, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xd2, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xe7, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0xeb, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xee, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0xff, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x10c, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x119, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x7, 0xc, 0x122, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x125, 
    0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x12b, 0xa, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x130, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0x133, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x137, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x13a, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x13e, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x141, 0xb, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0x144, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x147, 0xb, 0xd, 0x5, 0xd, 
    0x149, 0xa, 0xd, 0x3, 0xd, 0x7, 0xd, 0x14c, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0x14f, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x154, 
    0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x157, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x7, 0xd, 0x15c, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x15f, 0xb, 0xd, 
    0x3, 0xd, 0x7, 0xd, 0x162, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x165, 0xb, 
    0xd, 0x5, 0xd, 0x167, 0xa, 0xd, 0x3, 0xd, 0x7, 0xd, 0x16a, 0xa, 0xd, 
    0xc, 0xd, 0xe, 0xd, 0x16d, 0xb, 0xd, 0x3, 0xd, 0x5, 0xd, 0x170, 0xa, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x17b, 0xa, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x18e, 0xa, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x195, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x19c, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x1ae, 0xa, 0x14, 
    0xc, 0x14, 0xe, 0x14, 0x1b1, 0xb, 0x14, 0x3, 0x14, 0x2, 0x5, 0xa, 0x16, 
    0x26, 0x15, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x2, 0x8, 0x3, 0x2, 
    0x8, 0x9, 0x3, 0x2, 0xa, 0xb, 0x4, 0x2, 0x4, 0x4, 0xc, 0xe, 0x3, 0x2, 
    0xf, 0x10, 0x3, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2e, 0x2f, 0x2, 0x1f9, 0x2, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x53, 0x3, 0x2, 0x2, 0x2, 0x6, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x79, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb7, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xef, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x12, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x16, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x18, 0x16f, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x171, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x174, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x194, 0x3, 0x2, 0x2, 0x2, 0x20, 0x19b, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x24, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2a, 0x7, 0x2d, 0x2, 0x2, 
    0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x32, 0x5, 
    0x4, 0x3, 0x2, 0x2f, 0x31, 0x7, 0x2d, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 0x39, 0x5, 0x1e, 0x10, 0x2, 0x36, 
    0x38, 0x7, 0x2d, 0x2, 0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x44, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x40, 0x5, 0xa, 0x6, 0x2, 0x3d, 0x3f, 0x7, 0x2d, 0x2, 
    0x2, 0x3e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x35, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x3, 0x2, 0x2, 
    0x49, 0x4a, 0x5, 0x1e, 0x10, 0x2, 0x4a, 0x4b, 0x5, 0x6, 0x4, 0x2, 0x4b, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x3, 0x2, 0x2, 0x4d, 0x4e, 
    0x5, 0x1e, 0x10, 0x2, 0x4e, 0x4f, 0x7, 0x4, 0x2, 0x2, 0x4f, 0x50, 0x5, 
    0xa, 0x6, 0x2, 0x50, 0x54, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x5, 
    0x2, 0x2, 0x52, 0x54, 0x5, 0x1e, 0x10, 0x2, 0x53, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x5, 0x3, 0x2, 0x2, 0x2, 0x55, 0x59, 0x7, 0x6, 0x2, 0x2, 0x56, 
    0x58, 0x7, 0x2d, 0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x66, 0x5, 0x8, 0x5, 0x2, 0x5d, 0x5f, 0x7, 0x2d, 0x2, 
    0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x65, 
    0x5, 0x8, 0x5, 0x2, 0x64, 0x60, 0x3, 0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6d, 0x7, 0x2d, 0x2, 0x2, 0x6c, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x7, 
    0x2, 0x2, 0x72, 0x7, 0x3, 0x2, 0x2, 0x2, 0x73, 0x7a, 0x5, 0xa, 0x6, 
    0x2, 0x74, 0x75, 0x7, 0x6, 0x2, 0x2, 0x75, 0x76, 0x5, 0x8, 0x5, 0x2, 
    0x76, 0x77, 0x7, 0x7, 0x2, 0x2, 0x77, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x7a, 0x5, 0x4, 0x3, 0x2, 0x79, 0x73, 0x3, 0x2, 0x2, 0x2, 0x79, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x7b, 0x7c, 0x8, 0x6, 0x1, 0x2, 0x7c, 0xb8, 0x5, 0x24, 
    0x13, 0x2, 0x7d, 0xb8, 0x7, 0x30, 0x2, 0x2, 0x7e, 0x80, 0x7, 0x11, 0x2, 
    0x2, 0x7f, 0x81, 0x5, 0xa, 0x6, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0xb8, 0x7, 0x12, 0x2, 0x2, 0x83, 0x84, 0x7, 0xd, 0x2, 0x2, 0x84, 0x85, 
    0x5, 0xa, 0x6, 0x2, 0x85, 0x86, 0x7, 0xc, 0x2, 0x2, 0x86, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x11, 0x2, 0x2, 0x88, 0x8d, 0x5, 0x1c, 
    0xf, 0x2, 0x89, 0x8a, 0x7, 0x13, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0x1c, 0xf, 
    0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 
    0x7, 0x12, 0x2, 0x2, 0x91, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x92, 0xb8, 0x5, 
    0x22, 0x12, 0x2, 0x93, 0xb8, 0x5, 0x1e, 0x10, 0x2, 0x94, 0x96, 0x7, 
    0x16, 0x2, 0x2, 0x95, 0x97, 0x5, 0xa, 0x6, 0x2, 0x96, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0xb8, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x99, 0x7, 0x13, 0x2, 0x2, 0x99, 0xb8, 0x5, 0xa, 0x6, 0x12, 
    0x9a, 0x9b, 0x7, 0x17, 0x2, 0x2, 0x9b, 0xb8, 0x5, 0x10, 0x9, 0x2, 0x9c, 
    0x9d, 0x7, 0x18, 0x2, 0x2, 0x9d, 0xb8, 0x5, 0x10, 0x9, 0x2, 0x9e, 0x9f, 
    0x7, 0x19, 0x2, 0x2, 0x9f, 0xb8, 0x5, 0x10, 0x9, 0x2, 0xa0, 0xa1, 0x7, 
    0x1a, 0x2, 0x2, 0xa1, 0xb8, 0x5, 0xa, 0x6, 0xe, 0xa2, 0xa3, 0x7, 0x1b, 
    0x2, 0x2, 0xa3, 0xb8, 0x5, 0xa, 0x6, 0xd, 0xa4, 0xb8, 0x7, 0x1c, 0x2, 
    0x2, 0xa5, 0xa6, 0x7, 0x1d, 0x2, 0x2, 0xa6, 0xb8, 0x5, 0xa, 0x6, 0xb, 
    0xa7, 0xa8, 0x7, 0x1e, 0x2, 0x2, 0xa8, 0xb8, 0x5, 0x12, 0xa, 0x2, 0xa9, 
    0xaa, 0x7, 0x1f, 0x2, 0x2, 0xaa, 0xb8, 0x5, 0x14, 0xb, 0x2, 0xab, 0xad, 
    0x7, 0x21, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x22, 
    0x2, 0x2, 0xaf, 0xb8, 0x5, 0x16, 0xc, 0x2, 0xb0, 0xb1, 0x7, 0x23, 0x2, 
    0x2, 0xb1, 0xb8, 0x5, 0x1a, 0xe, 0x2, 0xb2, 0xb8, 0x5, 0x20, 0x11, 0x2, 
    0xb3, 0xb4, 0x7, 0x24, 0x2, 0x2, 0xb4, 0xb8, 0x5, 0xc, 0x7, 0x2, 0xb5, 
    0xb6, 0x7, 0x25, 0x2, 0x2, 0xb6, 0xb8, 0x5, 0xe, 0x8, 0x2, 0xb7, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0x7d, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0x83, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0x92, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0x94, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xec, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0xba, 0xc, 0x24, 0x2, 0x2, 0xba, 0xbe, 0x9, 0x2, 0x2, 0x2, 0xbb, 0xbd, 
    0x7, 0x4, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xeb, 0x5, 0xa, 0x6, 0x25, 0xc2, 0xc3, 0xc, 0x23, 0x2, 0x2, 
    0xc3, 0xc7, 0x9, 0x3, 0x2, 0x2, 0xc4, 0xc6, 0x7, 0x4, 0x2, 0x2, 0xc5, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 
    0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xeb, 0x5, 0xa, 
    0x6, 0x24, 0xcb, 0xcc, 0xc, 0x22, 0x2, 0x2, 0xcc, 0xd0, 0x9, 0x4, 0x2, 
    0x2, 0xcd, 0xcf, 0x7, 0x4, 0x2, 0x2, 0xce, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 
    0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xeb, 0x5, 0xa, 0x6, 0x23, 0xd4, 0xd5, 0xc, 
    0x1b, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x4, 0x2, 0x2, 0xd6, 0xeb, 0x5, 0xa, 
    0x6, 0x1c, 0xd7, 0xd8, 0xc, 0x1a, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x14, 0x2, 
    0x2, 0xd9, 0xeb, 0x5, 0xa, 0x6, 0x1b, 0xda, 0xdb, 0xc, 0x18, 0x2, 0x2, 
    0xdb, 0xeb, 0x5, 0xa, 0x6, 0x19, 0xdc, 0xdd, 0xc, 0x21, 0x2, 0x2, 0xdd, 
    0xeb, 0x9, 0x5, 0x2, 0x2, 0xde, 0xdf, 0xc, 0x19, 0x2, 0x2, 0xdf, 0xeb, 
    0x7, 0x15, 0x2, 0x2, 0xe0, 0xe1, 0xc, 0x16, 0x2, 0x2, 0xe1, 0xeb, 0x5, 
    0x1e, 0x10, 0x2, 0xe2, 0xe3, 0xc, 0x13, 0x2, 0x2, 0xe3, 0xeb, 0x5, 0x4, 
    0x3, 0x2, 0xe4, 0xe6, 0xc, 0x8, 0x2, 0x2, 0xe5, 0xe7, 0x7, 0xe, 0x2, 
    0x2, 0xe6, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x20, 0x2, 0x2, 0xe9, 
    0xeb, 0x5, 0x26, 0x14, 0x2, 0xea, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xea, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xea, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xea, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x5, 
    0xa, 0x6, 0x2, 0xf0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x5, 0xa, 
    0x6, 0x2, 0xf2, 0xf, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x11, 0x2, 
    0x2, 0xf4, 0xf5, 0x5, 0xa, 0x6, 0x2, 0xf5, 0xf6, 0x7, 0x12, 0x2, 0x2, 
    0xf6, 0xf7, 0x5, 0x6, 0x4, 0x2, 0xf7, 0xff, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0xf9, 0x7, 0x11, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0xa, 0x6, 0x2, 0xfa, 0xfb, 
    0x7, 0x12, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x8, 0x5, 0x2, 0xfc, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0xff, 0x5, 0x6, 0x4, 0x2, 0xfe, 0xf3, 0x3, 0x2, 
    0x2, 0x2, 0xfe, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0xff, 0x11, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 0x11, 0x2, 0x2, 
    0x101, 0x102, 0x5, 0xa, 0x6, 0x2, 0x102, 0x103, 0x7, 0x12, 0x2, 0x2, 
    0x103, 0x104, 0x5, 0x6, 0x4, 0x2, 0x104, 0x10c, 0x3, 0x2, 0x2, 0x2, 
    0x105, 0x106, 0x7, 0x11, 0x2, 0x2, 0x106, 0x107, 0x5, 0xa, 0x6, 0x2, 
    0x107, 0x108, 0x7, 0x12, 0x2, 0x2, 0x108, 0x109, 0x5, 0x8, 0x5, 0x2, 
    0x109, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x5, 0x6, 0x4, 0x2, 
    0x10b, 0x100, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x105, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x10d, 
    0x10e, 0x7, 0x11, 0x2, 0x2, 0x10e, 0x10f, 0x5, 0xa, 0x6, 0x2, 0x10f, 
    0x110, 0x7, 0x12, 0x2, 0x2, 0x110, 0x111, 0x5, 0x6, 0x4, 0x2, 0x111, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x11, 0x2, 0x2, 0x113, 
    0x114, 0x5, 0xa, 0x6, 0x2, 0x114, 0x115, 0x7, 0x12, 0x2, 0x2, 0x115, 
    0x116, 0x5, 0x8, 0x5, 0x2, 0x116, 0x119, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x119, 0x5, 0x6, 0x4, 0x2, 0x118, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x8, 0xc, 0x1, 0x2, 0x11b, 0x11c, 
    0x7, 0x30, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x11, 0x2, 0x2, 0x11d, 0x11e, 
    0x5, 0xa, 0x6, 0x2, 0x11e, 0x123, 0x7, 0x12, 0x2, 0x2, 0x11f, 0x120, 
    0x7, 0x13, 0x2, 0x2, 0x120, 0x122, 0x7, 0x30, 0x2, 0x2, 0x121, 0x11f, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x125, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 
    0x5, 0x18, 0xd, 0x2, 0x127, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 
    0x7, 0x30, 0x2, 0x2, 0x129, 0x12b, 0x5, 0x18, 0xd, 0x2, 0x12a, 0x11a, 
    0x3, 0x2, 0x2, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x131, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0xc, 0x5, 0x2, 0x2, 0x12d, 0x12e, 
    0x7, 0x26, 0x2, 0x2, 0x12e, 0x130, 0x5, 0x16, 0xc, 0x6, 0x12f, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 0x138, 0x7, 
    0x6, 0x2, 0x2, 0x135, 0x137, 0x7, 0x2d, 0x2, 0x2, 0x136, 0x135, 0x3, 
    0x2, 0x2, 0x2, 0x137, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x148, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x145, 0x5, 
    0x8, 0x5, 0x2, 0x13c, 0x13e, 0x7, 0x2d, 0x2, 0x2, 0x13d, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x13e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 
    0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x142, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x144, 0x5, 
    0x8, 0x5, 0x2, 0x143, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x144, 0x147, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x146, 0x149, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 
    0x2, 0x2, 0x2, 0x148, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 
    0x2, 0x2, 0x2, 0x149, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14c, 0x7, 
    0x2d, 0x2, 0x2, 0x14b, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14f, 0x3, 
    0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 
    0x2, 0x2, 0x2, 0x14e, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 
    0x2, 0x2, 0x2, 0x150, 0x170, 0x7, 0x7, 0x2, 0x2, 0x151, 0x155, 0x7, 
    0x11, 0x2, 0x2, 0x152, 0x154, 0x7, 0x2d, 0x2, 0x2, 0x153, 0x152, 0x3, 
    0x2, 0x2, 0x2, 0x154, 0x157, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x166, 0x3, 
    0x2, 0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x158, 0x163, 0x5, 
    0x8, 0x5, 0x2, 0x159, 0x15d, 0x7, 0x13, 0x2, 0x2, 0x15a, 0x15c, 0x7, 
    0x2d, 0x2, 0x2, 0x15b, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15f, 0x3, 
    0x2, 0x2, 0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 
    0x2, 0x2, 0x2, 0x15e, 0x160, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 
    0x2, 0x2, 0x2, 0x160, 0x162, 0x5, 0x8, 0x5, 0x2, 0x161, 0x159, 0x3, 
    0x2, 0x2, 0x2, 0x162, 0x165, 0x3, 0x2, 0x2, 0x2, 0x163, 0x161, 0x3, 
    0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x167, 0x3, 
    0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 0x158, 0x3, 
    0x2, 0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16b, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x16a, 0x7, 0x2d, 0x2, 0x2, 0x169, 0x168, 0x3, 
    0x2, 0x2, 0x2, 0x16a, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x169, 0x3, 
    0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16e, 0x3, 
    0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x170, 0x7, 
    0x12, 0x2, 0x2, 0x16f, 0x134, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x151, 0x3, 
    0x2, 0x2, 0x2, 0x170, 0x19, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x7, 0x30, 
    0x2, 0x2, 0x172, 0x173, 0x5, 0x6, 0x4, 0x2, 0x173, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x175, 0x7, 0x35, 0x2, 0x2, 0x175, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x176, 0x177, 0x7, 0x30, 0x2, 0x2, 0x177, 0x178, 0x7, 0x4, 0x2, 
    0x2, 0x178, 0x17a, 0x5, 0x24, 0x13, 0x2, 0x179, 0x17b, 0x5, 0x22, 0x12, 
    0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x17b, 0x195, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x30, 0x2, 
    0x2, 0x17d, 0x17e, 0x7, 0x26, 0x2, 0x2, 0x17e, 0x195, 0x5, 0xa, 0x6, 
    0x2, 0x17f, 0x180, 0x7, 0x30, 0x2, 0x2, 0x180, 0x181, 0x7, 0x26, 0x2, 
    0x2, 0x181, 0x195, 0x5, 0xa, 0x6, 0x2, 0x182, 0x183, 0x7, 0x27, 0x2, 
    0x2, 0x183, 0x195, 0x5, 0xa, 0x6, 0x2, 0x184, 0x185, 0x7, 0x28, 0x2, 
    0x2, 0x185, 0x195, 0x5, 0xa, 0x6, 0x2, 0x186, 0x187, 0x7, 0x30, 0x2, 
    0x2, 0x187, 0x195, 0x5, 0xa, 0x6, 0x2, 0x188, 0x189, 0x7, 0x30, 0x2, 
    0x2, 0x189, 0x18a, 0x5, 0xa, 0x6, 0x2, 0x18a, 0x18b, 0x7, 0x26, 0x2, 
    0x2, 0x18b, 0x18d, 0x5, 0xa, 0x6, 0x2, 0x18c, 0x18e, 0x7, 0x29, 0x2, 
    0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 
    0x2, 0x18e, 0x195, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x30, 0x2, 
    0x2, 0x190, 0x191, 0x7, 0x11, 0x2, 0x2, 0x191, 0x192, 0x5, 0xa, 0x6, 
    0x2, 0x192, 0x193, 0x7, 0x12, 0x2, 0x2, 0x193, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x176, 0x3, 0x2, 0x2, 0x2, 0x194, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x194, 0x182, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x184, 0x3, 0x2, 0x2, 0x2, 0x194, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x188, 0x3, 0x2, 0x2, 0x2, 0x194, 0x18f, 0x3, 0x2, 0x2, 
    0x2, 0x195, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x196, 0x19c, 0x7, 0x34, 0x2, 
    0x2, 0x197, 0x198, 0x7, 0x34, 0x2, 0x2, 0x198, 0x199, 0x7, 0xd, 0x2, 
    0x2, 0x199, 0x19a, 0x7, 0x34, 0x2, 0x2, 0x19a, 0x19c, 0x7, 0xc, 0x2, 
    0x2, 0x19b, 0x196, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x197, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x21, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x9, 0x6, 0x2, 0x2, 
    0x19e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x9, 0x7, 0x2, 0x2, 0x1a0, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x8, 0x14, 0x1, 0x2, 0x1a2, 
    0x1a3, 0x5, 0xa, 0x6, 0x2, 0x1a3, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
    0x1a5, 0xc, 0x6, 0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x2a, 0x2, 0x2, 0x1a6, 
    0x1ae, 0x5, 0x26, 0x14, 0x7, 0x1a7, 0x1a8, 0xc, 0x5, 0x2, 0x2, 0x1a8, 
    0x1a9, 0x7, 0x2b, 0x2, 0x2, 0x1a9, 0x1ae, 0x5, 0x26, 0x14, 0x6, 0x1aa, 
    0x1ab, 0xc, 0x4, 0x2, 0x2, 0x1ab, 0x1ac, 0x7, 0x2c, 0x2, 0x2, 0x1ac, 
    0x1ae, 0x5, 0x26, 0x14, 0x5, 0x1ad, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1ad, 
    0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1af, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x2b, 0x32, 0x39, 0x40, 0x43, 0x45, 0x53, 
    0x59, 0x60, 0x66, 0x69, 0x6e, 0x79, 0x80, 0x8d, 0x96, 0xac, 0xb7, 0xbe, 
    0xc7, 0xd0, 0xe6, 0xea, 0xec, 0xfe, 0x10b, 0x118, 0x123, 0x12a, 0x131, 
    0x138, 0x13f, 0x145, 0x148, 0x14d, 0x155, 0x15d, 0x163, 0x166, 0x16b, 
    0x16f, 0x17a, 0x18d, 0x194, 0x19b, 0x1ad, 0x1af, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

KotlinParser::Initializer KotlinParser::_init;
