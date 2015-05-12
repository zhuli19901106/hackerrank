#include <algorithm>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
	int ans = max(a, b);
	ans = max(ans, c);
	ans = max(ans, d);
	
	return ans;
}

int main()
{
	int a, b, c, d;
	
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d\n", ans);
	
	return 0;
}