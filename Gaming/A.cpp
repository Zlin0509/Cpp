#include "bits/stdc++.h"
using namespace std;
string c;
int ans1,ans2,ans3;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>c)
	{
		int c1=0,c2=0,c3=0;
		int l = -1;
		int len = c.length();
		for(int i=0;i<len;i++)
		{
			if(c[i]<='9'&&c[i]>='0') ++c1;
			else if(c[i]<='z'&&c[i]>='a') ++c2;
			else if(c[i]<='Z'&&c[i]>='A') ++c3;
			else
			{
				if(!c1&&!c2&&!c3)
				{
					l = i;
					continue;
				}
				if(c1&&c2&&c3) ans1+=5;
				else if((c1&&c2)||(c1&&c3)) ans1+=3;
				else if(c2&&c3) ans1+=1;
				ans2+=i-l;
				l = i;
				++ans3;
				c1=c2=c3=0;
			}
		}
	}
	cout<<ans1<<'\n'<<ans2<<' '<<ans3;
	return 0;
}
