#include<bits/stdc++.h>
#define mod 1000000007
#define maxl 2
#define ll long long
using namespace std;


struct matrix
{
    ll a[maxl][maxl];
    matrix()
    {
        memset(a,0,sizeof a);
    }
    void init()
    {
        a[0][0]=1, a[0][1]=1;
        a[1][0]=1, a[1][1]=0;
    }

    matrix operator* ( matrix temp )
    {
        matrix res;
        for(int i=0; i<maxl; i++)
        {
            for(int j=0; j<maxl; j++)
            {
                res.a[i][j]=0;
                for(int k=0; k<maxl; k++)
                {
                    res.a[i][j] =( res.a[i][j]+ (temp.a[i][k]*a[k][j]) )%mod;
                }
            }
        }
        return res;
    }

};

matrix Power(matrix mat, ll n)
{
    if(n == 1) return mat;

    matrix res = Power(mat,n/2);
    res = res*res;

    if( (n%2) == 1 ) res= res*mat;

    return res;
}

ll Matrix_Expo(matrix mat, ll n)
{
    matrix res = Power(mat,n);
    return res.a[0][0];
}

int main()
{
    ll n;
    struct matrix mat;
    mat.init();
    while( scanf("%lld",&n) != EOF )
    {
        printf("%lld\n",Power(mat,n-1));
    }
    return 0;
}
