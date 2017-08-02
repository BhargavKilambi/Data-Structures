#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int main()

{
    int flag; 
   char ch;
  stack<char> s;
  
  int i=0,size;
   char a[20];
  cout<<"Enter string : ";
  cin.get(a,20);
  size = strlen(a);


  for(i=0;i<size;i++)
  {
    ch=a[i];
    s.push(ch); }

  for(i=0;i<size;i++)
  {  
    if(s.top()==a[i])
       {  flag=1;
           s.pop(); }
    else
       { cout<<"Not a Palindrome!";
          flag=0;
          break; }
   }
 
  if(flag==1)
   {cout<<"Palindrome!"<<endl;}
 


}
