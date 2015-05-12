#include <cstdio>
using namespace std;

int main()
{
	int i;
	long l;
	long long int ll;
	char s[10];
	float f;
	double d;
	
	scanf("%d%ld%lld%s%f%lf", &i, &l, &ll, s, &f, &d);
	printf("%d\n%ld\n%lld\n%s\n%f\n%f\n", i, l, ll, s, f, d);
	
	return 0;
}
