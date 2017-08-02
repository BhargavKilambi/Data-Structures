#include<iostream>

using namespace std;

class queue
{
    public:
  int q[20];
  int front; //same as head
  int rear;  //same as tail

 queue()
 {
   front=rear=-1;} //constructor

 void enqueue(int x)
{
   if(rear==19)
   {  cout<<"Queue is FULL\n";
       exit;
    }
   else
   {
     q[++rear]=x;
     cout<<"ADDED.\n";
    }
}

 void dequeue()
{
   cout<<q[front++]<<"is dequeued.\n";
   
}

void disp()
{
   int i;
   cout<<"The queue is:\n";
   for(i=front;i<rear;i++)
    {
       cout<<q[i]<<endl;
     }
}

};

int main()
{
   queue qq;
   int x,a,n,i;

  while(1)
{
   cout<<"CHOOSE:\n1.Add elements.\n2.Enqueue\n3.Dequeue\n4.Display\n5.stop"<<endl;
   cin>>a;

  switch(a)
  {
     case 1:
       {  cout<<"The size is:";
           cin>>n;
         cout<<"Enter:\n";
           for(i=0;i<n;i++)
            {   cin>>x;
                qq.enqueue(x);
             }
         break;
       }
     case 2:
      {   cout<<"Enter:";
          cin>>x;
           qq.enqueue(x);
         break;
      }
     case 3:
      {
         qq.dequeue();
         break;
       }
      case 4:
      {
         qq.disp();
          break;
        }

     case 5:
      break;

  }


cout<<"1.Continue 2.Stop"<<endl;
cin>>a;
if(a==1)
continue;
else
 break;
}
}

