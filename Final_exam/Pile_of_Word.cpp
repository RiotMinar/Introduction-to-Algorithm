#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size())
        {
            cout<<"NO";
        }
        else
        {
            int a[26]={0},b[26]={0};
            for(int i=0;i<s1.size();i++)
                a[s1[i]-'a']++;
            for(int i=0;i<s2.size();i++)
                b[s2[i]-'a']++;
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                if(a[i]!=0 && b[i]!=0 && a[i]==b[i])
                {
                    cnt+=a[i];
            }
        }
        if(cnt==s1.size())cout<<"YES";
        else cout<<"NO";
        }
        
        cout<<endl;
    }
    return 0;
}