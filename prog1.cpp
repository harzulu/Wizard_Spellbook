#include <iostream>
#include <fstream>
#include <string>
#include "./prog1.h"
 

using namespace std;

wizard* sort_wizards(string wizard_file, int &login_accounts)
{
	char c = 32;
	char n = 10;
	string temp_string;
	long int temp_int;
	float temp_float;

	ifstream wiz_file;
	wiz_file.open(wizard_file);

	if (!wiz_file.is_open())
	{
		cerr << "There was an problem opening your '"<< wizard_file << "' file. Please try again." << endl;
		exit(1);
	}
	else
	{
		wiz_file >> login_accounts;
	}

	wizard *wiz_table = new wizard[login_accounts];

	for (int i = 1; i <= login_accounts; i++)
	{
		getline(wiz_file, temp_string, c);
		wiz_table[i].name = temp_string;

		getline(wiz_file, temp_string, c);
		temp_int = stoi(temp_string);
		wiz_table[i].id = temp_int;

		getline(wiz_file, temp_string, c);
		wiz_table[i].password = temp_string;

		getline(wiz_file, temp_string, c);
		wiz_table[i].position_title = temp_string;

		getline(wiz_file, temp_string, n);
		temp_float = stoi(temp_string);
		wiz_table[i].beard_length = temp_float;

	}


	return wiz_table;

}

void login(wizard* wiz_table, int &login_accounts, int &attempts, int &student)
{
	long int id;
	string password;
	int account = 100;

	if (attempts == 3)
	{
		cout << "You have failed 3 attempts. Please try again later." << endl;
		exit(0);
	}
	else
	{
		cout << "Enter in your ID number: " << endl;
		cin >> id;

		for (int i = 1; i <= login_accounts; i++)
		{
			if (id == wiz_table[i].id)
			{
				account = i;
				i = login_accounts;
			}
			else
			{
				continue;
			}
		}

		cout << "Please enter your password: " << endl;
		cin >> password;

		if (wiz_table[account].password == password)
		{
			cout << "Welcome " << wiz_table[account].name << "!" << endl;
			cout << "ID number: " << wiz_table[account].id << endl;
			cout << "Role: " << wiz_table[account].position_title << endl;
			cout << "Beard length: " << wiz_table[account].beard_length << endl;
			if (wiz_table[account].position_title == "Student")
			{
				student = 1;
				return;
			}
			else
			{
				return;
			}
		}
		else
		{
			cout << "Incorrect login info, please try again:" << endl;
			attempts++;
			login(wiz_table, login_accounts, attempts, student);
		}
	}
}

void menu()
{
	int choice = 9;

	cout << "What would you like to do?" << endl;
	cout << "(1) Sort the spellbooks by number of pages." << endl;
	cout << "(2) Sort the spells by their types." << endl;
	cout << "(3) Sort the spells by their success rate." << endl;
	cout << "(4) Quit the program " << endl;
	cin >> choice;

	if (choice > 4) 
	{
		while (choice > 4)
		{
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			cout << "What would you like to do?" << endl;
			cout << "(1) Sort the spellbooks by number of pages." << endl;
			cout << "(2) Sort the spells by their types." << endl;
			cout << "(3) Sort the spells by their success rate." << endl;
			cout << "(4) Quit the program " << endl;
			cin >> choice;
		}
	}
	else
	{
		cout << "Your choice is " << choice << endl;
	}

	if (choice == 1)
	{
		cout << "Your choice is " << choice << endl;
		return;
	}

	else if (choice == 2)
	{
		cout << "Your choice is " << choice << endl;
		return;
	}

	else if (choice == 3)
	{
		cout << "Your choice is " << choice << endl;
		return;
	}

	else if (choice == 4)
	{
		cout << "Your choice is " << choice << endl;
		return;
	}

	else
	{
		cout << "fail" << endl;
		return;
	}
}

spellbook* create_spellbooks(string spellbook_file, int &book_ammount)
{
	char c = 32;
	char n = 10;
	string temp_string;
	long int temp_int;
	float temp_float;

	ifstream spell_file;
	spell_file.open(spellbook_file);

	if (!spell_file.is_open())
	{
		cerr << "There was an problem opening your '"<< spellbook_file << "' file. Please try again." << endl;
		exit(1);
	}
	else
	{
		spell_file >> book_ammount;
	}

	spellbook *spell_table = new spellbook[book_ammount];

	for (int i = 1; i <= book_ammount; i++)
	{
		getline(spell_file, temp_string, c);
		spell_table[i].title = temp_string;

		getline(spell_file, temp_string, c);
		spell_table[i].author = temp_string;

		getline(spell_file, temp_string, c);
		temp_int = stoi(temp_string);
		spell_table[i].num_pages = temp_int;

		getline(spell_file, temp_string, c);
		temp_int = stoi(temp_string);
		spell_table[i].edition = temp_int;

		getline(spell_file, temp_string, n);
		temp_int = stoi(temp_string);
		spell_table[i].num_spells = temp_int;

		for (int x = 0; x <= temp_int; x++)
		{
			getline(spell_file, temp_string, c);
			spell_table[i].s->name = temp_string;

			getline(spell_file, temp_string, c);
			temp_float = stoi(temp_string);
			spell_table[i].s->success_rate = temp_float;

			getline(spell_file, temp_string, c);
			spell_table[i].s->effect = temp_string;
		}

	}


	return spell_table;


}
void create_spells()
{
	
}
void get_spellbook_data()
{
	
}
void get_spell_data()
{
	
}
void delete_info(wizard *wiz_table, spellbook *spell_table, int book_ammount)
{
    delete[] wiz_table;
    wiz_table = NULL;


    delete[] spell_table;
    spell_table = NULL;
}

