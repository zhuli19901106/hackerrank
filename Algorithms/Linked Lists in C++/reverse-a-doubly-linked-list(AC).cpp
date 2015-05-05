/*
	Reverse a doubly linked list, input list may also be empty
	Node is defined as
	struct Node
	{
		int data;
		Node *next;
		Node *prev;
	}
*/
Node* Reverse(Node* head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	
	Node *p1 = head;
	Node *p2 = p1->next;
	p1->next = NULL;
	p2->prev = NULL;
	Node *p3;
	while (p2 != NULL) {
		p3 = p2->next;
		p2->next = p1;
		p1->prev = p2;
		if (p3 != NULL) {
			p3->prev = NULL;
		}
		p1 = p2;
		p2 = p3;
	}
	return p1;
}