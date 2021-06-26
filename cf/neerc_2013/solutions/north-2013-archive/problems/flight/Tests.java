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
/* Tests                                                          */
/*                                                                */
/* Author                Pavel Mavrin                             */
/******************************************************************/

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

public class Tests {

    private static final int MAX_N = 1000;
    private static final int MAX_S = 1000;
    private static final int MAX_K = 50;

    int testNumber = 0;

    void printTest(int n, int s, int k, int[] a) throws FileNotFoundException {
        testNumber++;
        PrintWriter out = new PrintWriter("tests/" + String.format("%02d", testNumber));

        myAssert(n >= 1 && n <= MAX_N);
        myAssert(s >= 1 && s <= MAX_S);
        myAssert(k >= 1 && k <= MAX_K && k <= s);
        int[] q = new int[s];
        for (int i = 0; i < n; i++) {
            myAssert(a[i] >= 0 && a[i] < s);
            q[a[i]]++;
        }
        for (int i = 0; i < s; i++) {
            myAssert(q[i] <= 6);
        }
        out.println(n + " " + s + " " + k);
        for (int i = 0; i < n; i++) {
            out.print(a[i] + 1);
            if (i == n - 1)
                out.println();
            else
                out.print(" ");
        }

        out.close();
    }

    private void myAssert(boolean b) {
        if (!b) throw new AssertionError();
    }

    public static void main(String[] args) throws IOException {
        new Tests().run();
    }

    private void run() throws IOException {
        new File("tests").mkdir();

        printTest(10, 12, 2, new int[]{5, 3, 1, 4, 1, 2, 0, 10, 7, 4});

        printRandomTest(10, 8, 2);
        printRandomTest(11, 13, 3);
        printRandomTest(12, 10, 4);
        printRandomTest(13, 14, 1);

        for (int k = 5; k <= 40; k += 5) {
            printRandomTest(100, 100 - random.nextInt(20), k);
        }

        for (int k = 5; k <= 50; k += 5) {
            printGroupedTest(100, 100 - random.nextInt(20), k);
        }

        for (int k = 5; k <= 50; k += 5) {
            printRandomTest(1000, 1000 - random.nextInt(200), k);
        }

        for (int k = 5; k <= 50; k += 5) {
            printGroupedTest(1000, 1000 - random.nextInt(200), k);
        }

        printReversedTest(1000, 1000, 1);
        printReversedTest(1000, 1000, 2);
        printReversedTest(1000, 1000, 10);
        printReversedTest(1000, 1000, 50);

    }

    private void printGroupedTest(int n, int s, int k) throws FileNotFoundException {
        int[] a = new int[n];
        int[] q = new int[s];
        boolean[] z = new boolean[s];
        z[s - 1] = true;
        for (int i = 0; i < k - 1; i++) {
            int j = random.nextInt(s);
            while (z[j]) {
                j = random.nextInt(s);
            }
            z[j] = true;
        }
        int l = 0;
        for (int i = 0; i < k; i++) {
            int r = l;
            while (!z[r]) r++;

            int ll = l * n / s;
            int rr = (r + 1) * n / s;

            for (int j = ll; j < rr; j++) {
                int x = l + random.nextInt(r - l + 1);
                while (q[x] == 6) {
                    x = l + random.nextInt(r - l + 1);
                }
                a[j] = x;
                q[x]++;
            }
            l = r + 1;
        }
//        Collections.reverse(Arrays.asList(a));
        printTest(n, s, k, a);
    }

    private void printReversedTest(int n, int s, int k) throws FileNotFoundException {
        int[] a = new int[n];
        int[] q = new int[s];
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        printTest(n, s, k, a);
    }

    Random random = new Random(1242454578978978L);

    private void printRandomTest(int n, int s, int k) throws FileNotFoundException {
            int[] a = new int[n];
            int[] q = new int[s];
            for (int i = 0; i < n; i++) {
                int j = random.nextInt(s);
                while (q[j] == 6) {
                    j = random.nextInt(s);
                }
                a[i] = j;
                q[j]++;
            }
            printTest(n, s, k, a);
    }
}

