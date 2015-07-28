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

void post(node *root, vector<int> &v)
{
    if (root == NULL) {
        return;
    }
    post(root->left, v);
    post(root->right, v);
    v.push_back(root->data);
}

void Postorder(node *root)
{
    vector<int> v;
    post(root, v);
    
    int i;
    int n = v.size();
    for (i = 0; i < n; ++i) {
        printf((i ? " %d" : "%d"), v[i]);
    }
    printf("\n");
}