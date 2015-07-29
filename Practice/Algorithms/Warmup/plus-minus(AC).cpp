#include <cstdio>
using namespace std;

int main()
{
    int p, n, z;
    int nn, i, val;
    
    p = n = z = 0;
    scanf("%d", &nn);
    for (i = 0; i < nn; ++i) {
        scanf("%d", &val);
        if (val > 0) {
            ++p;
        } else if (val < 0) {
            ++n;
        } else {
            ++z;
        }
    }
    printf("%.3f\n", 1.0 * p / nn);
    printf("%.3f\n", 1.0 * n / nn);
    printf("%.3f\n", 1.0 * z / nn);
    
    return 0;
}