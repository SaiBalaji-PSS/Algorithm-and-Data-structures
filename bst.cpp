#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
	
}*root;

class bst{
	public:
		bst()
		{
			root=NULL;
		}
		node* insert(node *root,int e)
		{
			if(root==NULL)
			{
				root=new node;
				root->data=e;
				root->left=NULL;
				root->right=NULL;
				cout<<"INSERTED"<<root->data<<endl;
			}
			else if(e<root->data)
			{
				root->left=insert(root->left,e);
			}
			else
			{
				root->right=insert(root->right,e);
			}
			return root;
		
		}
		node* find(node *t,int e)
		{
			if(t==NULL)
			{
				cout<<"ELEMENT NOT FOUND"<<endl;
			}
			else if(e<t->data)
			{
				return find(t->left,e);
			}
			else if(e>t->data)
			{
				return find(t->right,e);
			}
			else
			{
				cout<<"FOUND::"<<t->data<<""<<"AT ADDRESS::"<<t<<endl;
			}
			return t;
		}
		node*  findmin(node *t)
		{
			while(t->left!=NULL)
			{
				t=t->left;
			}
			return t;
		}
		node* findmax(node* t)
		{
			while(t->right!=NULL)
			{
				t=t->right;
			}
			return t;
		}
		
		void preorder(node* t)
		{
			if(t==NULL)
			{
				return;
			}
			cout<<t->data<<"\t";
			preorder(t->left);
			preorder(t->right);
		}
		void inorder(node* t)
		{
			if(t==NULL)
			{
				return;
			}
				
			preorder(t->left);
			cout<<t->data<<"\t";
			preorder(t->right);
		}
		
		node* deletes(node* t,int e)
		{
			if(t==NULL)
			{
				cout<<"ELEMENT NOT FOUND FOR DELETION"<<endl;
				return NULL;
			}
			else if(e<t->data)
			{
				t->left=deletes(t->left,e);
			}
			else if(e>t->data)
			{
				t->right=deletes(t->right,e);
			}
			else
			{
				if(t->left!=NULL&&t->right!=NULL)
				{
					struct node *temp=findmin(t->right);
					t->data=temp->data;
					t->right=deletes(t->right,temp->data);
					cout<<"DELETED::"<<t->data<<endl;
				}
				else if(t->left==NULL)
				{
					struct node *temp=t;
						cout<<"DELETED::"<<t->data<<endl;
					t=t->right;
					delete temp;
				}
				else if(t->right==NULL)
				{
					struct node *temp=t;
						cout<<"DELETED::"<<t->data<<endl;
					t=t->left;
					delete temp;
				}
				
				
			}
			return t;
		}
		
		void postorder(node *t)
		{
			if(t==NULL)
			{
				return;
			}
			postorder(t->left);
			postorder(t->right);
			cout<<t->data<<"\t";
		}
		
};



int main()
{
	bst obj;
	root=obj.insert(root,10);
	root=obj.insert(root,56);
	root=obj.insert(root,12);
	root=obj.insert(root,45);
	obj.find(root,10);
	obj.find(root,12);
	cout<<"MINIMUM ELEMENT IS::"<<obj.findmin(root)->data<<endl;
	cout<<"MAXIMUM ELEMENT IS::"<<obj.findmax(root)->data<<endl;
	
	cout<<endl;
	
	obj.deletes(root,56);
	cout<<endl;
	cout<<"PREORDER"<<endl;
	obj.preorder(root);
	cout<<endl;
	cout<<"POSTORDER"<<endl;
	obj.postorder(root);
	cout<<endl;
	cout<<"INORDER"<<endl;
	obj.inorder(root);
	
	
	
	return 0;
}
