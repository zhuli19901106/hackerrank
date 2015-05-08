#include <cstdio>
using namespace std;

typedef long long int LL;
LL x, y;

LL rangeBitwiseAnd(LL m, LL n) {
	while (n > m) {
		n = (n & n - 1);
	}
	return m & n;
}

int main()
{
	int t, ti;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", rangeBitwiseAnd(x, y));
	}
	
	return 0;
}