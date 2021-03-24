#include <bits/stdc++.h>

using namespace std;


// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> output;
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<a.size();j++)
        {
            cout<<a[j]<<" ";
            if(j==a.size()-1)
            {
                a[0] = a[j];
            }
            else{
                a[j+1] = a[j];
            }
        }
            cout<<endl;
    }

    for(int i=0; i<queries.size(); i++)
    {
        int t = queries[i];
        int v = a[t];
        output.push_back(v);
    }
    return output;
}

int main()
{
	int n, k, q;
	cin>>n;
	cin>>k;
	cin>>q;
	vector<int> a;
	for(int i=0; i<n; i++)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	for(int j=0; j<a.size();j++)
        {
            cout<<"O:- "<<a[j]<<" ";
            if(j==a.size()-1)
            {
                a[0] = a[j];
            }
            else{
                a[j+1] = a[j];
            }
        }
	
	vector<int> queries;
	for(int i=0; i<q; i++)
	{
		int temp;
		cin>>temp;
		queries.push_back(temp);
	}
	
	vector<int> result = circularArrayRotation(a, k, queries);
	
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<<endl;
	}
}

