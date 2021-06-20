#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>g[100];
queue<int>Q;

int d[100],col[100],par[100],f[100],time;

void DFS_Visit(int u)
{
    col[u]=2;
    time=time+1;
    d[u]=time;
    for(int i=0;i<g[u].size();i++)
    {
        if(col[i]==1)
        {
            par[i]=u;
            DFS_Visit(i);
        }
    }

    col[u]=3;
    time=time+1;
    f[u]=time;
}

int main()
{
    int node,edge,u,v,source;

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);//for undirected graph
    }

    for(int i=0;i<node;i++)
    {
        d[i]=-1;
        col[i]=1;
        par[i]=-1;
        f[i]=-1;
    }
    time=0;
    for(int i=0;i<node;i++)
    {
        if(col[i]==1)
        {
            DFS_Visit(i);
        }
    }

    cout<<"The Results are : "<<endl;
    cout<<"Node  Color  D.Time  Parent   F.Time"<<endl;
    for(int i=0;i<node;i++)
    {
        cout<<i<<"       "<<col[i]<<"      "<<d[i]<<"        "<<par[i]<<"      "<<f[i]<<endl;
    }
}
