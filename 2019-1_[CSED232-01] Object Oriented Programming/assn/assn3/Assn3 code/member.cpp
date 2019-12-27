/*
학번: 20180551
이름: 이준석
povis ID: ljs9904ljs

명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
*/

#include "default.h"
//

int nonMember::isREGI(int idx)
{
	return person[idx].isRegi;
}

int nonMember::isLogin(int idx)
{
	return person[idx].isLogin;
}

void nonMember::change_iden(int idx, int iden)
{
	person[idx].identity = iden;
}

int nonMember::id_pw_check(string tID, string tPassword, int &idx)
{
	int i;
	int success = 0;
	for (i = 0; i < MAX_MEM; i++) {
		if (person[i].ID == tID && person[i].password == tPassword) { // SUCCESS
			success = 1;
			idx = i;
			break;
		}
	}
	return success;
}

int nonMember::whatIdentity(int idx)
{
	return person[idx].identity;
}

int nonMember::loginUserIdx()
{
	int idx = -1;
	int i;

	for (i = 0; i < MAX_MEM; i++) {
		if ((person[i].isLogin)) {
			idx = i;
			break;
		}
	}
	if (idx == -1) {
		cout << "No user is currently logged in." << endl;
		return -1;
	}
	else
		return idx;
}

void nonMember::do_register(int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i = 0;
	int idx;
	string tRRN, tID, tPassword;
	cout << "Selected Menu: 1.1 Register as a Member" << endl;


	if (!loadMode) {
		//RRN, ID, password를 입력받는다.
		cout << "RRN: "; fflush(stdout);
		cin >> tRRN;
		cout << "ID: "; fflush(stdout);
		cin >> tID;
		cout << "password: "; fflush(stdout);
		cin >> tPassword;

		
		if (totLogin == 1) { //로그인 되어 있는 경우에는 회원 가입 불가
			cout << "FAIL" << endl;
			inLogWrite << "1" << " " << "1" << " " << tRRN << " " << tID << " " << tPassword << " " << endl;
			return;
		}

		for (i = 0; i < MAX_MEM; i++) { // ID나 RRN 둘 중의 하나라도 겹치면 회원 가입 불가
			if (person[i].ID == tID || person[i].RRN == tRRN) { //
				cout << "FAIL" << endl;
				inLogWrite << "1" << " " << "1" << " " << tRRN << " " << tID << " " << tPassword << " " << endl;
				return;
			}
		}

		for (i = 0; i < MAX_MEM; i++) { //배열의 빈 칸을 찾는다.
			if (!(person[i].isRegi)) {
				idx = i;
				break;
			}
		}

		//valid case에 해당할 때, 배열의 빈 칸에 정보를 저장한다.
		person[idx].ID = tID;
		person[idx].isRegi = 1; // 등록됨을 표시
		person[idx].password = tPassword;
		person[idx].RRN = tRRN;
		person[idx].identity = 2; // 일반 멤버가 된다.
		cout << "SUCCESS" << endl;
		inLogWrite << "1" << " " << "1" << " " << tRRN << " " << tID << " " << tPassword << " " << endl;
		return;
	}
	else {
		tRRN = tokens[2]; tID = tokens[3]; tPassword = tokens[4];
		cout << "RRN: " << tRRN << endl; fflush(stdout);
		cout << "ID: " << tID << endl; fflush(stdout);
		cout << "password: " << tPassword << endl; fflush(stdout);

		if (totLogin == 1) {
			cout << "FAIL" << endl;
			return;
		}

		for (i = 0; i < MAX_MEM; i++) {
			if (person[i].ID == tID || person[i].RRN == tRRN) {
				cout << "FAIL" << endl;
				return;
			}
		}

		for (i = 0; i < MAX_MEM; i++) {
			if (!(person[i].isRegi)) {
				idx = i;
				break;
			}
		}

		//valid case에 해당할 때
		person[idx].ID = tID;
		person[idx].isRegi = 1; // 등록됨을 표시
		person[idx].password = tPassword;
		person[idx].RRN = tRRN;
		person[idx].identity = 2; // 일반 멤버가 된다.
		cout << "SUCCESS" << endl;
		return;

	}
}

void nonMember::do_login(int idx) 
{
	person[idx].isLogin = 1;
}

int Group::getIsGrp(int idx)
{
	return grp[idx].isGrp;
}

