#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct FullName { 
    string name, surname;
};
class Person {
public:
    Person(const string& first_name, const string& last_name, int year) {
        full_name[year] = { first_name, last_name };
        birth_of_year = year;
        for (auto& i : full_name) {
            if (i.first < year) full_name.erase(i.first);
        }
    }
    void ChangeFirstName(int year, const string & first_name) {
        for (auto& i : full_name) {
            if (year >= i.first) {
                if (full_name.count(year) == 0) full_name[year].surname = "";
                full_name[year].name = first_name; 
            }
            break;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        for (auto& i : full_name) {
            if (year >= i.first) {
                if (full_name.count(year) == 0) full_name[year].name = ""; 
                full_name[year].surname = last_name; 
            }
            break; 
        }
    }
    string GetFullName(int year) const {
        if (birth_of_year != 0 && year < birth_of_year) {
          return "No person";
          }
        else if (full_name.size() == 0) { 
            return "Incognito"; 
        }
        else {
            for (const auto& i : full_name) {
                if (year < i.first) return "Incognito"; 
                break;
            }
        }
        string second_name = "";
        string second_surname = "";
        for (const auto& i : full_name) { 
            if (i.first <= year && i.second.surname != "") second_surname = i.second.surname;
            if (i.first <= year && i.second.name != "") second_name = i.second.name; 
        }
        if (second_name == "") {
          return second_surname + " with unknown first name"; 
          }
        else if (second_surname == "") {
          return second_name + " with unknown last name"; 
          }
        else {
          return second_name + " " + second_surname;
          }
    }
    string GetFullNameWithHistory(int year) const {
        if (birth_of_year != 0 && year < birth_of_year) {
          return "No person";
          }
        else if (full_name.size() == 0) { 
            return "Incognito"; 
        }
        else {
            for (const auto& i : full_name) {
                if (year < i.first) {
                  return "Incognito"; 
                  }
                break; 
            }
        }
        string second_name = "";
        string second_surname = "";
        vector<string> secondname; 
        vector<string> firstname; 
        for (const auto& i : full_name) { 
            if (i.first <= year && i.second.surname != "") {
                if (i.second.surname != second_surname && second_surname != "") {
                    secondname.push_back(second_surname);
                }
                second_surname = i.second.surname;
            }
            if (i.first <= year && i.second.name != "") {
                if (i.second.name != second_name && second_name != "") {
                    firstname.push_back(second_name);
                }
                second_name = i.second.name;
            }
        }
        string secondname_string = "", firstname_string = "";
        if (secondname.size() > 0) { 
            secondname_string += " (" + secondname[secondname.size() - 1]; 
            if (secondname.size() > 1) {
                for (int i = secondname.size() - 1; i > 0; --i) {
                    secondname_string += ", " + secondname[i - 1]; 
                }
            }
            secondname_string += ")"; 
        }
        if (firstname.size() > 0) {
            firstname_string += " (" + firstname[firstname.size() - 1];
            if (firstname.size() >1) {
                for (int i = firstname.size() - 1; i > 0; --i) {
                    firstname_string += ", " + firstname[i - 1];
                }
            }
            firstname_string += ")";
        }
        if (second_name == "") {
          return second_surname + secondname_string + " with unknown first name";
          }
        else if (second_surname == "") {
          return second_name + firstname_string + " with unknown last name";
          }
        else { 
          return second_name + firstname_string + " " + second_surname + secondname_string;
          }
    }
private: 
    int birth_of_year;
    map<int, FullName> full_name; 
};
int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1960, "Appolinaria");
    person.ChangeLastName(1960, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

  return 0;
}