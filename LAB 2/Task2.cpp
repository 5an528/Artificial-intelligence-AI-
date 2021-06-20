#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>g[100];
queue<int>Q;

int d[100], col[100], par[100];

int main()
{
    int node,edge,u,v,source,destination1,destination2,flag=0,flag2=0;

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)//loop for getting edge
    {
        cin>>u>>v;
        g[u].push_back(v);//u to v edge
        g[v].push_back(u);// v to u edge (undirected graph)
    }

    for(int i = 0; i < node; i++)//loop for initializing
    {
        d[i]=-1;//inf. distance
        col[i]=0;//0 for white
        par[i]=-1;//null parent
    }

    cout<<"Enter Your Source Node A: ";
    cin>>destination1;
    cout<<"Enter the destination node B: ";
    cin>>destination2;
    cout<<"Enter the destination node C: ";
    cin>>source;

    col[source]=1;//1 is for gray
    d[source]=0;//no distance for source node
    Q.push(source);//source pushed in the queue

    while(!Q.empty())//loop for BFS
    {
        u=Q.front();//first node saved from the queue
        Q.pop();//pop the first node of the queue

        for(int i=0;i<g[u].size();i++)//loop for neighbor check
        {
            v=g[u][i];//neighbor saved for the queue
            if(col[v]==0)//if the neighbor color is white
            {
                col[v]=1;//1 is for gray
                d[v]=d[u]+1;//parent node distance plus one for defined one
                par[v]=u;//previous node is the parent of the neighbor
                Q.push(v);//node pushed in the queue
            }
            col[u]=2; //2 is for Black
        }
    }


    cout<<endl<<destination1<<" -> ";
    while(destination1!=source)
    {
        cout<<par[destination1]<<" -> ";
        destination1=par[destination1];
        flag++;
    }

    cout<<endl<<endl<<destination2<<" -> ";
    while(destination2!=source)
    {
        cout<<par[destination2]<<" -> ";
        destination2=par[destination2];
        flag2++;
    }

    if(flag<flag2)
        cout<<endl<<endl<<"NODE A is Closer to Node C";
    else
        cout<<endl<<endl<<"NODE B is Closer to Node C";
}
