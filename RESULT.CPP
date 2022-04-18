#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
class reportcard
{
long int adno,rollno,attend;
float eng,maths,phy,che,opt,pprac;
float cprac,oprac,phytotal,chetotal,ototal,perc;
char sname[20], fname[20], clas[10], schooln[40];
char egrade,mgrade,pgrade,cgrade,ograde;
public:
	void enter();
	void display();
	void modify();
	void searchadno();
	void searchn();
	void del();
	void writedata();
	int retadno()
	{
	return adno;
	}
	char* retname()
	{
	return sname;
	}
	void disp();
};
reportcard rc;

void reportcard::enter()
{ clrscr();
cout<<"Enter the name of student: ";
gets(sname);
cout<<endl;
cout<<"Enter the class of student: ";
gets(clas);
cout<<endl;
cout<<"Enter student's Father name: ";
gets(fname);
cout<<endl;
cout<<"Enter Admission Number of student: ";
cin>>adno;
cout<<endl;
cout<<"Enter Roll Number of Student: ";
cin>>rollno;
cout<<endl;
cout<<"Enter student's marks in Physics (70 Marks): ";
cin>>phy;
cout<<endl;
cout<<"Enter student's marks in Physics Practical (30 Marks): ";
cin>>pprac; cout<<endl;
cout<<"Enter student's marks in Chemistry (70): ";
cin>>che; cout<<endl;
cout<<"Enter student's marks in Chemistry Practical (30 Marks): ";
cin>>cprac; cout<<endl;
cout<<"Enter student's marks in Maths (100 Marks): ";
cin>>maths; cout<<endl;
cout<<"Enter student's marks in English (100 Marks): ";
cin>>eng; cout<<endl;
cout<<"Enter student's marks in Optional Subject (70 Marks): ";
cin>>opt; cout<<endl;
cout<<"Enter student's marks in Optional Practical (30 Marks): ";
cin>>oprac; cout<<endl;
cout<<"Enter the School name: ";
gets(schooln); cout<<endl;
cout<<"Enter student's attendance out of 300: ";
cin>>attend; cout<<endl;
}

void reportcard::display()
{ clrscr();
cout<<setw(41)<<schooln<<endl;
cout<<setw(47)<<"Session 2021-22"<<endl;
cout<<"Name: ";
puts(sname);
cout<<"Father's Name: ";
puts(fname);
cout<<"\nAdmission Number: "<<adno;
cout<<setw(50)<<"Class: ";
cout<<clas<<endl;
cout<<"Roll Number: "<<rollno<<endl;
cout<<"============================================================================="<<endl;
cout<<"Subject"<<setw(25)<<"Marks (100/70)"<<setw(20)<<"Practicals (30)"<<setw(8)<<"Total"<<setw(14)<<setw(10)<<"Grade"<<endl;
if(eng>90)
egrade='A';
else if(eng<=90 && eng>75)
egrade='B';
else if(eng<=75 && eng>60)
egrade='C';
else
egrade='D';

cout<<"English"<<setw(18)<<eng<<setw(18)<<"-"<<setw(15)<<eng<<"        "<<egrade<<endl;

if(maths>90)
mgrade='A';
else if(maths<=90 && maths>75)
mgrade='B';
else if(maths<=75 && maths>60)
mgrade='C';
else
mgrade='D';

cout<<"Maths"<<setw(20)<<maths<<setw(18)<<"-"<<setw(15)<<maths<<"        "<<mgrade<<endl;

phytotal=(phy+pprac);

if(phytotal>90)
pgrade='A';
else if(phytotal<=90 && phytotal>75)
pgrade='B';
else if(phytotal<=75 && phytotal>60)
pgrade='C';
else
pgrade='D';

cout<<"Physics"<<setw(18)<<phy<<setw(18)<<pprac<<setw(15)<<phytotal<<"        "<<pgrade<<endl;

chetotal=che+cprac;
if(chetotal>90)
cgrade='A';
else if(chetotal<=90 && chetotal>75)
cgrade='B';
else if(chetotal<=75 && chetotal>60)
cgrade='C';
else
cgrade='D';

cout<<"Chemistry"<<setw(16)<<che<<setw(18)<<cprac<<setw(15)<<chetotal<<"        "<<cgrade<<endl;

ototal=opt+oprac;
if(ototal>90)
ograde='A';
else if(ototal<=90 || ototal>75)
ograde='B';
else if(ototal<=75 || ototal<60)
ograde='C';
else
ograde='D';

cout<<"Optional"<<setw(17)<<opt<<setw(18)<<oprac<<setw(15)<<ototal<<"        "<<ograde<<endl;
cout<<"============================================================================="<<endl;
cout<<"Attendance: "<<attend<<"/300"<<endl;
cout<<"Teacher's Sign_______"<<setw(56)<<"Principal Sign_________"<<endl;
cout<<"Parent's Sign________"<<endl;
}

