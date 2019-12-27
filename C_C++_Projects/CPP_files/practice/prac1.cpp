#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex() { real = 0.0; imag = 0.0; }
    Complex(double real_) {
        real = real_;
        imag = 0.0;
    }
    Complex(double real_, double imag_) {
        real = real_;
        imag = imag_;
    }
    Complex(Complex &src) {
        real = src.real;
        imag = src.imag;
    }
    Complex& operator+(Complex &op) {
        Complex res(real + op.real, imag + op.imag);
        return res;
    }
    Complex& operator-(Complex &op) {
        Complex res(real - op.real, imag - op.imag);
        return res;
    }
    void print() {
        printf("( %.2lf ) + ( %.2lfi )\n", real, imag);
    }
};




int main() {
    Complex op1(5, 7);
    op1.print();
    Complex op2(10, -9);
    op2.print();

    (op1+op2).print();
    //Complex op3 = op1 + (op2 + op1);
    //op3.print();
    int a = 10 + 20 + 30;
    cout << a << endl;
    return 0;

}