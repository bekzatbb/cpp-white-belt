#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

int Num(const int& x, const int& y) {
    if (y == 0)
        return x;
    return Num(y, x % y);
}

int NOD(const int& x, const int& y) {
    return x * y / Num(x, y);
}

class Rational {
public:
    Rational() {}
    Rational(int x, int y) {
        int nod = abs(Num(x, y));
        if (x < 0 && y < 0) {
            numerator = -x / nod;
            denominator = -y / nod;
        }
        else if (x >= 0 && y < 0) {
            numerator = -x / nod;
            denominator = -y / nod;
        }
        else {
            numerator = x / nod;
            denominator = y / nod;
        }
    }
    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }
    
private:
    int denominator = 1;
    int numerator = 0;
};

Rational operator + (const Rational& lhs, const Rational& rhs) {
    int nod = NOD(lhs.Denominator(), rhs.Denominator());
    if (lhs.Denominator() > nod) {
        int new_numerator = lhs.Denominator() / nod * lhs.Numerator() +
            rhs.Denominator() / nod * rhs.Numerator();
        return Rational(new_numerator, nod);
    }
    else {
        int new_numerator = nod / lhs.Denominator() * lhs.Numerator() +
            nod / rhs.Denominator() * rhs.Numerator();
        return Rational(new_numerator, nod);
    }
}
Rational operator - (const Rational& lhs, const Rational& rhs) {
    int nod = NOD(lhs.Denominator(), rhs.Denominator());
    if (lhs.Denominator() > nod) {
        int new_numerator = lhs.Denominator() / nod * lhs.Numerator() -
            rhs.Denominator() / nod * rhs.Numerator();
        return Rational(new_numerator, nod);
    }
    else {
        int new_numerator = nod / lhs.Denominator() * lhs.Numerator() -
            nod / rhs.Denominator() * rhs.Numerator();
        return Rational(new_numerator, nod);
    }
}
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator());
}
Rational operator / (const Rational& lhs, const Rational& rhs) {
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}
bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}
ostream& operator << (ostream& stream, const Rational& r) {
    return stream << r.Numerator() << '/' << r.Denominator();
}
istream& operator >> (istream& stream, Rational& r) {
    int x, y;
    char z;
    stream >> x >> z >> y;
    if (stream && z == '/') {
        r = Rational(x, y);
    }
    return stream;
}

int main() {
     {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }

    cout << "OK" << endl;
    return 0;
}