//============================================================================
// Name        : Assignment 12
// Author      : Gaurav Kshirsagar
// Batch       : F-10
// Class       : SE-10
// Roll No     : 23228
//============================================================================

#include <iostream>
//#include "DAF.h"
#include<fstream>
#include<iomanip>
using namespace std;
struct student{
	char name[20];
	//string name;
	int roll_no;
	//string dept;
	char dept[5];
	int marks;
	int chain;
};

class DAF{

	student sg;
	student sp;

public:
	DAF();
	virtual ~DAF();
	inline int index_calc(int);
	void init();
	void create();
	void display();
	void add_record();
	int search_record(int);
	int modify_record(int);
};

/* DAF_H_ */
DAF::DAF() {
	// TODO Auto-generated constructor stub
	sg.chain=-1;
	sp.chain=-1;
}

DAF::~DAF() {
	// TODO Auto-generated destructor stub
}

void DAF::init()
{
	ofstream fout;

			fout.open("data.dat",ios::out |ios::binary );


			sp.name[0]='$';
			sp.roll_no=-1;
			sp.dept[0]='$';
			sp.marks=-1;
			sp.chain=-1;

			for(int i=0;i<10;i++)
				fout.write((char*)&sp,sizeof(sp));

			fout.close();
}

inline int DAF::index_calc(int x)
{
	return(x%10);
}

void DAF::create()
{
	fstream fp;

	int index,temp2,temp;

	fp.open("data.dat",ios::in|ios::out|ios::binary);

	cout<<"Enter name :";
	cin>>sp.name;
	cout<<"Enter roll no :";
	cin>>sp.roll_no;
	cout<<"Enter department :";
	cin>>sp.dept;
	cout<<"Enter marks :";
	cin>>sp.marks;

	index=index_calc(sp.roll_no);


	fp.seekg((sizeof(sg))*index,ios::beg);
	fp.read((char*)&sg,sizeof(sg));


	if(sg.roll_no==-1)
	{
		fp.seekp((sizeof(sp))*index,ios::beg);
		fp.write((char*)&sp,sizeof(sp));
		return;
	}

	temp2=index;

	while(temp2!=index_calc(sg.roll_no) && sg.roll_no!=-1)
	{
			index=(index+1)%10;
			fp.seekg((sizeof(sg))*index,ios::beg);
			fp.read((char*)&sg,sizeof(sg));
	}

	while(sg.chain!=-1) //Now using chain bits go till end of chain for given index
	{
				index=sg.chain;
				fp.seekg((sizeof(sg))*index,ios::beg);
				fp.read((char*)&sg,sizeof(sg));
	}

	temp=index;
	fp.seekg((sizeof(sg))*temp,ios::beg);
	fp.read((char*)&sg,sizeof(sg));

		while(sg.roll_no!=-1) //Now increment index by one till we get empty place to store new record
			{
				temp=(temp+1)%10;
				fp.seekg((sizeof(sg))*temp,ios::beg);
				fp.read((char*)&sg,sizeof(sg));

			}


	if(index!=temp)
	{
		fp.seekg((sizeof(sg))*index,ios::beg);
		fp.read((char*)&sg,sizeof(sg));
		sg.chain=temp;

		fp.seekp((sizeof(sg))*index,ios::beg);
		fp.write((char*)&sg,sizeof(sg));

	}

	fp.seekp((sizeof(sp))*temp,ios::beg);
	fp.write((char*)&sp,sizeof(sp));



	fp.close();
}


void DAF::display()
{
	ifstream fin;
	fin.open("data.dat",ios::in|ios::binary);

	cout<<"----------------------------------------------------------------\n";
	cout<<"|   Name    |  Roll No  |  Department  |   Marks   |   Chain   |\n";
	cout<<"----------------------------------------------------------------\n";

	while(fin.read((char*)&sg,sizeof(sg)))
	{
		 cout<<"|"<<setw(11)<<sg.name<<"|"<<setw(11)<<sg.roll_no<<"|"<<setw(14)<<sg.dept<<"|"<<setw(11)<<sg.marks<<"|"<<setw(11)<<sg.chain<<"|"<<endl;
	}

	cout<<"----------------------------------------------------------------\n";

	fin.close();
}


