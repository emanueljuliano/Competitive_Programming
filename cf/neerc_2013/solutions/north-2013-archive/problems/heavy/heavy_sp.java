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
/* Author                Sergey Poromov                           */
/******************************************************************/

import java.util.*;
import java.io.*;

public class heavy_sp implements Runnable {
    public static void main(String[] args) {
        new Thread(new heavy_sp()).start();
    }

    @Override
    public void run() {
        try {
            br = new BufferedReader(new FileReader("heavy.in"));
            out = new PrintWriter("heavy.out");
            solve();
            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(566);
        }
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
    boolean eof = false;

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    ArrayList<Integer>[] G;
    boolean[] u;
    int[] pair;

    ArrayList<Integer>[] G2;
    boolean[] u2;

    boolean dfs(int i) {
        if (u[i]) return false;
        u[i] = true;
        for (int j : G[i]) {
            if (pair[j] == -1 || dfs(pair[j])) {
                pair[j] = i;
                return true;
            }
        }
        return false;
    }

    void dfs2(int i) {
        u2[i] = true;
        for (int j : G2[i]) {
            if (!u2[j]) {
                dfs2(j);
            }
        }
    }

    void solve() {
        int n = nextInt();
        int k = nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = nextToken();
        }
        TreeMap<String, Integer> starts = new TreeMap<>();
        TreeMap<String, Integer> ends = new TreeMap<>();
        int[] from = new int[n];
        int[] to = new int[n];
        for (int i = 0; i < n; i++) {
            String start = s[i].substring(0, Math.min(k, s[i].length()));
            String end = s[i].substring(s[i].length() - Math.min(s[i].length(), k));
            if (!starts.containsKey(start)) {
                starts.put(start, starts.size());
            }
            if (!ends.containsKey(end)) {
                ends.put(end, ends.size());
            }
            from[i] = starts.get(start);
            to[i] = ends.get(end);
        }
        int l = starts.size();
        int r = ends.size();
        G = new ArrayList[l];
        u = new boolean[l];
        pair = new int[r];
        Arrays.fill(pair, -1);
        for (int i = 0; i < l; i++) {
            G[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            G[from[i]].add(to[i]);
        }
        int ans = 0;
        for (int i = 0; i < l; i++) {
            Arrays.fill(u, false);
            if (dfs(i)){
                ans++;
            }
        }

        out.println(ans);

        G2 = new ArrayList[l + r];
        u2 = new boolean[l + r];
        boolean[] pairL = new boolean[l];
        for (int i = 0; i < G2.length; i++) {
            G2[i] = new ArrayList<>();
        }
        for (int i = 0; i < l; i++) {
            for (int j : G[i]) {
                if (pair[j] == i) {
                    G2[j + l].add(i);
                    pairL[i] = true;
                } else {
                    G2[i].add(j + l);
                }
            }
        }
        for (int i = 0; i < l; i++) {
            if (!pairL[i]) {
                dfs2(i);
            }
        }

        ArrayList<Integer>[] groups = new ArrayList[l + r];
        for (int i = 0; i < groups.length; i++) {
            if ((i < l) ^ u2[i]) {
                groups[i] = new ArrayList<>();
            }
        }
        for (int i = 0; i < n; i++) {
            if (groups[from[i]] != null) {
                groups[from[i]].add(i);
            } else if (groups[to[i] + l] != null) {
                groups[to[i] + l].add(i);
            }
        }
        for (int i = 0; i < groups.length; i++) {
            if (groups[i] != null && groups[i].size() > 0) {
                out.print(groups[i].size());
                for (int j : groups[i]) {
                    out.print(" " + (j + 1));
                }
                out.println();
            }
        }
    }
}

