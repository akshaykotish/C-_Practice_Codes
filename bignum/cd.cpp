#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	int arr[N];
	int dic[N];
	
	int m_10s = 10;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
		int j=10;
		while(arr[i]/j != 0)
		{
			j= j*10;
			if(m_10s < j)
			{
				m_10s = j;
			}
		}
		dic[i] = j;
	}
	
	for(int i=0; i<N-1; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				temp = dic[i];
				dic[i] = dic[j];
				dic[j] = temp;
			}	
		}	
	}
	
	int j = 9;
	
	for(int k=10; k<=m_10s; k=k*10)
	{
		for(int i=0; i<N; i++)
		{
			if(dic[i] == k && arr[i]/(k/10) == j)
			{
				cout<<arr[i];
			}
		}
		if(k==m_10s && j>=0)
		{
			j--;
			k = 1;
		}
	}
	
	
}
