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
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class dwarf_gk {
    static Scanner in;
    static PrintWriter out;

    class Rule {
        final int c1, c2, r;

        public Rule(Scanner in) {
            r = in.nextInt() - 1;
            c1 = in.nextInt() - 1;
            c2 = in.nextInt() - 1;
        }
    }

    void run() {
        int n = in.nextInt();
        int m = in.nextInt();

        int[] costs = new int[n];
        for (int i = 0; i < n; i++) {
            costs[i] = in.nextInt();
        }

        List<List<Rule>> rules = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            rules.add(new ArrayList<Rule>());
        }

        for (int i = 0; i < m; i++) {
            Rule rule = new Rule(in);
            rules.get(rule.c1).add(rule);
            rules.get(rule.c2).add(rule);
        }

        boolean[] used = new boolean[n];
        for (int i = 0; i < n; i++) {
            int minCost = Integer.MAX_VALUE;
            int minJ = -1;
            for (int j = 0; j < n; j++) {
                if (!used[j] && minCost > costs[j]) {
                    minCost = costs[j];
                    minJ = j;
                }
            }
            used[minJ] = true;
            for (Rule rule : rules.get(minJ)) {
                if (used[rule.c1] && used[rule.c2] && costs[rule.r] > costs[rule.c1] + costs[rule.c2]) {
                    costs[rule.r] = costs[rule.c1] + costs[rule.c2];
                }
            }
        }
        
        out.println(costs[0]);
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("dwarf.in"));
        out = new PrintWriter("dwarf.out");

        new dwarf_gk().run();

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

