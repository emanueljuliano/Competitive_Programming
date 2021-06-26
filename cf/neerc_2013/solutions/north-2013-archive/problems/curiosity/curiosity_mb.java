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
/* Solution                                                       */
/*                                                                */
/* Author                Maxim Buzdalov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class curiosity_mb {
    public static long fitness = 0;

    private static final int MODULO = 1000000007;
    private static final int MULTIPLE = 311;
    private static int add(int a, int b) {
        return (a + b) % MODULO;
    }
    private static int sub(int a, int b) {
        return (a - b + MODULO) % MODULO;
    }
    private static int mul(int a, int b) {
        return (int) (((long) (a) * b) % MODULO);
    }
    private static final int[] pow = new int[2001];
    static {
        pow[0] = 1;
        for (int i = 1; i < pow.length; ++i) {
            pow[i] = mul(pow[i - 1], MULTIPLE);
        }
    }

    static class Hasher {
        private final String base;
        private final int[] prefix;
        public Hasher(String base) {
            this.base = base;
            prefix = new int[base.length() + 1];
            prefix[0] = 0;
            for (int i = 0; i < base.length(); ++i) {
                prefix[i + 1] = add(base.charAt(i), mul(prefix[i], MULTIPLE));
            }
        }
        public int hash(int from, int until) {
            return sub(prefix[until], mul(prefix[from], pow[until - from]));
        }
        public static int concat(int hash1, int len1, int hash2, int len2) {
            return add(mul(hash1, pow[len2]), hash2);
        }
    }

    static class OpenHashMap {
        static final int SIZE = 10007;
        final int[] hashV;
        final int[] hashP;
        final int[] indexV;
        final int[] indexN;
        final int[] hashes;
        int size = 0;
        int hashCount = 0;
        public OpenHashMap() {
            hashV = new int[SIZE];
            hashP = new int[SIZE];
            indexV = new int[SIZE];
            indexN = new int[SIZE];
            hashes = new int[SIZE];
            clear();
        }
        public void clear() {
            Arrays.fill(hashV, -1);
            Arrays.fill(hashP, -1);
            Arrays.fill(indexV, -1);
            Arrays.fill(indexN, -1);
            Arrays.fill(hashes, -1);
            size = 0;
            hashCount = 0;
        }
        private int lookup(int hash) {
            int hp = hash % SIZE;
            while (hashV[hp] != -1 && hashV[hp] != hash) {
                hp = (hp + 1) % SIZE;
                ++fitness;
            }
            if (hashV[hp] == -1) {
                hashV[hp] = hash;
                hashes[hashCount++] = hash;
            }
            return hp;
        }
        public void add(int hash, int index) {
            int hp = lookup(hash);
            indexV[size] = index;
            indexN[size] = hashP[hp];
            hashP[hp] = size;
            ++size;
        }
        public int indexByHash(int hash) {
            return hashP[lookup(hash)];
        }
        public int get(int index) {
            return indexV[index];
        }
        public int next(int index) {
            return indexN[index];
        }
        public int hashCount() {
            return hashCount;
        }
        public int getHash(int i) {
            return hashes[i];
        }
    }

    public static String solve(String f, String s) {
        Hasher hf = new Hasher(f);
        Hasher hs = new Hasher(s);
        OpenHashMap map = new OpenHashMap();
        int[] matchStore = new int[2001];

        int bestSumLength = Integer.MAX_VALUE;
        int bestOffset = -1;
        int bestFirstLength = -1;

        for (int fLength = 1; fLength <= f.length(); ++fLength) {
            map.clear();
            for (int i = f.length() - fLength; i >= 0; --i) {
                map.add(hf.hash(i, i + fLength), i);
            }
            for (int h = 0, hl = map.hashCount(); h < hl; ++h) {
                int hash = map.getHash(h);
                int matchCount = 0;
                int hashI = map.indexByHash(hash);
                int prevIndex = -1;
                while (hashI != -1) {
                    int index = map.get(hashI);
                    if (prevIndex == -1 || prevIndex + fLength <= index) {
                        matchStore[matchCount++] = index;
                        prevIndex = index;
                    }
                    hashI = map.next(hashI);
                }
                if (Math.abs(s.length() - f.length()) % matchCount == 0) {
                    int sLength = fLength + (s.length() - f.length()) / matchCount;
                    if (sLength >= 0) {
                        
                        int resultHash = hf.hash(0, matchStore[0]);
                        int resultLength = matchStore[0];
                        for (int i = 0; i < matchCount; ++i) {
                            resultHash = Hasher.concat(
                                    resultHash, resultLength,
                                    hs.hash(matchStore[0], matchStore[0] + sLength), sLength
                            );
                            resultLength += sLength;
                            int end = i + 1 < matchCount ? matchStore[i + 1] : f.length();
                            int nsl = end - matchStore[i] - fLength;
                            resultHash = Hasher.concat(
                                    resultHash, resultLength,
                                    hf.hash(matchStore[i] + fLength, end), nsl
                            );
                            resultLength += nsl;
                        }
                        if (resultHash == hs.hash(0, s.length())) {
                            if (fLength + sLength < bestSumLength) {
                                bestSumLength = fLength + sLength;
                                bestFirstLength = fLength;
                                bestOffset = matchStore[0];
                            }
                        }
                    }
                }
            }
        }
        if (bestOffset == -1) throw new AssertionError();
        return "s/" + f.substring(bestOffset, bestOffset + bestFirstLength) + "/"
                    + s.substring(bestOffset, bestOffset + bestSumLength - bestFirstLength) + "/g";
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new FileReader("curiosity.in"));
             PrintWriter out = new PrintWriter("curiosity.out")) {
            String f = in.readLine();
            String s = in.readLine();
            if (1 > f.length() || f.length() > 2000 || 1 > s.length() || s.length() > 2000 || f.equals(s)) {
                throw new AssertionError();
            }
            out.println(solve(f, s));
        }
    }
}

