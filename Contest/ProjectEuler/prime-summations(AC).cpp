#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long int LL;
const int N = 1000;
char b[N + 1];
int p[N / 2];
vector<LL> dp[N + 1];
vector<LL> sum;
int pc;

void Eratosthenes()
{
	int i, j;
	
	memset(b, 0, sizeof(b));
	
	b[0] = b[1] = 1;
	for (i = 2; i <= N / i; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; j <= N / i; ++j) {
			b[i * j] = 1;
		}
	}
	pc = 0;
	for (i = 0; i <= N; ++i) {
		if (b[i]) {
			continue;
		}
		p[pc++] = i;
	}
}

int main()
{
	Eratosthenes();
	
	int i, j, k;
	
	for (i = 0; i <= N; ++i) {
		dp[i].resize(pc, 0);
		dp[i][0] = (i & 1) ? 0 : 1;
	}
	
	for (i = 1; i < pc; ++i) {
		dp[0][i] = 1;
		for (j = 1; j <= N; ++j) {
			dp[j][i] = dp[j][i - 1];
			k = j - p[i];
			while (k >= 0) {
				dp[j][i] += dp[k][i - 1];
				k -= p[i];
			}
		}
	}
	
	sum.resize(N + 1, 0);
	for (i = 2; i <= N; ++i) {
		sum[i] = dp[i][pc - 1];
		// printf("a[%d] = %lld\n", i, sum[i]);
	}

	int t, ti;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &i);
		printf("%lld\n", sum[i]);
	}
	
	return 0;
}