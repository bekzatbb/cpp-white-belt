#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    int N, num;
    vector<int> v; //тут храним введенные числа
    cin >> N; //узнаем количество чисел
    for (N; N > 0; --N) {
        cin >> num; //считываем числа
        v.push_back(num); //добавляем в вектор
    }
    //для сортировки используем изученную функцию sort
    //в качестве параметра сортировки будет лямбда-функция (третий аргумент)
    sort(begin(v), end(v), [](const int& x, const int& y) {
        //в уроках до этого не было рассказано о функции нахождения модуля...
        //а писать свою неохота было, поэтому просто спросил инет про модуль, выдал - abs()
        return abs(x) < abs(y); //сортировка будет от меньшего к большему (по модулю)
    });
    for (const auto& i : v) { 
        cout << i << " "; //выводим отсортированные числа
    }
    return 0;
}