int Group::check1(string &_grpName) //그룹 이름을 입력받고 그룹 이름이 기존의 그룹 이름과 중복되는지 확인한다. 중복되지 않는다면 그 입력한 그룹 이름을 내보낸다.
{
	int i;
	string grpName;
	cin >> grpName;

	for (i = 0; i < MAX_GROUP; i++) {
		if (grp[i].groupName == grpName) {
			cout << "FAIL" << endl;
			return -1;
		}
	}
	_grpName = grpName;
	return 0;
}

int Group::toGrp(nonMember &NM, string grpName, int idx) //리더를 그룹에 추가한다. 그리고 리더가 추가된 그룹의 인덱스를 반환한다.
{
	int i;
	int _cur;
	int grpIDX = -1;

	for (i = 0; i < MAX_GROUP; i++) {
		if (grp[i].groupName == "") { //그룹 배열의 빈자리를 찾아서 그곳에 그룹 정보를 저장한다.
			_cur = grp[i].cur;

			grp[i].groupName = grpName; // 그룹 이름을 추가한다.

			grp[i].groupLeader = NM.getID(idx); // 그룹 리더 자리에 그 그룹을 만든 사람의 ID를 저장한다.

			//그룹 멤버로도 추가한다.
			grp[i].groupMems[_cur] = NM.getID(idx);
			grp[i].cur++;
			//그룹 존재를 표시한다.
			grp[i].isGrp = 1;
			grpIDX = i;
			break;

		}
	}
	return grpIDX;
}


void nonMember::do_logout(int menu, int& grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) // 2.1
{
	int i;

	if (!loadMode) {
		for (i = 0; i < MAX_MEM; i++) {
			person[i].isLogin = 0;
		}
		totLogin = 0;
		grade = 1;
		cout << "SUCCESS" << endl;
		if (menu == 2) {
			inLogWrite << "2" << " " << "1" << " " << endl;
		}
		else if (menu == 3) {
			inLogWrite << "3" << " " << "1" << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "1" << " " << endl;
		}
		return;
	}
	else {
		for (i = 0; i < MAX_MEM; i++) {
			person[i].isLogin = 0;
		}
		totLogin = 0;
		grade = 1;
		cout << "SUCCESS" << endl;
		return;
	}
}

int nonMember::do_unsub(int menu, int& grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) // 2.2
{
	int i = 0;
	string tID, tPassword;

	if (!loadMode) {
		cout << "ID: "; fflush(stdout);
		cin >> tID;
		cout << "password: "; fflush(stdout);
		cin >> tPassword;

		for (i = 0; i < MAX_MEM; i++) {
			if (person[i].ID == tID && person[i].password == tPassword && person[i].isLogin == 1) { // SUCCESS

				person[i].ID = "";
				person[i].isLogin = 0;
				person[i].isRegi = 0;
				person[i].password = "";
				person[i].RRN = "";

				cout << "SUCCESS" << endl;

				//회원 탈퇴 이후 로그아웃과 신분 강등.
				totLogin = 0;
				grade = 1;
				if (menu == 2) {
					inLogWrite << "2" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
				}
				else if (menu == 3) {
					inLogWrite << "3" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
				}
				else if (menu == 4) {
					inLogWrite << "4" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
				}
				return 0;
			}
		}

		cout << "FAIL" << endl;
		if (menu == 2) {
			inLogWrite << "2" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
		}
		else if (menu == 3) {
			inLogWrite << "3" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
		}
		return -1;
	}
	else {
		tID = tokens[2]; tPassword = tokens[3];
		cout << "ID: " << tID << endl; fflush(stdout);
		cout << "password: " << tPassword << endl; fflush(stdout);

		for (i = 0; i < MAX_MEM; i++) {
			if (person[i].ID == tID && person[i].password == tPassword && person[i].isLogin == 1) { // SUCCESS

				person[i].ID = "";
				person[i].isLogin = 0;
				person[i].isRegi = 0;
				person[i].password = "";
				person[i].RRN = "";

				cout << "SUCCESS" << endl;

				//회원 탈퇴 이후 로그아웃과 신분 강등.
				totLogin = 0;
				grade = 1;

				return 0;
			}
		}

		cout << "FAIL" << endl;
		return -1;
	}
}

