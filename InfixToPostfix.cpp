#include<iostream>
#include<cstdlib>
#define size 100
using namespace std;
class Stack
{
public:
  char a[size];
  char ip[100];
  char op[100];
  int top,j,n;
  Stack()
  {
    top=-1;
    j=0;
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
  void push(char e)
  {
    if(isfull())
    {
      cout<<"Stack overflow\n";
      exit(0);
    }
    a[++top]=e;

  }
  char pop()
  {
    if(isempty())
    {
      cout<<"Stack underflow\n";
      exit(0);
    }
    return a[top--];
  }

  char peek()
  {
    if(isempty())
    {
      return 0;
    }
    return a[top];
  }
  void get()
  {
    cout<<"Enter the length of the expression\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>ip[i];
    }

    for(int i=0;i<n;i++)
    {
      if(ip[i]=='(')
      { char t=ip[i];

        this->push(t);
        cout<<"PUSHED::"<<ip[i]<<endl;
      }

      else if(ip[i]=='+'||ip[i]=='-'||ip[i]=='*'||ip[i]=='/')
      {  cout<<"sdf"<<ip[i];
         while(this->peek()=='+'||this->peek()=='-'||this->peek()=='*'||this->peek()=='/')
         {cout<<"sdf2";
           if(preced(ip[i])<preced(this->peek())||preced(ip[i])==preced(this->peek()))
           {  cout<<this->peek();

             op[j]=this->pop();
            cout<<"recived"<<op[i]<<endl;
            j++;

           }
           else
           {
             break;
           }
         }
         this->push(ip[i]);
         cout<<"pushed"<<ip[i]<<endl;
      }

      else if(ip[i]==')')
      { cout<<"GOT"<<ip[i]<<endl;
        while(this->peek()!='(')
        {
          op[j]=this->pop();

          cout<<"RECIVED"<<op[j]<<endl;
          j++;
          //n--;

        }
        if(this->peek()=='(')
        {

          cout<<"poped"<<this->pop()<<endl;
        //  n--;
        }
      }
      else if(ip[i]>='a'||ip[i]<='z')
      {    cout<<"recived00"<<ip[i]<<endl;
        op[j]=ip[i];
          cout<<"recived"<<op[j]<<endl;
          j++;
      }

    }
    while(!isempty())
    {
      op[j]=this->pop();
      j++;
    }
    //cout<<op[0];
  }

    int preced(char e)
    {
      switch(e)
      {
        case '+':
        case '-':
        {
          return 1;
        }
        case '*':
        case '/':
        {
          return 2;
        }
      }
    }



  void show()
  {  for(int i=0;i<n;i++)
    {
      cout<<op[i]<<endl;

    }


  }

};

int main()
{
  Stack obj;
  obj.get();
  obj.show();
  return 0;
}
