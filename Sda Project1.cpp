// SDA Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#pragma once
#include <cstring>
#include<string.h>
#include"Header.h"
#include <string>

using namespace std;

Person::Person(string n)
{
	cout << "Person";
	name = n;
}
//------------------------------------------------------------Academic Office --------------------------------------
//1==========================
void AcademicOfficer::Addcourse()// function to add course
{
	ofstream file;
	
	file.open("LMSDATA.txt", ios::out | ios::app);
	if (!file.is_open())
	{
		cout << "Unable to open file.." << endl;
	}

	Course  c;
	c.setvalues();
	file << c.id<<"\t";
	file << c.Cname << endl;;


	cout << "Done with write" << endl;





	file.close();


}

// 2========= 
void AcademicOfficer::removecourse()// function to remove or delete the Course from the file
{
	char find[20];
	Course obj;
	cout << "enter the id which you want to delete:" << endl;
	cin.ignore();
	cin.getline(find, 20);

	ifstream inFile;
	inFile.open("LMSDATA.txt", ios::in | ios::binary);
	bool flag = 1;
	ofstream outFile;
	string arr[50][50];
	int i = 0;
	outFile.open("temp.txt", ios::out | ios::binary );
	if (!inFile || !outFile)
	{
		cout << "error in opening file" << endl;
	}
	while (!inFile.eof())
	{
		inFile >> obj.id;
		getline(inFile, obj.Cname);
		arr[i][0] = obj.id.c_str();
		if (strcmp(arr[i][0].c_str(),find)!=0)
		{
			if (outFile.is_open()) {
				outFile << obj.id << "\t";
				outFile << obj.Cname << endl;
				flag = 0;
			}
		}
		else
		{
			
		}
		i++;

	}

	inFile.close();
	outFile.close();

		remove("LMSDATA.txt");

	// rename new file to the older file
	rename ("temp.txt",  "LMSDATA.txt");

	if (flag == 0)
	{
		cout << "record deleted" << endl;
	}
	else
	{
		cout << "record not deleted " << endl;
	}


}
//3==================================
/// <summary>
/// function to update the course detail in the file whiere the details are stored
/// </summary>
void AcademicOfficer::updatecoursedetails()
 {

	fstream inFile;
	ofstream outfile;
	inFile.open("LMSDATA.txt", ios::in);
	outfile.open("temp.txt", ios::out|ios::app);

	if (!inFile)
	{
		cout << "unable to oepn file" << endl;
	}
	inFile.seekg(0);
	char found[20];
	cout << "Enter Course id whoses detail u want to update:";
	cin.ignore();
	cin.getline(found, 20);
	
	Course c;
	bool got = 0;
	string arr[50][50];
	int i = 0;
	while (!inFile.eof())
	{
		inFile >> c.id;
		getline(inFile, c.Cname);
	
		arr[i][0] = c.id;
		if (strcmp(arr[i][0].c_str(),found)!=0)
		{
			outfile << c.id << "\t";
			outfile << c.Cname << endl;
			

		}
		else
		{
			got = 0;

			cout << "enter new values to update:" << endl;
			cin.ignore();
			c.setvalues();

		
			outfile << c.id << "\t";
			outfile << c.Cname << endl;
		
		}
	
	}
	inFile.close();
	outfile.close();
	ifstream temp;
	inFile.open("LMSDATA.txt", ios::out);
	temp.open("temp.txt", ios::in);
	while (!temp.eof()||!inFile.eof())
	{
		getline(temp, c.id);
		getline(temp, c.Cname);
		inFile << c.id << "\t";
		inFile << c.Cname;
		inFile << endl;
	}
	remove("temp.txt");

	// rename new file to the older file

	if (got == 0)
	{
		cout << "found.. Enter updated id" << endl;
		
	

	}
	else
	{
		cout << "entry not found" << endl;
	}
 }
