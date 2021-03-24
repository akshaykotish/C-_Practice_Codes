#include<iostream>
using namespace std;
int main()
{
	int N = 10;
	int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int upper = N-1;
	int lower = 0;
	int srch;
	cin>>srch;
	while(lower <= upper)
	{
		int mid = (upper + lower)/2;
		
		if(arr[mid] == srch)
		{
			cout<<"Match Found"<<endl;
			break;
		}
		else if(arr[mid] > srch)
		{
			upper = mid - 1;
		}
		else if(arr[mid] < srch)
		{
			lower = mid + 1;
		}
		else if(lower == upper)
		{
			cout<<"Not Found";
		}
	}
}
