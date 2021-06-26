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
/* Tests                                                          */
/*                                                                */
/* Author                Dmitry Shtukenberg                       */
/******************************************************************/

import java.io.*;
import java.util.*;

public class Tests {
    int testNo = 0;
    PrintWriter out;
    static PrintWriter descriptions;
    Random random = new Random(7023842358235832895L);

    static int MAX_P = 10;
    static int MAX_L = 100_000;
    static int MAX_V = 999_999_999;
    static int MAX_N = 100_000;

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

    void endTest(String expression, int... X) {
        validate(X);
        validate(expression);
        out.println(X.length);
        for (int i = 0; i < X.length; i++) {
            if (i != 0) {
                out.print(" ");
            }
            out.print(X[i]);
        }
        out.println();
        out.println(expression);
        out.close();
    }

    private void validate(String expression) {
        assert between(expression.length(), 1, MAX_L);
        new Parser(expression, 1).parse();
    }

    private void validate(int[] x) {
        assert between(x.length, 1, MAX_N);
        for (int i : x) {
            assert between(i, 0, MAX_V) : "x = " + i;
        }
    }

    int randomInt(int from, int to) {
        return random.nextInt(to - from) + from;
    }

    int randomAlmost(int n) {
        if (n == 1) {
            return 1;
        }
        return randomInt(n - (int) Math.log(n), n);
    }

    void simpleTest(String expression, int... x) {
        beginTest(expression);
        endTest(expression, x);
    }

    static class Parser {
        class Stats {
            final int complexity;
            final double maxOps;
            final double minOps;

            Stats(int complexity, double minOps, double maxOps) {
                assert between(complexity, 0, MAX_P) : "Complexity = " + complexity;
                this.complexity = complexity;
                this.minOps = minOps;
                this.maxOps = maxOps;
            }

            public Stats op() {
                return new Stats(complexity, minOps + minOps(complexity), maxOps + maxOps(complexity));
            }

        }

        private int maxOps(int complexity) {
            return (complexity == 0 ? 1 : n);
        }

        private int minOps(int complexity) {
            return (complexity == 0 ? 1 : MAX_P);
        }

        final char[] line;
        int pos;
        final int n;

        Parser(String line, int n) {
            this.line = (line + "#").toCharArray();
            this.n = n;
        }

        void expect(char ch) {
            if (nextToken() != ch) {
                throw new AssertionError(String.format("%d: '%c' expected, '%c' found", pos, ch, line[pos - 1]));
            }
        }

        char nextToken() {
            return line[pos++];
        }

        public Stats parse() {
            Stats e = parseExpression();
            assert e.complexity == 0;
            expect('#');
            return e;
        }

        private Stats parseExpression() {
            final char token = nextToken();
            switch (token) {
                case '-':
                    return parseExpression().op();
                case '*':
                    expect(':');
                    Stats r = parseExpression();
                    return new Stats(2 * r.complexity, r.minOps + minOps(r.complexity) * minOps(r.complexity), r.maxOps + maxOps(r.complexity));
                case '+':
                    expect('/');
                    Stats e = parseExpression();
                    assert e.complexity > 0 : "Fold of non-vector " + pos;
                    return new Stats(0, e.minOps + MAX_P, e.maxOps + n - 1);
            }
            Stats op1 = parseTerm(token);
            switch (nextToken()) {
                case '+':
                case '-': {
                    Stats op2 = parseExpression();
                    int c = Math.max(op1.complexity, op2.complexity);
                    return new Stats(
                            c,
                            op1.minOps + op2.minOps + minOps(c),
                            op1.maxOps + op2.maxOps + maxOps(c)
                    );
                }
                case '*': {
                    Stats op2 = parseExpression();
                    int c = op1.complexity + op2.complexity;
//                    System.out.println(c + " " + op1.complexity + " " + op2.complexity + " " + new String(line, start, pos - start));
                    return new Stats(
                            c,
                            op1.minOps + op2.minOps + minOps(c) * minOps(c),
                            op1.maxOps + op2.maxOps + maxOps(c)
                    );
                }
                default:
                    pos--;
                    return op1;
            }
        }

        private Stats parseTerm(char token) {
            switch (token) {
                case '(':
                    Stats op = parseExpression();
                    expect(')');
                    return op;
                case 'X':
                    return new Stats(1, 1, 1);
                case 'N':
                    return new Stats(0, 1, 1);
                default:
                    if (Character.isDigit(token)) {
                        StringBuilder sb = new StringBuilder();
                        sb.append(token);
                        while (Character.isDigit(line[pos])) {
                            sb.append(nextToken());
                        }
                        assert between(Integer.parseInt(sb.toString()), 0, MAX_V);
                        return new Stats(0, 1, 1);
                    }
                    throw new AssertionError("Invalid term " + pos);
            }
        }
    }

