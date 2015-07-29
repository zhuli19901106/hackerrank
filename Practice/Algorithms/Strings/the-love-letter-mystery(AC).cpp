#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10005;
char s[N];

int count(char s[])
{
	int i, j;
	int ans;
	
	i = 0;
	j = strlen(s) - 1;
	ans = 0;
	
	while (i < j) {
		if (s[i] < s[j]) {
			ans += s[j] - s[i];
		} else {
			ans += s[i] - s[j];
		}
		++i;
		--j;
	}
	
	return ans;
}

int main()
{
	int t, ti;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%s", s);
		printf("%d\n", count(s));
	}

	return 0;
}