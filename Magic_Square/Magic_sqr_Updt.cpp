#include<iostream>

using namespace std;

void Display()
{
	for(int i=1; i<10; i++)
	{
		for(int j=1; j<10; j++)
		{
			for(int k=1; k<10; k++)
			{
				if(i + j + k == 15 && i!=j && j!= k && i!=k)
				{
					cout<<i<<" + "<<j<<" + "<<k<<" = 15"<<endl;
				}
			}
		}
	}
}

int main()
{
	Display();
}
