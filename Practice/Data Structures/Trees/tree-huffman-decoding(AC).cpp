#include <cstdio>
#include <string>
using namespace std;
/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/
void decode_huff(node *root,string s)
{
    string ans = "";
    node *p = root;
    int n = s.length();
    int i;
    for (i = 0; i < n; ++i) {
        p = s[i] == '0' ? p->left : p->right;
        if (p->left == NULL && p->right == NULL) {
            ans.push_back(p->data);
            p = root;
        }
    }
    printf("%s\n", ans.data());
}