#include<iostream>
using namespace std;

int one(int arr[], int i)
{
	if(i<9)
	{
		cout<<arr[i]<<endl;
		i++;
		one(arr, i);
	}
}

int main()
{
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	one(arr, 0);
}

