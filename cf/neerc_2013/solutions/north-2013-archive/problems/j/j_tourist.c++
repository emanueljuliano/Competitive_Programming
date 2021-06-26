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
/* Author                Gennady Korotkevich                      */
/******************************************************************/

#include <stdio.h>
#include <cassert>
#include <set>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char s[123456];
int pos;
string token;
int n;
int x[123456];

void get_token() {
  if (s[pos] == 0) {
    token = "";
    return;
  }
  token = "";
  token += s[pos];
  if ('0' <= s[pos] && s[pos] <= '9') {
    pos++;
    while ('0' <= s[pos] && s[pos] <= '9') {
      token += s[pos];
      pos++;
    }
  } else
  if ('*' == s[pos] && ':' == s[pos + 1]) {
    pos++;
    token += s[pos];
    pos++;
  } else
  if ('+' == s[pos] && '/' == s[pos + 1]) {
    pos++;
    token += s[pos];
    pos++;
  }
  else pos++;
}

const int C = 12;
const int md = 1000000000;

int spow[C];

struct Poly {
  int* a;
  
  Poly() {
    this->a = new int[C];
    for (int i = 0; i < C; i++) this->a[i] = 0;
  }
};

Poly* parse_expr();

Poly* parse_term() {
  if (token == "(") {
    get_token();
    Poly* res = parse_expr();
    assert(token == ")");
    get_token();
    return res;
  }
  if (token == "X") {
    Poly* res = new Poly();
    res->a[1] = 1;
    get_token();
    return res;
  }
  if (token == "N") {
    Poly* res = new Poly();
    res->a[0] = n;
    get_token();
    return res;
  }
  Poly* res = new Poly();
  res->a[0] = 0;
  int len = token.length();
  for (int i = 0; i < len; i++) res->a[0] = res->a[0] * 10 + (token[i] - '0');
  get_token();
  return res;
}

Poly* parse_expr() {
  if (token == "-" || token == "*:" || token == "+/") {
    string op = token;
    get_token();
    Poly* res = parse_expr();
    if (op == "-") {
      for (int i = 0; i < C; i++) res->a[i] = (md - res->a[i]) % md;
    } else
    if (op == "*:") {
      int z[C];
      for (int i = 0; i < C; i++) z[i] = 0;
      for (int i = 0; i < C; i++)
        for (int j = 0; i + j < C; j++) z[i + j] = (z[i + j] + 1LL * res->a[i] * res->a[j]) % md;
      for (int i = 0; i < C; i++) res->a[i] = z[i];
    } else {
      int sum = 0;
      for (int i = 0; i < C; i++) sum = (sum + 1LL * spow[i] * res->a[i]) % md;
      res->a[0] = sum;
      for (int i = 1; i < C; i++) res->a[i] = 0;
    }
    return res;
  }
  Poly* x = parse_term();
  if (token == "" || token == ")") return x;
  string op = token;
  get_token();
  Poly* y = parse_expr();
  if (op == "+") {
    for (int i = 0; i < C; i++) x->a[i] = (x->a[i] + y->a[i]) % md;
    return x;
  }
  if (op == "-") {
    for (int i = 0; i < C; i++) x->a[i] = (x->a[i] + md - y->a[i]) % md;
    return x;
  }
  assert(op == "*");
  int z[C];
  for (int i = 0; i < C; i++) z[i] = 0;
  for (int i = 0; i < C; i++)
    for (int j = 0; i + j < C; j++) z[i + j] = (z[i + j] + 1LL * x->a[i] * y->a[j]) % md;
  for (int i = 0; i < C; i++) x->a[i] = z[i];
  return x;
}

int main() {
  freopen("j.in", "r", stdin);
  freopen("j.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  for (int p = 0; p < C; p++) {
    spow[p] = 0;
  }
  for (int i = 0; i < n; i++) {
    int z = 1;
    for (int p = 0; p < C; p++) {
      spow[p] = (spow[p] + z) % md;
      z = (1LL * z * x[i]) % md;
    }
  }
  scanf("%s", s);
  pos = 0;
  get_token();
  Poly* p = parse_expr();
  printf("%d\n", p->a[0]);
  return 0;
}
