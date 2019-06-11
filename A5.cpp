//============================================================================
// Name        : A5.cpp
// Author      : Nachiket Erlekar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
  using namespace std;

  class Graph{
  	int **Gmat;
  	int n;
  public:
  	Graph(int d){
  	n=d;
	  	Gmat=new int*[n];
	  	for(int i=0;i<n;i++)
	  	Gmat[i]=new int[n];

	  	for(int i=0;i<n;i++)
  	  		for(int j=0;j<n;j++)
	  			Gmat[i][j]=-1;
  	}
  void create();
  void prims();
  void kruskals();

  };


  void Graph::kruskals(){
  int min;
  int parent[n];
  int result[n][n];
  int u=0;
  int v=0;
  int noofedges=1;
   int G[n][n];

  	for(int i=0;i<n;i++)
  		for(int j=0;j<n;j++)
  			G[i][j]=Gmat[i][j];


  for(int i=0;i<n;i++){

  		parent[i]=-1;

  		for(int j=0;j<n;j++){
  		if(G[i][j]==-1)
  				G[i][j]=999;
  			result[i][j]=0;
  		}}
  while(noofedges<n){
  	min=999;
  		for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  		if(G[i][j]<min)
  		{min=G[i][j];
  		u=i;
  		v=j;}
  		}
  		}
  		int x=u;
  		int y=v;
  	G[u][v]=G[v][u]=999;
  	int rt1,rt2;
  	while(u>=0){
  	rt1=u;
  	u=parent[u];
  	}

  	while(v>=0){
  	rt2=v;
  	v=parent[v];
  	}

  		if(rt1!=rt2)
  		{noofedges++;
  		result[x][y]=min;
  		result[y][x]=min;
  		parent[rt2]=rt1;
  		}

  }
    cout<<"\nMinimum spanning tree Matrix is: \n";


    int sum=0;
    for(int i=0;i<n;i++)
{
cout<<"\n";
	for(int j=0;j<n;j++){
		cout<<result[i][j]<<"\t";
	sum=sum+result[i][j];
	}
	}
cout<<"\nCost is: "<<sum/2;



  }

  void Graph::prims(){
  int result[n][n];
  int visited[n];
  int min;
  int u=0;
  int v=0;
  int G[n][n];

  	for(int i=0;i<n;i++)
  		for(int j=0;j<n;j++)
  			G[i][j]=Gmat[i][j];

  	for(int i=0;i<n;i++){

  		visited[i]=0;

  		for(int j=0;j<n;j++){
  			if(G[i][j]==-1)
  				G[i][j]=999;
  			result[i][j]=0;
  		}}


  	visited[0]=1;
  for(int counter=0;counter<n-1;counter++)
	{
  		min=999;
  		for(int i=0;i<n;i++)
  		{
  		if(visited[i]==1)
  			{
  			for(int j=0;j<n;j++)
  			{
  			if(visited[j]!=1)
  				{
  				if(min>G[i][j])
  				{
  				min=G[i][j];
  				u=i;
  				v=j;
  				}
  				}
  			}
  			}
  		}
  		visited[v]=1;
  		result[u][v]=min;
  		result[v][u]=min;
  }


  cout<<"\nMinimum spanning tree Matrix is: \n";
  int sum=0;
  for(int i=0;i<n;i++)
{
cout<<"\n";
	for(int j=0;j<n;j++){
		cout<<result[i][j]<<"\t";
	sum=sum+result[i][j];
	}
	}
cout<<"\nCost is: "<<sum/2;


  }

  void Graph::create(){
  		char ch,ch1;
  		int u,v,w;
  		do{
  		cout<<"\nEnter starting office number";
		cin>>u;
		cout<<"\nEnter ending office number";
		cin>>v;

		  if(u>=n){
		  	cout<<"\nInvalid office number";
		  	continue;
		  }
		  if(v>=n){
		  cout<<"\nInvalid office number";
		  	continue;
		  }

		  if(Gmat[u][v]!=-1){
			  cout<<"\nAlready added\n Do you want to change amount?";
			  cin>>ch1;
			  if(ch1=='n'||ch1=='N')
			  	continue;
		  }
		  cout<<"\nEnter Amount";
		  cin>>w;
		  if(w>0){
		 	Gmat[u][v]=w;
		 	Gmat[v][u]=w;
		 	 }
		  else{
		  	cout<<"\nInvalid Amount\n ENTER AGAIN";
			continue;
	  		}
	  		cout<<"\nDo you want to add another?";
	  		cin>>ch;

  }while(ch=='y'||ch=='Y');


  }


  int main(){
  int n;
  cout<<"\nEnter number of offices: ";
  cin>>n;
  Graph obj(n);
  obj.create();
	  do{
	  cout<<"\nCompute MINIMUM SPANNING TREE by:\n\t 1. Prim's Algorithm\n\t 2. Kruskal's Algorithm\n3. EXIT";
	  cin>>n;
	  if(n==1)
	  obj.prims();
	  if(n==2)
	  obj.kruskals();
	  }while(n!=3);
  return 0;
  }
  /*


Enter number of offices: 4

Enter starting office number0

Enter ending office number3

Enter Amount50

Do you want to add another?y

Enter starting office number1

Enter ending office number2

Enter Amount12

Do you want to add another?y

Enter starting office number0

Enter ending office number3

Already added
 Do you want to change amount?n

Enter starting office number1

Enter ending office number2

Already added
 Do you want to change amount?n

Enter starting office number0

Enter ending office number1

Enter Amount44

Do you want to add another?y

Enter starting office number0

Enter ending office number2

Enter Amount36

Do you want to add another?y

Enter starting office number1

Enter ending office number2

Already added
 Do you want to change amount?n

Enter starting office number0

Enter ending office number3

Already added
 Do you want to change amount?y

Enter Amount44

Do you want to add another?n

Compute MINIMUM SPANNING TREE by:
	 1. Prim's Algorithm
	 2. Kruskal's Algorithm
3. EXIT1

Minimum spanning tree Matrix is: 

0	0	36	44	
0	0	12	0	
36	12	0	0	
44	0	0	0	
Cost is: 92
Compute MINIMUM SPANNING TREE by:
	 1. Prim's Algorithm
	 2. Kruskal's Algorithm
3. EXIT2

Minimum spanning tree Matrix is: 

0	0	36	44	
0	0	12	0	
36	12	0	0	
44	0	0	0	
Cost is: 92
Compute MINIMUM SPANNING TREE by:
	 1. Prim's Algorithm
	 2. Kruskal's Algorithm
3. EXIT3
shreyas@shreyas:~/2416$ 
*/
