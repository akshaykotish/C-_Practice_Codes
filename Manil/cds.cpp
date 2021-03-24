#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	cin>>N;
	
	string str[N];
	for(int i=0; i<N; i++)
	{
		cin>>str[i];
	}
	
	int Q;
	cin>>Q;
	string qur[Q];
	
	for(int i=0; i<Q; i++)
	{
		cin>>qur[i];
		
	}
	
	for(int i=0; i<Q; i++)
	{
		int v1 = 0;
		int v2 = 0;
		int f3 = 0;
		for(int j = 0; j<qur[i].length(); j++)
		{
			if(qur[i][j] == '-')
			{
				f3++;
			}
			else{
					if(f3 == 0)
					{
						int t_c = ((int)(qur[i][j]) - 48);
						v1 = (v1 * 10) + t_c;
					}
					else{
						int t_c = ((int)(qur[i][j]) - 48);
						v2 = (v2 * 10) + t_c;
					}
			}
			
		
		}
		
		v1 = v1 -1;
		v2 = v2 - 1;
		int op = 0;
		for(int m = v1; m<=v2; m++)
		{
			int f1 = 0;
			for(int j=0; j<str[m].length(); j++)
			{
				if(j == 0 || j==str[m].length()-1)
				{
					int c = str[m][j];
					if(c == 97 || c == 101 || c == 105 || c == 111 || c == 117)
					{
						f1++;
					
						if(str[m].length() == 1)
						{
							f1++;
						}
					}	
					
				}
				
			
			}
			if(f1 >1)
			{
				op++;
			}
		}
		cout<<""<<op<<endl;
	}
	
}
