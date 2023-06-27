#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
#include<vector>
void print_matrix(int **s,int i,int j){
    if(i==j){
        cout<<"A"<<i;
        return;
    }
    else{
        cout<<"(";
        print_matrix(s,i,s[i][j]);
        print_matrix(s,s[i][j]+1,j);
        cout<<")";
        return;
    }
}

int matrix(vector<int> &p){
    int n=p.size()-1;
    int r[n+1][n+1];
    int **s;
    s=(int **)malloc((n+1)*sizeof(int*));
    for(int i=0;i<n+1;i++){
        s[i]=(int *)malloc((n+1)*sizeof(int*));
    }
    //int s[n+1][n+1];
    for(int i=1;i<=n;i++){
        r[i][i]=0;
        s[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            r[i][j]=INT_MIN;
            for(int k=i;k<=j-1;k++){
                int q=r[i][k]+r[k+1][j]+p[i-1]*p[j]*p[k];
                if(q>r[i][j]){
                    r[i][j]=q;
                    s[i][j]=k;
                }
            }

        }
    }
    //print_matrix(s,1,n);

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++) cout<<" ";
        for(int j=i;j<=n;j++) cout<<s[i][j]<<" ";
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<r[i][j]<<" ";
        }
        if(i!=n) cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<s[i][j]<<" ";
        }
        if(i!=n) cout<<endl;
    }
    print_matrix(s,1,n);
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++) cout<<" ";
        for(int j=i;j<=n;j++) cout<<r[i][j]<<" ";
        cout<<endl;
    }*/
    return r[1][n];
    
}
int main(){
    int n,ele;
    cin>>n;
    vector<int> p;
    for(int i=0;i<n;i++){
        cin>>ele;
        p.push_back(ele);
    }
    cout<<"\n"<<matrix(p);
}