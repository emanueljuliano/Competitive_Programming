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
/* Tests                                                          */
/*                                                                */
/* Author                Sergey Poromov                           */
/******************************************************************/

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

public class Tests {

    private static int testsCount = 0;
    private static Random random = new Random(25843572);
    private static boolean useShuffle = true;
    private static boolean randLen = true;

    private static int MAX = 5000;
    private static int MAXLEN = 550;

    public static void main(String[] args) {
        new File("tests").mkdir();
        writeSamples();
        writeManual();

        writeRand(2, 3, 10, 3, 10);
        writeMulti(10, 5, 20);
        randLen = false;
        writeOneToMany(1, 1, 1, 2);
        write1(1, 1);
        writeOneToMany(1, 100, 1, 2);
        randLen = true;
        writeFull(3, 4, 5, 20);

        for (int i = 0; i < 10; i++) {
            int l = random.nextInt(MAX / (2 + 10 * i));
            int r = random.nextInt(MAX / (2 + 10 * i));
            int m = random.nextInt(MAX / (1 + i));
            int len = random.nextInt(MAXLEN - 10) + 10;
            int k = random.nextInt(len / 2 - 3) + 3;
            writeRand(l, r, m, k, len);
        }

        writeRand(1000, 1000, MAX, 10, MAXLEN);
        writeRand(MAX / 2, MAX / 2, MAX, 100, MAXLEN);
        writeCycle(MAX / 2, 100, MAXLEN);
        writeAntiKun(MAX / 2, MAXLEN);
        write1(MAX, MAXLEN);
        writeOneToMany(1, MAX - 1, 33, 99);
        writeManyToOne(MAX - 1, 1, 28, 56);
        {
            int t = (int) Math.floor(Math.sqrt(MAX));
            writeFull(t, t, 10, 239);
            randLen = false;
            writeFull(t, t, MAXLEN / 2, MAXLEN);
            randLen = true;
        }
        writeTriple(MAX / 3, 36, 88);
        writeMulti(MAX, 1, 2);
        writeMulti(MAX, 156, MAXLEN);

        writeAntiKun(MAX / 3, 100);
        randLen = false;
        writeFull(5, 6, 1, 3);
        writeRand2(500, 500, MAX - 3, 100);
        writeRand2(MAX / 2, MAX / 2, MAX, MAXLEN);
        writeAntiKun2(MAX, 42, MAXLEN);
    }

    private static void writeSamples() {
        write(new String[]{"AA", "AB", "BB", "BA"}, 1);
        write(new String[]{"ABA", "BAB", "XY"}, 2);
    }

    private static void writeManual() {
        write(new String[]{"AA"}, 2);
        write(new String[]{"CAT", "CAR", "BAT"}, 2);
        write(new String[]{"CAT", "CAR", "BAT"}, 3);
    }

    private static void write1(int n, int len) {
        String[] s = new String[n];
        String ss = repeatString(len, 'A');
        Arrays.fill(s, ss);
        write(s, len);
    }

    private static void writeAntiKun(int n, int len) {
        BiGraph g = new BiGraph(n, n);
        g.edges.add(new Edge(0, 0));
        for (int i = 1; i < n; i++) {
            g.edges.add(new Edge(i, i - 1));
            g.edges.add(new Edge(i, i));
        }
        int k = g.genSpecStrings(len);
        useShuffle = false;
        write(g.toStrings(), k);
        useShuffle = true;
    }

    private static void writeAntiKun2(int n, int k, int len) {
        int t = n / 4;
        BiGraph g = new BiGraph(3 * t, t);
        for (int i = 0; i < t; i++) {
            g.edges.add(new Edge(i, i));
            if (i > 0) {
                g.edges.add(new Edge(i, i - 1));
            }
        }
        for (int i = t; i < 3 * t; i++) {
            g.edges.add(new Edge(i, 0));
        }
        g.generateStrings(k, len);
        useShuffle = false;
        write(g.toStrings(), k);
        useShuffle = true;
    }

