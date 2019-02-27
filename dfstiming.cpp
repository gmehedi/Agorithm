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

int n,t=1;
struct str
{
    int start;
    int endd;
}
dfst[maxl+2];
int level[maxl+1];
int parent[maxl+1];
vector<int>v[maxl+1];
bool sign[maxl+2];

void DFS(int u, int lev)
{
    dfst[u].start=t;
    level[u]=lev;
 //   cout<<"EEE   "<<dfst[u].start<<endl;
    sign[u]=false;

    for (int i = 0; i < v[u].size(); ++i)
    {
        int v1=v[u][i];
        if(sign[v1])
        {
            t++;
            parent[v1]=u;
            DFS(v1,lev+1);
            dfst[v1].endd=t;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i < n; ++i)
    {
       int u1,v1;
       scanf("%d %d",&u1,&v1);
       v[u1].pb(v1);
       v[v1].pb(u1);
    }

    memset(sign,true,sizeof sign);
    DFS(1,1);
    dfst[1].endd=t;
    for(int i=1; i<=n; i++) cout<<dfst[i].start<<"  "<<dfst[i].endd<<endl;
    return 0;
}
