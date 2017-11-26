#include<iostream>
#include<vector>
#include<map>

using namespace std;

int **g;

template <typename T>
void printMatrix(T **arr,int *x, int *y, int m, int n)
{
	cout<<"i\\j  ";
	for(int j=0; j<n; j++)
	    cout<<y[j]<<" ";
	cout<<endl;
	for(int i=0; i<m; i++){
	    cout<<" "<<x[i]<<"   ";
	    for(int j=0; j<n; j++){
	    	cout<<arr[i][j]<<" ";
            }
	    cout<<endl;
	}	
}

//solution with time complex O(n3)
int fillAndCalc(int *a, int m)
{
	int account = 0;
	//fill array g[m][m]
	for(int i=0; i<m; i++)
	{
	    for(int j=0; j<m; j++)
	    {
		g[i][j]=0;
		for(int k=0; k<j; k++)
		{
	            if(a[i]-a[j]==a[j]-a[k]){
			g[i][j]=g[j][k]+1;
		    }
		}

		//calculate arithmetic subsequence account of sequence of length m
	        account += g[i][j];
	    }
	}
	
	printMatrix(g, a, a, m, m);

	return account;
}

int main()
{
	int input[5]={2,4,6,8,10};
	int n=5;

	g=new int *[n];
	for(int i=0; i<n; i++)
	{
		g[i]=new int[n];
	}	
	int c=fillAndCalc(input, n);
	cout<<"Arithmetic subsequence account of sequence is "<<c<<endl;

        for(int i=0; i<n; i++)
	{
		delete [] g[i];
	}
	delete [] g;
}
