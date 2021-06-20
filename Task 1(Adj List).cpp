#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>g[100];


int main()
{
    int node,edge,u,v,source;

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;
    for(int i = 0; i<node; i++)
    {
        cout<<"Neighbor of "<<i<<" --> ";
        for(int j = 0; j<g[i].size(); j++)
        {
            v=g[i][j];
            cout<<v<<" ";
        }
        cout<<endl;
    }
}
