/*
학번: 20180551
이름: 이준석
povis ID: ljs9904ljs

명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
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
	string voteItem[MAX_ITEM] = { "item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10" }; // 투표 항목
	int itemNum; //투표 항목 수
	int voteItemNum[MAX_ITEM] = { 0, };
	int isVote = 0;

	//RRN 기록
	string voteRRN[MAX_MEM];
	int cur = 0;
}VOTE;

class votelist { // 일반 투표를 관리하는 클래스
protected:
	VOTE vList[MAX_VOTE];

public:
	votelist() {}
	~votelist() {}
	string getSubj(int idx);
	int getIsVote(int idx);
	virtual int duplTest(string subj); //중복 검사, 기존의 투표 목록과 이름이 겹치는지 확인한다.
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

class group_votelist :public votelist { // 그룹 투표를 관리하는 클래스
protected:
	string groupName; //그룹의 이름 정보를 저장한다.
public:
	group_votelist() :votelist() {}
	void printGrpVotesInfo();
	string getGrpName();
	void addV(string subj, int item);
	int duplTest(string subj); //중복 검사, 기존의 투표 목록과 이름이 겹치는지 확인한다.
	void setGrpName(string _name);
};


#endif