//4-------------------------------------------------
void AcademicOfficer::addsectioninfo()// Add Section informtaion the section of a Course along with the course id
{
	ofstream file;

	file.open("Section Details.txt", ios::out | ios::app);
	if (!file.is_open())
	{
		cout << "Unable to open file.." << endl;
	}

	Section*s=new Section();
	Course c;
	
	s->Adddetails();

	c.setvalues();
	file << s->Sname<<'\t';
	file << c.id << '\t';
	file << c.Cname << "\t";
	
	cout << "Done with write" << endl;

	file.close();
}
void AcademicOfficer::Sectioninfoprint()// Print function to print the Section info stored on the screen
{



	ifstream inFile;
	inFile.open("Section Details.txt", ios::in);
	
	Section *obj=new Section();
	Course c;
	cout << "------------------The SECTION DETAILS ARE----------------" << endl;
	cout << "Section" << "\t" << "C-id" << "\t" << "Course name" << endl;
	while (!inFile.eof())
	{
		inFile >> obj->Sname;
		inFile >> c.id;
		getline(inFile, c.Cname);
		
		cout << obj->Sname << "  " << c.id <<c.Cname<< endl;
	}

	inFile.close();

}
void AcademicOfficer::displayRead()// Function to display the Deatils of Courses only...
{
	


	ifstream inFile;
	inFile.open("LMSDATA.txt", ios::in);
	inFile.seekg(0);
	Course obj;
	string line;
	cout << "------------------The COURSES DETAILS ARE----------------" << endl;

	while (!inFile.eof())
	{
		
		inFile >> obj.id;
		getline(inFile, obj.Cname);
		
		



		cout << obj.id << "  " << obj.Cname << endl;
	}

	inFile.close();

}
//---------------------------------End of Academic Officier------------------------------------------------------------



//------------------------------------------------------Student-------------------------------------------------

// Function 1 for Student registration of Courses;

void Registration:: StudentRegistration()
{
	ofstream sfile,sfile1;
	Student st;

	cout << "enter rollNum:";
	cin.ignore();
	getline(cin, st.rn);

	string filename = st.rn + ".txt";
	sfile.open("StudentRegDetails.txt", ios::out| ios::app);
	sfile1.open(filename, ios::out | ios::app);
	if (!sfile|| !sfile1)
	{
		cout << "unable to open file" << endl;
	}
	cout << "enter Student name:";
	cin.ignore();
	getline(cin, st.name);
	
	int num;
	cout << "enter the number of courses u want to register:";
	cin >> num;
	if (num <= 5)
	{
		for (int i = 1; i <= num; i++)
		{

			Section* s = new Section();
			Course* c = new Course();


			c->setvalues();
			cout << "Section selection:";
			cin.ignore();
			getline(cin, s->Sname);
			if (sfile.is_open() || sfile1.is_open())
			{
				sfile << st.rn << "\t";
				sfile << st.name << "\t";
				sfile << s->Sname << "\t";
				sfile << c->id << "\t";
				sfile << c->Cname << endl;



				// writing into file1
				sfile1 << st.rn << "\t";
				sfile1 << st.name << "\t";
				sfile1 << s->Sname << "\t";
				sfile1 << c->id << "\t";
				sfile1 << c->Cname << endl;


			}
			cout << "done with Registration.. you details are" << endl;
			cout << st.rn << " " << st.name << " " << s->Sname << " " << c->id << " " << c->Cname << endl;
		}
	}
	else
	{
		cout << " You  can not register in more than 5 course ....!!!  PLEASE reenter again" << endl;
		cin >> num;

	}
	sfile.close();
}
// Function no 2=====  View The trancript ---------------------------------------------
void Student::veiwtranscript(string rn)
{
	ifstream sfile;
	Student st;
	ofstream sfile1;
	Section s;
	Course c;

	
	sfile.open(rn+".txt", ios::in);
	sfile1.open(rn+"Transcript"+".txt",  ios::out);
	if (!sfile.is_open())
	{
		cout << "unable to open file" << endl;

	}
	string h;
	cout << "-----------THE Transcrpit OF" << rn << "  Student are:" << endl;
	cout << "RollNo" << "\t" << "Name"  <<endl;
	while (!sfile.eof())
	{
		sfile >> st.rn;
		getline(sfile, st.name);
		getline(sfile, h);
		getline(sfile, h);
		getline(sfile, h);
	}
	sfile.close();
	cout << "Roll No:" << " " << st.rn << "\t" << "Student Name" << " " << st.name << endl;
	sfile1 << "Roll No:" << " " << st.rn << "\t" << "Student Name" << " " << st.name << endl;

	sfile.open(rn+".txt", ios::in);
cout	<< "section" << "\t" << "Cid" << "\t" << "course" << "\t"<<"Grade"<<"\t"<<"GPA" << endl;
cout << endl;

sfile1 << "section" << "\t" << "Cid" << "\t" << "course" << "\t" << "Grade" << "\t" << "GPA" << endl;
sfile1 << endl;
	while (!sfile.eof())
	{

		sfile >>h;
		getline(sfile,h);
		sfile >> s.Sname;
		sfile >> c.id;
		getline(sfile, c.Cname);
		sfile >> st.grade;
		st.grade = 'I';
		sfile >> st.cgpa;
		st.cgpa = 0;
		cout << s.Sname << "\t" << c.id << "\t" << c.Cname << "\t" << 'I' <<'0' << endl;;
		sfile1 << s.Sname << "\t" << c.id << "\t" << c.Cname << "\t" << st.grade << st.cgpa << endl;;
		cout << endl;
	}

	sfile.close();
}

