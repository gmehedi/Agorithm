#include <bits/stdc++.h>
#define pii              pair <ull,int>
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
#define maxl 1000001
#define psz 20
using namespace std;

struct str
{
    ll sum;
    ll prop;
}
tree[maxl*4LL+2LL];

void Prop(ll node, ll s, ll e)
{
    //cout<<"E  "<<s<<"  "<<e<<"  "<<e-s+1<<"   "<<tree[node].prop<<endl;
    tree[node].sum += (e-s+1LL)*tree[node].prop;
    if(s == e)
    {
        tree[node].prop=0LL;
        return;
    }

    tree[node*2LL].prop+=tree[node].prop;

    tree[(node*2LL)+1LL].prop+=tree[node].prop;
    tree[node].prop=0LL;
    //cout<<"SS  "<<tree[node].sum<<endl;
    return;

}

void Build(ll node, ll s, ll e)
{
    if(s == e) { tree[node].sum=0LL, tree[node].prop=0LL; return; }
    ll mid = (s+e)/2LL;

    Build(node*2LL,s,mid);
    Build((node*2LL)+1LL,mid+1LL,e);

    tree[node].sum=0LL, tree[node].prop=0LL;
}

void Update(ll node, ll s, ll e, ll i, ll j, ll prop)
{
    if(tree[node].prop != 0LL)
    {
        Prop(node,s,e);
    }
    if(s>j || e<i) return;
    if(s>=i && e<=j)
    {
        tree[node].prop = prop;
        Prop(node,s,e);
        return;
    }
    ll mid = (e+s)/2LL;

    Update(node*2LL,s,mid,i,j,prop);
    Update((node*2LL)+1LL,mid+1LL,e,i,j,prop);

    tree[node].sum=tree[node*2LL].sum+tree[(node*2LL)+1LL].sum;
}

ll Qry(ll node, ll s, ll e, ll i, ll j)
{
    if(tree[node].prop != 0LL) 
    {
        Prop(node,s,e);
    }
    if(s>j || e<i) return 0LL;
    if(s>=i && e<=j)
    {
        return tree[node].sum;
    }
    ll mid = (e+s)/2LL;
    ll p1 = Qry(node*2LL,s,mid,i,j);
    ll p2 = Qry((node*2LL)+1LL,mid+1LL,e,i,j);

    tree[node].sum = tree[node*2LL].sum+tree[(node*2LL)+1LL].sum;

    return(p1+p2);
}

int  main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        Build(1LL,1LL,maxl);
        ll n,c,l,r;
        scanf("%lld %lld",&n,&c);

        while(c--)
        {
            int types;
            scanf("%d %lld %lld",&types,&l,&r);
           // l++,r++;
            if(types)
            {
                printf("%lld\n",Qry(1LL,1LL,maxl,l,r));
            }
            else
            {
                ll val;
                scanf("%lld",&val);
                Update(1LL,1LL,maxl,l,r,val);
            }

        }
    }

    return 0;
}
