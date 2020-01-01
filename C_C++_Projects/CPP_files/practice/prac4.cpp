/* 
 * operator overloading
 * 
 *
 */


#include <iostream>
#include <typeinfo>

#define makechar(x) #x
#define paster( n ) printf_s( "token" #n " = %d", token##n )

using namespace std;
/*
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
    Complex operator+(Complex& src) {
        Complex v(real + src.real, imag + src.imag );
        return v;
    }
};
*/

int main() {
    //Complex a, c1(13.2, 14.4);


    
    if(typeid(makechar(c)) == typeid(string)) {
        cout << "equal!" << endl;
    }
    else if(typeid(makechar(c)) == typeid(const char *)) {
        cout << "const char * equal!" << endl;
    }
    else {
        cout << "diff!" << endl;
    }

    cout << typeid(makechar(c)).name() << endl;






    return 0;
}
