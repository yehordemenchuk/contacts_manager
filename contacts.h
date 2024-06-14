#ifndef CONTACTS_H
#define CONTACTS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using age = short;

enum updating_data {
    NAME,
    SURNAME,
    PHONE_NUMBER,
    AGE,
    NO_DATA
};

class Contact {
    string m_name;
    string m_surname;
    string m_phone_number;
    age m_age;

public:
    void set_contact_info(string name, string surname, string phone_number, age age) {
        m_name = name;

        m_surname = surname;

        m_phone_number = phone_number;

        m_age = age;
    }

    string get_name() { return m_name; }

    string get_surname() { return m_surname; }

    string get_phone_number() { return m_phone_number; }

    age get_age() { return m_age; }

    void print_contact_info() {
        cout << "Name: " << m_name << '\n';

        cout << "Surname: " << m_surname << '\n';

        cout << "Phone number: " << m_phone_number << '\n';

        cout << "Age: " << m_age << endl;
    }
};

void show_contacts(vector <Contact> &contacts);

void insert_contact(vector <Contact> &contacts, Contact &new_contact);

void get_contact_name_surname(string &name, string &surname);

Contact* search_contact_by_name_surname(vector <Contact> &contacts);

updating_data data_to_update();

void update_data(updating_data data_to_update, Contact* p_updating_contact);

void update_contact_name_surname(vector <Contact> &contacts);

Contact create_contact();

#endif