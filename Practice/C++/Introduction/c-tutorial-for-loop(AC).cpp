#include <cstdio>
using namespace std;

char s[][10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
int a, b;

int main()
{
	int n;
	scanf("%d%d", &a, &b);
	for (n = a; n <= b; ++n) {
		if (n >= 1 && n <= 9) {
			printf("%s\n", s[n]);
		} else if (n & 1) {
			printf("odd\n");
		} else {
			printf("even\n");
		}
	}
	
	return 0;
}