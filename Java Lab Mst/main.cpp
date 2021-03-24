#include<iostream>
#include<string.h>
using namespace std;

struct Admin{
	static int id;
	string AID;
	string Name;
	string Email;
	string Contact;
	string Designation;
	string Password;
	Admin *Link;
};
Admin *admin = new Admin();
Admin *apoint = admin;


struct Student{
	int id;
	string UID;
	string Name;
	string Email;
	string Contact;
	string Course;
	string Section;
	float Fees;
	string Password;
	Student *Link;
};
Student *student = new Student();
Student *spoint = student;

struct Faculty{
	int id;
	string FID;
	string Name;
	string Email;
	string Contact;
	string Designation;
	float Salary;
	string Password;
	Faculty *Link;
};
Faculty *faculty = new Faculty();
Faculty *fpoint = faculty;

struct Subjects{
	int id;
	int Student_ID;
	int Faculty_ID;
	string Title;
	string Details;
	string Time;
	Subjects *Link;
};
Subjects *subject = new Subjects();
Subjects *subpoint = subject;


class Students{
	Student *s;

	public:
	static int id;
	void Assign_Students(Student *temp)
	{
		s = temp;
	}
	
	
	
	void Load()
	{
		cout<<"UID:- "<<s->UID<<endl;
		cout<<"Name:- "<<s->Name<<endl;
		cout<<"Email:- "<<s->Email<<endl;
		cout<<"Contact:- "<<s->Contact<<endl;
		cout<<"Course:- "<<s->Course<<endl;
		cout<<"Section:- "<<s->Section<<endl;
		cout<<"Fees:- "<<s->Fees<<endl;
	}
	
	void TimeTable()
	{
		Subjects *subj = new Subjects();
		subj = subject->Link;
		cout<<"\nTime Table\n";
		while(subj != NULL)
		{
			if(subj->Student_ID = s->id)
			{
				cout<<subj->Title<<" "<<subj->Details<<" "<<subj->Time<<endl;
			}
			subj = subj->Link;
		}
	}
};

class Facultys{
	Faculty *f;

	public:
	static int id;
	void Assgn_Facultys(Faculty *temp)
	{
		f = temp;
	}
	
	
	void Load()
	{
		cout<<"FID:- "<<f->FID<<endl;
		cout<<"Name:- "<<f->Name<<endl;
		cout<<"Email:- "<<f->Email<<endl;
		cout<<"Contact:- "<<f->Contact<<endl;
		cout<<"Designation:- "<<f->Designation<<endl;
		cout<<"Salary:- "<<f->Salary<<endl;
	}
	
	void TimeTable()
	{
		Subjects *subj = new Subjects();
		subj = subject->Link;
		cout<<"\nTime Table\n";
		while(subj != NULL)
		{
			if(subj->Faculty_ID == f->id)
			{
				cout<<subj->Title<<" "<<subj->Details<<" "<<subj->Time<<endl;
			}
			subj = subj->Link;
		}
	}
};

class Admins{
	public:
	static int id;
	Admin *a;
	void Assign_Admins(Admin *temp)
	{
		a = temp;
	}
	
	
	void Add_Student()
	{
		Student *temp = new Student();
		temp->id = a->id;
		a->id++;
		cout<<"Enter UID\n";
		cin>>temp->UID;
		cout<<"Enter Password\n";
		cin>>temp->Password;
		cout<<"Enter Name\n";
		cin>>temp->Name;
		cout<<"Enter Email\n";
		cin>>temp->Email;
		cout<<"Enter Contact\n";
		cin>>temp->Contact;
		cout<<"Enter Course\n";
		cin>>temp->Course;
		cout<<"Enter Section\n";
		cin>>temp->Section;
		cout<<"Enter Fees\n";
		cin>>temp->Fees;
		spoint->Link = temp;
		spoint = temp;
	}
	
	void Add_Faculty()
	{
		Faculty *temp = new Faculty();
		temp->id = a->id;
		a->id++;
		cout<<"Enter FID\n";
		cin>>temp->FID;
		cout<<"Enter Password\n";
		cin>>temp->Password;
		cout<<"Enter Name\n";
		cin>>temp->Name;
		cout<<"Enter Email\n";
		cin>>temp->Email;
		cout<<"Enter Contact\n";
		cin>>temp->Contact;
		cout<<"Enter Designation\n";
		cin>>temp->Designation;
		cout<<"Enter Salary\n";
		cin>>temp->Salary;
		fpoint->Link = temp;
		fpoint = temp;
		
	}
	
