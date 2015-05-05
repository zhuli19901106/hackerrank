/*
	Insert Node at the end of a linked list 
	head pointer input could be NULL as well for empty list
	Node is defined as 
	struct Node
	{
		 int data;
		 struct Node *next;
	}
*/
Node* Insert(Node *head,int data)
{
	Node *p1 = new Node();
	p1->data = data;
	p1->next = NULL;
	
	if (head == NULL) {
		return p1;
	}
	
	Node *p2 = head;
	while (p2->next != NULL) {
		p2 = p2->next;
	}
	p2->next = p1;
	
	return head;
}
