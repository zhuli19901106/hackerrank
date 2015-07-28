/*
	Delete Node at a given position in a linked list 
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
Node* Delete(Node *head, int position)
{
	if (head == NULL) {
		return NULL;
	}
	
	Node *p1;
	
	if (position == 0) {
		p1 = head->next;
		delete head;
		return p1;
	}
	
	int i;
	Node *p2 = head;
	for (i = 1; i < position; ++i) {
		p2 = p2->next;
	}
	p1 = p2->next;
	p2->next = p1->next;
	delete p1;
	return head;
}
