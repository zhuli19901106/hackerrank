#include <cstdio>
using namespace std;

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            putchar(' ');
        }
        for (j = 0; j <= i; ++j) {
            putchar('#');
        }
        putchar('\n');
    }
    
    return 0;
}