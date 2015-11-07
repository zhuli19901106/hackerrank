#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    const int n = 10;
    int a[n];
    int i;
    int sum;
    
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    sum = 0;
    for (i = 0; i < 6; i += 2) {
        sum += a[n - 1 - i];
    }
    printf("%d\n", sum);
    
    return 0;
}