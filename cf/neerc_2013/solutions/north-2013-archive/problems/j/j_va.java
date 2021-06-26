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
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

import javax.swing.plaf.multi.MultiPanelUI;

public class j_va implements Runnable {
	public static void main(String[] args) {
		new Thread(new j_va()).run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}

		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	int POW = 32;// 11;

	long[] sum = new long[POW];

	int mod = 1000000000;
	long[] X;
	long[] N;
	char[] c;
	int pos;

	public long[] intToVector(long x) {
		long[] ans = new long[POW];
		ans[0] = x;
		return ans;
	}

	public long[] sum(long[] a, long[] b) {
		long[] ans = new long[a.length];
		for (int i = 0; i < ans.length; i++) {
			ans[i] = (a[i] + b[i]) % mod;
		}
		return ans;
	}

	public long[] sub(long[] a, long[] b) {
		long[] ans = new long[a.length];
		for (int i = 0; i < ans.length; i++) {
			ans[i] = (a[i] - b[i] + mod) % mod;
		}
		return ans;
	}

	public long[] mul(long[] a, long[] b) {
		long[] ans = new long[a.length];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				if (i + j < ans.length)
					ans[i + j] = (ans[i + j] + a[i] * b[j]) % mod;
			}
		}
		return ans;
	}

	public long[] minus(long[] a) {
		long[] ans = new long[a.length];
		for (int i = 0; i < ans.length; i++) {
			ans[i] = (mod - a[i]) % mod;
		}
		return ans;
	}

	public long[] square(long[] a) {
		return mul(a, a);
	}

	public long[] fold(long[] a) {
		long s = 0;
		for (int i = 0; i < a.length; i++) {
			s = (s + a[i] * sum[i]) % mod;
		}
		return intToVector(s);
	}

	public long[] number() {
		long x = 0;
		while (Character.isDigit(c[pos])) {
			x = (x * 10 + (c[pos] - '0')) % mod;
			pos++;
		}
		return intToVector(x);
	}

	public long[] term(char c) {
		switch (c) {
		case '(':
			long[] r = expr();
			nextChar();
			return r;
		case 'X':
			return X;
		case 'N':
			return N;
		default:
			pos--;
			return number();
		}
	}

	public long[] expr() {
		char c = nextChar();
		switch (c) {
		case '-':
			return minus(expr());
		case '*':
			nextChar();
			return square(expr());
		case '+':
			nextChar();
			return fold(expr());
		default:
			long[] term = term(c);
			switch (nextChar()) {
			case '+':
				return sum(term, expr());
			case '-':
				return sub(term, expr());
			case '*':
				return mul(term, expr());
			default:
				pos--;
				return term;
			}
		}
	}

	public char nextChar() {
		return c[pos++];
	}

	public void solve() throws IOException {
		int n = nextInt();
		X = new long[n];

		for (int i = 0; i < n; i++) {
			X[i] = nextInt();
		}

		long[][] Xs = new long[POW][n];
		Arrays.fill(Xs[0], 1);

		sum[0] = n;
		for (int i = 1; i < POW; i++) {
			for (int j = 0; j < n; j++) {
				Xs[i][j] = (Xs[i - 1][j] * X[j]) % mod;
				sum[i] += Xs[i][j];
				sum[i] %= mod;
			}
		}

		N = intToVector(n);

		X = new long[POW];
		X[1] = 1;

		c = (nextToken() + '$').toCharArray();

		out.println(expr()[0]);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("j.in"));
			out = new PrintWriter("j.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}

