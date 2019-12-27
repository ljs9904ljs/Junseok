/*
�й�: 20180551
�̸�: ���ؼ�
povis ID: ljs9904ljs

������(Honor code)

������ �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.��
*/

#pragma once

#include "member.h"

//�޴� ���
int printMenu1();
void printMenu2(int num);
void printMenu3(int num);
void printMenu4(int num);
void printMenu5(int num);
void clearTokens(string * tokens);
void doTask();


// �޴� ���� 
/*
 *11�� 1.1�� �޴��� �ǹ��ϰ� 12�� 1.2�� �޴��� �ǹ��Ѵ�. �׷������� �޴��� ����� ������ �Լ��� �̸��� ���Ͽ���.
 */

/*Non Member*/
void nm11(nonMember &NM, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // ȸ�� ����
void nm12(nonMember &NM, Group &G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�α���
//void nm13();

/*Member*/
void m21(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�α׾ƿ�
void m22(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // ȸ�� Ż��
void m23(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ ����
void m24(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ �߰�
void m25(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ ��� ���
void m26(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ ����
void m27(Group &G, nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�׷� ����
void m28(group_votelist *grp_v, Group &G, nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�׷� ����
//void m29();


//Group Member

void gm31(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);//�α׾ƿ�
void gm32(nonMember &NM, Group &G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //ȸ�� Ż��
void gm33(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);// �Ϲ� ��ǥ Ȥ�� �׷� ��ǥ ����
void gm34(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);//�Ϲ� ��ǥ Ȥ�� �׷� ��ǥ �߰�
void gm35(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);//��� ��ǥ(�Ϲ�, �׷�) ��� ���
void gm36(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ Ȥ�� �׷� ��ǥ ����
void gm37(nonMember &NM, Group &G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�׷� Ż��

//void gm38();

//Group Leader

void gl41(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�α׾ƿ�
void gl42(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ Ȥ�� �׷� ��ǥ ����
void gl43(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ Ȥ�� �׷� ��ǥ �߰�
void gl44(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //��� ��ǥ(�Ϲ�, �׷�) ��� ���
void gl45(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�Ϲ� ��ǥ Ȥ�� �׷� ��ǥ ����
void gl46(nonMember &NM, Group &G, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�׷� ���� ��� ��� ���
void gl47(nonMember &NM, Group &G, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //�׷� ��� ���� �ϱ�

//void gl48();

void menu00(nonMember &NM, Group &G, votelist &memV, group_votelist *grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // ���� �޴�, ��� ��ǥ ������ ��� ��� ������ ���
