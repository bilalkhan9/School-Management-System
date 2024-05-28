#include<iostream>
#include<fstream>
using namespace std;

int ID;
class Student
{
 	  public :
	  		 int id;
			 string name;
			 int age;
			 string stream;
			 
		void addStudent()
		{
		  	 cout<<"Enter Name"<<endl;
		  	 cin.get();
		  	 getline(cin,name);
		  	 cout<<"Enter Your age"<<endl;
		  	 cin>>age;
		  	 cout<<"Enter Your Stream"<<endl;
		  	 cin.get();
		  	 getline(cin,stream);
		  	 ID++;
		  	 
		  	 ofstream fout;
		  	 fout.open("c:/file/student.txt",ios::app);
		  	 fout<<"\n"<<ID;
		  	 fout<<"\n"<<name;
		  	 fout<<"\n"<<age;
		  	 fout<<"\n"<<stream;
		  	 fout.close();
			 
			 fout.open("c:/file/ID.txt",ios::app);
			 fout<<	"\n"<<ID;
			 fout.close();	  	 
		  	 
		  	 cout<<"Record Added Succesfully"<<endl;
	    }
		
		void printAllStudents()
		{
		  	ifstream fin;
			  fin.open("c:/file/student.txt");
			  
			  Student s;
			  
			  while(!fin.eof())
			  {
			    fin>>s.id;
				fin.ignore();
				getline(fin,s.name);
				fin>>s.age;
				fin.ignore();
				getline(fin,s.stream);
				
				
				cout<<"\nID = "<<s.id;
				cout<<"\nName = "<<s.name;
				cout<<"\nAge = "<<s.age;
				cout<<"\nStream = "<<s.stream;
				 				   
			  } 
			  fin.close();
        }
		
		void searchStudent(int id)
		{
		 	 ifstream fin;
			  fin.open("c:/file/student.txt");
			  
			  Student s;
			  
			  while(!fin.eof())
			  {
			    fin>>s.id;
				fin.ignore();
				getline(fin,s.name);
				fin>>s.age;
				fin.ignore();
				getline(fin,s.stream);
				
				if(id==s.id)
				{
				
				cout<<"\nID = "<<s.id;
				cout<<"\nName = "<<s.name;
				cout<<"\nAge = "<<s.age;
				cout<<"\nStream = "<<s.stream;
				 
				 break;
				 }				   
			  } 
			  fin.close();
        }
        
        void deleteStudent(int id)
        {
		   ifstream fin;
		   fin.open("c:/file/student.txt");
		   
		   ofstream fout;
		   fout.open("c:/file/temp.txt");
		   
		   Student s;
		   while(!fin.eof())
		   {
		   	fin>>s.id;
			fin.ignore();
			getline(fin,s.name);
			fin>>s.age;
			fin.ignore();
			getline(fin,s.stream);
			
			if(id != s.id)
			{
			   fout<<"\n"<<s.id;
		  	 fout<<"\n"<<s.name;
		  	 fout<<"\n"<<s.age;
		  	 fout<<"\n"<<s.stream;
		  	 
			  			
		    }
								
		   }
		   fin.close();
		   fout.close();
		   
		   remove("c:/file/student.txt");
		   rename("c:/file/temp.txt" , "c:/file/student.txt");
		   
		   cout<<"Record Deleted Successfully"<<endl;
		    	 
	    }
		
		void updateStudent(int id)
		{
		 	  	 deleteStudent(id);
		 	  	 
		 	  	 Student s;
		 	  	 cout<<"Enter Name"<<endl;
		 	  	 cin.get();
		 	  	 getline(cin,s.name);
		 	  	 cout<<"Enter Age"<<endl;
		 	  	 cin>>s.age;
		 	  	 cout<<"Enter Stream"<<endl;
		 	  	 cin.get();
		 	  	 getline(cin,s.stream);
		 	  	 
		 	  	 ofstream fout;
		 	  	 fout.open("c:/file/student.txt",ios::app);
		 	  
			   fout<<"\n"<<id;
		  	   fout<<"\n"<<s.name;
		  	   fout<<"\n"<<s.age;
		  	   fout<<"\n"<<s.stream;
		  	   
		  	   fout.close();
		  	   
		  	   cout<<"Record Updeted Successfully"<<endl;
		  	 	 
        }
        
        
}; 

int main()
{
 int choice;
 
 ifstream fin;
 fin.open("c:/file/id.txt");
 if(!fin)
 {
  cout<<"File Not Found"<<endl; 		 
 }
 else
 {
  while(!fin.eof())
  	{
	 	fin>>ID; 			 
    } 	 
 }
 fin.close();
 while(true)
 {
  cout<<"\n\n========================"<<endl;
  cout<<"\nEnter your Choice"<<endl;
  cout<<"1. Add Student"<<endl;
  cout<<"2. Print All Student"<<endl;
  cout<<"3. Saerch a Student"<<endl;
  cout<<"4. Uodate a Student"<<endl;
  cout<<"5. Delete a Student"<<endl;
  
  cin>>choice;
  
  Student s;
  int id; 
  
  switch(choice)
  {
   case 1:
   		s.addStudent();
   		break;
   case 2:
   		s.printAllStudents();
   		break;
   case 3:
   		cout<<"Enter Student id"<<endl;
   		cin>>id;
   		s.searchStudent(id);
   		break;
   		
   case 4:
   		cout<<"Enter Student id"<<endl;
   		cin>>id;
   		s.updateStudent(id);
   		break;
   case 5: 	
   		cout<<"Enter Student id"<<endl;
   		cin>>id;
   		s.deleteStudent(id);
   		break;
		   
		   default :
		   		   return 0;			
  }			
 } 	
 system("pause");
 return 0;
}
