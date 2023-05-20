#include <iostream>

using namespace std;

class Complex {
private:
    double i, j;
public:
    Complex(int = 0, int = 0);

    void display();

    Complex &operator++();

    Complex operator++(int);

    bool operator<(const Complex &c);

    friend ostream &operator<<(ostream &output, Complex &C);
};

Complex::Complex(int a, int b) {
    i = a;
    j = b;
}

void Complex::display() {
    cout << i << " + " << j << endl;
}

Complex &Complex::operator++() {
    ++i;
    ++j;
    return *this;
}

Complex Complex::operator++(int) {
    Complex tmp = *this;
    ++i;
    ++j;
    return tmp;
}

bool Complex::operator<(const Complex &c) {
    if (i < c.i)
        return true;
    if (i == c.i && j < c.j)
        return true;

    return false;
}

ostream &operator<<(ostream &output, Complex &C) {
    output << "i: " << C.i << " j: " << C.j;
    return output;
}


int main() {
    Complex complex(1, 2), complex1, complex2(1, 3);
    complex.display();
//    ++(++complex);
//    complex.display();

//    cout << endl;
//
//    cout << (complex < complex1) << endl;
//    cout << (complex < complex2) << endl;

    cout << complex << endl;
}





