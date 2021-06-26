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
/* Author                Mikhail Dvorkin                          */
/******************************************************************/

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class kids_md {
	private static String fileName = kids_md.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	public void run() {
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		// m * b == n * c
		int g = BigInteger.valueOf(b).gcd(BigInteger.valueOf(c)).intValue();
		int m = c / g; // * k
		int n = b / g; // * k
		// m * k > a && n * k > d && n * k >= b && m * k >= c
		int k = Math.max(
				(Math.max(a + 1, c) + m - 1) / m,
				(Math.max(d + 1, b) + n - 1) / n
				);
		if ((m & k & a & 1) == 1 || (n & k & d & 1) == 1) {
			k++;
		}
		out.println(m * k + " " + n * k);
		regular(1, m * k, a);
		regular(m * k + 1, n * k, d);
		for (int i = 0; i < m * k; i++) {
			int j0 = i / m * n;
			for (int j = 0; j < b; j++) {
				out.println((i + 1) + " " + ((j0 + j) % (n * k) + m * k + 1));
			}
		}
	}

	void regular(int from, int n, int deg) {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= deg / 2; j++) {
				out.println((from + i) + " " + (from + (i + j) % n));
			}
		}
		if (deg % 2 == 1) {
			for (int i = 0; i < n / 2; i++) {
				out.println((from + i) + " " + (from + i + n / 2));
			}
		}
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		in = new Scanner(new File(inputFileName));
		out = new PrintWriter(outputFileName);
		new kids_md().run();
		in.close();
		out.close();
	}
}

