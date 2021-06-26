/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem K. Kids in a Friendly Class                            */
/*                                                                */
/* Original idea         Mikhail Dvorkin                          */
/* Problem statement     Mikhail Dvorkin                          */
/* Test set              Mikhail Dvorkin                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class kids_va implements Runnable {
	public static void main(String[] args) {
		new Thread(new kids_va()).run();
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

	public int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public void regular(int n, int d, int add) {
		add++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < d / 2; j++) {
				out.println((i + add) + " " + ((i + j + 1) % n + add));
			}
		}

		if (d % 2 == 1) {
			for (int i = 0; i < n / 2; i++) {
				out.println((i + add) + " " + ((i + n / 2) % n + add));
			}
		}
	}

	public void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		int d = nextInt();

		int g = gcd(b, c);

		b = b / g;
		c = c / g;

		// System.err.println(b + " " + c);
		// System.err.println(b * g);
		// System.err.println(c * g);
		// System.err.println(Math.max(b * g, d + 1));
		// System.err.println(Math.max(c * g, a + 1));

		int k = Math.max((Math.max(b * g, d + 1) + b - 1) / b,
				(Math.max(c * g, a + 1) + c - 1) / c);
		System.err.println(k);

		if ((c * k * a) % 2 == 1 || (b * k * d) % 2 == 1) {
			k++;
		}

		int n = c * k;
		int m = b * k;

		out.println(n + " " + m);
		regular(n, a, 0);
		regular(m, d, n);

		int z = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b * g; j++) {
				out.println((i + 1) + " " + (z + 1 + n));
				z = (z + 1) % m;
			}
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("kids.in"));
			out = new PrintWriter("kids.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}

