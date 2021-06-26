/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem J. J                                                   */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Dmitry Shtukenberg                       */
/*                       Georgiy Korneev                          */
/* Test set              Dmitry Shtukenberg                       */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class j_gk {
    static Scanner in;
    static PrintWriter out;
    static final int P = 10 + 1;
    static final long MODULO = 1_000_000_000;

    char[] line;
    int pos = 0;

    long add(long a1, long a2) {
        return (a1 + a2) % MODULO;
    }

    long multiply(long a1, long a2) {
        return (a1 * a2) % MODULO;
    }
    
    long neg(long a) {
        return (MODULO - a) % MODULO;
    }

    long[] X;
    long[] N;
    long[] xp = new long[P];
    void run() {
        int n = in.nextInt();
        long[] x = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = value(in.nextInt());
        }

        long[] p = new long[n];
        Arrays.fill(p, value(1));
        Arrays.fill(xp, value(0));
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < n; j++) {
                xp[i] = add(xp[i], p[j]);
                p[j] = multiply(p[j], x[j]);
            }
        }

        X = new long[P];
        Arrays.fill(X, value(0));
        X[1] = value(1);
        
        N = scalar(value(n));

        line = (in.next().replaceAll("\\s", "") + "#").toCharArray();
        long[] result = expression();
        out.println(result[0]);
        expect('#');
    }

    private long value(int i) {
        while (i < 0) {
            i += MODULO;
        }
        return i % MODULO;
    }

    private long[] scalar(long v) {
        long[] r = new long[P];
        Arrays.fill(r, value(0));
        r[0] = v;
        return r;
    }

    long[] add(long[] a, long[] b) {
        long[] r = new long[P];
        for (int i = 0; i < P; i++) {
            r[i] = add(a[i], b[i]);
        }
        return r;
    }

    long[] subtract(long[] a, long[] b) {
        long[] r = new long[P];
        for (int i = 0; i < P; i++) {
            r[i] = add(a[i], neg(b[i]));
        }
        return r;
    }

    long[] multiply(long[] a, long[] b) {
        long[] r = new long[P * 2];
        for (int i = 0; i < r.length; i++) {
            r[i] = value(0);
        }
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < P; j++) {
                r[i + j] = add(r[i + j], multiply(a[i], b[j]));
            }
        }
        return r;
    }

    long[] expression() {
        long[] op = term();
        switch (nextToken()) {
            case '+': return add(op, expression());
            case '-': return subtract(op, expression());
            case '*': return multiply(op, expression());
            default:
                pos--;
                return op;
        }
    }

    long[] term() {
        final char token = nextToken();
        switch (token) {
            case '-':
                return minus(expression());
            case '*':
                expect(':');
                return square(expression());
            case '+':
                expect('/');
                return fold(expression());
            case 'X':
                return X;
            case 'N':
                return N;
            case '(':
                long[] r = expression();
                expect(')');
                return r;
            default:
                if (Character.isDigit(token)) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(token);
                    while (Character.isDigit(line[pos])) {
                        sb.append(nextToken());
                    }
                    return scalar(value(Integer.parseInt(sb.toString())));
                }
                throw new AssertionError("Invalid term " + pos);
        }
    }

    private long[] fold(long[] a) {
        long r = value(0);
        for (int i = 0; i < P; i++) {
            r = add(r, multiply(a[i], xp[i]));
        }
        return scalar(r);
    }

    private long[] square(long[] a) {
        return multiply(a, a);
    }

    private long[] minus(long[] a) {
        long[] r = new long[P + 1];
        for (int i = 0; i < P; i++) {
            r[i] = neg(a[i]);
        }
        return r;
    }

    private void expect(char ch) {
        if (nextToken() != ch) {
            throw new AssertionError(String.format("%d: '%c' expected, '%c' found", pos, ch, line[pos - 1]));
        }
    }

    char nextToken() {
        return line[pos++];
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
            in = new Scanner(new File("j.in"));
        out = new PrintWriter("j.out");

        new j_gk().run();

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

