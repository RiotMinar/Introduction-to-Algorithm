#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)cin>>b[i];
    int i=0,j=0,c[m+n],curr=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])c[curr++]=a[i++];
        else c[curr++]=b[j++];
    }
    while(i<n)c[curr++]=a[i++];
    while(j<m)c[curr++]=b[j++];
    for(int k=0;k<m+n;k++)cout<<c[k]<<" ";
    return 0;
}