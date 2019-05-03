#include <iostream>

using namespace std;

class Edge
{
public :
    int source,dest,weight;
};
bool compare(Edge E1,Edge E2)
{
    return E1.weight<E2.weight;
}
void kruskals(Edge *input;int n,int E)
{
    sort(input,input+E,compare)
}
int main()
{
    int i,j,e,n;
    cout<<"Enter no. of vertices \n";
    cin>>n;
    cout<<"Enter no. of edges \n";
    cin>>e;
    Edge *input =new Edge[e];

    for(i=0;i<e;i++)
    {
        int s,d,weight;
        cout<<"enter source vertex \n";
        cin>>input[i].s;
        cout<<"Enter destination vertex \n";
        cin>>input[i].d;
        cout<<"enter the weight \n";
        cin>>input[i].weight;
    }
    kruskals(edges,n,e);
    return 0;
}
