#include <bits/stdc++.h> 
  
using namespace std; 
  
// Function to generate largest possible 
// number with given digits 
int findMaxNum(int arr[], int n) 
{    
    // sort the given array in 
    // descending order 
    sort(arr, arr+n, greater<int>()); 
      
    int num = arr[0]; 
      
    // generate the number 
    for(int i=1; i<n; i++) 
    { 
        num = num*10 + arr[i]; 
    } 
      
    return num; 
} 
  
// Driver code 
int main()  
{ 
    int arr[] = {786, 75, 79, 33, 76, 8, 69, 6, 67}; 
      
    int n = sizeof(arr)/sizeof(arr[0]); 
      
    cout<<findMaxNum(arr,n); 
      
    return 0; 
} 
