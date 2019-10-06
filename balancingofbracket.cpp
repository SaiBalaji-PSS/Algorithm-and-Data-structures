#include<iostream>
#include<cstdlib>
#include<cstring>
#define size 100
using namespace std;
class stack
{
public:
  int top;
  char a[size];
  stack()
  {
    top=-1;
  }

  bool isfull()
  {
    if(top==size-1)
    {
      return 1;
    }
    return 0;
  }

  bool isempty()
  {
    if(top==-1)
    {
      return 1;
    }
    return 0;
  }

  void push(int e)
  {
    if(this->isfull())
    {
      cout<<"Stack overflow\n";
      exit(0);
    }

    a[++top]=e;
  }

  char pop()
  {
    if(this->isempty())
    {
      cout<<"Stack underflow\n";
      exit(0);
    }

    return a[top--];
  }

  void get()
  {  cout<<"Enter the no of char\n";
     int n;
     cin>>n;
    cout<<"Enter the expression\n";
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
      if(a[i]=='('||a[i]=='['||a[i]=='{')
      { char e=a[i];
        this->push(e);
      }
      else if(a[i]==')')
      {
        if(this->isempty())
        {
          cout<<"Invalid"<<endl;
          exit(0);
        }
        else if(char e=this->pop()!='(')
        {cout<<"Invalid";
         exit(0);
        }
      }

      else if(a[i]==']')
      {
        if(this->isempty())
        {
          cout<<"Invalid"<<endl;
          exit(0);
        }
        else if(char e=this->pop()!='[')
        {cout<<"Invalid";
         exit(0);
        }
      }

      else if(a[i]=='}')
      {
        if(this->isempty())
        {
          cout<<"Invalid"<<endl;
          exit(0);
        }
        else if(char e=this->pop()!='{')
        {cout<<"Invalid";
         exit(0);
        }
      }

    }

    if(this->isempty())
    {
      cout<<"Valid\n";
    }
    else
    {
      cout<<"Invalid\n";
    }


  }

};

int main()
{
  stack obj;
  obj.get();
  return 0;
}
