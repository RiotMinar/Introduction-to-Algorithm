#include <bits/stdc++.h>
using namespace std;
vector<int> x[1005];
int main()
{
    int n,e;
    cin>>n>>e;
    memset(x,0,sizeof(x));
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        sort(x[i].begin(),x[i].end());
        reverse(x[i].begin(),x[i].end());
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a;
        cin>>a;
        if(x[a].empty())cout<<-1;
        else for(int i:x[a])cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}