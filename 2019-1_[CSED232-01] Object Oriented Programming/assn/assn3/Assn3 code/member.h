/*
�й�: 20180551
�̸�: ���ؼ�
povis ID: ljs9904ljs

������(Honor code)

������ �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.��
*/

#pragma once

#ifndef __MEMBER_H__
#define __MEMBER_H__
#include "vote.h"


typedef struct Info {
	string RRN = "";
	string ID = "";
	string password = "";
	int isLogin = 0;
	int isRegi = 0;
	int identity; // 1�� non���, 2�� �Ϲ� ���, 3�� �׷� ���, 4�� �׷� ����
}INFO;

class nonMember { //��ȸ��, ȸ�� ������ �����ϴ� Ŭ����
protected:
	INFO person[MAX_MEM];
	int totLogin;
public:
	nonMember() {
		totLogin = 0;
	}
	virtual int id_pw_check(string tID, string tPassword, int &idx);
	virtual int whatIdentity(int idx);
	void change_iden(int idx, int iden);
	int isLogin(int idx);
	int isTotLogin();
	string getID(int idx);
	void do_logout(int menu, int& grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
	int do_unsub(int menu, int& grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
	int getIDXbyID(string _ID);
	int isREGI(int idx);

	virtual int loginUserIdx(); // ���� �α��� ������ �ε����� �����Ѵ�.
	virtual void do_register(int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // 1-1
	virtual void do_login(int idx);

	//
	virtual void do_delVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //2.3
	void do_delVote(int menu, group_votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
	virtual void do_addVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //2.4
	void do_addVote(int menu, group_votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
	virtual void do_listVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //2.5
	void do_listVote(int menu, group_votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
	virtual void do_castVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); //2.6
	void do_castVote(int menu, group_votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
	virtual void do_castVote2(int menu, votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens); // �׷� ��ǥ

};

/*class Member : public nonMember {
protected:

public:
	int getIsGrp(int idx);
	int check1(string &_grpName);
	void toGrp(string grpName, int idx);
	void set_identity(int idx, int set);



};*/

typedef struct groupManage { 
	int isGrp = 0;

	
	string groupName = "";
	string groupMems[MAX_GROUP_MEM];
	string groupLeader;
	int cur = 0;
	
}GRP;

class Group : public nonMember { //�׷��� ������ �����ϴ� Ŭ����
protected:
	GRP grp[MAX_GROUP];
public:
	int check1(string &_grpName);
	int toGrp(nonMember & NM, string grpName, int idx);
	int getIsGrp(int idx);
	void printGrpID(int idx);
	string getLeaderID(int idx);
	string getMemID(int idx, int idx2);
	string grpNameByID(string _ID);

	void delMem(int idx, int idx2);
	void grpPrint();
	string getGrpName(int idx);
	int getGrpCur(int idx);
	void setGrpCur(int idx, int setValue);
	void setGrpMem(int idx, string setID);
	void set_identity(int idx, int set);
	void delID(string _ID);
};

#endif