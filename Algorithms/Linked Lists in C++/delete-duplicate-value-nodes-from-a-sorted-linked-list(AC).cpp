/*
	Remove all duplicate elements from a sorted linked list
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
Node* RemoveDuplicates(Node *head)
{
	if (head == NULL) {
		return NULL;
	}
	
	Node *p1, *p2;
	
	p1 = head;
	while (p1->next != NULL) {
		p2 = p1->next;
		if (p1->data == p2->data) {
			p1->next = p2->next;
			delete p2;
		} else {
			p1 = p1->next;
		}
	}
	
	return head;
}