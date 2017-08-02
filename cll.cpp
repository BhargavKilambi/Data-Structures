#include<iostream>

using namespace std;

class node
{
  public:
  int data;
  node *link;
};

class circlinkedlist
{
  public:
  node *head;
 
  circlinkedlist()
{head=NULL;}

void ins_front(int x)
{
  node *p=new node();
  node *ptr=head;
  p->data=x;
  
   if(head==NULL)
{
     head=p;
     p->link=head;
}
  else
{
   p->link=head;

  while(ptr->link!=head)
{
  ptr=ptr->link;}

  ptr->link=p;
  head=p;
  
}
}
void ins_end(int x)
{
  node *p=new node();
  node *ptr=head;
  p->data=x;
  
   if(head->link==NULL)
{
   
     head=p;
     p->link=head;
}
  else
{
   p->link=head;

  do
{
  ptr=ptr->link;}while(ptr->link!=head);

  ptr->link=p;
  
}
}
void disp()
{
  node *ptr=head;

  do
{
  cout<<ptr->data;
  ptr=ptr->link;
}while(ptr->link!=head);

}
};

int main()
{
  int i,n,x;

  circlinkedlist cll;

cout<<"Enter the size:";
 cin>>n;

cout<<"Enter the values:\n";

for(i=0;i<n;i++)
{
  cin>>x;
  cll.ins_end(x);
}

cout<<"the list is:\n";
cll.disp();

}
