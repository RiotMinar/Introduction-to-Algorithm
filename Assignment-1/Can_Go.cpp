#include <bits/stdc++.h>
using namespace std;
char x[1005][1005];
bool val[1005][1005];
int n,m;
vector<pair<int,int>> y={{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)return false;
    else return true;
}
int flg=0;
void bfs(int si,int sj)
{
    if(x[si][sj]=='B')
    {
        flg=1;
        return;
    }
    val[si][sj]=true;
    int ci,cj;
    for(int i=0;i<4;i++)
    {
        ci=si+y[i].first;
        cj=sj+y[i].second;
        if(valid(ci,cj) && x[ci][cj]!='#' && !val[ci][cj])
        {
            bfs(ci,cj);
        }
    }
}
int main()
{
    memset(val,false,sizeof(val));
    int k,l;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                cin>>x[i][j];
                if(x[i][j]=='A')
                {
                    k=i;
                    l=j;
                }
            }
    bfs(k,l);
    if(flg==1)cout<<"YES";
    else cout<<"NO";
    return 0;
}