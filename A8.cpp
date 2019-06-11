//============================================================================
// Name        : A8.cpp
// Author      : Nachiket Erlekar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
class node
{
	string w;
	string m;
	node *left,*right;
	int height;
	public:
	friend class avl;
};
class avl
{
  public:
  	node *root;
  	string a,b,c,d;
        int count,found;
  	avl()
  	{
  	 root=NULL;
         count=0;
         found=0;	
	}
    int diff(node *);
    void searchword();
    void updateword();
    int height(node *);
    void comparisions();
    node *balance(node *);
    void inorder_1(node *);
    void inorder_2(node *);
    void ascending_display();
    void descending_display();
    void ins(string ,string );
    node* rr_rotation(node *);
    node* ll_rotation(node *);
    node* lr_rotation(node *);
    node* rl_rotation(node *);
    node* avl_search(string );
    node* minValueNode(node* );
    node* insert(node *root,string value,string meaning);
};
void avl::ins(string x,string y)
{
	root=insert(root,x,y);
}
int avl::height(node *temp)
{
    int h=0;
    if (temp!=NULL)
    {
    int l_height=height(temp->left);
    int r_height=height(temp->right);
    int max_height=max(l_height, r_height);
    h=max_height+1;
    }
    return h;
}
int avl::diff(node *temp)
{
	if(temp == NULL)
	  return 0;
    int l_height=height(temp->left);
    int r_height=height(temp->right);
    int b_factor=l_height-r_height;
    return b_factor;
}
node *avl::rr_rotation(node *parent)
{
    node *temp;
    temp=parent->right;
    parent->right=temp->left;
    temp->left=parent;
    return temp;
}
node *avl::ll_rotation(node *parent)
{
    node *temp;
    temp=parent->left;
    parent->left=temp->right;
    temp->right=parent;
    return temp;
}
node *avl::lr_rotation(node *parent)
{
    node *temp;
    temp=parent->left;
    parent->left=rr_rotation(temp);
    return ll_rotation(parent);
}
node *avl::rl_rotation(node *parent)
{
    node *temp;
    temp=parent->right;
    parent->right=ll_rotation(temp);
    return rr_rotation(parent);
}
node *avl::balance(node *temp)
{
    int bal_factor=diff(temp);
    if(bal_factor>1)
    {
        if (diff(temp->left)>0)
            temp=ll_rotation(temp);
        else
            temp=lr_rotation(temp);
    }
    else if(bal_factor<-1)
    {
        if (diff(temp->right)>0)
            temp=rl_rotation(temp);
        else
            temp=rr_rotation(temp);
    }
    return temp;
}
node* avl::insert(node *root,string value,string meaning)
{
    if (root==NULL)
    {
        root=new node;
        root->w=value;
        root->m=meaning;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if(value<root->w)
    {
        root->left=insert(root->left,value,meaning);
        root=balance(root);
    }
    else if(value>=root->w)
    {
        root->right=insert(root->right,value,meaning);
        root=balance(root);
    }
    return root;
}
void avl::inorder_1(node *m)
{
 if(m!=NULL)
 {
 inorder_1(m->left);
 cout<<m->w<<"\t";
 inorder_1(m->right);
 }
}
void avl::inorder_2(node *n)
{
 if(n!=NULL)
 {
 inorder_2(n->right);
 cout<<n->w<<"\t";
 inorder_2(n->left);
 }
}
void avl::ascending_display()
{
 if(root==NULL)
  {
  cout<<"Tree is Empty.\n";
  }
 else
  {
  cout<<"Displaying Words of Dictionary in ascending order:-\n";
  inorder_1(root);
  cout<<"\n";
  }
}
void avl::descending_display()
{
 if(root==NULL)
  {
  cout<<"Tree is Empty.\n";
  }
 else
  {
  cout<<"Displaying Words of Dictionary in descending order:-\n";
  inorder_2(root);
  cout<<"\n";
  }
}
node* avl::avl_search(string j)
{
    found=count=0;
    node *q1=root;
    while(found!=1)
    {
       count++;
       if(j < q1->w)
        {
            if(q1->left==NULL)
            {   
               return NULL;
            }
            else
            {
                q1=q1->left;
            }
        }
      else if(j > q1->w)
        {
            if(q1->right==NULL)
            {
               return NULL;
            }
            else
            {
               q1=q1->right;
            }
        }
      else 
       {
        if((j.compare(q1->w))==0)
           {
               found=1;
               return q1;
           }
       }
    }
}
void avl::searchword()
{
 node *u;
 cout<<"Enter the word to be search:-\n";
 cin>>a;
 if(root==NULL)
  {
   cout<<"Dictionary is Empty.\n";
   return ;
  }
 u=avl_search(a);
 if(u==NULL)
    {
    cout<<"Word Not Found.\n";
    }
 else
    {
      cout<<"Word Found.\n";
      cout<<u->w<<"\t"<<u->m<<"\n";
    }      
}
void avl::updateword()
{
  cout<<"Enter the word to be updated:-\n";
  cin>>b;
  if(root==NULL)
   {
    cout<<"Dictionary is Empty.\n";
    return;
   }
  struct node *e;
  e=avl_search(b);
  if(e==NULL)
    {
    cout<<"Word Not Found.\n";
    }
 else
    {
      cout<<"Word Found.\n";
      cout<<"Enter the updated meaning:-\n";
      cin>>c;
      e->m=c;
    }            
}
void avl::comparisions()
{
 cout<<"The maximum comparisions required for searching are:-\n";
 cout<<count<<"\n";
}
int main()
{
avl a;
int l;
string word,meaning;
do
{
  cout<<"Enter your choice:-\n";
  cout<<"1.Insert a Word in the Dictionary\n";
  cout<<"2.Display Words of Dictionary in Ascending order\n";
  cout<<"3.Display Words of Dictionary in Descending order\n";
  cout<<"4.Search a Word in the Dictionary\n";
  cout<<"5.Update a Word in the Dictionary\n";
  cout<<"6.Calculate Maximum Comparisons\n";
  cout<<"7.Exit\n";
  cin>>l;
  switch(l)
  {
   case 1:
   cout<<"Enter the word:-\n";
   cin>>word;
   cout<<"Enter the meaning:-\n";
   cin>>meaning;
   a.ins(word,meaning);
   break;
   case 2:
   a.ascending_display();
   break;
   case 3:
   a.descending_display();
   break;
   case 4:
   a.searchword();
   break;
   case 5:
   a.updateword();
   break;
   case 6:
   a.comparisions();
   break;
   case 7:
   break;
   default:
   cout<<"Invalid Choice\n";
   break;
  }
}while(l!=7);
return 0;
}
