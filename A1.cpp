
#include <iostream>
using namespace std;
void showchoices();

class node{
	int data;
	node *left;
	node *right;
public:
	node(int x)
{
		data=x;
		left=NULL;
		right=NULL;
}
	friend class Bin_tree;
};
class stack
{
	node* data[30];
	int top;
public:
	stack()
{
		top=-1;
}
	bool isFull()
	{
		if(top==29)
			return true;
		else
			return false;
	}
	bool isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	void push(node* p)
	{
		if(!isFull())
		{
			top++;
			data[top]=p;
		}
	}
	node* pop()
	{
		node *p=data[top];
		if(!isEmpty())
		{
			top--;
		}
		return p;
	}
};

class Bin_tree{
	node *root;

public:
	int count1=0;

	//To create tree recurrsively
	void create()
	{
		root=insert();
	}
	node* insert();
	//To display preorder recurrsively
	void preorder()
	{
		pre_recc(root);
	}
	void pre_recc(node*);
	//To display postorder recurrsively
	void postorder()
	{
		post_recc(root);
	}
	void post_recc(node*);
	//To display inorder recurrsively
	void inorder()
	{
		in_recc(root);
	}
	void in_recc(node*);
	//To display preorder non-recurrsive
	void pre_non_recc()
	{
		stack s;
		node* p=root;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			s.push(p);
			p=p->left;
		}
		while(!s.isEmpty())
		{
			p=s.pop();
			p=p->right;
			while(p!=NULL)
			{
				cout<<p->data<<" ";
				s.push(p);
				p=p->left;
			}

		}
	}
	//To display in-order non-reccursively
	void in_non_recc()
	{
		node *p=root;
		stack s;
		while(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}
		while(!s.isEmpty())
		{
			p=s.pop();
			cout<<p->data;
			p=p->right;
			while(p!=NULL)
			{
				s.push(p);
				p=p->left;
			}

		}
	}
	//To display post-order non recurrsively
	void post_non_recc()
	{
		node* p=root;
		stack s,s1;
		s.push(p);
		while(!s.isEmpty())
		{
			p=s.pop();
			s1.push(p);
			if(p->left!=NULL)
			{
				s.push(p->left);
			}
			if(p->right!=NULL)
			{
				s.push(p->right);
			}
		}
		while(!s1.isEmpty())
		{
			p=s1.pop();
			cout<<p->data<<" ";
		}
		cout<<endl;

	}
	//To create mirror image of same tree
	void mirror()
	{
		mirror_recc(root);
	}
	void mirror_recc(node* T)
	{
		node* temp;
		if(T==NULL)
			return;
		mirror_recc(T->left);
		mirror_recc(T->right);
		temp=T->left;
		T->left=T->right;
		T->right=temp;
	}
	//To create a mirror image as a new tree
	node* mirror_n_recc(node* T)
	{
		if(T!=NULL)
		{
		node* temp=new node(T->data);
		temp->left=mirror_n_recc(T->left);
		temp->right=mirror_n_recc(T->right);
		return temp;
		}
		else
			return NULL;

	}
	//To find height of tree
	void height()
	{
		cout<<"Height of tree is"<<height_recc(root)<<endl;
	}
	int height_recc(node* T)
	{
		int h1,h2;
		if(T==NULL)
			return 0;
		else{
			h1=height_recc(T->left);
			h2=height_recc(T->right);
			return (1+max(h1,h2));

		}

	}
	int max(int a, int b)
	{
		if(a>b)
			return a;
		else
			return b;
	}
	//To find number of leaf nodes
	void leaf()
	{
		int count=leaf_recc(root);
		cout<<"Total number of leaf nodes are: "<<count<<endl;
	}
	int leaf_recc(node* T)
	{
		if(T==NULL)
			return 0;
		if(T->left==NULL && T->right==NULL)
			return 1;

		return leaf_recc(T->left)+leaf_recc(T->right);
	}
	//To find the interior nodes
	void interior()
	{
		int count=leaf_recc(root);
		cout<<"Total nodes are: "<<count1<<endl;
		cout<<"Interior nodes are: "<<count1-count<<endl;
	}
	//To delete all nodes of tree
	void del()
	{
		delete_node(root);
		cout<<"The total number of nodes in tree now are"<<count1;
	}
	void delete_node(node*);

};
node* Bin_tree::insert()
{
	node *p;
	int x;
	cout<<"Enter the data or -1 to enter no data"<<endl;
	cin>>x;
	if(x==-1)
		return NULL;
	else
	{
		p=new node(x);
		cout<<"Enter to the left of "<<x<<endl;
		p->left=insert();
		cout<<"Enter to the right of "<<x<<endl;
		p->right=insert();
		count1++;

	}

	return p;
}


void Bin_tree::pre_recc(node* T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" ";
		pre_recc(T->left);
		pre_recc(T->right);
	}
}

void Bin_tree::post_recc(node* T)
{
	if(T!=NULL)
	{
		post_recc(T->left);
		post_recc(T->right);
		cout<<T->data<<" ";
	}
}

void Bin_tree::in_recc(node* T)
{
	if(T!=NULL)
	{
		in_recc(T->left);
		cout<<T->data;
		in_recc(T->right);
	}
}
void Bin_tree::delete_node(node* T)
{
	if(T!=NULL)
	{
		delete_node(T->left);
		delete_node(T->right);
		count1=count1-1;
		delete T;
	}



}
int main()
{
	Bin_tree obj;
	int ch,q=0;
	showchoices();
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
		obj.preorder();
		break;
	}
	case 3:
	{
		obj.pre_non_recc();
		break;
	}
	case 4:
	{
		obj.postorder();
		break;
	}
	case 5:
	{
		obj.post_non_recc();
		break;
	}
	case 6:
	{
		obj.inorder();
		break;
	}
	case 7:
	{
		obj.in_non_recc();
		break;
	}
	case 8:
	{
		obj.height();
		break;
	}
	case 9:
	{
		obj.leaf();
		break;
	}
	case 10:
	{
		obj.interior();
		break;
	}
	case 11:
	{
		obj.mirror();
		cout<<"Mirror image of tree is:"<<endl;
		obj.preorder();
		break;
	}
	case 12:
	{
		Bin_tree t;
		t=obj;
		cout<<"Pre-order representation od the copied tree is:"<<endl;
		obj.pre_non_recc();
		break;
	}
	case 13:
	{
		obj.del();
		cout<<"All nodes are deleted"<<endl;
		break;

	}
	}cout<<"Do you want to continue(1 for yes/0 for no)?"<<endl;
	cin>>q;
	}while(q==1);
	return 0;
}
void showchoices()
{
	cout<<"1. Create a binary tree"<<endl;
	cout<<"2. Display preorder(recurrsive)"<<endl;
	cout<<"3. Display preorder(non-recurrsive)"<<endl;
	cout<<"4.Display postorder(recurrsive)"<<endl;
	cout<<"5. Display postorder(non-recurrsive)"<<endl;
	cout<<"6. Display inorder(non-recurrsive)"<<endl;
	cout<<"7. Display inrder(recurrsive)"<<endl;
	cout<<"8. Display the height of tree"<<endl;
	cout<<"9. Display the number of leaf "<<endl;
	cout<<"10. Display the number of interior nodes"<<endl;
	cout<<"11. Create the mirror image of tree"<<endl;
	cout<<"12.To copy a tree into another"<<endl;
	cout<<"13. To delete all nodes of tree"<<endl;
}
