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
	Node *prev;
};
/***************************Head Node creation*********************************/
Node *head = NULL;
/**************************Create new node*************************************/
Node* createnew_Node(int value)
{
	struct Node* temp = new Node();
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
/********************************printListForward******************************/
void printListForward()
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

/*******************************printListReverse ******************************/
void printListReverse()
{
	struct Node* temp = head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}

	cout << "tail->";
	if(temp == NULL)
	{
		cout << "NULL";
	}
	else
	{
		while(temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->prev;
		}
		cout<< "NULL";
	}
	cout << endl;
}
/*************************Insert nodes at the beginning************************/
void insertAtBeginning(int value)
{
	struct Node* temp = createnew_Node(value);
	temp->next = head;
	head->prev = temp;
	head = temp;


}
/************************insertAtSpecificPosition******************************/
void insertAtPosition(int value, int pos)
{
	struct Node* temp = head;
	struct Node* local = NULL;
	if(head == NULL)
	{
		insertAtBeginning(value);
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
		local->prev = temp;
		(temp->next)->prev = local;
		temp->next = local;
	}
}
/****************************Insert a node at the end**************************/
void insertAtEnd(int value)
{
	struct Node* iterate = head;
	struct Node* temp =NULL;
	temp = createnew_Node(value);
	if(iterate != NULL)
	{
		while(iterate->next != NULL)
		{
			iterate = iterate->next;
		}
		iterate->next = temp;
		temp->prev = iterate;
	}
	else
	{
		head = temp;
	}
}
/*****************************deleteAtBeginning********************************/
void deleteAtBeginning()
{
	struct Node* temp = head;
	if(head != NULL)
	{
		head = head->next;
	}
	temp->next = NULL;
	head->prev = NULL;
	delete temp;
}
/*********************************deleteAtEnd**********************************/
void deleteAtEnd()
{
	struct Node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	(temp->prev)->next = NULL;
	temp->prev = NULL;
	delete temp;
}
/*********************************deleteAtEnd**********************************/
void deleteAtPosition(int pos)
{
	struct Node* temp = head;

	for(int i=0; (i<(pos-1) && (temp!= NULL)); i++)
	{
		temp = temp->next;
	}
	if(temp->prev != NULL)
	{
		(temp->prev)->next = temp->next;
	}
	if(temp->next != NULL)
	{
		(temp->next)->prev = temp->prev;
		head =  temp->next;
	}

	temp->next = NULL;
	temp->prev = NULL;
}

int main()
{
	// Demonstrating various operations on the doubly linked
	// list.
	// Insertion at End
	insertAtEnd( 10);
	insertAtEnd( 20);
	// Insertion at beginning
	insertAtBeginning( 5);
	// Insertion at specific position
	insertAtPosition( 15, 2);

	// print the list
	cout << "After Insertions:" << endl;
	printListForward();
	printListReverse();

	// deletion from beginning
	deleteAtBeginning();
	cout << "After Deletions:" << endl;
	printListForward();
	printListReverse();
	// deletion from end
	deleteAtEnd();
	cout << "After Deletions:" << endl;
	printListForward();
	printListReverse();
	// deletion from specific position
	deleteAtPosition( 1);

	cout << "After Deletions:" << endl;
	printListForward();
	printListReverse();


	return 0;
}