    private static void writeFull(int l, int r, int k, int len) {
        BiGraph g= new BiGraph(l, r);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                g.edges.add(new Edge(i, j));
            }
        }
        g.generateStrings(k, len);
        write(g.toStrings(), k);
    }

    private static void writeCycle(int n, int k, int len) {
        BiGraph g = new BiGraph(n, n);
        for (int i = 0; i < n; i++) {
            g.edges.add(new Edge(i, i));
            g.edges.add(new Edge(i, (i + 1) % n));
        }
        g.generateStrings(k, len);
        write(g.toStrings(), k);
    }

    private static void writeTriple(int n, int k, int len) {
        BiGraph g = new BiGraph(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = -1; j <= 1; j++) {
                g.edges.add(new Edge(i, (i + j + n) % n));
            }
        }
        g.generateStrings(k, len);
        write(g.toStrings(), k);
    }

    private static void writeOneToMany(int r, int m, int k, int len) {
        BiGraph g = new BiGraph(1, r);
        for (int i = 0; i < r; i++) {
            g.edges.add(new Edge(0, i));
        }
        for (int i = r; i < m; i++) {
            g.edges.add(new Edge(0, random.nextInt(r)));
        }
        g.generateStrings(k, len);
        write(g.toStrings(), k);
    }

    private static void writeManyToOne(int l, int m, int k, int len) {
        BiGraph g = new BiGraph(l, 1);
        for (int i = 0; i < l; i++) {
            g.edges.add(new Edge(i, 0));
        }
        for (int i = l; i < m; i++) {
            g.edges.add(new Edge(random.nextInt(l), 0));
        }
        g.generateStrings(k, len);
        write(g.toStrings(), k);
    }

    private static void writeMulti(int m, int k, int len) {
        BiGraph g = new BiGraph(1, 1);
        for (int i = 0; i < m; i++) {
            g.edges.add(new Edge(0, 0));
        }
        g.generateStrings(k, len);
        write(g.toStrings(), k);
    }

    private static void writeRand(int l, int r, int m, int k, int len) {
        BiGraph g = new BiGraph(l, r);
        for (int i = 0; i < l; i++) {
            g.edges.add(new Edge(i, random.nextInt(r)));
        }
        for (int i = 0; i < r; i++) {
            g.edges.add(new Edge(random.nextInt(l), i));
        }
        for (int i = l + r; i < m; i++) {
            g.edges.add(new Edge(random.nextInt(l), random.nextInt(r)));
        }
        g.generateStrings(k, len);
        write(g.toStrings(), k);
    }

    private static void writeRand2(int l, int r, int m, int len) {
        BiGraph g = new BiGraph(l, r);
        for (int i = 0; i < l; i++) {
            g.edges.add(new Edge(i, random.nextInt(r)));
        }
        for (int i = 0; i < r; i++) {
            g.edges.add(new Edge(random.nextInt(l), i));
        }
        for (int i = l + r; i < m; i++) {
            g.edges.add(new Edge(random.nextInt(l), random.nextInt(r)));
        }
        int k = g.genSpecStrings2(len);
        write(g.toStrings(), k);
    }

    private static void write(String[] names, int k) {
        PrintWriter out = null;
        try {
            out = new PrintWriter(String.format("tests/%02d", ++testsCount));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(566);
        }
        out.println(names.length + " " + k);
        for (String s : names) {
            out.println(s);
        }
        out.close();
    }

    private static String randString(int len) {
        StringBuilder sb = new StringBuilder(len);
        for (int i = 0; i < len; i++) {
            sb.append((char)(random.nextInt(26) + 'A'));
        }
        return sb.toString();
    }

    private static String repeatString(int len, char ch) {
        StringBuilder sb = new StringBuilder();
        for (int i =0 ; i< len; i++) {
            sb.append(ch);
        }
        return sb.toString();
    }

    public static class Edge {
        int a, b;

        String s;

        Edge(int l, int r) {
            a = l;
            b = r;
        }
    }

    public static class BiGraph {
        int ln, rn;
        ArrayList<Edge> edges = new ArrayList<>();

        BiGraph(int l, int r) {
            ln = l;
            rn = r;
        }

        void generateStrings(int k, int maxLen) {
            String[] ls = new String[ln];
            String[] rs = new String[rn];
            for (int i = 0; i < ln; i++) {
                ls[i] = randString(k);
            }
            for (int i = 0; i < rn; i++) {
                rs[i] = randString(k);
            }
            for (Edge e : edges) {
                int tlen = randLen && (maxLen > 2 * k) ? random.nextInt(maxLen - 2 * k) : maxLen - 2 * k;
                e.s = ls[e.a] + randString(tlen) + rs[e.b];
            }
        }

        private void nextString(StringBuilder sb) {
            int i = sb.length() - 1;
            while (sb.charAt(i) == 'Z') {
                i--;
            }
            sb.setCharAt(i, (char) (sb.charAt(i) + 1));
            i++;
            while(i < sb.length()) {
                sb.setCharAt(i++, 'A');
            }
        }

        int genSpecStrings(int len) {
            if (ln != rn) {
                throw new Error();
            }
            int l = 1;
            int c = 26;
            while (c < ln || c < rn) {
                c *= 26;
                l++;
            }
            String[] s = new String[ln];
            StringBuilder sb = new StringBuilder(repeatString(l, 'A'));
            for (int i = 0; i < s.length; i++) {
                s[i] = sb.toString();
                nextString(sb);
            }
            String repeat = repeatString(len - 2 * l, 'A');
            for (Edge e : edges) {
                e.s = s[e.a] + repeat + s[e.b];
            }
            return l;
        }

        int genSpecStrings2(int len) {
            String[] ls = new String[ln];
            String[] rs = new String[rn];
            int l = 1;
            int c = 26;
            while (c < ln || c < rn) {
                c *= 26;
                l++;
            }
            StringBuilder sb = new StringBuilder(repeatString(l, 'A'));
            String repeat = repeatString(len / 2 - l, 'X');
            for (int i = 0; i < Math.max(ln, rn); i++) {
                if (i < ln) {
                    ls[i] = repeat + sb.toString();
                }
                if (i < rn) {
                    rs[i] = repeat + sb.toString();
                }
                nextString(sb);
            }
            for (Edge e : edges) {
                e.s = ls[e.a] + rs[e.b];
            }
            return ls[0].length();
        }

        String[] toStrings() {
            if (useShuffle) {
                Collections.shuffle(edges, random);
            }

            String[] names = new String[edges.size()];
            int t = 0;
            for (Edge e : edges) {
                names[t++] = e.s;
            }
            return names;
        }
    }

}


