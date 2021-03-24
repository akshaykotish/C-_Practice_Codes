
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Datas{
	int i;
	int j;
	int gcd;
};


void Rounds(int *R, int r){
	int sum = 0;
	for(int i=0; i<r; i++)
	{
		sum = sum + ((i+1) * R[r-i-1]);
	}
	cout<<sum;
}


void Running(int *A, int N)
{
	vector<Datas> d;

	int i =0, j=1;
	while(i < N*2 && j<N*2)
	{
		Datas datas;
			int gcd = __gcd(A[i], A[j]);
			datas.i = i;
			datas.j = j;
			datas.gcd = gcd;
		d.push_back(datas);
		
		if(j==(N*2)-1 && i<N*2)
		{
			
			i++;
			j = i;
		}
		j++;
	}

	int l = d.size();
	int R[N];
	int r = 0;
	int biggest = 0;
	int p = 0;
	int a = 0, b = 0;
	for(int x=0; x<l; x++)
	{
		biggest = 0;
		a = -1;
		b=-1;
		for(int y=0; y<l; y++)
		{
			if(d[y].gcd > biggest && A[d[y].i] != 0 && A[d[y].j] != 0)
			{
				biggest = d[y].gcd;
				a = d[y].i;
				b = d[y].j;
			}
		}
		if(biggest != 0)
		{
			R[r] = biggest;
			A[a] = 0;
			A[b] = 0;
			//cout<<R[r]<<endl;
			r++;
		}
	}
	Rounds(R,r);

}

int main() {
	int N;
	cin>>N;
	int *A = new int[N*2];
	for(int i=0; i<N*2; i++)
	{
		cin>>A[i];
	}
	//Display(A, N*2);
	//Magic(A,N);
	Running(A, N);
}
