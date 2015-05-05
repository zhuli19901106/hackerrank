/*
	Merge two sorted lists A and B as one linked list
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
Node* MergeLists(Node *headA, Node* headB)
{
	Node *p1 = headA;
	Node *p2 = headB;
	if (p1 == NULL) {
		return p2;
	} else if (p2 == NULL) {
		return p1;
	}
	
	Node *p3, *head;
	if (p1->data < p2->data) {
		head = p3 = p1;
		p1 = p1->next;
		p3->next = NULL;
	} else {
		head = p3 = p2;
		p2 = p2->next;
		p3->next = NULL;
	}
	
	while (p1 != NULL && p2 != NULL) {
		if (p1->data < p2->data) {
			p3->next = p1;
			p1 = p1->next;
		} else {
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
		p3->next = NULL;
	}
	if (p1 != NULL) {
		p3->next = p1;
	}
	if (p2 != NULL) {
		p3->next = p2;
	}
	
	return head;
}