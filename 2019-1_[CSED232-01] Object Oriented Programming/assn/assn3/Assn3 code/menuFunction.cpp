/*
학번: 20180551
이름: 이준석
povis ID: ljs9904ljs

명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
*/

#include "default.h"
// 일반 함수

void set_iden(nonMember &NM, int idx, int iden)
{
	NM.change_iden(idx, iden);
}

int getIDXbyGroupName(Group &G, group_votelist *grpV, string _grpName)
{
	int i;
	int idx = -1;
	for (i = 0; i < MAX_GROUP_VOTE; i++) {
		if (grpV[i].getGrpName() == _grpName) {
			idx = i;
			break;
		}
	}
	return idx;
}

//menu function

/*Non Member*/
void nm11(nonMember &NM, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	NM.do_register(loadMode, inLogRead, inLogWrite, tokens, nTokens); // 1.1번 메뉴를 수행할 메소드
}
void nm12(nonMember & NM, Group & G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i = 0;
	int idx = -1;
	int right = 0;
	string tID, tPassword;
	int isLogin = 0;

	cout << "Selected Menu: 1.2 Login" << endl;

	if (!loadMode) {//로드모드가 아니면

		cout << "ID: "; fflush(stdout);
		cin >> tID;
		cout << "password: "; fflush(stdout);
		cin >> tPassword;

		isLogin = NM.isTotLogin();
		if (isLogin) { // 로그인이 이미 되어 있다면
			cout << "FAIL" << endl; // 로그인 불가능(실패)
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}

		right = NM.id_pw_check(tID, tPassword, idx); // 등록되어 있는 ID와 password인지 확인한다.
		if (!right) { //등록되어 있지 않다면
			cout << "FAIL" << endl; // 로그인 실패
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}
		if (NM.whatIdentity(idx) == 4) { //그룹 리더가 로그인할 때
			grade = 4;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}
		else if (NM.whatIdentity(idx) == 3) { //그룹 멤버가 로그인할 때
			grade = 3;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}
		else if (NM.whatIdentity(idx) == 2) { //일반 멤버가 로그인할 때
			grade = 2;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}
	}
	else {
		tID = tokens[2]; tPassword = tokens[3];
		cout << "ID: " << tID << endl; fflush(stdout);
		cout << "password: " << tPassword << endl; fflush(stdout);

		isLogin = NM.isTotLogin();
		if (isLogin) {
			cout << "FAIL: You are already logged in." << endl;

			return;
		}

		right = NM.id_pw_check(tID, tPassword, idx);
		if (!right) {
			cout << "FAIL" << endl;

			return;
		}
		if (NM.whatIdentity(idx) == 4) {
			grade = 4;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;

			return;
		}
		else if (NM.whatIdentity(idx) == 3) {
			grade = 3;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;

			return;
		}
		else if (NM.whatIdentity(idx) == 2) {
			grade = 2;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;

			return;
		}

	}
}
//void nm13();

