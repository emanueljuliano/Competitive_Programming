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
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>
#include <cassert>
#include <vector>

const int MOD = 1000000000;

using std::vector;

const int N = 523456;

int pf[N], xx[N], type[N], left[N], right[N], s[N], cur, len, fr = 0, n, yy[N];


const int POW = 12;
const int UM = ~1;
const int USQ = ~2;
const int UF = ~3;
const int BSUM = ~4;
const int BMUL = ~5;
const int BMIN = ~6;
const int VX = ~7;

int pT();

int pE() {
  if (s[cur] == '-' || (s[cur] == '*' && s[cur + 1] == ':') || (s[cur] == '+' && s[cur + 1] == '/')) {
    int v = fr++;
    type[v] = s[cur] == '-' ? UM : s[cur] == '*' ? USQ : UF;
    if (s[cur] == '-') ++cur; else {
      cur += 2;
    }
    left[v] = pE();
    return v;
  }
  int v = pT();
  while (cur < len && (s[cur] == '+' || s[cur] == '-' || s[cur] == '*')) {
    int u = fr++;
    type[u] = s[cur] == '+' ? BSUM : s[cur] == '-' ? BMIN : BMUL;
    ++cur;
    left[u] = v;
    right[u] = pE();
    v = u;
  }
  return v;
}

int pT() {
  if (s[cur] == '(') {
    ++cur;
    int v = pE();
    assert(s[cur] == ')');
    ++cur;
    return v;
  }
  if (s[cur] == 'X') {
    ++cur;
    int v = fr++;
    type[v] = VX;
    return v;
  }
  if (s[cur] == 'N') {
    ++cur;
    int v = fr++;
    type[v] = n;
    return v;
  }
  int v = fr++;
  type[v] = 0;
  while (s[cur] >= '0' && s[cur] <= '9') {
    type[v] = type[v] * 10 + s[cur] - '0';
    ++cur;
  }
  return v;
}

vector<int> mul(vector<int> const & a, vector<int> const & b) {
  int n = a.size();
  int m = b.size();
  vector<int> c(n + m - 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i + j] += (long long) a[i] * b[j] % MOD;
      c[i + j] %= MOD;
    }
  }
  return c;
}

vector<int> add(vector<int> const & a, vector<int> const & b) {
  int n = a.size();
  int m = b.size();
  vector<int> c(std::max(n, m));
  for (int i = 0; i < n || i < m; i++) {
    if (i < n) c[i] += a[i];
    if (i < m) c[i] += b[i];
    if (c[i] >= MOD) c[i] -= MOD;
  }
  return c;
}

vector<int> sub(vector<int> const & a, vector<int> const & b) {
  int n = a.size();
  int m = b.size();
  vector<int> c(std::max(n, m));
  for (int i = 0; i < n || i < m; i++) {
    if (i < n) c[i] += a[i];
    if (i < m) c[i] -= b[i];
    if (c[i] < 0) c[i] += MOD;
  }
  return c;
}

vector<int> eval(int v) {
  if (type[v] >= 0) {
    vector<int> a(1);
    a[0] = type[v];
    return a;
  }
  if (type[v] == VX) {
    vector<int> a(2);
    a[1] = 1;
    return a;
  }
  if (type[v] == UM) {
    vector<int> a = eval(left[v]);
    int n = a.size();
    for (int i = 0; i < n; i++) {
      a[i] = a[i] == 0 ? 0 : MOD - a[i];
    }
    return a;
  }
  if (type[v] == USQ) {
    vector<int> a = eval(left[v]);
    a = mul(a, a);
    return a;
  }
  if (type[v] == UF) {
    vector<int> a = eval(left[v]);
    vector<int> b(1);
    int n = a.size();
    int s = 0;
    for (int i = 0; i < n; i++) {
      s = (s + (long long) pf[i] * a[i]) % MOD;
    }
    b[0] = s;
    return b;
  }
  if (type[v] == BSUM) {
    vector<int> a = eval(left[v]);
    vector<int> b = eval(right[v]);
    return add(a, b);
  }
  if (type[v] == BMUL) {
    vector<int> a = eval(left[v]);
    vector<int> b = eval(right[v]);
    return mul(a, b);
  }
  if (type[v] == BMIN) {
    vector<int> a = eval(left[v]);
    vector<int> b = eval(right[v]);
    return sub(a, b);
  }  
  assert(false);
}

int main() {
  freopen("j.in", "r", stdin);
  freopen("j.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", xx + i);
  }
  cur = 0;
  for (int i = 0; i < n; i++) yy[i] = 1;
  for (int i = 0; i < POW; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      s = (s + yy[j]) % MOD;
      yy[j] = (long long) yy[j] * xx[j] % MOD;
    }
    pf[i] = s;
  }
  int c = getchar();
  while (c <= 32) c = getchar();
  while (c > 32) {
    s[len++] = c;
    c = getchar();
  }
  int v = pE();
  vector<int> ans = eval(v);
  printf("%d\n", ans[0]);
}
