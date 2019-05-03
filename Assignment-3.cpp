#include <iostream>
#include<climits>
using namespace std;

int findMinVertex(int *time,bool* visited,int n)
{
    int minVertex=-1,i;
    for(i=0;i<n;i++)
    {
        if(!visited[i]&&(minVertex==-1 || time[i]<time[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void dijkstras(int **edges,int n)
{
    int *time=new int[n];
    int i,j;
    bool *visited=new bool[n];

    for(i=0;i<n;i++)
    {
        time[i]=INT_MAX;
        visited[i]=false;
    }

    time[0]=0;

    for(i=0;i<n-1;i++)
    {
        int minVertex=findMinVertex(time,visited,n);
        visited[minVertex]=true;
        for(j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0 && !visited[j])
            {
                int dist=time[minVertex] + edges[minVertex][j];
                if(dist<time[j])
                    time[j]=dist;
            }
        }
    }
    cout<<"destination"<<"\t"<<"time"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<i<<"\t"<<time[i]<<endl;
    }
}
int main()
{
    int i,j,e,n;
    cout<<"Enter no. of airports \n";
    cin>>n;
    cout<<"Enter no. of routes \n";
    cin>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++)
        edges[i]=new int[n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        edges[i][j]=0;
    for(i=0;i<e;i++)
    {
        int s,d,time;
        cout<<"enter source\n";
        cin>>s;
        cout<<"Enter destination\n";
        cin>>d;
        cout<<"enter time for flight\n";
        cin>>time;
        edges[d][s]=time;
        edges[s][d]=time;
    }
    dijkstras(edges,n);
    return 0;
}
