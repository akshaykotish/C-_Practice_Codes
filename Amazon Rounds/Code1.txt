
#include <iostream>
#include <string.h>

using namespace std;

long long arr[26];
long long distinct[26];

void Clear_Distinct(int i, int N)
{
	if(i < N)
	{
		distinct[i] = 0;
		Clear_Distinct(++i, N);
	}
}

long long Get_All_Distinct(int i, int N)
{
	if(i < N)
	{
		if(distinct[i] == 1)
		{
			return Get_All_Distinct(++i, N) + 1;
		}
		else{
			return Get_All_Distinct(++i, N);
		}
	}
	return 0;
}

void Set_Distinct(long long d){
	for(long long t=1; t<=d; t++)
	{
		if(d >= t)
		{
			arr[t-1]++;
		}
	}
}

void Divide_And_Rule(long long N, string S){

	long long i=0;
	long long j=i;

	string o = "";

	while(i<N && j<N)
	{
		o = o + S[j];
		distinct[(int)S[j] - 97] = 1;
		long long d = Get_All_Distinct(0, 26);
		Set_Distinct(d);
		if(j==N-1)
		{
			i++;
			j = i-1;
			o = "";
			Clear_Distinct(0, 26);
		}
		j++;
	}
}

void Display()
{
	for(long long t=0; t<26; t++)
	{
		cout<<arr[t]<<" ";
	}
}

int main() {
	long long N;
	cin>>N;
	string S;
	cin>>S; 
	Divide_And_Rule(N, S);
	Display();
	return 0;
}
