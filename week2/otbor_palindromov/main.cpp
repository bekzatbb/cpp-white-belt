#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool IsPalindrom(string i) { //функция определения палиндрома
    vector<char> r; //вспомогательный вектор сделаю
    for (auto ch : i) { //положу строку в вектор
        r.push_back(ch); //каждую букву в вектор
    }
    int leight = r.size(); //определю размер (сколько букав в строке)
    for (auto ch2 : r) { //теперь у меня есть возможность обращаться к символам строки по индексу
        if (ch2 != r[leight - 1]) return false; //сравниваю первый и последний и т.д. (второй и предпоследний)
        leight--; //"хороший" индекс - с последней буквы до первой дойдет, уменьшается
    }
    return true; //если предыдущий цикл прошел без "фальши", то возвращаем "тру" (значит строка - палиндром)
}
vector<string> PalindromFilter(vector<string> words, int minLength) { //фильтруем палиндромы
    vector<string> Output; //вектор для вывода
    for (auto i : words) { //перебираем все строки
        if (IsPalindrom(i) && i.size() >= minLength) { //если строка является палиндором и больше или равна нужной длинны, то...
            Output.push_back(i); //...записываем в вектор для вывода
        }
    }
    return Output; //возвращаем новый вектор
}
int main() //этого нет в задании, так для себя ))))
{
    vector<string> words = { "abacaba","aba" };
    int minLength = 5;
    int sh = 0;
    string a = "";
    for (string i : PalindromFilter(words, minLength)) {
        sh++;
        if (sh > 1) { a = ", "; }
        cout << a << i;
    }
    return 0;
}