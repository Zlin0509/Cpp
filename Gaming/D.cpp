#include "bits/stdc++.h"
using namespace std;
int n,m;
int a[10010]{};
int s,t;
struct edge
{
	int v,to,next;
}e[300010]{};
int tot,head[300010]{};
inline void Zlin()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,u,v,val;i<=m;i++)
	{
		cin>>u>>v>>val;
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int ttt;
	cin>>ttt;
	while(ttt--) Zlin();	
}
