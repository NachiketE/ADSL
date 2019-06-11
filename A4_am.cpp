//============================================================================
// Name        : Ass4_am.cpp
// Author      : Nachiket Erlekar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<queue>
using namespace std;


class graph
{
private:
	int **gr;
	string *cities;
	int max_size,count;
	bool *visited;
public:
	graph(int n=0)
{
		max_size=n;
		gr = new int*[n];
		for(int i=0;i<n;i++)
		{
			gr[i]=new int[n];
		}
		cities= new string[n];
		count=0;
		visited = new bool[n];
}
	void in();
	int get_city(string);
	void add_city();
	void add_path();
	void display();
	void del_city();
	void del_path();
	void indegree();
	void outdegree();
	void dfs(int);
	void bfs();
};

void graph::in()
{
	for(int i=0;i<max_size;i++)
	{
		for(int j=0;j<max_size;j++)
		{
			if(i==j)
				gr[i][j]=-1;
			else
				gr[i][j]=0;
		}
	}
	for(int i=0;i<max_size;i++)
		visited[i]=false;
}
int graph::get_city(string c)
{
	for(int i=1;i<=count;i++)
	{
		if(cities[i]==c)
		{
			return i;
		}
	}
	return 0;
}
void graph::add_city()
{
	count++;
	cout<<"Enter city: ";
	cin>>cities[count];
}
void graph::add_path()
{
	string s,d;
	cout<<"Enter source city: ";
	cin>>s;
	cout<<"Enter destination city: ";
	cin>>d;
	int sn=get_city(s);
	int dn=get_city(d);
	if(sn==0)
	{
		cout<<"Source city isn't added!"<<endl;
		return;
	}
	if(dn==0)
	{
		cout<<"Destination city isn't added!"<<endl;
		return;
	}
	cout<<"Enter the amount of fuel used: ";
	cin>>gr[sn][dn];
}
void graph::display()
{
	for(int i=1;i<=count;i++)
		cout<<cities[i]<<endl;
	for(int i=1;i<=count;i++)
	{
		for(int j=1;j<=count;j++)
		{
			cout<<gr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void graph::del_city()
{
	string d;
	cout<<"Enter the city to be deleted: ";
	cin>>d;
	int in=get_city(d);
	for(int i=in;i<count;i++)
	{
		cities[i]=cities[i+1];
	}
	for(int i=in;i<count;i++)
	{
		for(int j=0;j<=count;j++)
		{
			gr[i][j]=gr[i+1][j];
		}
	}
	for(int i=in;i<count;i++)
	{
		for(int j=0;j<=count;j++)
		{
			gr[i][j]=gr[j][i+1];
		}
	}
	count--;
}
void graph::del_path()
{
	string s,d;
	cout<<"Enter source city: ";
	cin>>s;
	cout<<"Enter destination city: ";
	cin>>d;
	int sn=get_city(s);
	int dn=get_city(d);
	if(sn==0)
	{
		cout<<"Source city isn't added!"<<endl;
		return;
	}
	if(dn==0)
	{
		cout<<"Destination city isn't added!"<<endl;
		return;
	}
	gr[sn][dn]=0;
}
void graph::outdegree()
{
	for(int i=1;i<=count;i++)
	{
		int od=0;
		for(int j=1;j<=count;j++)
		{
			if(gr[i][j]>0)
				od++;
		}
		cout<<"Out-degree of city "<<cities[i]<<" is: "<<od<<endl;
	}
}
void graph::indegree()
{
	for(int i=1;i<=count;i++)
	{
		int id=0;
		for(int j=1;j<=count;j++)
		{
			if(gr[j][i]>0)
				id++;
		}
		cout<<"In-degree of city "<<cities[i]<<" is: "<<id<<endl;
	}
}
void graph::dfs(int v)
{
	visited[v]=true;
	cout<<cities[v]<<endl;
	for(int j=1;j<=count;j++)
	{
		if(gr[v][j]>0&&!visited[j])
		{
			dfs(j);
		}
	}
}
void graph::bfs()
{
	bool con[count+1];
	for(int i=1;i<=count;i++)
	{
		con[i]=false;
		visited[i]=false;
	}
	queue<int>q;
	q.push(1);
	visited[1]=true;
	con[1]=true;
	cout<<cities[1]<<endl;
	while(!q.empty())
	{
		int in=q.front();
		q.pop();
		for(int j=1;j<=count;j++)
		{
			if(gr[in][j]>0&&!visited[j])
			{
				visited[j]=true;
				cout<<cities[j]<<endl;
				if(!con[j])
				{
					q.push(j);
					con[j]=true;
				}
			}
		}
	}
}


int main()
{
	graph g(10);
	g.in();
	int choice;
	while(1)
	{
		cout<<"Enter choice\n1.Add city\n2.Delete city\n3.Add path\n4.Delete path\n5.Indegree\n6.Outdegree\n7.DFS\n8.BFS\n9.Display\n10.Exit\n";
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
			g.dfs(1);
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









