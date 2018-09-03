
//M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define maxi 100000
#define sz 17  //log2(maxi)
using namespace std;
int n,a[maxi],sparse_table[sz][maxi];

void built_sparse_table()
{
    for(int i=0; i<n; i++) sparse_table[0][i]=a[i]; // initialize for 2^0 or 1 length

    for(int p=1; (1<<p)<n; p++) // 1 to max power
    {
        for(int i=0; i+(1<<p)<=n; i++) // from column i to  2^p length
        {
            int val1 = sparse_table[p-1][i];
            int val2 = sparse_table[p-1][i+(1<<p-1)];
            sparse_table[p][i]=max(val1,val2);
        }
    }

}

int Queary(int i, int j)
{
    int p=log2(j-i+1);

    int val1 = sparse_table[p][i];
    int val2 = sparse_table[p][j-(1<<p)+1];

    return max(val1,val2);
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    built_sparse_table();

    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        int from,to;
        scanf("%d %d",&from,&to);
        printf("The max value from %d to %d is %d\n",from,to,Queary(from-1,to-1));
    }

    return 0;
}
