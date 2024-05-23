#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int num=c,h;
    if(b<=c)
    {
        h=1;
        a=a-(c-b)/2;
        if(a<=0)
        {
            cout<<h<<'\n';
            return;
        }
    }
    else
    {
        h=b/c;
        b%c==0?h:++h;
        a=a-(c-b%c)/2;
        if(a<=0)
        {
            cout<<h<<'\n';
            return;
        }
        ++h;
    }
    
    while(num<=2)
    {
        ++h;
        a-=num/2;
        if(a<=0)
        {
            cout<<h<<'\n';
            return;
        }
        num=num-num/2;
    }
    cout<<"-1"<<'\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}