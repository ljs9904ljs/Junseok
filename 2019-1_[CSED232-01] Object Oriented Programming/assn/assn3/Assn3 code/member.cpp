/*
�й�: 20180551
�̸�: ���ؼ�
povis ID: ljs9904ljs

������(Honor code)

������ �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.��
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
		//RRN, ID, password�� �Է¹޴´�.
		cout << "RRN: "; fflush(stdout);
		cin >> tRRN;
		cout << "ID: "; fflush(stdout);
		cin >> tID;
		cout << "password: "; fflush(stdout);
		cin >> tPassword;

		
		if (totLogin == 1) { //�α��� �Ǿ� �ִ� ��쿡�� ȸ�� ���� �Ұ�
			cout << "FAIL" << endl;
			inLogWrite << "1" << " " << "1" << " " << tRRN << " " << tID << " " << tPassword << " " << endl;
			return;
		}

		for (i = 0; i < MAX_MEM; i++) { // ID�� RRN �� ���� �ϳ��� ��ġ�� ȸ�� ���� �Ұ�
			if (person[i].ID == tID || person[i].RRN == tRRN) { //
				cout << "FAIL" << endl;
				inLogWrite << "1" << " " << "1" << " " << tRRN << " " << tID << " " << tPassword << " " << endl;
				return;
			}
		}

		for (i = 0; i < MAX_MEM; i++) { //�迭�� �� ĭ�� ã�´�.
			if (!(person[i].isRegi)) {
				idx = i;
				break;
			}
		}

		//valid case�� �ش��� ��, �迭�� �� ĭ�� ������ �����Ѵ�.
		person[idx].ID = tID;
		person[idx].isRegi = 1; // ��ϵ��� ǥ��
		person[idx].password = tPassword;
		person[idx].RRN = tRRN;
		person[idx].identity = 2; // �Ϲ� ����� �ȴ�.
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

		//valid case�� �ش��� ��
		person[idx].ID = tID;
		person[idx].isRegi = 1; // ��ϵ��� ǥ��
		person[idx].password = tPassword;
		person[idx].RRN = tRRN;
		person[idx].identity = 2; // �Ϲ� ����� �ȴ�.
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

int Group::check1(string &_grpName) //�׷� �̸��� �Է¹ް� �׷� �̸��� ������ �׷� �̸��� �ߺ��Ǵ��� Ȯ���Ѵ�. �ߺ����� �ʴ´ٸ� �� �Է��� �׷� �̸��� ��������.
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

int Group::toGrp(nonMember &NM, string grpName, int idx) //������ �׷쿡 �߰��Ѵ�. �׸��� ������ �߰��� �׷��� �ε����� ��ȯ�Ѵ�.
{
	int i;
	int _cur;
	int grpIDX = -1;

	for (i = 0; i < MAX_GROUP; i++) {
		if (grp[i].groupName == "") { //�׷� �迭�� ���ڸ��� ã�Ƽ� �װ��� �׷� ������ �����Ѵ�.
			_cur = grp[i].cur;

			grp[i].groupName = grpName; // �׷� �̸��� �߰��Ѵ�.

			grp[i].groupLeader = NM.getID(idx); // �׷� ���� �ڸ��� �� �׷��� ���� ����� ID�� �����Ѵ�.

			//�׷� ����ε� �߰��Ѵ�.
			grp[i].groupMems[_cur] = NM.getID(idx);
			grp[i].cur++;
			//�׷� ���縦 ǥ���Ѵ�.
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

				//ȸ�� Ż�� ���� �α׾ƿ��� �ź� ����.
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

				//ȸ�� Ż�� ���� �α׾ƿ��� �ź� ����.
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

		//�ߺ��� ��ǥ �������� �˻��Ѵ�.
		if (!memV.duplTest(tSubj)) { //�ߺ��� �������
			if (menu == 2) {
				inLogWrite << "2" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 3) {
				inLogWrite << "3" << " " << "4" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "3" << " " << "0" << " " << tSubj << " " << itemNum << " " << endl;
			}
			return; //����
		}

		//valid case�� ��
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

		//�ߺ��� ��ǥ �������� �˻��Ѵ�.
		if (!memV.duplTest(tSubj)) { //�ߺ��� �������
			return; //����
		}

		//valid case�� ��
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

		//�ߺ��� ��ǥ �������� �˻��Ѵ�.
		if (!grpV.duplTest(tSubj)) { //�ߺ��� �������
			if (menu == 3) {
				inLogWrite << "3" << " " << "4" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
			}
			else if (menu == 4) {
				inLogWrite << "4" << " " << "3" << " " << "1" << " " << tSubj << " " << itemNum << " " << endl;
			}
			return; //����
		}

		//valid case�� ��
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

		//�ߺ��� ��ǥ �������� �˻��Ѵ�.
		if (!grpV.duplTest(tSubj)) { //�ߺ��� �������
			return; //����
		}

		//valid case�� ��
		grpV.addV(tSubj, itemNum);

		cout << "SUCCESS" << endl;
		return;
	}
}


void nonMember::do_listVote(int menu, votelist &memV, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens) //2.5
{
	//��ǥ ����Ʈ ���
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
	//��ǥ ����Ʈ ���
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

		userIndex = loginUserIdx(); //�α����� ������ �ε����� �޾ƿ´�.
		if (userIndex == -1) { //�α����� ������ ����.
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

		//��ǥ �׸� ���� ������ Ȯ���Ѵ�.
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

		userIndex = loginUserIdx(); //�α����� ������ �ε����� �޾ƿ´�.
		if (userIndex == -1) { //�α����� ������ ����.
			cout << "FAIL" << endl;
			return;
		}
		tRRN = person[userIndex].RRN;
		if (!memV.testVoteRRN(tRRN)) {
			cout << "FAIL" << endl;
			return;
		}

		//��ǥ �׸� ���� ������ Ȯ���Ѵ�.
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

	userIndex = loginUserIdx(); //�α����� ������ �ε����� �޾ƿ´�.
	if (userIndex == -1) { //�α����� ������ ����.
		cout << "FAIL" << endl;
		return;
	}
	tRRN = person[userIndex].RRN;
	if (!grpV.testVoteRRN(tRRN)) {
		cout << "FAIL" << endl;
		return;
	}

	//��ǥ �׸� ���� ������ Ȯ���Ѵ�.
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

		userIndex = loginUserIdx(); //�α����� ������ �ε����� �޾ƿ´�.
		if (userIndex == -1) { //�α����� ������ ����.
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

		//��ǥ �׸� ���� ������ Ȯ���Ѵ�.
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

		userIndex = loginUserIdx(); //�α����� ������ �ε����� �޾ƿ´�.
		if (userIndex == -1) { //�α����� ������ ����.
			cout << "FAIL" << endl;
			return;
		}
		tRRN = person[userIndex].RRN;
		if (!grpV.testVoteRRN(tRRN)) {
			cout << "FAIL" << endl;
			return;
		}

		//��ǥ �׸� ���� ������ Ȯ���Ѵ�.
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