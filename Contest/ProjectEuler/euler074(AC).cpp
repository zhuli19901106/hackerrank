//https://www.hackerrank.com/contests/projecteuler/challenges/euler074
// Optimization on memory and speed is needed.
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1000000;
int f[10];
int a[N + 1];
int c[5 * N + 1];
int seq[1000];
int sc;
vector<int> v[65];

int next(int n)
{
	int s = 0;
	
	while (n != 0) {
		s += f[n % 10];
		n /= 10;
	}
	return s;
}

void solve(int n)
{
	int i;
	int ans;
	int cycle;

	i = 1;
	sc = 0;
	while (true) {
		if (c[n] > 0) {
			ans = i - 1;
			cycle = c[n];
			break;
		}
		c[n] = i++;
		seq[sc++] = n;
		n = next(n);
	}
	for (i = 0; i < ans; ++i) {
		c[seq[i]] = 0;
		if (i < cycle && seq[i] <= N) {
			a[seq[i]] = ans - i;
		}
	}
}

int main()
{
	int i;
	f[0] = 1;
	for (i = 1; i < 10; ++i) {
		f[i] = f[i - 1] * i;
	}
	
	memset(a, -1, sizeof(a));
	a[0] = 2;
	memset(c, 0, sizeof(c));
	for (i = 1; i <= N; ++i) {
		if (a[i] != -1) {
			continue;
		}
		solve(i);
	}
	
	for (i = 0; i <= N; ++i) {
		v[a[i]].push_back(i);
	}
	
	int t, ti;
	int len, n;
	int cc;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &len);
		cc = 0;
		for (i = 0; i < v[len].size(); ++i) {
			if (v[len][i] > n) {
				break;
			}
			printf((cc++ ? " %d" : "%d"), v[len][i]);
		}
		if (cc == 0) {
			printf("-1");
		}
		printf("\n");
	}
	
	return 0;
}