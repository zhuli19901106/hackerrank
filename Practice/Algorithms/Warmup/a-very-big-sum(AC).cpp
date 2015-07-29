#include <cstdio>
using namespace std;

typedef long long int LL;
int main()
{
    int n;
    int i;
    int val;
    LL sum = 0;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &val);
        sum += val;
    }
    printf("%lld\n", sum);
    
    return 0;
}