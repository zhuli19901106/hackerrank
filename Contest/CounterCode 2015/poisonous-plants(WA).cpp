#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

const int N = 100000;
int n;
int a[N + 1];

void solve()
{
    int ans = 0;
    int cc;
    int i, j;
    
    i = 0;
    j = i + 1;
    while (i < n) {
        if (a[i] >= a[j]) {
            i = j;
            j = i + 1;
            continue;
        }
        cc = 0;
        while (j < n && a[i] < a[j]) {
            while (j < n && a[j] < a[j + 1]) {
                ++j;
            }
            ++j;
            ++cc;
        }
        i = j;
        j = i + 1;
        ans = max(ans, cc);
    }
    printf("%d\n", ans);
}

int main()
{
    int i;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        a[n] = INT_MIN;
        solve();
    }
    
    return 0;
}