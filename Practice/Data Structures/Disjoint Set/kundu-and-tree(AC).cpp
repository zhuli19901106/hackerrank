#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;
const LL MOD = 1000000007LL;
vector<int> dj, cc;
vector<LL> v;
vector<LL> sum;
int n;

int findRoot(int x)
{
    int r = x;
    while (r != dj[r]) {
        r = dj[r];
    }
    int k = x;
    while (x != r) {
        x = dj[x];
        dj[k] = r;
        cc[k] = cc[r];
        k = x;
    }
    return r;
}

int main()
{
    scanf("%d", &n);
    dj.resize(n + 1);
    cc.resize(n + 1);
    
    int i;
    for (i = 1; i <= n; ++i) {
        dj[i] = i;
        cc[i] = 1;
    }
    
    int x, y;
    int rx, ry;
    char s[1000];
    for (i = 1; i < n; ++i) {
        scanf("%d%d%1s", &x, &y, s);
        if (s[0] == 'r') {
            continue;
        }
        rx = findRoot(x);
        ry = findRoot(y);
        if (rx != ry) {
            dj[rx] = ry;
            cc[ry] += cc[rx];
        }
    }
    for (i = 1; i <= n; ++i) {
        findRoot(i);
        if (i == dj[i]) {
            v.push_back(cc[i]);
        }
    }
    
    n = v.size();
    sum.resize(n);
    sum[0] = v[0];
    for (i = 1; i < n; ++i) {
        sum[i] = (sum[i - 1] + v[i]) % MOD;
    }
    
    for (i = n - 1; i > 0; --i) {
        sum[i] = (v[i] * sum[i - 1]) % MOD;
    }
    sum[0] = 0;
    
    for (i = 1; i < n; ++i) {
        sum[i] = (sum[i] + sum[i - 1]) % MOD;
    }
    
    LL ans = 0;
    for (i = 1; i < n; ++i) {
        ans = (ans + v[i] * sum[i - 1]) % MOD;
    }
    printf("%lld\n", ans);
    
    return 0;
}