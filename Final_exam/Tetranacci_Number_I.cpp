#include <bits/stdc++.h>
using namespace std;

long long int dp[1005];
int fibo(long long int n)
{
    if(dp[n]!=-1)
        return dp[n];
    dp[n]= fibo(n-1)+fibo(n-2)+fibo(n-3)+fibo(n-4);
    return dp[n];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    dp[0]=0;dp[1]=1;dp[2]=1;dp[3]=2;
    long long int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}