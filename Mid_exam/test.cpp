#include <bits/stdc++.h>
using namespace std;
char x[1005][1005];
bool vis[1005][1005];
int lvl[1005][1005];
int n,m;
int a,b,c,d;
vector<pair<int,int>> y={{-2,1},{-2,-1},{-1,2},{-1,-2},{2,1},{2,-1},{1,2},{1,-2}};
bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)return false;
    else return true;
}
void bfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    lvl[si][sj]=0;
    while(!q.empty())
    {
        pair<int,int> par=q.front();
        q.pop();
        int pari=par.first;
        int parj=par.second;

        for(int i=0;i<8;i++)
        {
            int ci=pari+y[i].first;
            int cj=parj+y[i].second;
            if(valid(ci,cj) && !vis[ci][cj] )
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                lvl[ci][cj]=lvl[pari][parj]+1;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    memset(lvl,-1,sizeof(lvl));
    memset(x,'.',sizeof(x));
    cin>>a>>b>>c>>d;
    bfs(a,b);
    cout<<lvl[c][d];
    return 0;
}