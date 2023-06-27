#include<iostream>
#include<climits>
using namespace std;
#include<vector>
int max(int a, int b){
    if(a>=b) return a;
    else return b;
}
void rod_cutting(int *p,int n){
    int r[n];
    int c[n];
    r[0]=0;
    cout<<r[0];
    for(int l=1;l<=n;l++){
        r[l]=-1;
        for(int k=1;k<=l;k++){
            int q=p[k]+r[l-k];
            if(q>r[l]){
                r[l]=q;
                c[l]=k;
                cout<<q<<" "<<k<<" "<<l<<"\t";
                cout<<p[k]<<"-"<<k<<" "<<r[l-k]<<"-"<<l-k<<endl;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<r[i]<<" ";
    for(int i=1;i<=n;i++) cout<<c[i]<<" "; 
    int fc=c[n];
    int at=0;
    while(fc<=n){
        cout<<fc-at<<endl;
        at=fc;
        if(fc==n) break;
        fc=fc+c[n-fc];
    }
}
int main(){
    int n;
    cin>>n;
    int prices[n];
    prices[0]=0;
    for(int i=1;i<=n;i++) cin>>prices[i];
    rod_cutting(prices,n);
}