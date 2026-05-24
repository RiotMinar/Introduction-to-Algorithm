#include <bits/stdc++.h>
using namespace std;

int val[1005],wgt[1005];
int dp[1005][1005];
int find(int i,int mx_weight)
{
    if(i<0 || mx_weight<=0)
        return 0;
    if(dp[i][mx_weight]!=-1)
        return dp[i][mx_weight];
    if(wgt[i]<=mx_weight)
    {
        int op1=find(i-1,mx_weight-wgt[i])+val[i];
        int op2=find(i-1,mx_weight);
        dp[i][mx_weight]=max(op1,op2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight]=find(i-1,mx_weight);
        return dp[i][mx_weight];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,mxw;
        cin>>n>>mxw;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=mxw;j++)
                dp[i][j]=-1;
        for(int i=0;i<n;i++)
            cin>>wgt[i];
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        cout<<find(n-1,mxw)<<endl;
    }
    return 0;
}