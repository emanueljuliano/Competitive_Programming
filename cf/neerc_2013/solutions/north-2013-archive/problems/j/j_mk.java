/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem J. J                                                   */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Dmitry Shtukenberg                       */
/*                       Georgiy Korneev                          */
/* Test set              Dmitry Shtukenberg                       */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Mikhail Kever                            */
/******************************************************************/

import java.io.*;
import java.util.*;

public class j_mk {

	static class Parser {
		String input;
		int position;

		Parser(String input) {
			this.input = input;
			this.position = 0;
		}

		int curChar() {
			if (position == input.length()) {
				return -1;
			}
			return input.charAt(position);
		}

		void move() {
			++position;
		}

		Expression parseExpression() {
			int cur = curChar();
			if (cur == '-') {
				move();
				Expression e = parseExpression();
				return new UnaryMinusExpression(e);
			}
			if (cur == '*') {
				move();
				move();
				Expression e = parseExpression();
				return new UnarySquareExpression(e);
			}
			if (cur == '+') {
				move();
				move();
				Expression e = parseExpression();
				return new FoldExpression(e);
			}
			Expression term = parseTerm();
			cur = curChar();
			if (cur == '-') {
				move();
				Expression e = parseExpression();
				return new SubExpression(term, e);
			}
			if (cur == '*') {
				move();
				Expression e = parseExpression();
				return new MulExpression(term, e);
			}
			if (cur == '+') {
				move();
				Expression e = parseExpression();
				return new AddExpression(term, e);
			}
			return term;
		}

		Expression parseTerm() {
			int cur = curChar();
			if (cur == '(') {
				move();
				Expression e = parseExpression();
				move();
				return e;
			}
			if (cur == 'X') {
				move();
				return XExpression.INSTANCE;
			}
			if (cur == 'N') {
				move();
				return NumberExpression.NUMBER_N;
			}
			if ('0' <= cur && cur <= '9') {
				int value = 0;
				while ('0' <= curChar() && curChar() <= '9') {
					value = value * 10 + curChar() - '0';
					move();
				}
				return new NumberExpression(value);
			}
			throw new RuntimeException();
		}
	}

	static abstract class Expression {
		abstract Polynomial evaluate();
	}

	static class AddExpression extends Expression {
		Expression e1, e2;

		public AddExpression(Expression e1, Expression e2) {
			this.e1 = e1;
			this.e2 = e2;
		}

		@Override
		Polynomial evaluate() {
			return Polynomial.add(e1.evaluate(), e2.evaluate());
		}
	}

	static class SubExpression extends Expression {
		Expression e1, e2;

		public SubExpression(Expression e1, Expression e2) {
			this.e1 = e1;
			this.e2 = e2;
		}

		@Override
		Polynomial evaluate() {
			return Polynomial.sub(e1.evaluate(), e2.evaluate());
		}
	}

	static class MulExpression extends Expression {
		Expression e1, e2;

		public MulExpression(Expression e1, Expression e2) {
			this.e1 = e1;
			this.e2 = e2;
		}

		@Override
		Polynomial evaluate() {
			return Polynomial.multiply(e1.evaluate(), e2.evaluate());
		}
	}

	static class UnaryMinusExpression extends Expression {
		Expression e;

		public UnaryMinusExpression(Expression e) {
			this.e = e;
		}

		@Override
		Polynomial evaluate() {
			return Polynomial.negate(e.evaluate());
		}
	}

	static class UnarySquareExpression extends Expression {
		Expression e;

		public UnarySquareExpression(Expression e) {
			this.e = e;
		}

		@Override
		Polynomial evaluate() {
			Polynomial result = e.evaluate();
			return Polynomial.multiply(result, result);
		}
	}

	static class FoldExpression extends Expression {
		Expression e;

		public FoldExpression(Expression e) {
			this.e = e;
		}

		@Override
		Polynomial evaluate() {
			Polynomial what = e.evaluate();
			int foldResult = evaluator.evaluate(what);
			return new Polynomial(new int[] { foldResult });
		}
	}

	static class XExpression extends Expression {
		static final XExpression INSTANCE = new XExpression();

		@Override
		Polynomial evaluate() {
			return Polynomial.X;
		}
	}

	static class NumberExpression extends Expression {
		static NumberExpression NUMBER_N;

		final int value;

		public NumberExpression(int value) {
			this.value = value;
		}

		@Override
		Polynomial evaluate() {
			return new Polynomial(new int[] { value });
		}
	}

