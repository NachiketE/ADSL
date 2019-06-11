#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <iomanip> 
#include<cstdlib> 

using namespace std; 
class phoneBook{ 
    char name[10],add[10];
    int div,roll; 
    public: 
    void getdata(); 
    void showdata(); 
    char *getname(){ return name; } 
    int getroll(){ return roll; } 
    
    void update ( char *nm,char *addr, int divi )
    { 
        strcpy(name,nm); 
        strcpy(add,addr);
         div=divi;
    } 
}; 

void phoneBook :: getdata(){ 
    cout<<"\nEnter Name : "; 
    cin>>name; 
    cout<<"\nEnter Roll Number : "; 
    cin>>roll; 
    cout<<"\nEnter Division : "; 
    cin>>div; 
    cout<<"\nEnter City : "; 
    cin>>add; 
} 

void phoneBook :: showdata()
{  
    cout<<"\n\nName-: "<<name; 
    cout<<"\nRoll Number-: "<<roll;
    cout<<"\nDivision-:"<<div;
    cout<<"\nCity-: "<<add<<"\n"; 
} 


int  main() 
{ 
    phoneBook rec; 
    fstream file; 
    file.open("data.dat", ios::ate | ios::in | ios::out | ios::binary); 
    char ch,nm[10],addr[10]; 
    int choice,found=0;
    int roll,div; 
    while(1) 
    { 
        //clrscr(); 
        cout<<"\n*****Department Students*****\n"; 
        cout<<"1) Add New Record\n"; 
        cout<<"2) Display All Records\n";  
        cout<<"3) Search Person Name\n"; 
        cout<<"4) Search Roll No.\n";
        cout<<"5) Update Information\n"; 
        cout<<"6) Exit\n"; 
        cout<<"Choose your choice : "; 
        cin>>choice; 
        int cnt=0; 

        switch(choice) 
        { 
            case 1 : //New Record 
                 rec.getdata(); 
                 cin.get(ch); 
                 file.write((char *) &rec, sizeof(rec)); 
                 break; 

            case 2 : //Display All Records 
                 file.seekg(0,ios::beg); 
                 cout<<"\n\n================Records in Phone Book===================\n"; 
                 while(file)
                 { 
                    file.read((char *) &rec, sizeof(rec)); 
                    if(!file.eof()) 
                    {
                    	cout<<"\n---------------------------------------------------";
                        rec.showdata(); 
                        cout<<"\n---------------------------------------------------";
                    }
                 } 
                 file.clear(); 
                 break; 

            case 3 : //Search when person name is known. 
                 cout<<"\n\nEnter Name : "; 
                 cin>>nm; 
                 file.seekg(0,ios::beg); 
                 found=0; 
                 while(file.read((char *) &rec, sizeof(rec))) 
                 { 
                    if(strcmp(nm,rec.getname())==0) 
                    { 
                        found=1; 
                        rec.showdata(); 
                    } 
                 } 
                 file.clear(); 
                 if(found==0) 
                    cout<<"\n\n---Record Not found---\n"; 
                // getch(); 
                 break; 

            case 4 : //Search name on basis of roll no. 
                 cout<<"\n\nEnter Roll No : "; 
                 cin>>roll; 
                 file.seekg(0,ios::beg); 
                 found=0; 
                 while(file.read((char *) &rec, sizeof(rec))) 
                 { 
                    if(roll==rec.getroll()) 
                    { 
                        found=1; 
                        rec.showdata(); 
                    } 
                 } 
                 file.clear(); 
                 if(found==0) 
                    cout<<"\n\n---Record Not found---\n"; 
                // getch(); 
                 break; 

            case 5 : //Update Information. 
                 cout<<"\n\nEnter Roll No : "; 
                 cin>>roll; 
                 file.seekg(0,ios::beg); 
                 found=0; 

                 while(file.read((char *) &rec, sizeof(rec))) 
                 { 
                    cnt++; 
                    if(rec.getroll()==roll) 
                    { 
                        found=1; 
                        break; 
                    } 
                 } 
                 file.clear(); 
                 if(found==0) 
                    cout<<"\n\n---Record Not found---\n"; 
                 else 
                 { 
                    int location = (cnt-1) * sizeof(rec); 
                    cin.get(ch); 
                    if(file.eof()) 
                        file.clear(); 

                    cout<<"Enter Updated name : "; 
                    cin>>nm;
                    cout<<"\nEnter Updated Division-: ";
                    cin>>div;
                    cout<<"\nEnter Updated Address-: ";
                    cin>>addr; 
                    file.seekp(location); 
                    
                    rec.update(nm,addr, div); 
                    
                    file.write((char *) &rec, sizeof(rec)); 
                    file.flush(); 
                 } 
                 break; 
            case 6 : exit(1); 
            		break; 
        } 

    } 

file.close(); 
} 
/*
shreyas@shreyas:~/2416/A10$ g++ A10.cpp
shreyas@shreyas:~/2416/A10$ ./a.out

*****Department Students*****
1) Add New Record
2) Display All Records
3) Search Roll No.
4) Search Person Name
5) Update Information
6) Exit
Choose your choice : 1

Enter Name : shreyas

Enter Roll Number : 2416

Enter Division : 4  

Enter City : Pune

*****Department Students*****
1) Add New Record
2) Display All Records
3) Search Roll No.
4) Search Person Name
5) Update Information
6) Exit
Choose your choice : 2


================Records in Phone Book===================

---------------------------------------------------

Name-: chinmay
Roll Number-: 2166
Division-:1
City-: jalgaon

---------------------------------------------------
---------------------------------------------------

Name-: sid
Roll Number-: 2162
Division-:1
City-: nashik

---------------------------------------------------
---------------------------------------------------

Name-: dev
Roll Number-: 2144
Division-:1
City-: nashik

---------------------------------------------------
---------------------------------------------------

Name-: rushi
Roll Number-: 2241
Division-:2
City-: nashik

---------------------------------------------------
---------------------------------------------------

Name-: vikas
Roll Number-: 21256
Division-:1
City-: nanded

---------------------------------------------------
---------------------------------------------------

Name-: shreyas
Roll Number-: 2416
Division-:4
City-: Pune

---------------------------------------------------
*****Department Students*****
1) Add New Record
2) Display All Records
3) Search Roll No.
4) Search Person Name
5) Update Information
6) Exit
Choose your choice : 3


Enter Name : shreyas


Name-: shreyas
Roll Number-: 2416
Division-:4
City-: Pune

*****Department Students*****
1) Add New Record
2) Display All Records
3) Search Roll No.
4) Search Person Name
5) Update Information
6) Exit
Choose your choice : 5


Enter Roll No : 2416
Enter Updated name : Shreyas

Enter Updated Division-: 1

Enter Updated Address-: Mumbai

*****Department Students*****
1) Add New Record
2) Display All Records
3) Search Roll No.
4) Search Person Name
5) Update Information
6) Exit
Choose your choice : 2


================Records in Phone Book===================

---------------------------------------------------

Name-: chinmay
Roll Number-: 2166
Division-:1
City-: jalgaon

---------------------------------------------------
---------------------------------------------------

Name-: sid
Roll Number-: 2162
Division-:1
City-: nashik

---------------------------------------------------
---------------------------------------------------

Name-: dev
Roll Number-: 2144
Division-:1
City-: nashik

---------------------------------------------------
---------------------------------------------------

Name-: rushi
Roll Number-: 2241
Division-:2
City-: nashik

---------------------------------------------------
---------------------------------------------------

Name-: vikas
Roll Number-: 21256
Division-:1
City-: nanded

---------------------------------------------------
---------------------------------------------------

Name-: Shreyas
Roll Number-: 2416
Division-:1
City-: Mumbai

---------------------------------------------------
*****Department Students*****
1) Add New Record
2) Display All Records
3) Search Roll No.
4) Search Person Name
5) Update Information
6) Exit
Choose your choice : 6
shreyas@shreyas:~/2416/A10$ 
*/
