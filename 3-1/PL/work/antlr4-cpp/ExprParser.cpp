
// Generated from Expr.g4 by ANTLR 4.8


#include "ExprListener.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::AssnContext *> ExprParser::ProgContext::assn() {
  return getRuleContexts<ExprParser::AssnContext>();
}

ExprParser::AssnContext* ExprParser::ProgContext::assn(size_t i) {
  return getRuleContext<ExprParser::AssnContext>(i);
}

std::vector<ExprParser::ExprContext *> ExprParser::ProgContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ProgContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ProgContext::NEWLINE() {
  return getTokens(ExprParser::NEWLINE);
}

tree::TerminalNode* ExprParser::ProgContext::NEWLINE(size_t i) {
  return getToken(ExprParser::NEWLINE, i);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}

void ExprParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ExprParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__5)
      | (1ULL << ExprParser::INT)
      | (1ULL << ExprParser::REAL)
      | (1ULL << ExprParser::ID))) != 0)) {
      setState(18);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(8);
        assn();
        setState(9);
        match(ExprParser::T__0);
        setState(11);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ExprParser::NEWLINE) {
          setState(10);
          match(ExprParser::NEWLINE);
        }
        break;
      }

      case 2: {
        setState(13);
        expr(0);
        setState(14);
        match(ExprParser::T__0);
        setState(16);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ExprParser::NEWLINE) {
          setState(15);
          match(ExprParser::NEWLINE);
        }
        break;
      }

      }
      setState(22);
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

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::NumContext* ExprParser::ExprContext::num() {
  return getRuleContext<ExprParser::NumContext>(0);
}

tree::TerminalNode* ExprParser::ExprContext::ID() {
  return getToken(ExprParser::ID, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::ExprContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(30);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::INT:
      case ExprParser::REAL: {
        setState(24);
        num();
        break;
      }

      case ExprParser::ID: {
        setState(25);
        match(ExprParser::ID);
        break;
      }

      case ExprParser::T__5: {
        setState(26);
        match(ExprParser::T__5);
        setState(27);
        expr(0);
        setState(28);
        match(ExprParser::T__6);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(40);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(38);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(32);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(33);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__1

          || _la == ExprParser::T__2)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(34);
          expr(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(35);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(36);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__3

          || _la == ExprParser::T__4)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(37);
          expr(5);
          break;
        }

        } 
      }
      setState(42);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssnContext ------------------------------------------------------------------

ExprParser::AssnContext::AssnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::AssnContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::NumContext* ExprParser::AssnContext::num() {
  return getRuleContext<ExprParser::NumContext>(0);
}


size_t ExprParser::AssnContext::getRuleIndex() const {
  return ExprParser::RuleAssn;
}

void ExprParser::AssnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssn(this);
}

void ExprParser::AssnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssn(this);
}

ExprParser::AssnContext* ExprParser::assn() {
  AssnContext *_localctx = _tracker.createInstance<AssnContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleAssn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(ExprParser::ID);
    setState(44);
    match(ExprParser::T__7);
    setState(45);
    num();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

ExprParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::NumContext::INT() {
  return getToken(ExprParser::INT, 0);
}

tree::TerminalNode* ExprParser::NumContext::REAL() {
  return getToken(ExprParser::REAL, 0);
}


size_t ExprParser::NumContext::getRuleIndex() const {
  return ExprParser::RuleNum;
}

void ExprParser::NumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNum(this);
}

void ExprParser::NumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNum(this);
}

ExprParser::NumContext* ExprParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleNum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    _la = _input->LA(1);
    if (!(_la == ExprParser::INT

    || _la == ExprParser::REAL)) {
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

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "prog", "expr", "assn", "num"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "';'", "'*'", "'/'", "'+'", "'-'", "'('", "')'", "'='"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "NEWLINE", "INT", "REAL", "ID", "WS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
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
    0x3, 0xf, 0x34, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xe, 
    0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x13, 0xa, 0x2, 0x7, 
    0x2, 0x15, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x18, 0xb, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x21, 
    0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x29, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x2c, 0xb, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x3, 
    0x4, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x5, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 
    0x6, 0x7, 0x3, 0x2, 0xc, 0xd, 0x2, 0x37, 0x2, 0x16, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x20, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x5, 0x6, 0x4, 0x2, 0xb, 0xd, 0x7, 0x3, 
    0x2, 0x2, 0xc, 0xe, 0x7, 0xb, 0x2, 0x2, 0xd, 0xc, 0x3, 0x2, 0x2, 0x2, 
    0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 0xe, 0x15, 0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 
    0x5, 0x4, 0x3, 0x2, 0x10, 0x12, 0x7, 0x3, 0x2, 0x2, 0x11, 0x13, 0x7, 
    0xb, 0x2, 0x2, 0x12, 0x11, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x13, 0x15, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0xf, 0x3, 0x2, 0x2, 0x2, 0x15, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x3, 0x2, 0x2, 0x2, 0x17, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 
    0x8, 0x3, 0x1, 0x2, 0x1a, 0x21, 0x5, 0x8, 0x5, 0x2, 0x1b, 0x21, 0x7, 
    0xe, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0x8, 0x2, 0x2, 0x1d, 0x1e, 0x5, 0x4, 
    0x3, 0x2, 0x1e, 0x1f, 0x7, 0x9, 0x2, 0x2, 0x1f, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x19, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x21, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x23, 0xc, 0x7, 0x2, 0x2, 0x23, 0x24, 0x9, 0x2, 0x2, 0x2, 0x24, 0x29, 
    0x5, 0x4, 0x3, 0x8, 0x25, 0x26, 0xc, 0x6, 0x2, 0x2, 0x26, 0x27, 0x9, 
    0x3, 0x2, 0x2, 0x27, 0x29, 0x5, 0x4, 0x3, 0x7, 0x28, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x25, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2d, 
    0x2e, 0x7, 0xe, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0xa, 0x2, 0x2, 0x2f, 0x30, 
    0x5, 0x8, 0x5, 0x2, 0x30, 0x7, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x9, 
    0x4, 0x2, 0x2, 0x32, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9, 0xd, 0x12, 0x14, 
    0x16, 0x20, 0x28, 0x2a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
