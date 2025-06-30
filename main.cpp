#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int acc_no;
int sr_no;
int found_acc;
void update(int sr_no, int acc_no, string name1, string name2, string ph_no, string pin_code, float balance, char status, char del);

string available(int find_acc)
{
	string name, name1, name2, pin_code, ph_no;
	float balance;
	char status;
	int sr_no, acc_no;
	found_acc = -1;

	ifstream read("Bank Database.txt");
	while ((found_acc == -1) && (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found				{
	{
		if (acc_no == find_acc)
			found_acc = 0;
	}
	read.close();
	if (found_acc < 0) // if not found
		return "Invalid";
	else if (found_acc == 0)
	{
		name = name1 + " " + name2;
		cout << "XXX" << name << "XXXX" << endl;
	}
	return name;
}

void send(int from, int to, int amount)
{
	string name1, name2, oin_code, ph_no, pin_code;
	float balance;
	int sr_no, acc_no;
	char status;

	ifstream read("Bank Database.txt");																				  // from
	while ((acc_no != from) && (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found
	{
	}
	read.close();
	balance -= amount;
	update(sr_no, acc_no, name1, name2, ph_no, pin_code, balance, status, 'u');

	found_acc = -1;
	ifstream read2("Bank Database.txt");																			 // to
	while ((acc_no != to) && (read2 >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found
	{
	}
	read.close();
	balance += amount;
	update(sr_no, acc_no, name1, name2, ph_no, pin_code, balance, status, 'u');
}

void acc_info(int iska) // TO PRINT, give acc no
{
	string name1, name2, pin_code, ph_no;
	float balance;
	int acc_no, sr_no;
	char status;
	found_acc = -1;

	ifstream read("Bank Database.txt");
	while ((found_acc == -1) && (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found
	{
		if (acc_no == iska)
			found_acc = 0;
	}
	cout << "\nName: " << name1 << " " << name2 << endl;
	cout << "Account number: " << acc_no << endl;
	cout << "Balance: " << balance << "/-" << endl;
	cout << "Phone: +92" << ph_no << endl;
}

int last_acc() // gives last acc number
{

	string name1, name2, ph_no, pin_code;
	float balance;
	char status;
	ifstream read("Bank Database.txt");
	while (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)
	{
	}
	read.close();
	return acc_no;
}

int last_sr() // gives last serial number
{
	int sr_no = 0;
	string name1, name2, ph_no, pin_code;
	float balance;
	char status;

	ifstream read("Bank Database.txt");
	while (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)
	{
	}
	read.close();
	return sr_no;
}
void re_sr_no()
{
	int no_lines = 0;
	string line;
	string data[100];

	ifstream read("Bank Database.txt");
	while (getline(read, line))
	{
		no_lines++;
	}

	cout << "xxxx" << no_lines << "linesXXX" << endl;
	for (int i = 0; i < no_lines; i++)
	{
		getline(read, data[i]);
	}
	read.close();

	size_t pos;
	for (int i = 0; i < no_lines; i++)
	{
		pos = data[i].find('\t');
		if (pos != std::string::npos)
			data[i].erase(0, pos + 1);
	}

	ofstream write("Bank Database.txt");
	int new_sr = 1;

	for (int i = 0; i < no_lines; i++)
	{
		write << new_sr << "\t" << data[i] << endl;
		new_sr++;
	}
}
void new_entry(string name1, string name2, string ph_no, string pin_code, float balance)
{
	int sr_no = 0;
	sr_no = last_sr() + 1;
	acc_no = last_acc() + 107;
	if (acc_no == 107)
		acc_no = 100049;
	char status = 'A';

	ofstream new_entry("Bank Database.txt", ios::app);
	if (new_entry.fail())
		cout << "File failed to Open; at time of newentry" << endl;
	else
		new_entry << sr_no << "\t" << acc_no << "\t" << name1 << "\t" << name2 << "\t" << balance << "\t" << ph_no << "\t" << pin_code << "\t" << status << endl;
	new_entry.close();
}

void update(int sr_no, int acc_no, string name1, string name2, string ph_no, string pin_code, float balance, char status, char del) // we give it credentials of 1 line and it updates that line but keeps the rest
{
	vector<string> data;
	string line; // readsindividual line from file o write in vecor
	cout << "\nupdate ko mila data " << sr_no << "\t" << acc_no << "\t" << name1 << "\t" << name2 << "\t" << balance << "\t" << ph_no << "\t" << pin_code << "\t" << status << endl;

	ifstream read("Bank Database.txt");
	while (getline(read, line))
	{
		data.push_back(line);
	}
	read.close();
	ofstream update("Bank Database.txt");
	for (int i = 0; i < data.size(); i++) // writing back
	{
		if (i != sr_no - 1)
			update << data[i] << endl;
		else if (i == sr_no - 1 && del != 'd')
			update << sr_no << "\t" << acc_no << "\t" << name1 << "\t" << name2 << "\t" << balance << "\t" << ph_no << "\t" << pin_code << "\t" << status << endl;
	}
	// re_sr_no ();
}

void block(int to_block, char what)
{
	string name1, name2, ph_no, pin_code;
	float balance;
	int found_acc = -1;
	int sr_no, acc_no;
	char status;

	ifstream read("Bank Database.txt");
	if (read.fail())
		cout << "File failed to open; at time of block account " << endl;

	else
	{
		while ((found_acc == -1) && (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found
		{
			if (sr_no == to_block)
				found_acc = 0;
		}
		read.close();
	}
	status = what;
	update(sr_no, acc_no, name1, name2, ph_no, pin_code, balance, status, 'u'); // send back exact data just by blocked status, u is update no block
}

void pin_change(int to_change_at, string new_pin)
{
	string name1, name2, ph_no, pin_code;
	float balance;
	int found_acc = -1;
	int sr_no, acc_no;
	char status;

	ifstream read("Bank Database.txt");
	if (read.fail())
		cout << "File failed to open; at time of block account " << endl;

	else
	{
		while ((found_acc == -1) && (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found
		{
			if (sr_no == to_change_at)
				found_acc = 0;
		}
		read.close();
	}
	pin_code = new_pin;
	update(sr_no, acc_no, name1, name2, ph_no, pin_code, balance, status, 'u'); // send back exact data just by blocked status
	cout << "PIN changes Successfully" << endl;
}

int user_func(int to_serve) // give acc no
{
	char change = 'n';
	string name1, name2, ph_no, pin_code;
	int sr_no, acc_no;
	float balance;
	char status;

	int user_choice;
	float cashier;
	char again_service;
	string pin_test;
	string pin1, pin2;
	char pinin;

	found_acc = -1;
	ifstream read("Bank Database.txt");
	while ((found_acc == -1) && (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found
	{
		if (acc_no == to_serve)
			found_acc = 0;
	}
	cout << "Select from the Options below" << endl;
	cout << "  1. Withdraw Cash\n  2. Deposit Money\n  3. Transfer Funds\n  4. Change PIN\n  5. View Information\n  6. Delete Account" << endl;
	cout << "CHOOSE: ";
	cin >> user_choice;

	switch (user_choice)
	{
	case 1:
	{
		cout << "\n==== WITHDRAW CASH ====";
		do
		{
			cout << "\nEnter amount in rupees: ";
			cin >> cashier;
			if (cashier > balance)
			{
				change = 'n';
				cout << "\nInsufficient Balance!" << endl;
				cout << "You have a Balance of " << balance << "/- in your account" << endl;
				cout << "Try again? ";
				cin >> again_service;
			}
			else
			{
				again_service = 'n';
				balance -= cashier;
				change = 'y';
				update(sr_no, acc_no, name1, name2, ph_no, pin_code, balance, status, 'u');
				cout << "==== TRANSACTION SUCCESSFUL ====" << endl;
				cout << "New Balance is " << balance << "/-" << endl;
			}
		} while (again_service == 'y' || again_service == 'Y');

		break;
	}
	case 2:
	{
		cout << "\n==== CASH DEPOSIT ====";
		cout << "\nEnter amount in rupees: ";
		cin >> cashier;
		balance += cashier;
		change = 'y';
		update(sr_no, acc_no, name1, name2, ph_no, pin_code, balance, status, 'u');
		cout << "Successful Deposit" << endl;
		cout << "New Balance is " << balance << "/-" << endl;

		break;
	}
	case 3:
	{
		int to;
		cout << "\n==== TRANSFER MONEY ====";
		do
		{
			cout << "\nEnter receiver's Account Number: ";
			cin >> to;
			cout << "Account: " << available(to) << endl;
		} while (available(to) == "Invalid");

		cout << "Enter Money in Rupees: ";
		cin >> cashier;

		if (available(to) != "Invalid")
		{
			send(acc_no, to, cashier);
			cout << "==== SENT SUCCESSFLLY ====" << endl;
		}
		break;
	}

	case 4:
	{
		cout << "\n==== CHANGE PIN ====";
		do
		{
			again_service = 'n';
			cout << "\nEnter your current 4-digit PIN: ";
			cin >> pin_test;
			if (pin_code != pin_test)
			{
				cout << "Invalid PIN, try again" << endl;
			}
			else if (pin_code == pin_test)
			{
				do
				{
					cout << "Enter New 4-digit PIN: ";
					cin >> pin1;
					cout << "Enter New 4-digit PIN again: ";
					cin >> pin2;
					if ((pin1 == pin2) && pin1.length() == 4)
					{
						pin1 = pin_code;
						change = 'y';
						cout << "==== PIN CHANGED SUCCESSFULLY ====" << endl;
						pinin = 'y';
					}
					else
					{
						cout << "Try again!" << endl;
					}

				} while (pinin != 'y');
			}
		} while (pin_code != pin_test);

		break;
	}
	case 5:
	{
		cout << "\n==== VIEW INFORMATION" << endl;
		acc_info(acc_no);
		break;
	}
	case 6:
	{
		char confirm = 'n';
		cout << "\n==== DELETE ACCOUNT ====" << endl;

		cout << "Enter PIN for verification: ";
		cin >> pin_test;

		if (pin_test == pin_code)
		{
			cout << "Are you sure you want to delete your account?" << endl;
			acc_info(acc_no);
			cout << "\n!!! WARNING !!!\nTyping y will delete your account permanently. Your balance will be lost!" << endl;
			cout << "CONFIRM: ";
			cin >> confirm;
			if (confirm == 'Y' || confirm == 'y')
			{
				update(sr_no, acc_no, name1, name2, ph_no, pin_code, balance, status, 'd');
				cout << "==== DELETED SUCCESSFULLY ====" << endl;
			}
			else
				cout << "==== DELETION CANCELLED ====" << endl;
		}
		else
		{
			cout << "Wrong PIN" << endl;
			cout << "Your acount has been BLOCKED!" << endl;
			block(sr_no, 'B');
		}
		break;
	}
	} // switch
	return 0;
}

int main()
{
	int acc_no;
	string name1, name2, ph_no, pin_code;
	float balance = 0;
	char status;

	int choice;
	char loop_main;

	float deposit = 0;
	char deposit_ans;

	cout << "==== WELCOME ====\n  1. Current User\n  2. Open Account\n  3. Exit ";
	do
	{
		cout << "\nCHOOSE: ";
		cin >> choice;
		int pin_tries = 1;
		switch (choice)
		{
		case 1:
		{
			cout << "\n==== CURRENT USER ====" << endl;
			int find_acc;
			string find_pin;
			int found_acc = -1;
			int found_pin = -1;
			char again;
			do
			{
				cout << "\nEnter 6-digit account number: ";
				cin >> find_acc;

				ifstream read("Bank Database.txt");
				if (read.fail())
				{
					cout << "File failed to open; at time of reading account number" << endl;
					return 1;
				}
				else
				{

					while ((found_acc == -1) && (read >> sr_no >> acc_no >> name1 >> name2 >> balance >> ph_no >> pin_code >> status)) // reading from file until end or found
					{
						if (acc_no == find_acc)
							found_acc = 0;
					}
					read.close();
					if (found_acc < 0) // if not found
					{
						cout << "Account not registered!" << endl;
						cout << "Try again(Y/N)? ";
						cin >> again;
					}
					else // if found
					{
						cout << "Welcome " << acc_no << " " << name1 << " " << name2 << " " << balance << " +92" << ph_no << " " << pin_code << endl;
						again = 'n';
						char again_pin = 'y';
						if (status == 'A') // not blocked
						{
							do
							{
								cout << "\nEnter 4-digit PIN: ";
								cin >> find_pin;
								pin_tries++;
								if (find_pin == "FORGOT")
								{
									again_pin = 'n';
									string new_pin;
									cout << "Enter new 4-digit PIN: ";
									cin >> new_pin;
									pin_change(sr_no, new_pin);
								}
								else if (find_pin == pin_code) // big big
								{
									found_pin == 1;
									pin_tries = 5;
									again_pin = 'n';
									cout << "LOGIN SUCCESSFUL\n"
										 << endl;
									user_func(acc_no);
									return 0;
								}
								else
								{
									if (pin_tries <= 2 || (pin_tries > 2 && pin_tries < 5))
										cout << "Incorrect PIN!" << endl;
									if (pin_tries == 2)
										cout << "====CAUTION====\nAfter 4 wrong tries yout account will be Blocked!\nForgoten PIN? Type FORGOT" << endl;
									else if (pin_tries == 5)
									{
										cout << "Your acount has been BLOCKED!" << endl;
										block(sr_no, 'B');
										again == 'n';
										loop_main = 'n';
									}
								}										// else
							}											// do
							while (again_pin == 'y' && pin_tries <= 4); // pin input
						}												// if not blocked
						else											// is blocked
						{
							cout << "\nYour account is BLOCKED!\nContact administration for further information." << endl;
							again == 'n';
							loop_main = 'n';
						}						  // else; is blocked
					}							  // acc no yes found
				}								  // else of did not open at time of acc no, matlab did found
			}									  // asks acc no loop, iske andar pin
			while (again == 'y' || again == 'Y'); // acc no and uske ander pin while

			break;
		} // case1 current user
		case 2:
		{
			cout << "=== Open Account ====" << endl;
			cout << "\nEnter your First Name: ";
			cin >> name1;
			cout << "Enter Surname: ";
			cin >> name2;
			do
			{
				cout << "Enter your phone number: +92";
				cin >> ph_no;
				if (ph_no.length() != 10)
					cout << "Invalid Number" << endl;
			} while (ph_no.length() != 10);
			do
			{
				cout << "Set a 4-digit PIN code: ";
				cin >> pin_code;
			} while (pin_code.length() != 4); // to get 4digit pin
			cout << "Would you like to make a Deposit? ";
			cin >> deposit_ans;
			if (deposit_ans == 'Y' || deposit_ans == 'y')
			{
				cout << "Deposit in Rupees: ";
				cin >> deposit;
				balance = balance + deposit;
			}
			new_entry(name1, name2, ph_no, pin_code, balance);
			cout << "\n==== OPENED SUCCESSFULLY ====" << endl;
			cout << "Your account number is " << last_acc() << endl;
			break;
		}
		case 3:
		{
			cout << "\n==== EXIT ====" << endl;
			break;
		}
		case 0:
		default:
		{
			cout << "Invalid Input!" << endl;
			cout << "Try again? ";
			cin >> loop_main;
		}
		}						// swich
	} while (loop_main == 'y'); // first step input iske ander switch case

	cout << "\nThankYou for using our Bank" << endl;
	cout << "==== GOODBYE ====" << endl;

	return 0;
}
