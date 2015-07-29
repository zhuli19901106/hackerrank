#include <cstdio>
using namespace std;

int main()
{
    int n;
    int i, j;
    int sum = 0;
    int val;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &val);
            if (i == j) {
                sum += val;
            }
            if (i + j == n - 1) {
                sum -= val;
            }
        }
    }
    sum = sum >= 0 ? sum : -sum;
    printf("%d\n", sum);
    
    return 0;
}