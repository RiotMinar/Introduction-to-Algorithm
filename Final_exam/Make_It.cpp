#include <bits/stdc++.h>
using namespace std;
int x;
void mns()
{
    x-=3;
}
void divide()
{
    x/=2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        queue<int>pq;
    pq.push(1);
    cin>>x;
    bool check=false;
    while(x>100)
    {
        if(x%2==0)divide();
        else mns();
    }
    while(!pq.empty())
    {
        int tmp=pq.front();
        if(tmp==x)
        {   
            check=true;
            break;
        }
        pq.pop();
        if(tmp*2<=x)pq.push(tmp*2);
        if(tmp+3<=x)pq.push(tmp+3);

    }
    if(check)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    }
    return 0;
}