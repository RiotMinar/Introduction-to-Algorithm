#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    long long int adj_m[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)adj_m[i][j]=0;
            else adj_m[i][j]=LLONG_MAX;
        }
    }
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c<adj_m[a][b])adj_m[a][b]=c;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adj_m[i][k]!=LLONG_MAX && adj_m[k][j]!=LLONG_MAX && adj_m[i][k]+adj_m[k][j]<adj_m[i][j])
                    adj_m[i][j]= adj_m[i][k]+adj_m[k][j];
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(adj_m[a][b]==LLONG_MAX)cout<<-1;
        else cout<<adj_m[a][b];
        cout<<endl;
    }
    return 0;
}