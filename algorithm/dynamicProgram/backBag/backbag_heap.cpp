#include<iostream>
#include<algorithm>

using namespace std;

#define N 5
#define C 10

int w[N]={2,2,6,5,4};
int v[N]={6,3,5,4,6};
int **d;

void dn(int c=C);
void printArrDn(int c=C);

int main()
{
	int cpct;
	//cout<<"input weight of every thing:";
	//for(int i=0;i<N;i++) cin>>w[i];
	//cout<<endl;
	//cout<<"input value of every thing:";
	//for(int i=0;i<N;i++) cin>>v[i];
	//cout<<endl;
	cout<<"input the capacity of the bag:";
	cin>>cpct;
	d=new int*[N];
	for( int i=0, i<=C, i++){
		d[i]=new int[C+1];
	}
	dn(cpct);
	cout<<"The biggest value the bag can contain:"<<d[N-1][cpct]<<endl;
	printArrDn(cpct);
	for( int i=0, i<=C, i++){
		delete [] d[i];
	}
	delete []d;
	
}

void printArrDn(int c)
{
	cout<<"id "<<"wgh "<<"vlu  "<<endl;
	for(int i=0; i<N;  i++){
		cout<<i<<"   "<<w[i]<<"   "<<v[i]<<"   ";
		for(int j=0; j<=c; j++){
			cout<<d[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void dn(int c)
{
	int temp=0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<=c; j++)
		{
			if(i==0) d[i][j]=(w[i]>j?0:v[i]);
			if(i>0){ 
				d[i][j]=d[i-1][j];
				//if(j>=w[i]){
				//	 d[i][j]=max(d[i-1][j-w[i]]+v[i], d[i-1][j]);
				//}
				if(j>=w[i]&&(d[i-1][j-w[i]]+v[i]> d[i][j])){
					 d[i][j]=d[i-1][j-w[i]]+v[i];
				}
			}
		}
	}
}

