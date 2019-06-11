//============================================================================
// Name        : TBT.cpp
// Author      : Nachiket Erlekar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
	node *left,*right;
	int lbit,rbit;
	int child;
	int data;
public:
	node(int x)
{
		data=x;
		left=right=NULL;
		lbit=rbit=0;
		child=-1;
}
	friend class TBT;
};
class TBT
{
	node *root;
public:
	TBT()
{
		root=new node(0);
		root->left=root->right=root;
		root->lbit=root->rbit=0;
		root->child=-1;
}
	void create()
	{
		create_recc(root,0);
	}
	void create_recc(node *father,int child)
	{
		node *T;
		int x;
		cout<<"Enter the number or '-1' to stop"<<endl;
		cin>>x;
		if(x==-1)
			return;
		else
		{
			if(child==0)
			{
				T=new node(x);
				T->lbit=T->rbit=0;
				T->child=child;
				T->left=father->left;
				T->right=father;
				father->left=T;
				father->lbit=1;
			}
			if(child==1)
			{
				T=new node(x);
				T->lbit=T->rbit=0;
				T->child=child;
				T->right=father->right;
				T->left=father;
				father->right=T;
				father->rbit=1;
			}
			cout<<"Enter to the left of "<<x<<endl;
			create_recc(T,0);
			cout<<"Enter to the right of "<<x<<endl;
			create_recc(T,1);
		}
	}
	void inorder()
	{
		node *T=root->left;
		while(T->lbit==1)
		{
			T=T->left;
		}
		while(T!=root)
		{
			cout<<T->data<<" ";
			T=in_succ(T);
		}
	}
	node* in_succ(node* T)
	{
		if(T->rbit==0)
		return T->right;
		else
		{
			T=T->right;
			while(T->lbit==1)
			{
				T=T->left;
			}
			return T;
		}
	}
	void preorder()
	{
		node* T=root->left;
		while(T!=root)
		{
			cout<<T->data<<" ";
			T=pre_succ(T);
		}
	}
	node* pre_succ(node* T)
	{
		if(T->lbit==1)
		{
			return T->left;
		}
		while(T->rbit==0 && T->right!=root)
		{
			T=T->right;
		}
		return T->right;
	}
	/*void delete_num()
		{
			int x;
			cout<<"Enter the number to be deleted"<<endl;
			cin>>x;
			node *p=search_recc(root->left,x);
			cout<<"word found: "<<p->data;
			//root->left=del_recc(root->left,x);
		}
	node* search_recc(node* T,int x)
	{

			if(T->data==x)
			{
				return T;
			}
			else
			{
				T->left=search_recc(T->left,x);
				T->right=search_recc(T->right,x);
			}

		}
	}*/
	/*void del_recc(node* T,int x)
	{
		if(T!=root)
		{

		}
	}*/
};
int main()
{
	TBT obj;
	int ch,q=1;
	cout<<"--------MENU---------"<<endl;
	cout<<"1.)Create a TBT"<<endl;
	cout<<"2.)Display TBT in inorder"<<endl;
	cout<<"3.)Display TBT in preorder"<<endl;
	do{
	cout<<"Enter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
	{
		obj.create();
		break;
	}
	case 2:
	{
		cout<<"INORDER REPRESENTATION: ";
		obj.inorder();
		cout<<endl;
		break;
	}
	case 3:
	{
		cout<<"PREORDER REPRESENTATION: "<<endl;
		obj.preorder();
		cout<<endl;
		break;
	}
	case 4:
	{
		obj.delete_num();
	}
	}
	cout<<"Do you want to continue(1 for yes/0 for no)?"<<endl;
	cin>>q;
}while(q==1);
return 0;
}
