#include <iostream>
#include <fstream>
#include <string>
#include "./prog1.h"


using namespace std;

int main(int argc, char** argv)
{
	int login_accounts;
	int book_ammount;
	int attempts = 0;
	int student = 0;

	string wizard_file = argv[1];
	string spellbook_file = argv[2];

	wizard* wiz_table = sort_wizards(wizard_file, login_accounts);

	login(wiz_table, login_accounts, attempts, student);

	spellbook* spellbk_table = create_spellbooks(spellbook_file, book_ammount);

	menu();

	delete_info(wiz_table, spellbk_table, book_ammount);


	//delete_info(wiz_table);//, spellbook_table, spell_table);

	return 0;
}
