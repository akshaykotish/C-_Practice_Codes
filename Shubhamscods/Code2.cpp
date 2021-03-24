#include<iostream>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
	
	int i=0;
	int count = 0;
	int c, d;
	while(i < n-1)
	{
		int j=i+1;
		while(j < n)
		{
			int a = arr[i];
			int b = arr[j];
			
				if(a + k == b && (a != c || b != d))
				{
					count++;
					c = a;
					d = b;
				}
				j++;
		}
		
	
		i++;
	}
		cout<<count;
	
}
