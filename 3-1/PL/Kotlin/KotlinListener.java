// Generated from Kotlin.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link KotlinParser}.
 */
public interface KotlinListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link KotlinParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(KotlinParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(KotlinParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#fun}.
	 * @param ctx the parse tree
	 */
	void enterFun(KotlinParser.FunContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#fun}.
	 * @param ctx the parse tree
	 */
	void exitFun(KotlinParser.FunContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(KotlinParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(KotlinParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#state}.
	 * @param ctx the parse tree
	 */
	void enterState(KotlinParser.StateContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#state}.
	 * @param ctx the parse tree
	 */
	void exitState(KotlinParser.StateContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(KotlinParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(KotlinParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#pack}.
	 * @param ctx the parse tree
	 */
	void enterPack(KotlinParser.PackContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#pack}.
	 * @param ctx the parse tree
	 */
	void exitPack(KotlinParser.PackContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#imp}.
	 * @param ctx the parse tree
	 */
	void enterImp(KotlinParser.ImpContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#imp}.
	 * @param ctx the parse tree
	 */
	void exitImp(KotlinParser.ImpContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#ifs}.
	 * @param ctx the parse tree
	 */
	void enterIfs(KotlinParser.IfsContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#ifs}.
	 * @param ctx the parse tree
	 */
	void exitIfs(KotlinParser.IfsContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#fors}.
	 * @param ctx the parse tree
	 */
	void enterFors(KotlinParser.ForsContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#fors}.
	 * @param ctx the parse tree
	 */
	void exitFors(KotlinParser.ForsContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#whiles}.
	 * @param ctx the parse tree
	 */
	void enterWhiles(KotlinParser.WhilesContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#whiles}.
	 * @param ctx the parse tree
	 */
	void exitWhiles(KotlinParser.WhilesContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#classs}.
	 * @param ctx the parse tree
	 */
	void enterClasss(KotlinParser.ClasssContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#classs}.
	 * @param ctx the parse tree
	 */
	void exitClasss(KotlinParser.ClasssContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#classes}.
	 * @param ctx the parse tree
	 */
	void enterClasses(KotlinParser.ClassesContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#classes}.
	 * @param ctx the parse tree
	 */
	void exitClasses(KotlinParser.ClassesContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#inter}.
	 * @param ctx the parse tree
	 */
	void enterInter(KotlinParser.InterContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#inter}.
	 * @param ctx the parse tree
	 */
	void exitInter(KotlinParser.InterContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#string}.
	 * @param ctx the parse tree
	 */
	void enterString(KotlinParser.StringContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#string}.
	 * @param ctx the parse tree
	 */
	void exitString(KotlinParser.StringContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#assn}.
	 * @param ctx the parse tree
	 */
	void enterAssn(KotlinParser.AssnContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#assn}.
	 * @param ctx the parse tree
	 */
	void exitAssn(KotlinParser.AssnContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(KotlinParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(KotlinParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#comment}.
	 * @param ctx the parse tree
	 */
	void enterComment(KotlinParser.CommentContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#comment}.
	 * @param ctx the parse tree
	 */
	void exitComment(KotlinParser.CommentContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#num}.
	 * @param ctx the parse tree
	 */
	void enterNum(KotlinParser.NumContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#num}.
	 * @param ctx the parse tree
	 */
	void exitNum(KotlinParser.NumContext ctx);
	/**
	 * Enter a parse tree produced by {@link KotlinParser#range}.
	 * @param ctx the parse tree
	 */
	void enterRange(KotlinParser.RangeContext ctx);
	/**
	 * Exit a parse tree produced by {@link KotlinParser#range}.
	 * @param ctx the parse tree
	 */
	void exitRange(KotlinParser.RangeContext ctx);
}