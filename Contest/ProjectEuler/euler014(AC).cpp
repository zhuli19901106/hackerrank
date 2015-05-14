//https://www.hackerrank.com/contests/projecteuler/challenges/euler014
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5000000;
int a[N + 1];
int ans[N + 1];

long long int st[1000];
int sp;

int solve(long long int n)
{
	if (n == 1) {
		return 0;
	}

	if (a[n] != -1) {
		return a[n];
	}

	sp = 0;
	while (true) {
		st[sp++] = n;
		n = n & 1 ? (n + (n << 1) + 1) : n >> 1;
		if (n <= N && a[n] != -1) {
			break;
		}
	}
	int c = a[n];

	int i;
	for (i = sp - 1; i >= 0; --i) {
		++c;
		if (st[i] > N) {
			continue;
		}
		a[st[i]] = c;
	}

	return c;
}

int main()
{
	memset(a, -1, sizeof(a));

	int i;
	int mx;
	int mi;

	ans[0] = 0;
	mx = 0;
	mi = 0;
	for (i = 1; i <= N; ++i) {
		a[i] = solve(i);
		if (a[i] >= mx) {
			mx = a[i];
			mi = i;
		}
		ans[i] = mi;
	}

	int t, ti;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &i);
		printf("%d\n", ans[i]);
	}
	
	return 0;
}