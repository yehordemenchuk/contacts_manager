#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "contacts.h"
#include "contacts_manager.h"

void upload_contact(Contact &contact, ifstream &input_file) {
    string name, surname, phone_number;
    age age;

    input_file >> name;
    
    input_file >> surname;

    input_file >> phone_number;

    input_file >> age;

    contact.set_contact_info(name, surname, phone_number, age);
}

void upload_contacts(vector <Contact> &contacts) {
    ifstream input_file(contacts_manager::contacts_file_name);

    if (!input_file) {
        cout << "File couldn`t be open for reading" << endl;

        exit(EXIT_FAILURE);
    }

    while (input_file) {
        Contact contact;

        upload_contact(contact, input_file);

        insert_contact(contacts, contact);
    }
}

void save_contact(Contact &contact, ofstream &output_file) {
    output_file << contact.get_name() << ' ' << contact.get_surname() << ' ' << contact.get_phone_number() << ' ' << contact.get_age() << endl;
}

void save_contacts(vector <Contact> &contacts) {
    ofstream output_file(contacts_manager::contacts_file_name, ios::out | ios::trunc);

    if (!output_file) {
        cout << "File couldn`t be open for writing" << endl;

        exit(EXIT_FAILURE);
    }

    for (auto contact : contacts)
        save_contact(contact, output_file);
}

contacts_manager::commands get_command() {
    string command;

    cout << "Enter command (show, insert, search, update, exit): " << '\n';

    getline(cin, command);

    if (command == "show")
        return contacts_manager::SHOW_CONTACTS;

    else if (command == "insert")
        return contacts_manager::INSERT_CONTACT;

    else if (command == "search")
        return contacts_manager::SEARCH_CONTACT;
    
    else if (command == "update")
        return contacts_manager::UPDATE_CONTACT_DATE;
    
    else if (command == "exit")
        return contacts_manager::PROGRAM_EXIT;

    else 
        return contacts_manager::UNRECOGNIZED_COMMAND;
}

void execute_command(contacts_manager::commands command, vector <Contact> &contacts) {
    Contact new_contact;

    switch(command) {
        case contacts_manager::SHOW_CONTACTS:
            show_contacts(contacts);
            
            break;
        
        case contacts_manager::INSERT_CONTACT:
            new_contact = create_contact();

            insert_contact(contacts, new_contact);

            break;
        
        case contacts_manager::SEARCH_CONTACT:
            search_contact_by_name_surname(contacts);

            break;
        
        case contacts_manager::UPDATE_CONTACT_DATE:
            update_contact_name_surname(contacts);

            break;
        
        case contacts_manager::PROGRAM_EXIT:
            save_contacts(contacts);

            break;
        
        case contacts_manager::UNRECOGNIZED_COMMAND:
            cout << "Command wasn`t recognized. Enter valid command." << '\n';

            break;
    }
}

void manager() {
    vector <Contact> contacts_book;
    contacts_manager::commands command;

    upload_contacts(contacts_book);

    while (command != contacts_manager::PROGRAM_EXIT) {
        command = get_command();

        execute_command(command, contacts_book);
    }

    cout << "Good bye:)" << endl;
}