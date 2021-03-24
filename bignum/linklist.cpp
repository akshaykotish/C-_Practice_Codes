#include<iostream>
using namespace std;

struct linkedlist{
	int val;
	linkedlist *next_ll = NULL;
};

linkedlist* insert(linkedlist *root, int value)
{
	linkedlist *temp = new linkedlist();
	temp->val = value;
	root->next_ll = temp;
	return temp;
}

void display(linkedlist *root)
{
	while(root->next_ll != NULL)
	{
		cout<<root->next_ll->val<<" -> ";
		root = root->next_ll;
	}
}

int main()
{
	linkedlist *root1 = new linkedlist();
	linkedlist *root2 = new linkedlist();
	
	linkedlist *node1 = root1;
	linkedlist *node2 = root2;
		
	for(int i=0; i<3; i++)
	{
		node1 = insert(node1, i);
	}	
	for(int i=0; i<6; i++)
	{
		node2 = insert(node2, i);
	}	
	
	for(int i=6; i<10; i++)
	{
		node1 = insert(node1, i);
		node2->next_ll = node1;
		node2 = node2->next_ll;
	}
	
	display(root1);
	cout<<endl;
	display(root2);
}
