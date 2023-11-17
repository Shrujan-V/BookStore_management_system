#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#include<sstream>
#include<ctime>
#include<conio.h>

using namespace std;

class Bookstore
{
	public:
	void addBooks();
	void interface();
	void searchById();
	void searchByBookName();
	void searchByAuthors();
	void updateById();
	void displaybook();
	void deletebooks();
	void sellBook();
	
};

void Bookstore::sellBook()
{
	time_t tt;
    struct tm* ti; 
    time(&tt);
    ti = localtime(&tt); 
	Bookstore obj;
	obj.interface();
	int choice ;
	string id,name1,author,temp,line;
	char Y='y';
	fstream file,file1,file2;
	int num_cop,st=0;
	int no_copy, count = 0;
	string b_id, b_idd, b_name, a_name,bb_name,aa_name;
	cout<<"\nHOW MANY BOOKS ARE YOU SELLING? : "<<endl;
	int num;
	cin>>num;

	do
	{
	file2.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\bookregistry.csv",ios:: out| ios::app);
	file.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv",ios::in | ios::app);
	file1.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project1.csv",ios:: out| ios::app);
	if (!file)
		cout << "\n\nFile Opening Error...";
	else
		{
		
		cout << "\n\nBOOK ID : ";
		cin >> b_id;
		
					while(getline(file,line)){
						stringstream inpstr(line);	
						getline(inpstr,id,',');
						getline(inpstr,name1,',');
						getline(inpstr,author,',');
						getline(inpstr,temp,',');
						num_cop=atoi(temp.c_str());
						

						if(id==b_id){
							cout<<"HOW MANY COPIES SOLD?: ";
							cin>>no_copy;
							if(no_copy<=num_cop){
							file1<<id<<','<<name1<<','<<author<<','<<num_cop-no_copy<<"\n";
							count=1;
							file2<<id<<','<<name1<<','<<author<<','<<no_copy<<asctime(ti)<<"\n";}
							else{
							file1<<id<<','<<name1<<','<<author<<','<<num_cop<<"\n";
							cout<<"NOT ENOUGH BOOKS"<<endl;
							getch();
							}
						}
						else
						{
							file1<<id<<','<<name1<<','<<author<<','<<num_cop<<"\n";
						}
						}
						if(count!=1)
						cout<<"BOOK NOT FOUND!";
		}
	file1.close();
	file.close();
	file2.close();
	remove("project.csv");
	rename("project1.csv",
		"project.csv");
	num--;

	}while(num);
	
}

void Bookstore::displaybook()
{
    Bookstore obj;
    obj.interface();
    fstream file;
    string id,name1,author,temp;
    int num_cop;
    string line ="";
    file.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv", ios::in | ios::app);
    if (!file)
        cout << "\n\nFILE OPENING ERROR !";
    else{
            printf("\n%-35s %-35s %-35s %-35s\n","ID","NAME","AUTHOR","NUMBER OF COPIES");
			printf("--------------------------------------------------------------------------------------\
-----------------------------------------\n");
            while (getline(file, line)) {
                stringstream inpstr(line);
                getline(inpstr, id, ',');
                getline(inpstr, name1, ',');
                getline(inpstr, author, ',');
                getline(inpstr, temp, ',');
                num_cop = atoi(temp.c_str());
                printf("%-35s %-35s %-35s %-35s\n",id.c_str(),name1.c_str(),author.c_str(),temp.c_str());
                line = "";
			}
            file.close();
}
cout<<endl;
cout<<"PRESS ANY KEY TO CONTINUE...";
getch();
}
void Bookstore::deletebooks()
{
	Bookstore obj;
	obj.interface();
	//DELETE BOOK WITH ID ,DELETE ALL BOOKS OF A PARTICULAR AUTHOR,dELETE BOOK USING NAME ,BURNN LIB!!
	int choice ;
	string id,name1,author,temp,line;
	fstream file, file1;
	int num_cop,st=0;
	int no_copy, count = 0;
	string b_id, b_idd, b_name, a_name,bb_name,aa_name;

	// Append file in output mode
	
	file.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv",ios::in | ios::app);
	file1.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project1.csv",ios:: out| ios::app);
	if (!file)
		cout << "\n\nFile Opening Error...";
	else
		{
		cout<<"1.DELETE BOOK WITH ID\n2.DELETE ALL BOOKS OF A PARTICULAR AUTHOR\n3.DELETE BOOK USING NAME\n4.BURNN LIB!!\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout << "\n\nBook ID : ";
					cin >> b_id;
					while(getline(file,line)){
						stringstream inpstr(line);	
						getline(inpstr,id,',');
						getline(inpstr,name1,',');
						getline(inpstr,author,',');
						getline(inpstr,temp,',');
						num_cop=atoi(temp.c_str());
						

						if(id==b_id){
							
							count=1;
						}
						else
						{
							file1<<id<<','<<name1<<','<<author<<','<<num_cop<<"\n";
						}
						}
						if (count == 0)
							cout << "\n\nBook ID "
								<< "Not Found...";
							
						break;
			case 2:
				cout << "\n\nAUTHOR  : ";
					cin >> aa_name;
					
					while(getline(file,line)){
						stringstream inpstr(line);	
						getline(inpstr,id,',');
						getline(inpstr,name1,',');
						getline(inpstr,author,',');
						getline(inpstr,temp,',');
						num_cop=atoi(temp.c_str());
						

						if(author==aa_name){
							
							count=1;
						}
						else
						{
							file1<<id<<','<<name1<<','<<author<<','<<num_cop<<"\n";
						}
						}
						if (count == 0)
							cout << "\n\nBook ID "
								<< "Not Found...";
							
						break;
			case 3:
				cout<<"NAME OF THE BOOK";
				cin>>bb_name;
				while(getline(file,line)){
						stringstream inpstr(line);	
						getline(inpstr,id,',');
						getline(inpstr,name1,',');
						getline(inpstr,author,',');
						getline(inpstr,temp,',');
						num_cop=atoi(temp.c_str());
						

						if(name1==bb_name){
							
							count=1;
						}
						else
						{
							file1<<id<<','<<name1<<','<<author<<','<<num_cop<<"\n";
						}
						}
						if (count == 0)
							cout << "\n\nBook ID "
								<< "Not Found...";
							
						break;
			case 4:
				remove("book.csv");
				rename("book1.csv","book.csv");
				break;
	}
	// Close the file
	file1.close();
	file.close();
	remove("project.csv");
	rename("project1.csv",
		"project.csv");
}
}
void Bookstore::interface()
{
	system("cls");
	cout<<"---------------------------------------------------********  (\\_/)                        (\\_/)  ********\
---------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\
     (^.^)   WELCOME TO BUNNIES   (^.^)"<<endl;
	cout<<"---------------------------------------------------********  /> <\\                        /> <\\  ********\
---------------------------------------------------"<<endl;
cout<<"\n\n\n";
}

