#include<iostream>

using namespace std;

struct thread
{
    int data;
    int lthread,rthread;
    thread *right,*left;
}*root=NULL;

struct thread *dummy=NULL;



void create()
{
    int f=0;
    thread *curr;
    thread *nn;
    nn=new thread;
    nn->left=NULL;
    nn->right=NULL;
    nn->lthread=0;
    nn->rthread=0;
    cout<<"enter data\n";
    cin>>nn->data;
    if(root==NULL)
    {
        root=nn;
        dummy=new thread;
        dummy->data=-999;
        dummy->left=root;
        dummy->right=dummy;
        dummy->lthread=1;
        dummy->rthread=1;
        nn->left=nn->right=dummy;
    }
    else
    {
        curr=root;
        for(;;)
        {
            f=0;
            while(1)
            {
                  if(nn->data<curr->data)
                  {
                     if(!curr->left||curr->left==dummy)
                     {
                         nn->left=curr->left;
                         curr->left=nn;
                         nn->right=curr;
                         curr->lthread=1;
                         f=1;
                     }
                     else
                         curr=curr->left;
                  }
                  else if(nn->data>curr->data)
                  {
                     if(curr->right!=NULL||curr->right==dummy)
                     {
                         nn->right=curr->right;
                         curr->right=nn;
                         nn->left=curr;
                         curr->rthread=1;
                         f=1;
                     }
                     else
                        curr=curr->left;
                  }
                  if(f==1)
                    break;
            }
            if(f==1)
            break;
        }
    }

}

void inorder(thread *temp)
{

      while(temp->lthread==1)
      {
          temp=temp->left;
      }
      while(temp!=dummy)
      {
          cout<<temp->data<<"\t";
          if(temp->rthread==0)
            temp=temp->right;
          else
          {
              temp=temp->right;
              while(temp->lthread==1)
                temp=temp->left;
          }
      }
}
int main()
{
    char ch='y';
    int p;
    while(ch=='y')
    {
        cout<<"MENU\n 1.create\n 2.inorder\n";
        cin>>p;
        switch(p)
        {
            case 1:create();
            break;
            case 2:inorder(root);
            break;
        }
        cout<<"do you want to continue\n";
        cin>>ch;
    }
    return 0;
}
