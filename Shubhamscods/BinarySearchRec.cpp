#include<iostream>
using namespace std;

int recursive(int arr[], int lower, int upper, int search)
{
	if(lower <= upper)
	{
		int mid = (lower + upper)/2;
		if(arr[mid] == search)
	 	{
			cout<<"Search Found..";
			return 1;
		}
		else if(arr[mid] < search)
		{
			lower++;
			recursive(arr, lower, upper, search);
		}
		else if(arr[mid] > search)
		{
			upper--;
			recursive(arr, lower, upper, search);
		}
	}
}

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int search;
	cin>>search;
	recursive(arr, 0, 9, search);
}
