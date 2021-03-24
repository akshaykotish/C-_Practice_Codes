//Magic Square
/*
1 2 3
4 5 6
7 8 9



*/

#include<iostream>
using namespace std;

void left_to_right(int arr[][3])
{
	
}

void top_to_bottom(int arr[][3])
{
	
}

void right_to_left(int arr[][3])
{
	
}

void bottom_to_top(int arr[][3])
{
	
}

void diagonal(int arr[][3])
{
	
}

void call()
{
	for(int i=1; i<10; i++)
	{
		for(int j=i+1; j<10; j++)
		{
			for(int k=j+1; k<10; k++)
			{	
				if(i+j+k == 15 && i!=j && j!=k && i!=k && j==5)
				{
					cout<<i<<" + "<<j<<" + "<<k<<" = 15"<<endl;	
				}
			}	
		}		
	}
}

int main()
{
	call();
}
