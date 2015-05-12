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
int n;

int main()
{
	scanf("%d", &n);
	if (n >= 1 && n <= 9) {
		printf("%s\n", s[n]);
	} else {
		printf("Greater than 9\n");
	}
	
	return 0;
}