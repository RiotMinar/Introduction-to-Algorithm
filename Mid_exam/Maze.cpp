#include <bits/stdc++.h>
using namespace std;
char x[1005][1005];
bool vis[1005][1005];
int lvl[1005][1005];
pair<int,int> parent[1005][1005];
int n,m;
int a,b,c,d;
vector<pair<int,int>> y={{0,1},{0,-1},{-1,0},{1,0}};
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

        for(int i=0;i<4;i++)
        {
            int ci=pari+y[i].first;
            int cj=parj+y[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && x[ci][cj]!='#')
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                lvl[ci][cj]=lvl[pari][parj]+1;
                parent[ci][cj]=par;
            }
        }
    }
}
int main()
{
        cin>>n>>m;
        memset(vis,false,sizeof(vis));
        memset(lvl,-1,sizeof(lvl));
        memset(parent,-1,sizeof(parent));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>x[i][j];
                if(x[i][j]=='R')
                {
                    a=i;b=j;
                }
                if(x[i][j]=='D')
                {
                    c=i;d=j;
                }
            }
        }
        
        bfs(a,b);
        int ni=c,nj=d;
        if(vis[c][d])
        {
        while(true)
        {
            if(x[ni][nj]=='R')break;
            x[ni][nj]='X';
            pair<int,int> par=parent[ni][nj];
            ni=par.first;
            nj=par.second;
            
        }
        }
        x[c][d]='D';
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<x[i][j];
            }
            cout<<endl;
        }
    return 0;
}