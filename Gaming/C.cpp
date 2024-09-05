#include "bits/stdc++.h"
using namespace std;
int n,tot;
int a[5];
int used[20];
map<int,int>uu;
long long ss = 0;
vector<long long>aa;
stack<int>ans;
bool check = 0;
inline void prework(int dep,int sum)
{
	if(dep>n)
	{
		aa.push_back(sum);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!used[i])
		{
			++used[i];
			prework(dep+1,sum*10+a[i]);
			--used[i];
		}
}
inline void dfs(int dep,long long sum)
{
	if(sum == ss/2){
		check = 1;
		while(!ans.empty())
		{
			cout<<ans.top()<<'\n';
			ans.pop();
		}
	}
	if(dep>tot||check) return;
	for(auto ii=aa.begin();ii!=aa.end();ii++)
	{
		int it = *ii;
		if(!uu[it])
		{
			uu[it]=1;
			if(!check)
			ans.push(it);
			dfs(dep+1,sum+it*it);
			if(check) break;
			ans.pop();
			uu[it]=0;
		}
	}
}
inline void Zlin()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	prework(1,0);
	tot = aa.size() / 2;
	if(n==3){
		for(auto it:aa) ss+=it*it;
		dfs(1,0);
		return;
	}
	sort(aa.begin(),aa.end());
	for(int i = 0;i<tot/2;i++)
		ans.push(aa[i]),ans.push(aa[tot*2-1-i]);
	while(!ans.empty())
	{
		cout<<ans.top()<<'\n';
		ans.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	Zlin();	
}
