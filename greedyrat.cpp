#include<iostream>
#include<math.h>
using namespace std;
int adj[20][20];
int col[100][100] ;
int tmpy = 0 ;
pair <float,int> qarr[3];
struct some
{
    float val;
    int ssi,ssj;
} var[5];
void minh(some arr[])
{
    int tmp;
    for(int i=0; i<4; i++)
    {
        qarr[i].first = arr[i].val;
        qarr[i].second = i;
    }
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            if(qarr[i].first>qarr[j].first)
            {
                tmp = qarr[i].first;
                qarr[i].first = qarr[j].first;
                qarr[j].first = tmp;
                qarr[i].second = j;
            }
        }
    }
    for(int i=0; i<4; i++)
    {
        cout<<"Qarr "<<i<<" "<<qarr[i].second<<" ";

    }
    cout<<endl;
//    float mn = 100000;
//    int index;
//    for(int i=0; i<4; i++)
//    {
//        if(mn>arr[i].val && arr[i].flag==true)
//        {
//            mn = arr[i].val;
//            index = i;
//        }
//    }
//    return index;
}
void can_it_reach(int si,int sj,int di,int dj)
{
    cout<<si<<" "<<sj<<" "<<di<<" "<<dj<<endl;
    if(si==di && sj==dj)
    {
        cout<<"Reached";
        return;
    }
    col[si][sj] = 1;
    var[0].val = sqrt((si-di)*(si-di)+(sj+1-dj)*(sj+1-dj));
    var[0].ssi = si;
    var[0].ssj = sj+1;
    var[1].val = sqrt((si-di)*(si-di)+(sj-1-dj)*(sj-1-dj));
    var[1].ssi = si;
    var[1].ssj = sj-1;
    var[2].val = sqrt((si+1-di)*(si+1-di)+(sj-dj)*(sj-dj));
    var[2].ssi = si+1;
    var[2].ssj = sj;
    var[3].val = sqrt((si-1-di)*(si-1-di)+(sj-dj)*(sj-dj));
    var[3].ssi = si-1;
    var[3].ssj = sj;
    for(int i=0; i<4; i++)
    {
        cout<<"Hur "<<i<<" "<<var[i].val<<" ";

    }
    cout<<endl;


    int minv =0;
    minh(var);

    for(int i=0; i<4; i++)
    {
        cout<<adj[var[qarr[i].second].ssi][var[qarr[i].second].ssj]<<" adj\n";
        if(adj[var[qarr[i].second].ssi][var[qarr[i].second].ssj]!=1)
        {
            var[i].val = 100000;
            cout<<var[i].val<<" in"<<endl;
        }
        cout<<var[i].val<<endl;
    }
    cout<<endl;

    cout<<"ssi "<<var[qarr[0].second].ssi<<" "<<"ssj "<<var[qarr[0].second].ssj<<"\n";
    cout<<"minv "<<minv<<endl;
    if(adj[var[qarr[0].second].ssi][var[qarr[0].second].ssj]==1 && col[var[qarr[0].second].ssi][var[qarr[0].second].ssj]==0)
    {

        can_it_reach(var[qarr[0].second].ssi,var[qarr[0].second].ssj,di,dj);
        cout<<"1done\n";
    }

    if(adj[var[qarr[1].second].ssi][var[qarr[1].second].ssj]==1 && col[var[qarr[1].second].ssi][var[qarr[1].second].ssj]==0)
    {

        can_it_reach(var[qarr[1].second].ssi,var[qarr[1].second].ssj,di,dj);
    }

    if(adj[var[qarr[2].second].ssi][var[qarr[2].second].ssj]==1 && col[var[qarr[2].second].ssi][var[qarr[2].second].ssj]==0)
    {

        can_it_reach(var[qarr[2].second].ssi,var[qarr[2].second].ssj,di,dj);
    }

    if(adj[var[qarr[3].second].ssi][var[qarr[3].second].ssj]==1 && col[var[qarr[3].second].ssi][var[qarr[3].second].ssj]==0)
    {
        can_it_reach(var[qarr[3].second].ssi,var[qarr[3].second].ssj,di,dj);
    }
}
int main()
{
    int node,edge,u,v,si,sj,di,dj;
    cin>>node>>edge;
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<edge; j++)
        {
            cin>>u;
            adj[i][j]=u;
        }

    }
    cin>>si>>sj>>di>>dj;
    can_it_reach(si,sj,di,dj);
}
