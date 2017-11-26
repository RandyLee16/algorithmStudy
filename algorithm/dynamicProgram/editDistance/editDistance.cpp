#include<iostream>
#include<algorithm>

using namespace std;

int **d;

template <typename T>
void printMatrix(T **arr, char *x, char *y, int m, int n)
{
	cout<<"i\\j O ";
	for(int j=0; j<n; j++)
	    cout<<y[j]<<" ";
	cout<<endl<<" O  ";
	for(int i=0; i<m+1; i++){
	    if(i>0)
	    	cout<<" "<<x[i-1]<<"  ";
	    for(int j=0; j<n+1; j++){
	    	cout<<arr[i][j]<<" ";
            }
	    cout<<endl;
	}	
}

int minOfThree(int a, int b, int c)
{
	int tmp= a<b ? a:b;
	if(c<tmp) tmp=c;
	return tmp;
}

int minDis(char *a, int x, char *b, int y)
{
	for(int i=0; i<=x; i++)
	{
	    for(int j=0; j<=y; j++)
	    {
		if(i==0) d[i][j]=j;
		if(j==0) d[i][j]=i;
		if(i>0&&j>0)
		{
		    if(a[i-1]==b[j-1]){
			d[i][j]=d[i-1][j-1];
		    }else{
			d[i][j]=minOfThree(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+1);
		    }
		}
	    }
	}	

	printMatrix(d, a, b, x, y);
	return d[x][y];
}

int main()
{
	char aa[]="abc";
	int xx=3;
	
	char bb[]="acde";
	int yy=4;
	
	d = new int *[xx+1];
	for(int i=0; i<xx+1; i++){
	    d[i]=new int[yy+1];
	}	
	
	int ret = minDis(aa, xx, bb, yy);
	cout<<"The longest edit distance from strA to strB is "<<ret<<endl;

	for(int j=0; j<xx+1; j++){
	    delete [] d[j];
	}
	delete []d;
}


