#include <cstdio>
using namespace std;

void solve(int n, int m)
{
    int d = 0;
    int i;
    if (n % 2) {
        d += m / (2 * n) * 2;
        m %= 2 * n;
        if (m < n) {
            i = m % 2 == 0 ? m / 2 + 1 : n + 1 - (m + 1) / 2;
        } else if (m == n) {
            ++d;
            i = n;
        } else {
            ++d;
            m -= n + 1;
            i = m % 2 == 0 ? m / 2 + 1 : n - (m + 1) / 2;
        }
    } else {
        d += m / n;
        m %= n;
        i = m % 2 == 0 ? m / 2 + 1 : n + 1 - (m + 1) / 2;
    }
    printf("%d %d\n", i, d);
}

int main()
{
    int t, ti;
    int n, m;
    
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        scanf("%d%d", &n, &m);
        --m;
        solve(n, m);
    }
    
    return 0;
}