/*Member*/
void m21(nonMember &NM, int& grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 2.1 Logout" << endl;

	NM.do_logout(2, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); //로그아웃을 수행한다.
}
void m22(nonMember &NM, int&grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 2.2 Unsubscribe form System" << endl;
	NM.do_unsub(2, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); //회원탈퇴를 수행한다.
}
void m23(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	cout << "Selected Menu 2.3 Delete Existing Vote" << endl;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) {
		if (mem_v.getIsVote(i)) //투표 주제가 존재하는 배열의 칸일 때
			cout << mem_v.getSubj(i) << ", "; fflush(stdout); //투표 주제를 출력한다
	}
	cout << endl;

	NM.do_delVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // 투표 주제를 지운다
}
void m24(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int temp = 0;
	cout << "Selected Menu 2.4 Add a Vote Item" << endl;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) {
		if (mem_v.getIsVote(i) == 1) { // 배열의 칸 안에 투표 주제가 존재할 때
			temp++;
			cout << mem_v.getSubj(i) << ", "; fflush(stdout); // 투표 주제를 출력한다.
		}
	}
	cout << endl;

	if (temp == 0) {
		cout << "None" << endl; // 투표 주제가 하나도 없을 때
	}

	NM.do_addVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // 투표 주제를 추가한다.
}
void m25(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 2.5 List All Vote Items." << endl;
	cout << "<General Vote>" << endl;
	NM.do_listVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // 투표 주제 및 현황을 출력한다. 일반 투표만 출력한다.
}
void m26(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	cout << "Selected Menu: 2.6 Cast a vote" << endl;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) { // 투표 주제를 출력한다.
		cout << mem_v.getSubj(i) << " "; fflush(stdout);
	}
	cout << endl;

	NM.do_castVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // 일반 투표를 진행한다.
}
void m27(Group &G, nonMember &NM, int&grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	string grpName;
	int idx;
	int temp;
	string tID;

	cout << "Selected Menu: 2.7 Join Group" << endl;
	G.grpPrint();
	cout << endl;

	if (!loadMode) {
		cout << "Group Name to Join: "; fflush(stdout);
		cin >> grpName;

		idx = NM.loginUserIdx(); //로그인한 유저의 인덱스를 받아온다.

		if (idx == -1) { //로그인한 유저가 없다.
			cout << "FAIL: No user is logged in." << endl;
			inLogWrite << "2" << " " << "7" << " " << grpName << " " << endl;
			return;
		}
		tID = NM.getID(idx);

		for (i = 0; i < MAX_GROUP; i++) {
			if (G.getGrpName(i) == grpName) { // 입력한 그룹 명과 일치하는 그룹을 찾는다.
				temp = G.getGrpCur(i);
				NM.change_iden(idx, 3); // 그룹 멤버가 되었음을 의미한다.

				//그룹의 멤버로서 추가한다.
				G.setGrpMem(i, tID);

				//SUCCESS
				grade = 3;
				cout << "SUCCESS" << endl;
				inLogWrite << "2" << " " << "7" << " " << grpName << " " << endl;
				return;
			}
		}

		//FAIL, 입력한 그룹 명의 그룹이 존재하지 않는다.
		cout << "FAIL: The group with the name you entered does not exist." << endl;
		inLogWrite << "2" << " " << "7" << " " << grpName << " " << endl;
		return;
	}
	else {
		grpName = tokens[2];
		cout << "Group Name to Join: " << grpName << endl; fflush(stdout);

		idx = NM.loginUserIdx(); //로그인한 유저의 인덱스를 받아온다.

		if (idx == -1) { //로그인한 유저가 없다.
			cout << "FAIL: No user is logged in." << endl;
			return;
		}
		tID = NM.getID(idx);

		for (i = 0; i < MAX_GROUP; i++) {
			if (G.getGrpName(i) == grpName) { // 입력한 그룹 명과 일치하는 그룹을 찾는다.
				temp = G.getGrpCur(i);
				NM.change_iden(idx, 3); // 그룹 멤버가 되었음을 의미한다.

				//그룹의 멤버로서 추가한다.
				G.setGrpMem(i, tID);

				//SUCCESS
				grade = 3;
				cout << "SUCCESS" << endl;
				return;
			}
		}

		//FAIL, 입력한 그룹 명의 그룹이 존재하지 않는다.
		cout << "FAIL: The group with the name you entered does not exist." << endl;
		return;
	}

}
void m28(group_votelist *grpV, Group &G, nonMember &NM, int& grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int noUse = 0;
	string grpName;
	int idx;
	int grpIDX;

	int success = 0;
	cout << "Selected Menu: 2.8 Create a Group" << endl;
	G.grpPrint();
	cout << endl;

	if (!loadMode) {
		cout << "Group Name to Create: "; fflush(stdout);
		noUse = G.check1(grpName); //그룹 이름을 입력받고 그룹 이름이 기존의 그룹 이름과 중복되는지 확인한다. 중복되지 않는다면 그 입력한 그룹 이름을 내보낸다.

		if (noUse == -1) {
			inLogWrite << "2" << " " << "8" << " " << grpName << " " << endl;
			return;
		}

		for (i = 0; i < MAX_MEM; i++) {
			if (NM.isLogin(i) == 1) {
				idx = i;
				success = 1;
				break;
			}
		}
		if (!success) { // 로그인한 사용자가 없으면 당연히 실패
			cout << "FAIL: No user is logged in." << endl;
			inLogWrite << "2" << " " << "8" << " " << grpName << " " << endl;
			return;
		}
		grpIDX = G.toGrp(NM, grpName, idx); //리더를 그룹에 추가한다. 그리고 리더가 추가된 그룹의 인덱스를 반환하고 받는다.
		grpV[grpIDX].setGrpName(grpName); // 그룹 이름을 추가한다.
		//SUCCESS
		G.set_identity(idx, 4); // 그룹 리더가 된다.
		NM.change_iden(idx, 4); // 그룹 리더 저장
		cout << "SUCCESS" << endl;
		inLogWrite << "2" << " " << "8" << " " << grpName << " " << endl;
		grade = 4;
		return;
	}
	else {
		grpName = tokens[2];
		cout << "Group Name to Create: " << grpName << endl; fflush(stdout);

		for (i = 0; i < MAX_GROUP; i++) {
			if (G.getGrpName(i) == grpName) {
				cout << "FAIL: It is a group name that already exists." << endl;
				noUse = -1;
				break;
			}
		}

		if (noUse == -1) {
			return;
		}

		for (i = 0; i < MAX_MEM; i++) {
			if (NM.isLogin(i) == 1) {
				idx = i;
				success = 1;
				break;
			}
		}
		if (!success) {
			cout << "FAIL: No user is logged in." << endl;
			return;
		}
		grpIDX = G.toGrp(NM, grpName, idx);
		grpV[grpIDX].setGrpName(grpName);
		//SUCCESS
		G.set_identity(idx, 4); // 그룹 리더가 된다.
		NM.change_iden(idx, 4); // 그룹 리더 저장
		cout << "SUCCESS" << endl;

		grade = 4;
		return;
	}

}


