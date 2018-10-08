

#include<bits/stdc++.h>
#define maxl 10000
#define ll long long
#define ull unsigned long long
using namespace std;

ull dp[maxl][maxl];
ull binomialCoeff(ull n, ull k)
{
  if (k==0 || k==n)  return 1;
  if(dp[n][k] != -1) return dp[n][k];

  return dp[n][k]= binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);

}

int main()
{
    ull n, k;
    memset(dp,-1,sizeof dp);
    while(scanf("%lld %lld",&n,&k)==2)
    {
        printf("Value of C(%lld, %lld) is %lld ", n, k, binomialCoeff(n, k));
    }
    return 0;
}
