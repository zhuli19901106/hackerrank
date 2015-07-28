#include <queue>
#include <vector>
using namespace std;
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    if (root == NULL) {
        return;
    }
    queue<node *> q;
    vector<int> v;
    node *p;
    
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        v.push_back(p->data);
        if (p->left != NULL) {
            q.push(p->left);
        }
        if (p->right != NULL) {
            q.push(p->right);
        }
    }
    
    int n = v.size();
    int i;
    for (i = 0; i < n; ++i) {
        printf((i ? " %d" : "%d"), v[i]);
    }
}