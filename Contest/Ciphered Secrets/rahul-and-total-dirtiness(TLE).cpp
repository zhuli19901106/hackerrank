#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 50005;
const LL MOD = 1000000007;
LL a[N];
int n;
int q;

int lowBit(int x)
{
    return x & -x;
}

void add(int x, LL val)
{
	// Modify one
    while (x >= 1 && x <= n) {
        a[x] += val;
        x += lowBit(x);
    }
}

LL sum(int x)
{
	// Summate all
    LL res = 0;
    while (x >= 1 && x <= n) {
        res += a[x];
        x -= lowBit(x);
    }
    return res;
}

LL sumInterval(int x, int y)
{
    return sum(y) - sum(x - 1);
}

void getDirty(int x, int y)
{
	int i;
	LL v1, v2;

	for (i = x; i <= y; ++i) {
		v1 = sumInterval(i, i);
		v2 = (v1 & 1 ? 3 * v1 + 1 : v1 >> 1);
		add(i, v2 - v1);
	}
}

void printAll()
{
	int i;

	for (i = 1; i <= n; ++i) {
		printf("%lld ", sumInterval(i, i));
	}
	printf("\n");
}

int main()
{
	LL val;
	int x, y;
	int op;
	int i;

	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (i = 1; i <= n; ++i) {
		scanf("%lld", &val);
		add(i, val);
	}
	scanf("%d", &q);
	for (i = 1; i <= q; ++i) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 0) {
			getDirty(x, y);
		} else {
			printf("%lld\n", sumInterval(x, y) % MOD);
		}
	}

	return 0;
}