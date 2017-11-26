#include<iostream>

using namespace std;

// d[n] = d[n-1] + d[n-2],  d[1]=1, d[2]=2, d[3]=3
int climbStairs(int n)
{
  int ret;
  if(n==1) return 1;
  if(n==2) return 2;
  int *arr = new int[n+1];
  arr[1]=1;
  arr[2]=2;

  for(int i=3; i<=n; i++){
    arr[i]=arr[i-1]+arr[i-2];
  }
  ret=arr[n];
  delete []arr;
  return ret;
}

int main()
{
    cout<<"#For n-step stairs, find the solution for walking onto it with 1/2 stairs per step#"<<endl;
    cout<<"N: ";
    int x;
    cin>>x;
    cout<<"Solution: "<<climbStairs(x)<<endl;
    
}
