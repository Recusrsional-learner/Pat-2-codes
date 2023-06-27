#include<iostream>
using namespace std;
#include<vector>
void find_transforms(string a, string b){
    int l=a.size();
    if(l!=b.size()){
        cout<<"Not possible";
        return;
    }
    int amt=0;
    int array[l];
    vector<int> transforms;
    for(int i=0;i<l;i++){
        if(a[i]==b[i]){
            array[i]=1;
            amt++;
        }
        else array[i]=0;
    }
    for(int i=0;i<l;i++){
        if(array[i]==0){
            for(int j=i+1;j<l;j++){
                if(array[j]==0){
                    if(a[i]==b[j] && b[i]==a[j]){
                        array[i]=1;
                        array[j]=1;
                        amt+=2;
                        transforms.push_back(i+1);
                        transforms.push_back(j+1);
                    }
                }
            }
        }
    }
    if(amt!=l){
        cout<<"Not possible";
        return;
    }
    else{
        for(int i=0;i<l;i++){
            if(a[i]==b[i]) amt--;
        }
        for(int i=0;i<amt;i=i+2){
                cout<<transforms[i]<<" "<<transforms[i+1]<<"\n";
        }
    }
}
int main(){
    string a="abcd";
    string b="cdba";
    find_transforms(a,b);
}