void nonMember::do_delVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //2.3
{
	int i = 0;
	string tSubj;

	if (!loadMode) {

		cout << "Subject to Delete: "; fflush(stdout);
		cin >> tSubj;

		for (i = 0; i < MAX_VOTE; i++) {
			if (memV.getSubj(i) == tSubj) {
				memV.delV(tSubj);
				cout << "SUCCESS" << endl;
				if (menu == 2) {
					inLogWrite << "2" << " " << "3" << " " << "0" << " " << tSubj << " " << endl;
				}
				else if (menu == 3) {
					inLogWrite << "3" << " " << "3" << " " << "0" << " " << tSubj << " " << endl;
				}
				else if (menu == 4) {
					inLogWrite << "4" << " " << "2" << " " << "0" << " " << tSubj << " " << endl;
				}
				return;
			}
		}

		//FAIL
		cout << "FAIL" << endl;
		if (menu == 2) {
			inLogWrite << "2" << " " << "3" << " " << "0" << " " << tSubj << " " << endl;
		}
		else if (menu == 3) {
			inLogWrite << "3" << " " << "3" << " " << "0" << " " << tSubj << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "2" << " " << "0" << " " << tSubj << " " << endl;
		}
		return;
	}
	else {
		tSubj = tokens[3];
		cout << "Subject to Delete: " << tSubj << endl; fflush(stdout);

		for (i = 0; i < MAX_VOTE; i++) {
			if (memV.getSubj(i) == tSubj) {
				memV.delV(tSubj);
				cout << "SUCCESS" << endl;

				return;
			}
		}

		//FAIL
		cout << "FAIL" << endl;
		return;
	}
}