int DAF::search_record(int x)
{

	fstream fp;
	fp.open("data.dat",ios::in|ios::out|ios::binary);

	int index=index_calc(x);
	fp.seekg((sizeof(sg))*(index+1),ios::beg);
	fp.read((char*)&sg,sizeof(sg));

	if(sg.roll_no==-1)
	{
		cout<<"Record not found";
		return -1;
	}

		while(1)
		{
			if(sg.roll_no==x)
				{
					cout<<"\n Record found at index "<<index;


					cout<<"\n----------------------------------------------------------------\n";
					cout<<"|   Name    |  Roll No  |  Department  |   Marks   |   Chain   |\n";
					cout<<"----------------------------------------------------------------\n";
					cout<<"|"<<setw(11)<<sg.name<<"|"<<setw(11)<<sg.roll_no<<"|"<<setw(14)<<sg.dept<<"|"<<setw(11)<<sg.marks<<"|"<<setw(11)<<sg.chain<<"|"<<endl;
					cout<<"----------------------------------------------------------------\n";

					return index;


				}
			else if(sg.chain==-1 && index_calc(sg.roll_no)==index)
				{
					cout<<"Record not found";
					return -1;
				}
			else
			{
				if(index_calc(sg.roll_no)!=index)
					index=(index+1)%10;
				else
					index=sg.chain;

				fp.seekg((sizeof(sg))*index,ios::beg);
				fp.read((char*)&sg,sizeof(sg));

			}

		}

}

int DAF::modify_record(int x)
{
		fstream fp;
		int ch;
		fp.open("data.dat",ios::in|ios::out|ios::binary);

		int index=index_calc(x);
		fp.seekg((sizeof(sg))*index,ios::beg);
		fp.read((char*)&sg,sizeof(sg));

			if(sg.roll_no==-1)
			{
				cout<<"Record not found";
				return -1;
			}


			while(1)
			{
				if(sg.roll_no==x)
					{
						cout<<"Record found at index "<<index;

						cout<<"Select field to modify :\n1.name\n2.dept\n3.marks\n";
										cout<<"Enter choice : ";
										cin>>ch;

										switch(ch)
										{
											case 1:cout<<"Enter modified name: ";
											cin>>sg.name;
											break;

											case 2:cout<<"Enter modified dept: ";
											cin>>sg.dept;
											break;

											case 3:cout<<"Enter modified marks: ";
											cin>>sg.marks;
											break;

											default:	break;
										}

						fp.seekp((sizeof(sg))*index,ios::beg);
						fp.write((char*)&sg,sizeof(sg));



						return index;
					}
				else if(sg.chain==-1 && index_calc(sg.roll_no)==index)
					{
						cout<<"Record not found";
						return -1;
					}
				else
				{
					if(index_calc(sg.roll_no)!=index)
						index=(index+1)%10;
					else
						index=sg.chain;

					fp.seekg((sizeof(sg))*index,ios::beg);
					fp.read((char*)&sg,sizeof(sg));

				}

			}

}

int main() {

	DAF s;
	int ch,n,i,roll;





	do
	{

			cout<<"\nMenu\n1:Create New Database \n2:Display records\n3:Add Record(s)\n4:Search Record\n5:Modify Record\n6:Exit\n";
			cout<<"\nEnter choice : ";
			cin>>ch;


	switch(ch)
	{

	case 1: s.init();
			cout<<"\n*** Database Created  Successfully*** \n";
			s.display();
			break;

	case 2: s.display();
			break;

	case 3: cout<<"Enter no of records you want to add :";
			cin>>n;
			for(i=1;i<=n;i++)
				s.create();

			cout<<"\n*** Records Added Successfully*** \n";
			s.display();
			break;

	case 4: s.display();
			cout<<"Enter roll no of student to search record: ";
			cin>>roll;
			s.search_record(roll);
			break;


	case 5: s.display();
			cout<<"Enter roll no of student to modify record: ";
				cin>>roll;
				if(s.modify_record(roll)!=-1)
				{
					cout<<"*** Record Successfully Modified ***\n";
					s.display();
				}


		    break;

	case 6:
			break;

	}

	}while(ch!=6);


	return 0;
}
