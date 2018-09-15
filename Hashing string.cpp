// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define maxl 1001000
#define maxp 1010000
#define p1 31
#define p2 51
using namespace std;

long long power[maxp];
long long mod1 = 1e9+9,mod2=1e9+7;
long long cum[maxl];

vector<long long>hv;
void Power_generate()
{
    power[0]=1;
    for(long long i=1; i<=maxp; i++)
    {
        power[i]= ((power[i-1])*p1 )%mod1;
    }
}

long long Hashing(char *s, long long len)
{
    long long value=0;
    cum[0]=0;
    for(int i=0; i<len; i++)
    {
        int temp= (s[i]-'A')+1;
        value= ( value+(temp*power[i]) )%mod1;
        hv.push_back(value); //  hash value of every position of a string
        cum[i+1]=value; // hash values cumulative sum of a string
    }
    return value%mod1; // hash value of total string
}


long long get(long long l,long long r)
{
    long long po=maxp-l;
    cout<<"G  "<<po<<"   "<<l<<"  "<<r<<endl;
    return ( (power[po]*(cum[r]-cum[l-1])%mod1)+mod1)%mod1;
}


long long Hash_substring(char *s, long long len)
{
   set<int> sett;
    for(int i=1; i<=len; i++)
    {
        for(int j=i; j<=len; j++)
        {
            long long val = get(i,j);
            val=val%mod1;   //cout<<"G  "<<val<<  "   "<<cum[j]<<"  "<<cum[i-1]<<endl;
            sett.insert(val); //count the number of unique substring
        }
    }
    return (long long) sett.size();
}
int main()
{
    Power_generate();
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        char s[maxl];
        scanf("%s",s);
        long long len=strlen(s);
        Hashing(s,len);
        printf("%lld\n",Hash_substring(s,len));
        int q;
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            long long l1,r1,l2,r2;
            scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
            if(get(l1,r1) == get(l2,r2)) printf("Equel\n");
            else printf("Not equel\n");
        }
    }
    return 0;
}
