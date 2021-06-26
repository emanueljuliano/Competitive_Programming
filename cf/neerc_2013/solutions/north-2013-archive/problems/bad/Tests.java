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
/* Tests                                                          */
/*                                                                */
/* Author                Andrew Stankevich                        */
/******************************************************************/

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Tests {
    class Test {
        String[] s;
        boolean[][] v;

        Test(String[] s, boolean[][] v) {
            this.s = s;
            this.v = v;
        }
    }

    int testNo = 1;

    public void printTest(Test test) {
        PrintWriter out = null;
        try {
            new File("tests").mkdir();
            out = new PrintWriter("tests/" + testNo / 10 + testNo % 10);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return;
        }

        out.println(test.s.length + " " + test.v.length);
        for (String s : test.s) {
            out.println(s);
        }
        for (boolean[] z : test.v) {
            for (boolean x : z) {
                out.print(x ? "X" : ".");
            }
            out.println();
        }

        out.close();
        testNo++;
    }

    Random rnd = new Random(4290018901376482L);

    String randomString(int len) {
        StringBuilder r = new StringBuilder();
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                r.append((char) ('A' + rnd.nextInt(26)));
            } else {
                r.append((char) ('a' + rnd.nextInt(26)));
            }
        }
        return r.toString();
    }

    String[] randomStringArray(int n, int minL, int maxL) {
        Set<String> used = new HashSet<>();
        String[] r = new String[n];
        for (int i = 0; i < n; i++) {
            String s;
            do {
                s = randomString(minL + rnd.nextInt(maxL - minL + 1));
            } while (used.contains(s));
            used.add(s);
            r[i] = s;
        }
        return r;
    }

    void printRandom(int n, int m, int pInvalid) {
        String[] names = randomStringArray(n, 1, 100);
        boolean[][] votes = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            if (rnd.nextInt(100) < pInvalid) {
                if (rnd.nextBoolean()) {
                    continue;
                } else {
                    int t = 2 + rnd.nextInt(n - 1);
                    for (int j = 0; j < t; j++) {
                        votes[i][j] = true;
                    }
                    for (int j = 0; j < n; j++) {
                        int k = rnd.nextInt(j + 1);
                        boolean tmp = votes[i][j]; votes[i][j] = votes[i][k]; votes[i][k] = tmp;
                    }
                }
            } else {
                votes[i][rnd.nextInt(n)] = true;
            }
        }
        printTest(new Test(names, votes));
    }

    void printGeometric(int n, int m, int pInvalid) {
        String[] names = randomStringArray(n, 1, 100);
        boolean[][] votes = new boolean[m][n];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            int j = rnd.nextInt(n);
            p[i] = p[j];
            p[j] = i;
        }
        for (int i = 0; i < m; i++) {
            if (rnd.nextInt(100) < pInvalid) {
                if (rnd.nextBoolean()) {
                    continue;
                } else {
                    int t = 2 + rnd.nextInt(n - 1);
                    for (int j = 0; j < t; j++) {
                        votes[i][j] = true;
                    }
                    for (int j = 0; j < n; j++) {
                        int k = rnd.nextInt(j + 1);
                        boolean tmp = votes[i][j]; votes[i][j] = votes[i][k]; votes[i][k] = tmp;
                    }
                }
            } else {
                int j = 0;
                while (rnd.nextBoolean() && j < n - 1) {
                    j++;
                }
                votes[i][p[j]] = true;
            }
        }
        printTest(new Test(names, votes));
    }

    void printDoubleGeometric(int n, int m, int pInvalid) {
        String[] names = randomStringArray(n, 1, 100);
        boolean[][] votes = new boolean[m][n];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            int j = rnd.nextInt(n);
            p[i] = p[j];
            p[j] = i;
        }
        for (int i = 0; i < m; i++) {
            if (rnd.nextInt(100) < pInvalid) {
                if (rnd.nextBoolean()) {
                    continue;
                } else {
                    int t = 2 + rnd.nextInt(n - 1);
                    for (int j = 0; j < t; j++) {
                        votes[i][j] = true;
                    }
                    for (int j = 0; j < n; j++) {
                        int k = rnd.nextInt(j + 1);
                        boolean tmp = votes[i][j]; votes[i][j] = votes[i][k]; votes[i][k] = tmp;
                    }
                }
            } else {
                int j = 0;
                while (rnd.nextInt(3) == 0 && j < n - 1) {
                    j++;
                }
                votes[i][p[j]] = true;
            }
        }
        printTest(new Test(names, votes));
    }

    void printEmpty(int n, int m) {
        String[] names = randomStringArray(n, 1, 100);
        boolean[][] votes = new boolean[m][n];
        printTest(new Test(names, votes));
    }

    void printFull(int n, int m) {
        String[] names = randomStringArray(n, 1, 100);
        boolean[][] votes = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(votes[i], true);
        }
        printTest(new Test(names, votes));
    }

    void printDagestan(int n, int m) {
        String[] names = randomStringArray(n, 1, 100);
        boolean[][] votes = new boolean[m][n];
        int j = rnd.nextInt(n);
        for (int i = 0; i < m; i++) {
            votes[i][j] = true;
        }
        printTest(new Test(names, votes));
    }

    public void run() {
        Test t = new Test(new String[]{"Loudy", "Apples", "Dogman", "Miller"},
                new boolean[][]{
                    {false, true, false, false},
                    {true, false, false, false},
                    {false, false, false, false},
                    {false, false, true, false},
                    {false, false, true, true},
                    {false, false, true, false},
                    {false, false, true, false}
                }
        );
        printTest(t);
        printRandom(2, 10, 0);
        printRandom(2, 1, 0);
        printRandom(3, 20, 0);
        printRandom(10, 1000, 0);
        printRandom(2, 10, 10);
        printRandom(3, 20, 10);
        printRandom(10, 1000, 10);
        printRandom(2, 10, 50);
        printRandom(3, 20, 50);
        printRandom(10, 1000, 50);
        printRandom(2, 10, 100);
        printRandom(3, 20, 100);
        printRandom(10, 1000, 100);

        printEmpty(2, 10);
        printEmpty(10, 1000);
        printFull(2, 10);
        printFull(10, 1000);

        printGeometric(10, 32, 0);

        printDagestan(2, 10);
        printDagestan(10, 1000);

        printGeometric(2, 10, 0);
        printGeometric(2, 1, 0);
        printGeometric(3, 20, 0);
        printGeometric(10, 1000, 0);
        printGeometric(2, 10, 10);
        printGeometric(3, 20, 10);
        printGeometric(10, 1000, 10);
        printGeometric(2, 10, 50);
        printGeometric(3, 20, 50);
        printGeometric(10, 1000, 50);

        printRandom(10, 901, 20);
        printRandom(10, 997, 20);
        printRandom(10, 999, 20);
        printGeometric(10, 901, 20);
        printGeometric(10, 997, 20);
        printGeometric(10, 999, 20);
        printDoubleGeometric(10, 901, 20);
        printDoubleGeometric(10, 997, 20);
        printDoubleGeometric(10, 999, 20);
        printRandom(10, 701, 20);
        printRandom(10, 797, 20);
        printRandom(10, 799, 20);
        printGeometric(10, 701, 20);
        printGeometric(10, 797, 20);
        printGeometric(10, 799, 20);
        printDoubleGeometric(10, 701, 20);
        printDoubleGeometric(10, 797, 20);
        printDoubleGeometric(10, 799, 20);
        printRandom(10, 128, 20);
        printRandom(10, 256, 20);
        printRandom(10, 512, 20);
        printGeometric(10, 128, 20);
        printGeometric(10, 256, 20);
        printGeometric(10, 512, 20);
        printDoubleGeometric(10, 128, 20);
        printDoubleGeometric(10, 256, 20);
        printDoubleGeometric(10, 512, 20);
    }

    public static void main(String[] args) {
        new Tests().run();
    }
}


