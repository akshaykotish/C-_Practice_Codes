#include<iostream>
using namespace std;

int main()
{
	int i_c[9];
	int j_c[9];
	int k_c[9];
	
	int l = 0;
	for(int i=1; i<=9; i++)
	{
		for(int j=i+1; j<=9; j++)
		{
			for(int k=j+1; k<=9; k++)
			{
				if(i+j+k == 15 && i!=j && j!=k && i!=k)
				{
					cout<<i<<" + "<<j<<" + "<<k<<" = "<<" 15"<<endl;
					i_c[l] = i;
					j_c[l] = j;
					k_c[l] = k;
				}
			}
		}
	}
	
	cout<<"Our machine learnerd forming magic square..";
	
	
	int arr[3][3] = {
		{5, 3, 4},
		{1, 5, 8},
		{6, 4, 2}
	};
	
	int row =0 , col = 0;
			int count=0;
		
					for(int c = 0; c<l; c++)
					{
						if((arr[row][col] == i_c[c] || arr[row][col] == j_c[c] || arr[row][col] == k_c[c]) && 
						arr[row][col+1] == i_c[c] || arr[row][col+1] == j_c[c] || arr[row][col+1] == k_c[c]) && 
						arr[row][col+2] == i_c[c] || arr[row][col+2] == j_c[c] || arr[row][col+2] == k_c[c]))
						{
								
						}		
					}
		}
			 
		}	
	}
	
}


/*
1 2 3
4 5 6
7 8 9
*/





