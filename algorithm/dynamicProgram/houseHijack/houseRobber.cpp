#include<iostream>
#include<algorithm>

using namespace std;

int maxBooty(int *a, int n)
{
	int f2=0, f1=0, ret=0;
	for(int i=0; i<n; i++)
	{
	    if(i==0){
	    	f2 = a[0];
		ret = f2;
	    }else if(i==1){
		f1 = a[1];
		ret=max(f2, f1);
	    }else{
		ret=max(f2+a[i], f1);
		f2=f1;
		f1=ret;	
	    }
	}
	return ret;
}

int main()
{
	int input[]={3, 8, 4, 7, 2, 5, 6};
	int m =7;
	int result = maxBooty(input, m);
	cout<<"Result is "<<result<<endl;
}
