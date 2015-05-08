/*
10 9
2 1
3 1
4 3
5 2
6 1
7 2
8 6
9 8
10 8
*/
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

const int N = 105;
int n, m;
set<int> a[N];
vector<pair<int, int> > v;
int cc;
int b[N];
int ans;

void countNode(int x)
{
	b[x] = 1;
	++cc;

	set<int>::iterator it;
	int y;
	for (it = a[x].begin(); it != a[x].end(); ++it) {
		y = *it;
		if (b[y]) {
			continue;
		}
		countNode(y);
	}
}

void canRemove(int x, int y)
{
	a[x].erase(y);
	a[y].erase(x);

	cc = 0;
	memset(b, 0, sizeof(b));
	countNode(x);

	if (cc % 2) {
		a[x].insert(y);
		a[y].insert(x);
	} else {
		++ans;
	}
}

int main()
{
	int x, y;
	int i;
	
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		a[x].insert(y);
		a[y].insert(x);
		v.push_back(make_pair(x, y));
	}

	ans = 0;
	for (i = 0; i < m; ++i) {
		canRemove(v[i].first, v[i].second);
	}
	printf("%d\n", ans);
	
	for (i = 1; i <= n; ++i) {
		a[i].clear();
	}
	v.clear();
	
	return 0;
}