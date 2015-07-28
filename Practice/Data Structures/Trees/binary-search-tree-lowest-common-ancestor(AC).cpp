/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
node *lca(node *root, int v1,int v2)
{
    if (root == NULL) {
        return NULL;
    }
    if (v1 > v2) {
        return lca(root, v2, v1);
    }
    while (root != NULL) {
        if (root->data >= v1 && root->data <= v2) {
            return root;
        }
        if (root->data < v1) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return root;
}