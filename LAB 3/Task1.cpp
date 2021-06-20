#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>g[100];
queue<int>Q;

int d[100],col[100],par[100],f[100],time,limi,source,destination;

bool fu = false;

bool DFS_Visit(int u,int des, int l)
{
    bool r;
    if(u==des)
        return true;
    if(l<=0)
        return false;

    col[u]=2;
    time=time+1;
    d[u]=time;
    for(int i=0;i<g[u].size();i++)
    {
        int k =g[u][i];
        r=DFS_Visit(k,des,l-1);
        if(r)fu=true;
    }

    col[u]=3;
    time=time+1;
    f[u]=time;
    return fu;
}

int main()
{
    int node,edge,u,v;

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<node;i++)
    {
        d[i]=-1;
        col[i]=1;
        par[i]=-1;
        f[i]=-1;
    }
    time=0;

    cout<<endl<<endl<<"Input your source Node --> ";
    cin>>source;
    cout<<endl<<"Input your Destination Node --> ";
    cin>>destination;
    cout<<endl<<"Input your Limit Node --> ";
    cin>>limi;

    bool flag = DFS_Visit(source,destination,limi);

    if(flag==true)
        cout<<endl<<"Path is available"<<endl;
    else
        cout<<endl<<"Path is not available"<<endl;
}
