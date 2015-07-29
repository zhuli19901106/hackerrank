#include <cstdio>
#include <cstring>
using namespace std;

/*
4 5
10101
11100
11010
00101
*/

const int N = 505;
const int M = 16;
unsigned a[N][M];
int ac;
int n, m;
int len;
char s[1000];
char t[35];
int maxone;
int maxcc;

void getBits(int i)
{
	int j, k;
	unsigned b;
	
	for (j = 0; j < m; ++j) {
		b = 0;
		for (k = 0; k < 32; ++k) {
			b = (b << 1) | (s[(j << 5) + k] - '0');
		}
		a[i][j] = b;
	}
}

int countMatch(int x, int y)
{
	int i;
	unsigned u;
	int one;
	
	one = 0;
	for (i = 0; i < m; ++i) {
		u = a[x][i] | a[y][i];
		while (u != 0) {
			u = u & u - 1u;
			++one;
		}
	}
	
	return one;
}

int main()
{
	int i, j;

	scanf("%d%d", &n, &m);
	int r = (32 - (m & 31)) & 31;
	for (i = 0; i < r; ++i) {
		t[i] = '0';
	}
	t[i] = 0;
	
	m = (m + 31) / 32;
	for (i = 0; i < n; ++i) {
		scanf("%s", s);
		strcat(s, t);
		getBits(i);
	}
	
	int one;
	
	maxone = -1;
	maxcc = 0;
	for (i = 0; i < n; ++i) {
		for (j = i + 1; j < n; ++j) {
			one = countMatch(i, j);
			if (one > maxone) {
				maxone = one;
				maxcc = 1;
			} else if (one == maxone) {
				++maxcc;
			}
		}
	}
	
	printf("%d\n%d\n", maxone, maxcc);
	
	return 0;
}