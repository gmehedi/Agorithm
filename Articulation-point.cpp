#include <bits/stdc++.h>
#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull              unsigned long long
#define f                first
#define s                second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define mk(x1,y1) make_pair(x1, y1)
#define maxl 100001
#define psz 20
using namespace std;

vector<int>g[maxl];
int visited[maxl];
bool sign[maxl];
int low[maxl],d[maxl],parent[maxl];
int t=1;

void Articulation(int s,bool root)
{
    t++;
    low[s]=d[s]=t;
    visited[s]=1;
    int child=0;

    for(int i=0; i<g[s].size(); i++)
    {
        int v=g[s][i];

        if(visited[v])
        {
            low[s]=min(low[s],d[v]);
        }
        if(!visited[v])
        {
            Articulation(v,false);

            if(d[s]<=low[v]&&!root)
            {
                sign[s]=true;
            }
            low[s]=min(low[s],low[v]);
            child++;
        }
        if(child>1&&root)
        {
            sign[s]=true;
        }

    }

}
void setting()
{
    for(int i=0; i<maxl; i++)
    {
        g[i].clear();
        visited[i]=sign[i]=low[i]=d[i]=parent[i]=0;
        t=0;
    }
}
int main()
{

    setting();
    int n,m;
    scanf("%d%d",&n,&m);
    int u,v;
    while(m--)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(visited[i]==0) Articulation(i,true);

    }
    int tot=0;
    for(int i=1; i<=n; i++)
    {
        if(sign[i])
        {
            tot++;
        }
    }
    printf("%d",tot);

}
