#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class user
{
protected:
	string username;
	string email;
	string password;
public:
	virtual void signup() =0;
	virtual void showdata() {};
	virtual void displayabook() {};
	virtual void edit() {};
	virtual void add() {};
	virtual void del() {};
	virtual void modify() {};
	virtual void showallbk(){};
	virtual void displayavbook() {};
	virtual void order() {};
};
class book
{
	int bnum;
	string bname, author;
	string category;
	float price;
	int no_copy;

public:
	void addbook()
	{
		cout << "\nENTER DETAILS ABOUT BOOK U WANT TO PURCHASE\n";
		cout << "\nEnter The Book Number: ";
		cin >> bnum;
		cout << "\nEnter The Name of The Book: ";
		cin >> bname;
		cout << "\nEnter The Author's Name: ";
		cin >> author;
		cout << "\nEnter No. Of Copies : ";
		cin >> no_copy;
	}
	void showbook()
	{
		cout << "\nBook Number: " << bnum;
		cout << "\nBook Name: " << bname;
		cout << "\nAuthor's Name: " << author;
		cout << "\nCOPIES : " << no_copy;
	}
	void modify_book()
	{
		cout << "\nBook number : " << bnum;
		cout << "\nModify Book Name : ";
		cin >> bname;
		cout << "\nModify The Author's Name: ";
		cin >> author;
		cout << "\nMOdify No. Of Copies : ";
		cin >> no_copy;
	}
	int getbooknumber()
	{
		return bnum;
	}
	int av()
	{
		return no_copy;
	}
	void bookreport()
	{
		cout << bnum << setw(30) << bname << setw(30) << author << setw(30) << no_copy << endl;
	}
	void dstock()
	{
		no_copy--;
	}
};
///////////////////////////////////////////////
//fstream bok;
vector <book> boook;
////////////////////////////////////////////////////////////////
class admin :public user
{
public:
	void signup()
	{
		cout << "enter ur username :";
		cin >> username;
		cout << "enter ur email :";
		cin >> email;
		cout << "enter ur password :";
		cin >> password;
	}
	void showdata()
	{
		cout << username<<endl;
		cout << email<<endl;
		cout << password<<endl;
	}
	
	void add()
	{
			system("cls");
			book b;
			b.addbook();
			boook.push_back(b);
			cout << "-------------Added sucessfully---------------" << endl;
			b.bookreport();	
	}
	void modify()
	{
		int n;
		int flag = 1;
		system("cls");
		cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
		showallbk();
		cout << "which book number u want to edit:" << endl;
		cin >> n;
		for (int i = 0; i < boook.size(); i++)
		{
			if (boook[i].getbooknumber() == n)
			{
				boook[i].modify_book();
				cout << "editied succesfully" << endl;
				flag = 0;
				break;
			}
		}
		if (flag) {cout << "book not found" << endl;}
	}
		void del()
		{
			int n;
			int flag = 1;
			system("cls");
			cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
			showallbk();
			cout << "which book number u want to delete:" << endl;
			cin >> n;
			for (int i = 0; i < boook.size(); i++)
			{
				if (boook[i].getbooknumber() == n)
				{
					boook.erase(boook.begin() + i);
					cout << "erased succesfully" << endl;
					flag = 0;
					break;
				}
			}
			if (flag) { cout << "book not found" << endl; }
		}
	
	void displayabook() {
		int n;
		int flag = 1;
		system("cls");
		cout << "which book number u want to show" << endl;
		cin >> n;
		for (int i = 0; i < boook.size(); i++)
		{
			if (boook[i].getbooknumber() == n)
			{
				cout << "found succesfully" << endl;
				boook[i].showbook();
				flag = 0;
				break;
			}
		}
		if (flag) { cout << "book not found" << endl; }
	}

