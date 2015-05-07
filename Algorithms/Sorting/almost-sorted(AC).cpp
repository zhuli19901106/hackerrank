#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

bool sorted(vector<int> &v)
{
	int n = v.size();
	int i;
	
	for (i = 1; i < n; ++i) {
		if (v[i] < v[i - 1]) {
			return false;
		}
	}
	return true;
}

bool canSwap(vector<int> &v, int &ll, int &rr)
{
	int i;
	int n = v.size();
	
	ll = rr = -1;
	for (i = 1; i < n; ++i) {
		if (v[i] < v[i - 1]) {
			if (ll == -1) {
				ll = i - 1;
			} else if (rr == -1) {
				rr = i;
			} else {
				return false;
			}
		}
	}
	if (rr == -1) {
		swap(v[ll], v[ll + 1]);
		if (sorted(v)) {
			rr = ll + 1;
			return true;
		} else {
			swap(v[ll], v[ll + 1]);
			return false;
		}
	} else {
		swap(v[ll], v[rr]);
		if (sorted(v)) {
			return true;
		} else {
			swap(v[ll], v[rr]);
			return false;
		}
	}
}

void rev(vector<int> &v, int ll, int rr)
{
	int i = ll;
	int j = rr;
	while (i < j) {
		swap(v[i], v[j]);
		++i;
		--j;
	}
}

bool canReverse(vector<int> &v, int &ll, int &rr)
{
	int i;
	int n = v.size();
	
	ll = rr = -1;
	i = 1;
	while (i < n && v[i] >= v[i - 1]) {
		++i;
	}
	ll = i - 1;
	while (i < n && v[i] <= v[i - 1]) {
		++i;
	}
	rr = i - 1;
	
	rev(v, ll, rr);
	if (sorted(v)) {
		return true;
	} else {
		rev(v, ll, rr);
		return false;
	}
}

int main()
{
	vector<int> v;
	int val;
	int n, i;
	
	scanf("%d", &n);
	v.push_back(-1);
	for (i = 0; i < n; ++i) {
		scanf("%d", &val);
		v.push_back(val);
	}
	v.push_back(1000005);
	
	int ll, rr;
	if (sorted(v)) {
		printf("yes\n");
	} else if (canSwap(v, ll, rr)) {
		printf("yes\nswap %d %d\n", ll, rr);
	} else if (canReverse(v, ll, rr)) {
		printf("yes\nreverse %d %d\n", ll, rr);
	} else {
		printf("no\n");
	}
	v.clear();

	return 0;
}