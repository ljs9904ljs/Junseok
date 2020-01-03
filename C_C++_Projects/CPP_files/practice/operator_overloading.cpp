/* 
 * operator overloading
 * 
 *
 */


#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex() {real = 0.0; imag = 0.0; }
    Complex(double real_) {
        real = real_;
        imag = 0.0;
    }
    Complex(double real_, double imag_) {
        real = real_;
        imag = imag_;
    }
    Complex(Complex& src) {
        real = src.real;
        imag = src.imag;
    }
    void dump() {
        cout << real << "+" << imag << "i" << endl;
    }
    Complex operator+(const Complex &c) {
        Complex v(real + c.real, imag + c.imag);
        return v;
    }
};


void func(Complex c) {
    cout << "* start of func *" << endl;
    c.dump();
    cout << "* end of func *" << endl;
}


int main() {
    func({20.0,23.3}); // convert constructor , braced-init-list

    Complex c1,c2(5.3, 7.2);
    c1 = c2 + 5;
    c1.dump();

    






    return 0;
}