	void showallbk()
	{
		system("cls");
		cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
		for (int i = 0; i < (boook.size()); i++)
		{
			boook[i].bookreport();
		}
	}

};
class reader :public user
{
	int phoneno;
	string address;
	string paymentmethod;
	friend class user;
public:
	void signup()
	{
		cout << "enter ur username :";
		cin >> username;
		cout << "enter ur email :";
		cin >> email;
		cout << "enter ur password :";
		cin >> password;
		cout << "enter ur phoneno :";
		cin >> phoneno;
		cout << "enter ur address :";
		cin >> address;
		cout << "enter ur payment method: Cash/visa :";
		cin >> paymentmethod;
	}
	void showdata()
	{
		cout << username << endl;
		cout << email << endl;
		cout << password << endl;
		cout << phoneno << endl;
		cout << address << endl;
		cout << paymentmethod << endl;
	}
	void edit()
	{
		signup();
	}
	void displayavbook()
	{
		int flag = 1;
		system("cls");
		cout << "Avalible books" << endl;


		for (int i = 0; i < boook.size(); i++)
		{
			if (boook[i].av() != 0)
			{
				boook[i].showbook();
				flag = 0;
			}
		}
		if (flag) { cout << "No avalible books" << endl; }

	}
	void displayabook() {
		int n;
		int flag = 1;
		system("cls");
		cout << "which book number u want to show" << endl;
		cin >> n;
		for (int i = 0; i < boook.size(); i++)
		{
			if (boook[i].getbooknumber() == n)
			{
				cout << "found succesfully" << endl;
				boook[i].showbook();
				flag = 0;
				break;
			}
		}
		if (flag) { cout << "book not found" << endl; }
	}
	void order()
	{
		system("cls");
		cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
		displayavbook();
		int n;
		int flag = 1;
		cout << "which book number u want to order" << endl;
		cin >> n;
		for (int i = 0; i < boook.size(); i++)
		{
			if (boook[i].getbooknumber() == n && boook[i].av()!=0)
			{
				cout << "purchased succesfully" << endl;
				boook[i].showbook();
				boook[i].dstock();
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "book not found or unavalible " << endl;
		}
	}
};
	void main()
	{
		
		char d;
		int fl = 0;
		while (1)
		{ 
			user *us;
			while (fl != 1)
			{
				cout << "signup for a:admin or r:reader" << endl;
				cin >> d;
				switch (d)
				{
				case 'a':
					us = new admin;
					fl = 1;
					break;
				case 'r':
					us = new reader;
					fl = 1;
					break;
				default:
					cout << "\a";
				}
			}
			us->signup();
			fl = 0;
			system("cls");
			int option = 0;
				switch (d)
				{
				case 'a':
					while (option != 6) {
						cout << "\t\t----------------------------------------------------";
						cout << "\n\t\tPress 1 to Add new book";
						cout << "\n\t\tPress 2 to Modify book";
						cout << "\n\t\tPress 3 to Delete book";
						cout << "\n\t\tPress 4 to Show all books";
						cout << "\n\t\tPress 5 to Search for book";
						cout << "\n\t\tPress 6 to Exit and return to signup";
						cout << "\n\t\t----------------------------------------------------\n";
						cout << "\n\t\tOption: ";
						cin >> option;
						switch (option)
						{
						case 1:  system("cls");
							us->add();
							break;
						case 2: system("cls");
							us->modify();
							break;
						case 3: system("cls");
							us->del();
							break;
						case 4: system("cls");
							cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
							us->showallbk();
							break;
						case 5:
							system("cls");
							us->displayabook();
							break;
						case 6:delete us;
							break;
						default:cout << "\a";
						}
					}
				case 'r':
					while (option != 6){
					cout << "\t\t----------------------------------------------------";
					cout << "\n\t\tPress 1 to Edit your information";
					cout << "\n\t\tPress 2 to Display availble books";
					cout << "\n\t\tPress 3 to Search for a book";
					cout << "\n\t\tPress 4 to Order a book";
					cout << "\n\t\tPress 5 to See youraccount details";
					cout << "\n\t\tPress 6 to Exit and return to signup";
					cout << "\n\t\t----------------------------------------------------\n";
					cout << "\n\t\tOption: ";
					cin >> option;
					switch (option)
					{
					case 1:  system("cls");
						us->edit();
						break;
					case 2: system("cls");
						us->displayavbook();
						break;
					case 3: system("cls");
						us->displayabook();
						break;
					case 4:system("cls");
						us->order();
						break;
					case 5: system("cls");
						us->showdata();
						break;
					case 6:delete us;
						break;
					default:
						cout << "\a";
					}
					}
				}
			}
		}