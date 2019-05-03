#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};
struct node *head5=NULL;
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
struct node *head4=NULL;


void create();
void s_insert();
void s_delete();
void s_search();
void intersection();
void s_union();
void display( node *head);
void difference();
int main()
{
    int n;
    char ch='y';
    while(ch=='y')
    {
        cout<<"MENU\n 1. create\n 2. s_insert\n 3. delete\n 4. search\n 5. intersection\n 6. union\n 7.difference\n";
        cin>>n;
        switch(n)
        {
            case 1: create();
            break;
            case 2: s_insert();
            break;
            case 3: s_delete();
            break;
            case 4: s_search();
            break;
            case 5: intersection();
            break;
            case 6: s_union();
            break;
            case 7:difference();
            break;
        }
        cout<<"do you want to continue\n";
        cin>>ch;
    }
return 0;
}

void create()
{
    int p,n,i;
    node *nn;
    cout<<"enter set in which you want to add\n ";
    cin>>p;
    if(p==1)
    {
        cout<<"how many elements you want to add";
        cin>>n;

        for(i=0;i<n;i++)
        {
            nn=new node;
            nn->next=NULL;
            cout<<"enter data to be entered in set\n";
            cin>>nn->data;
            if (head1==NULL)
            {
                head1=nn;
            }
            else
            {
               nn->next=head1;
               head1=nn;
            }
        }
        display(head1);
    }
    else
    {
        cout<<"how many elements you want to add";
        cin>>n;
        for(i=0;i<n;i++)
        {
            nn=new node;
            nn->next=NULL;
            cout<<"enter data to be entered in set\n";
            cin>>nn->data;
            if (head2==NULL)
            {
                head2=nn;
            }
            else
            {
               nn->next=head2;
               head2=nn;
            }
        }
        display(head2);
    }
}
void display( node *head)
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}
void s_insert()
{
   int p;
   node *nn;
   nn=new node;
   nn->next=NULL;
   cout<<"enter data to be entered in set\n";
   cin>>nn->data;
   cout<<"enter set number in which you want to add\n";
   cin>>p;
   if(p==1)
   {
      nn->next=head1;
      head1=nn;
   }
   else
   {
       nn->next=head2;
       head2=nn;
   }
   display(head1);
   cout<<endl;
   display(head2);
}
void s_delete()
{
    node *temp,*prev;
    int p,n;
    cout<<"enter number you want to delete";
    cin>>n;
    cout<<"enter set number in which you want to delete\n";
    cin>>p;
    if(p==1)
    {
        temp=head1;
        while(temp->data!=n)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete (temp);
        display(head1);
    }
    else
    {
        temp=head2;
        while(temp->data!=n)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete (temp);
        display(head2);
    }
}
void s_search()
{
    int n,p,f=0;
    node *temp;
    cout<<"enter number you want to search\n";
    cin>>n;
    cout<<"enter set number\n";
    cin>>p;
    if(p==1)
    {
        temp=head1;
        while(temp->next!=NULL)
        {
            if(temp->data==n)
            {
                f=1;
                break;

            }
            temp=temp->next;
        }
    }
    else
    {
       temp=head2;
        while(temp->next!=NULL)
        {
            if(temp->data==n)
            {
                f=1;
                break;
            }
            temp=temp->next;
        }
    }
    if(f==1)
            cout<<"found";
    else
            cout<<"not found\n";
}

void intersection()
{
  node *temp1,*temp2,*nn;
  temp1=head1;
  while(temp1!=NULL)
  {
   temp2=head2;
  while(temp2!=NULL)
  {
    if(temp1->data==temp2->data)
    {

	nn=new node;
	nn->next=NULL;
	nn->data=temp1->data;
	if (head3==NULL)
        {
            head3=nn;
        }
        else
        {
           nn->next=head3;
           head3=nn;
        }
     }
     temp2=temp2->next;
   }
   temp1=temp1->next;
  }
  display(head3);
}

void s_union()
{
  int f=0;
  node *nn,*temp1,*temp2;
  temp1=head1;
  while(temp1!=NULL)
  {
    nn=new node;
    nn->next=NULL;
    nn->data=temp1->data;
    if (head4==NULL)
    {

        head4=nn;
    }
    else
    {
       nn->next=head4;
       head4=nn;
    }
   temp1=temp1->next;
  }
    temp2=head2;
    while(temp2!=NULL)
    {
        temp1=head1;
        while(temp1!=NULL)
        {
            if(temp2->data==temp1->data)
            {
                f=1;
            }
            temp1=temp1->next;
        }
        if(f==0)
        {
            nn=new node;
            nn->next=NULL;
            nn->data=temp2->data;
            nn->next=head4;
            head4=nn;
        }
        temp2=temp2->next;
    }
   display(head4);
}

void difference()
{
    int f=0,d=0;
    node *temp1,*temp2,*nn;
    temp1=head1;
    while(temp1!=NULL)
    {
        f=0;
        temp2=head2;
        while(temp2!=NULL)
        {
            if(temp2->data==temp1->data)
            {
                f=1;
            }
            temp2=temp2->next;
        }
        if(f==0)
        {
           nn=new node;
            nn->next=NULL;
            nn->data=temp1->data;
            if (head5==NULL)
            {
             head5=nn;
            }
            else
            {
               nn->next=head5;
               head5=nn;
            }
            d++;
        }
        temp1=temp1->next;
    }
    cout<<d;
    display(head5);
}





