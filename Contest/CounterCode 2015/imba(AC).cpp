#include <cstdio>
using namespace std;

const int N = 100000;
int a[N];
int n;

void solve()
{
    int i, j;
    j = (n & 1) ^ 1;
    for (i = n / 2 + 1; i <= n; ++i) {
        a[j] = i;
        j += 2;
    }
    j = n & 1;
    for (i = n / 2; i >= 1; --i) {
        a[j] = i;
        j += 2;
    }
    for (i = 0; i < n; ++i) {
        printf((i ? " %d" : "%d"), a[i]);
    }
    printf("\n");
}

int main()
{
    int t, ti;
    
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        scanf("%d", &n);
        solve();
    }
    
    return 0;
}