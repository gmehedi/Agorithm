//M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define maxi 100000
#define sz 17  //log2(maxi)
using namespace std;

int level[maxi],parent[maxi],table[sz][maxi],n,m;
bool sign[maxi];
vector<int>g[maxi];
void bfs(int s)
{
    sign[s]=false;
    level[s]=1;
    parent[s]=-1;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i=0; i<(int)g[f].size(); i++)
        {
            int v=g[f][i];
            if(sign[v])
            {
                q.push(v);
                sign[v]=false;
                level[v]=level[f]+1;
                parent[v]=f;
            }
        }
    }
}

void bfs()
{
    memset(sign,true,sizeof sign);
    for(int i=1; i<=n; i++)
    {
        if(sign[i]) bfs(i);
    }
}

void build_table()
{
    for(int p=0; p<=sz; p++)
    {
        for(int i=1; i<=n; i++) //node
        {
            if(p==0) { table[p][i]=parent[i]; continue; }
        //     cout<<"P  "<<table[p-1][i]<<endl;
            if( table[p-1][i] != -1 ) table[p][i]= table[p-1][table[p-1][i]];

        }
    }
}

int Lowest_common_ancestor(int u, int v)
{
    if(level[u]>level[v]) swap(u,v); // we want to choose minimum level for u
    // Now we need to equel the level u and v node
    for(int i=sz; i>=0; i--)
    {
        int x=table[i][v];
        if( level[x]==level[u] ){ v=x; break;  }
        if(level[x]>level[u]) v=x;
    }
    if(u==v) return u;
    // find the common nearest node
    for(int i=sz; i>=0; i--)
    {
        int u1 = table[i][u];
        int v1 = table[i][v];
        if( u1 != v1)  u=u1, v=v1;
    }
    return parent[u];

}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    //for(int i=1; i<=n; i++) cout<<"P  "<<i<<"   "<<parent[i]<<"  "<<level[i]<<endl;
    build_table();

    int q;
    scanf("%d",&q);

    for(int i=0; i<q; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        cout<<Lowest_common_ancestor(u,v)<<endl;
    }
    return 0;
}
