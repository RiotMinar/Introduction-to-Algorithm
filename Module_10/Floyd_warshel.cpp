#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int adj_m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)adj_m[i][j]=0;
            else adj_m[i][j]=INT_MAX;
        }
    }
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c<adj_m[a][b])adj_m[a][b]=c;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj_m[i][k]!=INT_MAX && adj_m[k][j]!=INT_MAX && adj_m[i][k]+adj_m[k][j]<adj_m[i][j])
                    adj_m[i][j]= adj_m[i][k]+adj_m[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj_m[i][j]==INT_MAX)cout<<"INF";
                else cout<<adj_m[i][j];
                cout<<" ";
            }
            cout<<endl;
        }
    return 0;
}