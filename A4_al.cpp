//============================================================================
// Name        : Ass4_al.cpp
// Author      : Nachiket Erlekar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<cstdlib>
#include<queue>
using namespace std;

class graph;
class node
{
private:
	node *next,*down;
	string city;
public:
	node()
{
		next=NULL;
		down=NULL;
}
	friend class graph;
};

class graph
{
private:
	string *arr;
	int count=0;
	bool *visited;
public:
	graph()
{
		start=NULL;
		arr=new string[20];
		visited=new bool[20];
		for(int i=0;i<20;i++)
			visited[i]=false;
		count=0;
}
	node *start;
	void add_city();
	void add_path();
	node *find_h(node *,string);
	node *find_v(string);
	void del_path();
	void display();
	void del_city();
	void del_nodes(node *);
	void outdegree();
	void indegree();
	int get_index(string);
	void dfs(node *);
	void bfs();
};

void graph::add_city()
{
	node *temp=new node;
	cout<<"Enter the city: ";
	cin>>temp->city;
	count++;
	arr[count]=temp->city;
	if(start==NULL)
	{
		start=temp;
		return;
	}
	node *cur=start;
	while(cur->down!=NULL)
		cur=cur->down;
	cur->down=temp;
}
node *graph::find_v(string c)
{
	node *cur=start;
	while(cur!=NULL)
	{
		if(cur->city==c)
			return cur;
		cur=cur->down;
	}
	return NULL;
}
node *graph::find_h(node *f,string s)
{
	while(f->next!=NULL)
	{
		if(f->next->city==s)
			return f;
		f=f->next;
	}
	return NULL;
}
void graph::add_path()
{
	string s;
	cout<<"Enter the source city: ";
	cin>>s;
	node *temp=new node;
	cout<<"Enter the destination city: ";
	cin>>temp->city;
	if(find_v(s)==NULL||find_v(temp->city)==NULL)
	{
		cout<<"Enter valid cities!"<<endl;
		return;
	}
	node *f=find_v(s);
	while(f->next!=NULL)
		f=f->next;
	f->next=temp;
}
void graph::del_path()
{
	string s,d;
	cout<<"Enter the source city: ";
	cin>>s;
	cout<<"Enter the destination city: ";
	cin>>d;
	if(find_v(s)==NULL||find_v(d)==NULL)
	{
		cout<<"Enter valid cities!"<<endl;
		return;
	}
	node *f = find_v(s);
	node *temp=find_h(f,d);
	if(temp==NULL)
	{
		cout<<"Path non-existent!"<<endl;
		return;
	}
	node *p=temp->next;
	temp->next=p->next;
	p->next=NULL;
	delete p;
}
void graph::display()
{
	node *cur=start;
	while(cur!=NULL)
	{
		node *temp=cur;
		while(temp!=NULL)
		{
			cout<<temp->city<<" ";
			temp=temp->next;
		}
		cout<<endl;
		cur=cur->down;
	}
}
void graph::del_city()
{
	string d;
	cout<<"Enter the city to be deleted: ";
	cin>>d;
	node *f=find_v(d);
	if(f==NULL)
	{
		cout<<"Enter a valid city!"<<endl;
		return;
	}
	if(start==f)
	{
		start=start->down;
	}
	else
	{
		node *cur=start;
		while(cur->down->city!=d)
			cur=cur->down;
		node *temp=cur->down;
		cur->down=temp->down;
		temp->down=NULL;
	}
	del_nodes(f);
	node *cur=start;
	while(cur!=NULL)
	{
		node *temp1=find_h(cur,d);
		node *temp2=temp1->next;
		temp1->next=temp2->next;
		free(temp2);
		cur=cur->down;
	}
	int in=get_index(d);
	for(int i=in;i<count;i++)
	{
		arr[i]=arr[i+1];
	}
	count--;
}
void graph::del_nodes(node *f)
{
	if(f==NULL)
		return;
	del_nodes(f->next);
	free(f);
}
void graph::outdegree()
{
	int od;
	node *cur=start;
	while(cur!=NULL)
	{
		od=0;
		node *temp=cur;
		while(temp!=NULL)
		{
			od++;
			temp=temp->next;
		}
		cout<<"Out-degree of city "<<cur->city<<" is: "<<od-1<<endl;
		cur=cur->down;
	}
}
void graph::indegree()
{
	int id;
	node *cur=start;
	while(cur!=NULL)
	{
		id=0;
		string c=cur->city;
		node *temp=start;
		while(temp!=NULL)
		{
			node *p=find_h(temp,c);
			if(p!=NULL)
			{
				id++;
			}
			temp=temp->down;
		}
		cout<<"In-degree of city "<<cur->city<<" is: "<<id<<endl;
		cur=cur->down;
	}
}
int graph::get_index(string city)
{
	for(int i=1;i<=count;i++)
	{
		if(arr[i]==city)
			return i;
	}
	return 0;
}
void graph::dfs(node *start)
{
	cout<<start->city<<endl;
	int i=get_index(start->city);
	visited[i]=true;
	for(node *cur=start;cur!=NULL;cur=cur->next)
	{
		int j=get_index(cur->city);
		if(!visited[j])
		{
			node *temp=find_v(cur->city);
			dfs(temp);
		}
	}
}
void graph::bfs()
{
	bool *cons=new bool[count+1];
	queue<int>q;
	for(int i=1;i<=count;i++)
	{
		visited[i]=false;
		cons[i]=false;
	}
	q.push(get_index(start->city));
	cons[get_index(start->city)]=true;
	while(!q.empty())
	{
		node *cur=find_v(arr[q.front()]);
		q.pop();
		for(node *temp=cur;temp!=NULL;temp=temp->next)
		{
			int ind=get_index(temp->city);
			if(!visited[ind])
			{
				visited[ind]=true;
				cout<<temp->city<<endl;
			}
			if(!cons[ind])
			{
				cons[ind]=true;
				q.push(ind);
			}
		}
	}

}


int main()
{
	graph g;
	int choice;
	while(1)
	{
		cout<<"Enter choice\n1.Add city\n2.Delete city\n3.Add path\n4.Delete path\n5.In-degree\n6.Out-degree\n7.DFS\n8.BFS\n9.Display\n10.Exit\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			g.add_city();
			break;
		case 2:
			g.del_city();
			break;
		case 3:
			g.add_path();
			break;
		case 4:
			g.del_path();
			break;
		case 5:
			g.indegree();
			break;
		case 6:
			g.outdegree();
			break;
		case 7:
			g.dfs(g.start);
			break;
		case 8:
			g.bfs();
			break;
		case 9:
			g.display();
			break;
		case 10:
			return 0;
		}
	}
	return 0;
}









