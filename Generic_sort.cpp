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


  void insertion()
  {
    int i,j,k;
    T t;
    k=0;
    for(i=1;i<n;i++)
    {
      t=a[i];
      j=i-1;
      while(j>=0&&a[j]>t)
      {
        a[j+1]=a[j];
        j=j-1;
        k++;
        
      }
      a[j+1]=t;

    }
    cout<<"Counter value::"<<k<<endl;
  }

  void selection()
  {
    int i,j,min,k;
    T t;
    k=0;
    for(i=0;i<n-1;i++)
    {    min=i;
      for(j=i+1;j<n;j++)
      {
        if(a[min]>a[j])
        {
          min=j;
     
        }
                 t=a[min];
        a[min]=a[i];
        a[i]=t;
        k++;
        
        
    
        

      }
    }
    cout<<"Counter value::"<<k<<endl;
    
  }

};
int main()
{   cout<<"INTEGER SORT"<<endl;
    sample <int> obj;
   
   
    obj.get();
    cout<<"Entered elements are"<<endl;
    obj.show();
    
    cout<<"Enter the choice 1.Selection\n2.Insertion\n";
    int ch;
    
    cin>>ch;
    switch(ch)
    {
    	case 1:
    	{
    cout<<"INSERTION SORT"<<endl;
    obj.insertion();
    obj.show();
    break;
    	}
    	
    	
    	case 2:
    	{
    
    cout<<"SELECTION SORT"<<endl;
    obj.selection();
    obj.show();
    	}
    	
    	default:
    	{
    		cout<<"Invalid choice\n";
    	}
    }

    return 0;
}
