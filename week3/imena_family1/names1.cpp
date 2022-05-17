#include <iostream>
#include <string>
#include <map>
using namespace std;
struct FullName { //создадим структуру из имени и фамилии
    string Name;
    string Soname;
};
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Soname = ""; //если такого года еще нет, то добавим пустую фамилию в этот год
        YearNameSoname[year].Name = first_name; //добавим указанное имя
    }
    void ChangeLastName(int year, const string& last_name) {
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Name = ""; //если такого года еще нет, то добавим пустое имя в этот год
        YearNameSoname[year].Soname = last_name; //и добавим указанную фамилию
    }
    string GetFullName(int year) {
        if (YearNameSoname.size() == 0) { //если размер = 0
            return "Incognito"; //выводим Инкогнито
        }
        else { //ну или так
            for (const auto& i : YearNameSoname) {
                if (year < i.first) return "Incognito"; //если искомый год меньше первого года изменения, выводим Инкогнито
                break; //сразу выходим из цикла
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname) { //полистаем нашу структуру, (не стал отдельно функцию делать)
            //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в структуре)
            if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
            //тоже самое с именем
            if (i.first <= year && i.second.Name != "") nm = i.second.Name;
        }
        if(nm == "") return sn + " with unknown first name"; //условие, если имя пустое(вывод фамилии и текста)
        else if(sn == "") return nm + " with unknown last name"; //условие, если фамилия пуста (вывод имени и текста)
        else return nm + " " + sn; //вывод имени и фамилии
    }
private: //объявим в приватной секции
    map<int, FullName> YearNameSoname; //структуру с годом и полным именем
};