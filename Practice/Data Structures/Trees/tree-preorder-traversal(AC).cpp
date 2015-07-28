#include <vector>
using namespace std;
/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void pre(node *root, vector<int> &v)
{
    if (root == NULL) {
        return;
    }
    v.push_back(root->data);
    pre(root->left, v);
    pre(root->right, v);
}

void Preorder(node *root)
{
    vector<int> v;
    pre(root, v);
    
    int i;
    int n = v.size();
    for (i = 0; i < n; ++i) {
        printf((i ? " %d" : "%d"), v[i]);
    }
}