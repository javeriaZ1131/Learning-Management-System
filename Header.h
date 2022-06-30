#pragma once
#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
class Person
{
public:

	string name;
	Person()
	{

	}
	Person(string n);
	virtual void Addcourse() {};
	virtual void updatecoursedetails() {};

	virtual void removecourse() {};
	virtual void displayRead() {};
	virtual void addsectioninfo() {};
	virtual void Sectioninfoprint() {};
	virtual void veiwtranscript(string rn) {};
	virtual void selection(int r) {};
	
};

//-------------- Student Class-----------------------
class Student :public Person
{
public:
	string rn;
	char grade;
	double cgpa;
	Student():Person()
	{
		rn = '\0';
		grade = '\0';
		cgpa = 0.0;
	}
	Student(string n, string rn) :Person(n)
	{
		cout << "Student";
		this->name = n;
		this->rn = rn;
	}

	
	void veiwtranscript(string rn);

};
class Registration: public Student
{
public:
	
	Registration():Student()
	{
		
		
	}
	
	void StudentRegistration();
	void Studentregprint();
	void Studentdetails(string filename);
};

// tecaher Class
class Teacher :public Person
{
public:

	string s;
	string m, q, a,a2, f;
	Teacher() :Person()
	{
		name = '\0';
		s = '\0';
		m, q, a,a2, f = '\0';
	}
	Teacher(string n) :Person(n)
	{
		cout << "Teacher";
		this->name = n;
		
	}
	string teacherdetails();
	void selection(int r);

	void setEvaluationcriteria(string section);
	void Marksentry(string s);
	void Studentperformanvce(string s);
};

// Academic officer---------------------------------
class AcademicOfficer :public Person
{

public:
	
	AcademicOfficer() :Person()
	{
		
	}
	AcademicOfficer(string n,string i,string k) : Person(n)
	{
		cout << "AcademicOfficer";
		this->name = n;
		
	}
	void Addcourse();
	void removecourse();
	void updatecoursedetails();
	void displayRead();
	 void addsectioninfo();
	 void Sectioninfoprint();
};

class Course
{

public:

	string id;
	string Cname;
	char iD[19];
	char cname[50];
	Course()
	{
		id = '\0';
		Cname = '\0';
		iD[20] = { '\0' };

		cname[51] = {'\0'};
	}
	Course(string s, string id)
	{

		this->id = id;
		Cname = s;
		
	}
	void setvalues()
	{
		cout << "enter id:";
		
	
		cin.ignore();
		getline(cin, id);
		strcpy_s(iD, id.c_str());
		cout << "Enter cname:";
	
		cin.ignore();
		getline(cin, Cname);

		strcpy_s(cname, Cname.c_str());
	}
	
	void showData()
	{
		cout << "\nid : " << id << endl;;
		cout << "\nStudent Name : " << cname << endl;;
	}
	
	void display()
	{
		ifstream inFile;
		inFile.open("LMSDATA.dat", ios::binary| ios::in);

		Course obj;

		while (inFile.read((char*)&obj, sizeof(obj)))
		{
			obj.showData();
		}

		inFile.close();
	}

};

class Section
{
public:
	
	Registration* r;
	string Sname;
	Course* c1;
	Section()
	{
		Sname = '\0';
//	 c1=new Course();
	}
	Section(string s, string n, string id)
	{
		Sname = s;
		
	}
	void Adddetails()
	{
		cout << "ENter section name:";
		cin.ignore();
		getline(cin,Sname);
		
	}

};