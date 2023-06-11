#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T;
int n,m,q;
bool sp[N];
long long sum[N][3];
int c[N];
long long ans[3];
struct node
{
    int v;
    long long w;    
};
vector<node> e[N],esp[N];
map< pair<int,int> , long long > val;
int d[N];
int D;
char s[109];
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        T++;
        printf("Case %d:\n",T);
        D=sqrt(m*2);
        memset(ans,0,sizeof(ans));
        memset(sum,0,sizeof(sum));
        memset(d,0,sizeof(d));
        memset(sp,0,sizeof(sp));
        val.clear();
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1,u,v,w;i<=m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            d[u]++;d[v]++;
            if(!val[{u,v}]) 
            {
                e[u].push_back((node){v,0});
                e[v].push_back((node){u,0});
            }
            val[{u,v}]+=w;
            val[{v,u}]+=w;
            ans[c[u]+c[v]]+=w;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<e[i].size();j++)
            {
                e[i][j].w=val[{i,e[i][j].v}];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(d[i]>=D)
            {
                sp[i]=1;
                for(int j=0;j<e[i].size();j++)
                {
                    int v=e[i][j].v;
                    long long w=e[i][j].w;
                    esp[v].push_back((node){i,w});
                    sum[i][c[v]]+=w;
                }
            }
        }
        scanf("%d",&q);
        for(int i=1,x,y;i<=q;i++)
        {
            scanf("%s",s);
            if(s[0]=='A')
            {
                scanf("%d %d",&x,&y);
                printf("%lld\n",ans[x+y]);    
            }
            else
            {
                scanf("%d",&x);
                if(sp[x])
                {
                    ans[c[x]+0]-=sum[x][0];
                    ans[c[x]+1]-=sum[x][1];
                    c[x]^=1;
                    ans[c[x]+0]+=sum[x][0];
                    ans[c[x]+1]+=sum[x][1];
                }
                else
                {
                    for(int j=0;j<e[x].size();j++)
                    {
                        int v=e[x][j].v;
                        long long w=e[x][j].w;
                        ans[c[x]+c[v]]-=w;
                        ans[(c[x]^1)+c[v]]+=w;
                    }
                    c[x]^=1;
                }
                for(int j=0;j<esp[x].size();j++)
                {
                    int v=e[x][j].v;
                    long long w=e[x][j].w;
                    sum[v][c[x]]+=w;
                    sum[v][c[x]^1]-=w;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            vector<node>().swap(e[i]);
            vector<node>().swap(esp[i]);
        }
    }
    return 0;
}
