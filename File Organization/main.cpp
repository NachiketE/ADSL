#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    int rollno;
    char name[20];
    char div;
    int link;
    bool isdeleted;

public:
    Student();

    Student(int r, string s, char d);

    void getData();

    void printData();

    friend class File;
};

class Index
{
    public:
    int flag;
    int ptr;

    Index()
    {
        flag = 0;
        ptr = -1;
    }
    friend class File;
};

class File
{
    fstream fileObj;
    string name;
    string indexFile;
    Index index;

public:
    File(string s, string i);

    void insert(Student s);

    void read(int r);

    void update(Student s);

    void remove(int r);

    int hash(int r);
};

int main()
{
    Student s;
    File file("data.txt","index.txt");
    int choice;
    int r;
    do{
        cout<<"****************************** MENU ***********************************"<<endl;
        cout<<"1.Insert Record.\n2.Search Record.\n3.Update Record.\n4.Remove Record\n0.Exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                s.getData();
                file.insert(s);
                break;
            case 2:
                cout<<"Enter Roll No : ";
                cin>>r;
                file.read(r);
                break;
            case 3:
                cout<<"Enter Updated Record "<<endl;
                s.getData();
                file.update(s);
                break;
            case 4:
                cout<<"Enter roll no. to be deleted : ";
                cin>>r;
                file.remove(r);
                break;
            case 0:
                break;
            default:
                cout<<"Invalid choice !"<<endl;
        }
        cout<<endl;
    }while(choice != 0);
    return 0;
}

//Student class Functions
Student::Student()
{
    rollno = -1;
    div = ' ';
    link = -1;
    isdeleted = false;
}

Student::Student(int r, string s, char d)
{
    rollno = r;
    for(int i = 0; s[i] != '\0'; i++){
        name[i] = s[i];
    }
    div = d;
    link = -1;
}

void Student::getData()
{
    cout << "Enter roll no, name and division of student " << endl;
    cin >> rollno >> name >> div;
}

void Student::printData()
{
    cout << "Roll No : " << rollno << endl;
    cout << "Name : " << name << endl;
    cout << "Div : " << div << endl;
}

//File class Functions
File::File(string s, string i)
{
    name = s;
    indexFile = i;
    fileObj.open(&indexFile[0], ios::app);
    if (fileObj)
    {
        if(fileObj.tellp() == 0){
            for (int i = 0; i < 10; i++)
            {
                fileObj.write((char *)&index, sizeof(index));
            }
        }
        fileObj.close();
    }
    else
    {
        cout << "Error : Could not open index file !" << endl;
    }
}

int File::hash(int r){
    return r % 10;
}

void File::insert(Student s){
    fstream index(&indexFile[0], ios::in | ios::out);
    Index temp;
    if(index){
        fileObj.open(&name[0], ios::in | ios::out);
        fileObj.seekp(0, ios::end);
        int eof = fileObj.tellp();
        if(fileObj){
            int i = hash(s.rollno);
            index.seekp(i * sizeof(temp), ios::beg);
            index.read((char *)&temp, sizeof(temp));
            if(temp.flag == 0){
                temp.ptr = fileObj.tellp();
                temp.flag = 1;
                index.seekp(-sizeof(temp), ios::cur);
                index.write((char *)&temp, sizeof(temp));
                fileObj.write((char *)&s, sizeof(s));
            }
            else{
                fileObj.seekp(temp.ptr, ios::beg);
                Student s2;
                fileObj.read((char *)&s2, sizeof(s2));
                while(s2.link != -1){
                    fileObj.seekg(s2.link, ios::beg);
                    fileObj.read((char *)&s2, sizeof(s2));
                }
                s2.link = eof;
                fileObj.seekp(-sizeof(s2), ios::cur);
                fileObj.write((char *)&s2, sizeof(s2));
                fileObj.seekp(eof, ios::beg);
                fileObj.write((char *)&s, sizeof(s));
            }
            fileObj.close();
        }else{
            cout<<"Error : Could not open record file !"<<endl;
        }
        index.close();
    }else{
        cout<<"Error : Could not open index file !"<<endl;
    }
}

