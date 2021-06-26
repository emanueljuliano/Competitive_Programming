/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem E. Energy Tycoon                                       */
/*                                                                */
/* Original idea         Vitaly Aksenov                           */
/* Problem statement     Vitaly Aksenov                           */
/* Test set              Vitaly Aksenov                           */
/******************************************************************/
/* Tests                                                          */
/*                                                                */
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class Tests {
    private Random rnd = new Random(239533);
    private int tests = 1;
    private final int MAXN = 100_000;
    private final int MAXM = 100_000;

    public void writeTest(int n, int[] c) {
        try {
            PrintWriter out = new PrintWriter(String.format("tests/%02d", tests++));

            out.println(n);
            for (int i = 0; i < c.length; i++) {
                out.print(c[i]);
            }
            out.println();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void genRandomTest(int n, int m) {
        int[] c = new int[m];
        for (int i = 0; i < c.length; i++) {
            c[i] = rnd.nextInt(2) + 1;
        }
        writeTest(n, c);
    }

    public void genEasyTest(int n, int m, int div) {
        int[] c = new int[m];
        for (int i = 0; i < div; i++) {
            c[i] = 2;
        }
        for (int i = div; i < c.length; i++) {
            c[i] = 1;
        }
        writeTest(n, c);
    }

    public void genToLongTest(int n, int m) {
        int[] c = new int[m];
        for (int i = 0; i < c.length; i++) {
            c[i] = 1;
        }
        writeTest(n, c);
    }

    public void gen() {
        writeTest(3, new int[] { 2, 1, 1, 2, 1 });
        writeTest(2, new int[] { 1, 2 });
        writeTest(2, new int[] { 2, 1, 1 });

        genEasyTest(1, 10, 5);
        genEasyTest(1, 10, 6);
        for (int i = 0; i < 4; i++) {
            int m = rnd.nextInt(10) + 1;
            genEasyTest(rnd.nextInt(9) + 2, m, rnd.nextInt(m + 1));
        }
        genToLongTest(10, 10);
        for (int i = 0; i < 4; i++) {
            genRandomTest(rnd.nextInt(10) + 1, rnd.nextInt(10) + 1);
        }

        for (int i = 0; i < 4; i++) {
            int m = rnd.nextInt(100) + 1;
            genEasyTest(rnd.nextInt(99) + 2, m, rnd.nextInt(m + 1));
        }
        for (int i = 0; i < 4; i++) {
            genRandomTest(rnd.nextInt(100) + 1, rnd.nextInt(100) + 1);
        }

        for (int i = 0; i < 4; i++) {
            int m = rnd.nextInt(MAXM) + 1;
            genEasyTest(rnd.nextInt(MAXN - 1) + 2, m, rnd.nextInt(m + 1));
        }
        for (int i = 0; i < 4; i++) {
            genRandomTest(rnd.nextInt(MAXN) + 1, rnd.nextInt(MAXM) + 1);
        }

        genToLongTest(MAXN, MAXM);
        for (int i = 0; i < 4; i++) {
            genEasyTest(MAXN, MAXM, rnd.nextInt(MAXM + 1));
        }
        for (int i = 0; i < 4; i++) {
            genRandomTest(MAXN, MAXM);
        }
    }

    public static void main(String[] args) {
        new Tests().gen();
    }
}

