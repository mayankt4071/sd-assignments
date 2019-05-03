#include<iostream>
using namespace std;
void heapsort(int *marks,int n);
void build_maxheap(int *marks,int n);
void heapify(int* marks,int n,int largest);
int main()

    int n;
    cout<<"enter number of students\n";
    cin>>n;
    int *marks=new int[n];
    cout<<"enter marks of students\n";
    for(int i=0;i<n;i++)
        cin>>marks[i];
    heapsort(marks,n);
    cout<<"largest"<<marks[0];
    cout<<"smallest"<<marks[n];

}
void heapsort(int *marks,int n)
{
    build_maxheap(marks,n);
    for(int i=n;i>1;i--)
    {
        swap(marks[1],marks[i]);
        heapify(marks,i,1);
    }

}
void build_maxheap(int *marks,int n)
{
    int i;
    for( i=n/2;i<=1;i--)
        heapify(marks,n,i);
}
void heapify(int* marks,int n,int largest)
{
    int i=largest;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&marks[l]>marks[largest])
        largest=l;
    else if(r<n&&marks[r]>marks[largest])
        largest=r;
    if(largest!=i)
    {
        swap(marks[i],marks[largest]);
        heapify(marks,n,largest);
    }
}
