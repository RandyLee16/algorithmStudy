#include<iostream>
#include<algorithm>

using namespace std;

int **c;
char **b;

template <typename T>
void printMatrix(T **arr,int *x, int *y, int m, int n)
{
	cout<<"X\\Y O ";
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

int lcsLength(int *xx, int *yy, int mm, int nn)
{
	for(int i=0; i<=mm;i++){
		for(int j=0;j<=nn;j++){
			if(i==0||j==0){
				c[i][j]=0;
				b[i][j]=' ';
			}else{
			    if(xx[i-1]==yy[j-1]){ //NOTE: b(i,j) coresponding to x[i-1],y[j-1]
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='O';   //obligue arrow
			    }else{    //xx[i]!=yy[j]
				c[i][j]=max(c[i-1][j], c[i][j-1]);
				//RESULT2: the result may change it  change >=  tp >
				if(c[i-1][j]>= c[i][j-1]) b[i][j]='U'; //up arrow
				else                      b[i][j]='L'; //left arrow
			    }
			}
		}
	}	
	cout<<"Length of LCS is "<<c[mm][nn]<<endl;
	cout<<endl<<"Table c:"<<endl;
	printMatrix(c, xx, yy, mm, nn);
	cout<<endl<<"Table b:"<<endl;
	printMatrix(b, xx, yy, mm, nn);
	
}

void printLcs(int *xx, int i, int j)
{
	if(i==0||j==0) return;

	if(b[i][j]=='O'){
	    printLcs(xx, i-1, j-1);
	    cout<<xx[i-1]<<" ";  //NOTE: b(i,j) coresponding to x[i-1],y[j-1]
	}else if(b[i][j]=='U'){
	    printLcs(xx, i-1, j);
	}else if(b[i][j]=='L'){
	    printLcs(xx, i, j-1);
	}
}

int main()
{
	int m,n;
	int *x,*y;

	//cout<<"Input sequence X, size: "<<endl;
	//cin>>m;
	//x=new int[m];
	//cout<<endl<<"element of X: "<<endl;
	//for(int i=0;i<m;i++){
	//    cin>>x[i];
	//}

	//cout<<"Input sequence Y, size: "<<endl;
	//cin>>n;
	//y=new int[n];
	//cout<<endl<<"element of Y: "<<endl;
	//for(int i=0;i<n;i++){
	//    cin>>y[i];
	//}
	
	int xx[6]={2,4,3,1,2,1};
	int yy[7]={1,2,3,2,4,1,2};
	m=6;
	n=7;
	x=xx;
	y=yy;

	//create dynamic 2d array int c[m+1][n+1]
	c = new int *[m+1];
	for(int i=0; i<m+1; i++){
	    c[i]=new int[n+1];
	}	
	

	//create dynamic 2d array char b[m+1][n+1]
	b = new char *[m+1];
	for(int j=0; j<m+1; j++){
	    b[j]=new char[n+1];
	}

	lcsLength(x, y, m, n);
 
	cout<<"LCS sequence is:"<<endl;
        printLcs(x, m, n);
	cout<<endl;

	//free space poiinted by c
	for(int i=0; i<m+1; i++){
	    delete [] c[i];
	}	
	delete []c;

	//free space poiinted by b
	for(int j=0; j<m+1; j++){
	    delete [] b[j];
	}
	delete []b;
}
