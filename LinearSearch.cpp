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
		{	cout<<"ENTERED ELEMENTS ARE"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<a[i]<<endl;
			}
		}
		void ls(int n)
		{  int flag=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==key)
			{
				flag=1;
				break;
			}
			
		}
		if(flag==1)
			{
				cout<<"FOUND"<<endl;;
			}
			else
			{
				cout<<"NOT FOUND";
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
	obj.show(n);
	obj.ls(n);
	
}
