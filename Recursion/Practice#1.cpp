#include<iostream>
using namespace std;

int Print_Recurse(int e, int f)
{
	if(e>=0 && f >=0 && f<=e)
	{
		cout<<e<<" "<<f<<endl;
		if(e == f)
		{
			cout<<"Covered"<<endl;
			e--;
			Print_Recurse(e, 0);
		}
		
		f++;
		Print_Recurse(e, f);
	}
}

int main()
{
	Print_Recurse(9, 0);
	return 0;
}
