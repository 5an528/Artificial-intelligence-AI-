#include<iostream>
using namespace std;
int rowsum[5]= {0};
int csum[5]= {0},i,j;
int a[100][100];
int q[100][100];
int y,z;
void qmatrix()
{
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            rowsum[i]=rowsum[i]+a[i][j];
            csum[i]=csum[i]+a[j][i];
        }
        cout<<"S"<<i<<" "<<rowsum[i]<<" "<<csum[i]<<endl;
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(i==j)
                q[i][j]=0;
            else
                q[i][j]=(5-2)*a[i][j] - rowsum[i]-csum[j];
        }
    }
    cout<<endl;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            cout<<q[i][j]<<" ";
        }
        cout<<"\n";
    }
    int minvalue=0;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(minvalue>q[i][j])
            {
                minvalue=q[i][j];
                y=i;
                z=j;
            }
        }
    }
    cout<<endl<<"min value is "<<minvalue<<" seq position -> S"<<y<<" S"<<z<<endl;

}

int main()
{
    int n;
    cout<<"Enter size of the matrix -> ";
    cin>>n;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
        for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    qmatrix();

}

