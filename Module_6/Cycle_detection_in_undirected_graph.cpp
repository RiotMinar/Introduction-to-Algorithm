#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int child:adj_list[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    memset(adj_list,false,sizeof(adj_list));
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    return 0;
}