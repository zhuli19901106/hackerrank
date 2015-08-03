#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int i, j;
    vector<vector<int> > dp(2, vector<int>(n2 + 1, 0));
    
    int f, nf;
    
    f = 0;
    nf = !f;
    for (i = 0; i < n1; ++i) {
        dp[f][0] = 0;
        for (j = 0; j < n2; ++j) {
            if (s1[i] == s2[j]) {
                dp[f][j + 1] = dp[nf][j] + 1;
            } else {
                dp[f][j + 1] = max(dp[f][j], dp[nf][j + 1]);
            }
        }
        f = !f;
        nf = !f;
    }
    return dp[nf][n2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2) << endl;
    
    return 0;
}