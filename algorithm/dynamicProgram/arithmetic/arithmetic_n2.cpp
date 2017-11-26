#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

//solution with time complex O(n2)
int fillAndCalc(int *a, int m)
{
	int account = 0;
	int blackAccount = 0;
	vector<unordered_map<int, int>> arithTable(m);
	//fill array g[m][m]
	for(int i=1; i<m; i++)
	{
	    for(int j=0; j<i; j++)
	    {
		int diff=a[i]-a[j];
		int num=1 ;    //arithmetic sequence number, treat a subsequence with lenghth 2 a arithmetic sequence too
		if(!arithTable[j].empty())
	            if(arithTable[j].count(diff)){
			num=arithTable[j][diff]+1;
		}
		arithTable[i][diff]=num;

		//calculate arithmetic subsequence account of sequence of length m
		cout<<"For "<<i<<", diff-num is "<<diff<<" - "<<num<<endl;
	        account += num;
	    }
	    blackAccount += arithTable[i].size();
	}
	
		
	return account-blackAccount;
}

int main()
{
	int input[5]={2,4,6,8,10};
	int n=5;

	int c=fillAndCalc(input, n);
	cout<<"Arithmetic subsequence account of sequence is "<<c<<endl;

}