void Registration::Studentdetails(string filename)// a simple print function to display the Student details
{
	ifstream sfile;
	Student st;

	Section s;
	Course c;


	sfile.open(filename+".txt", ios::binary | ios::in);

	if (!sfile.is_open())
	{
		cout << "unable to open file" << endl;

	}

	cout << "-----------THE Courses details OF" << filename << "  Student are:" << endl;
	cout << "RollNo" << "\t" << "Name" << "\t" << "section" << "\t" << "Cid" << "\t" << "course" << endl;
	while (!sfile.eof())
	{

		sfile >> st.rn;
		getline(sfile, st.name);
		sfile >> s.Sname;
		sfile >> c.id;

		getline(sfile, c.Cname);

		cout << st.rn << "\t" << st.name << "\t" << s.Sname << "\t" << c.id << "\t" << c.Cname;
		cout << endl;
	}

	sfile.close();
}
void Registration::Studentregprint()// function to print the Registration of differnet studnets and there details
{
	ifstream sfile;
	Student st;

	Section s;
	Course c;

	
		sfile.open("StudentRegDetails.txt", ios::binary | ios::in);

		if (!sfile.is_open())
		{
			cout << "unable to open file" << endl;

		}
	
		cout << "Reading...." << endl;
		cout << "RollNo" << "\t" << "Name" << "\t" << "section" << "\t"<<"Cid" <<"\t"<< "course" << endl;
		while(!sfile.eof())
		{
			
			sfile >> st.rn;
			getline(sfile,st.name);
			sfile >> s.Sname ;
			sfile >> c.id;
		
			getline(sfile, c.Cname);
		

			cout << st.rn << " " << st.name << " " << s.Sname << " " << c.id << " "<<c.Cname;
			cout << endl;
		}
	
	sfile.close();
}

//-------------------------------------------End of Student-----------------------------------------------



//--------------------------------------------------------Teacher ---------------------------------------------

string Teacher::teacherdetails()// adding Tecaher name and section
{
	
		cout << "kindly enter your name:" << endl;
		cin.ignore();
		getline(cin, name);

		Sectioninfoprint();
		cout << "kindly select your section:";
		cin.ignore();
		getline(cin, s);

		return s;
	
}
void Teacher::setEvaluationcriteria(string section)//set evaluation Criteria
{
	ofstream file;
	file.open(name+"EC"+".txt", ios::out| ios::app);
	if (!file.is_open())
	{
		cout << "Unable to open file" << endl;
	}
	int h;
	
	cout << "Evavlution Criterias for Section" << section << endl;
	cout << "enter weitage for quizes:";
	getline(cin, q);
		cout << "enter weitage for mid(1+2):";
		getline(cin, m);

	cout << "enter weitage for assignmnets:";
	getline(cin, a);
	cout << "enter weitage for finals:";
	getline(cin, f);
	file <<"Tacehr name"<<" "<<"section"<<"\t"<< "Quiz" << " " << "Mids" << " " << "Assignments" << " " << "finals" << endl;
	
		file << name;
		file << section;
		file << q<<"\t";
		file << m<<"\t";
		file << a<<"\t";
		file << f<<"\t";

	
	cout << "Done with write" << endl;
}
void Teacher::Marksentry(string s)// function for entry of marks of a section in a file
{
	ofstream file;
	Student st;
	int num;
	file.open(s+"MarkSheet" + ".txt", ios::out, ios::app);
	if (!file.is_open())
	{
		cout << "unable to open file" << endl;
	}
	cout << "Enter total strength of class" << num;

	cout << "Total Student :" << num << '\t'<<"Section :"<<s << endl;;
	cout << "SNo"<<"\t" << "RollNo" << "\t" << "Quiz" << "\t" << "Mids" << "\t" << "\t" << "Assignment 1" << '\t'<<"Assignment 2" << "finals" << endl;
	for (int i = 1; i <= num; i++)
	{
		file << i;
		cout << "Rollno:";
		cin.ignore();
		getline(cin, st.rn);
		file << st.rn;

		cout << "Quiz:";
		cin.ignore();
		getline(cin,q );
		file << q;
		cout << "Mids 1 and 2:";
		cin.ignore();
		getline(cin, m);

		file << m;
		
		cout << "assignment 1:";
		cin.ignore();
		getline(cin, a);
		file << a;
		cout << "assignment 2:";
		cin.ignore();
		getline(cin, a2);
		file << a2;

		cout << "finals marks:";
		cin.ignore();
		getline(cin, f);
		file << f;
	}

	cout << "Done with entry all details" << endl;
}

