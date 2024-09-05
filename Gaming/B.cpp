#include "bits/stdc++.h"
using namespace std;
int n;
struct ss{
int id,sum;
} c[33];
bool cmp(const ss &a,const ss &b){
	if(a.sum!=b.sum)return a.sum>b.sum;
	return a.id<b.id;
}
int s[22]={0,25,21,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
int used[33];
inline void Zlin()
{
	for(int i=1;i<=30;i++) c[i].id=i,c[i].sum=0;
	cin>>n;
	while(n--)
	{
		for(int i=1,cc,p;i<=20;i++)
		{
			cin>>cc>>p;
			++used[cc];
			c[cc].sum+=s[p];
		}
	}
	sort(c+1,c+31,cmp);
	for(int i=1;i<=30;i++)
	{
		if(used[c[i].id])
			cout<<c[i].id<<' '<<c[i].sum<<'\n';
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	Zlin();	
}
