#include<iostream>
using namespace std;

class abc{
	public:
	static int a;
};

class xyz{
	public:
	static int x;
};

int abc::a = 0;
int xyz::x = 0;

int main()
{
	abc a;
	abc b;
	xyz x;
	xyz y;
	a.a = 10;
	b.a = 20;
	x.x = 30;
	y.x = 40;
	cout<<"a.a = "<<a.a<<endl;
	cout<<"b.a = "<<b.a<<endl;
	cout<<"x.x = "<<x.x<<endl;
	cout<<"y.x = "<<y.x<<endl;
}
