#include <cstdio>
using namespace std;

typedef unsigned long long int ULL;

const int N = 64;
ULL dp[N][3];
ULL ans;

ULL solve(ULL x, int idx)
{
	if (x == 0) {
		return idx == 0 ? 1 : 0;
	}
	ULL b = 1ull << 63;
	int i = 63;
	while (b > x) {
		b >>= 1;
		--i;
	}
	return solve(x ^ b, (idx + 2) % 3) + dp[i][idx];
}

int main()
{
	int i;

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (i = 1; i < N; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] + dp[i - 1][1];
	}

	int t, ti;
	ULL x;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%llu", &x);
		ans = solve(x, 0) - 1;
		printf("%llu\n", ans);
	}

	return 0;
}