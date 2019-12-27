/*
학번: 20180551
이름: 이준석
povis ID: ljs9904ljs

명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
*/

#pragma once

#include "member.h"

//메뉴 출력
int printMenu1();
void printMenu2(int num);
void printMenu3(int num);
void printMenu4(int num);
void printMenu5(int num);
void clearTokens(string * tokens);
void doTask();


// 메뉴 수행 
/*
 *11은 1.1번 메뉴를 의미하고 12는 1.2번 메뉴를 의미한다. 그런식으로 메뉴의 기능을 수행할 함수의 이름을 정하였다.
 */

/*Non Member*/
void nm11(nonMember &NM, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // 회원 가입
void nm12(nonMember &NM, Group &G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //로그인
//void nm13();

/*Member*/
void m21(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //로그아웃
void m22(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // 회원 탈퇴
void m23(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 제거
void m24(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 추가
void m25(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 목록 출력
void m26(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 진행
void m27(Group &G, nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //그룹 참가
void m28(group_votelist *grp_v, Group &G, nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //그룹 생성
//void m29();


//Group Member

void gm31(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);//로그아웃
void gm32(nonMember &NM, Group &G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //회원 탈퇴
void gm33(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);// 일반 투표 혹은 그룹 투표 제거
void gm34(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);//일반 투표 혹은 그룹 투표 추가
void gm35(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);//모든 투표(일반, 그룹) 목록 출력
void gm36(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 혹은 그룹 투표 진행
void gm37(nonMember &NM, Group &G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //그룹 탈퇴

//void gm38();

//Group Leader

void gl41(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //로그아웃
void gl42(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 혹은 그룹 투표 제거
void gl43(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 혹은 그룹 투표 추가
void gl44(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //모든 투표(일반, 그룹) 목록 출력
void gl45(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //일반 투표 혹은 그룹 투표 진행
void gl46(nonMember &NM, Group &G, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //그룹 내의 모든 멤버 출력
void gl47(nonMember &NM, Group &G, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //그룹 멤버 강퇴 하기

//void gl48();

void menu00(nonMember &NM, Group &G, votelist &memV, group_votelist *grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // 공통 메뉴, 모든 투표 정보와 모든 멤버 정보를 출력
