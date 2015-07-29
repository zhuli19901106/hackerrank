#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<int> >  small;
    priority_queue<int, vector<int>, greater<int> >  large;
    int n;
    int i;
    int v1, v2;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v1);
        if (small.size() <= large.size()) {
            small.push(v1);
        } else {
            large.push(v1);
        }
        if (!large.empty() && small.top() > large.top()) {
            v1 = small.top();
            small.pop();
            v2 = large.top();
            large.pop();
            small.push(v2);
            large.push(v1);
        }
        if (small.size() == large.size()) {
            printf("%.1f\n", (small.top() + large.top()) / 2.0);
        } else {
            printf("%.1f\n", (double)small.top());
        }
    }
    
    return 0;
}