#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int lcs(string x,string y,int n,int m){
    string s="";
    int t[n+1][m+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i==0||j==0)
                t[i][j]=0;
            else if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
//    for(int i=0;i<=n;++i){
//        for(int j=0;j<=m;++j){
//            cout<<t[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return t[n][m];
}

int lcsubstring(string x,string y,int n,int m){
    int ans=INT_MIN;
    int t[n+1][m+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i==0||j==0)
                t[i][j]=0;
            else if(x[i-1]==y[j-1])
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=0;
            ans=max(ans,t[i][j]);
        }
    }
//    for(int i=0;i<=n;++i){
//        for(int j=0;j<=m;++j){
//            cout<<t[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return ans;
}

int main(){
    string x;
    string y;
    cin>>x>>y;
    cout<<lcs(x,y,x.length(),y.length());
    return 0;
}
