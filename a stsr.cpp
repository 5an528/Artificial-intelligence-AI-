#include<iostream>
#include<vector>
using namespace std;
vector <int> hur;
vector <int> prev;
vector <int> dist;
int nnode;
struct node
{
    int nd;
    int weight;
} temp;
vector <node>adj[100];
struct pqueue
{
    int n,dis;
    bool flag;
} Q[100];
int Qpop()
{
    int minv = 1000000,index;
    for(int i=0; i<nnode; i++)
    {
        if(Q[i].dis<minv && Q[i].flag==true)
        {
            minv = Q[i].dis;
            index = i;
        }
    }
    Q[index].flag = false;
    return index;
}
bool empty_or_not()
{
    for(int i=0; i<nnode; i++)
    {
        if(Q[i].flag==true)
        {
            return true;
        }
    }
    return false;
}
void path(int start, int dest)
{
    if(Q[dest].dis==0)
    {

    }
    else if(dest==start)
    {
        return;
    }
    else
    {
        path(start,prev[dest]);
    }
    cout<<dest<<" ";
}
void a_star_search(int src)
{
    int u;
    Q[src].dis=0;
    dist[src] = 0;
    while(empty_or_not())
    {
        u = Qpop();
        for(int i=0; i<adj[u].size(); i++)
        {
            temp = adj[u][i];
            if(dist[temp.nd]>dist[u]+temp.weight)
            {
                dist[temp.nd]=dist[u]+temp.weight;
                Q[temp.nd].dis = dist[temp.nd]+hur[temp.nd];
                prev[temp.nd] = u;
            }
        }
    }
}
int main()
{
    int n,e,u,v,w,s,dst,h;
    cin>>nnode>>e;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        temp.nd=v;
        temp.weight = w;
        adj[u].push_back(temp);
        temp.nd = v;
        adj[v].push_back(temp);
    }
    for(int i=0; i<nnode; i++)
    {
        Q[i].n=i;
        Q[i].dis = 100000;
        Q[i].flag = true;
        prev.push_back(10000);
        dist.push_back(10000);
        cout<<"Input Heuristic cost of : "<<i<<" : ";
        cin>>h;
        hur.push_back(h);
    }
    cout<<"Source & destination node :";
    cin>>s>>dst;
    a_star_search(s);
    cout<<"Path : ";
    path(s,dst);
    cout<<"\nWeight : ";
    for(int i=0; i<nnode; i++)
    {
        cout<<Q[i].dis<<" ";
    }
    cout<<endl;
}
