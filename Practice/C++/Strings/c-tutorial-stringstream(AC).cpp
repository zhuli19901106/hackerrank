#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
	stringstream ss(str);
	vector<int> v;
	char ch;
	int val;
	
	ss >> val;
	v.push_back(val);
	while (ss >> ch) {
		ss >> val;
		v.push_back(val);
	}
	return v;
}

int main()
{
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for(int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}
	
	return 0;
}
