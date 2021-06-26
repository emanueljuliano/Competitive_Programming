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
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class heavy_gk {
    static Scanner in;
    static PrintWriter out;

    class Side {
        List<List<Integer>> edges = new ArrayList<>();
        Map<String, Integer> indices = new HashMap<>();
        Map<Integer, Set<Integer>> ids = new HashMap<>();

        public Integer add(String v, int id) {
            Integer index = indices.get(v);
            if (index == null) {
                index = indices.size();
                indices.put(v, index);
                ids.put(index, new HashSet<Integer>());
                edges.add(new ArrayList<Integer>());
            }
            ids.get(index).add(id);
            return index;
        }
    }

    Side left = new Side();
    Side right = new Side();

    Integer[] back;
    boolean[] useL, useR;

    void run() {
        int n = in.nextInt();
        int k = in.nextInt();

        for (int i = 0; i < n; i++) {
            String chain = in.next();
            Integer l = left.add(chain.substring(0, k), i + 1);
            Integer r = right.add(chain.substring(chain.length() - k), i + 1);
            left.edges.get(l).add(r);
        }

        int ls = left.indices.size();
        int rs = right.indices.size();

        back = new Integer[rs];
        Arrays.fill(back, -1);

        useL = new boolean[ls];
        useR = new boolean[rs];
        boolean[] ansL = new boolean[ls];
        int answer = 0;
        for (int i = 0; i < ls; i++) {
            Arrays.fill(useL, false);
            ansL[i] = dfs(i);
            if (ansL[i]) {
                answer++;
            }
        }

        Arrays.fill(useL, false);
        Arrays.fill(useR, false);

        for (int i = 0; i < ls; i++) {
            if (!ansL[i]) {
                dfs(i);
            }
        }

        Set<Integer> used = new HashSet<>();
        out.println(answer);
        for (int i = 0; i < ls; i++) {
            if (!useL[i]) {
                dump(left.ids.get(i), used);
            }
        }

        for (int i = 0; i < rs; i++) {
            if (useR[i]) {
                dump(right.ids.get(i), used);
            }
        }
    }

    private void dump(Set<Integer> ids, Set<Integer> used) {
        ids.removeAll(used);
        used.addAll(ids);
        out.print(ids.size());
        for (int id : ids) {
            out.print(" " + id);
        }
        out.println();
    }

    private boolean dfs(Integer i) {
        if (useL[i]) {
            return false;
        }
        useL[i] = true;
        for (Integer j : left.edges.get(i)) {
            useR[j] = true;
            if (back[j] == -1 || dfs(back[j])) {
                back[j] = i;
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("heavy.in"));
        out = new PrintWriter("heavy.out");

        new heavy_gk().run();

        in.close();
        out.close();
    }

    static class Scanner {
        final BufferedReader reader;
        StringTokenizer tokenizer = new StringTokenizer("");

        public Scanner(File file) throws FileNotFoundException {
            reader = new BufferedReader(new FileReader(file));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (!tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new AssertionError();
                }
            }
            return tokenizer.nextToken();
        }

        public void close() {
        }
    }
}

