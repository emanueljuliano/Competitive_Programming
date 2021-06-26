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
/* Tests                                                          */
/*                                                                */
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Tests {

	Random rnd = new Random(239);
	int tests = 1;
	final int MAXC = 1000000000;
	final int MAXN = 10000;
	final int MAXM = 100000;
	final int HALFN = 80;

	class Rule {
		int a, b, c;

		public Rule(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}

		public int hashCode() {
			return a * 1000000 + Math.min(b, c) * 1000 + Math.max(b, c);
		}

		public boolean equals(Object o) {
			if (o instanceof Rule) {
				Rule r = (Rule) o;
				return r.a == a && r.b == b && r.c == c;
			}
			return false;
		}

		public String toString() {
			return (a + 1) + " " + (b + 1) + " " + (c + 1);
		}
	}

	public int getRandom(int n, int b, int c) {
		int a = rnd.nextInt(n);
		while (a == b || a == c) {
			a = rnd.nextInt(n);
		}
		return a;
	}

    public void writeTest(int[] d, Rule... rules) {
        writeTest(d, Arrays.asList(rules));
    }

	public void writeTest(int[] d, List<Rule> r) {
		try {
            System.out.println("Writing test " + tests);
            PrintWriter out = new PrintWriter(String.format("tests/%02d", tests++));

			out.println(d.length + " " + r.size());
			for (int i = 0; i < d.length; i++) {
				if (i != 0)
					out.print(" ");
				out.print(d[i]);
			}

			out.println();

			for (Rule rule : r) {
				out.println(rule);
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void lineTest(int n) {
		if (n % 2 == 0)
			n--;

		int[] d = new int[n];
		d[0] = n;

		ArrayList<Rule> rules = new ArrayList<Rule>();

		for (int i = 2; i < d.length; i += 2) {
			d[i - 1] = 1;
			d[i] = n;
			rules.add(new Rule(i - 2, i - 1, i));
		}
		d[n - 1] = 1;

		writeTest(d, rules);
	}

	public List<Rule> genRandomRules(int n, int m, HashSet<Rule> used, int[] d, int split) {
		List<Rule> r = new ArrayList<Rule>();
		if (n > HALFN) {
			int MAX_IT = 100000000;
			int it = 0;
			while (it < MAX_IT && r.size() < m) {
				Rule rule = null;
				it = 0;

				do {
					it++;
					int a = rnd.nextInt(n);
					int b = getRandom(n, a, -1);
					int c = getRandom(n, a, b);
					if (d[a] >= split) {
                                        	continue;
                                        }
					rule = new Rule(a, b, c);
				} while (it < MAX_IT && (rule == null || used.contains(rule)));

				if (it < MAX_IT) {
					r.add(rule);
					used.add(rule);
				}
			}
		} else {
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					for (int c = b + 1; c < n; c++) {
						if (a == b || a == c || d[a] >= split)
							continue;
						r.add(new Rule(a, b, c));
					}
				}
			}
		}

		return r;
	}

	public void halfRandomTest(int n, int m, int k) {

		int[] d = new int[n];

		ArrayList<Rule> r = new ArrayList<Rule>();

		d[0] = rnd.nextInt(MAXC - k) + k + 1;

		HashSet<Rule> used = new HashSet<Rule>();
		for (int i = 0; i < k; i++) {
			d[2 * i + 1] = d[0] / (k + 1);
			d[2 * i + 2] = rnd.nextInt(MAXC - k + i + 1 - d[0]) + k - i + d[0];
			Rule rule = new Rule(2 * i, 2 * i + 1, 2 * i + 2);
			used.add(rule);
			r.add(rule);
		}
		d[2 * k] = d[0] / (k + 1);

		for (int i = 2 * k + 1; i < n; i++) {
			d[i] = rnd.nextInt(MAXC + 1 - d[0]) + d[0];
		}

		r.addAll(genRandomRules(n, m - r.size(), used, d, d[0]));

		writeTest(d, r);
	}

	public void randomTest(int n, int m, boolean zero) {
		int[] d = new int[n];

		for (int i = 0; i < d.length; i++) {
			d[i] = zero ? 0 : rnd.nextInt(MAXC + 1);
		}

		List<Rule> r = genRandomRules(n, m, new HashSet<Rule>(), d, 0);

		writeTest(d, r);
	}

	public void gen() {
		if (!new File("tests").exists()) {
			new File("tests").mkdir();
		}

		writeTest(
                new int[] { 5, 0, 1, 2, 5 },
                new Rule(5 - 1, 2 - 1, 3 - 1),
                new Rule(4 - 1, 2 - 1, 3 - 1),
                new Rule(1 - 1, 4 - 1, 5 - 1)
        );

		writeTest(
                new int[] { 2, 2, 1 },
                new Rule(1 - 1, 2 - 1, 3 - 1)
        );

		writeTest(
                new int[] { 0, 0, 0 },
                new Rule(1 - 1, 2 - 1, 3 - 1)
        );

		writeTest(
                new int[] { 1, 0, 0 },
                new Rule(1 - 1, 2 - 1, 3 - 1)
        );

		writeTest(
                new int[] { 1, 0, 0 },
                new Rule(1 - 1, 2 - 1, 3 - 1)
        );


		for (int i = 0; i < 4; i++) {
			lineTest(rnd.nextInt(HALFN - 10) + 10);
			int n = rnd.nextInt(HALFN - 10) + 10;
			halfRandomTest(n, rnd.nextInt(n * n * n) + 1, rnd.nextInt(n / 2 - 1));
			n = rnd.nextInt(HALFN - 10) + 10;
			randomTest(n, rnd.nextInt(n * n * n) + 1, false);
		}

		halfRandomTest(100, MAXM, 100 / 2 - 2);
		randomTest(100, MAXM, false);
		randomTest(100, MAXM, true);

		for (int i = 0; i < 6; i++) {
			lineTest(rnd.nextInt(MAXN - 100));
			int n = rnd.nextInt(MAXN - 100) + 100;
			halfRandomTest(n, rnd.nextInt(MAXM) + 1, rnd.nextInt(n / 2 - 1));
			n = rnd.nextInt(MAXN - 100) + 100;
			randomTest(n, rnd.nextInt(MAXM) + 1, false);
		}

		for (int i = 0; i < 3; i++) {
			halfRandomTest(MAXN, MAXM, MAXN / (5 - i) - 2);  
        }

		halfRandomTest(MAXN, MAXM, MAXN / 2 - 2);
		randomTest(MAXN, MAXM, false);
		randomTest(MAXN, MAXM, true);
	}

	public static void main(String[] args) {
		new Tests().gen();
	}
}

