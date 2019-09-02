#include<iostream>
#define size 100
using namespace std;
class stack 
{
private:
    int a[size];
    int n,top;
public:
    stack ()
    {
        n=0;
        top=-1;
    }
    void push()
    {
        int e;
        cout<<"ENTER THE ELEMENT"<<endl;
        cin>>e;
        if(top==size-1)
        {
            cout<<"STACK OVERFLOW"<<endl;
            return;
        }
        cout<<"INSERTING..."<<e<<endl;
        a[++top]=e;
        n++;
    }
    int  pop()
    {
        if(top==-1)
        {
            cout<<"STACK UNDERFLOW"<<endl;
            //return ;
        }
        cout<<"REMOVING..."<<a[top]<<endl;
        return a[top--];
        n--;
    }
    void show()
    {	cout<<"STACK ELEMENTS ARE"<<endl;
        for(int i=0;i<n;i++)
        {   
            cout<<a[i]<<endl;
        }

    }
};
int main()
{
    stack obj;
    int ch,c;
    do
    {
         cout<<"1.PUSH"<<"\n"<<"2.POP"<<"\n"<<"3.SHOW"<<endl;
    cin>>ch;
    switch (ch)

    {
        case 1:
            obj.push();
            break;
    
        case 2:
            obj.pop();
            break;
        case 3:
        	obj.show();
        	break;
        default:
            cout<<"INVALID CHOICE"<<endl;
    }
    cout<<"DO YOU WANT TO CONTINUE"<<endl;
    cin>>c;
    } while (c==1);
    return 0;
   
}
