#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2000000;
int n, k;
int a[N + 1];

int main()
{
    int i, j;
    
    memset(a, 0, (N + 1) * sizeof(int));
    scanf("%d%d", &n, &k);
    for (i = 0; i < k; ++i) {
        scanf("%d", &j);
        a[j] = 1;
    }
    i = 1;
    while (i <= n) {
        while (i <= n && a[i] == 1) {
            ++i;
        }
        j = i + 1;
        while (j <= n && a[j] != 1) {
            ++j;
        }
        if (i == 1 || j > n) {
            k += (j - i) / 2;
        } else {
            k += (j - i - 1) / 2;
        }
        i = j + 1;
    }
    printf("%d\n", k);
    
    return 0;
}