/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem C. Correcting Curiosity                                */
/*                                                                */
/* Original idea         Yury Petrov                              */
/* Problem statement     Maxim Buzdalov                           */
/* Test set              Maxim Buzdalov                           */
/******************************************************************/
/* Tests                                                          */
/*                                                                */
/* Author                Maxim Buzdalov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class Tests {
    static final String alphabet;
    static final Random random = new Random(1235234523);
    static {
        StringBuilder sb = new StringBuilder(" -,:;");
        for (char x = 'a'; x <= 'z'; ++x) sb.append(x);
        for (char x = 'A'; x <= 'Z'; ++x) sb.append(x);
        alphabet = sb.toString();
    }
    static int nTests = 0;
    static final File root = new File("tests");
    static void rmrf(File f) {
        if (f.isDirectory()) {
            for (File ch : f.listFiles()) {
                rmrf(ch);
            }
        }
        f.delete();
    }
    static void write(String oldv, String newv) throws IOException {
        try (PrintWriter out = new PrintWriter(String.format("%s/%02d", root.getName(), ++nTests))) {
            out.println(oldv);
            out.println(newv);
        }
    }
    static String multiply(String what, int times) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < times; ++i) {
            sb.append(what);
        }
        return sb.toString();
    }
    static String randomString(int length, int alphabetSize) {
        alphabetSize = Math.min(alphabetSize, alphabet.length());
        StringBuilder rv = new StringBuilder();
        for (int i = 0; i < length; ++i) {
            rv.append(alphabet.charAt(random.nextInt(alphabetSize)));
        }
        return rv.toString();
    }
    static String collisionString(int length) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; ++i) {
            sb.append((char) ('a' + Integer.bitCount(i) % 2));
        }
        return sb.toString();
    }
    public static void main(String[] args) throws IOException {
        rmrf(root);
        root.mkdir();
        write("move left, move right; move up", "move left, move down, move up");
        write("If not found: move x; else move -x", "If found: move x; else move -x");
        write("abababa", "cbc");
        write("a", "b");
        write("aaa", "bbb");
        write("aaa", "bb");
        write("aaaaaaaaaa", "aaaaaaaaaaaaaaa");
        write("aaaaaaaaaa", "aaaaa");

        write("aaaDELETEbbb", "aaabbb");
        write("aaaDELETE", "aaa");
        write("DELETEaaa", "aaa");

        write("aaabbb", "aaaADDbbb");
        write("aaa", "aaaADD");
        write("bbb", "ADDbbb");

        write("baabaabaabaab", "baabbaabbaabbaabb");

        write("babbababb", "b");

        final int MAX = 2000;

        for (int sz : new int[] {50, 100, 200, 500, 1000, MAX}) {
            write(multiply("a", sz), multiply("a", sz - 1));
            write(multiply("a", sz - 1), multiply("a", sz));
            write(multiply("a", sz), multiply("a", sz / 10 * 9));
            write(multiply("a", sz - 1) + "b", "b" + multiply("a", sz - 1));
            write(multiply("b", sz - 2) + "a", multiply("b", sz - 2) + "aa");
            write(multiply("b", sz - 15) + multiply("a", 15), multiply("ab", sz / 2));
            write(randomString(sz, 2), randomString(sz, 2));
            write(randomString(sz, 100), randomString(sz, 100));
            write(collisionString(sz), collisionString(sz - 1));
        }

        for (int times = 0; times < 5; ++times) {
            String pref = randomString(MAX / 2, 2);
            String suff1 = multiply("a", MAX / 2);
            String suff2 = multiply("a", MAX / 2 - 1) + "b";
            write(pref + suff1, pref + suff2);
        }
    }
}