//void m29();

void gm31(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 3.1 Logout" << endl;
	NM.do_logout(3, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); // 로그 아웃 한다.
}

void gm32(nonMember &NM, Group& G, int&grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int userIDX;
	userIDX = NM.loginUserIdx(); // 현재 사용자의 인덱스를 받아온다.
	string userID;
	userID = NM.getID(userIDX); //  현재 사용자의 인덱스를 바탕으로 현재 사용자의 아이디를 받아온다.
	string groupID;
	int i, j;
	int check = 0;
	int success;

	cout << "Selected Menu: 3.2 Unsubscribe form System" << endl;
	success = NM.do_unsub(3, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); // 회원 탈퇴를 진행하고 성공적으로 진행되면 0을 리턴한다.

	if (success == 0) { // 회원 탈퇴가 성공적이라면
		//그룹에서 그 탈퇴한 멤버와 관련된 정보를 지운다.
		for (i = 0; i < MAX_GROUP; i++) {
			for (j = 0; j < MAX_GROUP_MEM; j++) {
				groupID = G.getMemID(i, j);
				if (groupID == userID) {
					G.delMem(i, j);
					check = 1;
					break;
				}
			}
			if (check == 1) {
				break;
			}
		}
	}
}

void gm33(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int selectType;

	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	//화면 출력
	cout << "Selected Menu 3.3 Delete Existing Vote" << endl;
	mem_v.printMemV(); // 일반 투표 목록 출력
	grp_v[groupIDX].printGrpV(); // 그룹 투표 목록 출력

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//메뉴 기능 수행
		cin >> selectType;

		//selectType에 따라 일반 투표를 지울지 그룹 투표를 지울지 결정하고 그에 관해 투표 지우기를 수행한다.
		if (selectType == 0) {
			NM.do_delVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_delVote(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
	else {
		selectType = atoi(tokens[2].c_str());
		cout << "Select Vote Type(0: general, 1: group): " << selectType << endl; fflush(stdout);

		//selectType에 따라 일반 투표를 지울지 그룹 투표를 지울지 결정하고 그에 관해 투표 지우기를 수행한다.
		if (selectType == 0) {
			NM.do_delVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_delVote(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}

	}

}

void gm34(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int selectType;
	int temp = 0;
	int temp2 = 0;

	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);


	cout << "Selected Menu 3.4 Add a Vote Item" << endl;
	cout << "<General Votes>" << endl; //일반 투표 목록 출력
	for (i = 0; i < MAX_VOTE; i++) {
		if (mem_v.getIsVote(i) == 1) {
			temp++;
			cout << mem_v.getSubj(i) << ", "; fflush(stdout);
		}
	}
	cout << endl;
	if (temp == 0) {
		cout << "None" << endl;
	}
	cout << "<Group Votes>" << endl; // 그룹 투표 목록 출력
	for (i = 0; i < MAX_VOTE; i++) {
		if (grp_v[groupIDX].getIsVote(i) == 1) {
			temp2++;
			cout << grp_v[groupIDX].getSubj(i) << ", "; fflush(stdout);
		}
	}
	cout << endl;
	if (temp2 == 0) {
		cout << "None" << endl;
	}


	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//메뉴 기능 수행
		cin >> selectType;

		//selectType에 따라 투표를 추가한다.
		if (selectType == 0) {
			NM.do_addVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_addVote(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
	else {
		selectType = atoi(tokens[2].c_str());
		cout << "Select Vote Type(0: general, 1: group): " << selectType << endl; fflush(stdout);
		//메뉴 기능 수행

		//selectType에 따라 투표를 추가한다.
		if (selectType == 0) {
			NM.do_addVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_addVote(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}

	}
}

void gm35(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	//투표 목록을 출력한다. 일반 투표와 그룹 투표를 모두 출력한다.
	if (!loadMode) {
		cout << "Selected Menu: 3.5 List All Vote Items." << endl;
		cout << "<General Vote>" << endl;
		NM.do_listVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		cout << "<Group Vote>" << endl;
		NM.do_listVote(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
	}
	else {
		cout << "Selected Menu: 3.5 List All Vote Items." << endl;
		cout << "<General Vote>" << endl;
		NM.do_listVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		cout << "<Group Vote>" << endl;
		NM.do_listVote(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
	}
}

void gm36(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int selectType;
	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	cout << "Selected Menu: 3.6 Cast a vote" << endl;
	mem_v.printMemV();
	grp_v[groupIDX].printGrpV();

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//메뉴 기능 수행
		cin >> selectType;

		//selectType에 따라 일반 투표 하기와 그룹 투표 하기로 나누어져서 수행된다.
		if (selectType == 0) {
			NM.do_castVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_castVote2(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
	else {
		selectType = atoi(tokens[2].c_str());
		cout << "Select Vote Type(0: general, 1: group): " << selectType << endl; fflush(stdout);
		//메뉴 기능 수행
		if (selectType == 0) {
			NM.do_castVote(3, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_castVote2(3, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}

}

void gm37(nonMember &NM, Group &G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int userIDX;
	string _ID;
	cout << "Selected Menu: 3.7 Unsubscribe form Group" << endl;
	if (!loadMode) {
		userIDX = NM.loginUserIdx(); //현재 사용자의 인덱스를 받아온다.
		_ID = NM.getID(userIDX); //현재 사용자의 아이디를 받아온다.
		G.delID(_ID); //그룹 멤버 목록에서 아이디를 지운다.
		NM.change_iden(userIDX, 2); //신분이 일반 멤버로 전환된다.
		grade = 2;
		cout << "SUCCESS" << endl;
		inLogWrite << "3" << " " << "7" << " " << endl;
		return;
	}
	else {
		userIDX = NM.loginUserIdx(); //현재 사용자의 인덱스를 받아온다.
		_ID = NM.getID(userIDX); //현재 사용자의 아이디를 받아온다.
		G.delID(_ID); //그룹 멤버 목록에서 아이디를 지운다.
		NM.change_iden(userIDX, 2); //신분이 일반 멤버로 전환된다.
		grade = 2;
		cout << "SUCCESS" << endl;
		return;
	}

}


void gl41(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 4.1 Logout" << endl;
	NM.do_logout(4, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens);
}

void gl42(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int selectType;

	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	//화면 출력
	cout << "Selected Menu 4.2 Delete Existing Vote" << endl;
	mem_v.printMemV();
	grp_v[groupIDX].printGrpV();

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//메뉴 기능 수행
		cin >> selectType;

		if (selectType == 0) {
			NM.do_delVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_delVote(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
	else {
		selectType = atoi(tokens[2].c_str());
		cout << "Select Vote Type(0: general, 1: group): " << selectType << endl; fflush(stdout);

		if (selectType == 0) {
			NM.do_delVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_delVote(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}

	}
}

void gl43(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int selectType;
	int temp = 0;
	int temp2 = 0;

	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);


	cout << "Selected Menu 4.3 Add a Vote Item" << endl;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) {
		if (mem_v.getIsVote(i) == 1) {
			temp++;
			cout << mem_v.getSubj(i) << ", "; fflush(stdout);
		}
	}
	cout << endl;
	if (temp == 0) {
		cout << "None" << endl;
	}
	cout << "<Group Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) {
		if (grp_v[groupIDX].getIsVote(i) == 1) {
			temp2++;
			cout << grp_v[groupIDX].getSubj(i) << ", "; fflush(stdout);
		}
	}
	cout << endl;
	if (temp2 == 0) {
		cout << "None" << endl;
	}


	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//메뉴 기능 수행
		cin >> selectType;

		if (selectType == 0) {
			NM.do_addVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_addVote(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
	else {
		selectType = atoi(tokens[2].c_str());
		cout << "Select Vote Type(0: general, 1: group): " << selectType << endl; fflush(stdout);
		//메뉴 기능 수행

		if (selectType == 0) {
			NM.do_addVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_addVote(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}

	}
}

void gl44(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	if (!loadMode) {
		cout << "Selected Menu: 4.4 List All Vote Items." << endl;
		cout << "<General Vote>" << endl;
		NM.do_listVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		cout << "<Group Vote>" << endl;
		NM.do_listVote(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
	}
	else {
		cout << "Selected Menu: 4.4 List All Vote Items." << endl;
		cout << "<General Vote>" << endl;
		NM.do_listVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		cout << "<Group Vote>" << endl;
		NM.do_listVote(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
	}
}

void gl45(nonMember &NM, Group &G, votelist &mem_v, group_votelist *grp_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int selectType;
	//그룹의 인덱스를 찾기 위한 변수들
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//로그인한 사용자가 속한 그룹의 인덱스 찾기
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	cout << "Selected Menu: 4.5 Cast a vote" << endl;
	mem_v.printMemV();
	grp_v[groupIDX].printGrpV();

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//메뉴 기능 수행
		cin >> selectType;

		if (selectType == 0) {
			NM.do_castVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_castVote2(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
	else {
		selectType = atoi(tokens[2].c_str());
		cout << "Select Vote Type(0: general, 1: group): " << selectType << endl; fflush(stdout);
		//메뉴 기능 수행
		if (selectType == 0) {
			NM.do_castVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_castVote2(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
}

void gl46(nonMember &NM, Group &G, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) // 모든 그룹 멤버들을 출력한다.
{
	int i;
	int userIDX;
	int success = 0;
	int idx = 0;

	cout << "Selected Menu: 4.6 List All Group Members" << endl;
	cout << "<Group Members>" << endl;
	if (!loadMode) {
		userIDX = NM.loginUserIdx();

		for (i = 0; i < MAX_GROUP; i++) {
			if (NM.getID(userIDX) == G.getLeaderID(i)) {
				idx = i;
				break;
			}
		}
		G.printGrpID(idx);
		inLogWrite << "4" << " " << "6" << " " << endl;
		return;
	}
	else {
		userIDX = NM.loginUserIdx();

		for (i = 0; i < MAX_GROUP; i++) {
			if (NM.getID(userIDX) == G.getLeaderID(i)) {
				idx = i;
				break;
			}
		}
		G.printGrpID(idx);
		return;
	}
}

void gl47(nonMember &NM, Group &G, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	
	string _leaderID;
	string banID;
	string tempID;
	int userIDX;
	int i;
	int idx = 0;
	int idx2;
	int banIDX;
	int success = 0;

	cout << "Selected Menu: 4.7 Ban a Group Member" << endl;
	if (!loadMode) {
		cout << "Group Member's ID to Ban: "; fflush(stdout);
		cin >> banID;

		userIDX = NM.loginUserIdx(); //리더의 인덱스를 받아온다.
		_leaderID = NM.getID(userIDX); // 리더의 ID
		if (banID == _leaderID) {
			cout << "FAIL" << endl;
			inLogWrite << "4" << " " << "7" << " " << banID << " " << endl;
			return;
		}

		for (i = 0; i < MAX_GROUP; i++) {
			if (_leaderID == G.getLeaderID(i)) { //리더의 아이디를 이용하여 그룹에서 리더가 속한 인덱스를 찾는다.
				idx = i;
				
				break;
			}
		}
		///////////////////////////////
		for (i = 0; i < MAX_GROUP_MEM; i++) {
			if (banID == G.getMemID(idx, i)) {
				success = 1;
				idx2 = i;
				break;
			}
		}
		if (!success) {
			cout << "FAIL" << endl;
			inLogWrite << "4" << " " << "7" << " " << banID << " " << endl;
			return;
		}


		G.delID(banID); //입력한 ID에 해당하는 ID를 그룹 멤버에서 지운다.
		banIDX = NM.getIDXbyID(banID);
		NM.change_iden(banIDX, 2); //강퇴를 당한 멤버의 신분을 그룹 멤버에서 일반 멤버로 변경한다.
		cout << "SUCCESS" << endl;
		inLogWrite << "4" << " " << "7" << " " << banID << " " << endl;
		return;
	}
	else {
		banID = tokens[2];
		cout << "Group Member's ID to Ban: " << banID << endl; fflush(stdout);

		userIDX = NM.loginUserIdx(); //리더의 인덱스를 받아온다.
		_leaderID = NM.getID(userIDX); // 리더의 ID
		if (banID == _leaderID) {
			cout << "FAIL" << endl;
			return;
		}

		for (i = 0; i < MAX_GROUP; i++) {
			if (_leaderID == G.getLeaderID(i)) { //리더의 아이디를 이용하여 그룹에서 리더가 속한 인덱스를 찾는다.
				idx = i;
				break;
			}
		}
		///////////////////////////////
		for (i = 0; i < MAX_GROUP_MEM; i++) {
			if (banID == G.getMemID(idx, i)) {
				success = 1;
				idx2 = i;
				break;
			}
		}
		if (!success) {
			cout << "FAIL" << endl;

			return;
		}


		G.delID(banID); //입력한 ID에 해당하는 ID를 그룹 멤버에서 지운다.
		banIDX = NM.getIDXbyID(banID);
		NM.change_iden(banIDX, 2); //신분 변경
		cout << "SUCCESS" << endl;

		return;
	}


}


void menu00(nonMember &NM, Group &G, votelist &memV, group_votelist *grpV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i, j;
	if (!loadMode) {
		inLogWrite << "0" << " " << "0" << " " << endl;
	}
	else {
		cout << "0 0" << endl;
	}

	cout << endl;
	cout << "<Member List>" << endl;
	for (i = 0; i < MAX_MEM; i++) {
		if (!NM.isREGI(i))
		{
			continue;
		}
		cout << "[ID]: " << NM.getID(i) << ", [Joined Group]: " << G.grpNameByID(NM.getID(i)) << ", [Position]: "; fflush(stdout);
		if (NM.whatIdentity(i) == 4) {
			cout << "Group Leader" << endl;
		}
		else if (NM.whatIdentity(i) == 3) {
			cout << "Group Member" << endl;
		}
		else if (NM.whatIdentity(i) == 2) {
			cout << "Member" << endl;
		}
		else {
			cout << "Non Member" << endl;
		}
	}

	cout << "<Group List>" << endl;
	for (i = 0; i < MAX_GROUP; i++) {
		if (!G.getIsGrp(i))
		{
			continue;
		}
		cout << G.getGrpName(i) << ", "; fflush(stdout);
	}
	cout << endl;

	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) {
		if (!memV.getIsVote(i)) {
			continue;
		}
		cout << memV.getSubj(i) << ", "; fflush(stdout);
	}
	cout << endl;

	cout << "<Group Votes>" << endl;
	for (i = 0; i < MAX_GROUP_VOTE; i++) {
		if (!grpV->getIsVote(i)) {
			continue;
		}
		grpV[i].printGrpVotesInfo();
	}
	cout << endl;


}