void File::read(int r){
    Student s;
    Index temp;
    fstream index(&indexFile[0], ios::in | ios::out);
    if(index){
        fileObj.open(&name[0], ios::in);
        if(fileObj){
            int i = hash(r);
            index.seekp(i * sizeof(temp), ios::beg);
            index.read((char *)&temp, sizeof(temp));
            if(temp.flag == 1){
                fileObj.seekg(temp.ptr, ios::beg);
                fileObj.read((char *)&s, sizeof(s));
                if(s.rollno == r && !s.isdeleted){
                    s.printData();
                }else{
                    while(s.link != -1){
                        fileObj.seekg(s.link, ios::beg);
                        fileObj.read((char *)&s, sizeof(s));
                        if(s.rollno == r)
                            break;
                    }
                    if(s.rollno == r && !s.isdeleted){
                        s.printData();
                    }else{
                        cout<<"Record not found !"<<endl;
                    }
                }
            }
            else{
                cout<<"Record not found !"<<endl;
            }
            fileObj.close();
        }else{
            cout<<"Error : Could not open record file !"<<endl;
        }
        index.close();
    }else{
        cout<<"Error : Could not open index file !"<<endl;
    }
}

void File::update(Student s){
    Student s1;
    Index temp;
    fstream index(&indexFile[0], ios::in | ios::out);
    if(index){
        fileObj.open(&name[0], ios::in | ios::out);
        if(fileObj){
            int i = hash(s.rollno);
            index.seekp(i * sizeof(temp), ios::beg);
            index.read((char *)&temp, sizeof(temp));
            if(temp.flag == 1){
                fileObj.seekp(temp.ptr, ios::beg);
                fileObj.read((char *)&s1, sizeof(s1));
                if(s1.rollno == s.rollno && !s1.isdeleted){
                    s.link = s1.link;
                    fileObj.seekp(-sizeof(s), ios::cur);
                    fileObj.write((char *)&s, sizeof(s));
                }else{
                    while(s1.link != -1){
                        fileObj.seekp(s1.link, ios::beg);
                        fileObj.read((char *)&s1, sizeof(s1));
                        if(s1.rollno == s.rollno && !s1.isdeleted)
                            break;
                    }
                    if(s1.rollno == s.rollno){
                        s.link = s1.link;
                        fileObj.seekp(-sizeof(s), ios::cur);
                        fileObj.write((char *)&s, sizeof(s));
                    }else{
                        cout<<"Record not found !"<<endl;
                    }
                }
            }
            else{
                cout<<"Record not found !"<<endl;
            }
            fileObj.close();
        }else{
            cout<<"Error : Could not open record file !"<<endl;
        }
        index.close();
    }else{
        cout<<"Error : Could not open index file !"<<endl;
    }
}

void File::remove(int r){
    Student s;
    Index in;
    fstream index(&indexFile[0], ios::in | ios::out);
    if(index){
        fileObj.open(&name[0], ios::in | ios::out);
        if(fileObj){
            int i = hash(r);
            index.seekp(i * sizeof(in), ios::beg);
            index.read((char *)&in, sizeof(in));
            if(in.flag == 1){
                fileObj.seekp(in.ptr, ios::beg);
                fileObj.read((char *)&s, sizeof(s));
                if(s.rollno == r){
                    s.isdeleted = true;
                    in.ptr = s.link;
                    if(s.link == -1){
                        in.flag = 0;
                    }
                    index.seekp(-sizeof(in), ios::cur);
                    index.write((char *)&in, sizeof(in));
                    fileObj.seekp(-sizeof(s), ios::beg);
                    fileObj.write((char *)&s, sizeof(s));
                }else{
                    Student s2;
                    while(s.link != -1){
                        s2 = s;
                        fileObj.seekp(s.link, ios::beg);
                        fileObj.read((char *)&s, sizeof(s));
                        if(s.rollno == r){
                            break;
                        }
                    }
                    if(s.rollno == r){
                        s2.link = s.link;
                        fileObj.seekp(-2 * sizeof(s2), ios::cur);
                        fileObj.write((char *)&s2, sizeof(s2));
                        s.isdeleted = true;
                        fileObj.write((char *)&s, sizeof(s));
                    }else{
                        cout<<"Record not found !"<<endl;
                    }
                }
            }else{
                cout<<"Record not found !"<<endl;
            }
            fileObj.close();
        }else{
            cout<<"Error : Could not open record file !"<<endl;
        }
        index.close();
    }else{
        cout<<"Error : Could not open index file !"<<endl;
    }
}