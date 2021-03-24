#include<iostream>
using namespace std;
	
struct Node{
	int id;
	int value;
	Node *link;
};

int index = 0;
int N = 0;
int *arr_x = new int[N];
int *arr_y = new int[N];
Node *Home = new Node();
Node *to_Point = Home;

int* Copy(int arr[])
{
	int *temp = new int[N];
	for(int i=0; i<N; i++)
	{
		temp[i] = arr[i];
	}
	return temp;
}

void Create_Index_Memory()
{
	int *temp_x = Copy(arr_x);
	int *temp_y = Copy(arr_y);
	delete[] arr_x; 
	delete[] arr_y; 
	N++;
	arr_x = new int[N];
	arr_y = new int[N];
	arr_x = Copy(temp_x);
	arr_y = Copy(temp_y);
	delete[] temp_x; 
	delete[] temp_y; 
}

Node* Add(Node *root, int id, int value)
{
	Node *temp = new Node();
	temp->id = id;
	temp->value = value;
	root->link = temp;
	return temp;
}

void Create_Node()
{
	index++;
	cout<<"Enter the value for the node :- ";
	int e;
	cin>>e;
	to_Point = Add(to_Point, index, e);
	Linking();
}

void Linking()
{
	int f=1; 
	while(f!= 0)
	{
		Create_Index_Memory();
		int e;
		cout<<"Enter Node to Link with :- ";
		cin>>e;
		arr_x[N-1] = index;
		arr_y[N-1] = e;
	}
}

void Display(Node *root)
{
	root = root->link;
	while(root != NULL)
	
	{
		cout<<"Node Id is "<<root->id<<" Node Value is "<<root->value<<" And the links are ";
		for(int i=0; i<N; i++)
		{
			if(root->id == arr_x[i])
			{
				cout<<" -> "<<arr_y[i];
			}
		}
		cout<<endl;
		
		root = root->link;
	}
}

int main()
{
	for(int i=0; i<3; i++)
	{
		Create_Node();
	}
	Display(Home);
}
