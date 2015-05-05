/*
	Print elements of a linked list in reverse order as standard output
	head pointer could be NULL as well for empty list
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
void ReversePrint(Node *head)
{
	if (head == NULL) {
		return;
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
	
	p1 = p2;
	while (p1 != NULL) {
		printf("%d\n", p1->data);
		p1 = p1->next;
	}
}
