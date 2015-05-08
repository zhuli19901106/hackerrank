/*
	Insert Node in a doubly sorted linked list 
	After each insertion, the list should be sorted
	Node is defined as
	struct Node
	{
		int data;
		Node *next;
		Node *prev
	}
*/
Node* SortedInsert(Node *head,int data)
{
	Node *p1 = new Node();
	p1->data = data;
	p1->prev = NULL;
	p1->next = NULL;
	
	if (head == NULL) {
		head = p1;
		return head;
	}
	
	if (data <= head->data) {
		p1->next = head;
		head->prev = p1;
		return p1;
	}
	
	Node *p2 = head;
	while (p2->next != NULL && p2->next->data < data) {
		p2 = p2->next;
	}
	Node *p3 = p2->next;
	p2->next = p1;
	p1->prev = p2;
	p1->next = p3;
	if (p3 != NULL) {
		p3->prev = p1;
	}
	
	return head;
}