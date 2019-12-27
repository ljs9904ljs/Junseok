#include <iostream>

using namespace std;

const char* fun() { return "Hellow"; }

int f2() { return 111; }

int main()
{
    const char* q = fun();
    //q[0]='h';    // 예외발생, fun() 이 임시 메모리를 리턴하는데 거기 접근하려 한다.
    cout << "q : " << q << endl;

    cout << "f2 : " << f2() << endl;
    
    int b = f2();
    
    string str = const_cast<char*>("my name is");
    char *p = new char[str.length()];
    p = const_cast<char*>(str.c_str());
    cout << p << endl;
    p[0] = 'A';
    cout << p << endl;

}   