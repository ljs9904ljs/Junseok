/*
�й�: 20180551
�̸�: ���ؼ�
povis ID: ljs9904ljs

������(Honor code)

������ �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.��
*/

#include "default.h"
// �Ϲ� �Լ�

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
	NM.do_register(loadMode, inLogRead, inLogWrite, tokens, nTokens); // 1.1�� �޴��� ������ �޼ҵ�
}
void nm12(nonMember & NM, Group & G, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i = 0;
	int idx = -1;
	int right = 0;
	string tID, tPassword;
	int isLogin = 0;

	cout << "Selected Menu: 1.2 Login" << endl;

	if (!loadMode) {//�ε��尡 �ƴϸ�

		cout << "ID: "; fflush(stdout);
		cin >> tID;
		cout << "password: "; fflush(stdout);
		cin >> tPassword;

		isLogin = NM.isTotLogin();
		if (isLogin) { // �α����� �̹� �Ǿ� �ִٸ�
			cout << "FAIL" << endl; // �α��� �Ұ���(����)
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}

		right = NM.id_pw_check(tID, tPassword, idx); // ��ϵǾ� �ִ� ID�� password���� Ȯ���Ѵ�.
		if (!right) { //��ϵǾ� ���� �ʴٸ�
			cout << "FAIL" << endl; // �α��� ����
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}
		if (NM.whatIdentity(idx) == 4) { //�׷� ������ �α����� ��
			grade = 4;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}
		else if (NM.whatIdentity(idx) == 3) { //�׷� ����� �α����� ��
			grade = 3;
			NM.do_login(idx);
			cout << "SUCCESS" << endl;
			inLogWrite << "1" << " " << "2" << " " << tID << " " << tPassword << " " << endl;
			return;
		}
		else if (NM.whatIdentity(idx) == 2) { //�Ϲ� ����� �α����� ��
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

	NM.do_logout(2, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); //�α׾ƿ��� �����Ѵ�.
}
void m22(nonMember &NM, int&grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 2.2 Unsubscribe form System" << endl;
	NM.do_unsub(2, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); //ȸ��Ż�� �����Ѵ�.
}
void m23(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	cout << "Selected Menu 2.3 Delete Existing Vote" << endl;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) {
		if (mem_v.getIsVote(i)) //��ǥ ������ �����ϴ� �迭�� ĭ�� ��
			cout << mem_v.getSubj(i) << ", "; fflush(stdout); //��ǥ ������ ����Ѵ�
	}
	cout << endl;

	NM.do_delVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // ��ǥ ������ �����
}
void m24(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	int temp = 0;
	cout << "Selected Menu 2.4 Add a Vote Item" << endl;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) {
		if (mem_v.getIsVote(i) == 1) { // �迭�� ĭ �ȿ� ��ǥ ������ ������ ��
			temp++;
			cout << mem_v.getSubj(i) << ", "; fflush(stdout); // ��ǥ ������ ����Ѵ�.
		}
	}
	cout << endl;

	if (temp == 0) {
		cout << "None" << endl; // ��ǥ ������ �ϳ��� ���� ��
	}

	NM.do_addVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // ��ǥ ������ �߰��Ѵ�.
}
void m25(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 2.5 List All Vote Items." << endl;
	cout << "<General Vote>" << endl;
	NM.do_listVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // ��ǥ ���� �� ��Ȳ�� ����Ѵ�. �Ϲ� ��ǥ�� ����Ѵ�.
}
void m26(nonMember &NM, votelist &mem_v, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int i;
	cout << "Selected Menu: 2.6 Cast a vote" << endl;
	cout << "<General Votes>" << endl;
	for (i = 0; i < MAX_VOTE; i++) { // ��ǥ ������ ����Ѵ�.
		cout << mem_v.getSubj(i) << " "; fflush(stdout);
	}
	cout << endl;

	NM.do_castVote(2, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens); // �Ϲ� ��ǥ�� �����Ѵ�.
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

		idx = NM.loginUserIdx(); //�α����� ������ �ε����� �޾ƿ´�.

		if (idx == -1) { //�α����� ������ ����.
			cout << "FAIL: No user is logged in." << endl;
			inLogWrite << "2" << " " << "7" << " " << grpName << " " << endl;
			return;
		}
		tID = NM.getID(idx);

		for (i = 0; i < MAX_GROUP; i++) {
			if (G.getGrpName(i) == grpName) { // �Է��� �׷� ��� ��ġ�ϴ� �׷��� ã�´�.
				temp = G.getGrpCur(i);
				NM.change_iden(idx, 3); // �׷� ����� �Ǿ����� �ǹ��Ѵ�.

				//�׷��� ����μ� �߰��Ѵ�.
				G.setGrpMem(i, tID);

				//SUCCESS
				grade = 3;
				cout << "SUCCESS" << endl;
				inLogWrite << "2" << " " << "7" << " " << grpName << " " << endl;
				return;
			}
		}

		//FAIL, �Է��� �׷� ���� �׷��� �������� �ʴ´�.
		cout << "FAIL: The group with the name you entered does not exist." << endl;
		inLogWrite << "2" << " " << "7" << " " << grpName << " " << endl;
		return;
	}
	else {
		grpName = tokens[2];
		cout << "Group Name to Join: " << grpName << endl; fflush(stdout);

		idx = NM.loginUserIdx(); //�α����� ������ �ε����� �޾ƿ´�.

		if (idx == -1) { //�α����� ������ ����.
			cout << "FAIL: No user is logged in." << endl;
			return;
		}
		tID = NM.getID(idx);

		for (i = 0; i < MAX_GROUP; i++) {
			if (G.getGrpName(i) == grpName) { // �Է��� �׷� ��� ��ġ�ϴ� �׷��� ã�´�.
				temp = G.getGrpCur(i);
				NM.change_iden(idx, 3); // �׷� ����� �Ǿ����� �ǹ��Ѵ�.

				//�׷��� ����μ� �߰��Ѵ�.
				G.setGrpMem(i, tID);

				//SUCCESS
				grade = 3;
				cout << "SUCCESS" << endl;
				return;
			}
		}

		//FAIL, �Է��� �׷� ���� �׷��� �������� �ʴ´�.
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
		noUse = G.check1(grpName); //�׷� �̸��� �Է¹ް� �׷� �̸��� ������ �׷� �̸��� �ߺ��Ǵ��� Ȯ���Ѵ�. �ߺ����� �ʴ´ٸ� �� �Է��� �׷� �̸��� ��������.

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
		if (!success) { // �α����� ����ڰ� ������ �翬�� ����
			cout << "FAIL: No user is logged in." << endl;
			inLogWrite << "2" << " " << "8" << " " << grpName << " " << endl;
			return;
		}
		grpIDX = G.toGrp(NM, grpName, idx); //������ �׷쿡 �߰��Ѵ�. �׸��� ������ �߰��� �׷��� �ε����� ��ȯ�ϰ� �޴´�.
		grpV[grpIDX].setGrpName(grpName); // �׷� �̸��� �߰��Ѵ�.
		//SUCCESS
		G.set_identity(idx, 4); // �׷� ������ �ȴ�.
		NM.change_iden(idx, 4); // �׷� ���� ����
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
		G.set_identity(idx, 4); // �׷� ������ �ȴ�.
		NM.change_iden(idx, 4); // �׷� ���� ����
		cout << "SUCCESS" << endl;

		grade = 4;
		return;
	}

}


