#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5000000;
int ans[N];

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

void solve()
{
	int i, j, k;
	int x, y, z;
	int sum;
	
	i = 1;
	while (true) {
		if ((4 * i + 6) * i + 2 > N) {
			break;
		}
		j = i + 1;
		while (true) {
			x = j * j - i * i;
			y = 2 * j * i;
			if (gcd(x, y) != 1) {
				++j;
				continue;
			}
			z = j * j + i * i;
			sum = x + y + z;
			if (sum > N) {
				break;
			}
			k = 1;
			while (k * sum <= N) {
				++ans[k * sum];
				++k;
			}
			++j;
		}
		++i;
	}
	
	for (i = 1; i <= N; ++i) {
		ans[i] = ans[i] == 1 ? ans[i - 1] + 1 : ans[i - 1];
	}
}

int main()
{
	solve();
	
	int t, ti;
	int n;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	
	return 0;
}