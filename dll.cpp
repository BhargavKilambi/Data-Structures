#include<iostream>

using namespace std;

class node
{
   public:
   int data;
   node *rlink;
   node *llink;
};

class linkedlist
{
   public:
  node *head;

  linkedlist()
{  head=NULL;}

void ins_front(int x)
{
  node *p = new node();

p->data=x;
  p->rlink=NULL;

if(head==NULL)
{head=p;}
else
{
  p->rlink=head;
  head=p;
}
}

void ins_end(int x)
{
  node *ptr = head;
  node *p = new node();

  while(ptr->rlink!=NULL)
{
   ptr=ptr->rlink;}
ptr->rlink=p;
p->llink=ptr;

  p->rlink=NULL;
  p->data=x;
}

void ins_pos(int n,int x)
{
  int i=0;
  node *p=new node();
  node *ptr=head;

  while(i<n-1)
 {
    ptr=ptr->rlink;
     i++;}

 p->rlink=ptr->rlink;
 p->llink=ptr;

  ptr->rlink->llink=p;
  ptr->rlink=p;

  p->data=x;
}

void disp()
{
  node *ptr=head;

  while(ptr!=NULL)
{
   cout<<ptr->data<<endl;
   ptr=ptr->rlink;
}
}
};

int main()
{
  int i=0,n,m,x;

  cout<<"Enter the number of elements:";
  cin>>n;

  linkedlist ll;
  cout<<"Enter the elements:"<<endl;
  cin>>x;
  ll.ins_front(x);
  cout<<"Added\n";
  for(i=0;i<n-1;i++)
 {
   cout<<"Enter:";
   cin>>x;
   ll.ins_end(x);
    cout<<"Added"<<endl;}

 cout<<"The elements are:\n";
  ll.disp();

  cout<<"Position:";
  cin>>m;
  cout<<"Enter value:";
  cin>>x;
ll.ins_pos(m,x);

 cout<<"The elements are:\n";
ll.disp();

}










