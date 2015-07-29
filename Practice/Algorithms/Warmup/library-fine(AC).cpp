#include <cstdio>
using namespace std;

int main()
{
    int y, m, d;
    int y1, m1, d1;
    int f;
    
    scanf("%d%d%d", &d1, &m1, &y1);
    scanf("%d%d%d", &d, &m, &y);
    f = 0;
    do {
        if (y1 < y) {
            f = 0;
            break;
        }
        if (y1 > y) {
            f = 10000;
            break;
        }
        if (m1 < m) {
            f = 0;
            break;
        }
        if (m1 > m) {
            f = 500 * (m1 - m);
            break;
        }
        if (d1 < d) {
            f = 0;
            break;
        }
        f = 15 * (d1 - d);
    } while (false);
    printf("%d\n", f);
    
    return 0;
}