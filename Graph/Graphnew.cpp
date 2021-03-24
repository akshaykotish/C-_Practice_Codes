#include<iostream>
using namespace std;

struct node{
	int node_id;
	int value;	
};

int N = 5;
int index = 0;
int **arr = new int*[N];

/*
void Dummy_Values()
{
	for(int i=0; i<N; i++)
	{
		arr[i] = i;
	}
}
*/

int* copy(int arr[])
{

	int **temp = new int*[N];
	for(int i=0; i<N; i++)
	{
		temp[i] = new int[2];
		
		temp[i][0] = arr[i][0];
		temp[i][1] = arr[i][1];
	}
	return *temp;
}

void Display(int prnt[])
{
	cout<<"Line :- ";
	for(int i=0; i<N; i++)
	{
		cout<<prnt[i]<<" ";
	}
	cout<<endl;
}

void Increase_Container()
{
	int *temp;
	temp = copy(*arr);
	N++;
	*arr = new int[N];
	*arr = copy(temp);
	Display(*arr);
}

void Add_Connection()
{
	arr[0] = new int[2];
}


int main()
{
	Increase_Container();
}
