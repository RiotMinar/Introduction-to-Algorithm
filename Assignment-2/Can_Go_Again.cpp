#include <bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int a,b;
    long long int c;
    edge(int a,int b,int c)
    {
        this->a=a;
        this->b=b;
        this->c=c;  
    }
};
long long int dis[1005];
int main()
{
    int n,e;
    cin>>n>>e;
    vector<edge> edge_list;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge_list.push_back(edge(a,b,c));
    }
    for(int i=0;i<=n;i++)
        dis[i]=LLONG_MAX;
    int src;
    cin>>src;
    dis[src]=0;
    for(int i=1;i<n-1;i++)
    {
        for(auto ed:edge_list)
        {
            int a=ed.a,b=ed.b,c=ed.c;
            if(dis[a]!=LLONG_MAX && dis[a]+c<dis[b])
                dis[b]=dis[a]+c;
        }
    }
    bool cycle=false;
    for(int i=1;i<n-1;i++)
    {
        for(auto ed:edge_list)
        {
            int a=ed.a,b=ed.b,c=ed.c;
            if(dis[a]!=LLONG_MAX && dis[a]+c<dis[b])
                cycle=true;
        }
    }
    if(cycle)cout<<"Negative Cycle Detected";
    else
    {
        int t;
        cin>>t;
        while(t--)
        {
            int a;
            cin>>a;
            if(dis[a]==LLONG_MAX)cout<<"Not Possible";
            else cout<<dis[a];
            cout<<endl;
        }
    }
    return 0;
}