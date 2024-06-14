#ifndef CONTACTS_MANAGER_H
#define CONTACTS_MANAGER_H

#include <fstream>
#include <vector>
#include <string>
#include "contacts.h"

using namespace std;

namespace contacts_manager {
    enum commands {
        SHOW_CONTACTS,
        INSERT_CONTACT,
        SEARCH_CONTACT,
        UPDATE_CONTACT_DATE,
        PROGRAM_EXIT,
        UNRECOGNIZED_COMMAND
    };

    const string contacts_file_name = "contacts.txt";
}

void upload_contact(Contact &contact, ifstream &input_file);

void upload_contacts(vector <Contact> &contacts);

void save_contact(Contact &contact, ofstream &output_file);

void save_contacts(vector <Contact> &contacts);

contacts_manager::commands get_command();

void execute_command(contacts_manager::commands command, vector <Contact> &contacts);

void manager();

#endif