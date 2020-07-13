using namespace std;

struct wizard {
  string name;
  int id;
  string password;
  string position_title; 
  float beard_length;
};

struct spellbook {
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell *s;
};

struct spell {
  string name;
  float success_rate;
  string effect; 
};

wizard* sort_wizards(string wizard_file, int &login_accounts);
void login(wizard* wiz_table, int &login_accounts, int &attempts, int &student);
void menu();
spellbook* create_spellbooks(string spellbook_file, int &book_ammount);
void create_spells();
void get_spellbook_data(); 
void get_spell_data(); 
void delete_info(wizard *wiz_table, spellbook *spellbook_table, int book_ammount);//, spellbook **spellbook_table, spell ** spell_table);