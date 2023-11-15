 #include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>

using namespace std;
class Student
{
 int admno;
 char name[200];
 char gender;
 int std;
 float marks;
 float percentage;
 
 public:
  void getData();
  void showData();
  int getAdmno()
  {
  return admno;
  }
}s;

class Teacher
{
 int regno;
 char name[200];
 char gender;
 char phone[100];
 float salary;
 int standard;

 public:
  void getdata();
  void showdata();
  int getregno()
  {
  return regno;
  }
}t;

class Guest
{
char name[200];
char sname[200];
char gender;
int grade;
char phone[100];
char address[1000];
	public:
		void getdatA();
		void showdatA();
}g;

void principal()
{
	int k=0,ch,z,j,u,f,y,m,choice=1;
	system("cls");
	cout<<"\t\t\t\tADMINISTRATIVE LOGIN\n\n";
	cout<<"USERNAME:SEEDLING\n";
	cout<<"PASSWORD:";
	char c=' ';
	char q[20];
	string pass="";
	while(c!=13)
	{
		c=getch();
		if(c!=13)
		{
			pass+=c;
			cout<<"*";
		}
	}
	ifstream o;
	o.open("pass.txt",ios::in | ios::out | ios::app );
	while(!o.eof())
	{
	o>>q;
    }
	if(pass==q)
	{
		cout<<"\nPASSWORD VALIDATED\n";
		k=1;
	}
	else
	{
		cout<<"\nPASSWORD INVALID\n";
		k=0;
	}
	o.close();
	if(k==1)
{
	while(choice==1)
	{
		system("cls");
	cout<<"\n\t\t\tADMINISTRATIVE LOGIN\n";
	cout<<"1.VIEW STUDENT DATA\n2.VIEW TEACHER DETAILS\n3.VIEW GUEST DETAIL\n";
	cin>>z;
	switch(z)
	{
	case 1:
	cout<<"1. WRITE STUDENT DATA TO FILE\n";
	cout<<"2. READ STUDENT DATA FROM FILE\n";
	cout<<"3. SEARCH STUDENT DETAIL FROM FILE\n";
	cout<<"4. DELETE STUDENT DETAIL FROM FILE\n";
	cout<<"5. RESTORE TRASHED STUDENT DETAIL\n";
	cout<<"6. MODIFY STUDENT DETAIL\n";
	cout<<"ENTER YOUR CHOICE  : ";
	cin>>j;
	system("cls");
	if(j==1)
	{
	//	cout<<"ENTER GRADE OF STUDENT:";
//cin>>y;
//	if(y==1)
//	{
 ofstream fout;
 //ofstream bout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 //fout.open("StudentsGRADE1.dat",ios::binary|ios::out|ios::app); 
 s.getData();
 fout.write((char*)&s,sizeof(s));
// bout.write((char*)&s,sizeof(s));
 fout.close();
// bout.close();
  cout<<"\n\nDATA SUcESSFULLY SAVED TO FILE....\n";
//}
/*if(y==2)
{
 ofstream fout;
 //ofstream bout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 //bout.open("StudentsGRADE2.dat",ios::binary|ios::out|ios::app); 
 s.getData();
 fout.write((char*)&s,sizeof(s));
 //bout.write((char*)&s,sizeof(s));
 fout.close();
 //bout.close();
  cout<<"\n\nDATA SUCCESSFULLY SAVED TO FILE....\n";
}*/
/*else
{
	cout<<"INVALID ENTRY\n";
}*/
}

   if(j==2)
   {
   
    	ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nDATA READ FROM FILE SUCCESSFULLY....\n";
 /*cout<<"DO YOU WANT TO VIEW STUDENT GRADE LIST 1.YES\t2.NO:";
 cin>>m;
 //if(m==1)
 {
 	cout<<"ENTER GRADE TO SEARCH :";
 	cin>>y;
 	if(y==1)
 	{
 		ifstream fin;
 fin.open("StudentsGRADE1.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";
	 }
	 if(y==2)
	 {
	 	ifstream fin;
 fin.open("StudentsGRADE2.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();*/
 //cout<<"\n\nDATA READ SUCCESSFULLY....\n";
	 
	 /*else
	 {
	 	cout<<"INVALID ENTRY";
	 }*/
 }
/* else
 {
 	cout<<"EXITING\n";
 }*/

    if(j==3)
    {
    	int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 cout<<"ENTER ADMISSION NUMBER TO SEARCH : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"THE DETAILS OF ADMISSION NUMBER "<<n<<" ARE DISPLAYED BELOW:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)cout<<"THE ADMISSION NUMBER. "<<n<<" NOT FOUND....\n\n";
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";
}
    if(j==4)
	{
int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Students.dat",ios::in|ios::binary);
 fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
 tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);

 cout<<"ENTER THE ADMISSION NUMBER TO TRASH: ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"ADMISSION NUMBER "<<n<<" ENTERED HAS BEEN TRASHED:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"THE ADMISSION NUMBER "<<n<<" NOT FOUND....\n\n";
 remove("Students.dat");
 rename("tempStud.dat","Students.dat");
}
if(j==5)
{
    	ifstream fin;
 fin.open("TrashStud.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";
}
 if(j==6)
 {
     	int n, flag=0, pos;
 fstream fio;

 fio.open("Students.dat",ios::in|ios::out|ios::binary);
 
 cout<<"ENTER ADDMISSION NUMBER TO MODIFY: ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getAdmno())
  {
   cout<<"THE FOLLOWING ADMISSION NUMBER: "<<n<<" WILL BE MODIFIED:\n";
   s.showData();
   cout<<"\n\nENTER THE DETAILS BELOW....\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"THE ADMISSION NUMBER: "<<n<<" NOT FOUND....\n\n";
    
    }
    break;
		case 2:
	cout<<"1. WRITE STAFF DATA TO FILE\n";
	cout<<"2. READ TEACHER DATA FROM FILE\n";
	cout<<"3. SEARCH STAFF DETAIL FROM FILE\n";
	cout<<"4. DELETE SATFF DETAIL FROM FILE\n";
	cout<<"5. RESTORE TRASHED STAFFED DETAIL\n";
	cout<<"6. MODIFY STAFF DETAIL\n";
	cout<<"ENTER YOUR CHOICE  : ";
	cin>>u;
	system("cls");
	if(u==1)
	{
		/*cout<<"ENTER THE STAFF GRADE   :";
		cin>>f;*/
	//	if(f==1)
	//	{
		ofstream fout;
		//ofstream bout;
        fout.open("TEACHERS.dat",ios::binary|ios::out|ios::app);
        //bout.open("TEACHERSGRADE1.dat",ios::binary|ios::out|ios::app);
        t.getdata();
        fout.write((char*)&t,sizeof(t));
        //bout.write((char*)&t,sizeof(t));
        fout.close();
        //bout.close();
         cout<<"\n\nDATA SAVED TO FILE....\n";
    }
       /* if(f==2)
		{
		ofstream fout;
		ofstream bout;
 fout.open("TEACHERS.dat",ios::binary|ios::out|ios::app);
 bout.open("TEACHERSGRADE2.dat",ios::binary|ios::out|ios::app);
 t.getdata();
 fout.write((char*)&t,sizeof(t));
 bout.write((char*)&t,sizeof(t));
 fout.close();
 bout.close();
  cout<<"\n\nDATA SAVED TO FILE....\n";
}
 else
 {
 	cout<<"INVALID ENTRY\n\n";
 }*/
	//}

	if(u==2)
	{
		ifstream fin;
 fin.open("TEACHERS.dat",ios::in|ios::binary);
 while(fin.read((char*)&t,sizeof(t)))
 {
  t.showdata();
 }
 fin.close();
 cout<<"\n\nDATA READ FROM FILE SUCCESSFULLY....\n";
	}
	
	
	    if(u==3)
    {
    	int n, flag=0;
 ifstream fin;
 fin.open("TEACHERS.dat",ios::in|ios::binary);
 cout<<"ENTER REGISTRATION NUMBER YOU WANT TO SEARCH : ";
 cin>>n;
 
 while(fin.read((char*)&t,sizeof(t)))
 {
  if(n==t.getregno())
  {
   cout<<"THE DETAILS OF ENTERED ADDMISSION NUMBER: "<<n<<" IS DISPLAYED BELOW:\n";
   t.showdata();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"REGISTRATION NUMBER "<<n<<" NOT FOUND....\n\n";
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";
}
    if(u==4)
	{
int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("TEACHERS.dat",ios::in|ios::binary);
 fout.open("TempTEACHERS.dat",ios::out|ios::app|ios::binary);
 tout.open("TrashTEACHERS.dat",ios::out|ios::app|ios::binary);

 cout<<"ENTER REGISTRATION NUMBER TO TRASH : ";
 cin>>n;
 
 while(fin.read((char*)&t,sizeof(t)))
 {
  if(n==t.getregno())
  {
   cout<<"REGISTRATION NUMBER: "<<n<<" HAS BEEN TRASHED:\n";
   t.showdata();
   tout.write((char*)&t,sizeof(t));
   flag++;
  }
  else
  {
   fout.write((char*)&t,sizeof(t));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"THE REGISTRATION NUMBER: "<<n<<" NOT FOUND....\n\n";
 remove("TEACHERS.dat");
 rename("tempTEACHERS.dat","TEACHERS.dat");
}
if(u==5)
{
    	ifstream fin;
 fin.open("TrashTEACHERS.dat",ios::in|ios::binary);
 while(fin.read((char*)&t,sizeof(t)))
 {
  t.showdata();
 }
 fin.close();
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";
}
 if(u==6)
 {
     	int n, flag=0, pos;
 fstream fio;

 fio.open("TEACHERS.dat",ios::in|ios::out|ios::binary);
 
 cout<<"ENTER REGISTRATION NUMBER TO MODIFY : ";
 cin>>n;
 
 while(fio.read((char*)&t,sizeof(t)))
 {
  pos=fio.tellg();
  if(n==t.getregno())
  {
   cout<<"THE REGISTRATION NUMBER "<<n<<" WILL BE MODIFIED WITH NEW DATA:\n";
   t.showdata();
   cout<<"\n\nENTER DETAILS LISTED BELOW\n";
   t.getdata();
   fio.seekg(pos-sizeof(t));
   fio.write((char*)&t,sizeof(t));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"THE REGISTRATION NO. "<<n<<" NOT FOUND....\n\n";
	
	}
		break;
	case 3:

    	ifstream fin;
 fin.open("GUEST.dat",ios::in|ios::binary);
 while(fin.read((char*)&g,sizeof(g)))
 {
  g.showdatA();
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
	break;
	/*default:
		cout<<"INVALID ENTRY\n";*/

	
	system("pause");
}
cout<<"DO YOU WANT TO COTINUE:\n1.YES(ADMIN MENU)\n2.NO\n";
cin>>choice;
};
}
}

void guest()
{
	int l,ask=1;
	char r[1000];
	system("cls");
    int wrote=0;
	string pname,sname,phnumber,address,grade;
	ofstream fout;
 fout.open("GUEST.dat",ios::binary|ios::out|ios::app);
 g.getdatA();
 fout.write((char*)&g,sizeof(g));
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
	wrote=1;
	if(wrote==1)
	{
		while(ask==1)
		{
		
	system("cls");
	cout<<"WELCOME WHAT WOULD YOU LIKE TO VIEW\n";
	cout<<"1.HOME\n";
	cout<<"2.ABOUT US\n";
	cout<<"3.ACADEMICS\n";
	cout<<"4.ADMISSIONS\n";
	cout<<"5.CAMPUS LIFE\n";
	cout<<"6.BULLETIN BOARD\n";
	cout<<"7.CONTACT US\n";
	cout<<"8.EXIT\n";
	wrote=0;
	cout<<"WHAT DO YOU WANT TO VIEW :";
	cin>>l;
 
		if(l==1)
		{
		
		ifstream u;
		u.open("HOME.txt");
		while(!u.eof())
		{
			u.getline(r,1000);
			cout<<r<<"\n";
		}
		u.close();
		}
		if(l==2)
			{
			ifstream u;
		u.open("ABOUT US.txt");
		while(!u.eof())
		{
			u.getline(r,1000);
			cout<<r<<"\n";
		}
		u.close();
		}
		if(l==3)
		{
	
			ifstream u;
		u.open("ACADEMICS.txt");
		while(!u.eof())
		{
			u.getline(r,1000);
			cout<<r<<"\n";
		}
		u.close();
	}
		if(l==4)
		{

			ifstream u;
		u.open("ADMISSIONS.txt");
		while(!u.eof())
		{
			u.getline(r,1000);
			cout<<r<<"\n";
		}
		u.close();
    }
		if(l==5)
		{

			ifstream u;
		u.open("CAMPUS LIFE.txt");
		while(!u.eof())
		{
			u.getline(r,1000);
			cout<<r<<"\n";
		}
		u.close();
		}
		if(l==6)
		{

			ifstream u;
		u.open("BULLETIN BOARD.txt");
		while(!u.eof())
		{
			u.getline(r,1000);
			cout<<r<<"\n";
		}
		u.close();
		}
	
		if(l==7)
		{
			ifstream u;
		u.open("CONTACT US.txt");
		while(!u.eof())
		{
			u.getline(r,1000);
			cout<<r<<"\n";
		}
		u.close();
		}
		if(l==8)
			{
			}
		else
		{
			cout<<"INVALID ENTRY\n";
		}
		cout<<"DO YOU WANT TO CONTINUE\n1.YES(GUEST MENU)\n2.NO(LOGIN TYPE):\n";
		cin>>ask;
	};
	  
    }
}
void student()
{
	system("cls");
	int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 cout<<"Enter YOUR ADMISSION NUMBER: ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"DETAILS OF ADDMISSION NUMBER: "<<n<<" DISPLAYED BELOW:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)cout<<"THE ADMISSION NUMBER: "<<n<<" NOT FOUND....\n\n";
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";	
}
void teacher()
{
	system("cls");
		int n, flag=0;
 ifstream fin;
 fin.open("TEACHERS.dat",ios::in|ios::binary);
 cout<<"Enter YOUR REGISTRATION NUMBER: ";
 cin>>n;
 
 while(fin.read((char*)&t,sizeof(t)))
 {
  if(n==t.getregno())
  {
   cout<<"DETAILS OF REGISTRATION NUMBER: "<<n<<" DISPLAYED BELOW:\n";
   t.showdata();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"THE REGISTRATION NUMBER: "<<n<<" NOT FOUND....\n\n";
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";
}
void parent()
{
	system("cls");
	int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 cout<<"Enter YOUR ADMISSION NUMBER: ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"DETAILS OF ADMISSION NUMBER: "<<n<<" DISPLAYED BELOW:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)cout<<"THE ADMISSION NUMBER "<<n<<" NOT FOUND....\n\n";
 cout<<"\n\nDATA READ SUCCESSFULLY....\n";	
	
}




void Student::getData()
{
 cout<<"\n\nENTER STUDENT DETAILS......\n";
 cout<<"Enter Admission No.     : "; cin>>admno;
 cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,200);
 cout<<"Enter Gender (M/F)      : "; cin>>gender;
 cout<<"Enter Standard          : "; cin>>std;
 cout<<"Enter Marks (out of 500): "; cin>>marks;
 cout<<endl;
 percentage=marks*100.0/500.00;
}
void Teacher::getdata()
{
 cout<<"\n\nEnter STAFF Details......\n";
 cout<<"Enter REGISTRATION No.  : "; cin>>regno;
 cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,200);
 cout<<"Enter Gender (M/F)      : "; cin>>gender;
 cout<<"Enter PHONE NUMBER      : "; cin.ignore();cin.getline(phone,100);
 cout<<"Enter SALARY            : "; cin>>salary;
 cout<<"ENTER STAFF GRADE       : ";cin>>standard;
 cout<<endl;
}
void Guest::getdatA()
{
 cout<<"\n\nENTER YOUR Details......\n";
 cout<<"Enter Full Name                                  :"; cin.ignore(); cin.getline(name,200);
 cout<<"Enter YOUR WARDS Full Name                       :"; cin.ignore(); cin.getline(sname,200);
 cout<<"Enter YOUR WARDS Gender (M/F)                    :"; cin>>gender;
 cout<<"WHAT GRADE ARE YOU WISHING TO JOIN YOUR WARD IN  :"; cin>>grade;
 cout<<"Enter PHONE NUMBER                               :"; cin.ignore(); cin.getline(phone,100);
 cout<<"Enter ADDRESS                                    :"; cin.ignore(); cin.getline(address,1000);
 cout<<endl;
}
void Student::showData()
{
 cout<<"\n\n.......STUDENT DETAILS......\n";
 cout<<"Admission No.     : "<<admno<<endl;
 cout<<"Full Name         : "<<name<<endl;
 cout<<"Gender            : "<<gender<<endl;
 cout<<"Standard          : "<<std<<endl;
 cout<<"Marks (out of 500): "<<marks<<endl;
 cout<<"Percentage        : "<<percentage<<endl;
 cout<<endl;
}

void Teacher::showdata()
{
 cout<<"\n\n.......STAFF DETAILS......\n";
 cout<<"REGISTRATION  No. : "<<regno<<endl;
 cout<<"Full Name         : "<<name<<endl;
 cout<<"Gender            : "<<gender<<endl;
 cout<<"PHONE NUMBER      : "<<phone<<endl;
 cout<<"SALARY            : "<<salary<<endl;
 cout<<"STAFF GRADE       : "<<standard<<endl;
 cout<<endl;
}
void Guest::showdatA()
{
	cout<<"FULL NAME           :"<<name<<endl;
	cout<<"STUDENT NAME        :"<<sname<<endl;
	cout<<"STUDENT GENDER      :"<<gender<<endl;
	cout<<"STUDENT GRADE VISIT :"<<grade<<endl;
	cout<<"PARENT PHONE NUMBER :"<<phone<<endl;
	cout<<"RESIDENTIAL ADDRESS :"<<address<<endl;
	cout<<endl;
}
/*void addData()
{
 ofstream fout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n\nDATA WRITTEN TO FILE....\n";
}

void adddata()
{
 ofstream fout;
 fout.open("TEACHERS.dat",ios::binary|ios::out|ios::app);
 t.getdata();
 fout.write((char*)&t,sizeof(t));
 fout.close();
}

void displayData()
{
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
}

void displaydata()
{
 ifstream fin;
 fin.open("TEACHERS.dat",ios::in|ios::binary);
 while(fin.read((char*)&t,sizeof(t)))
 {
  t.showdata();
 }
 fin.close();
 }

void searchData()
{
 int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 cout<<"ENTER ADMISSION NUMBER TO SEARCH : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"THE DETAILS OF ADMISSION NUMBER: "<<n<<" DISPLAYED BELOW:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"THE ADMISSION NUMBER: "<<n<<" NOT FOUND....\n\n";
}

void searchdata()
{
 int n, flag=0;
 ifstream fin;
 fin.open("TEACHERS.dat",ios::in|ios::binary);
 cout<<"Enter REGISTRATION NUMBER TO SEARCH : ";
 cin>>n;
 
 while(fin.read((char*)&t,sizeof(t)))
 {
  if(n==t.getregno())
  {
   cout<<"THE DETAILS OF REGISTRATION NUMBER: "<<n<<" DISPLAYED BELOW:\n";
   t.showdata();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"THE ADMISSION NUMBER ENTERED: "<<n<<" NOT FOUND....\n\n";

}

void deleteData()
{
 int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Students.dat",ios::in|ios::binary);
 fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
 tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);

 cout<<"ENTER ADMISSION NUMBER TO TRASH : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"ENTERED ADMISSION NUMBER: "<<n<<" HAS BEEN TRASHED:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 remove("Students.dat");
 rename("tempStud.dat","Students.dat");
}

void getTrash()
{
 ifstream fin;
 fin.open("TrashStud.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
}

void modifyData()
{
 int n, flag=0, pos;
 fstream fio;

 fio.open("Students.dat",ios::in|ios::out|ios::binary);
 
 cout<<"ENTER ADMISSION NUMBER TO MODIFY: ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getAdmno())
  {
   cout<<"THE ADMISSION NUMBER: "<<n<<" WILL BE MODIFIED WITH NEW DETAILS:\n";
   s.showData();
   cout<<"\n\nENTER THE DETAILS BELOW....\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"THE ADMISSION NUMBER: "<<n<<" NOT FOUND....\n\n";
}
/*/
void DSAJCOMPO()
{
 int ch,q,close=0;
 int  x=1;
 while(x==1)
 {
  system("cls");
    cout<<"\n\t\t\t\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
    cout<<"\n\t\t\t\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%     ";
    cout<<"\n\t\t\t\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%  ";
    cout<<"\n\t\t\t\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%     ";
    cout<<"\n\t\t\t\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%";
    cout<<"\n\n\t\t\t\t\t\t          %%%%%%%%  %%%%%        ";
    cout<<"\n\t\t\t\t\t\t             %%     %   %      ";
    cout<<"\n\t\t\t\t\t\t             %%     %%%%%    \n\n\n";
	
	
	
	cout<<"\t\t\t%%%%%%%% %%%%%%% %%%%%%% %%%%%%%%% %%      %%%%%%%% %%%%     %% %%%%%%%%%%\n";
	cout<<"\t\t\t%%       %%      %%        %     % %%         %%    %%  %%   %% %%        \n";
	cout<<"\t\t\t%%%%%%%% %%%%%%% %%%%%%%   %     % %%         %%    %%   %%  %% %%    %%%%\n";
	cout<<"\t\t\t      %% %       %%        %     % %%         %%    %%    %% %% %%    %% %\n";
	cout<<"\t\t\t%%%%%%%% %%%%%%% %%%%%%% %%%%%%%%% %%%%%%% %%%%%%%% %%     %%%% %%%%%%%% %\n";
	cout<<"\t\t\t\t\t\tPRIMARY SCHOOL\n";
	
	cout<<"\n\nSELECT LOGIN TYPE:\n";
	cout<<"1.PRINCIPAL\n2.TEACHER\n3.STUDENT\n4.PARENT\n5.GUEST SESSION\n6.EXIT\n";
	cin>>q;
	switch(q)
	{
		case 1:principal();
		break;
		case 2:teacher();
		break;
		case 3:student();
		break;
		case 4:parent();
		break;
		case 5:guest();
		break;
		case 6:
			close++;
			x++;
		break;
		default:cout<<"*********INVALID INPUT*************";
		break;		
	}
	if(close==0)
	{
	cout<<"DO YOU WANT TO CONTINUE :\n1.YES(LOGIN MENU)\n2.NO(EXIT PROGRAM)\n";
	cin>>x;
  system("pause");
   }
 };
}

int main()
{
 DSAJCOMPO();
 cout<<"done by \n\nsathya\t\t19mic0110\nkarthick\t\t19mic0118";
 
}


