#include<iostream>
using namespace std;
template<class T>class sample
{
private:
  T a[100];
  int n;
public:

  void get()
  {
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
  }

void show()
  {

    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<endl;
    }
  }


  void st()
  {
    int i,j,t;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n-i-1;j++)
      {
        if(a[j]>a[j+1])
        {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
        }
      }
    }
  }

  void insertion()
  {
    int i,j,t;
    for(i=1;i<n;i++)
    {
      t=a[i];
      j=i-1;
      while(j>=0&&a[j]>t)
      {
        a[j+1]=a[j];
        j=j-1;
      }
      a[j+1]=t;

    }
  }

  void selection()
  {
    int i,j,min,t;
    for(i=0;i<n-1;i++)
    {    min=i;
      for(j-i+1;j<n;j++)
      {
        if(a[min]>a[j])
        {
          min=j;
        }
        t=a[min];
        a[min]=a[i];
        a[i]=t;

      }
    }
  }

};
int main()
{   cout<<"INTEGER SORT"<<endl;
    sample <int> obj;

    cout<<"INT SORT"<<endl;
    obj.get();
    cout<<"Entered elements are"<<endl;
    obj.show();
    cout<<"BUBBLE SORT"<<endl;
    obj.st();
    obj.show();
    obj.insertion();
    cout<<"INSERTION SORT"<<endl;
    obj.show();
    cout<<"SELECTION SORT"<<endl;
    obj.show();

    sample <char> obj1;

    cout<<"CHAR SORT"<<endl;
    obj1.get();
    cout<<"Entered elements are"<<endl;
    obj1.show();
    cout<<"BUBBLE SORT"<<endl;
    obj1.st();
    obj1.show();
    obj1.insertion();
    cout<<"INSERTION SORT"<<endl;
    obj1.show();
    cout<<"SELECTION SORT"<<endl;
    obj1.show();







    return 0;
}
