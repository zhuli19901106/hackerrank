#include <cstdio>
using namespace std;

int main()
{
    char s[100];
    int hh, mm, ss;
    
    scanf("%s", s);
    sscanf(s, "%02d:%02d:%02d", &hh, &mm, &ss);
    if (s[8] == 'A') {
        if (hh == 12) {
            hh = 0;
        }
    } else {
        if (hh != 12) {
            hh += 12;
        }
    }
    printf("%02d:%02d:%02d\n", hh, mm, ss);
    
    return 0;
}