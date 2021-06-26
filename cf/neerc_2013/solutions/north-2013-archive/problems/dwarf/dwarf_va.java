/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem D. Dwarf Tower                                         */
/*                                                                */
/* Original idea         Vitaly Aksenov                           */
/* Problem statement     Vitaly Aksenov                           */
/* Test set              Vitaly Aksenov                           */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class dwarf_va implements Runnable {
	public static void main(String[] args) {
		new Thread(new dwarf_va()).run();
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

	private class Rule {
		int a, b, c;

		public Rule(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		int[] d = new int[n];

		for (int i = 0; i < d.length; i++) {
			d[i] = nextInt();
		}

		ArrayList<Rule>[] e = new ArrayList[n];
		for (int i = 0; i < e.length; i++) {
			e[i] = new ArrayList<Rule>();
		}

		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			int c = nextInt() - 1;

			Rule r = new Rule(a, b, c);
			e[b].add(r);
			e[c].add(r);
		}

		boolean[] was = new boolean[n];
		for (int i = 0; i < n; i++) {
			int mi = -1;
			for (int j = 0; j < n; j++) {
				if (!was[j] && (mi == -1 || d[mi] > d[j])) {
					mi = j;
				}
			}

            was[mi] = true;
			for (Rule r : e[mi]) {
				d[r.a] = Math.min(d[r.a], d[r.b] + d[r.c]);
			}
		}

//        System.out.println(Arrays.toString(d));
        out.println(d[0]);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("dwarf.in"));
			out = new PrintWriter("dwarf.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}

