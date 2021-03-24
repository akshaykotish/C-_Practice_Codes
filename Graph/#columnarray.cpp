#include<iostream>
using namespace std;
int main()
{
	
	int Number_of_Linked_list_boxes = 8;
	int N = 100;
	cout<<"Numbers of records :- ";
	cin>>N;
	
	
	int arr_x[N];
	int arr_y[N];
	
	int index = 0;
	int id = 1;
	
	for(int i=1; i<=Number_of_Linked_list_boxes; i++)
	{
		int e = 0;
		while(e != 1)
		{
			cout<<"Enter 1) To Add Link \n0) Exit\n";
			int f;
			cin>>f;
			switch(f)
			{
				int k;
				case 1:
					cout<<"Enter Value To Link with (Y) From (X="<<i<<") :- ";
					cin>>k;
					arr_x[index] = i; 
					arr_y[index] = k;
					index++;
					break;
				case 0:
					e = 1;
					break;
			}
		}
	}

	for(int i=1; i<=Number_of_Linked_list_boxes; i++)
	{
		for(int j=0; j<index; j++)
		{
			cout<<"ID:- "<<(j+1)<<" X:- "<<arr_x[j]<<" Y:- "<<arr_y[j]<<endl;
		}
	}	
}
