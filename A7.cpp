//============================================================================
// Name        : Assignment7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

class Node
{
	string key,type,ival;
	int chain;

public:

	friend class HashTable;

};

class HashTable
{
	Node HT[30];
	int n;

public:

	HashTable()
{
		n=0;
		for(int i=0;i<30;i++)
		{
			HT[i].key="#";
			HT[i].chain=-1;
		}

}

	void create();
	void withoutInsert(Node);
	void withInsert(Node);
	void find();
	void del();
	void modify();

};

int main()
{
	HashTable obj;
	int l;
	char ans;

	obj.create();
	do
	{
		ab:
		cout<<"\n\n\t\t\tMENU";
		cout<<"\n1.RETRIEVE.";
		cout<<"\n2.DELETE.";
		cout<<"\n3.MODIFY.";
		cout<<"\n4.EXIT.";
		cout<<"\n\nCHOOSE AN OPTION FROM ABOVE MENU:- ";
		cin>>l;

		switch(l)
		{

		case 1:

			obj.find();

			break;

		case 2:

			obj.del();

			break;

		case 3:

			obj.modify();

			break;

		case 4:

			exit(0);

		default:

			cout<<"\n\n\nCHOOSE AN OPTION FROM ABOVE MENU ONLY.";
			goto ab;


		}//switch casehttps://www.google.com/gmail/

		cout<<"\n\nDO YOU WANT TO CONTINUE:- ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');


	return 0;
}


void HashTable::create()
{
	int ch;

	cout<<"\nENTER THE NUMBER OF IDENTIFIERS(SYMBOLS) TO BE STORED:- ";
	cin>>n;


	cout<<"\n\n\t\t\tMENU";
	cout<<"\n1.WITHOUT REPLACEMENT.";
	cout<<"\n2.WITH REPLACEMENT.";
	cout<<"\n\nENTER TYPE OF LINEAR PROBING:- ";
	cin>>ch;


	for(int i=0;i<n;i++)
	{
		Node nn;

		cout<<"\n"<<i+1<<" ENTRY";
		cout<<"\nENTER IDENTIFIER(SYMBOL) NAME:- ";
		cin>>nn.key;
		cout<<"\nENTER DATA TYPE:- ";
		cin>>nn.type;
		cout<<"\nENTER THE INITIAL VALUE:- ";
		cin>>nn.ival;

		if(ch==1)
			withoutInsert(nn);
		if(ch==2)
			withInsert(nn);
	}
}

void HashTable::withoutInsert(Node nn)
{
	int l,u,v,i;

	l=nn.key.length()%n;

	if(HT[l].key=="#")
	{
		HT[l]=nn;
		HT[l].chain=-1;
	}

	else
	{
		v=l;
		u=HT[l].chain;

		while(u!=-1)
		{
			v=u;
			u=HT[v].chain;
		}//while

		for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
		HT[i]=nn;
		HT[v].chain=i;
		HT[i].chain=-1;

	}

	for(int i=0;i<n;i++)
		cout<<"\n"<<HT[i].key<<"\t"<<HT[i].chain;


}

void HashTable::withInsert(Node nn)
{
	int l,u,v,i;

	l=nn.key.length()%n;

	if(HT[l].key=="#")
	{
		HT[l]=nn;
		HT[l].chain=-1;
	}

	else if(HT[l].key.length()%n==l)
	{
		v=l;
		u=HT[l].chain;

		while(u!=-1)
		{
			v=u;
			u=HT[v].chain;
		}//while

		for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
		HT[i]=nn;
		HT[v].chain=i;
		HT[i].chain=-1;

	}

	else
	{
		Node temp;
		temp=HT[l];


		HT[l]=nn;
		HT[l].ival=nn.ival;
		HT[l].chain=-1;

		for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
		HT[i]=temp;
		HT[i].chain=-1;

		int k;
		for(k=0;HT[k].chain!=l;k=(k+1)%n);
		HT[k].chain=i;
		HT[i].chain=-1;

	}//else

	for(int i=0;i<n;i++)
		cout<<"\n"<<HT[i].key<<"\t"<<HT[i].chain;

}

void HashTable::find()
{
	string k;
	int u,v,l;

	cout<<"\nENTER THE KEY OF THE ELEMENT TO RETRIEVE:- ";
	cin>>ws;
	getline(cin,k);

	l=k.length()%n;

	if(HT[l].key==k)
	{
		cout<<"\nFOUND.";
		cout<<"\n"<<HT[l].key<<"  "<<HT[l].type<<"  "<<HT[l].ival;
	}

	else
	{
		v=l;
		u=HT[l].chain;

		while(u!=-1 && HT[v].key!=k)
		{
			v=u;
			u=HT[v].chain;
		}

		if(HT[v].key==k)
		{
			cout<<"\nFOUND.";
			cout<<"\n"<<HT[v].key<<"  "<<HT[v].type<<"  "<<HT[v].ival;
		}

		else
			cout<<"\nENTRY NOT FOUND.";


	}


}

void HashTable::del()
{
	string k;
	int u,v,w,l;

	cout<<"\nENTER THE KEY OF THE ELEMENT TO DELETE:- ";
	cin>>ws;
	getline(cin,k);

	l=k.length()%n;

	if(HT[l].key==k)
	{
		HT[l].key="#";
		HT[l].type="";
		HT[l].ival="";
		v=HT[l].chain;

		if(v!=-1)
		{
			HT[l]=HT[v];

			HT[v].key="#";
			HT[v].type="";
			HT[v].ival="";
			HT[v].chain=-1;

		}

		cout<<"\n\nDELETE SUCCESSFUL.\n";
	}

	else
	{
		v=l;
		u=HT[l].chain;

		while(u!=-1 && HT[v].key!=k)
		{
			w=v;
			v=u;
			u=HT[v].chain;
		}

		if(HT[v].key==k)
		{
			HT[v].key="#";
			HT[v].type="";
			HT[v].ival="";
			HT[v].chain=-1;
			HT[w].chain=HT[v].chain;
			cout<<"\nDELETE SUCCESSFUL.\n";
		}

		else
			cout<<"\nENTRY DOES NOT EXSIST.";
	}//else

	for(int i=0;i<n;i++)
		cout<<"\n"<<HT[i].key<<"\t"<<HT[i].chain;
}

void HashTable::modify()
{
	string newval,k;
	int u,v,l;

	cout<<"\nENTER KEY OF THE ELEMENT TO MODIFY:- ";
	cin>>ws;
	getline(cin,k);

	cout<<"\nENTER THE NEW INITIAL VALUE:- ";
	cin>>ws;
	getline(cin,newval);

	l=k.length()%n;

	if(HT[l].key==k)
		HT[l].ival=newval;

	else
	{
		v=l;
		u=HT[l].chain;

		while(u!=-1 && HT[v].key!=k)
		{
			v=u;
			u=HT[v].chain;
		}//while

		if(HT[v].key==k)
			HT[v].ival=newval;
		else
			cout<<"\nENTRY DOES NOT EXSIST.";

	}//else

}


