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
/* Tests                                                          */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class Tests {
    int testNo = 0;
    PrintWriter out;
    static PrintWriter descriptions;
    Random random = new Random(7023842358235832895L);

    static final int MAX_N = 20;
    enum Op {
        r, R, c, C, D, F
    }

    void beginTest(String description, Object... args) {
        ++testNo;
        descriptions.format("%02d: %s\n", testNo, String.format(description, args));
        descriptions.flush();
        System.out.format("%02d: %s\n", testNo, String.format(description, args));
        try {
            out = new PrintWriter(String.format("tests/%02d", testNo));
        } catch (FileNotFoundException e) {
            throw new AssertionError(e);
        }
    }

    int randomInt(int from, int to) {
        return random.nextInt(to - from) + from;
    }

    int randomAlmost(int n) {
        return randomInt(n - (int) Math.log(n), n);
    }

    private void endTest(List<String> sudokus, Set<Op> ops) {
        assert 1 <= sudokus.size() && sudokus.size() <= MAX_N;
        out.println(sudokus.size());
        for (int i = 0 ; i < sudokus.size(); i++) {
            String b = sudokus.get(i);
            if (i != 0) {
                out.println();
            }
            write(shuffle(b, ops));
        }
        out.close();
    }

    private int[][] PERMS = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    String shuffle(String sudoku, Set<Op> ops) {
        int[] assignment = new int[10];
        for (int i = 1; i <= 9; i++) {
            int j = ops.contains(Op.D) ? 1 + randomInt(0, i) : i;
            assignment[i] = assignment[j];
            assignment[j] = i;
        }

        int[][] cp = new int[][]{PERMS[randomOp(ops, Op.c, 3)], PERMS[randomOp(ops, Op.c, 3)], PERMS[randomOp(ops, Op.c, 3)], PERMS[randomOp(ops, Op.C, 3)]};
        int[][] rp = new int[][]{PERMS[randomOp(ops, Op.r, 3)], PERMS[randomOp(ops, Op.r, 3)], PERMS[randomOp(ops, Op.r, 3)], PERMS[randomOp(ops, Op.R, 3)]};
        StringBuilder sb = new StringBuilder();
        int ic = ops.contains(Op.F) && random.nextBoolean() ? 1 : 9;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int rt = rp[3][i / 3];
                int ct = cp[3][j / 3];
                sb.append((char) ('0' + assignment[sudoku.charAt((rt * 3 + rp[rt][i % 3]) * ic + (ct * 3 + cp[ct][j % 3]) * (10 - ic)) - '0']));
            }
        }

        return sb.toString();
    }

    private int randomOp(Set<Op> ops, Op v, int to) {
        return ops.contains(v) ? randomInt(0, to) : 0;
    }

    void write(String sudoku) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = sudoku.charAt(i * 9 + j);
                out.print(".123456789".charAt(ch - '0'));
            }
            out.println();
        }
    }

    boolean[] randomHoles(int holes) {
        int[] p = new int[81];
        for (int i = 0; i < p.length; i++) {
            int j = randomInt(0, i + 1);
            p[i] = p[j];
            p[j] = i;
        }

        boolean[] h = new boolean[81];
        for (int i = 0; i < holes; i++) {
            h[p[i]] = true;
        }
        return h;
    }

    String holes(String sudoku, boolean[] holes) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 81; i++) {
            sb.append(holes[i] ? "0" : sudoku.charAt(i));
        }
        return sb.toString();
    }

    void test(int n, int distinct, Set<Op> ops, int minHoles, boolean correlatedHoles) {
        test(n, distinct, ops, minHoles, 0, correlatedHoles);
    }

    private void test(int n, int distinct, Set<Op> ops, int minHoles, int dHoles, boolean correlatedHoles) {
        beginTest(
                "%d (%d distinct) Sudokus with %s %s holes, ops=%s",
                n,
                distinct,
                dHoles == 0 ? "" + minHoles : minHoles + ".." + (minHoles + dHoles),
                correlatedHoles ? "correlated" : "random",
                ops
        );
        String[] base = new String[distinct];
        boolean[] holes = randomHoles(randomInt(minHoles, minHoles + dHoles + 1));
        for (int i = 0; i < distinct; i++) {
            if (!correlatedHoles) {
                holes = randomHoles(randomInt(minHoles, minHoles + dHoles + 1));
            }
            base[i] = holes(randomSudoku(), holes);
        }
        List<String> sudokus = new ArrayList<>(Arrays.asList(base));
        for (int i = distinct; i < n; i++) {
            sudokus.add(base[randomInt(0, distinct)]);
        }
        Collections.shuffle(sudokus, random);
        endTest(sudokus, ops);
    }

    public void run() throws IOException {
        sampleTest();

        for (Op op : Op.values()) {
            test(5, 3, EnumSet.of(op), 70, true);
        }
        test(5, 3, EnumSet.of(Op.r, Op.R), randomInt(0, 82), random.nextBoolean());
        test(5, 3, EnumSet.of(Op.c, Op.C), randomInt(0, 82), random.nextBoolean());
        test(5, 3, EnumSet.of(Op.r, Op.c), randomInt(0, 82), random.nextBoolean());
        test(5, 3, EnumSet.of(Op.R, Op.C), randomInt(0, 82), random.nextBoolean());
        test(5, 3, EnumSet.of(Op.D, Op.F), randomInt(0, 82), random.nextBoolean());
        test(5, 3, EnumSet.allOf(Op.class), randomInt(0, 82), random.nextBoolean());

        for (int i = 6; i < MAX_N; i++) {
            test(i, 1, EnumSet.allOf(Op.class), randomInt(0, 82), random.nextBoolean());
            test(i, i, EnumSet.allOf(Op.class), randomInt(0, 82), random.nextBoolean());
            test(i, i / 2, EnumSet.allOf(Op.class), randomInt(0, 82), random.nextBoolean());
        }

        for (int d  : new int[]{81, 10, 2, 1}) {
            test(MAX_N, 1 + randomInt(0, 2), EnumSet.allOf(Op.class), randomInt(0, 81 - d + 1), d, false);
            test(MAX_N, randomAlmost(MAX_N), EnumSet.allOf(Op.class), randomInt(0, 81 - d + 1), d, false);
            test(MAX_N, randomInt(MAX_N / 3, MAX_N * 2 / 3), EnumSet.allOf(Op.class), randomInt(0, 81 - d + 1), d, false);

        }

        for (int h : new int[]{0, 2, 79, 80, 81}) {
            for (int i = 0; i < (h >= 80 ? 1 : 2); i++) {
                test(MAX_N, 1 + randomInt(0, 2), EnumSet.allOf(Op.class), h, i % 2 == 0);
                test(MAX_N, MAX_N, EnumSet.allOf(Op.class), h, i % 2 == 0);
                test(MAX_N, randomInt(MAX_N / 3, MAX_N * 2 / 3), EnumSet.allOf(Op.class), h, i % 2 == 0);
            }
        }
    }

    private void sampleTest() {
        beginTest("Sample");
        endTest(
                Arrays.asList(
                        "000001000100000000020000080000000000800009000000000000000070000000200010200040000",
                        "000020000000704000800000009080002001002000000000000000000000000001080000000000000",
                        "100000000000000000000000000000000000000000000000000000000000000000000000000000000",
                        "000001000100000000020000080000000000800009000000000000000070000000200010200040000"
                ),
                EnumSet.noneOf(Tests.Op.class)
        );
    }

    class Generator {
        boolean[][] rows = new boolean[9][9];
        boolean[][] cols = new boolean[9][9];
        boolean[][] blocks = new boolean[9][9];
        char[] field = new char[81];

        Generator() {
            run(0);
        }

        boolean run(int i) {
            if (i == 81) {
                return true;
            }
            int[] ds = new int[9];
            for (int j = 0; j < 9; j++) {
                int k = randomInt(0, j + 1);
                ds[k] = j;
                ds[j] = j;
            }
            for (int d : ds) {
                field[i] = (char) ('1' + d);
                if (!rows[i / 9][d] && !cols[i % 9][d] && !blocks[i / 27 * 3 + i % 9 / 3][d]) {
                    rows[i / 9][d] = true;
                    cols[i % 9][d] = true;
                    blocks[i / 27 * 3 + i % 9 / 3][d] = true;
                    if (run(i + 1)) {
                        return true;
                    }
                    rows[i / 9][d] = false;
                    cols[i % 9][d] = false;
                    blocks[i / 27 * 3 + i % 9 / 3][d] = false;
                }
            }
            return false;
        }
    }

    private String randomSudoku() {
        return new String(new Generator().field);
    }


    public static void main(String[] args) throws IOException {
        descriptions = new PrintWriter("tests/tests.lst");
        new Tests().run();
        descriptions.close();
    }
}

