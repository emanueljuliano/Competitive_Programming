/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem L. Lonely Mountain                                     */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Georgiy Korneev                          */
/* Test set              Georgiy Korneev                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Mikhail Kever                            */
/******************************************************************/

import java.io.*;
import java.util.*;

public class lonely_mk {

	static void solve() throws IOException {
		Point[] xz = readPoints();
		Point[] yz = readPoints();
		int maxZ1 = 0;
		int maxZ2 = 0;
		for (Point p : xz) {
			maxZ1 = Math.max(maxZ1, p.y);
		}
		for (Point p : yz) {
			maxZ2 = Math.max(maxZ2, p.y);
		}
		if (maxZ1 != maxZ2) {
			out.println("Invalid plan");
		} else {
			Set<Integer> alllonely_mkevelsSet = new HashSet<>();
			for (Point p : xz) {
				alllonely_mkevelsSet.add(p.y);
			}
			for (Point p : yz) {
				alllonely_mkevelsSet.add(p.y);
			}
			int[] alllonely_mkevels = new int[alllonely_mkevelsSet.size()];
			int cnt = 0;
			for (int i : alllonely_mkevelsSet) {
				alllonely_mkevels[cnt++] = i;
			}
			Arrays.sort(alllonely_mkevels);
			double[] len1 = lengthPerlonely_mkevel(alllonely_mkevels, xz);
			double[] len2 = lengthPerlonely_mkevel(alllonely_mkevels, yz);
//			System.err.println("levels: " + Arrays.toString(alllonely_mkevels));
//			System.err.println("length for level: " + Arrays.toString(len1));
//			System.err.println("length for level: " + Arrays.toString(len2));

			double volume = 0;
			for (int level = 0; level < alllonely_mkevels.length-1; level ++) {
				double from1 = len1[2 * level+1], to1 = len1[2 * level + 2];
				double from2 = len2[2 * level+1], to2 = len2[2 * level + 2];
				double y = alllonely_mkevels[level + 1] - alllonely_mkevels[level];
				volume += calcVolume(from1, to1, from2, to2, y);
			}
			out.println(volume);
		}
	}

	private static double calcVolume(double from1, double to1, double from2,
			double to2, double y) {
		double k1 = (to1 - from1) / y;
		double k2 = (to2 - from2) / y;

		double result = 0;
		result += k1 * k2 * (y * y * y) / 3;
		result += (from1 * k2 + from2 * k1) * (y * y) / 2;
		result += from1 * from2 * y;
		return result;
	}

	private static double[] lengthPerlonely_mkevel(int[] alllonely_mkevels, Point[] xz) {
		int n = alllonely_mkevels.length;
		double[] add = new double[n];
		double[] eventK = new double[n];

		double[] result = new double[2 * n];

		for (int i = 0; i < xz.length - 1; i++) {
			Point u = xz[i];
			Point v = xz[i + 1];
			int x1 = u.x, x2 = v.x;
			int y1 = u.y, y2 = v.y;

			if (y1 == y2) {
				int pos = Arrays.binarySearch(alllonely_mkevels, y1);
				add[pos] -= x2 - x1;
				continue;
			}

			double k = (double) (x2 - x1) / (double) (y2 - y1);
			int pos1 = Arrays.binarySearch(alllonely_mkevels, y1);
			int pos2 = Arrays.binarySearch(alllonely_mkevels, y2);
			eventK[pos1] += -k;
			eventK[pos2] += k;
		}

		double curK = 0;
		double curVal = xz[xz.length - 1].x - xz[0].x;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				curVal += curK * (alllonely_mkevels[i] - alllonely_mkevels[i - 1]);
			}
			result[2 * i] = curVal;
			curVal += add[i];
			result[2 * i + 1] = curVal;
			curK += eventK[i];
		}

		return result;
	}

	private static Point[] readPoints() throws IOException {
		int n = nextInt();
		Point[] points = new Point[n];
		for (int i = 0; i < n; i++) {
			points[i] = new Point(nextInt(), nextInt());
		}
		return points;
	}

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("lonely.in"));
		out = new PrintWriter("lonely.out");
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

