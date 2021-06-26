/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem F. Flight Boarding Optimization                        */
/*                                                                */
/* Original idea         Pavel Mavrin                             */
/* Problem statement     Pavel Mavrin                             */
/* Test set              Pavel Mavrin                             */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class flight_va {
	public static void main(String[] args) {
		new flight_va().run();
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

	private int[] add;

	private void set(int i, int x) {
		while (i < add.length) {
			add[i] += x;
			i = i | (i + 1);
		}
	}

	private int sum(int i) {
		int ans = 0;
		while (i > 0) {
			ans += add[i];
			i = (i & (i + 1)) - 1;
		}
		return ans;
	}

	public void solve() throws IOException {
		int n = nextInt();
		int s = nextInt();
		int k = nextInt();

		ArrayList<Integer>[] a = new ArrayList[s];
		for (int i = 0; i < a.length; i++) {
			a[i] = new ArrayList<>();
		}

		for (int i = 0; i < n; i++) {
			a[nextInt() - 1].add(i + 1);
		}

		int[][] sum = new int[s][s];

		add = new int[n + 1];

		for (int i = 0; i < sum.length; i++) {
			Arrays.fill(add, 0);
			for (int j = i; j < sum[0].length; j++) {
				sum[i][j] = i == j ? 0 : sum[i][j - 1];
				for (int q = a[j].size() - 1; q >= 0; q--) {
					sum[i][j] += sum(a[j].get(q));
					set(a[j].get(q), 1);
				}
			}
		}

		int[][] ans = new int[k][s];

		for (int i = 0; i < ans.length; i++) {
			Arrays.fill(ans[i], Integer.MAX_VALUE / 2);
		}

		for (int i = 0; i < ans[0].length; i++) {
			ans[0][i] = sum[0][i];
		}

		int res = ans[0][s - 1];
		for (int kk = 1; kk < k; kk++) {
			for (int i = 1; i < s; i++) {
				for (int j = 0; j < i; j++) {
					ans[kk][i] = Math.min(ans[kk - 1][j] + sum[j + 1][i],
							ans[kk][i]);
					if (i == s - 1)
						res = Math.min(res, ans[kk][i]);
				}
			}
		}

		out.println(res);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("flight.in"));
			out = new PrintWriter("flight.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