    private static boolean between(int x, int a, int b) {
        return a <= x && x <= b;
    }

    void handmadeTests() {
        // Constants-only tests
        simpleTest("10", 1);
        simpleTest("-10", 1);
        simpleTest("*:10", 1);
        simpleTest("*:-10", 1);
        simpleTest("-*:10", 1);
        simpleTest("10+20", 1);
        simpleTest("10-20", 1);
        simpleTest("10*20", 1);
        simpleTest("10--20", 1);
        simpleTest("-10--20", 1);
        simpleTest("10*20--30", 1);
        simpleTest("(10*20)--30", 1);
        simpleTest("(10*20)-(-30)", 1);
        simpleTest("(*:10*-20)-(-30)*40", 1);
        simpleTest("999999999", 1);
        simpleTest("999999999*999999999", 1);

        // N-only tests
        simpleTest("N", 1, 1, 1);
        simpleTest("-N", 1, 1, 1);
        simpleTest("*:N", 1, 1, 1);
        simpleTest("*:-N", 1, 1, 1);
        simpleTest("-*:N", 1, 1, 1);
        simpleTest("N+N", 1, 1, 1);
        simpleTest("N-N", 1, 1, 1);
        simpleTest("N*N", 1, 1, 1);
        simpleTest("N--N", 1, 1, 1);
        simpleTest("-N--N", 1, 1, 1);
        simpleTest("N*N--N", 1, 1, 1);
        simpleTest("(N*N)--N", 1, 1, 1);
        simpleTest("(N*N)-(-N)", 1, 1, 1);
        simpleTest("(*:N*-N)-(-N)*N", 1, 1, 1);

        // Scalar-only tests
        simpleTest("10+N", 1, 1, 1);
        simpleTest("N-20", 1, 1, 1);
        simpleTest("10*N", 1, 1, 1);
        simpleTest("10--N", 1, 1, 1);
        simpleTest("-N--20", 1, 1, 1);
        simpleTest("10*N--30", 1, 1, 1);
        simpleTest("(10*20)--N", 1, 1, 1);
        simpleTest("(N*20)-(-30)", 1, 1, 1);
        simpleTest("(*:N*-20)-(-30)*N", 1, 1, 1);
        simpleTest("999999999*N", 1, 1, 1);

        // X-only tests
        simpleTest("+/X", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
        simpleTest("+/-X", 1, 2, 3, 4, 5);
        simpleTest("-+/X", 1, 2, 3, 4, 5);
        simpleTest("+/*:X", 1, 2, 3, 4, 5);
        simpleTest("*:+/X", 1, 2, 3, 4, 5);
        simpleTest("+/X+X", 1, 2, 3, 4, 5);
        simpleTest("+/X-X", 1, 2, 3, 4, 5);
        simpleTest("+/X*X", 1, 2, 3, 4, 5);
        simpleTest("+/X--X", 1, 2, 3, 4, 5);
        simpleTest("+/-X--X", 1, 2, 3, 4, 5);
        simpleTest("+/X*X--X", 1, 2, 3, 4, 5);
        simpleTest("+/(*:X*-X)-(-X)*X", 1, 2, 3, 4, 5);
        simpleTest("+/(*:X*-+/X)-(+/-X)*X", 1, 2, 3, 4, 5);
        simpleTest("+/(*:X*-+/X)-(+/-X)*X", 10);
    }

    void sampleTests() {
        beginTest("Sample 1"); endTest("+/*:X", 1, 2, 3, 4, 5);
        beginTest("Sample 2"); endTest("N++/X-X+1", 1, 2, 3, 4, 5);
        beginTest("Sample 3"); endTest("+/(3-+/*:*:X)-X**:X", 11, 56, 37);
    }

    public void run() throws IOException {
        sampleTests();
        handmadeTests();
        randomTests(1, 30);
        randomTests(30, 30);
        randomTests(1000, 1000);
        randomTests(1, MAX_L);
        randomTests(MAX_N, MAX_L);
    }

    private void randomTests(int size, int len) {
        if (size != 1) {
            randomTest(randomAlmost(size), MAX_V, randomAlmost(len), true, "(");
            randomTest(randomAlmost(size), MAX_V, randomAlmost(len), true, "+/");
            randomTest(randomAlmost(size), MAX_V, randomAlmost(len), true, "*");
            randomTest(randomAlmost(size), MAX_V, randomAlmost(len), true, "-");
            randomTest(randomAlmost(size), MAX_V, randomAlmost(len), true, "+");
            randomTest(randomAlmost(size), MAX_V, randomAlmost(len), false, "*:");
            randomTest(randomAlmost(size), MAX_V, randomAlmost(len), true, "=");
        }

        randomTest(randomAlmost(size), MAX_V, len, true, "(", "+/", "*:", "=", "*", "-", "+");
        randomTest(randomAlmost(size), MAX_V, len, true, "(", "+/", "*:", "=", "*", "-", "+", "=", "=", "=", "=");
        randomTest(randomAlmost(size), MAX_V, len, true, "(", "+/", "*:", "=", "*", "-", "+", "-", "+", "-", "+");
        randomTest(randomAlmost(size), MAX_V, len, true, "(", "+/", "*:", "=", "*", "-", "+", "*", "*", "*", "*");
    }

    private void randomTest(int n, int v, int l, boolean vector, String... ops) {
        String expression = new Generator(ops).generate(l, vector);
        Parser.Stats stats = new Parser(expression, n).parse();
        beginTest("random(%d, %d, %d, %s), minOps=%g, maxOps=%g", n, v, l, Arrays.toString(ops), stats.minOps, stats.maxOps);
        int[] x = new int[n];
        for (int i = 0; i < x.length; i++) {
            x[i] = randomInt(0, v + 1);
        }

        endTest(expression, x);
    }

    class Generator {
        final StringBuilder sb = new StringBuilder();
        final String[] ops;

        public Generator(String[] ops) {
            this.ops = ops.clone();
        }

        String generate(int l, boolean vector) {
            if (vector) {
                sb.append("+/");
                g(l - 2, MAX_P, true);
            } else {
                g(l, 0, true);
            }
//            System.out.println(sb);
            return sb.toString();
        }

        void g(int l, int p, boolean rhs) {
            assert l > 0;
            if (l == 1) {
                leaf(p, 1, rhs);
                return;
            }

            String op = ops[randomInt(0, ops.length)];
            switch (op) {
                case "+":
                case "-":
                    if (l >= 3) {
                        int z = randomInt(1, l - 1);
                        g(z, p, false);
                        sb.append(op);
                        g(l - z - 1, p, rhs);
                    } else {
                        leaf(p, l, rhs);
                    }
                    return;
                case "*":
                    if (l >= 3) {
                        if (rhs) {
                            int z = randomInt(1, l - 1);
                            int q = randomInt(0, p + 1);
                            g(z, q, false);
                            sb.append(op);
                            g(l - z - 1, p - q, true);
                        } else {
                            sb.append("(");
                            g(l - 2, p, true);
                            sb.append(")");
                        }
                    } else {
                        leaf(p, l, rhs);
                    }
                    return;
                case "=":
                    sb.append("-");
                    g(l - 1, p, rhs);
                    return;
                case "*:":
                    if (!rhs || p == 1) {
                        g(l, p, false);
                    } else if (l >= 3) {
                        sb.append("*:");
                        g(l - 2, p / 2, true);
                    } else {
                        leaf(p, l, rhs);
                    }
                    return;
                case "+/":
                    if (l >= 5) {
                        if (rhs) {
                            if (p == 0) {
                                sb.append("+/");
                                g(l - 2, MAX_P, true);
                            } else {
                                sb.append("X").append("+-*".charAt(randomInt(0, 3))).append("+/");
                                g(l - 4, MAX_P, true);
                            }
                        } else {
                            sb.append("(");
                            g(l - 2, p, true);
                            sb.append(")");
                        }
                    } else {
                        leaf(p, l, rhs);
                    }
                    return;
                case "(":
                    if (l >= 3) {
                        sb.append("(");
                        g(l - 2, p, true);
                        sb.append(")");
                    } else {
                        leaf(p, l, rhs);
                    }
                    return;
                default:
                    throw new AssertionError("Unknown operation '" + op + "'");
            }
        }

        private void leaf(int p, int l, boolean multiplyAllowed) {
            assert between(l, 1, 4);
            if (p > 0) {
                if (p > 1 && multiplyAllowed) {
                    if (l == 4) {
                        sb.append("-*:X");
                        return;
                    } else if (l == 3) {
                        sb.append("*:X");
                        return;
                    }
                }
                if (l == 4) {
                    sb.append("X--X");
                } else if (l == 3) {
                    sb.append("X+X");
                } else if (l == 2) {
                    sb.append("-X");
                } else {
                    sb.append("X");
                }
            } else if (l == 1 && randomInt(0, 2) == 0) {
                sb.append("N");
            } else {
                sb.append(randomInt(1, 10));
                for (int i = 1; i < l; i++) {
                    sb.append(randomInt(0, 10));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        descriptions = new PrintWriter("tests/tests.lst");
        new Tests().run();
        descriptions.close();
    }
}

