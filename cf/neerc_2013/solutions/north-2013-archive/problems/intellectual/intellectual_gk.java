/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem I. Intellectual Property                               */
/*                                                                */
/* Original idea         Mikhail Dvorkin                          */
/* Problem statement     Yury Petrov                              */
/*                       Georgiy Korneev                          */
/* Test set              Georgiy Korneev                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class intellectual_gk {
    public static final int NP = 6 * 6 * 6 * 6;
    static Scanner in;
    static PrintWriter out;

    void run() {
        int n = in.nextInt();

        int[][][] sudokus = new int[n][9][9];
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < 9; i++) {
                String line = in.next();
                for (int j = 0; j < 9; j++) {
                    sudokus[k][i][j] = line.charAt(j) == '.' ? -1 : line.charAt(j) - '1';
                }
            }
        }

        Map<String, int[]> left = new HashMap<>();
        for (int k = 0; k < n; k++) {
            final int[] cp = perm(0);
            for (int p = 0; p < 2 * NP; p++) {
                String normalized = normalize(sudokus[k], perm(p), cp, p >= NP);
                int[] items = left.get(normalized);
                if (items == null) {
                    items = new int[n];
                    Arrays.fill(items, -1);
                    left.put(normalized, items);
                }
                items[k] = p;
            }
        }

        int[][] perm1 = new int[n][n];
        int[][] perm2 = new int[n][n];
        boolean[][] found = new boolean[n][n];
        for (int j = 0; j < n; j++) {
            int[] rp2 = perm(0);
            for (int p2 = 0; p2 < NP; p2++) {
                int[] p1s = left.get(normalize(sudokus[j], rp2, perm(p2), false));
                if (p1s != null) {
                    for (int i = 0; i < n; i++) {
                        if (p1s[i] != -1) {
                            found[i][j] = true;
                            perm1[i][j] = p1s[i];
                            perm2[i][j] = p2;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (found[i][j]) {
                    ok(sudokus[i], perm1[i][j], sudokus[j], perm2[i][j]);
                } else {
                    out.println("No");
                }
            }
        }
    }

    private void ok(int[][] s1, int p1, int[][] s2, int p2) {
        List<String> actions = actions(p1, "r");
        Collections.reverse(actions);
        actions.addAll(actions(p2, "c"));
        if (p1 >= NP) {
            actions.add(0, "F");
        }

        int[] assignment1 = assignment(s1, perm(p1), perm(0), p1 >= NP);
        int[] assignment2 = assignment(s2, perm(0), perm(p2), false);
        boolean[] used = new boolean[9];
        int[] assignment = new int[9];
        Arrays.fill(assignment, -1);
        for (int i = 0; i < 9; i++) {
            if (assignment1[i] != -1) {
                for (int j = 0; j < 9; j++) {
                    if (assignment2[j] == assignment1[i]) {
                        assignment[j] = i;
                        used[i] = true;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            if (!used[i]) {
                for (int j = 0; j < 9; j++) {
                    if (assignment[j] == -1) {
                        assignment[j] = i;
                        break;
                    }
                }
            }
        }

        for (int[] swap : swaps(assignment)) {
            actions.add(String.format("D %d %d", swap[0] + 1, swap[1] + 1));
        }

        out.println("Yes");
        out.println(actions.size());
        for (String action : actions) {
            out.println(action);
        }
    }

    private List<String> actions(int p, String s) {
        List<String> actions = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            for (int[] swap : swaps(r(p, i))) {
                actions.add(String.format("%s %d %d", s, swap[0] + i * 3 + 1, swap[1] + i * 3 + 1));
            }
        }
        for (int[] swap : swaps(r(p, 3))) {
            actions.add(String.format("%s %d %d", s.toUpperCase(), swap[0] + 1, swap[1] + 1));
        }
        return actions;
    }

    private String normalize(int[][] sudoku, int[] rp, int[] cp, boolean transpose) {
        int[] assignment = assignment(sudoku, rp, cp, transpose);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int d = transpose ? sudoku[cp[j]][rp[i]] : sudoku[rp[i]][cp[j]];
                sb.append(d == -1 ? '.' : '1' + assignment[d]);
            }
        }
        return sb.toString();
    }

    private int[] assignment(int[][] sudoku, int[] rp, int[] cp, boolean transpose) {
        int[] assignment = new int[9];
        Arrays.fill(assignment, -1);
        int c = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int d = transpose ? sudoku[cp[j]][rp[i]] : sudoku[rp[i]][cp[j]];
                if (d != -1) {
                    if (assignment[d] == -1) {
                        assignment[d] = c++;
                    }
                }
            }
        }
        return assignment;
    }

    private int[][] PERMS = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

    private int[][] swaps(int[] perm) {
        perm = perm.clone();
        List<int[]> swaps = new ArrayList<>();
        for (int i = 0; i < perm.length; i++) {
            if (perm[i] != i) {
                for (int j = i + 1; j < perm.length; j++) {
                    if (perm[j] == i) {
                        swaps.add(new int[]{i, j});
                        perm[j] = perm[i];
                        perm[i] = i;
                    }
                }
            }
        }
        Collections.reverse(swaps);
        return swaps.toArray(new int[swaps.size()][]);
    }

    private int[] perm(int p) {
        int[] perm = new int[9];
        for (int i = 0; i < 9; i++) {
            int k = r(p, 3)[i / 3];
            perm[k * 3 + r(p, k)[i % 3]] = i;
        }
        return perm;
    }

    int[] P = {1, 6, 6 * 6, 6 * 6 * 6 };
    private int[] r(int p, int k) {
        return PERMS[(p / P[k]) % 6];
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("intellectual.in"));
        out = new PrintWriter("intellectual.out");

        new intellectual_gk().run();

        in.close();
        out.close();
    }
}

