/*
	Get Nth element from the end in a linked list of integers
	Number of elements in the list will always be greater than N.
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
int GetNode(Node *head,int positionFromTail)
{
	++positionFromTail;
	Node *p1, *p2;
	int i;
	
	p1 = head;
	for (i = 0; i < positionFromTail; ++i) {
		p1 = p1->next;
	}
	p2 = head;
	while (p1 != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	
	return p2->data;
}