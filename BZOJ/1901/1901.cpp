```
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cctype>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define RepD(i,n) for(int i=n;i>=0;i--)
#define MEM(a) memset(a,0,sizeof(a))
#define MEMI(a) memset(a,127,sizeof(a))
#define MEMi(a) memset(a,128,sizeof(a))
#define MAXN (10000+10)
#define MAXM (10000+10)
#define MAXAi (1000000000+10)
#define MINAi (0)
int n,m,a[MAXN];
struct node
{
	int ch[2],c,fa;
	node():c(0),fa(0){ch[0]=ch[1]=0;}
}q[MAXN*4*100];
int root[MAXN]={0},tot=0;
void insert(int &x,int l,int r,int c,int d)
{
	if (!x) x=++tot;
	q[x].c+=d;
	int m=l+r>>1;
	if (l==r) return;
	if (c<=m) insert(q[x].ch[0],l,m,c,d),q[q[x].ch[0]].fa=x;
	else insert(q[x].ch[1],m+1,r,c,d),q[q[x].ch[1]].fa=x;
}
void update(int x,int c,int d)
{
	for(int i=x;i<=n;i+=i&(-i)) insert(root[i],MINAi,MAXAi,c,d);
}
int ans[MAXN],ans_siz=0;
void qur(int x)
{
	for(int i=x;i;i-=i&(-i)) ans[++ans_siz]=root[i];
}
void turn(bool c)
{
	For(i,ans_siz) ans[i]=q[ans[i]].ch[c];
}
int main()
{
//	freopen("bzoj1901.in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,n) scanf("%d",&a[i]),update(i,a[i],1);
	while (m--)
	{
		char c[2];
		scanf("%s",c);
		switch(c[0])
		{
			case 'C':
				{
					int i,c;
					scanf("%d%d",&i,&c);
					update(i,a[i],-1);
					update(i,a[i]=c,1);
					break;
				}
			default:
				{
					int l,r,k;
					scanf("%d%d%d",&l,&r,&k);
					ans_siz=0;
					qur(r);int ad_end=ans_siz;qur(l-1);	
					l=MINAi,r=MAXAi;
					while (l<r)
					{
						int m=l+r>>1,s=0;
						For(i,ad_end) s+=q[q[ans[i]].ch[0]].c;
						Fork(i,ad_end+1,ans_siz) s-=q[q[ans[i]].ch[0]].c;
						if (k<=s) turn(0),r=m;else turn(1),l=m+1,k-=s;
					}
					cout<<l<<endl;					
				}	
		}
	}
	
	
	
	
	return 0;
}
```
