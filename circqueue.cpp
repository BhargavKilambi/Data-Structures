#include<iostream>
#define MAX 10

using namespace std;

class cqueue
{
  int q[10];
  int front,rear;

  public:
  cqueue()
  {
    front=rear=-1;}


  void enqueue(int x)
 {  
   if(front==rear==-1)
    { front++; 
       rear++;
      q[rear]=x; }
   else if(front==0 && rear==MAX-1)
      { cout<<"Queue Overflow"<<endl; }
   else
     {   
       rear = (rear+1)%MAX; 
        q[rear]=x; }  

  }
 
  void dequeue()
  {
     if(front==rear==-1)
       { cout<<"Queue Underflow"<<endl; }
     else
      {  front = (front+1)%MAX; }
  }


void disp()
  {
     int i;
     
     cout<<"The Queue is: "<<endl;
    for(i=front+1;i<=rear;i++)
      cout<<q[i]<<endl;

  }

};



int main()
 {   cqueue q;
    int i=0,x;

    cout<<"Enter 5 elements:"<<endl;

   for(i=0;i<5;i++)
    {
      cin>>x;
      q.enqueue(x);
   }

   //cout<<"The queue is : "<<endl;
   q.disp();

   q.dequeue();
   q.dequeue();

  cout<<"Queue after dequeuing:"<<endl;

   q.disp();
}



  




