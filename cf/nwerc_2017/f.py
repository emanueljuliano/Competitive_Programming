import functools

import sys
MAX = 1000000
sys.setrecursionlimit(MAX)

@functools.lru_cache(maxsize=MAX)
def T(n):
    if (n == 1):
        return 1
    ans = 0
    for k in range(1, n//2):
        ans = max(ans, T(n-k) + T(k) + 2*k)
    return ans


print(T(int(2e4)))
