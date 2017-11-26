#include<iostream>

using namespace std;

// d[i] indicate length of the longest increasing subsequence ending with a[i] of sequence(a[0] ~ a[i])
int *d;

int lisLength(int *a, int m)
{
	for(int i=0; i<m; i++)
	    cout<<a[i]<<" ";
	cout<<endl;

	int len = 1;
	for(int i=0; i<m; i++)
	{
	    d[i] = 1;
	    for(int j=0; j<i; j++)
	    {
		if(a[j]<=a[i] && (d[j]+1)>d[i])
		    d[i] = d[j]+1;
	    }
	    if(d[i]>len) len =d[i];
	}
	
	for(int i=0; i<m; i++)
	    cout<<d[i]<<" ";
	cout<<endl;

	return len;
}

int main()
{
	int input[6] = {5, 3, 4, 8, 6, 7};
	int m = 6;
	
	d = new int[m];
	int length = lisLength(input, m);

	cout<<"The longest increading subsequence length of input is "<< length << endl;
}
