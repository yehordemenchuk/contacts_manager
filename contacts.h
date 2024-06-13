#ifndef CONTACTS_H
#define CONTACTS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using age = short;
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

    void print_name() { cout << "Name: " << m_name << endl; }

    void print_surname() { cout << "Surname: " << m_surname << endl; }

    void print_phone_number() { cout << "Phone number: " << m_phone_number << endl; }

    void print_age() { cout << "Age: " << m_age << endl; }

    void print_contact_info() {
        print_name();

        print_surname();

        print_phone_number();

        print_age();
    }
};

#endif