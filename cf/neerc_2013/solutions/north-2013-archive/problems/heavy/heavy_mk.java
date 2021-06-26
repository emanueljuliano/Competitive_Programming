/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem H. Heavy Chain Clusterization                          */
/*                                                                */
/* Original idea         Yury Petrov                              */
/* Problem statement     Sergey Poromov                           */
/*                       Mikhail Dvorkin                          */
/* Test set              Sergey Poromov                           */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Mikhail Kever                            */
/******************************************************************/

import java.io.*;
import java.util.*;

public class heavy_mk {

	static void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextToken();
		}

		Map<String, Integer> idPrefix = new HashMap<String, Integer>();
		Map<String, Integer> idSuffix = new HashMap<String, Integer>();
		Integer[] prefixId = new Integer[n];
		Integer[] suffixId = new Integer[n];
		for (int i = 0; i < n; i++) {
			String prefix = s[i].substring(0, k);
			String suffix = s[i].substring(s[i].length() - k);
			prefixId[i] = get(idPrefix, prefix);
			suffixId[i] = get(idSuffix, suffix);
		}

		Graph graph = new Graph(idPrefix.size(), idSuffix.size());
		for (int i = 0; i < n; i++) {
			graph.addEdge(prefixId[i], suffixId[i]);
		}
		boolean[][] results = graph.doTheMatching();
		boolean[] takePrefix = results[0], takeSuffix = results[1];
		int components = 0;
		int[] componentPrefix = new int[idPrefix.size()];
		int[] componentSuffix = new int[idSuffix.size()];
		for (int i = 0; i < idPrefix.size(); i++) {
			if (takePrefix[i]) {
				componentPrefix[i] = components++;
			}
		}
		for (int i = 0; i < idSuffix.size(); i++) {
			if (takeSuffix[i]) {
				componentSuffix[i] = components++;
			}
		}
		List<Integer>[] listForComponent = new List[components];
		for (int i = 0; i < components; i++) {
			listForComponent[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			if (takePrefix[prefixId[i]]) {
				listForComponent[componentPrefix[prefixId[i]]].add(i);
			} else {
				if (takeSuffix[suffixId[i]]) {
					listForComponent[componentSuffix[suffixId[i]]].add(i);
				} else {
					throw new AssertionError();
				}
			}
		}
		out.println(components);
		for (List<Integer> list : listForComponent) {
			out.print(list.size());
			for (int i = 0; i < list.size(); i++) {
				out.print(' ');
				out.print(list.get(i) + 1);
			}
			out.println();
		}
	}

	static class Graph {
		List<Integer>[] edges;
		int[] match1;
		int[] match2;
		int n, m;

		int[] visited;

		@SuppressWarnings("unchecked")
		Graph(int n, int m) {
			edges = new List[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new ArrayList<>();
			}
			match1 = new int[n];
			match2 = new int[m];
			visited = new int[n];
			this.n = n;
			this.m = m;
			Arrays.fill(match1, -1);
			Arrays.fill(match2, -1);
		}

		void addEdge(int u, int v) {
			edges[u].add(v);
		}

		int dfsTime;

		boolean dfs(int u) {
			visited[u] = dfsTime;
			for (int v : edges[u]) {
				if (match2[v] < 0) {
					match2[v] = u;
					match1[u] = v;
					return true;
				}
			}
			for (int v : edges[u]) {
				if (visited[match2[v]] != dfsTime && dfs(match2[v])) {
					match2[v] = u;
					match1[u] = v;
					return true;
				}
			}
			return false;
		}

		boolean[][] doTheMatching() {
			Arrays.fill(match1, -1);
			Arrays.fill(match2, -1);
			Arrays.fill(visited, -1);
			for (int i = 0; i < n; i++) {
				dfsTime = i;
				if (match1[i] < 0) {
					dfs(i);
				}
			}

			Arrays.fill(visited, -1);
			dfsTime = 1;

			for (int i = 0; i < n; i++) {
				if (match1[i] < 0) {
					dfs(i);
				}
			}

			boolean[] result1 = new boolean[n];
			for (int i = 0; i < n; i++) {
				result1[i] = visited[i] < 0;
			}

			boolean[] result2 = new boolean[m];
			for (int i = 0; i < n; i++) {
				if (visited[i] > 0) {
					for (int j : edges[i]) {
						result2[j] = true;
					}
				}
			}
			return new boolean[][] { result1, result2 };
		}
	}

	private static <T> Integer get(Map<T, Integer> id, T key) {
		Integer result = id.get(key);
		if (result == null) {
			result = id.size();
			id.put(key, result);
		}
		return result;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("heavy.in"));
		out = new PrintWriter("heavy.out");
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

