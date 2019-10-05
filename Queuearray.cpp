#include<iostream>
#define size 5
using namespace std;
class queue
{
public:
  int a[size];
  int n;
  int rear,front;
  queue()
  {
    n=0;
    rear=-1;
    front=0;
  }
  bool isfull()
  {
    if(n==size-1)
    {
      return 1;
    }
    return 0;
  }

  bool isempty()
  {
    if(n==0)
    {
      return 1;
    }
    return 0;
  }

  void enqueue()
  {
    int e;
    if(this->isfull())
    { cout<<"Queue is full\n";
      return;
    }
    cout<<"Enter the element to insert"<<endl;
    cin>>e;

    rear++;
    cout<<"Inserted"<<e<<endl;
    a[rear]=e;
    n++;

  }

  void dequeue()
  {
    if(this->isempty())
    {
      cout<<"queue is empty\n";
      return;
    }


    cout<<"Processed"<<a[front]<<endl;
    a[front++]=-1;
    n--;
  }

  void show()
  {
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<endl;
    }
  }
};

int main()
{
  queue obj;
  int ch,c;
  do {
    cout<<"Enter 1)enqueue\n2)dequeue\n3)show";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        obj.enqueue();
        break;
      }

      case 2:
      {
        obj.dequeue();
        break;
      }

      case 3:

      {
        obj.show();
        break;
      }

      default:
      {
        cout<<"Invalid"<<endl;
      }
    }
    cout<<"Do u want to continue"<<endl;
    cin>>c;
  } while(c==1);


}
