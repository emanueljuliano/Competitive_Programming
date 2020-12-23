#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;


#define int ll
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());


typedef pair<int, int> pii;
typedef pair<string, string> pst;
typedef pair<pii, pii> piii;
typedef vector<piii> vpii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<pii> vpi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;
typedef pair<pld, pld> pldd;
typedef vector<pld> vpd;
typedef complex<double> base;


#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define my_abs(a) (((a) >= 0) ? (a) : -(a))
#define mp(a, b) make_pair(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define MODIK(a) (a >= M ? a - M : a)
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cout << (#x) << " = " << x << endl;
#ifdef ART_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif

//#define cerr if (false) cerr

const double PI = 2 * acos(0.0);

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";

istream &operator >> (istream &in, pii &a)
{
    in >> a.first >> a.second;
    return in;
}


ostream &operator << (ostream &out, pii &a)
{
    out << a.first << ' ' << a.second;
    return out;
}


istream &operator >> (istream &in, pld &a)
{
    in >> a.first >> a.second;
    return in;
}


ostream &operator << (ostream &out, pld &a)
{
    out << a.first << ' ' << a.second;
    return out;
}


template <class T0, class T1>
inline ostream & operator << (ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template <class T0, class T1, class T2>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template <class T0, class T1, class T2, class T3>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) <<
               ", " << get<2>(a) << ", " <<  get<3>(a) << "}";
}

template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void print(int a, int b, int n, vi h)
{
    ofstream cout("output.txt");
    cout << SZ(h) << ' ' << a << ' ' << b << '\n';
    for (int i = 0; i < SZ(h); ++i) {
        cout << h[i]  << ' ';
    }
    cout.close();
    exit(0);
}


inline bool break_time(ld time)
{
    return clock() > CLOCKS_PER_SEC * time;
}


void bonds()
{
    ld price, nkd, kd, year;
    int cnt;
    cout << "price nkd kd cnt year\n";
    cout << endl;
    cin >> price >> nkd >> kd >> cnt >> year;
    cout << 100 * ((1000 + kd * cnt - price * 10 - nkd) / (price * 10) / year);
}


ld get_rand_ld(ld l, ld r)
{
    uniform_real_distribution<double> gen(l, r);
    return gen(rng);
}


bool may(int E, ld T)
{
    if (E < 0)
        return 1;

    double eps = get_rand_ld(0, 1);
    return eps < exp(-E / T);
}



void smain();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef ART_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
//#else
//    freopen("trapped.in", "r", stdin);
//    freopen("trapped.out", "w", stdout);
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef ART_HOME
    cout << "\nTOTAL EXECUTIOn TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
}


const int N = 500 + 10, K = 1e9 + 10, A = 26, B = 2e2, oo = 1e10, M = 11092019, LOG = 17;
const int M1 = 1000000093, x1 = 27162;
const int M2 = 1000000087, x2 = 241;
const ld pi = atan2(1, 0) * 2, EPS = 1e-9, CEPS = 1e-11;


void NO()
{
    cout << "No\n";
    exit(0);
}


void YES()
{
    cout << "Yes\n";
    exit(0);
}


void smain() {
    int k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;

    if (t <= 1e7)
    {
        for (int i = 0; i < t; ++i)
        {
            if (k + y <= r)
                k += y;

            k -= x;
            if (k < l)
                NO();
        }

        YES();
    }

    if (x >= y)
    {
        if (k + y <= r)
            k += y;

        k -= x;
        t--;

        if (k / t < l / t + (x - y) - 5)
            NO();

        if (k < l + (x - y) * t)
            NO();
        
        YES();
    }

    for (int i = 0; i < 1e6 + 100; ++i) {
        if (k + y <= r)
            k += y;

        k -= x;
        if (k < l)
            NO();

        t--;

        int lb = -1, rb = 4e18 / x + 10;
        while (rb - lb > 1) {
            int m = lb + rb >> 1LL;
            if (k - x * m + y <= r)
                rb = m;
            else
                lb = m;
        }

        rb = min(rb, t);
        k -= rb * x;
        t -= rb;

        if (k < l)
            NO();

        if (!t)
            YES();
    }

    YES();
}