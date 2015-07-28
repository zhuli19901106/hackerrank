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

void in(node *root, vector<int> &v)
{
    if (root == NULL) {
        return;
    }
    in(root->left, v);
    v.push_back(root->data);
    in(root->right, v);
}

void Inorder(node *root)
{
    vector<int> v;
    in(root, v);
    
    int i;
    int n = v.size();
    for (i = 0; i < n; ++i) {
        printf((i ? " %d" : "%d"), v[i]);
    }
    printf("\n");
}