#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int abhi2(int arr[][3],int ms[][3]) 
{ 
    int count = 0; 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
                if (arr[i][j] != ms[i][j]) 
                {
                	arr[i][j]=ms[i][j];
                	count++;
				} 
            } 
        } 
        return count; 
    } 
int abhi1(int arr[][3]) 
{ 
        int ms[8][3][3] = { { { 8, 1, 6 }, { 3, 5, 7 }, { 4, 9, 2 } }, 
            			{ { 6, 1, 8 }, { 7, 5, 3 }, { 2, 9, 4 } }, 
            			{ { 4, 9, 2 }, { 3, 5, 7 }, { 8, 1, 6 } }, 
            			{ { 2, 9, 4 }, { 7, 5, 3 }, { 6, 1, 8 } }, 
            			{ { 8, 3, 4 }, { 1, 5, 9 }, { 6, 7, 2 } }, 
            			{ { 4, 3, 8 }, { 9, 5, 1 }, { 2, 7, 6 } }, 
            			{ { 6, 7, 2 }, { 1, 5, 9 }, { 8, 3, 4 } }, 
            			{ { 2, 7, 6 }, { 9, 5, 1 }, { 4, 3, 8 } }, 
						}; 
      int min = 9; 
        for (int i = 0; i < 8; i++) { 
            int x = abhi2(arr, ms[i]); 
            if (x < min) 
                min = x; 
        } 
        return min; 
} 

int  main() 
    { 
        int arr[3][3];
        cout<<"Enter 9 elements of your array bcoz its 3*3 matrix"<<endl;
        for(int i=0;i<3;i++)
        {
        	for(int j=0;j<3;j++)
        	{
        		cin>>arr[i][j];
			}
		}
		cout<<"Your array is:"<<endl;
		for(int i=0;i<3;i++)
        {
        	for(int j=0;j<3;j++)
        	{
        		cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"The total number of steps needed to convert=";
        cout<<abhi1	(arr)<<endl;
        cout<<"The new magic square is:"<<endl;
        for(int i=0;i<3;i++)
        {
        	for(int j=0;j<3;j++)
        	{
        		cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
    }
