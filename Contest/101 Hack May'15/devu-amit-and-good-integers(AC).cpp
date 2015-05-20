//https://www.hackerrank.com/contests/101hack25/challenges/devu-amit-and-good-integers
// What an embarrassment, only one solved.
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long int LL;
const int N = 100005;
LL a[N];
LL ll, rr;
int n;
vector<LL> ans;

void solve()
{
	int lp, rp;
	
	lp = 0;
	while (a[lp] < ll) {
		++lp;
	}
	--lp;
	rp = n - 1;
	while (a[rp] > rr) {
		--rp;
	}
	++rp;
	
	int i;
	for (i = 0; i < rp - lp - 1; ++i) {
		ans.push_back(0);
	}
	
	LL cl, cr;
	LL sum = 0;
	while (lp >= 0 && rp <= n - 1) {
		cl = ll - a[lp];
		cr = a[rp] - rr;
		if (cl < cr) {
			--lp;
			sum += cl;
		} else {
			++rp;
			sum += cr;
		}
		ans.push_back(sum);
	}
	while (lp >= 0) {
		cl = ll - a[lp];
		--lp;
		sum += cl;
		ans.push_back(sum);
	}
	while (rp <= n - 1) {
		cr = a[rp] - rr;
		++rp;
		sum += cr;
		ans.push_back(sum);
	}
	reverse(ans.begin(), ans.end());
}

int main()
{
	int t, ti;
	LL sum;
	int i;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%lld%lld", &n, &ll, &rr);
		for (i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
		}
		sort(a, a + n);
		
		if (a[0] > rr) {
			sum = 0;
			for (i = 0; i < n; ++i) {
				sum += a[i] - rr;
			}
			for (i = n - 1; i >= 0; --i) {
				printf((i == n - 1 ? "%lld" : " %lld"), sum);
				sum -= a[i] - rr;
			}
			printf("\n");
			continue;
		}

		if (a[n - 1] < ll) {
			sum = 0;
			for (i = 0; i < n; ++i) {
				sum += ll - a[i];
			}
			for (i = 0; i <= n - 1; ++i) {
				printf((i == 0 ? "%lld" : " %lld"), sum);
				sum -= ll - a[i];
			}
			printf("\n");
			continue;
		}
		
		solve();
		for (i = 0; i <= n - 1; ++i) {
			printf((i == 0 ? "%lld" : " %lld"), ans[i]);
		}
		printf("\n");
		ans.clear();
	}
	
	return 0;
}