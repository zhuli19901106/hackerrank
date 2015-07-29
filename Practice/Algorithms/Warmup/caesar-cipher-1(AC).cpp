#include <cctype>
#include <cstdio>
using namespace std;

int main()
{
    int n, k;
    char s[200];
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);
    
    int i;
    for (i = 0; i < n; ++i) {
        if (islower(s[i])) {
            s[i] = (s[i] - 'a' + k) % 26 + 'a';
        }
        if (isupper(s[i])) {
            s[i] = (s[i] - 'A' + k) % 26 + 'A';
        }
    }
    puts(s);
    
    return 0;
}