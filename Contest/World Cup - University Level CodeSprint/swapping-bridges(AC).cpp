#include <cstdio>
using namespace std;

const int N = 50005;
int dj[N];

int findRoot(int x)
{
    int r = x;
    while (r != dj[r]) {
        r = dj[r];
    }
    int k = x;
    while (k != r) {
        x = dj[x];
        dj[k] = r;
        k = x;
    }
    return r;
}

int main()
{
    int cases, ci;
    int i, j;
    int ri, rj;
    int cc;
    int n;
    
    scanf("%d", &cases);
    for (ci = 0; ci < cases; ++ci) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            dj[i] = i;
        }
        for (i = 0; i < n; ++i) {
            scanf("%d", &j);
            --j;
            ri = findRoot(i);
            rj = findRoot(j);
            if (ri != rj) {
                dj[ri] = rj;
            }
        }
        cc = 0;
        for (i = 0; i < n; ++i) {
            findRoot(i);
            if (dj[i] == i) {
                ++cc;
            }
        }
        printf("%d\n", cc - 1);
    }
    
    return 0;
}