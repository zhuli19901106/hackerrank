#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

typedef long long int LL;
class Solution {
public:
    LL largestRectangleArea(vector<int> &height) {
        vector<int> &a = height;
        stack<int> val, pos;
        int n = a.size();
        int i, min_i;
        LL ans = 0;
        
        for (i = 0; i < n; ++i) {
            if (val.empty() || a[i] >= val.top()) {
                val.push(a[i]);
                pos.push(i);
                continue;
            }
            min_i = i;
            while (!val.empty() && val.top() > a[i]) {
                ans = max(ans, 1LL * val.top() * (i - pos.top()));
                min_i = pos.top();
                val.pop();
                pos.pop();
            }
            val.push(a[i]);
            pos.push(min_i);
        }
        while (!val.empty()) {
            ans = max(ans, 1LL * val.top() * (i - pos.top()));
            val.pop();
            pos.pop();
        }
        
        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    vector<int> v;
    
    scanf("%d", &n);
    v.resize(n);
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    printf("%lld\n", sol.largestRectangleArea(v));
    
    return 0;
}