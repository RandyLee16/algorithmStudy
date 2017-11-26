#include<iostream>
#include<assert.h>

using namespace std;

static int n=0;

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


void perm(int a[], int l, int r){
    assert(l<=r);
    if(l==r){
        for(int i=0; i<=r; i++){
            cout<<a[i]<<" ";
        }
        n++;
        cout<<endl;
    }else{
        for(int j=l; j<=r; j++){
            swap(&a[j], &a[l]);
            perm(a, l+1, r);
            //swap(&a[j], &a[l]);
        }    
    }
}


int main(){
    int n;
    cout<<"Input array size:";
    cin >>n;
    int *array = (int *)malloc(sizeof(int)*n);
    cout<<"Input the array elements:"<<endl;
    for(int i=0; i<n; i++){
        cin >> *(array+i);
    }

    //int array[4]={1,2,3,4};
    cout<<endl<<"Input array is:"<<endl;
    for(int i=0; i<n; i++){
        cout<<*(array+i)<<" ";
    }
    cout<<endl<<"Permutation:"<<endl;
    perm(array, 0, n-1);

    cout<<"Total number of this perm is "<< n <<endl;
    free(array);

}
