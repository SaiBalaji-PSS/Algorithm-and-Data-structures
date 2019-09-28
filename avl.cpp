#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
  int height;
}*root;

class bst
{
    public:
       bst()
       {
         root=NULL;
       }


       node* singlerotateright(node *k2)
       {
         node *k1=k2->left;
         k2->left=k1->right;
         k1->right=k2;
         k1->height=max(heights(k1->left),heights(k1->right))+1;
         k2->height=max(heights(k2->left),heights(k2->right))+1;
         return k1;

       }

       node* singlerotateleft(node * k2)
       {
         node *k1=k2->right;
         k2->right=k1->left;
         k1->left=k2;
         k1->height=max(heights(k1->left),heights(k1->right))+1;
         k2->height=max(heights(k2->left),heights(k2->right))+1;
         return k1;
       }

       node* doublecase2(node *k3)
       {
         k3->left=singlerotateleft(k3->left);
         return singlerotateright(k3);
       }

       node* doublecase3(node* k3)
       {
         k3->right=singlerotateright(k3->right);
         return singlerotateleft(k3);
       }

       int heights(node *t)
       {
         if(t==NULL)
         {
           return -1;
         }
         return t->height;
       }
       int max(int h1,int h2)
       {
         if(h1>h2)
         {
           return h1;
         }
         return h2;
       }



       node* insert(node *t,int e)
       {
         if(t==NULL)
         {
           t=new node();
           t->data=e;
           t->left=NULL;
           t->right=NULL;
           t->height=0;
           cout<<"INSERTED::"<<t->data<<"____"<<"@::"<<t<<endl;
         }
         else if(e<t->data)
         {
           t->left=insert(t->left,e);

           if(heights(t->left)-heights(t->right)==2)
           {
             if(e<t->left->data)
             {
               t=singlerotateright(t);
             }
             else
             {
               t=doublecase2(t);
             }
           }
         }
         else if(e>t->data)
         {
           t->right=insert(t->right,e);
           if(heights(t->left)-heights(t->right)==2)
           {
             if(e>t->right->data)
             {
               t=singlerotateleft(t);
             }
             else
             {
               t=doublecase3(t);
             }
           }
         }
         t->height=max(heights(t->left),heights(t->right))+1;

         return t;
       }
       node * find(node *t,int e)
       {
         if(t==NULL)
         {
           cout<<"ELEMENT NOT FOUND"<<endl;
           return NULL;
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
           cout<<"FOUND::"<<t->data<<"___@::"<<t<<endl;
         }
         return t;

       }
        node* fm(node *t)
       {
         while(t->left!=NULL)
         {
           t=fm(t->left);
         }
        return t;
       }
       node* fmx(node *t)
       {
         while(t->right!=NULL)
         {
           t=fmx(t->right);
         }
         return t;
       }
       void preorder(node *t)
       {
         if(t==NULL)
         {
           return;
         }
         cout<<t->data<<"\t";
         preorder(t->left);
         preorder(t->right);
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

       void inorder(node *t)
       {
         if(t==NULL)
         {
           return;
         }
         inorder(t->left);
         cout<<t->data<<"\t";
         inorder(t->right);
       }




       node* deletes(node *t,int e)
       {
         if(t==NULL)
         {
           cout<<"ELEMENT NOT FOUND TO DELETE @::"<<t<<endl;
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
             struct node *temp=fm(t->right);
             t->data=temp->data;
             //cout<<"DELETED::"<<temp->data<<"___@"<<temp<<endl;
             t->right=deletes(t->right,temp->data);
           }
           else if(t->left==NULL)
           {
             struct node *temp1=t;
             t=t->right;
             cout<<"DELETED::"<<temp1->data<<"___@"<<temp1<<endl;
             delete temp1;
           }
           else if(t->right==NULL)
           {
             struct node *temp2=t;
             t=t->left;
             cout<<"DELETED::"<<temp2->data<<"___@"<<temp2<<endl;
             delete temp2;
           }
         }
         return t;
       }



};




int main()
{
  bst obj;
  root=obj.insert(root,10);
  obj.insert(root,20);
  obj.insert(root,5);
  obj.insert(root,100);
  obj.insert(root,125);
  obj.find(root,100);
  cout<<"FOUND MINIMUM::"<<obj.fm(root)->data<<"____@::"<<obj.fm(root)<<endl;
  cout<<"FOUND MAXIMUM::"<<obj.fmx(root)->data<<"____@::"<<obj.fmx(root)<<endl;
  cout<<endl<<endl;
  cout<<"AVL TREE ELEMENTS ARE"<<endl;
  obj.preorder(root);
  cout<<endl<<endl;
  obj.deletes(root,56);
  obj.deletes(root,20);
  obj.deletes(root,125);
  cout<<"PREORDER::"<<endl;
  obj.preorder(root);
  cout<<endl<<endl;
  cout<<"INORDER::"<<endl;
  obj.inorder(root);
  cout<<endl<<endl;
  cout<<"POSTORDER::"<<endl;
  obj.postorder(root);
  cout<<endl;

  return 0;
}
