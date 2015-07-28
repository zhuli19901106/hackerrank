#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct TreeNode {
    TreeNode(int val = 0) {
        this->val = val;
        this->left = this->right = NULL;
    }
    int val;
    struct TreeNode *left, *right;
} TreeNode;

void in(TreeNode *root, vector<int> &v)
{
    if (root == NULL) {
        return;
    }
    in(root->left, v);
    v.push_back(root->val);
    in(root->right, v);
}

void inorder(TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    vector<int> v;
    in(root, v);
    int n = v.size();
    int i;
    for (i = 0; i < n; ++i) {
        printf((i ? " %d" : "%d"), v[i]);
    }
    printf("\n");
}

void swapNode(TreeNode *root, int d, int k)
{
    if (root == NULL) {
        return;
    }
    if (d % k == 0) {
        swap(root->left, root->right);
    }
    swapNode(root->left, d + 1, k);
    swapNode(root->right, d + 1, k);
}

int main()
{
    int n;
    int i;
    scanf("%d", &n);
    vector<TreeNode *> v;
    for (i = 0; i < n; ++i) {
        v.push_back(new TreeNode(i + 1));
    }
    int ll, rr;
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &ll, &rr);
        if (ll != -1) {
            v[i]->left = v[ll - 1];
        }
        if (rr != -1) {
            v[i]->right = v[rr - 1];
        }
    }
    
    scanf("%d", &n);
    int k;
    for (i = 0; i < n; ++i) {
        scanf("%d", &k);
        swapNode(v[0], 1, k);
        inorder(v[0]);
    }
    
    return 0;
}