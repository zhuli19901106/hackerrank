#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long int LL;
typedef struct Order {
    int tt;
    int ll;
    
    bool operator < (const Order &o) const {
        if (tt != o.tt) {
            return tt < o.tt;
        }
        return ll < o.ll;
    }
} Order;

struct CmpFunctor {
    // SJF Algorithm
    bool operator () (const Order &o1, const Order &o2) const {
        if (o1.ll != o2.ll) {
            return o1.ll > o2.ll;
        }
        return o1.tt > o2.tt;
    }
};

int main()
{
    vector<Order> v;
    priority_queue<Order, vector<Order>, CmpFunctor> pq;
    int n;
    int i;
    
    scanf("%d", &n);
    v.resize(n);
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &v[i].tt, &v[i].ll);
    }
    sort(v.begin(), v.end());
    LL t = 0;
    LL ans = 0;
    
    i = 0;
    while (i < n || !pq.empty()) {
        if (pq.empty()) {
            t = v[i].tt;
            pq.push(v[i++]);
        }
        t += pq.top().ll;
        ans += t - pq.top().tt;
        pq.pop();
        while (i < n && v[i].tt <= t) {
            pq.push(v[i++]);
        }
    }
    printf("%lld\n", ans / n);
    
    return 0;
}