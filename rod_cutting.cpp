#include<iostream>
using namespace std;
#include<vector>
int max(int a, int b){
    if(a>=b) return a;
    else return b;
}
int min(int a,int b){
    if(a<=b) return a;
    else return b;
}
int rod_cutting(int *p,vector<int>&r,vector<int>&cut,int l){
    if(r[l]>=0){
        return r[l];
    }
    else {
        int q=INT_MIN;
        int m=min(3,l);
        for(int i=1; i<=m; i++){
            int c=rod_cutting(p,r,cut,l-i);
            int prev=q;
            q=max(q,p[i]+c);
            if(q>prev) {
              cout<<"hit"<<endl;
              cut[l]=i;
            }
        }
        r[l]=q;
        return q;
    }
}
void show_cuts(int l,vector<int>&c){
    int fc=c[l];
    if(fc==l){
        cout<<l<<endl;
        return;
    }
    else{
        cout<<fc<<endl;
        show_cuts(l-fc,c);
    }
}
void cuts(int l,vector<int>&c){
    cout<<"cut at"<<endl;
    int fc=c[l],fc_a=c[l];
    if(fc==l) cout<<fc<<endl;
    while(fc<l){
        cout<<fc<<endl;
        fc=fc+c[l-fc];
    }
}
int rod_cutting_i(int *p, int l){
    vector<int> r;
    vector<int> cut;
    for(int i=0;i<l+1;i++){
        r.push_back(-1);
        cut.push_back(-1);
    }
    cut[0]=0;
    r[0]=0;
    int ans=rod_cutting(p,r,cut,l);
    //for(int i=1;i<=l;i++) cout<<cut[i]<<endl;
    cout<<"cut pieces length"<<endl;
    show_cuts(l,cut);
    cuts(l,cut);
    return ans;
}

int main(){
    int p_l;
    cout<<"size of prices";
    int prices[4]={-1,1,3,4};
    int l;
    cout<<"Enter rod length"<<endl;
    cin>>l;
    int d=rod_cutting_i(prices,l);
    cout<<d;
}
