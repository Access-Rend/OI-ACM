#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int N=1e6+10;
struct acauto
{
	int ch[N][26],cnt[N],f[N],pc;
	void ini()
	{
		pc=0;
		memset(ch,0,sizeof(ch));
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
	}
	void insert(char *s)
	{
		int u=0,len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			if(!ch[u][s[i]-'a'])
				ch[u][s[i]-'a']=++pc;
			u=ch[u][s[i]-'a'];
		}
		cnt[u]++;
	}
	void getf()
	{
		queue<int>Q;
		for(int i=0;i<26;i++)
			if(ch[0][i])
			f[ch[0][i]]=0,Q.push(ch[0][i]);
		while(!Q.empty())//???????
		{
			int u=Q.front();Q.pop();
			for(int i=0;i<26;i++)
			if(ch[u][i])
			{
				f[ch[u][i]]=ch[f[u]][i];
				Q.push(ch[u][i]);
			}
			else	ch[u][i]=ch[f[u]][i];
		}
	}
	int query(char *s)
	{
		int u=0,len=strlen(s+1),ans=0;
		for(int i=1;i<=len;i++)
		{
			u=ch[u][s[i]-'a'];
			for(int j=u;j&&cnt[j]!=-1;j=f[j])
			ans+=cnt[j],cnt[j]=-1;//每存在一个cnt即为找到一个答案 
		}
		return ans;
	}
}AC;

void solve()
{
	int T,n;
	char s[N];
	scanf("%d",&T);
	while(T--)
	{
		AC.ini();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",s+1);
			AC.insert(s);
		}
		AC.getf();
		scanf("%s",s+1); 
		printf("%d\n",AC.query(s));
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

