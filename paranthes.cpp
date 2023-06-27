#include<iostream>
using namespace std;
int ways(int n){
    int r[n];
    r[1]=1;
    r[2]=1;
    for(int l=3;l<=n;l++){
        r[l]=0;
        for(int k=1;k<l;k++){
            r[l]+=r[k]*r[l-k];
        }
    }
    return r[n];
}
int main(){
    int n;
    cin>>n;
    cout<<ways(n);
}