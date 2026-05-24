#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int x[n][n];
    memset(x,0,sizeof(x));
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        x[a][b]=1;
        x[b][a]=1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j)x[i][j]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}