void nonMember::do_delVote(int menu, group_votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //
{
	int i = 0;
	string tSubj;
	if (!loadMode) {
		cout << "Subject to Delete: "; fflush(stdout);
		cin >> tSubj;

		for (i = 0; i < MAX_VOTE; i++) {
			if (grpV.getSubj(i) == tSubj) {
				grpV.delV(tSubj);
				cout << "SUCCESS" << endl;
				if (menu == 3) {
					inLogWrite << "3" << " " << "3" << " " << "1" << " " << tSubj << " " << endl;
				}
				else if (menu == 4) {
					inLogWrite << "4" << " " << "2" << " " << "1" << " " << tSubj << " " << endl;
				}

				return;
			}
		}

		//FAIL
		cout << "FAIL" << endl;
		if (menu == 3) {
			inLogWrite << "3" << " " << "3" << " " << "1" << " " << tSubj << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "2" << " " << "1" << " " << tSubj << " " << endl;
		}
		return;
	}
	else {
		tSubj = tokens[3];
		cout << "Subject to Delete: " << tSubj << endl; fflush(stdout);

		for (i = 0; i < MAX_VOTE; i++) {
			if (grpV.getSubj(i) == tSubj) {
				grpV.delV(tSubj);
				cout << "SUCCESS" << endl;

				return;
			}
		}

		//FAIL
		cout << "FAIL" << endl;

		return;
	}
}

void nonMember::do_addVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //2.4
{
	string tSubj;
	int itemNum;
	if (!loadMode) {
		cout << "Vote Subject: "; fflush(stdout);
		cin >> tSubj;
		cout << "Vote Item Number: "; fflush(stdout);
		cin >> itemNum;

		if (itemNum < 3 || itemNum >10) {
			cout << "FAIL" << endl;
			if (menu == 2) {
				inLogWrite << "2" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 3) {
				inLogWrite << "3" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "3" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}

			return;
		}

		//중복된 투표 주제인지 검사한다.
		if (!memV.duplTest(tSubj)) { //중복된 주제라면
			if (menu == 2) {
				inLogWrite << "2" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 3) {
				inLogWrite << "3" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "3" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			return; //종료
		}

		//valid case일 때
		memV.addV(tSubj, itemNum);
		if (menu == 2) {
			inLogWrite << "2" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
		}
		else if (menu == 3) {
			inLogWrite << "3" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "3" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
		}

	}
	else {
		tSubj = tokens[3]; itemNum = atoi(tokens[4].c_str());
		cout << "Vote Subject: " << tSubj << endl; fflush(stdout);
		cout << "Vote Item Number: " << itemNum << endl; fflush(stdout);

		if (itemNum < 3 || itemNum >10) {
			cout << "FAIL" << endl;
			return;
		}

		//중복된 투표 주제인지 검사한다.
		if (!memV.duplTest(tSubj)) { //중복된 주제라면
			return; //종료
		}

		//valid case일 때
		memV.addV(tSubj, itemNum);
	}
}

void nonMember::do_addVote(int menu, group_votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) {
	string tSubj;
	int itemNum;


	if (!loadMode) {
		cout << "Vote Subject: "; fflush(stdout);
		cin >> tSubj;
		cout << "Vote Item Number: "; fflush(stdout);
		cin >> itemNum;
		if (itemNum < 3 || itemNum >10) {
			cout << "FAIL" << endl;
			if (menu == 3) {
				inLogWrite << "3" << " " << "4" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "3" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
			}
			return;
		}

		//중복된 투표 주제인지 검사한다.
		if (!grpV.duplTest(tSubj)) { //중복된 주제라면
			if (menu == 3) {
				inLogWrite << "3" << " " << "4" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "3" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
			}
			return; //종료
		}

		//valid case일 때
		grpV.addV(tSubj, itemNum);
		if (menu == 3) {
			inLogWrite << "3" << " " << "4" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "3" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
		}
		cout << "SUCCESS" << endl;
		return;
	}
	else {
		tSubj = tokens[3]; itemNum = atoi(tokens[4].c_str());
		cout << "Vote Subject: " << tSubj << endl; fflush(stdout);
		cout << "Vote Item Number: " << itemNum << endl; fflush(stdout);

		if (itemNum < 3 || itemNum >10) {
			cout << "FAIL" << endl;
			return;
		}

		//중복된 투표 주제인지 검사한다.
		if (!grpV.duplTest(tSubj)) { //중복된 주제라면
			return; //종료
		}

		//valid case일 때
		grpV.addV(tSubj, itemNum);

		cout << "SUCCESS" << endl;
		return;
	}
}


void nonMember::do_listVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //2.5
{
	//투표 리스트 출력
	memV.listV();
	if (!loadMode) {
		if (menu == 2) {
			inLogWrite << "2" << " " << "5" << " " << endl;
		}
		else if (menu == 3) {
			inLogWrite << "3" << " " << "5" << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "4" << " " << endl;
		}
	}

}

void nonMember::do_listVote(int menu, group_votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //2.5
{
	//투표 리스트 출력
	grpV.listV();
	if (!loadMode) {
		if (menu == 3) {
			inLogWrite << "3" << " " << "5" << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "4" << " " << endl;
		}
	}
}

void nonMember::do_castVote(int menu, votelist& memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //2.6
{
	int i;
	int idx;
	int userIndex = -1;
	string tSubj;
	string tRRN;
	int target_item;
	int success = 0;
	int item_limit;

	if (!loadMode) {
		cout << "Vote Subject: "; fflush(stdout);
		cin >> tSubj;
		cout << "Vote for(Select 1 item): "; fflush(stdout);
		cin >> target_item;

		for (i = 0; i < MAX_VOTE; i++) {
			if (memV.getSubj(i) == tSubj) {
				success = 1;
				idx = i;
				break;
			}
		}
		if (!success) {
			cout << "FAIL" << endl;
			if (menu == 2) {
				inLogWrite << "2" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 3) {
				inLogWrite << "3" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "5" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			return;
		}

		userIndex = loginUserIdx(); //로그인한 유저의 인덱스를 받아온다.
		if (userIndex == -1) { //로그인한 유저가 없다.
			cout << "FAIL" << endl;
			if (menu == 2) {
				inLogWrite << "2" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 3) {
				inLogWrite << "3" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "5" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			return;
		}
		tRRN = person[userIndex].RRN;
		if (!memV.testVoteRRN(tRRN)) {
			cout << "FAIL" << endl;
			if (menu == 2) {
				inLogWrite << "2" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 3) {
				inLogWrite << "3" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "5" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			return;
		}

		//투표 항목 개수 제한을 확인한다.
		item_limit = memV.itemLimit(idx);
		if (item_limit < target_item || target_item <= 0) {
			cout << "FAIL" << endl;
			if (menu == 2) {
				inLogWrite << "2" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 3) {
				inLogWrite << "3" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "5" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
			}
			return;
		}
		memV.castV(tSubj, target_item, tRRN);
		cout << "SUCCESS" << endl;
		if (menu == 2) {
			inLogWrite << "2" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
		}
		else if (menu == 3) {
			inLogWrite << "3" << " " << "6" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "5" << " " << "0" << " " << tSubj << " " << target_item << " " << "0" << " " << endl;
		}
		return;
	}
	else {
		tSubj = tokens[3]; target_item = atoi(tokens[4].c_str());
		cout << "Vote Subject: " << tSubj << endl; fflush(stdout);
		cout << "Vote for(Select 1 item): " << target_item << endl; fflush(stdout);


		for (i = 0; i < MAX_VOTE; i++) {
			if (memV.getSubj(i) == tSubj) {
				success = 1;
				idx = i;
				break;
			}
		}
		if (!success) {
			cout << "FAIL" << endl;
			return;
		}

		userIndex = loginUserIdx(); //로그인한 유저의 인덱스를 받아온다.
		if (userIndex == -1) { //로그인한 유저가 없다.
			cout << "FAIL" << endl;
			return;
		}
		tRRN = person[userIndex].RRN;
		if (!memV.testVoteRRN(tRRN)) {
			cout << "FAIL" << endl;
			return;
		}

		//투표 항목 개수 제한을 확인한다.
		item_limit = memV.itemLimit(idx);
		if (item_limit < target_item || target_item <= 0) {
			cout << "FAIL" << endl;
			return;
		}
		memV.castV(tSubj, target_item, tRRN);
		cout << "SUCCESS" << endl;
		return;
	}
}

void nonMember::do_castVote(int menu, group_votelist& grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //2.6
{
	int i;
	int idx;
	int userIndex = -1;
	string tSubj;
	string tRRN;
	int target_item;
	int success = 0;
	int item_limit;

	cout << "Vote Subject: "; fflush(stdout);
	cin >> tSubj;
	cout << "Vote for(Select 1 item): "; fflush(stdout);
	cin >> target_item;

	for (i = 0; i < MAX_VOTE; i++) {
		if (grpV.getSubj(i) == tSubj) {
			success = 1;
			idx = i;
			break;
		}
	}
	if (!success) {
		cout << "FAIL" << endl;
		return;
	}

	userIndex = loginUserIdx(); //로그인한 유저의 인덱스를 받아온다.
	if (userIndex == -1) { //로그인한 유저가 없다.
		cout << "FAIL" << endl;
		return;
	}
	tRRN = person[userIndex].RRN;
	if (!grpV.testVoteRRN(tRRN)) {
		cout << "FAIL" << endl;
		return;
	}

	//투표 항목 개수 제한을 확인한다.
	item_limit = grpV.itemLimit(idx);
	if (item_limit < target_item) {
		cout << "FAIL" << endl;
		return;
	}
	grpV.castV(tSubj, target_item, tRRN);
	cout << "SUCCESS" << endl;
	return;
}

void nonMember::do_castVote2(int menu, votelist &grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int idx;
	int userIndex = -1;
	string tSubj;
	string tRRN;
	int target_item[2];
	int success = 0;
	int item_limit;

	if (!loadMode) {
		cout << "Vote Subject: "; fflush(stdout);
		cin >> tSubj;
		cout << "Vote for(Select 2 items): "; fflush(stdout);
		for (i = 0; i < 2; i++) {
			cin >> target_item[i];
		}
		for (i = 0; i < MAX_VOTE; i++) {
			if (grpV.getSubj(i) == tSubj) {
				success = 1;
				idx = i;
				break;
			}
		}
		if (!success) {
			cout << "FAIL" << endl;
			if (menu == 3) {
				inLogWrite << "3" << " " << "6" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "5" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
			}
			return;
		}

		userIndex = loginUserIdx(); //로그인한 유저의 인덱스를 받아온다.
		if (userIndex == -1) { //로그인한 유저가 없다.
			cout << "FAIL" << endl;
			if (menu == 3) {
				inLogWrite << "3" << " " << "6" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "5" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
			}
			return;
		}
		tRRN = person[userIndex].RRN;
		if (!grpV.testVoteRRN(tRRN)) {
			cout << "FAIL" << endl;
			if (menu == 3) {
				inLogWrite << "3" << " " << "6" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "5" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
			}
			return;
		}

		//투표 항목 개수 제한을 확인한다.
		item_limit = grpV.itemLimit(idx);
		for (i = 0; i < 2; i++) {
			if (item_limit < target_item[i]) {
				cout << "FAIL" << endl;
				if (menu == 3) {
					inLogWrite << "3" << " " << "6" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
				}
				else if (menu == 4) {
					inLogWrite << "4" << " " << "5" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
				}
				return;
			}
		}

		grpV.castV2(tSubj, target_item[0], target_item[1], tRRN);
		cout << "SUCCESS" << endl;
		if (menu == 3) {
			inLogWrite << "3" << " " << "6" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
		}
		else if (menu == 4) {
			inLogWrite << "4" << " " << "5" << " " << "1" << " " << tSubj << " " << target_item[0] << " " << target_item[1] << " " << endl;
		}

		return;
	}
	else {
		tSubj = tokens[3]; target_item[0] = atoi(tokens[4].c_str()); target_item[1] = atoi(tokens[5].c_str());
		cout << "Vote Subject: " << tSubj << endl; fflush(stdout);
		cout << "Vote for(Select 2 items): " << target_item[0] << " " << target_item[1] << endl; fflush(stdout);

		for (i = 0; i < MAX_VOTE; i++) {
			if (grpV.getSubj(i) == tSubj) {
				success = 1;
				idx = i;
				break;
			}
		}
		if (!success) {
			cout << "FAIL" << endl;
			return;
		}

		userIndex = loginUserIdx(); //로그인한 유저의 인덱스를 받아온다.
		if (userIndex == -1) { //로그인한 유저가 없다.
			cout << "FAIL" << endl;
			return;
		}
		tRRN = person[userIndex].RRN;
		if (!grpV.testVoteRRN(tRRN)) {
			cout << "FAIL" << endl;
			return;
		}

		//투표 항목 개수 제한을 확인한다.
		item_limit = grpV.itemLimit(idx);
		for (i = 0; i < 2; i++) {
			if (item_limit < target_item[i]) {
				cout << "FAIL" << endl;
				return;
			}
		}

		grpV.castV2(tSubj, target_item[0], target_item[1], tRRN);
		cout << "SUCCESS" << endl;

		return;
	}
}

//



void Group::grpPrint()
{
	int i;
	cout << "<Group List>" << endl;
	for (i = 0; i < MAX_GROUP; i++) {
		if (grp[i].isGrp) {
			cout << grp[i].groupName << ", "; fflush(stdout);
		}
	}
}

string Group::getGrpName(int idx)
{
	return grp[idx].groupName;
}

int Group::getGrpCur(int idx)
{
	return grp[idx].cur;
}

void Group::setGrpCur(int idx, int setValue)
{
	grp[idx].cur = setValue;
}

void Group::setGrpMem(int idx, string setID)
{
	int temp;
	temp = grp[idx].cur;
	grp[idx].groupMems[temp] = setID;
	grp[idx].cur++;
}

void Group::set_identity(int idx, int set)
{
	person[idx].identity = set;
}


string nonMember::getID(int idx)
{
	return person[idx].ID;
}

int nonMember::isTotLogin()
{
	return totLogin;
}

void Group::delID(string _ID)
{
	int i, j;

	for (i = 0; i < MAX_GROUP; i++) {
		for (j = 0; j < MAX_GROUP_MEM; j++) {
			if (grp[i].groupMems[j] == _ID) {
				grp[i].groupMems[j] = "";
			}
		}
	}
}

void Group::printGrpID(int idx)
{
	int i;
	for (i = 0; i < MAX_GROUP_MEM; i++) {
		if (i == MAX_GROUP_MEM - 1) {
			cout << grp[idx].groupMems[i] << endl;
			break;
		}
		cout << grp[idx].groupMems[i] << ", "; fflush(stdout);
	}
}

string Group::getLeaderID(int idx)
{
	return grp[idx].groupLeader;
}

string Group::getMemID(int idx, int idx2)
{
	return grp[idx].groupMems[idx2];
}

int nonMember::getIDXbyID(string _ID)
{
	int i, j;
	int tempIDX = -1;
	for (i = 0; i < MAX_MEM; i++) {
		if (person[i].ID == _ID) {
			tempIDX = i;
			break;
		}
	}
	return tempIDX;
}

string Group::grpNameByID(string _ID)
{
	int i, j;
	string tempName = "";
	for (i = 0; i < MAX_GROUP; i++) {
		for (j = 0; j < MAX_GROUP_MEM; j++) {
			if (grp[i].groupMems[j] == _ID) {
				tempName = grp[i].groupName;
				break;
			}
		}
	}
	if (tempName == "") {
		tempName = "None";
	}


	return tempName;

}

void Group::delMem(int idx, int idx2)
{
	grp[idx].groupMems[idx2] = "";
}