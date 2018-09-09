
#include <bits/stdc++.h>
#define szz 2010
using namespace std;
int phi[szz];
int cnt[szz]={0};
int prefix_kmp(string &s2)
{
    int j=0;
    int len= (int)s2.size();
    cnt[0]=phi[0]=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && s2[i] != s2[j]) j=phi[j-1];
        if(s2[i] == s2[j]) j++;
        phi[i]=j;
    }
    cout<<"PHI   ";
    for(int i=0; i<len; i++) cout<<phi[i]<<" ";
    cout<<endl;
}

long long kmp(string &s1, string &s2)
{
    long long total=0;
    prefix_kmp(s2);
    int j=0;
    int len1=(int)s1.size(), len2=(i     nt)s2.size();
    for(int i=0; i<len1; i++)
    {
        while(j>0 && s1[i] != s2[j] ) j=phi[j-1];

        if(s1[i] == s2[j]) cnt[j]+=1, j++;
    }
    cout<<"CNT  ";
    for(int i=0; i<len1; i++) cout<<cnt[i]<<" ";
    cout<<endl;
    for(int i=len2-1; i>=0; i--)
    {
        int ind=phi[i];
        if(ind != -1)
        cnt[ind-1]+=cnt[i];
    }
    for(int i=0; i<len1; i++) total+=cnt[i], cout<<"C  "<<cnt[i]<<endl;
    return total;
}
int main()
{
    int q;
    string s1,s2;
    while( cin>>s1>>s2)
    {
          memset(cnt,0,sizeof cnt);
          cout<<kmp( s1,s2 )<<endl;
    }
    return 0;
}
