#include<iostream>
using namespace std;

struct node{
	int value;
	node *left;
	node *right;
};

void Add_Node(int value, node *branch, int direction)
{
	node *temp = new node();
	temp->value = value;
	if(direction == 1)
	{
		branch->right = temp;
	}
	else{
		branch->left = temp;
	}
}


void Display(node *root)
{
	cout<<root->value<<endl;
	if(root->left != NULL)
	{
		Display(root->left);
	}	
	if(root->right != NULL)
	{
		Display(root->right);
	}
}

node* Add_After(node *root, int search)
{
	cout<<root->value<<endl;
	if(root->value == search)
	{
		return root;
	}
	if(root->left != NULL)
	{
		root  = Add_After(root->left, search);
	}	
	if(root->right != NULL)
	{
		root = Add_After(root->right, search);
	}
	return root;
}

void Create_Tree()
{
	node *root = new node();
	root->value = 0;
	int e = 1;
	while(e == 1)
	{
		int f;
		cout<<"Your Inputs\n0) Exit\n1) Add New Node";
		cin>>f;
		switch(f)
		{
			case 0:
				e = 0;
				break;
			case 1:
				int a, b, c;
				cout<<"Value to be added :- ";
				cin>>a;
				cout<<"New Node after :- ";
				cin>>b;
				cout<<"Left(0) or Right(1) :- ";
				cin>>c;
				Add_Node(a, Add_After(root, b), c);
				break;
		}
	}
	Display(root);
}

int main()
{
	/*
	cout<<"Binary Tree\n";
	node *ND = new node();
	node *RK = new node();
	node *MK = new node();
	node *RJ = new node();
	node *PJ = new node();
	node *AK = new node();
	node *LK = new node();
	ND->value = 1;
	RK->value = 2;
	MK->value = 3;
	RJ->value = 4;
	PJ->value = 5;
	AK->value = 6;
	LK->value = 7;
	ND->left = RK;
	ND->right = MK;
	RK->left = RJ;
	RK->right = PJ;
	MK->left = AK;
	MK->right = LK;
	*/
	Create_Tree();
	//Display(ND);
	
}
