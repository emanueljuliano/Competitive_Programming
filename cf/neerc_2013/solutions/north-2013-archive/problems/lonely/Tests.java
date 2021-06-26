/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem L. Lonely Mountain                                     */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Georgiy Korneev                          */
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

    static int MAX_N = 100_000;
    static int MAX_C = 1_000_000_000;

    class Proj {
        List<Integer> c = new ArrayList<Integer>(MAX_N);
        List<Integer> z = new ArrayList<Integer>(MAX_N);

        Proj add(int c, int z) {
            //assert this.c.isEmpty() || this.c.get(this.c.size() - 1) < c;
            this.c.add(c);
            this.z.add(z);
            return this;
        }

        void validate() {
            assert c.size() == z.size();
            assert 2 <= c.size() && c.size() <= MAX_N;
            assert z.get(0) == 0;
            assert z.get(z.size() - 1) == 0;
            int px = -MAX_C - 1;
            for (int i = 0; i < c.size(); i++) {
                assert px < c.get(i) : c;
                assert c.get(i) <= MAX_C;
                px = c.get(i);
                assert 0 <= z.get(i) && z.get(i) <= MAX_C;
            }
        }

        void clear() {
            c.clear();
            z.clear();
        }

        void write() {
            out.println(c.size());
            for (int i = 0; i < c.size(); i++) {
                if (i != 0) {
                    out.print(" ");
                }
                out.print(c.get(i) + " " + z.get(i));
            }
            out.println();
        }
        
        void pyramid(int c, int z) {
            int shift = -randomInt(0, c);
            add(shift, 0).add(shift + randomInt(1, c), z).add(shift + c, 0);
        }

        void roof(int c, int z) {
            int c1 = randomInt(1, c - 1);
            int c2 = randomInt(c1 + 1, c);
            add(0, 0).add(c1, z).add(c2, z).add(c, 0);
        }

        void pyramids(int s, int n, int z) {
            add(0, 0);
            int c = 0;
            for (int i = 0; i < n; i++) {
                int cs = randomInt(2, s);
                add(c + randomInt(1, cs), randomInt(1, z + 1));
                add(c + cs, 0);
                c += cs;
            }
            this.z.set(randomInt(0, n) * 2 + 1, z);
        }

        void roofsPyramids(int s, int n, int z, boolean skewed) {
            add(0, 0);
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (random.nextBoolean()) {
                    int cs = randomInt(2, s);
                    add(c + randomInt(1, cs), randomInt(1, z + 1)).add(c + cs, 0);
                    c += cs;
                } else {
                    int cs = randomInt(3, s);
                    int c1 = randomInt(1, cs - 1);
                    int c2 = randomInt(c1 + 1, cs);
                    int h1 = randomInt(1, z + 1);
                    int h2 = skewed ? randomInt(1, z + 1) : h1;
                    add(c + c1, h1).add(c + c2, h2).add(c + cs, 0);
                    c += cs;
                }
            }
            int i;
            do {
                i = randomInt(0, this.z.size());
            } while (this.z.get(i) == 0);
            this.z.set(i, z);
        }

        void max(int c, int prec) {
            prec++;
            add(-c, 0).add(-c + 1 + random.nextInt(prec), c)
                      .add( c - 1 - random.nextInt(prec), c - random.nextInt(prec))
                      .add(c, 0);
        }

        void random(int c, int z, int n, int horz) {
            Set<Integer> cs = new HashSet<>();
            for (int i = 0; i < n; i++) {
                int q;
                do {
                    q = randomInt(-c, c);
                } while (!cs.add(q));
                add(q, randomInt(0, z + 1));
            }
            this.z.set(0, 0);
            this.z.set(randomInt(1, n), z);
            this.z.set(n - 1, 0);
            Collections.sort(this.c);
            for (int i = 0; i < horz; i++) {
                int j = randomInt(1, n - 1);
                this.z.set(j, this.z.get(j - 1));
            }
            validate();
        }
    }

    Proj px = new Proj();
    Proj py = new Proj();

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

        px.clear();
        py.clear();
    }

    void endTest() {
        px.validate();
        py.validate();

        px.write();
        py.write();                   

        out.close();
        assert !out.checkError();
        out = null;
    }

    void sampleTests() {
        beginTest("Sample 1");
        px.add(0, 0).add(1, 1).add(2, 0).add(3, 3).add(4, 4).add(6, 0);
        py.add(0, 0).add(1, 1).add(2, 1).add(3, 4).add(4, 0);
        endTest();

        beginTest("Sample 2");
        px.add(-1, 0).add(0, 1).add(2, 0);
        py.add(0, 0).add(1, 1).add(2, 2).add(3, 0);
        endTest();
    }

    void endTest(boolean flip) {
        if (flip) {
            Proj t = px; px = py; py = t;
        }
        endTest();
    }

    int randomInt(int from, int to) {
        return random.nextInt(to - from) + from;
    }

    void pyramid(int x, int y, int z) {
        beginTest("One %dx%dx%d pyramid", x, y, z);
        px.pyramid(x, z);
        py.pyramid(y, z);
        endTest();
    }

    void roof(int x, int y, int z, boolean flip) {
        beginTest("One %dx%dx%d roof%s", x, y, z, flip ? ", flipped" : "");
        px.roof(x, z);
        py.pyramid(y, z);
        endTest(flip);       
    }

    void pillow(int x, int y, int z) {
        beginTest("One %dx%dx%d pillow", x, y, z);
        px.roof(x, z);
        py.roof(y, z);
        endTest();
    }

    void pyramids(int x, int y, int z, int cx, int cy) {
        beginTest("%dx%d grid of pyramids of size up to %dx%dx%d", cx, cy, x, y, z);
        px.pyramids(x, cx, z);
        py.pyramids(y, cy, z);
        endTest();
    }

    void roofsPyramidsAndPillows(int x, int y, int z, int cx, int cy, boolean skewed) {
        beginTest("%dx%d grid of roofs, pyramids and pillows of size up to %dx%dx%d%s", cx, cy, x, y, z, skewed ? ", skewed" : "");
        px.roofsPyramids(x, cx, z, skewed);
        py.roofsPyramids(y, cy, z, skewed);
        endTest();
    }

    void randomTest(int s, int n, boolean invalid, int horiz) {
        randomTest(s, s, s, randomAlmost(n), randomAlmost(n), invalid, horiz, horiz);
    }

    int randomAlmost(int n) {
        return randomInt(n - (int) Math.log(n), n);
    }

    void randomTest(int x, int y, int z, int n, int m, boolean invalid, int horizN, int horizM) {
        beginTest("Random test %dx%dx%d%s", x, y, z, invalid ? ", invalid" : "");
        z = randomAlmost(z);
        px.random(x, z, n, horizN);
        py.random(y, invalid ? randomAlmost(z) : z, m, horizM);
        endTest();
    }

    void handmadeTests() {
        pyramid(2, 2, 1);
        pyramid(2, 2, 2);
        pyramid(4, 4, 2);
        randomTest(5, 5, 5, 3, 3, true, 0, 0);
        randomTest(5, 5, 5, 5, 5, true, 0, 1);
        roof(3, 2, 2, false);
        roof(10, 4, 10, true);
        pillow(4, 5, 2);
        pillow(7, 5, 10);
        pyramids(5, 5, 2, 1, 5);
        pyramids(5, 5, 1, 5, 2);
        pyramids(5, 5, 5, 5, 5);
        roofsPyramidsAndPillows(7, 7, 7, 7, 7, false);
        roofsPyramidsAndPillows(7, 7, 7, 7, 7, true);
        randomTest(10, 10, false, 0);
        randomTest(100, 100, false, 20);
        randomTest(100, 100, true, 0);
        randomTest(1000, 1000, false, 100);
        randomTest(30000, 30000, false, 0);
        randomTest(50000, 50000, true, 0);
        randomTest(100000, MAX_N, false, 0);
        randomTest(3000000, MAX_N, false, MAX_N / 10);
        randomTest(10000000, MAX_N, false, 0);

        randomTest(MAX_N, MAX_C, MAX_C, MAX_N, MAX_N, false, 0, 1);
        randomTest(MAX_C, MAX_N, MAX_C, MAX_N, MAX_N, false, MAX_N / 4, 0);
        randomTest(MAX_C, MAX_C, MAX_C / 2, MAX_N, MAX_N, false, 0, MAX_N / 10);
        randomTest(MAX_C, MAX_C, 10, MAX_N, MAX_N, false, 1, 0);

        randomTest(MAX_C / 2, MAX_N / 2, false, 0);
        randomTest(MAX_C / 2, MAX_N, false, 0);
        randomTest(MAX_C, MAX_N, true, MAX_N / 3);
        randomTest(MAX_C, MAX_N, false, 0);
    }

    public void run() throws IOException {
        sampleTests();
        handmadeTests();


        beginTest("Half-max test");
        px.max(MAX_C, MAX_C / 4);
        py.max(MAX_C, MAX_C / 4);
        endTest();

        beginTest("Max test");
        px.max(MAX_C, 0);
        py.max(MAX_C, 0);
        endTest();
    }

    public static void main(String[] args) throws IOException {
        descriptions = new PrintWriter("tests/tests.lst");
        new Tests().run();
        descriptions.close();
    }
}

