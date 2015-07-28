/*
	Detect loop in a linked list 
	List could be empty also
	Node is defined as 
	struct Node
	{
		int data;
		struct Node *next;
	}
*/
int HasCycle(Node* head)
{
	if (head == NULL || head->next == NULL) {
		return 0;
	}
	Node *p1, *p2;
	
	p1 = p2 = head;
	while (true) {
		p1 = p1->next;
		p2 = p2->next;
		if (p2 == NULL) {
			return 0;
		}
		p2 = p2->next;
		if (p2 == NULL) {
			return 0;
		}
		if (p1 == p2) {
			return 1;
		}
	}
}