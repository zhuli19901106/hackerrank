#include <cstdio>
#include <vector>
using namespace std;

vector<int> dj, cc;
int n, m;

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
    int x, y;
    int rx, ry;
    int i;
    char s[10];
    
    scanf("%d%d", &n, &m);
    dj.resize(n + 1);
    cc.resize(n + 1);
    for (i = 1; i <= n; ++i) {
        dj[i] = i;
        cc[i] = 1;
    }
    for (i = 1; i <= m; ++i) {
        scanf("%s", s);
        if (s[0] == 'M') {
            scanf("%d%d", &x, &y);
            rx = findRoot(x);
            ry = findRoot(y);
            if (rx != ry) {
                dj[rx] = ry;
                cc[ry] += cc[rx];
            }
        } else if (s[0] == 'Q') {
            scanf("%d", &x);
            printf("%d\n", cc[findRoot(x)]);
        }
    }
    
    return 0;
}