//void m29();

void gm31(nonMember &NM, int &grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	cout << "Selected Menu: 3.1 Logout" << endl;
	NM.do_logout(3, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); // �α� �ƿ� �Ѵ�.
}

void gm32(nonMember &NM, Group& G, int&grade, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int userIDX;
	userIDX = NM.loginUserIdx(); // ���� ������� �ε����� �޾ƿ´�.
	string userID;
	userID = NM.getID(userIDX); //  ���� ������� �ε����� �������� ���� ������� ���̵� �޾ƿ´�.
	string groupID;
	int i, j;
	int check = 0;
	int success;

	cout << "Selected Menu: 3.2 Unsubscribe form System" << endl;
	success = NM.do_unsub(3, grade, loadMode, inLogRead, inLogWrite, tokens, nTokens); // ȸ�� Ż�� �����ϰ� ���������� ����Ǹ� 0�� �����Ѵ�.

	if (success == 0) { // ȸ�� Ż�� �������̶��
		//�׷쿡�� �� Ż���� ����� ���õ� ������ �����.
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

	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	//ȭ�� ���
	cout << "Selected Menu 3.3 Delete Existing Vote" << endl;
	mem_v.printMemV(); // �Ϲ� ��ǥ ��� ���
	grp_v[groupIDX].printGrpV(); // �׷� ��ǥ ��� ���

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//�޴� ��� ����
		cin >> selectType;

		//selectType�� ���� �Ϲ� ��ǥ�� ������ �׷� ��ǥ�� ������ �����ϰ� �׿� ���� ��ǥ ����⸦ �����Ѵ�.
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

		//selectType�� ���� �Ϲ� ��ǥ�� ������ �׷� ��ǥ�� ������ �����ϰ� �׿� ���� ��ǥ ����⸦ �����Ѵ�.
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

	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);


	cout << "Selected Menu 3.4 Add a Vote Item" << endl;
	cout << "<General Votes>" << endl; //�Ϲ� ��ǥ ��� ���
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
	cout << "<Group Votes>" << endl; // �׷� ��ǥ ��� ���
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
		//�޴� ��� ����
		cin >> selectType;

		//selectType�� ���� ��ǥ�� �߰��Ѵ�.
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
		//�޴� ��� ����

		//selectType�� ���� ��ǥ�� �߰��Ѵ�.
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
	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	//��ǥ ����� ����Ѵ�. �Ϲ� ��ǥ�� �׷� ��ǥ�� ��� ����Ѵ�.
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
	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	cout << "Selected Menu: 3.6 Cast a vote" << endl;
	mem_v.printMemV();
	grp_v[groupIDX].printGrpV();

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//�޴� ��� ����
		cin >> selectType;

		//selectType�� ���� �Ϲ� ��ǥ �ϱ�� �׷� ��ǥ �ϱ�� ���������� ����ȴ�.
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
		//�޴� ��� ����
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
		userIDX = NM.loginUserIdx(); //���� ������� �ε����� �޾ƿ´�.
		_ID = NM.getID(userIDX); //���� ������� ���̵� �޾ƿ´�.
		G.delID(_ID); //�׷� ��� ��Ͽ��� ���̵� �����.
		NM.change_iden(userIDX, 2); //�ź��� �Ϲ� ����� ��ȯ�ȴ�.
		grade = 2;
		cout << "SUCCESS" << endl;
		inLogWrite << "3" << " " << "7" << " " << endl;
		return;
	}
	else {
		userIDX = NM.loginUserIdx(); //���� ������� �ε����� �޾ƿ´�.
		_ID = NM.getID(userIDX); //���� ������� ���̵� �޾ƿ´�.
		G.delID(_ID); //�׷� ��� ��Ͽ��� ���̵� �����.
		NM.change_iden(userIDX, 2); //�ź��� �Ϲ� ����� ��ȯ�ȴ�.
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

	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	//ȭ�� ���
	cout << "Selected Menu 4.2 Delete Existing Vote" << endl;
	mem_v.printMemV();
	grp_v[groupIDX].printGrpV();

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//�޴� ��� ����
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

	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
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
		//�޴� ��� ����
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
		//�޴� ��� ����

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
	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
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
	//�׷��� �ε����� ã�� ���� ������
	int userIDX;
	int groupIDX;
	string _ID;
	string _grpName;
	//�α����� ����ڰ� ���� �׷��� �ε��� ã��
	userIDX = NM.loginUserIdx();
	_ID = NM.getID(userIDX);
	_grpName = G.grpNameByID(_ID);
	groupIDX = getIDXbyGroupName(G, grp_v, _grpName);

	cout << "Selected Menu: 4.5 Cast a vote" << endl;
	mem_v.printMemV();
	grp_v[groupIDX].printGrpV();

	if (!loadMode) {
		cout << "Select Vote Type(0: general, 1: group): "; fflush(stdout);
		//�޴� ��� ����
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
		//�޴� ��� ����
		if (selectType == 0) {
			NM.do_castVote(4, mem_v, loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
		else if (selectType == 1) {
			NM.do_castVote2(4, grp_v[groupIDX], loadMode, inLogRead, inLogWrite, tokens, nTokens);
		}
	}
}

void gl46(nonMember &NM, Group &G, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) // ��� �׷� ������� ����Ѵ�.
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

		userIDX = NM.loginUserIdx(); //������ �ε����� �޾ƿ´�.
		_leaderID = NM.getID(userIDX); // ������ ID
		if (banID == _leaderID) {
			cout << "FAIL" << endl;
			inLogWrite << "4" << " " << "7" << " " << banID << " " << endl;
			return;
		}

		for (i = 0; i < MAX_GROUP; i++) {
			if (_leaderID == G.getLeaderID(i)) { //������ ���̵� �̿��Ͽ� �׷쿡�� ������ ���� �ε����� ã�´�.
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


		G.delID(banID); //�Է��� ID�� �ش��ϴ� ID�� �׷� ������� �����.
		banIDX = NM.getIDXbyID(banID);
		NM.change_iden(banIDX, 2); //���� ���� ����� �ź��� �׷� ������� �Ϲ� ����� �����Ѵ�.
		cout << "SUCCESS" << endl;
		inLogWrite << "4" << " " << "7" << " " << banID << " " << endl;
		return;
	}
	else {
		banID = tokens[2];
		cout << "Group Member's ID to Ban: " << banID << endl; fflush(stdout);

		userIDX = NM.loginUserIdx(); //������ �ε����� �޾ƿ´�.
		_leaderID = NM.getID(userIDX); // ������ ID
		if (banID == _leaderID) {
			cout << "FAIL" << endl;
			return;
		}

		for (i = 0; i < MAX_GROUP; i++) {
			if (_leaderID == G.getLeaderID(i)) { //������ ���̵� �̿��Ͽ� �׷쿡�� ������ ���� �ε����� ã�´�.
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


		G.delID(banID); //�Է��� ID�� �ش��ϴ� ID�� �׷� ������� �����.
		banIDX = NM.getIDXbyID(banID);
		NM.change_iden(banIDX, 2); //�ź� ����
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