#include <iostream>


int GetBig(int& a, int& b)    // 함수 호출을 Rvalue 로 만들기 위해 int를 리턴
{
    return ( a > b ? a : b );
}

int main()
{
    int i = 10, j = 50;
    const int& big = GetBig( i, j );
    // 'big'를 GetBig()의 리턴값(Rvalue)에 대해 Lvalue로 바인딩한다.

    int& big2 = GetBig(i, j); // Error. big2 가 const가 아니므로
    // temporary 는 non-const reference 에 바인드 불가.

    return 0;
}