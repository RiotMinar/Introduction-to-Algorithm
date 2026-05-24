#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            int c;
            cin>>c;
            a[i]=c;
            b[i]=c;
        }
        sort(b,b+n);
        int l=b[n-2],r=b[n-1];
        for(int i=0;i<n;i++)
        {
            if(a[i]==l || a[i]==r)cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}