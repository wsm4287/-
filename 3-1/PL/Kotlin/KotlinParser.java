// Generated from Kotlin.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class KotlinParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, T__35=36, T__36=37, T__37=38, 
		T__38=39, T__39=40, T__40=41, T__41=42, NEWLINE=43, INT=44, REAL=45, ID=46, 
		Decom=47, Com=48, WS=49, TYPE=50, STRING=51, ESC=52, UNICODE=53, HEX=54;
	public static final int
		RULE_prog = 0, RULE_fun = 1, RULE_statement = 2, RULE_state = 3, RULE_expr = 4, 
		RULE_pack = 5, RULE_imp = 6, RULE_ifs = 7, RULE_fors = 8, RULE_whiles = 9, 
		RULE_classs = 10, RULE_classes = 11, RULE_inter = 12, RULE_string = 13, 
		RULE_assn = 14, RULE_type = 15, RULE_comment = 16, RULE_num = 17, RULE_range = 18;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "fun", "statement", "state", "expr", "pack", "imp", "ifs", "fors", 
			"whiles", "classs", "classes", "inter", "string", "assn", "type", "comment", 
			"num", "range"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'fun'", "'='", "'abstract fun'", "'{'", "'}'", "'*'", "'/'", "'+'", 
			"'-'", "'>'", "'<'", "'!'", "'++'", "'--'", "'('", "')'", "','", "'.'", 
			"'.*'", "'return'", "'if'", "'else'", "'else if'", "'&&'", "'||'", "'null'", 
			"'println'", "'for'", "'while'", "'in'", "'abstract'", "'class'", "'interface'", 
			"'package'", "'import'", "':'", "'var'", "'val'", "'?'", "'..'", "'step'", 
			"'downTo'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, "NEWLINE", "INT", "REAL", "ID", 
			"Decom", "Com", "WS", "TYPE", "STRING", "ESC", "UNICODE", "HEX"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Kotlin.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public KotlinParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgContext extends ParserRuleContext {
		public List<TerminalNode> NEWLINE() { return getTokens(KotlinParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(KotlinParser.NEWLINE, i);
		}
		public List<FunContext> fun() {
			return getRuleContexts(FunContext.class);
		}
		public FunContext fun(int i) {
			return getRuleContext(FunContext.class,i);
		}
		public List<AssnContext> assn() {
			return getRuleContexts(AssnContext.class);
		}
		public AssnContext assn(int i) {
			return getRuleContext(AssnContext.class,i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterProg(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitProg(this);
		}
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(41);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(38);
				match(NEWLINE);
				}
				}
				setState(43);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(67);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__2) | (1L << T__10) | (1L << T__14) | (1L << T__16) | (1L << T__19) | (1L << T__20) | (1L << T__21) | (1L << T__22) | (1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << T__26) | (1L << T__27) | (1L << T__28) | (1L << T__30) | (1L << T__31) | (1L << T__32) | (1L << T__33) | (1L << T__34) | (1L << T__36) | (1L << T__37) | (1L << INT) | (1L << REAL) | (1L << ID) | (1L << Decom) | (1L << Com) | (1L << TYPE))) != 0)) {
				{
				setState(65);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
				case 1:
					{
					setState(44);
					fun();
					setState(48);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(45);
						match(NEWLINE);
						}
						}
						setState(50);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				case 2:
					{
					setState(51);
					assn();
					setState(55);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(52);
						match(NEWLINE);
						}
						}
						setState(57);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				case 3:
					{
					setState(58);
					expr(0);
					setState(62);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==NEWLINE) {
						{
						{
						setState(59);
						match(NEWLINE);
						}
						}
						setState(64);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				}
				setState(69);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunContext extends ParserRuleContext {
		public AssnContext assn() {
			return getRuleContext(AssnContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public FunContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fun; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterFun(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitFun(this);
		}
	}

	public final FunContext fun() throws RecognitionException {
		FunContext _localctx = new FunContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_fun);
		try {
			setState(81);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(70);
				match(T__0);
				setState(71);
				assn();
				setState(72);
				statement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(74);
				match(T__0);
				setState(75);
				assn();
				setState(76);
				match(T__1);
				setState(77);
				expr(0);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(79);
				match(T__2);
				setState(80);
				assn();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public List<TerminalNode> NEWLINE() { return getTokens(KotlinParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(KotlinParser.NEWLINE, i);
		}
		public List<StateContext> state() {
			return getRuleContexts(StateContext.class);
		}
		public StateContext state(int i) {
			return getRuleContext(StateContext.class,i);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitStatement(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statement);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(83);
			match(T__3);
			setState(87);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(84);
					match(NEWLINE);
					}
					} 
				}
				setState(89);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			setState(103);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__2) | (1L << T__3) | (1L << T__10) | (1L << T__14) | (1L << T__16) | (1L << T__19) | (1L << T__20) | (1L << T__21) | (1L << T__22) | (1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << T__26) | (1L << T__27) | (1L << T__28) | (1L << T__30) | (1L << T__31) | (1L << T__32) | (1L << T__33) | (1L << T__34) | (1L << T__36) | (1L << T__37) | (1L << INT) | (1L << REAL) | (1L << ID) | (1L << Decom) | (1L << Com) | (1L << TYPE))) != 0)) {
				{
				setState(90);
				state();
				setState(100);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(94);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(91);
							match(NEWLINE);
							}
							}
							setState(96);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(97);
						state();
						}
						} 
					}
					setState(102);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
				}
				}
			}

			setState(108);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(105);
				match(NEWLINE);
				}
				}
				setState(110);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(111);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StateContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StateContext state() {
			return getRuleContext(StateContext.class,0);
		}
		public FunContext fun() {
			return getRuleContext(FunContext.class,0);
		}
		public StateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_state; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterState(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitState(this);
		}
	}

	public final StateContext state() throws RecognitionException {
		StateContext _localctx = new StateContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_state);
		try {
			setState(119);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__10:
			case T__14:
			case T__16:
			case T__19:
			case T__20:
			case T__21:
			case T__22:
			case T__23:
			case T__24:
			case T__25:
			case T__26:
			case T__27:
			case T__28:
			case T__30:
			case T__31:
			case T__32:
			case T__33:
			case T__34:
			case T__36:
			case T__37:
			case INT:
			case REAL:
			case ID:
			case Decom:
			case Com:
			case TYPE:
				enterOuterAlt(_localctx, 1);
				{
				setState(113);
				expr(0);
				}
				break;
			case T__3:
				enterOuterAlt(_localctx, 2);
				{
				setState(114);
				match(T__3);
				setState(115);
				state();
				setState(116);
				match(T__4);
				}
				break;
			case T__0:
			case T__2:
				enterOuterAlt(_localctx, 3);
				{
				setState(118);
				fun();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public NumContext num() {
			return getRuleContext(NumContext.class,0);
		}
		public TerminalNode ID() { return getToken(KotlinParser.ID, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<StringContext> string() {
			return getRuleContexts(StringContext.class);
		}
		public StringContext string(int i) {
			return getRuleContext(StringContext.class,i);
		}
		public CommentContext comment() {
			return getRuleContext(CommentContext.class,0);
		}
		public AssnContext assn() {
			return getRuleContext(AssnContext.class,0);
		}
		public IfsContext ifs() {
			return getRuleContext(IfsContext.class,0);
		}
		public ForsContext fors() {
			return getRuleContext(ForsContext.class,0);
		}
		public WhilesContext whiles() {
			return getRuleContext(WhilesContext.class,0);
		}
		public ClasssContext classs() {
			return getRuleContext(ClasssContext.class,0);
		}
		public InterContext inter() {
			return getRuleContext(InterContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public PackContext pack() {
			return getRuleContext(PackContext.class,0);
		}
		public ImpContext imp() {
			return getRuleContext(ImpContext.class,0);
		}
		public FunContext fun() {
			return getRuleContext(FunContext.class,0);
		}
		public RangeContext range() {
			return getRuleContext(RangeContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitExpr(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(181);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				setState(122);
				num();
				}
				break;
			case 2:
				{
				setState(123);
				match(ID);
				}
				break;
			case 3:
				{
				setState(124);
				match(T__14);
				setState(126);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__10) | (1L << T__14) | (1L << T__16) | (1L << T__19) | (1L << T__20) | (1L << T__21) | (1L << T__22) | (1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << T__26) | (1L << T__27) | (1L << T__28) | (1L << T__30) | (1L << T__31) | (1L << T__32) | (1L << T__33) | (1L << T__34) | (1L << T__36) | (1L << T__37) | (1L << INT) | (1L << REAL) | (1L << ID) | (1L << Decom) | (1L << Com) | (1L << TYPE))) != 0)) {
					{
					setState(125);
					expr(0);
					}
				}

				setState(128);
				match(T__15);
				}
				break;
			case 4:
				{
				setState(129);
				match(T__10);
				setState(130);
				expr(0);
				setState(131);
				match(T__9);
				}
				break;
			case 5:
				{
				setState(133);
				match(T__14);
				setState(134);
				string();
				setState(139);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__16) {
					{
					{
					setState(135);
					match(T__16);
					setState(136);
					string();
					}
					}
					setState(141);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(142);
				match(T__15);
				}
				break;
			case 6:
				{
				setState(144);
				comment();
				}
				break;
			case 7:
				{
				setState(145);
				assn();
				}
				break;
			case 8:
				{
				setState(146);
				match(T__19);
				setState(148);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
				case 1:
					{
					setState(147);
					expr(0);
					}
					break;
				}
				}
				break;
			case 9:
				{
				setState(150);
				match(T__16);
				setState(151);
				expr(16);
				}
				break;
			case 10:
				{
				setState(152);
				match(T__20);
				setState(153);
				ifs();
				}
				break;
			case 11:
				{
				setState(154);
				match(T__21);
				setState(155);
				ifs();
				}
				break;
			case 12:
				{
				setState(156);
				match(T__22);
				setState(157);
				ifs();
				}
				break;
			case 13:
				{
				setState(158);
				match(T__23);
				setState(159);
				expr(12);
				}
				break;
			case 14:
				{
				setState(160);
				match(T__24);
				setState(161);
				expr(11);
				}
				break;
			case 15:
				{
				setState(162);
				match(T__25);
				}
				break;
			case 16:
				{
				setState(163);
				match(T__26);
				setState(164);
				expr(9);
				}
				break;
			case 17:
				{
				setState(165);
				match(T__27);
				setState(166);
				fors();
				}
				break;
			case 18:
				{
				setState(167);
				match(T__28);
				setState(168);
				whiles();
				}
				break;
			case 19:
				{
				setState(170);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__30) {
					{
					setState(169);
					match(T__30);
					}
				}

				setState(172);
				match(T__31);
				setState(173);
				classs(0);
				}
				break;
			case 20:
				{
				setState(174);
				match(T__32);
				setState(175);
				inter();
				}
				break;
			case 21:
				{
				setState(176);
				type();
				}
				break;
			case 22:
				{
				setState(177);
				match(T__33);
				setState(178);
				pack();
				}
				break;
			case 23:
				{
				setState(179);
				match(T__34);
				setState(180);
				imp();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(234);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(232);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(183);
						if (!(precpred(_ctx, 34))) throw new FailedPredicateException(this, "precpred(_ctx, 34)");
						setState(184);
						_la = _input.LA(1);
						if ( !(_la==T__5 || _la==T__6) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(188);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==T__1) {
							{
							{
							setState(185);
							match(T__1);
							}
							}
							setState(190);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(191);
						expr(35);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(192);
						if (!(precpred(_ctx, 33))) throw new FailedPredicateException(this, "precpred(_ctx, 33)");
						setState(193);
						_la = _input.LA(1);
						if ( !(_la==T__7 || _la==T__8) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(197);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==T__1) {
							{
							{
							setState(194);
							match(T__1);
							}
							}
							setState(199);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(200);
						expr(34);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(201);
						if (!(precpred(_ctx, 32))) throw new FailedPredicateException(this, "precpred(_ctx, 32)");
						setState(202);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__9) | (1L << T__10) | (1L << T__11))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(206);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==T__1) {
							{
							{
							setState(203);
							match(T__1);
							}
							}
							setState(208);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(209);
						expr(33);
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(210);
						if (!(precpred(_ctx, 25))) throw new FailedPredicateException(this, "precpred(_ctx, 25)");
						setState(211);
						match(T__1);
						setState(212);
						expr(26);
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(213);
						if (!(precpred(_ctx, 24))) throw new FailedPredicateException(this, "precpred(_ctx, 24)");
						setState(214);
						match(T__17);
						setState(215);
						expr(25);
						}
						break;
					case 6:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(216);
						if (!(precpred(_ctx, 22))) throw new FailedPredicateException(this, "precpred(_ctx, 22)");
						setState(217);
						expr(23);
						}
						break;
					case 7:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(218);
						if (!(precpred(_ctx, 31))) throw new FailedPredicateException(this, "precpred(_ctx, 31)");
						setState(219);
						_la = _input.LA(1);
						if ( !(_la==T__12 || _la==T__13) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						break;
					case 8:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(220);
						if (!(precpred(_ctx, 23))) throw new FailedPredicateException(this, "precpred(_ctx, 23)");
						setState(221);
						match(T__18);
						}
						break;
					case 9:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(222);
						if (!(precpred(_ctx, 20))) throw new FailedPredicateException(this, "precpred(_ctx, 20)");
						setState(223);
						assn();
						}
						break;
					case 10:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(224);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(225);
						fun();
						}
						break;
					case 11:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(226);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(228);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==T__11) {
							{
							setState(227);
							match(T__11);
							}
						}

						setState(230);
						match(T__29);
						setState(231);
						range(0);
						}
						break;
					}
					} 
				}
				setState(236);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class PackContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public PackContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pack; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterPack(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitPack(this);
		}
	}

	public final PackContext pack() throws RecognitionException {
		PackContext _localctx = new PackContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_pack);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(237);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ImpContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ImpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_imp; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterImp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitImp(this);
		}
	}

	public final ImpContext imp() throws RecognitionException {
		ImpContext _localctx = new ImpContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_imp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(239);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfsContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StateContext state() {
			return getRuleContext(StateContext.class,0);
		}
		public IfsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifs; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterIfs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitIfs(this);
		}
	}

	public final IfsContext ifs() throws RecognitionException {
		IfsContext _localctx = new IfsContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_ifs);
		try {
			setState(252);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(241);
				match(T__14);
				setState(242);
				expr(0);
				setState(243);
				match(T__15);
				setState(244);
				statement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(246);
				match(T__14);
				setState(247);
				expr(0);
				setState(248);
				match(T__15);
				setState(249);
				state();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(251);
				statement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForsContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StateContext state() {
			return getRuleContext(StateContext.class,0);
		}
		public ForsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fors; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterFors(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitFors(this);
		}
	}

	public final ForsContext fors() throws RecognitionException {
		ForsContext _localctx = new ForsContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_fors);
		try {
			setState(265);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(254);
				match(T__14);
				setState(255);
				expr(0);
				setState(256);
				match(T__15);
				setState(257);
				statement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(259);
				match(T__14);
				setState(260);
				expr(0);
				setState(261);
				match(T__15);
				setState(262);
				state();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(264);
				statement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhilesContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StateContext state() {
			return getRuleContext(StateContext.class,0);
		}
		public WhilesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whiles; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterWhiles(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitWhiles(this);
		}
	}

	public final WhilesContext whiles() throws RecognitionException {
		WhilesContext _localctx = new WhilesContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_whiles);
		try {
			setState(278);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(267);
				match(T__14);
				setState(268);
				expr(0);
				setState(269);
				match(T__15);
				setState(270);
				statement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(272);
				match(T__14);
				setState(273);
				expr(0);
				setState(274);
				match(T__15);
				setState(275);
				state();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(277);
				statement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClasssContext extends ParserRuleContext {
		public List<TerminalNode> ID() { return getTokens(KotlinParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(KotlinParser.ID, i);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ClassesContext classes() {
			return getRuleContext(ClassesContext.class,0);
		}
		public List<ClasssContext> classs() {
			return getRuleContexts(ClasssContext.class);
		}
		public ClasssContext classs(int i) {
			return getRuleContext(ClasssContext.class,i);
		}
		public ClasssContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classs; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterClasss(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitClasss(this);
		}
	}

	public final ClasssContext classs() throws RecognitionException {
		return classs(0);
	}

	private ClasssContext classs(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ClasssContext _localctx = new ClasssContext(_ctx, _parentState);
		ClasssContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_classs, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(296);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				{
				setState(281);
				match(ID);
				setState(282);
				match(T__14);
				setState(283);
				expr(0);
				setState(284);
				match(T__15);
				setState(289);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__16) {
					{
					{
					setState(285);
					match(T__16);
					setState(286);
					match(ID);
					}
					}
					setState(291);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(292);
				classes();
				}
				break;
			case 2:
				{
				setState(294);
				match(ID);
				setState(295);
				classes();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(303);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ClasssContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_classs);
					setState(298);
					if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
					setState(299);
					match(T__35);
					setState(300);
					classs(4);
					}
					} 
				}
				setState(305);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ClassesContext extends ParserRuleContext {
		public List<TerminalNode> NEWLINE() { return getTokens(KotlinParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(KotlinParser.NEWLINE, i);
		}
		public List<StateContext> state() {
			return getRuleContexts(StateContext.class);
		}
		public StateContext state(int i) {
			return getRuleContext(StateContext.class,i);
		}
		public ClassesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classes; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterClasses(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitClasses(this);
		}
	}

	public final ClassesContext classes() throws RecognitionException {
		ClassesContext _localctx = new ClassesContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_classes);
		int _la;
		try {
			int _alt;
			setState(365);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				enterOuterAlt(_localctx, 1);
				{
				setState(306);
				match(T__3);
				setState(310);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(307);
						match(NEWLINE);
						}
						} 
					}
					setState(312);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
				}
				setState(326);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__2) | (1L << T__3) | (1L << T__10) | (1L << T__14) | (1L << T__16) | (1L << T__19) | (1L << T__20) | (1L << T__21) | (1L << T__22) | (1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << T__26) | (1L << T__27) | (1L << T__28) | (1L << T__30) | (1L << T__31) | (1L << T__32) | (1L << T__33) | (1L << T__34) | (1L << T__36) | (1L << T__37) | (1L << INT) | (1L << REAL) | (1L << ID) | (1L << Decom) | (1L << Com) | (1L << TYPE))) != 0)) {
					{
					setState(313);
					state();
					setState(323);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
					while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
						if ( _alt==1 ) {
							{
							{
							setState(317);
							_errHandler.sync(this);
							_la = _input.LA(1);
							while (_la==NEWLINE) {
								{
								{
								setState(314);
								match(NEWLINE);
								}
								}
								setState(319);
								_errHandler.sync(this);
								_la = _input.LA(1);
							}
							setState(320);
							state();
							}
							} 
						}
						setState(325);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
					}
					}
				}

				setState(331);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(328);
					match(NEWLINE);
					}
					}
					setState(333);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(334);
				match(T__4);
				}
				break;
			case T__14:
				enterOuterAlt(_localctx, 2);
				{
				setState(335);
				match(T__14);
				setState(339);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(336);
						match(NEWLINE);
						}
						} 
					}
					setState(341);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				}
				setState(356);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__2) | (1L << T__3) | (1L << T__10) | (1L << T__14) | (1L << T__16) | (1L << T__19) | (1L << T__20) | (1L << T__21) | (1L << T__22) | (1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << T__26) | (1L << T__27) | (1L << T__28) | (1L << T__30) | (1L << T__31) | (1L << T__32) | (1L << T__33) | (1L << T__34) | (1L << T__36) | (1L << T__37) | (1L << INT) | (1L << REAL) | (1L << ID) | (1L << Decom) | (1L << Com) | (1L << TYPE))) != 0)) {
					{
					setState(342);
					state();
					setState(353);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__16) {
						{
						{
						setState(343);
						match(T__16);
						setState(347);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==NEWLINE) {
							{
							{
							setState(344);
							match(NEWLINE);
							}
							}
							setState(349);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(350);
						state();
						}
						}
						setState(355);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				setState(361);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(358);
					match(NEWLINE);
					}
					}
					setState(363);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(364);
				match(T__15);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InterContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(KotlinParser.ID, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public InterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inter; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterInter(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitInter(this);
		}
	}

	public final InterContext inter() throws RecognitionException {
		InterContext _localctx = new InterContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_inter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(367);
			match(ID);
			setState(368);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(KotlinParser.STRING, 0); }
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterString(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitString(this);
		}
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_string);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(370);
			match(STRING);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssnContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(KotlinParser.ID, 0); }
		public NumContext num() {
			return getRuleContext(NumContext.class,0);
		}
		public CommentContext comment() {
			return getRuleContext(CommentContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AssnContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assn; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterAssn(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitAssn(this);
		}
	}

	public final AssnContext assn() throws RecognitionException {
		AssnContext _localctx = new AssnContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_assn);
		try {
			setState(402);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,43,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(372);
				match(ID);
				setState(373);
				match(T__1);
				setState(374);
				num();
				setState(376);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,41,_ctx) ) {
				case 1:
					{
					setState(375);
					comment();
					}
					break;
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(378);
				match(ID);
				setState(379);
				match(T__35);
				setState(380);
				expr(0);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(381);
				match(ID);
				setState(382);
				match(T__35);
				setState(383);
				expr(0);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(384);
				match(T__36);
				setState(385);
				expr(0);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(386);
				match(T__37);
				setState(387);
				expr(0);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(388);
				match(ID);
				setState(389);
				expr(0);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(390);
				match(ID);
				setState(391);
				expr(0);
				setState(392);
				match(T__35);
				setState(393);
				expr(0);
				setState(395);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,42,_ctx) ) {
				case 1:
					{
					setState(394);
					match(T__38);
					}
					break;
				}
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(397);
				match(ID);
				setState(398);
				match(T__14);
				setState(399);
				expr(0);
				setState(400);
				match(T__15);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public List<TerminalNode> TYPE() { return getTokens(KotlinParser.TYPE); }
		public TerminalNode TYPE(int i) {
			return getToken(KotlinParser.TYPE, i);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitType(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_type);
		try {
			setState(409);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,44,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(404);
				match(TYPE);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(405);
				match(TYPE);
				setState(406);
				match(T__10);
				setState(407);
				match(TYPE);
				setState(408);
				match(T__9);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CommentContext extends ParserRuleContext {
		public TerminalNode Decom() { return getToken(KotlinParser.Decom, 0); }
		public TerminalNode Com() { return getToken(KotlinParser.Com, 0); }
		public CommentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comment; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterComment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitComment(this);
		}
	}

	public final CommentContext comment() throws RecognitionException {
		CommentContext _localctx = new CommentContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_comment);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(411);
			_la = _input.LA(1);
			if ( !(_la==Decom || _la==Com) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NumContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(KotlinParser.INT, 0); }
		public TerminalNode REAL() { return getToken(KotlinParser.REAL, 0); }
		public NumContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_num; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterNum(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitNum(this);
		}
	}

	public final NumContext num() throws RecognitionException {
		NumContext _localctx = new NumContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_num);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(413);
			_la = _input.LA(1);
			if ( !(_la==INT || _la==REAL) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RangeContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<RangeContext> range() {
			return getRuleContexts(RangeContext.class);
		}
		public RangeContext range(int i) {
			return getRuleContext(RangeContext.class,i);
		}
		public RangeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_range; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).enterRange(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KotlinListener ) ((KotlinListener)listener).exitRange(this);
		}
	}

	public final RangeContext range() throws RecognitionException {
		return range(0);
	}

	private RangeContext range(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		RangeContext _localctx = new RangeContext(_ctx, _parentState);
		RangeContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_range, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(416);
			expr(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(429);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,46,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(427);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,45,_ctx) ) {
					case 1:
						{
						_localctx = new RangeContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_range);
						setState(418);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(419);
						match(T__39);
						setState(420);
						range(5);
						}
						break;
					case 2:
						{
						_localctx = new RangeContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_range);
						setState(421);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(422);
						match(T__40);
						setState(423);
						range(4);
						}
						break;
					case 3:
						{
						_localctx = new RangeContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_range);
						setState(424);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(425);
						match(T__41);
						setState(426);
						range(3);
						}
						break;
					}
					} 
				}
				setState(431);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,46,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 4:
			return expr_sempred((ExprContext)_localctx, predIndex);
		case 10:
			return classs_sempred((ClasssContext)_localctx, predIndex);
		case 18:
			return range_sempred((RangeContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 34);
		case 1:
			return precpred(_ctx, 33);
		case 2:
			return precpred(_ctx, 32);
		case 3:
			return precpred(_ctx, 25);
		case 4:
			return precpred(_ctx, 24);
		case 5:
			return precpred(_ctx, 22);
		case 6:
			return precpred(_ctx, 31);
		case 7:
			return precpred(_ctx, 23);
		case 8:
			return precpred(_ctx, 20);
		case 9:
			return precpred(_ctx, 17);
		case 10:
			return precpred(_ctx, 6);
		}
		return true;
	}
	private boolean classs_sempred(ClasssContext _localctx, int predIndex) {
		switch (predIndex) {
		case 11:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean range_sempred(RangeContext _localctx, int predIndex) {
		switch (predIndex) {
		case 12:
			return precpred(_ctx, 4);
		case 13:
			return precpred(_ctx, 3);
		case 14:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\38\u01b3\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\3\2\7\2*\n\2\f\2\16\2-\13\2\3\2\3\2\7\2\61\n\2\f"+
		"\2\16\2\64\13\2\3\2\3\2\7\28\n\2\f\2\16\2;\13\2\3\2\3\2\7\2?\n\2\f\2\16"+
		"\2B\13\2\7\2D\n\2\f\2\16\2G\13\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\5\3T\n\3\3\4\3\4\7\4X\n\4\f\4\16\4[\13\4\3\4\3\4\7\4_\n\4\f\4\16"+
		"\4b\13\4\3\4\7\4e\n\4\f\4\16\4h\13\4\5\4j\n\4\3\4\7\4m\n\4\f\4\16\4p\13"+
		"\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\5\5z\n\5\3\6\3\6\3\6\3\6\3\6\5\6\u0081"+
		"\n\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\7\6\u008c\n\6\f\6\16\6\u008f"+
		"\13\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\u0097\n\6\3\6\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\u00ad\n\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\u00b8\n\6\3\6\3\6\3\6\7\6\u00bd"+
		"\n\6\f\6\16\6\u00c0\13\6\3\6\3\6\3\6\3\6\7\6\u00c6\n\6\f\6\16\6\u00c9"+
		"\13\6\3\6\3\6\3\6\3\6\7\6\u00cf\n\6\f\6\16\6\u00d2\13\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\u00e7"+
		"\n\6\3\6\3\6\7\6\u00eb\n\6\f\6\16\6\u00ee\13\6\3\7\3\7\3\b\3\b\3\t\3\t"+
		"\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\t\u00ff\n\t\3\n\3\n\3\n\3\n\3\n"+
		"\3\n\3\n\3\n\3\n\3\n\3\n\5\n\u010c\n\n\3\13\3\13\3\13\3\13\3\13\3\13\3"+
		"\13\3\13\3\13\3\13\3\13\5\13\u0119\n\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\7"+
		"\f\u0122\n\f\f\f\16\f\u0125\13\f\3\f\3\f\3\f\3\f\5\f\u012b\n\f\3\f\3\f"+
		"\3\f\7\f\u0130\n\f\f\f\16\f\u0133\13\f\3\r\3\r\7\r\u0137\n\r\f\r\16\r"+
		"\u013a\13\r\3\r\3\r\7\r\u013e\n\r\f\r\16\r\u0141\13\r\3\r\7\r\u0144\n"+
		"\r\f\r\16\r\u0147\13\r\5\r\u0149\n\r\3\r\7\r\u014c\n\r\f\r\16\r\u014f"+
		"\13\r\3\r\3\r\3\r\7\r\u0154\n\r\f\r\16\r\u0157\13\r\3\r\3\r\3\r\7\r\u015c"+
		"\n\r\f\r\16\r\u015f\13\r\3\r\7\r\u0162\n\r\f\r\16\r\u0165\13\r\5\r\u0167"+
		"\n\r\3\r\7\r\u016a\n\r\f\r\16\r\u016d\13\r\3\r\5\r\u0170\n\r\3\16\3\16"+
		"\3\16\3\17\3\17\3\20\3\20\3\20\3\20\5\20\u017b\n\20\3\20\3\20\3\20\3\20"+
		"\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\5\20"+
		"\u018e\n\20\3\20\3\20\3\20\3\20\3\20\5\20\u0195\n\20\3\21\3\21\3\21\3"+
		"\21\3\21\5\21\u019c\n\21\3\22\3\22\3\23\3\23\3\24\3\24\3\24\3\24\3\24"+
		"\3\24\3\24\3\24\3\24\3\24\3\24\3\24\7\24\u01ae\n\24\f\24\16\24\u01b1\13"+
		"\24\3\24\2\5\n\26&\25\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&\2\b"+
		"\3\2\b\t\3\2\n\13\4\2\4\4\f\16\3\2\17\20\3\2\61\62\3\2./\2\u01f9\2+\3"+
		"\2\2\2\4S\3\2\2\2\6U\3\2\2\2\by\3\2\2\2\n\u00b7\3\2\2\2\f\u00ef\3\2\2"+
		"\2\16\u00f1\3\2\2\2\20\u00fe\3\2\2\2\22\u010b\3\2\2\2\24\u0118\3\2\2\2"+
		"\26\u012a\3\2\2\2\30\u016f\3\2\2\2\32\u0171\3\2\2\2\34\u0174\3\2\2\2\36"+
		"\u0194\3\2\2\2 \u019b\3\2\2\2\"\u019d\3\2\2\2$\u019f\3\2\2\2&\u01a1\3"+
		"\2\2\2(*\7-\2\2)(\3\2\2\2*-\3\2\2\2+)\3\2\2\2+,\3\2\2\2,E\3\2\2\2-+\3"+
		"\2\2\2.\62\5\4\3\2/\61\7-\2\2\60/\3\2\2\2\61\64\3\2\2\2\62\60\3\2\2\2"+
		"\62\63\3\2\2\2\63D\3\2\2\2\64\62\3\2\2\2\659\5\36\20\2\668\7-\2\2\67\66"+
		"\3\2\2\28;\3\2\2\29\67\3\2\2\29:\3\2\2\2:D\3\2\2\2;9\3\2\2\2<@\5\n\6\2"+
		"=?\7-\2\2>=\3\2\2\2?B\3\2\2\2@>\3\2\2\2@A\3\2\2\2AD\3\2\2\2B@\3\2\2\2"+
		"C.\3\2\2\2C\65\3\2\2\2C<\3\2\2\2DG\3\2\2\2EC\3\2\2\2EF\3\2\2\2F\3\3\2"+
		"\2\2GE\3\2\2\2HI\7\3\2\2IJ\5\36\20\2JK\5\6\4\2KT\3\2\2\2LM\7\3\2\2MN\5"+
		"\36\20\2NO\7\4\2\2OP\5\n\6\2PT\3\2\2\2QR\7\5\2\2RT\5\36\20\2SH\3\2\2\2"+
		"SL\3\2\2\2SQ\3\2\2\2T\5\3\2\2\2UY\7\6\2\2VX\7-\2\2WV\3\2\2\2X[\3\2\2\2"+
		"YW\3\2\2\2YZ\3\2\2\2Zi\3\2\2\2[Y\3\2\2\2\\f\5\b\5\2]_\7-\2\2^]\3\2\2\2"+
		"_b\3\2\2\2`^\3\2\2\2`a\3\2\2\2ac\3\2\2\2b`\3\2\2\2ce\5\b\5\2d`\3\2\2\2"+
		"eh\3\2\2\2fd\3\2\2\2fg\3\2\2\2gj\3\2\2\2hf\3\2\2\2i\\\3\2\2\2ij\3\2\2"+
		"\2jn\3\2\2\2km\7-\2\2lk\3\2\2\2mp\3\2\2\2nl\3\2\2\2no\3\2\2\2oq\3\2\2"+
		"\2pn\3\2\2\2qr\7\7\2\2r\7\3\2\2\2sz\5\n\6\2tu\7\6\2\2uv\5\b\5\2vw\7\7"+
		"\2\2wz\3\2\2\2xz\5\4\3\2ys\3\2\2\2yt\3\2\2\2yx\3\2\2\2z\t\3\2\2\2{|\b"+
		"\6\1\2|\u00b8\5$\23\2}\u00b8\7\60\2\2~\u0080\7\21\2\2\177\u0081\5\n\6"+
		"\2\u0080\177\3\2\2\2\u0080\u0081\3\2\2\2\u0081\u0082\3\2\2\2\u0082\u00b8"+
		"\7\22\2\2\u0083\u0084\7\r\2\2\u0084\u0085\5\n\6\2\u0085\u0086\7\f\2\2"+
		"\u0086\u00b8\3\2\2\2\u0087\u0088\7\21\2\2\u0088\u008d\5\34\17\2\u0089"+
		"\u008a\7\23\2\2\u008a\u008c\5\34\17\2\u008b\u0089\3\2\2\2\u008c\u008f"+
		"\3\2\2\2\u008d\u008b\3\2\2\2\u008d\u008e\3\2\2\2\u008e\u0090\3\2\2\2\u008f"+
		"\u008d\3\2\2\2\u0090\u0091\7\22\2\2\u0091\u00b8\3\2\2\2\u0092\u00b8\5"+
		"\"\22\2\u0093\u00b8\5\36\20\2\u0094\u0096\7\26\2\2\u0095\u0097\5\n\6\2"+
		"\u0096\u0095\3\2\2\2\u0096\u0097\3\2\2\2\u0097\u00b8\3\2\2\2\u0098\u0099"+
		"\7\23\2\2\u0099\u00b8\5\n\6\22\u009a\u009b\7\27\2\2\u009b\u00b8\5\20\t"+
		"\2\u009c\u009d\7\30\2\2\u009d\u00b8\5\20\t\2\u009e\u009f\7\31\2\2\u009f"+
		"\u00b8\5\20\t\2\u00a0\u00a1\7\32\2\2\u00a1\u00b8\5\n\6\16\u00a2\u00a3"+
		"\7\33\2\2\u00a3\u00b8\5\n\6\r\u00a4\u00b8\7\34\2\2\u00a5\u00a6\7\35\2"+
		"\2\u00a6\u00b8\5\n\6\13\u00a7\u00a8\7\36\2\2\u00a8\u00b8\5\22\n\2\u00a9"+
		"\u00aa\7\37\2\2\u00aa\u00b8\5\24\13\2\u00ab\u00ad\7!\2\2\u00ac\u00ab\3"+
		"\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00af\7\"\2\2\u00af"+
		"\u00b8\5\26\f\2\u00b0\u00b1\7#\2\2\u00b1\u00b8\5\32\16\2\u00b2\u00b8\5"+
		" \21\2\u00b3\u00b4\7$\2\2\u00b4\u00b8\5\f\7\2\u00b5\u00b6\7%\2\2\u00b6"+
		"\u00b8\5\16\b\2\u00b7{\3\2\2\2\u00b7}\3\2\2\2\u00b7~\3\2\2\2\u00b7\u0083"+
		"\3\2\2\2\u00b7\u0087\3\2\2\2\u00b7\u0092\3\2\2\2\u00b7\u0093\3\2\2\2\u00b7"+
		"\u0094\3\2\2\2\u00b7\u0098\3\2\2\2\u00b7\u009a\3\2\2\2\u00b7\u009c\3\2"+
		"\2\2\u00b7\u009e\3\2\2\2\u00b7\u00a0\3\2\2\2\u00b7\u00a2\3\2\2\2\u00b7"+
		"\u00a4\3\2\2\2\u00b7\u00a5\3\2\2\2\u00b7\u00a7\3\2\2\2\u00b7\u00a9\3\2"+
		"\2\2\u00b7\u00ac\3\2\2\2\u00b7\u00b0\3\2\2\2\u00b7\u00b2\3\2\2\2\u00b7"+
		"\u00b3\3\2\2\2\u00b7\u00b5\3\2\2\2\u00b8\u00ec\3\2\2\2\u00b9\u00ba\f$"+
		"\2\2\u00ba\u00be\t\2\2\2\u00bb\u00bd\7\4\2\2\u00bc\u00bb\3\2\2\2\u00bd"+
		"\u00c0\3\2\2\2\u00be\u00bc\3\2\2\2\u00be\u00bf\3\2\2\2\u00bf\u00c1\3\2"+
		"\2\2\u00c0\u00be\3\2\2\2\u00c1\u00eb\5\n\6%\u00c2\u00c3\f#\2\2\u00c3\u00c7"+
		"\t\3\2\2\u00c4\u00c6\7\4\2\2\u00c5\u00c4\3\2\2\2\u00c6\u00c9\3\2\2\2\u00c7"+
		"\u00c5\3\2\2\2\u00c7\u00c8\3\2\2\2\u00c8\u00ca\3\2\2\2\u00c9\u00c7\3\2"+
		"\2\2\u00ca\u00eb\5\n\6$\u00cb\u00cc\f\"\2\2\u00cc\u00d0\t\4\2\2\u00cd"+
		"\u00cf\7\4\2\2\u00ce\u00cd\3\2\2\2\u00cf\u00d2\3\2\2\2\u00d0\u00ce\3\2"+
		"\2\2\u00d0\u00d1\3\2\2\2\u00d1\u00d3\3\2\2\2\u00d2\u00d0\3\2\2\2\u00d3"+
		"\u00eb\5\n\6#\u00d4\u00d5\f\33\2\2\u00d5\u00d6\7\4\2\2\u00d6\u00eb\5\n"+
		"\6\34\u00d7\u00d8\f\32\2\2\u00d8\u00d9\7\24\2\2\u00d9\u00eb\5\n\6\33\u00da"+
		"\u00db\f\30\2\2\u00db\u00eb\5\n\6\31\u00dc\u00dd\f!\2\2\u00dd\u00eb\t"+
		"\5\2\2\u00de\u00df\f\31\2\2\u00df\u00eb\7\25\2\2\u00e0\u00e1\f\26\2\2"+
		"\u00e1\u00eb\5\36\20\2\u00e2\u00e3\f\23\2\2\u00e3\u00eb\5\4\3\2\u00e4"+
		"\u00e6\f\b\2\2\u00e5\u00e7\7\16\2\2\u00e6\u00e5\3\2\2\2\u00e6\u00e7\3"+
		"\2\2\2\u00e7\u00e8\3\2\2\2\u00e8\u00e9\7 \2\2\u00e9\u00eb\5&\24\2\u00ea"+
		"\u00b9\3\2\2\2\u00ea\u00c2\3\2\2\2\u00ea\u00cb\3\2\2\2\u00ea\u00d4\3\2"+
		"\2\2\u00ea\u00d7\3\2\2\2\u00ea\u00da\3\2\2\2\u00ea\u00dc\3\2\2\2\u00ea"+
		"\u00de\3\2\2\2\u00ea\u00e0\3\2\2\2\u00ea\u00e2\3\2\2\2\u00ea\u00e4\3\2"+
		"\2\2\u00eb\u00ee\3\2\2\2\u00ec\u00ea\3\2\2\2\u00ec\u00ed\3\2\2\2\u00ed"+
		"\13\3\2\2\2\u00ee\u00ec\3\2\2\2\u00ef\u00f0\5\n\6\2\u00f0\r\3\2\2\2\u00f1"+
		"\u00f2\5\n\6\2\u00f2\17\3\2\2\2\u00f3\u00f4\7\21\2\2\u00f4\u00f5\5\n\6"+
		"\2\u00f5\u00f6\7\22\2\2\u00f6\u00f7\5\6\4\2\u00f7\u00ff\3\2\2\2\u00f8"+
		"\u00f9\7\21\2\2\u00f9\u00fa\5\n\6\2\u00fa\u00fb\7\22\2\2\u00fb\u00fc\5"+
		"\b\5\2\u00fc\u00ff\3\2\2\2\u00fd\u00ff\5\6\4\2\u00fe\u00f3\3\2\2\2\u00fe"+
		"\u00f8\3\2\2\2\u00fe\u00fd\3\2\2\2\u00ff\21\3\2\2\2\u0100\u0101\7\21\2"+
		"\2\u0101\u0102\5\n\6\2\u0102\u0103\7\22\2\2\u0103\u0104\5\6\4\2\u0104"+
		"\u010c\3\2\2\2\u0105\u0106\7\21\2\2\u0106\u0107\5\n\6\2\u0107\u0108\7"+
		"\22\2\2\u0108\u0109\5\b\5\2\u0109\u010c\3\2\2\2\u010a\u010c\5\6\4\2\u010b"+
		"\u0100\3\2\2\2\u010b\u0105\3\2\2\2\u010b\u010a\3\2\2\2\u010c\23\3\2\2"+
		"\2\u010d\u010e\7\21\2\2\u010e\u010f\5\n\6\2\u010f\u0110\7\22\2\2\u0110"+
		"\u0111\5\6\4\2\u0111\u0119\3\2\2\2\u0112\u0113\7\21\2\2\u0113\u0114\5"+
		"\n\6\2\u0114\u0115\7\22\2\2\u0115\u0116\5\b\5\2\u0116\u0119\3\2\2\2\u0117"+
		"\u0119\5\6\4\2\u0118\u010d\3\2\2\2\u0118\u0112\3\2\2\2\u0118\u0117\3\2"+
		"\2\2\u0119\25\3\2\2\2\u011a\u011b\b\f\1\2\u011b\u011c\7\60\2\2\u011c\u011d"+
		"\7\21\2\2\u011d\u011e\5\n\6\2\u011e\u0123\7\22\2\2\u011f\u0120\7\23\2"+
		"\2\u0120\u0122\7\60\2\2\u0121\u011f\3\2\2\2\u0122\u0125\3\2\2\2\u0123"+
		"\u0121\3\2\2\2\u0123\u0124\3\2\2\2\u0124\u0126\3\2\2\2\u0125\u0123\3\2"+
		"\2\2\u0126\u0127\5\30\r\2\u0127\u012b\3\2\2\2\u0128\u0129\7\60\2\2\u0129"+
		"\u012b\5\30\r\2\u012a\u011a\3\2\2\2\u012a\u0128\3\2\2\2\u012b\u0131\3"+
		"\2\2\2\u012c\u012d\f\5\2\2\u012d\u012e\7&\2\2\u012e\u0130\5\26\f\6\u012f"+
		"\u012c\3\2\2\2\u0130\u0133\3\2\2\2\u0131\u012f\3\2\2\2\u0131\u0132\3\2"+
		"\2\2\u0132\27\3\2\2\2\u0133\u0131\3\2\2\2\u0134\u0138\7\6\2\2\u0135\u0137"+
		"\7-\2\2\u0136\u0135\3\2\2\2\u0137\u013a\3\2\2\2\u0138\u0136\3\2\2\2\u0138"+
		"\u0139\3\2\2\2\u0139\u0148\3\2\2\2\u013a\u0138\3\2\2\2\u013b\u0145\5\b"+
		"\5\2\u013c\u013e\7-\2\2\u013d\u013c\3\2\2\2\u013e\u0141\3\2\2\2\u013f"+
		"\u013d\3\2\2\2\u013f\u0140\3\2\2\2\u0140\u0142\3\2\2\2\u0141\u013f\3\2"+
		"\2\2\u0142\u0144\5\b\5\2\u0143\u013f\3\2\2\2\u0144\u0147\3\2\2\2\u0145"+
		"\u0143\3\2\2\2\u0145\u0146\3\2\2\2\u0146\u0149\3\2\2\2\u0147\u0145\3\2"+
		"\2\2\u0148\u013b\3\2\2\2\u0148\u0149\3\2\2\2\u0149\u014d\3\2\2\2\u014a"+
		"\u014c\7-\2\2\u014b\u014a\3\2\2\2\u014c\u014f\3\2\2\2\u014d\u014b\3\2"+
		"\2\2\u014d\u014e\3\2\2\2\u014e\u0150\3\2\2\2\u014f\u014d\3\2\2\2\u0150"+
		"\u0170\7\7\2\2\u0151\u0155\7\21\2\2\u0152\u0154\7-\2\2\u0153\u0152\3\2"+
		"\2\2\u0154\u0157\3\2\2\2\u0155\u0153\3\2\2\2\u0155\u0156\3\2\2\2\u0156"+
		"\u0166\3\2\2\2\u0157\u0155\3\2\2\2\u0158\u0163\5\b\5\2\u0159\u015d\7\23"+
		"\2\2\u015a\u015c\7-\2\2\u015b\u015a\3\2\2\2\u015c\u015f\3\2\2\2\u015d"+
		"\u015b\3\2\2\2\u015d\u015e\3\2\2\2\u015e\u0160\3\2\2\2\u015f\u015d\3\2"+
		"\2\2\u0160\u0162\5\b\5\2\u0161\u0159\3\2\2\2\u0162\u0165\3\2\2\2\u0163"+
		"\u0161\3\2\2\2\u0163\u0164\3\2\2\2\u0164\u0167\3\2\2\2\u0165\u0163\3\2"+
		"\2\2\u0166\u0158\3\2\2\2\u0166\u0167\3\2\2\2\u0167\u016b\3\2\2\2\u0168"+
		"\u016a\7-\2\2\u0169\u0168\3\2\2\2\u016a\u016d\3\2\2\2\u016b\u0169\3\2"+
		"\2\2\u016b\u016c\3\2\2\2\u016c\u016e\3\2\2\2\u016d\u016b\3\2\2\2\u016e"+
		"\u0170\7\22\2\2\u016f\u0134\3\2\2\2\u016f\u0151\3\2\2\2\u0170\31\3\2\2"+
		"\2\u0171\u0172\7\60\2\2\u0172\u0173\5\6\4\2\u0173\33\3\2\2\2\u0174\u0175"+
		"\7\65\2\2\u0175\35\3\2\2\2\u0176\u0177\7\60\2\2\u0177\u0178\7\4\2\2\u0178"+
		"\u017a\5$\23\2\u0179\u017b\5\"\22\2\u017a\u0179\3\2\2\2\u017a\u017b\3"+
		"\2\2\2\u017b\u0195\3\2\2\2\u017c\u017d\7\60\2\2\u017d\u017e\7&\2\2\u017e"+
		"\u0195\5\n\6\2\u017f\u0180\7\60\2\2\u0180\u0181\7&\2\2\u0181\u0195\5\n"+
		"\6\2\u0182\u0183\7\'\2\2\u0183\u0195\5\n\6\2\u0184\u0185\7(\2\2\u0185"+
		"\u0195\5\n\6\2\u0186\u0187\7\60\2\2\u0187\u0195\5\n\6\2\u0188\u0189\7"+
		"\60\2\2\u0189\u018a\5\n\6\2\u018a\u018b\7&\2\2\u018b\u018d\5\n\6\2\u018c"+
		"\u018e\7)\2\2\u018d\u018c\3\2\2\2\u018d\u018e\3\2\2\2\u018e\u0195\3\2"+
		"\2\2\u018f\u0190\7\60\2\2\u0190\u0191\7\21\2\2\u0191\u0192\5\n\6\2\u0192"+
		"\u0193\7\22\2\2\u0193\u0195\3\2\2\2\u0194\u0176\3\2\2\2\u0194\u017c\3"+
		"\2\2\2\u0194\u017f\3\2\2\2\u0194\u0182\3\2\2\2\u0194\u0184\3\2\2\2\u0194"+
		"\u0186\3\2\2\2\u0194\u0188\3\2\2\2\u0194\u018f\3\2\2\2\u0195\37\3\2\2"+
		"\2\u0196\u019c\7\64\2\2\u0197\u0198\7\64\2\2\u0198\u0199\7\r\2\2\u0199"+
		"\u019a\7\64\2\2\u019a\u019c\7\f\2\2\u019b\u0196\3\2\2\2\u019b\u0197\3"+
		"\2\2\2\u019c!\3\2\2\2\u019d\u019e\t\6\2\2\u019e#\3\2\2\2\u019f\u01a0\t"+
		"\7\2\2\u01a0%\3\2\2\2\u01a1\u01a2\b\24\1\2\u01a2\u01a3\5\n\6\2\u01a3\u01af"+
		"\3\2\2\2\u01a4\u01a5\f\6\2\2\u01a5\u01a6\7*\2\2\u01a6\u01ae\5&\24\7\u01a7"+
		"\u01a8\f\5\2\2\u01a8\u01a9\7+\2\2\u01a9\u01ae\5&\24\6\u01aa\u01ab\f\4"+
		"\2\2\u01ab\u01ac\7,\2\2\u01ac\u01ae\5&\24\5\u01ad\u01a4\3\2\2\2\u01ad"+
		"\u01a7\3\2\2\2\u01ad\u01aa\3\2\2\2\u01ae\u01b1\3\2\2\2\u01af\u01ad\3\2"+
		"\2\2\u01af\u01b0\3\2\2\2\u01b0\'\3\2\2\2\u01b1\u01af\3\2\2\2\61+\629@"+
		"CESY`finy\u0080\u008d\u0096\u00ac\u00b7\u00be\u00c7\u00d0\u00e6\u00ea"+
		"\u00ec\u00fe\u010b\u0118\u0123\u012a\u0131\u0138\u013f\u0145\u0148\u014d"+
		"\u0155\u015d\u0163\u0166\u016b\u016f\u017a\u018d\u0194\u019b\u01ad\u01af";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}