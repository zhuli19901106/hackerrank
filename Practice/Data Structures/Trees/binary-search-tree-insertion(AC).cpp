/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
node *newnode(int data)
{
    node *p = new node();
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

node *insert(node * root, int value)
{
    node *p;
    if (root == NULL) {
        p = newnode(value);
        return p;
    }
    p = root;
    while (true) {
        if (value < p->data) {
            if (p->left == NULL) {
                p->left = newnode(value);
            }
            p = p->left;
        } else if (value > p->data) {
            if (p->right == NULL) {
                p->right = newnode(value);
            }
            p = p->right;
        } else {
            break;
        }
    }
    return root;
}