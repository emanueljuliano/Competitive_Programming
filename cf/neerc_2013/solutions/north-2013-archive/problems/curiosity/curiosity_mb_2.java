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

public class curiosity_mb_2 {
    public static long fitness = 0;
    private static final int MAXN = 2000;

    private static final int MULTIPLE = 311;
    private static final long[] pow = new long[MAXN + 1];
    static {
        pow[0] = 1;
        for (int i = 1; i < pow.length; ++i) {
            pow[i] = pow[i - 1] * MULTIPLE;
        }
    }

    static class Hasher {
        private final String base;
        private final long[] prefix;
        public Hasher(String base) {
            this.base = base;
            prefix = new long[base.length() + 1];
            prefix[0] = 0;
            for (int i = 0; i < base.length(); ++i) {
                prefix[i + 1] = base.charAt(i) + prefix[i] * MULTIPLE;
            }
        }
        public long hash(int from, int until) {
            return prefix[until] - prefix[from] * pow[until - from];
        }
    }

    static class OpenHashMap {
        static final int SIZE = 1 << (32 - Integer.numberOfLeadingZeros(MAXN));
        static final int MASK = SIZE - 1;
        final long[] hashV;
        final int[] hashP;
        final int[] indexV;
        final int[] indexN;
        final int[] hashes;
        int size = 0;
        int hashCount = 0;
        public OpenHashMap() {
            hashV = new long[SIZE];
            hashP = new int[SIZE];
            indexV = new int[SIZE];
            indexN = new int[SIZE];
            hashes = new int[SIZE];
            clear();
        }
        public void clear() {
            Arrays.fill(hashV, -1);
            Arrays.fill(hashP, -1);
            size = 0;
            hashCount = 0;
        }
        private int lookup(long hash) {
            int hp = (int) (hash & MASK);
            while (true) {
                long v = hashV[hp];
                if (v == -1) {
                    hashV[hp] = hash;
                    hashes[hashCount++] = hp;
                    return hp;
                } else if (v == hash) {
                    return hp;
                }
                hp = (hp + 1) & MASK;
//                ++fitness;
            }
        }
        public void add(long hash, int index) {
            int hp = lookup(hash);
            indexV[size] = index;
            indexN[size] = hashP[hp];
            hashP[hp] = size;
            ++size;
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
            return hashP[hashes[i]];
        }
    }

    public static String solve(String f, String s) {
        Hasher hf = new Hasher(f);
        Hasher hs = new Hasher(s);
        OpenHashMap map = new OpenHashMap();
        int[] matchStore = new int[MAXN + 1];

        int bestSumLength = Integer.MAX_VALUE;
        int bestOffset = -1;
        int bestFirstLength = -1;

        for (int fLength = 1; fLength <= f.length(); ++fLength) {
            map.clear();
            for (int i = f.length() - fLength; i >= 0; --i) {
                map.add(hf.hash(i, i + fLength), i);
            }
            for (int h = 0, hl = map.hashCount(); h < hl; ++h) {
                int hashI = map.getHash(h);
                int matchCount = 0;
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
                        if (hf.hash(0, matchStore[0]) == hs.hash(0, matchStore[0])) {
                            boolean ok = true;
                            long hm = hs.hash(matchStore[0], matchStore[0] + sLength);
                            int resultLength = matchStore[0];
                            for (int i = 0; ok && i < matchCount; ++i) {  
                                ok &= hs.hash(resultLength, resultLength + sLength) == hm;
                                resultLength += sLength;
                                int end = i + 1 < matchCount ? matchStore[i + 1] : f.length();
                                int nsl = end - matchStore[i] - fLength;
                                ok &= hf.hash(matchStore[i] + fLength, end) == hs.hash(resultLength, resultLength + nsl);
                                resultLength += nsl;
                            }
                            if (ok) {
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
            if (1 > f.length() || f.length() > MAXN || 1 > s.length() || s.length() > MAXN || f.equals(s)) {
                throw new AssertionError();
            }
//            while (true) solve(f, s);
            out.println(solve(f, s));
        }
    }
}

