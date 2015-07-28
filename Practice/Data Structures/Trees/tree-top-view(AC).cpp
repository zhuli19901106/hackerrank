#include <algorithm>
#include <vector>
using namespace std;
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root)
{
    if (root == NULL) {
        return;
    }
    vector<int> v;
    node *p = root;
    while (p->left != NULL) {
        p = p->left;
        v.push_back(p->data);
    }
    reverse(v.begin(), v.end());
    p = root;
    while (p != NULL) {
        v.push_back(p->data);
        p = p->right;
    }
    
    int n = v.size();
    int i;
    for (i = 0; i < n; ++i) {
        printf((i ? " %d" : "%d"), v[i]);
    }
    printf("\n");
}