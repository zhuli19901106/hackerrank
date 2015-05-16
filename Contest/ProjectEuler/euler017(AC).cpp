//https://www.hackerrank.com/contests/projecteuler/challenges/euler017
#include <map>
#include <string>
#include <vector>
using namespace std;

map<int, string> m;
vector<string> words;

void init()
{
	m[0] = "Zero";
	m[1] = "One";
	m[2] = "Two";
	m[3] = "Three";
	m[4] = "Four";
	m[5] = "Five";
	m[6] = "Six";
	m[7] = "Seven";
	m[8] = "Eight";
	m[9] = "Nine";
	m[10] = "Ten";
	m[11] = "Eleven";
	m[12] = "Twelve";
	m[13] = "Thirteen";
	m[14] = "Fourteen";
	m[15] = "Fifteen";
	m[16] = "Sixteen";
	m[17] = "Seventeen";
	m[18] = "Eighteen";
	m[19] = "Nineteen";
	m[20] = "Twenty";
	m[30] = "Thirty";
	m[40] = "Forty";
	m[50] = "Fifty";
	m[60] = "Sixty";
	m[70] = "Seventy";
	m[80] = "Eighty";
	m[90] = "Ninety";
	int i, j;
	for (i = 2; i <= 9; ++i) {
		for (j = 1; j <= 9; ++j) {
			m[i * 10 + j] = m[i * 10] + " " + m[j];
		}
	}
}

void readNumber(long long int n)
{
	if (n == 0) {
		return;
	}
	// here n is limited between [0, 999];
	int a, b, c;
	
	a = n / 100;
	b = n % 100 / 10;
	c = n % 10 / 1;
	
	if (a > 0) {
		words.push_back(m[a]);
		words.push_back("Hundred");
		if (b != 0 || c != 0) {
			//words.push_back("And");
		}
	}
	if (b * 10 + c > 0) {
		words.push_back(m[b * 10 + c]);
	}
}

void printNumber(vector<string> &v)
{
	int n = v.size();
	int i;
	printf("%s", v[0].data());
	for (i = 1; i < n; ++i) {
		printf(" %s", v[i].data());
	}
	printf("\n");
}

int main()
{
	init();
	long long int n, n0;
	
	int t, ti;
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld", &n);
		if (n == 0) {
			printf("Zero\n");
			continue;
		}
		if (n < 0) {
			words.push_back("minus");
			n = -n;
		}
		n0 = n;
		if (n >= 1000000000000ll) {
			readNumber(n / 1000000000000ll);
			words.push_back("Trillion");
			n = n % 1000000000000ll;
		}
		if (n >= 1000000000) {
			readNumber(n / 1000000000);
			words.push_back("Billion");
			n = n % 1000000000;
		}
		if (n >= 1000000) {
			readNumber(n / 1000000);
			n = n % 1000000;
			words.push_back("Million");
		}
		if (n >= 1000) {
			readNumber(n / 1000);
			n = n % 1000;
			words.push_back("Thousand");
		}
		if (n0 >= 1000 && n / 100 == 0) {
			//words.push_back("And");
		}
		readNumber(n);
		printNumber(words);
		words.clear();
	}
	
	return 0;
}