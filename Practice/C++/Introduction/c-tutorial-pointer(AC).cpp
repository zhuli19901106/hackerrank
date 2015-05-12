#include <cstdio>
using namespace std;

int myabs(int x)
{
	return x >= 0 ? x : -x;
}

void update(int *a,int *b)
{
	*a += *b;
	*b = myabs(*a - 2 * *b);
}

int main()
{
	int a, b;
	int *pa = &a, *pb = &b;
	
	scanf("%d%d", &a, &b);
	update(pa, pb);
	printf("%d\n%d\n", a, b);
	
	return 0;
}