	static class Polynomial {
		static final Polynomial ZERO = new Polynomial(new int[] { 0 });
		static final Polynomial X = new Polynomial(new int[] { 0, 1 });
		int[] a;

		boolean isConstant() {
			return a.length == 1;
		}

		public static Polynomial negate(Polynomial p) {
			return Polynomial.sub(Polynomial.ZERO, p);
		}

		public Polynomial(int[] a) {
			this.a = a;
		}

		static Polynomial multiply(Polynomial p1, Polynomial p2) {
			return new Polynomial(multiply(p1.a, p2.a));
		}

		static Polynomial add(Polynomial p1, Polynomial p2) {
			return new Polynomial(add(p1.a, p2.a));
		}

		static Polynomial sub(Polynomial p1, Polynomial p2) {
			return new Polynomial(sub(p1.a, p2.a));
		}

		private static int[] sub(int[] u, int[] v) {
			int[] result = new int[Math.max(u.length, v.length)];
			for (int i = 0; i < Math.min(u.length, v.length); i++) {
				result[i] = subNumbers(u[i], v[i]);
			}
			if (u.length > v.length) {
				for (int i = v.length; i < u.length; i++) {
					result[i] = u[i];
				}
			} else {
				for (int i = u.length; i < v.length; i++) {
					result[i] = subNumbers(0, v[i]);
				}
			}
			return result;
		}

		private static int[] multiply(int[] u, int[] v) {
			int degU = u.length - 1;
			int degV = v.length - 1;
			int[] result = new int[degU + degV + 1];
			for (int i = 0; i <= degU; i++) {
				for (int j = 0; j <= degV; j++) {
					result[i + j] = addNumbers(result[i + j],
							multiplyNumbers(u[i], v[j]));
				}
			}
			return result;
		}

		private static int[] add(int[] u, int[] v) {
			if (u.length > v.length) {
				int[] t = u;
				u = v;
				v = t;
			}

			int[] result = new int[v.length];

			for (int i = 0; i < u.length; i++) {
				result[i] = addNumbers(u[i], v[i]);
			}
			for (int i = u.length; i < v.length; i++) {
				result[i] = v[i];
			}
			return result;
		}
	}

	private static int multiplyNumbers(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	public static int addNumbers(int a, int b) {
		a += b;
		if (a >= MOD) {
			a -= MOD;
		}
		return a;
	}

	public static int subNumbers(int a, int b) {
		a -= b;
		if (a < 0) {
			a += MOD;
		}
		return a;
	}

	static final int MOD = 1000000000;

	static PolynomialEvaluator evaluator;

	static class PolynomialEvaluator {
		int[] vectorX;
		int[] sumPows;
		int maxPows;

		public PolynomialEvaluator(int[] vectorX) {
			this.vectorX = vectorX;
			this.maxPows = 12;
			calcPows();
		}

		void calcPows() {
			sumPows = new int[maxPows];
			sumPows[0] = vectorX.length;
			int[] temp = vectorX.clone();
			for (int pow = 1; pow < maxPows; pow++) {
				int s = 0;
				for (int i = 0; i < temp.length; i++) {
					s = addNumbers(s, temp[i]);
				}
				sumPows[pow] = s;
				if (pow < maxPows - 1) {
					for (int i = 0; i < temp.length; i++) {
						temp[i] = multiplyNumbers(temp[i], vectorX[i]);
					}
				}
			}
		}

		int evaluate(Polynomial p) {
			int[] a = p.a;
			if (maxPows < a.length) {
				throw new AssertionError();
			}
			int value = 0;
			for (int i = 0; i < a.length; i++) {
				value = addNumbers(value, multiplyNumbers(a[i], sumPows[i]));
			}
			return value;
		}

	}

	static void solve() throws IOException {
		int n = nextInt();
		NumberExpression.NUMBER_N = new NumberExpression(n);
		int[] vectorX = new int[n];
		for (int i = 0; i < n; i++) {
			vectorX[i] = nextInt();
		}
		evaluator = new PolynomialEvaluator(vectorX);
		String what = nextToken();
		Parser parser = new Parser(what);
		Expression expression = parser.parseExpression();
		Polynomial result = expression.evaluate();

		out.println(result.a[0]);
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("j.in"));
		out = new PrintWriter("j.out");
		solve();
		br.close();
		out.close();
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer tok;

	static String nextToken() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			tok = new StringTokenizer(line);
		}
		return tok.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

}

