/*
	Insert Node at a given position in a linked list 
	The linked list will not be empty and position will always be valid
	First element in the linked list is at position 0
	Node is defined as 
	struct Node
	{
		 int data;
		 struct Node *next;
	}
*/
Node* InsertNth(Node *head, int data, int position)
{
	Node *p1 = new Node();
	p1->data = data;
	p1->next = NULL;
	
	if (head == NULL) {
		return p1;
	}
	
	if (position == 0) {
		p1->next = head;
		return p1;
	}
	
	int i;
	Node *p2 = head;
	for (i = 1; i < position; ++i) {
		p2 = p2->next;
	}
	p1->next = p2->next;
	p2->next = p1;
	
	return head;
}
