/*
	Find merge point of two linked lists
	Node is defined as
	struct Node
	{
		int data;
		Node* next;
	}
*/

int count(Node *head)
{
	int len = 0;	
	Node *p = head;
	while (p != NULL) {
		++len;
		p = p->next;
	}
	return len;
}

int FindMergeNode(Node *headA, Node *headB)
{
	int len1, len2;
	Node *p1, *p2;
	
	len1 = count(headA);
	len2 = count(headB);
	
	p1 = headA;
	p2 = headB;
	int i;
	if (len1 > len2) {
		for (i = len2; i < len1; ++i) {
			p1 = p1->next;
		}
	} else {
		for (i = len1; i < len2; ++i) {
			p2 = p2->next;
		}
	}
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1->data;
}
