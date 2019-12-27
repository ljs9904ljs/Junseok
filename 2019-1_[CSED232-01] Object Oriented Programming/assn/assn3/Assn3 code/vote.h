/*
�й�: 20180551
�̸�: ���ؼ�
povis ID: ljs9904ljs

������(Honor code)

������ �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.��
*/


#ifndef __VOTE_H__
#define __VOTE_H__
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

#define MAX_MEM 150
#define MAX_VOTE 150
#define MAX_ITEM 10
#define MAX_GROUP 10
#define MAX_GROUP_MEM 10
#define MAX_GROUP_VOTE 10
#define COMMAND_LOG_FILE_NAME "commandLog.txt"
#define OUTPUT_LOG_FILE_NAME "outputLog.txt"


typedef struct vote {
	string votesubj;
	string voteItem[MAX_ITEM] = { "item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10" }; // ��ǥ �׸�
	int itemNum; //��ǥ �׸� ��
	int voteItemNum[MAX_ITEM] = { 0, };
	int isVote = 0;

	//RRN ���
	string voteRRN[MAX_MEM];
	int cur = 0;
}VOTE;

class votelist { // �Ϲ� ��ǥ�� �����ϴ� Ŭ����
protected:
	VOTE vList[MAX_VOTE];

public:
	votelist() {}
	~votelist() {}
	string getSubj(int idx);
	int getIsVote(int idx);
	virtual int duplTest(string subj); //�ߺ� �˻�, ������ ��ǥ ��ϰ� �̸��� ��ġ���� Ȯ���Ѵ�.
	void addVoteRRN(int idx, string _RRN);
	int testVoteRRN(string _RRN);
	int itemLimit(int idx);
	void printMemV();
	void printGrpV();

	virtual void addV(string subj, int item);
	void delV(string subj);
	void listV();
	void castV(string subj, int item, string tRRN);
	void castV2(string subj, int item, int item2, string tRRN);
};

class group_votelist :public votelist { // �׷� ��ǥ�� �����ϴ� Ŭ����
protected:
	string groupName; //�׷��� �̸� ������ �����Ѵ�.
public:
	group_votelist() :votelist() {}
	void printGrpVotesInfo();
	string getGrpName();
	void addV(string subj, int item);
	int duplTest(string subj); //�ߺ� �˻�, ������ ��ǥ ��ϰ� �̸��� ��ġ���� Ȯ���Ѵ�.
	void setGrpName(string _name);
};


#endif