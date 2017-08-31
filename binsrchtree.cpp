#include<iostream>
#include<stack>
using namespace std;
class BST;
class node
{public:
 int data;
 node *leftc;
 node *rightc;

friend class BST;

};

class BST
{

 node *root;
 public:
 node *r();
 
 node *create(int x);
 void insert(int x);
 BST();
 int max();
 int min();
 void preorder(node *);
 void postorder(node *);
 int height(node *);
 void search(int x);
 friend int MAX(int,int);
 
};

int MAX(int a,int b)
{
 if(a>b)
 return a;
 else
 return b;
}

node *BST::r()
{ return root; }
BST::BST()
{
 root=NULL;
}

node *BST::create(int x)
{
 node *p= new node();
 p->data= x;
 p->leftc=NULL;
 p->rightc=NULL;
 return p;
}

void BST::insert(int x)
{
node *curr=root;
node *parent=NULL;

if(curr==NULL)
{
 root=create(x);
 
}
else
{
 curr=root;

 while(curr!=NULL)
  {
   if(x<curr->data)
   {
    parent=curr;
    curr=curr->leftc;
 }
   else if(x>curr->data)
   {
    parent=curr;
    curr=curr->rightc;
   }
  }
  if(x<parent->data)
  {
   parent->leftc=create(x);
   
  }
  else if(x>parent->data)
  {
   parent->rightc=create(x);
   
  }
 }
}

int BST::max()
{
 node *curr=root;

 while(curr->rightc!=NULL)
 {
  curr=curr->rightc;
 }
  cout<<"The Max is:"<<curr->data<<"\n";
}

int BST::min()
{
 node *curr=root;

 while(curr->leftc!=NULL)
 {
  curr=curr->leftc;
 }
 cout<<"The Min is:"<<curr->data<<"\n";
}

void BST::postorder(node *x)
{
 node *curr=x;
 if(x==NULL){ return;}
 else
 {
  
  postorder(curr->leftc);
  postorder(curr->rightc);
  cout<<curr->data<<"\t";
 }
}

int BST::height(node *x)
{
 if(x==NULL)
 return -1;
 else
 return 1+MAX(height(x->leftc),height(x->rightc));
}

void BST::search(int x)
{
  node * temp = root;
  int flag=0;

  while(temp!=NULL)
 { if(temp->data == x)
   {
     flag = 1;
     break;
   }
  else if(x < temp->data)
  {
    temp = temp->leftc;
    continue;
  }
 else if(x > temp->data)
  {
    temp = temp->rightc;
    continue;
  }
 }
 if(flag == 1)
 cout<<"Item found\n";
 else
 cout<<"Item not found\n";
}

void BST::preorder(node * root)
{
 stack<node *> s;
 node * curr = root;
 
 start:
 while(curr!=NULL)
 {
   cout<<curr->data<<"\t";
   s.push(curr->rightc);
   curr = curr->leftc;
 }
 if(s.empty()) return;
 else
 {
   curr = s.top();
   s.pop();
 }
 goto start;

}

 int main()
{
 BST A;
 
 int i = 0,n,x;
 cout<<"Enter size:";
 cin>>n;
 for(i=0;i<n;i++)
 {
   cout<<"Enter item:";
   cin>>x;   
   A.insert(x);
 }

 cout<<"Preorder:";
 A.preorder(A.r());

 cout<<"\nEnter item to search:";
 cin>>x;

 A.search(x);


}
