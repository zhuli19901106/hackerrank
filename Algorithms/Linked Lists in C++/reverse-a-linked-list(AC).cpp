/*
	Reverse a linked list and return pointer to the head
	The input list will have at least one element	
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
Node* Reverse(Node *head)
{
	if (head == NULL) {
		return NULL;
	}

	Node *p1, *p2, *p3;
	
	p1 = head->next;
	p2 = head;
	p2->next = NULL;
	while (p1 != NULL) {
		p3 = p1;
		p1 = p1->next;
		p3->next = p2;
		p2 = p3;
	}
	return p2;
}