void writedata()
{
ofstream fout;
fout.open("reportcard.dat",ios::binary);
rc.enter();
fout.write((char*)&rc,sizeof(rc));
fout.close();
cout<<"Student Record Created!!"<<endl;
}

void disp()
{
ifstream fin;
fin.open("reportcard.dat",ios::binary);
if(!fin)
{ cout<<"File is not Open!!!!"<<endl;
getch();
exit(0);
}
cout<<"Display all Records"<<endl;
while(fin.read((char*)&rc,sizeof(rc)))
{
rc.display();
getch();
}
fin.close();
}

void del()
{
clrscr();

ifstream fin("reportcard.dat",ios::binary);
ofstream fout("xyz.dat",ios::binary);
if(!fin)
{
cout<<"File is not Open!!!!"<<endl;
exit(0);
}
int n;
int f=0;
cout<<"Enter the Admission number of Student to delete his/her Record."<<endl;
cin>>n;
while(fin.read((char*)&rc,sizeof(rc)))
{
if(rc.retadno()==n)
{
fout.write((char*)&rc,sizeof(rc));
f++;
getch();
cout<<"Record Deleated Successfully!!!!"<<endl;
getch();
remove("reportcard.dat");
rename("xyz.dat","reportcard.dat");
}
}
if(f==0)
cout<<"Record not Found!!"<<endl;
fin.close();
fout.close();

}

void searchn()
{ clrscr();
ifstream fin("reportcard.dat",ios::binary);
if(!fin) {
cout<<"File not Open"<<endl;
exit(0);
}
char ename[20];
int f=0;
cout<<"Enter the name of student you want to search: ";
gets(ename);
while(fin.read((char*)&rc,sizeof(rc)))
{
if(strcmpi(rc.retname(),ename)==0)
{
rc.display();
f=1;
getch();
}
}
if(f==0)
{
cout<<"Record not found!!!!"<<endl;
}
fin.close();
}

void searchadno()
{
clrscr();
ifstream fin("reportcard.dat",ios::binary);
if(!fin)
{
cout<<"File not Open!!!!"<<endl;
exit(0);
}
int k;
int f=0;
cout<<"Enter Student's Admission Number you want to search"<<endl;
cin>>k;
while(fin.read((char*)&rc,sizeof(rc)))
{
 if(rc.retadno()==k)
  {
  rc.display();
  f=1;
  getch();
  }
}
if(f==0)
cout<<"Record not found!!!!"<<endl;
fin.close();
}

void modify()
{
clrscr();
fstream fin("reportcard.dat",ios::in|ios::out|ios::binary);
if(!fin)
{
cout<<"File is not Open!!"<<endl;
getch();
exit(0);
}
int n;
cout<<"Enter student's Admission Number whose record you want to modify: ";
cin>>n;
while(fin.read((char*)&rc,sizeof(rc)))
{
if(rc.retadno()==n)
{
cout<<"Record Found!!!!"<<endl;
rc.enter();
fin.seekg(fin.tellg()-sizeof(rc));
fin.write((char*)&rc,sizeof(rc));
cout<<endl<<"Record Updated Successfully!!!!"<<endl;
}
else
cout<<"Record Not Found!!!!"<<endl;
}
fin.close();
}

void main()
{
clrscr();
int n;
char ch;
do
{
clrscr();
cout<<"1. Write record in File."<<endl;
cout<<"2. Display all Records."<<endl;
cout<<"3. Delete any Record."<<endl;
cout<<"4. Search any record by student's name."<<endl;
cout<<"5. Search record by student's Admission Number."<<endl;
cout<<"6. Modify record."<<endl;
cout<<"0. Exit"<<endl;
cout<<"Enter your Choice...."<<endl;
cin>>n;
switch(n)
{
case 1:
	writedata();
	break;
case 2:
	disp();
	break;
case 3:
       del();
	break;
case 4:
       searchn();
	break;
case 5:
       searchadno();
	break;
case 6:
       modify();
	break;
case 0:
	exit(0);
default:
	cout<<"You entered wrong choice...."<<endl;
}
cout<<"Do you want to continue......"<<endl;
cin>>ch;
clrscr();
}while(ch=='y' || ch=='Y');
getch();
}