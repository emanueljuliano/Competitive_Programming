/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem B. Ballot Analyzing Device                             */
/*                                                                */
/* Original idea         Jury                                     */
/* Problem statement     Andrew Stankevich                        */
/* Test set              Andrew Stankevich                        */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class bad_va implements Runnable {
	public static void main(String[] args) {
		new Thread(new bad_va()).run();
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

	public class Person implements Comparable<Person> {
		String name;
		int cnt;

		public Person(String name) {
			this.name = name;
		}

		public int compareTo(Person p) {
			return p.cnt - cnt;
		}
	}

	public void solve() throws IOException {
		Locale.setDefault(Locale.US);

		int n = nextInt();
		int m = nextInt();

		Person[] p = new Person[n];
		for (int i = 0; i < p.length; i++) {
			p[i] = new Person(nextToken());
		}
		int invalid = 0;

		for (int i = 0; i < m; i++) {
			String t = nextToken();
			int ind1 = t.indexOf('X');
			int ind2 = t.indexOf('X', ind1 + 1);
			if (ind2 == -1 && ind1 != -1) {
				p[ind1].cnt++;
			} else {
				invalid++;
			}
		}

		Arrays.sort(p);

		for (int i = 0; i < p.length; i++) {
			out.println(String.format("%s %.2f%%", p[i].name, 100. * p[i].cnt
					/ m));
		}

		out.println(String.format("%s %.2f%%", "Invalid", 100. * invalid / m));
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("bad.in"));
			out = new PrintWriter("bad.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}

