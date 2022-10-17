#include <bits/stdc++.h>
#include <unistd.h>
#include <conio.h>

using namespace std;

int main();
stack<int> s;
map<int, queue<pair<int, string>>> mp;

class node
{
public:
	int ID;
	string proName;
	double prePrice;
	int quantity;
	int discount;
	node *next;

	node()
	{
		next = NULL;
		ID = 0;
		prePrice = 0.0;
		quantity = 0;
		discount = 0;
		proName = '\0';
	}
};
node *head = NULL;
node *tail = NULL;
class product
{
public:
	node *temp;

	product()
	{
		ifstream myfile;
		myfile.open("itemdetails.txt");

		int i, q, p;
		double d;
		string n;

		myfile >> i >> n >> p >> q >> d;
		while (!myfile.eof())
		{
			temp = new node;
			temp->ID = i;
			temp->proName = n;
			temp->prePrice = p;
			temp->quantity = q;
			temp->discount = d;

			if (head == NULL)
			{
				temp->next = head;
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
			myfile >> i >> n >> p >> q >> d;
		}
		myfile.close();
	}

	void additems();
	void showitems();
	void modify();
};
product pd;
void product ::additems()
{
	string name;
	int id, quant, dis;
	double price;
	temp = new node;
	system("cls");
	cout << "\n\n\n"
		 << endl;
	cout << "\t\t--------------------------------------------------------------------------------" << endl;
	cout << "\n"
		 << endl;

	cout << "\t\t\t\tEnter Product Id          : ";
	cin >> id;
	cout << "\t\t\t\tEnter Name of Product     : ";
	cin >> name;
	cout << "\t\t\t\tEnter Price of Prduct     : ";
	cin >> price;
	cout << "\t\t\t\tEnter Quantity of Product : ";
	cin >> quant;
	cout << "\t\t\t\tEnter Discount on Product : ";
	cin >> dis;
	cout << "\n"
		 << endl;

	cout << "\t\t---------------------------------------------------------------------------------" << endl;

	ofstream myfile;
	myfile.open("itemdetails.txt", ios ::app);
	temp->ID = id;
	temp->proName = name;
	temp->prePrice = price;
	temp->quantity = quant;
	temp->discount = dis;

	myfile << id << "\t\t" << name << "\t\t" << price << "\t\t" << quant << "\t\t" << dis << endl;
	myfile.close();
	if (head == NULL)
	{
		temp->next = head;
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void product ::showitems()
{
	if (head == NULL)
	{
		cout << "Sorry no items to show. Please try later." << endl;
		return;
	}
	node *tem = head;
	cout << "\n"
		 << endl;
	cout << "ID"
		 << "\t\t"
		 << "Name "
		 << "\t\t"
		 << "Price"
		 << "\t"
		 << "     Quantity"
		 << "\t"
		 << "    Discount" << endl;
	while (tem != NULL)
	{
		cout << tem->ID << "\t\t" << tem->proName << "\t\t" << tem->prePrice << "\t\t" << tem->quantity << "\t\t" << tem->discount << endl;
		tem = tem->next;
	}
}

void product ::modify()
{
	system("cls");
	showitems();

	string name;
	int id, quant, dis;
	double price;
	cout << "\n\n\n"
		 << endl;
	cout << "\t\t--------------------------------------------------------------------------------" << endl;
	cout << "\n"
		 << endl;

	cout << "\t\t\t\tEnter product id which you want to modify : ";
	int pid;
	cin >> pid;

	string newname;
	int newid, newquant, newdis;
	double newprice;

	cout << "\t\t\t\tEnter new id(if any)           :";
	cin >> newid;
	cout << "\t\t\t\tEnter Product new name(if any) :";
	cin >> newname;
	cout << "\t\t\t\tEnter new price(if any)        :";
	cin >> newprice;
	cout << "\t\t\t\tEnter new quantity(if any)     :";
	cin >> newquant;
	cout << "\t\t\t\tEnter new discount rate(if any):";
	cin >> newdis;

	cout << "\n"
		 << endl;
	cout << "\t\t---------------------------------------------------------------------------------" << endl;
	sleep(3);

	node *tem = head;
	while (tem != NULL)
	{
		if (tem->ID == pid)
		{
			tem->ID = newid;
			tem->proName = newname;
			tem->prePrice = newprice;
			tem->quantity = newquant;
			tem->discount = newdis;
			break;
		}
		else
			tem = tem->next;
	}

	ifstream fin;
	fin.open("itemdetails.txt");
	ofstream fout;
	fout.open("newitemdetails.txt");

	fin >> id >> name >> price >> quant >> dis;
	while (!fin.eof())
	{
		if (id != pid)
		{
			fout << id << "\t\t" << name << "\t\t" << price << "\t\t " << quant << "\t\t" << dis << endl;
		}
		else
		{
			fout << newid << "\t\t" << newname << "\t\t" << newprice << "\t\t" << newquant << "\t\t" << newdis << endl;
		}
		fin >> id >> name >> price >> quant >> dis;
	}

	fin.close();
	fout.close();

	remove("itemdetails.txt");
	rename("newitemdetails.txt", "itemdetails.txt");

	showitems();
}

class date
{
public:
	int day, mon, year;
};

void addemployee()
{
	date dob;
	date jd;

	string name;
	int eid;

	int ms;
	int leave;

	cout << "\n\n\n"
		 << endl;
	cout << "\t\t--------------------------------------------------------------------------------" << endl;
	cout << "\n"
		 << endl;

	cout << "\t\t\t\tEnter Empolyee id                       :";
	cin >> eid;

	cout << "\t\t\t\tEnter Empolyee name                     : ";
	cin >> name;

	cout << "\t\t\t\tEnter Date of Birth of Employee         : ";
	cin >> dob.day >> dob.mon >> dob.year;

	cout << "\t\t\t\tEnter joining date of Empolyee          : ";
	cin >> jd.day >> jd.mon >> jd.year;

	cout << "\t\t\t\tEnter total number of leaves of employee: ";
	cin >> leave;

	cout << "\t\t\t\tEnter Employee monthly salary           : ";
	cin >> ms;
	cout << "\n"
		 << endl;

	cout << "\t\t---------------------------------------------------------------------------------" << endl;

	ofstream myfile;
	myfile.open("employeedetails.txt", ios ::app);

	myfile << eid << "\t\t" << name << "\t\t" << dob.day << "/" << dob.mon << "/" << dob.year << "\t\t" << jd.day << "/" << jd.mon << "/" << jd.year << "\t\t" << leave << "\t\t" << ms << endl;
	myfile.close();
}

void showemployee()
{
	string jd, dob;
	string name;
	int id;
	int ms;
	int leave;

	ifstream myfile;
	myfile.open("employeedetails.txt");
	myfile >> id >> name >> dob >> jd >> leave >> ms;

	if (myfile.eof())
	{
		cout << "There is no employee to show. Pls click on 4 to add employee" << endl;
		myfile.close();
		return;
	}

	while (!myfile.eof())
	{
		cout << id << "\t\t" << name << "\t\t" << dob << "\t\t" << jd << "\t\t" << leave << "\t\t" << ms << endl;
		myfile >> id >> name >> dob >> jd >> leave >> ms;
	}

	myfile.close();
}

void modifyemployee()
{
	system("cls");
	showemployee();
	cout << "\n\n"
		 << endl;
	cout << "\t\t\t\tEnter Customer id whose details you want to modify :";
	int eid;
	cin >> eid;

	string jd, dob;
	string name;
	int id;
	int ms;
	int leave;

	date njd, ndob;
	string newname;
	int nid;
	int nms;
	int nleave;

	cout << "\n\n\n"
		 << endl;
	cout << "\t\t--------------------------------------------------------------------------------" << endl;
	cout << "\n"
		 << endl;

	cout << "\t\t\t\tEnter new id(if any)                    :";
	cin >> nid;

	cout << "\t\t\t\tEnter new name(if any)                  :";
	cin >> newname;

	cout << "\t\t\t\tEnter date of birth(if any)             :";
	cin >> ndob.day >> ndob.mon >> ndob.year;

	cout << "\t\t\t\tEnter joining date(if any)              :";
	cin >> njd.day >> njd.mon >> njd.year;

	cout << "\t\t\t\tEnter new total number of leaves(if any):";
	cin >> nleave;

	cout << "\t\t\t\tEnter new monthly salary(if any)        :";
	cin >> nms;
	cout << "\n"
		 << endl;

	cout << "\t\t---------------------------------------------------------------------------------" << endl;

	ifstream fin("employeedetails.txt");
	ofstream fout("newemployeedetails.txt", ios::app);

	fin >> id >> name >> dob >> jd >> leave >> ms;
	while (!fin.eof())
	{
		if (id != eid)
		{
			fout << id << "\t\t" << name << "\t\t" << dob << "\t\t" << jd << "\t\t" << leave << "\t\t" << ms << endl;
		}
		else
		{
			fout << nid << "\t\t" << newname << "\t\t" << ndob.day << "/" << ndob.mon << "/" << ndob.year << "\t\t" << njd.day << "/" << njd.mon << "/" << njd.year << "\t\t" << nleave << "\t\t" << nms << endl;
		}

		fin >> id >> name >> dob >> jd >> leave >> ms;
	}

	fin.close();
	fout.close();

	remove("employeedetails.txt");
	rename("newemployeedetails.txt", "employeedetails.txt");
}

void generatesalary()
{
	string jd, dob;
	string name;
	int id;
	int ms;
	int leave;
	cout << "Please Enter Customer ID:-";
	int eid;
	cin >> eid;
	int flag = 0;

	ifstream myfile("employeedetails.txt");
	myfile >> id >> name >> dob >> jd >> leave >> ms;

	while (!myfile.eof())
	{
		if (id == eid)
		{
			cout << "Employee Name: " << name << endl
				 << endl;
			cout << "Employee ID: " << id << endl
				 << endl;
			cout << "Employee monthly salary is: " << ms << endl
				 << endl;
			cout << "Total number of leaves of employee: " << leave << endl
				 << endl;
			cout << "Employee total salary generated is " << ms - (leave * 500) << endl;
			myfile.close();
			flag = 1;
			return;
		}
		myfile >> id >> name >> dob >> jd >> leave >> ms;
	}
	myfile.close();
	if (flag == 0)
	{
		cout << "No such employee with this id exist" << endl;
	}
}
bool is_Logged_In()
{
	string username, password, ur_name, ps_word;
	cout << "\t\t\t\t\t    Enter Username: ";
	cin >> username;
	cout << "\t\t\t\t\t    Enter password: ";
	cin >> password;

	ifstream myFile;
	myFile.open("data12\\" + username + ".txt");
	getline(myFile, ur_name);
	getline(myFile, ps_word);

	if (ur_name == username && ps_word == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void admin()
{

a:
	system("cls");
	system("color 02");
	cout << "\n\n"
		 << endl;
	cout << "\t\t\t\t--------------------Welcome to our Shop----------------------\n"
		 << endl;

	cout << "\t\t\t\t\t[1]. Enter to add product" << endl;
	cout << "\t\t\t\t\t[2]. Enter to view products" << endl;
	cout << "\t\t\t\t\t[3]. Enter to modify details of products" << endl;
	cout << "\t\t\t\t\t[4]. Enter to add Employee" << endl;
	cout << "\t\t\t\t\t[5]. Enter to show Employee Details" << endl;
	cout << "\t\t\t\t\t[6]. Enter to modify Employee Details" << endl;
	cout << "\t\t\t\t\t[7]. Enter to generate employee salary" << endl;
	cout << "\t\t\t\t\t[8]. Enter to exit" << endl;
	cout << "\n\t\t\t\t--------------------------------------------------------------" << endl;

	int choice;
	cout << "\t\t\t\t\tEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		pd.additems();
		system("cls");
		break;
	}

	case 2:
	{
		system("cls");
		pd.showitems();
		break;
	}

	case 3:
	{
		system("cls");
		pd.modify();

		break;
	}

	case 4:
	{
		addemployee();
		system("cls");
		break;
	}

	case 5:
	{
		system("cls");
		showemployee();
		break;
	}

	case 6:
	{
		system("cls");
		modifyemployee();
		break;
	}

	case 7:
	{
		system("cls");
		generatesalary();
		break;
	}
	default:
	{
		system("cls");
		main();
	}
	}
	cout << endl
		 << "\t\t-------------------Enter any key to go back------------" << endl;
	getch();
	goto a;
}

void customer()
{
	cout << "Your trolley number is:- " << s.top() << endl;
	cout << "Enter your name:-";
	string name;
	cin >> name;
	int c = s.top() % 5;
	if (c == 1)
	{
		cout << "\t Please go to the counter number 1 after shopping" << endl;
		mp[1].push(make_pair(s.top() / 5, name));
	}

	else if (c == 2)
	{
		cout << "\t Please go to the counter number 2 after shopping" << endl;
		mp[2].push(make_pair(s.top() / 5, name));
	}

	else if (c == 3)
	{
		cout << "\t Please go to the counter number 3 after shopping" << endl;
		mp[3].push(make_pair(s.top() / 5, name));
	}

	else if (c == 4)
	{
		cout << "\t Please go to the counter number 4 after shopping" << endl;
		mp[4].push(make_pair(s.top() / 5, name));
	}

	else
	{
		cout << "\t Please go to the counter number 5 after shopping" << endl;
		mp[5].push(make_pair(s.top() / 5, name));
	}

	s.pop();
}
void displayqueue(int c, map<int, queue<pair<int, string>>> m)
{
	if (m[c].size() == 0)
		cout << "Your queue is empty" << endl;
	while (m[c].size() != 0)
	{
		cout << m[c].front().second << endl;
		m[c].pop();
	}

	return;
}
void employee()
{

	int counter;
	cout << "Enter your counter number:-";
	cin >> counter;

	displayqueue(counter, mp);

	if (mp[counter].size() == 0)
	{
		cout << "Your queue is empty" << endl;
		return;
	}

	// to empty queue and generate bill of each customer
	while (mp[counter].size() != 0)
	{

		cout << "Hello " << mp[counter].front().second << endl;
		pd.showitems();
		cout << "Pls tell how many items you have bought:- ";
		int numitem;
		cin >> numitem;
		double total_amount = 0.00;

		while (numitem--)
		{
			ifstream fin("itemdetails.txt");
			ofstream fout("newitemdetails.txt");

			cout << "Enter product id:-__";
			int pid;
			cin >> pid;
			cout << "Enter quantity of that item:-";
			int quant;
			cin >> quant;

			node *tem = head;
			while (tem != NULL)
			{
				if (tem->ID == pid)
				{
					total_amount += quant * (tem->prePrice - ((tem->prePrice) * (double)(tem->discount) / 100));
					tem->quantity -= quant;
					break;
				}
				tem = tem->next;
			}
			string name;
			int id, quanty, dis;
			double price;

			fin >> id >> name >> price >> quanty >> dis;
			while (!fin.eof())
			{
				if (id != pid)
				{
					fout << id << "\t\t" << name << "\t\t" << price << "\t\t" << quanty << "\t\t" << dis << endl;
				}
				else
				{
					fout << id << "\t\t" << name << "\t\t" << price << "\t\t" << quanty - quant << "\t\t" << dis << endl;
				}
				fin >> id >> name >> price >> quanty >> dis;
			}

			fin.close();
			fout.close();

			remove("itemdetails.txt");
			rename("newitemdetails.txt", "itemdetails.txt");
		}
		cout << mp[counter].front().second << "  your total bill amount after discount is:-  " << total_amount << endl;
		cout << "----------------Thanks for Shopping------------------"
			 << "\n\n";
		int tn = mp[counter].front().first;
		s.push((5 * tn) + counter);
		mp[counter].pop();
	}
}
int main()
{
	for (int i = 100; i > 0; i--)
		s.push(i);
b:
	cout << "\n\n"
		 << endl;
	system("color 02");
	cout << "============================================ WELCOME TO MY KIRANA STORE ===========================================" << endl;
	cout << "\t                                  ....a place to buy your grocery....                                          \n\n"
		 << endl;
	cout << "\t\t\t\t\t[1]. Admin Portal\n"
		 << endl;
	cout << "\t\t\t\t\t[2]. Customer Portal\n"
		 << endl;
	cout << "\t\t\t\t\t[3]. Employee\n"
		 << endl;
	cout << "\t\t\t\t\t[4]. Exit\n"
		 << endl;
	cout << "====================================================================================================================\n\n"
		 << endl;

	cout << "\t\t\t\t\tEnter your choice: ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("cls");
		int option;
		system("color 03");

		cout << "\n\n\n"
			 << endl;
		cout << "\t\t--------------------------------------------------------------------------------" << endl;
		cout << "\n"
			 << endl;

		cout << "\t\t************************\t\t\t\t************************" << endl;
		cout << "\t\t*                      *\t\t\t\t*                      *" << endl;
		cout << "\t\t*   1.REGISTER NOW     *\t\t\t\t*        2.LOGIN       *" << endl;
		cout << "\t\t*                      *\t\t\t\t*                      *" << endl;
		cout << "\t\t************************\t\t\t\t************************" << endl;
		cout << "\n"
			 << endl;

		cout << "\t\t---------------------------------------------------------------------------------" << endl;

		cout << "\n\t\t\t\t\tPlease Enter Your Choice: ";
		cin >> option;

		if (option == 1)
		{
			string username, password;

			cout << "\t\t\t\t\tSelect a Username: ";
			cin >> username;
			cout << "\t\t\t\t\tSelect a password: ";
			cin >> password;

			cout << "\n\t\t\tCongratulation!.... you are being successfully registered" << endl;
			cout << "\n\t\t\t\t\t";
			system("PAUSE");

			ofstream MyFile;
			MyFile.open("data12\\" + username + ".txt");
			MyFile << username << endl
				   << password;
			MyFile.close();
			system("CLS");
			main();
		}
		else if (option == 2)
		{
			bool status = is_Logged_In();

			if (!status)
			{
				cout << "Incorrect Username Or password!" << endl;
				system("PAUSE");
				return 0;
			}
			else
			{
				cout << "\n\t\t\t\t\tSuccesfully Logged In........" << endl;
				cout << "\t\t\t\t\t";
				system("PAUSE");
				system("CLS");
			}
		}

		admin();
		break;

	case 2:
		system("cls");
		customer();
		break;

	case 3:
		system("cls");
		employee();
		break;

	default:
		system("cls");
		cout << "\n\n\t\tProgram terminated successfully..." << endl;
		exit(1);
	}
	goto b;
	return 0;
}
