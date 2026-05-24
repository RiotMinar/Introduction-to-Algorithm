#include <bits/stdc++.h>
using namespace std;
int cost[1005],wgt[1005];
int knap(int i,int mx_weight)
{
    if(i<0 || mx_weight<=0)
        return 0;
    if(wgt[i]<=mx_weight)
    {
        int op1=knap(i-1,mx_weight-wgt[i])+cost[i];
        int op2=knap(i-1,mx_weight);
        return max(op1,op2);
    }
    else
    {
        return knap(i-1,mx_weight);
    }

}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>cost[i];
    for(int i=0;i<n;i++)
        cin>>wgt[i];
    int max;
    cin>>max;
    cout<<knap(n-1,max);
    return 0;
}