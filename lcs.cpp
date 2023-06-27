#include<iostream>
#include<cstdlib>
using namespace std;
void print_lcs(int **c, string a, string b, int i, int j){
    if(i==0 || j==0) return;
    else if(a[i-1]==b[j-1]){
        print_lcs(c,a,b,i-1,j-1);
        cout<<a[i-1];
    }
    else if(c[i-1][j]>=c[i][j-1]){
        print_lcs(c,a,b,i-1,j);
        return;
    }
    else{
        print_lcs(c,a,b,i,j-1);
        return;
    } 

}
int lcs(string a, string b){
    int m=a.size();
    int n=b.size();
    int **c;
    c=(int**)malloc((m+1)*sizeof(int*));
    for(int i=0;i<=m;i++){
        c[i]=(int*)malloc((n+1)*sizeof(int*));
    }
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                c[i+1][j+1]=c[i][j]+1;
            }
            else if(c[i][j+1]>=c[i+1][j]){
                c[i+1][j+1]=c[i][j+1];
            }
            else c[i+1][j+1]=c[i+1][j];
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    print_lcs(c,a,b,m,n);
    return c[m][n];
}
int main(){
    string a="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    string b="GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    int d=lcs(a,b);
    cout<<d;
}