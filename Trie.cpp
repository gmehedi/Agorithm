// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define maxl 1020
using namespace std;
int state;
struct node
{
    int cnt=0,length=0;
    node* next[65];
    bool endmark;
    node()
    {
        endmark=false;
        for(int i=0; i<=52; i++) next[i]=NULL;
    }

} *Tree;

void insertt(string s, int len)
{
    node* curr=Tree;
    for(int i=0; i<len; i++)
    {
        int path=0;
        if(s[i]>='a' &&s[i]<='z') path=( (int)s[i]-'a'); // 0 to 25
        else path=( (int)s[i]-'A')+26; // 26 to start

        if(curr->next[path] == NULL)
        {
            curr->next[path]=new node();
            curr=curr->next[path];
            curr->length= i+1;

        }
        else curr=curr->next[path];
    }
    curr->endmark=true;
    curr->cnt++;
}

bool searching(string s, int len )
{
    node *curr=Tree;
    for(int i=0; i<len; i++)
    {
        int path=0;
        if(s[i]>='a' &&s[i]<='z') path=( (int)s[i]-'a'); //0 to 25
        else path=( (int)s[i]-'A')+26; // 26 to start

        if( curr->next[path] == NULL ) return false;
        else  curr=curr->next[path];
    }
    if(curr->endmark)
    {
        cout<<"Length  "<<curr->length<<endl;
        cout<<"Total  has "<<curr->cnt<<endl;
    }
    return curr->endmark;
}

int del(node *curr)
{
    for(int i=0; i<=52; i++)
        if(curr->next[i] != NULL) del(curr->next[i]);
    delete(curr);
}
int main()
{
    int n,q;
    while( scanf("%d",&n)==1 )
    {
        getchar();
        Tree= new node();
        for(int i=0; i<n; i++)
        {
            string s;
            getline(cin,s);
            int len=(int)s.size();
            insertt(s,len);
        }
        scanf("%d ",&q);

        for(int i=0; i<q; i++)
        {
            string s;
            getline(cin,s);
            int len=(int)s.size();
            if( searching(s,len) ) printf("Found\n");
            else printf("Not Found\n");
        }
        del(Tree);
    }
    return 0;
}
