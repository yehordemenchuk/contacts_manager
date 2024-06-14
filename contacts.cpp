#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstddef>
#include "contacts.h"

void show_contacts(vector <Contact> &contacts) {
    cout << "Contacts book" << '\n';

    for (auto contact : contacts) {
        contact.print_contact_info();

        cout << "***" << endl;
    }
}

void insert_contact(vector <Contact> &contacts, Contact &new_contact) {
    contacts.push_back(new_contact);
}

void make_empty_row() {
    cout << '\n';
}

void get_contact_name_surname(string &name, string &surname) {
    cout << "Enter contact name: " << '\n';
    getline(cin, name);

    cout << "Enter contact surname: " << '\n';
    getline(cin, surname);
}

Contact* search_contact_by_name_surname(vector <Contact> &contacts) {
    string name, surname;

    get_contact_name_surname(name, surname);

    make_empty_row();

    for (int i = 0, len = contacts.size(); i != len; ++i) {
        if (contacts[i].get_name() == name && contacts[i].get_surname() == surname) {
            cout << "Contact info" << '\n';

            contacts[i].print_contact_info();

            return &contacts[i];
        }
    }

    cout << "Contact with this name and surname doesn`t exist" << endl;

    return nullptr;
}

updating_data data_to_update() {
    string name_of_updating_data;

    cout << "Enter contact data to update: " << endl;

    getline(cin, name_of_updating_data);

    make_empty_row();

    if (name_of_updating_data == "name")
        return NAME;

    else if (name_of_updating_data == "surname")
        return SURNAME;

    else if (name_of_updating_data == "phonenumber")
        return PHONE_NUMBER;

    else if (name_of_updating_data == "age")
        return AGE;
    
    else
        return NO_DATA;
}

void update_data(updating_data data_to_update, Contact* p_updating_contact) {
    string updated_data;
    age updated_age;

    if (data_to_update == NO_DATA) {
        cout << "Incorrect data" << endl;

        return;
    }

    cout << "Enter new data: " << '\n';
    
    switch(data_to_update) {
        case NAME:
            getline(cin, updated_data);

            p_updating_contact->set_contact_info(updated_data, p_updating_contact->get_surname(), p_updating_contact->get_phone_number(), p_updating_contact->get_age());

            break;

        case SURNAME:
            getline(cin, updated_data);

            p_updating_contact->set_contact_info(p_updating_contact->get_name(), updated_data, p_updating_contact->get_phone_number(), p_updating_contact->get_age());

            break;

        case PHONE_NUMBER:
            getline(cin, updated_data);

            p_updating_contact->set_contact_info(p_updating_contact->get_name(), p_updating_contact->get_surname(), updated_data, p_updating_contact->get_age());

            break;
        
        case AGE:
            cin >> updated_age;
            
            p_updating_contact->set_contact_info(p_updating_contact->get_name(), p_updating_contact->get_surname(), p_updating_contact->get_phone_number(), updated_age);

            break;
    }
}

void update_contact_name_surname(vector <Contact> &contacts) {
    string new_name, new_surname, new_phone_number;
    age new_age;

    Contact* p_updating_contact = search_contact_by_name_surname(contacts);

    make_empty_row();

    if (p_updating_contact == nullptr) {
        return;
    }

    update_data(data_to_update(), p_updating_contact);
}

void cin_reset() {
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

Contact create_contact() {
    string name, surname, phone_number;
    age age;
    Contact contact;

    cout << "Enter data to create contact" << '\n';

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter surname: ";
    getline(cin, surname);

    cout << "Enter phonenumber: ";
    getline(cin, phone_number);

    cout << "Enter age: ";

    cin >> age;

    cin_reset();

    contact.set_contact_info(name, surname, phone_number, age);

    return contact;
}