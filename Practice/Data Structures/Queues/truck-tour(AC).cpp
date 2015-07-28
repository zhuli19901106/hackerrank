#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;
int main()
{
    vector<int> v;
    int x, y;
    int n, i, j;
    
    scanf("%d", &n);
    v.resize(n);
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        v[i] = x - y;
    }
    LL sum = 0;
    j = 0;
    for (i = 0; i < 2 * n - 1; ++i) {
        if (i - j >= n) {
            printf("%d\n", j);
            break;
        }
        sum += v[i % n];
        if (sum <= 0) {
            j = i + 1;
            sum = 0;
        }
    }
    
    return 0;
}