// Wo le ge qu. Zhe jiu AC le...
#include <cstdio>
using namespace std;

const int N = 500005;
int a[N];
int p[N];
int n;
int sum;

int main()
{
	int t, ti;
	int i;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			p[a[i]] = i;
		}
		sum = p[1] - 1;
		i = 2;
		while (true) {
			if (p[i] < p[i - 1]) {
				sum += n - p[i - 1];
				break;
			} else {
				sum += p[i] - p[i - 1] - 1;
				++i;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}