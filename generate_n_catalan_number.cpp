

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

ull catalan(ull n)
{
    ull c = binomialCoeff(2*n, n);
    return c/(n+1);
}

int main()
{
    memset(dp,-1,sizeof dp);
    for (ull i = 0; i < 100; i++)
    {
        cout << catalan(i) << " ";
    }

    return 0;
}
