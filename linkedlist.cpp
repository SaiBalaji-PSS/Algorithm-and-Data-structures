#include<iostream>
using namespace std;
struct node
{
	int value;
	struct node *next;
	
};

class list
{
	private:
		struct node *head;
		int n;
    public:
    	list()
    	{
    		head=NULL;
    		n=0;
		}
    	void insertbeg();
    	void insertend();
    	void insertpos();
    	void delbeg();
    	void delend();
    	void delpos();
    	
    	void display();
    
    	
};


void list:: insertbeg()
{
	struct node *temp;
	temp = new node;
	cout<<"ENTER THE VALUE TO INSERT AT BEGINING"<<endl;
	cin>>temp->value;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		n++;
		cout<<"LIST IS EMPTY SO INSERTING"<<head->value<<"IN BEGINING"<<endl;
		
		return;
	}
	temp->next=head;
	head=temp;
	n++;
	cout<<head->value;
}
void list::insertend()
{
	struct node *temp,*c;
	temp = new node;
	cout<<"ENTER THE VALUE TO INSERT AT END"<<endl;
	cin>>temp->value;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		n++;
		return;
	}
	for(c=head;c->next!=NULL;c=c->next);
	c->next=temp;
	
	
}
void list::insertpos()
{
	struct node *temp,*c;
	int pos;

	cout<<"ENTER THE POSITION"<<endl;
	cin>>pos;
	if(pos<=0&&pos>n+1)
	{
		cout<<"INVALID POSITION"<<endl;
		return;
	}
	if(pos==1)
	{
		insertbeg();
	}
	if(pos>n+1)
	{
		insertend();
		return ;
	}
	temp = new node;
	c= new node;
	cout<<"ENTER THE VALUE TO INSERT AT position"<<endl;
	cin>>temp->value;
	temp->next=NULL;
	int i;
	for( i=1,c=head;i<pos-1;c=c->next);
	temp->next=c->next;
	c->next=temp;
}
  void list::display()
  {
    node *temp=new node;
    temp=head;
    for(temp=head;temp!=NULL;temp=temp->next)
    
    {
      cout<<"["<<temp->value<<"]"<<"->";
      
    }
}
void list::delbeg()
{    struct node * temp;
	temp = new node;
	if(head==NULL)
	{
		cout<<"LIST EMPTY"<<endl;
		return;
	}
	temp=head;
	cout<<temp->value<<"IS DELETED"<<endl;
	head=head->next;
	delete temp;
	n--;
	
}
void list::delend()
{
	struct node *c,*p;
	if(head==NULL)
	{
		cout<<"EMPTY LIST";
		return ;
	}
	for(p=head,c=head;c->next!=NULL;p=c,c=c->next);
	cout<<c->value<<""<<"IS DELETED"<<endl;
	
	
	if(p==c)
	{
		head=NULL;
		delete p,c;
	}
	delete c;

	
}
void list:: delpos()
{
	struct node *p,*c;
	int pos;
	if(head==NULL)	
	{
		cout<<"LIST EMPTY";
		return;
	}
	cout<<"ENTER THE POSITION"<<endl;
	cin>>pos;
	if(pos<=0||pos>n)
	{
		cout<<"INVALID"<<endl;
		return;
	}
	if(pos==1)
	{
		delbeg();
	}
	if(pos==n)
	{
		delend();
	}
	int i;
	for(i=1,p=head,c=head;i!=pos;i++,p=c,c=c->next);
	cout<<c->value<<"IS DELETED"<<endl;
	p->next=c->next;
	delete c;
}

int main()
{
	list obj;
	
	obj.insertbeg();
	obj.insertbeg();
	obj.insertbeg();
	obj.insertbeg();
	
	
	obj.insertend();
	obj.insertpos();
	//obj.delbeg();
	//obj.delend();
	obj.delpos();
	
	return 0;
	
}