void Bookstore::searchById()
{
	Bookstore obj;
	obj.interface();
	string id;
	cout<<"\t ENTER THE ID: ";
    cin>>id;
	fstream file;
	string id1,name,author,temp;
    int num_cop,st=0;
    string line="";
	file.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv",ios::in | ios::app);
	if (!file)
		cout << "\n\nFILE OPEANING ERROR!";
	else {
		
		while(getline(file,line)){
			stringstream inpstr(line);	
			getline(inpstr,id1,',');
			getline(inpstr,name,',');
			getline(inpstr,author,',');
            getline(inpstr,temp,',');
            num_cop=atoi(temp.c_str());

			if(id==id1){
				cout<<"\nNAME : "<<name<<"\nAUTHOR : "<<author<<"\nNUMBER OF COPIES : "<<num_cop<<endl;
				cout<<"\n";
				st=1;
			}
            line="";
		}
		
	}
	if(!st)
			cout<<"\nID NOT FOUND!!\n\n";
    file.close();
	
}

void Bookstore::searchByAuthors()
{
	Bookstore obj;
	obj.interface();
	string author;
	cout<<"\t ENTER THE AUTHOR :";
	cin>>author;
	fstream file;
	string id,name,author1,temp;
    int num_cop,st=0;
    string line="";
	file.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv",ios::in | ios::app);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {
			
		while(getline(file,line)){
			stringstream inpstr(line);	
			getline(inpstr,id,',');
			getline(inpstr,name,',');
			getline(inpstr,author1,',');
            getline(inpstr,temp,',');
            num_cop=atoi(temp.c_str());

			if(author==author1){
				cout<<"\nid : "<<id<<"\nname : "<<name<<"\nnumber of copies : "<<num_cop<<"\n"<<endl;
				st=1;
			}
            line="";
		}
		
	}
	if(!st)
		cout<<"\nAUTHOR NOT FOUND!!\n\n";
    file.close();
	
}

