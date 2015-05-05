#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 50000;
char b[N + 1];
vector<int> p;

void sieve()
{
	int i, j;
	
	memset(b, 0, sizeof(b));
	b[0] = b[1] = 1;
	for (i = 2; i <= N / i; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; j <= N / i; ++j) {
			b[i * j] = 1;
		}
	}
	
	p.clear();
	for (i = 2; i <= N; ++i) {
		if (b[i]) {
			continue;
		}
		p.push_back(i);
	}
}

int dsum(int n)
{
	int sum = 0;
	
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	
	return sum;
}

bool isSmith(int n)
{
	if (n == 1) {
		return false;
	}
	
	int nsum = dsum(n);
	
	int psum = 0;
	int ds;
	int cc;
	
	int i = 0;
	while (p[i] <= n / p[i]) {
		if (n % p[i]) {
			++i;
			continue;
		}
		ds = dsum(p[i]);
		cc = 0;
		while (n % p[i] == 0) {
			n /= p[i];
			++cc;
		}
		psum += cc * ds;
	}
	if (n > 1) {
		psum += dsum(n);
		n = 1;
	}
	
	return nsum == psum;
}

int main()
{
	sieve();
	
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", isSmith(n) ? 1 : 0);
	}
	
	return 0;
}