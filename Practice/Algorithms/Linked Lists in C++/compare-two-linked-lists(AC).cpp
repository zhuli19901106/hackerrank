/*
	Compare two linked lists A and B
	Return 1 if they are identical and 0 if they are not. 
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
int CompareLists(Node *headA, Node* headB)
{
	Node *pa = headA;
	Node *pb = headB;
	
	while (pa != NULL && pb != NULL) {
		if (pa->data != pb->data) {
			return 0;
		}
		pa = pa->next;
		pb = pb->next;
	}
	return pa == NULL && pb == NULL;
}