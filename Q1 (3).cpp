#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Declaration of the dateType class
class dateType {
public:
    dateType(int m = 1, int d = 1, int y = 1900) {
        setDate(m, d, y);
    }

    void setDate(int m, int d, int y) {
        if (isValidDate(m, d, y)) {
            month = m;
            day = d;
            year = y;
        } else {
            cout << "Invalid date provided. Setting to default date: 01/01/1900.\n";
            month = 1;
            day = 1;
            year = 1900;
        }
    }

    void printDate() const {
        cout << month << "/" << day << "/" << year;
    }

    bool isLeapYear() const {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

private:
    int month, day, year;

    bool isValidDate(int m, int d, int y) {
        if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31) return false;
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
        if (m == 2) {
            return d <= (isLeapYear() ? 29 : 28);
        }
        return true;
    }
};

// Declaration of the addressType class
class addressType {
public:
    addressType(string str = "", string c = "", string st = "", string z = "")
        : streetAddress(str), city(c), state(st), zipCode(z) {}

    void printAddress() const {
        cout << streetAddress << ", " << city << ", " << state << " " << zipCode;
    }

private:
    string streetAddress;
    string city;
    string state;
    string zipCode;
};

// Declaration of the personType class
class personType {
public:
    void print() const {
        cout << firstName << " " << lastName;
    }

    void setName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    personType(string first = "", string last = "") : firstName(first), lastName(last) {}

private:
    string firstName;  // Variable to store the first name
    string lastName;   // Variable to store the last name
};

// Declaration of the extPersonType class
class extPersonType : public personType {
public:
    extPersonType(string first, string last, string phone, const addressType& adr, const dateType& dob, string rel)
        : personType(first, last), phoneNumber(phone), address(adr), birthday(dob), relationship(rel) {}

    void printPerson() const {
        print();
        cout << "\nPhone Number: " << phoneNumber
             << "\nAddress: ";
        address.printAddress();
        cout << "\nBirthday: ";
        birthday.printDate();
        cout << "\nRelationship: " << relationship << endl;
    }

private:
    string phoneNumber;
    addressType address;
    dateType birthday;
    string relationship;
};

// Declaration of the addressBookType class
class addressBookType {
public:
    void addPerson(const extPersonType& person) {
        if (entries.size() >= 500) {
            cout << "Address book full. Cannot add more entries.\n";
            return;
        }
        entries.push_back(person);
    }

    void printAddressBook() {
        for (auto& person : entries) {
            person.printPerson();
            cout << endl;
        }
    }

private:
    vector<extPersonType> entries;
};

// Main function to demonstrate the usage of classes
int main() {
    addressType johnsAddress("1234 Elm St", "Riverside", "CA", "92507");
    dateType johnsBirthday(10, 12, 1992);
    extPersonType johnDoe("John", "Doe", "951-123-4567", johnsAddress, johnsBirthday, "Friend");

    addressBookType myAddressBook;
    myAddressBook.addPerson(johnDoe);

    cout << "Address Book Entries:\n";
    myAddressBook.printAddressBook();

    return 0;
}
