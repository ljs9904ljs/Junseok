/*
학번: 20180551
이름: 이준석
povis ID: ljs9904ljs

명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
*/

#include "default.h"

//vote
// method


string votelist::getSubj(int idx)
{
	return vList[idx].votesubj;
}



int votelist::getIsVote(int idx)
{
	return vList[idx].isVote;
}


int votelist::duplTest(string subj) // 1리턴하면 중복아님, 0리턴하면 중복된 주제임.
{
	int i;
	int success = 1;
	for (i = 0; i < MAX_VOTE; i++) {
		if (vList[i].votesubj == subj && vList[i].isVote == 1) {
			cout << "This is a voting topic that already exists." << endl;
			success = 0;
			break;
		}
	}

	if (success) {
		cout << "SUCCESS" << endl;
	}
	return success;
}

int group_votelist::duplTest(string subj) // 1리턴하면 중복아님, 0리턴하면 중복된 주제임.
{
	int i;
	int success = 1;
	for (i = 0; i < MAX_GROUP_VOTE; i++) {
		if (vList[i].votesubj == subj && vList[i].isVote == 1) {
			cout << "This is a voting topic that already exists." << endl;
			success = 0;
			break;
		}
	}

	if (success) {
		cout << "SUCCESS" << endl;
	}
	return success;
}



void votelist::addVoteRRN(int idx, string _RRN)
{
	int temp;
	temp = vList[idx].cur;
	vList[idx].voteRRN[temp];
	vList[idx].cur = temp + 1;
}


int votelist::testVoteRRN(string _RRN) // 중복된 RRN이면 0 리턴, 중복 안 된 RRN이면 1 리턴.
{
	int i, j;
	int success = 1;
	for (i = 0; i < MAX_VOTE; i++) {
		for (j = 0; j < MAX_MEM; j++) {
			if (vList[i].voteRRN[j] == _RRN) {
				success = 0;
			}
		}
	}
	return success;
}



int votelist::itemLimit(int idx)
{
	return vList[idx].itemNum;
}



void votelist::printMemV()
{
	int i;
	int temp = 0;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) { //일반 투표 주제 출력
		if (vList[i].isVote) {
			cout << vList[i].votesubj << ", "; fflush(stdout);
			temp++;
		}
	}
	if (temp == 0) {
		cout << "None" << endl;
	}
	cout << endl;
}



void votelist::printGrpV()
{
	int i;
	int temp = 0;
	cout << "<Group Votes>" << endl;
	for (i = 0; i < MAX_GROUP_VOTE; i++) { //그룹 투표 주제 출력
		if (vList[i].isVote) {
			cout << vList[i].votesubj << ", "; fflush(stdout);
			temp++;
		}
	}
	if (temp == 0) {
		cout << "None" << endl;
	}
	cout << endl;
}


void votelist::addV(string subj, int item)
{
	int i;
	int idx;
	for (i = 0; i < MAX_VOTE; i++) {
		if (!(vList[i].isVote)) {
			idx = i;
			break;
		}
	}
	vList[idx].isVote = 1;
	vList[idx].votesubj = subj;
	vList[idx].itemNum = item;
}

void group_votelist::addV(string subj, int item)
{
	int i;
	int idx;
	for (i = 0; i < MAX_GROUP_VOTE; i++) {
		if (!(vList[i].isVote)) {
			idx = i;
			break;
		}
	}
	vList[idx].isVote = 1;
	vList[idx].votesubj = subj;
	vList[idx].itemNum = item;
}



void votelist::delV(string subj)
{
	int i;
	int idx;
	for (i = 0; i < MAX_VOTE; i++) {
		if (vList[i].votesubj == subj && vList[i].isVote == 1) {
			idx = i;
			break;
		}
	}
	vList[idx].isVote = 0;
	vList[idx].votesubj = "";

}


void votelist::listV()
{
	int i, j;
	int temp = 0;
	cout << "Vote Subject: "; fflush(stdout);
	for (i = 0; i < MAX_VOTE; i++) {
		if (vList[i].isVote) {
			cout << vList[i].votesubj; fflush(stdout);
			temp++;
			cout << ", Vote Counts per Item - "; fflush(stdout);
			for (j = 0; j < vList[i].itemNum; j++) {
				cout << vList[i].voteItem[j] << ": " << vList[i].voteItemNum[j] << " "; fflush(stdout);
			}
			cout << endl;
		}
	}
	if (temp == 0) {
		cout << "None" << endl;
	}

}


void votelist::castV(string subj, int item, string tRRN)
{
	int i;
	int temp;
	for (i = 0; i < MAX_VOTE; i++) {
		if (vList[i].votesubj == subj) {
			vList[i].voteItemNum[item - 1]++;
			temp = vList[i].cur;
			vList[i].voteRRN[temp] = tRRN;
			vList[i].cur++;
		}
	}
}


void votelist::castV2(string subj, int item, int item2, string tRRN)
{
	int i;
	int temp;
	for (i = 0; i < MAX_VOTE; i++) {
		if (vList[i].votesubj == subj) {
			vList[i].voteItemNum[item - 1]++;
			vList[i].voteItemNum[item2 - 1]++;

			temp = vList[i].cur;
			vList[i].voteRRN[temp] = tRRN;
			vList[i].cur++;
		}
	}
}

void group_votelist::printGrpVotesInfo()
{
	int i;
	int temp = 0;
	cout << groupName << ": "; fflush(stdout);
	for (i = 0; i < MAX_GROUP_VOTE; i++) {
		if (vList[i].isVote) {
			cout << vList[i].votesubj << ", "; fflush(stdout);
			temp++;
		}
	}
	if (temp == 0) {
		cout << "None"; fflush(stdout);
	}
	cout << endl;
}

string group_votelist::getGrpName()
{
	return groupName;
}

void group_votelist::setGrpName(string _name)
{
	groupName = _name;
}