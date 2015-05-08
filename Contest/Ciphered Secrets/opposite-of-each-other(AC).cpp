#include <cstdio>
using namespace std;

const int N = 1000005;
char s[N];
int x;
int n;

int main()
{
	int t, ti;
	int i;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &x);
		scanf("%s", s);
		for (i = 0; i < n; ++i) {
			x = s[i] == 'A' ? x : -x;
		}
		printf("%d\n", x);
	}

	return 0;
}