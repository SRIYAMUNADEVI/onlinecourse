/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
/************************datatype for node*************************************/
struct Node {
	int data;
	Node *next;
};
/***************************Head Node creation*********************************/
Node *head = NULL;
/**************************Create new node*************************************/
Node* createnew_Node(int value)
{
	struct Node* temp = new Node();
	temp->data = value;
	temp->next = NULL;
	return temp;
}
/*****************************display list*************************************/
void display()
{
	struct Node* temp = head;
	cout << "Head->";
	if(temp == NULL)
	{
		cout << "NULL";
	}
	else
	{
		while(temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout<< "NULL";
	}
	cout << endl;
}
/*************************Insert nodes at the beginning************************/
void insert(int value)
{
	struct Node* temp = createnew_Node(value);
	temp->next = head;
	head = temp;
}

void insertAtSpecificPosition(int value, int pos)
{
	struct Node* temp = head;
	struct Node* local = NULL;
	if(head == NULL)
	{
		insert(value);
	}
	else
	{
		while(((pos-1)!=0) && (temp->next!=NULL))
		{
			temp = temp->next;
			pos--;
		}
		local = createnew_Node(value);
		local->next = temp->next;
		temp->next = local;
	}
}
/****************************Insert a node at the end**************************/
void insertAtEnd(int value)
{
	struct Node* iterate = head;
	struct Node* temp =NULL;
	temp = createnew_Node(value);
	while(iterate->next != NULL)
	{
		iterate = iterate->next;
	}
	iterate->next = temp;
}

int main()
{
	// Insert nodes at the beginning
	insert(3);
	cout << "After inserting 3 at the beginning: "<< endl;
	display();

	insert(1);
	cout << "After inserting 1 at the beginning: "<< endl;
	display();

	insert(7);
	cout << "After inserting 7 at the beginning: "<< endl;
	display();

	insert(2);
	cout << "After inserting 2 at the beginning: "<< endl;
	display();

	insert(9);
	cout << "After inserting 9 at the beginning: "<< endl;
	display();

	// Insert a node at a specific position
	insertAtSpecificPosition(5, 2); // Insert 5 at position 2
	cout << "After inserting 5 at position 2: "<< endl;
	display();

	// Insert a node at the end
	insertAtEnd(10);
	cout << "After inserting 10 at the end: "<< endl;
	display();

	return 0;
}