void Bookstore::updateById()
{
	Bookstore obj;
	obj.interface();
	int choice ;
	string id,name1,author,temp,line;
	char Y='y';
	fstream file, file1;
	int num_cop,st=0;
	int no_copy, count = 0;
	string b_id, b_idd, b_name, a_name,bb_name,aa_name;
	do
	{
	file.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv",ios::in | ios::app);
	file1.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project1.csv",ios:: out| ios::app);
	if (!file)
		cout << "\n\nFile Opening Error...";
	else
		{
		cout << "\n\nBOOK ID : ";
					cin >> b_id;
					while(getline(file,line)){
						stringstream inpstr(line);	
						getline(inpstr,id,',');
						getline(inpstr,name1,',');
						getline(inpstr,author,',');
						getline(inpstr,temp,',');
						num_cop=atoi(temp.c_str());
						

						if(id==b_id){
							cout<<"ENTER THE NEW ID: ";
							cin>>id;
							cout<<"ENTER THE NAME: ";
							cin>>name1;
							cout<<"ENTER THE AUTHOR: ";
							cin>>author;
							cout<<"ENTER THE NUMBER OF COPIES: ";
							cin>>no_copy;
							file1<<id<<','<<name1<<','<<author<<','<<no_copy<<"\n";
							count=1;
						}
						else
						{
							file1<<id<<','<<name1<<','<<author<<','<<num_cop<<"\n";
						}
						}
						if(count!=1)
						cout<<"BOOK NOT FOUND!";
		}
	file1.close();
	file.close();
	remove("project.csv");
	rename("project1.csv",
		"project.csv");
		
	cout<<"\nDO YOU WANT TO CONTINUE Y|N :";
	cin>>Y;
	}while(Y=='y' || Y=='Y');
}

void Bookstore::searchByBookName()
{
	Bookstore obj;
	obj.interface();	
	string name;
	cout<<"\t ENTER THE BOOK NAME: ";
	cin>>name;
	fstream file;
	string id,name1,author,temp;
    int num_cop,st=0;
    string line="";
	file.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv",ios::in | ios::app);
	if (!file)
		cout << "\n\nFILE OPEANING ERROR!";
	else {
			
		while(getline(file,line)){
			stringstream inpstr(line);	
			getline(inpstr,id,',');
			getline(inpstr,name1,',');
			getline(inpstr,author,',');
            getline(inpstr,temp,',');
            num_cop=atoi(temp.c_str());
			

			if(name==name1){
				cout<<"\nid :"<<id<<"\nAUTHOR : "<<author<<"\nNUMBER OF COPIES : "<<num_cop<<"\n"<<endl;
				st=1;
			}
            line="";
		}
		
	}
	if(!st)
		cout<<"\nBOOK NOT FOUND!!\n\n";
    file.close();
	char str;
	if(str=='y' || str=='Y')
		obj.searchByBookName();
	else return;
	
}
void Bookstore::addBooks()
{
	Bookstore obj;
	obj.interface();
	fstream csvfile;
	int no_copies;
	string id,name,author;
	cout<<"\nENTER THE BOOK ID : ";
	cin>>id;
	cout<<"\nENTER THE BOOK NAME : ";
	cin>>name;
	cout<<"\nENTER THE BOOK'S AUTHOR : ";
	cin>>author;
	cout<<"\nENTER THE NUMBER OF COPIES : ";
	cin>>no_copies;
	
	csvfile.open("C:\\Users\\shruj\\OneDrive\\Documents\\c++\\project.csv",ios::app);
	csvfile<<id<<','<<name<<','<<author<<','<<no_copies<<"\n";
	csvfile.close();
	char str;
	cout<<"\nDO YOU WANT TO CONTINUE Y | N ? ";
	cin>>str;
	if(str=='y' || str=='Y')
		obj.addBooks();
	else return;

}

int main()
{
	int choice,choice2;
	string name,author,id;
	Bookstore obj;
	do{
		obj.interface();
		cout<<"\t\t\t\t\t\t\t\t     1.SELL BOOK\n\t\t\t\t\t\t\t\t     2.LIST ALL BOOKS\n\t\t\t\t\t\t\t\t     3.ADD BOOK\n\t\t\t\t\t\t\t\t     4.UPDATE BOOK\n\
\t\t\t\t\t\t\t\t     5.DELETE BOOK\n\t\t\t\t\t\t\t\t     6.SEARCH BOOK"<<endl<<endl;
	cout<<"WHAT OPERATION DO YOU WANT TO PERFORM?\n"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		obj.sellBook();
		break;
		case 2:
		obj.displaybook();
		break;
		case 3:
		obj.addBooks();
		break;
		case 4:
		obj.updateById();
		break;
		case 5:
		obj.deletebooks();
		break;
		case 6:
		char str;
		do
		{
		obj.interface();
		cout<<"\n1. SEARCH BY ID\n2. SEARCH BY NAME\n3. SEARCH BY AUTHOR\n"<<endl;
			cin>>choice2;
			switch(choice2){
				case 1:
            		obj.searchById();
					break;
				case 2:
					
					obj.searchByBookName();
					break;
				case 3:
					
					obj.searchByAuthors();
					break;
				default:
					cout<<"\nENTER A VALID CHOICE!!\n";
					break;
			}
			
			cout<<"\nDO YOU WANT TO CONTINUE Y | N ? ";
			cin>>str;
		}while(str=='y');
		break;
		default:
		cout<<"INVALID CHOICE\n";
		break;
	}
	}while(choice!=6);
}