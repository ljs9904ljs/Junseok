/*
 *  preprocessor operator
 *  1) 문자열화 operator #
 *  2) charizing operator #@  <- 안됨. 왜 ?
 *  3) token-pasting operator ##
 */



#include <iostream>
#include <typeinfo>

using namespace std;
// #define makechar(x) #@x
#define paster( n ) printf_s( "token" #n " = %d", token##n )





int main() {


    int token9 = 123;
    paster(9);












    return 0;
}