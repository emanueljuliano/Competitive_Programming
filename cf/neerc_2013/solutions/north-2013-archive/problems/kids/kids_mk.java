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
/* Author                Mikhail Kever                            */
/******************************************************************/

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class kids_mk {

	static void solve() throws IOException {
		int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
		doTheThing(a, b, c, d);
	}

	private static void doTheThing(int a, int b, int c, int d) {
		int bc = gcd(b, c);
		int girls0 = c / bc, boys0 = b / bc;

		int multiplier = 1;
		while (true) {
			if (girls0 * multiplier < c) {
				++multiplier;
				continue;
			}
			if (boys0 * multiplier < b) {
				++multiplier;
				continue;
			}
			if (!isGood(girls0 * multiplier, a)) {
				++multiplier;
				continue;
			}
			if (!isGood(boys0 * multiplier, d)) {
				++multiplier;
				continue;
			}
			break;
		}

		int girls = girls0 * multiplier, boys = boys0 * multiplier;
		List<Edge> girlGirl = solve(0, girls, a);
		List<Edge> boyBoy = solve(girls, girls + boys, d);
		List<Edge> girlBoy = solveGirlBoy(girls, boys, b, c);
		List<Edge> everything = new ArrayList<>();
		everything.addAll(girlGirl);
		everything.addAll(boyBoy);
		everything.addAll(girlBoy);
		out.println(girls + " " + boys);
		for (Edge edge : everything) {
			out.println((edge.u + 1) + " " + (edge.v + 1));
		}
		out.close();
		checkOurAnswer(girls, boys, everything, a, b, c, d);
	}

	static void checkOurAnswer(int girls, int boys, List<Edge> everything,
			int a, int b, int c, int d) {
		int[] toGirl = new int[girls + boys];
		int[] toBoy = new int[girls + boys];
		@SuppressWarnings("unchecked")
		Set<Edge> set = new HashSet(everything);
		if (set.size() != everything.size()) {
			throw new AssertionError();
		}
		for (Edge edge : everything) {
			int u = edge.u;
			int v = edge.v;
			if (u < girls) {
				++toGirl[v];
			} else {
				++toBoy[v];
			}
			if (v < girls) {
				++toGirl[u];
			} else {
				++toBoy[u];
			}
		}
		for (int i = 0; i < girls; i++) {
			if (toGirl[i] != a) {
				throw new AssertionError();
			}
			if (toBoy[i] != b) {
				throw new AssertionError();
			}
		}
		for (int i = girls; i < girls + boys; i++) {
			if (toGirl[i] != c) {
				throw new AssertionError();
			}
			if (toBoy[i] != d) {
				throw new AssertionError();
			}
		}
	}

	private static List<Edge> solveGirlBoy(int girls, int boys, int girlDeg,
			int boyDeg) {
		List<Edge> result = new ArrayList<>();

		final int[] girl = new int[girls];
		final int[] boy = new int[boys];
		PriorityQueue<Integer> girlsQ = new PriorityQueue<>(girls,
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						return girl[o2] - girl[o1];
					}
				});
		PriorityQueue<Integer> boysQ = new PriorityQueue<>(boys,
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						return boy[o2] - boy[o1];
					}
				});

		result.clear();
		Arrays.fill(girl, girlDeg);
		Arrays.fill(boy, boyDeg);
		girlsQ.clear();
		boysQ.clear();
		for (int i = 0; i < girls; i++) {
			girlsQ.add(i);
		}
		for (int i = 0; i < boys; i++) {
			boysQ.add(i);
		}

		List<Integer> list = new ArrayList<>();
		for (int g = 0; g < girls; g++) {
			for (int j = 0; j < girlDeg; j++) {
				int b = boysQ.poll();
				if (--boy[b] > 0) {
					list.add(b);
				}
				result.add(new Edge(g, b + girls));
			}
			boysQ.addAll(list);
			list.clear();
		}

		return result;
	}

	private static List<Edge> solve(int idFrom, int idTo, int degree) {
		int n = idTo - idFrom;
		List<Edge> result = new ArrayList<>();
		if ((degree & 1) == 0) {
			for (int u = 0; u < n; u++) {
				for (int edge = 1; edge <= degree / 2; edge++) {
					int v = u + edge;
					v = ((v % n) + n) % n;
					result.add(new Edge(u + idFrom, v + idFrom));
				}
			}
		} else {
			for (int u = 0; u < n; u++) {
				for (int edge = 1; edge <= degree / 2; edge++) {
					int v = u + edge;
					v = ((v % n) + n) % n;
					result.add(new Edge(u + idFrom, v + idFrom));
				}
			}
			for (int u = 0; u < n / 2; u++) {
				int v = u + n / 2;
				result.add(new Edge(u + idFrom, v + idFrom));
			}

		}
		return result;
	}

	private static boolean isGood(int n, int deg) {
		if ((deg & n & 1) != 0) {
			return false;
		}
		if (n < deg + 1) {
			return false;
		}
		return true;
	}

	private static int gcd(int a, int b) {
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			} else {
				b %= a;
			}
		}
		return a | b;
	}

	static class Edge {
		int u, v;

		public Edge(int u, int v) {
			if (u > v) {
				int t = u;
				u = v;
				v = t;
			}
			this.u = u;
			this.v = v;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + u;
			result = prime * result + v;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Edge other = (Edge) obj;
			if (u != other.u)
				return false;
			if (v != other.v)
				return false;
			return true;
		}
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("kids.in"));
		out = new PrintWriter("kids.out");
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

