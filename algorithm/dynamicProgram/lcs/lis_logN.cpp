#include<iostream>
#include<cstring>

using namespace std;

// d[i] indicate length of the longest increasing subsequence ending with a[i] of sequence(a[0] ~ a[i])
int *d;

int arrayCpyOnCond(int *des, int *src, int length,  int min, int max);

int maxByQuickSort(int *a, int m);

int lisLength(int *a, int m)
{

	int len = 1;
	int *tmp = new int[m];
	for(int i=0; i<m; i++)
	{
	    d[i] = 1;
	    for(int j=0; j<i; j++)
	    {
	       	//memcpy(tmp, a, j+1); 
	       	int realLen = arrayCpyOnCond(tmp, d, j+1, 0, a[i]) //copy d[i] to tmp[i] when a[j]<a[j]
	        int ldj = maxByQuickSort(tmp, realLen);
		d[i] = ldj+1;
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
