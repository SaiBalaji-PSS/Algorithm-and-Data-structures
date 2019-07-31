#include<iostream>
using namespace std;
class sample
{
	private:
		int a[100];
		int key;
	public:
		void get(int n)
		{
		
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
			cout<<"ENTER THE KEY"<<endl;
			cin>>key;
		}
		void show(int n)
		{
			for(int i=0;i<n;i++)
			{
				cout<<a[i]<<endl;
			}
		}
		void bs(int l,int h)
		{   int flag=0,mid;
		    
			while(l<h)
			{
				mid=l+h/2;
				if(key==a[mid])
				{
					flag=1;
					break;
				}
				else if(key<a[mid])
				{
					h=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			if(flag==1)
			{
				cout<<"FOUND"<<endl;
		    }
			else
			{
			   cout<<"NOT FOUND"<<endl;	
			}		
		}
};


int main()
{ 
       int n;
   	cout<<"Enter the number of elements"<<endl;
			cin>>n;
	sample obj;
	obj.get(n);
	obj.bs(0,n-1);
	obj.show(n);
}
