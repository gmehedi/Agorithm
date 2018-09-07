//M M Mehedi Hasan
//From BUBT
#include <bits/stdc++.h>
using namespace std;

int* prefix_kmp(string &s2)
{
    int j=0;
    int len= (int)s2.size();
    int* phi=new int[len];
    phi[0]=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && s2[i] != s2[j]) j=phi[j-1];
        if(s2[i] == s2[j]) j++;
        phi[i]=j;
    }

   // for(int i=0; i<len; i++) cout<<phi[i]<<" ";
    return phi;
}

bool kmp(string &s1, string &s2)
{
    int* phi= prefix_kmp(s2);
    int j=0;
    int len1=(int)s1.size(), len2=(int)s2.size();
    for(int i=0; i<len1 && j<len2; i++)
    {
        while(j>0 && s1[i] != s2[j] ) j=phi[j-1];
        if(s1[i] == s2[j]) j++;
        if(len2 == j) return true;
    }
    return false;
}
int main()
{
    int q;
    string s1,s2;
    cin>>s1>>q;
    for(int i=0; i<q; i++)
    {
        cin>>s2;
        if( kmp( s1,s2 ) ) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
