#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype> //для transform
using namespace std;
string str_to_low(const string& s) { //перевод строки в нижний регистр
    string result;
    for (auto i : s) { //все буквы
        result += tolower(i); //вставляем в новую строку в нижнем регистре
    }
    return result; //возвращаем новую строку в нижнем регистре
}
bool srt(string x, string y) {
    //по хорошему использовать бы функцию transform
    //трансформирования строки и перевести все символы в нижний регистр
    /*transform(x.begin(), x.end(), x.begin(), tolower);
    transform(y.begin(), y.end(), y.begin(), tolower);
    return x < y;*/
    //но проверку не пройдет(не знаю почему), поэтому...
    return str_to_low(x) < str_to_low(y); //сортировка будет от меньшего к большему (без учета регистра)
}
int main() {
    int N;
    string str;
    vector<string> v; //тут храним введенные строки
    cin >> N; //узнаем количество строк
    for (N; N > 0; --N) {
        cin >> str; //считываем строки
        v.push_back(str); //добавляем в вектор
    }
    //для сортировки используем изученную функцию sort
    sort(begin(v), end(v), srt);
    for (const auto& i : v) {
        cout << i << " "; //выводим отсортированные строки
    }
    return 0;
}