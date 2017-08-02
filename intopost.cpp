#include<iostream>
#include<locale>
#include<cstring>
#include<stack>

using namespace std;

class intopost
{   public:
   stack<char> s;
  int i=0,k=0;
    char ch;
 
  void intopostfix()
 {
    
    char infix[20]; 
    char postfix[20];
    int size;
  
   cout<<"Enter Infix : ";
   cin.get(infix,20);

   size = strlen(infix);
   

   while(i<size)
  { 
     ch = infix[i];

     if(isalnum(ch))
    {
       postfix[k++]=ch;
        }
     else if(ch=='(')
     {
        s.push(ch);
      }
    else if(ch==')')
    {
       do
      {  char a;
         a=s.top();
         postfix[k++]=a;
         s.pop();}while(s.top()!='(');
        s.pop(); }
    else if(s.empty() && ch=='+'||'-'||'*'||'/'||'^')
    {
      s.push(ch);  }
    else if(ch=='+'||'-'||'*'||'/'||'^')
     {
        int a = priority(ch);
        int b = priority(s.top());

        if(b>=a)
        {
          char d;       
          d=s.top();
          postfix[k++]=d;
          s.pop();
          s.push(ch); }
                   
        else
         { s.push(ch); }
      }
  i++; }

    do
    {
       char b;
       b=s.top();
       postfix[k++]=b;
       s.pop();
     }while(!s.empty());
    cout<<"The Postfix expression is :"<<endl;
   for(i=0;i<size;i++)
    { cout<<postfix[i]; }
    cout<<endl;
}

   int priority(char a)
    {

     switch(a)
       {case '*':
       case '/':
          { return 2;  break;  }
       case '+':
       case '-':
           {  return 1; break; }
       case '^':
           {  return 3; break; }

     }
     }
 


};



int main()
{

   intopost k;
   k.intopostfix();




}




  