	void Add_Admin()
	{
		Admin *temp = new Admin();
		temp->id = a->id;
		a->id++;
		cout<<"Enter FID\n";
		cin>>temp->AID;
		cout<<"Enter Password\n";
		cin>>temp->Password;
		cout<<"Enter Name\n";
		cin>>temp->Name;
		cout<<"Enter Email\n";
		cin>>temp->Email;
		cout<<"Enter Contact\n";
		cin>>temp->Contact;
		cout<<"Enter Designation\n";
		cin>>temp->Designation;
		apoint->Link = temp;
		apoint = temp;
	}
	
	void Add_TimeTable()
	{
		
		cout<<"Enter Faculty\n";
		string fid;
		cin>>fid;
		
		int f_id = 0;
		Faculty *f = new Faculty();
		f = faculty->Link;
		while(f!=NULL)
		{
			if(f->FID == fid)
			{
				f_id =f->id;	
			}		
			f = f->Link;
		}
		string crs, sctn;
		
		cout<<"Enter Course\n";
		cin>>crs;
		cout<<"Enter Section\n";
		cin>>sctn;
		Student *s = new Student();
		while(s!=NULL)
		{
			if(s->Course == crs && s->Section == sctn)
			{
				Subjects *temp = new Subjects();
				temp->id = a->id;
				a->id++;
				temp->Faculty_ID = f_id;
				cout<<"Enter Course Title\n";
				cin>>temp->Title;
				cout<<"Enter Course Details\n";
				cin>>temp->Details;
				cout<<"Enter Course Time\n";
				cin>>temp->Time;
				temp->Student_ID = s->id;
				subpoint->Link = temp;
				subpoint = temp;
			}
			s = s->Link;
		}
	}
};


class EBMS{
	public:
	
	void Menu()
	{
		int e = 1;
		while(e != 0)
		{
			cout<<"1) Login\n0) Exit\n";
			cin>>e;
			switch(e)
			{
				case 1:
					Login();
					break;
				case 0:
					e = 0;
					break;
			}
		}
	}
	
	void Login()
	{
		string user, password;
		cout<<"Enter User ID\n";
		cin>>user;
		cout<<"Enter Password\n";
		cin>>password;
		
		if(Check_Students(user, password) != NULL)
		{
			Students *s = new Students();
			s->Assign_Students(Check_Students(user, password));
			int e = 1;
			while(e != 0)
			{
				cout<<"1) Load\n2)TimeTable\n0) Exit\n";
				cin>>e;
				switch(e)
				{
					case 1:
						s->Load();
						break;
					case 2:
						s->TimeTable();
						break;
					case 0:
						e = 0;
						break;
				}
			}
		}
		else if(Check_Faculty(user, password) != NULL)
		{
			Facultys *f = new Facultys();
			f->Assgn_Facultys(Check_Faculty(user,password));
			int e = 1;
			while(e != 0)
			{
				cout<<"1) Load\n2)TimeTable\n0) Exit\n";
				cin>>e;
				switch(e)
				{
					case 1:
						f->Load();
						break;
					case 2:
						f->TimeTable();
						break;
					case 0:
						e = 0;
						break;
				}
			}
		}
		else if(Check_Admin(user, password) != NULL)
		{
			Admins *a = new Admins();
			int e = 1;
			while(e != 0)
			{
				cout<<"1) Add Student\n2)Add Faculty\n3) Add TimeTable\n4)Add Admin\n0) Exit\n";
				cin>>e;
				switch(e)
				{
					case 1:
						a->Add_Student();
						break;
					case 2:
						a->Add_Faculty();
						break;
					case 3:
						a->Add_TimeTable();
						break;
					case 4:
						a->Add_Admin();
						break;
					case 0:
						e = 0;
						break;
				}
			}
		}
	}
	
	Student *Check_Students(string user, string password)
	{
		Student *temp = student->Link;
		while(temp != NULL)
		{
			if(temp->UID == user && temp->Password == password)
			{
				cout<<user<<" Login sucessfully";
				return temp;
			}
			temp = temp->Link;
		}
		return NULL;
	}
	
	Faculty *Check_Faculty(string user, string password)
	{
		Faculty *temp = faculty->Link;
		while(temp != NULL)
		{
			if(temp->FID == user && temp->Password == password)
			{
				cout<<user<<" Login sucessfully";
				return temp;
			}
			temp = temp->Link;
		}
		return NULL;
	}
	
	Admin *Check_Admin(string user, string password)
	{
		Admin *temp = admin->Link;
		while(temp != NULL)
		{
			if(temp->AID == user && temp->Password == password)
			{
				cout<<user<<" Login sucessfully";
				return temp;
			}
			temp = temp->Link;
		}
		return NULL;
	}
};

int Admin::id  =1;

int main()
{
	Admins admin;
	admin.Add_Admin();
	EBMS ebms;
	ebms.Menu();
}
