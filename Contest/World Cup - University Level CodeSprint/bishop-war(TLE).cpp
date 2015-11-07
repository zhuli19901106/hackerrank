#include <cstdio>
using namespace std;

const int N = 10;
int n, m;
char s[N][N + 1];
int ans;
int d[4][2] = {{-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};

inline bool inbound(int x, int y)
{
    return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
}

void DFS(int r)
{
    if (r == n) {
        ++ans;
        return;
    }
    
    int i, k;
    int x, y;
    for (i = 0; i < m; ++i) {
        if (s[r][i] != '.') {
            // Either blocked or occupied
            continue;
        }
        
        s[r][i] = '+';
        for (k = 0; k < 4; ++k) {
            x = r + d[k][0];
            y = i + d[k][1];
            while (inbound(x, y) && s[x][y] != '*') {
                s[x][y] = '+';
                x += d[k][0];
                y += d[k][1];
            }
        }
        
        DFS(r + 1);
        
        for (k = 0; k < 4; ++k) {
            x = r + d[k][0];
            y = i + d[k][1];
            while (inbound(x, y) && s[x][y] != '*') {
                s[x][y] = '.';
                x += d[k][0];
                y += d[k][1];
            }
        }
        s[r][i] = '.';
    }
}

int main()
{
    int i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    ans = 0;
    
    DFS(0);
    printf("%d\n", ans);
    
    return 0;
}