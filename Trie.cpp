// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define maxi 1020
using namespace std;
int state;
struct node
{
    int cnt,length,path[65];
    bool endmark;
    void initialize()
    {
        endmark=false;
        memset(path,0,sizeof path);
    }
} Tree[maxi];

void insert(string &s, int &len)
{
    int curr=0;
    for(int i=0; i<len; i++)
    {
        int ch=s[i]-'A';
        if( Tree[curr].path[ch] )
        {
            curr=Tree[curr].path[ch];
        }
        else
        {
            Tree[curr].path[ch]= ++state;
            Tree[state].length = Tree[curr].length+1;
            Tree[state].initialize();
            curr=state;
        }
    }
    Tree[curr].endmark=true;
    Tree[curr].cnt++;
}

bool search(string &ss, int &len )
{
    int curr=0;
    for(int i=0; i<len; i++)
    {
        int ch=ss[i]-'A';
        if( !Tree[curr].path[ch] ) return false;
        curr=Tree[curr].path[ch];
    }
    return Tree[curr].endmark;
}

int main()
{
    int n,q;
    while( scanf("%d",&n)==1 )
    {
        getchar();
        for(int i=0; i<n; i++)
        {
            string s;
            getline(cin,s);
            int len=(int)s.size();
            insert(s,len);
        }
        scanf("%d",&q);
        getchar();
        for(int i=0; i<q; i++)
        {
            string ss;
            getline(cin,ss);
            int len=(int)ss.size();
            if( search(ss,len) ) printf("Found\n");
            else printf("Not Found\n");
        }
    }
    return 0;
}
