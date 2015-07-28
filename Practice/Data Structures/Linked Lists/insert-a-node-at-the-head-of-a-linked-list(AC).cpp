/*
	Insert Node at the begining of a linked list
	Initially head pointer argument could be NULL for empty list
	Node is defined as 
	struct Node
	{
		 int data;
		 struct Node *next;
	}
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
	Node *p1 = new Node();
	p1->data = data;
	p1->next = NULL;
	
	if (head == NULL) {
		return p1;		
	} else {
		p1->next = head;
		return p1;
	}
}
