#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int siz,n,m,grid[100][100],source1,source2,des1,des2,col[100][100];
struct p
{
    int x,y;
}temp,temp2,temp3,temp4;

queue<p>Q;
p par[100][100];

void BFS (int s1, int s2)
{
    col[s1][s2] = 1 ;
    temp.x = s1 ;
    temp.y = s2 ;
    Q.push(temp) ;

    while(!Q.empty())
    {
        temp = Q.front() ;
        Q.pop() ;
        int i = temp.x ;
        int j = temp.y ;

        if(i-1 >=0 &&col[i-1][j] == 0 && grid[i-1][j] == 1){
            col[i-1][j] = 1 ;
            par[i-1][j] = temp ;
            temp2.x = i-1 ;
            temp2.y = j ;
            Q.push(temp2) ;

        }
        if(i+1 < n &&col[i+1][j] == 0 && grid[i+1][j] == 1){
            col[i+1][j] = 1 ;
            par[i+1][j] = temp ;
            temp2.x = i+1 ;
            temp2.y = j ;
            Q.push(temp2) ;

        }

        if(j-1 >=0 &&col[i][j-1] == 0 && grid[i][j-1] == 1){
            col[i][j-1] = 1 ;
            par[i][j-1] = temp ;
            temp2.x = i ;
            temp2.y = j-1 ;
            Q.push(temp2) ;

        }

        if(j+1 < m &&col[i][j+1] == 0 && grid[i][j+1] == 1){
            col[i][j+1] = 1 ;
            par[i][j+1] = temp ;
            temp2.x = i ;
            temp2.y = j+1 ;
            Q.push(temp2) ;

        }


    }

}

void path(int d1, int d2, int st1, int st2)
{
    temp3.x = d1 ;
    temp3.y = d2 ;
    temp4.x = st1;
    temp4.y = st2;
    while(1)
    {
        if(temp3.x==temp4.x && temp3.y==temp4.y)
            {
                cout<<temp3.x<<" "<<temp3.y<<endl;
                break;
            }
        cout<<temp3.x<<" "<<temp3.y<<endl;
        temp3=par[temp3.x][temp3.y];
    }
}

int main()
{
    cout<<"Input the 2D graph size -> ";
    cin>>siz;
    cout<<endl;
    for(int i=0;i<siz;i++)
    {
        for(int j = 0; j<siz ; j++)
        {
            grid[i][j]=0;
            col[i][j] = 0 ;
        }
    }
    cout<<endl<<endl<<"Input the graph -> "<<endl;
    while(1)
    {
        cin>>n>>m;
        grid[n][m]=1;
        if(n==5&&m==5)
            break;
    }
    cout<<endl<<endl<<"Input your Source -> ";
    cin>>source1>>source2;
    cout<<endl<<endl<<"Input your Destination -> ";
    cin>>des1>>des2;

    for(int i=0;i<siz;i++)
    {
        for(int j = 0; j<siz ; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl<<"your Source -> "<<source1<<" "<<source2;
    cout<<endl<<endl<<"your Destination -> "<<des1<<" "<<des2;


    BFS(source1,source2);
    cout<<endl<<endl<<endl<<"For Path --> "<<endl;
    path(des1,des2,source1,source2);


}