void Teacher::Studentperformanvce(string s)// to view the Student poerform or the marks
{
	ifstream file;
	Student st;
	int num;
	file.open(s + "MarkSheet" + ".txt", ios::in);
	if (!file.is_open())
	{
		cout << "unable to open file" << endl;
	}
	cout << "Enter total strength of class" << num;

	cout << "Total Student :" << num << '\t' << "Section :" << s << endl;;
	cout << "SNo" << "\t" << "RollNo" << "\t" << "Quiz" << "\t" << "Mids" << "\t" << "\t" << "Assignment 1" << '\t' << "Assignment 2" << "finals" << endl;
	for (int i = 1; i <= num; i++)
	{
		file >> i;
		
		file >> st.rn;

		
		file>> q;
	

		file >> m;

	
		file >> a;
		
		file >> a2;

	
		file >> f;
	}
	cout  << "\t" << st.rn << " " << q << " " << m << " " << a << " " << a2 << " " << f << endl;
	cout << "Done with entry all details" << endl;
}
void Teacher::selection(int k)// selection of the specific criteria accoding to the user selection k
{
	if (k == 1)//set evavluation criteria 
	{
		
			string d = teacherdetails();
			setEvaluationcriteria(d);		
	}
	else if (k == 2)//enter marks
	{
	
		string d = teacherdetails();
	
		Marksentry(d);
	
	}
	else if (k == 3)// view Student performance
	{
		Section s;
		cout << "Enter the sections whose details you want to see";
		getline(cin, s.Sname);
		Studentperformanvce(s.Sname);
	}
	else
	{
		cout << "invalid...enter again" << endl;
		cin >> k;
	}
}
int main()
{
	int select;
	Person *p;

	string name;

	cout << "1- Teacher" << endl;
	cout << "2- Student" << endl;
	cout << "3-Academic Officer" << endl;

	cout << "log in as(select)" << endl;
	cin >> select;
while (true)
	{
		if (select == 1)// Teacher
		{
			int r;
			Teacher t;
			p = &t;
			cout << "1- Set Evaluation criteria" << endl;
			cout << "2- Marks Enetrence" << endl;
			cout << "2- View Student performance" << endl;
			cin >> r;
			p->selection(r);//  function that will perform the selection and call the  function according to requirmnet
			
		}
		else if (select == 2)//Student
		{
			int k;
			Student s;

			p = &s;
			cout << "1- Registration" << endl;
			cout << "2- view your transcript" << endl;
			cin >> k;
			if (k == 1)
			{
				Registration r;
				AcademicOfficer a1;
				a1.displayRead();
				a1.Sectioninfoprint();
				r.StudentRegistration();
				cout << "The Students registrations details are:" << endl;
				r.Studentregprint();
				/*cout << "The Courses registed of the student its self are:" << endl// here eneter the rollnumber as paramter
				r.Studentdetails();*/

			}
			else
			{
				
				cout << "enetr your roll no:";
				cin.ignore();
				getline(cin, s.rn);
				p->veiwtranscript(s.rn);


			}


		}
		else if (select == 3)//Academic Officer
		{
			int s;

			AcademicOfficer a;
			p = &a;
			cout << "Adminstrator Office:" << endl;
			cout << "1- Add Course" << endl;
			cout << "2- Remove Course" << endl;
			cout << "3- Update Course" << endl;
			cout << "4- Add Info of new Section" << endl;
			cin >> s;
			if (s == 1)
			{

				p->Addcourse();//write to bin file
				p->displayRead();//read from bin file
			}
			else if (s == 2)//delete by id
			{


				p->displayRead();
				p->removecourse();

				p->displayRead();
			}
			else if (s == 3)//update on id
			{
				p->displayRead();
				p->updatecoursedetails();
				p->displayRead();
			}
			else if (s == 4)// add section info
			{

				p->addsectioninfo();
				p->Sectioninfoprint();
			}

		}
		char l;
		cout << "Do you want to continue or exit ?  press C or E" << endl;

		cin >> l;

		if (l == 'C' || l == 'c')
		{
			continue;
		}
		else if (l == 'E' || l == 'e')
		{
			cout << "See you later... Bye" << endl;
			break;

		}
	}
}