#include "default.h"
using namespace std;

class memberInfo {
private:
	string RRN = "";
	string ID = "";
	string password = "";
	int login = 0; // �α��� �Ǿ� ������ 1, �� �Ǿ� ������ 0
	int reg = 0; // ��� �Ǿ� ������ 1, �� �Ǿ� ������ 0
	int isVote = 0; // ��ǥ ������ 1, �� ������ 0
public:
	void getRRN() {
		cin >> RRN;
	}
	void getID() {
		cin >> ID;
	}
	void getPassword() {
		cin >> password;
	}
	void add(string inRRN, string inID, string inPassword)
	{
		RRN = inRRN;
		ID = inID;
		password = inPassword;
	}
	void whatRRN(string & myRRN) {
		myRRN = RRN;
	}
	void whatID(string & myID) {
		myID = ID;
	}
	void whatPassword(string & myPassword) {
		myPassword = password;
	}
	void doLogin() {
		login = 1;
	}
	void doLogout() {
		login = 0;
	}
	int logState() {
		return login;
	}
	int regState() {
		return reg;
	}
	void doReg() {
		reg = 1;
	}
	void doRegOut() {
		reg = 0;
	}
	void doVote() {
		isVote = 1;
	}
	void delVote() {
		isVote = 0;
	}
	int whatVote() {
		return isVote;
	}
};

class memberCollection {
private:
	memberInfo memberList[MAX_NUM_MEMBER];
	int peopleCount = 0;
public:
	void getRRN(int index) {
		memberList[index].getRRN();
	}
	void getID(int index) {
		memberList[index].getID();
	}
	void getPassword(int index) {
		memberList[index].getPassword();
	}
	void whatMemListValues(int index, string & RRN, string & ID, string & password) { // ����Ǿ� �ִ� rrn, id, password�� �˷��ش�.
		memberList[index].whatRRN(RRN);
		memberList[index].whatID(ID);
		memberList[index].whatPassword(password);
	}
	void countUp() {
		peopleCount++;
	}
	void countDown() {
		peopleCount--;
	}
	void addMem(int index, string & RRN, string & ID, string & password) {
		memberList[index].add(RRN, ID, password);
		countUp();
	}
	void delMem(int index) {
		memberList[index].add("", "", "");
		memberList[index].doLogout();
		memberList[index].doRegOut();
		memberList[index].delVote();
		countDown();
	}
	int whatPeopleCount() {
		return peopleCount;
	}
	void login(int index) {
		memberList[index].doLogin();
	}
	void logout(int index) {
		memberList[index].doLogout();
	}
	int isLogin(int index) { // �α��� 1, �α׾ƿ� 0
		if (index == -1) {
			cout << "��Ͽ� ���� ����Դϴ�." << endl;
			return 0;
		}
		else
			return memberList[index].logState();

	}
	int isRegister(int index) { // ��� ������ ������ 1, ������ 0
		if (memberList[index].regState() == 0)
			return 0;
		else
			return 1;
	}

	void regi(int index) {
		memberList[index].doReg();
	}
	void undoRegi(int index) {
		memberList[index].doRegOut();
	}
};

class vote {
private:
	string voteSubject = "";
	string voteItem[MAX_NUM_VOTEITEM] = { "item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10" };
	int voteNum[MAX_NUM_VOTEITEM];
	int howManyItems = 0;
	int check = 0; // ��ǥ�� �����ϳ� �� �ϳ�, 0�̸� ���� 1�̸� �ִ�
public:
	int isCheck() {
		return check;
	}
	void whatItemNum(int &n) {
		n = howManyItems;
	}
	void whatSubject(string & subject) {
		subject = voteSubject;
	}
	int delVote(string subject) { //�ߺ��� ������ ��ǥ�� ���� �� ���� �ʳ�? �׸� ���� �ٸ��� �ؼ�. pdf �ٽ� �о��
		int success = 0;
		int i;

		if (voteSubject == subject) {
			for (i = 0; i < MAX_NUM_VOTEITEM; i++)
				voteNum[i] = -1;

			check = 0;
			voteSubject = "";
			howManyItems = 0;
			success = 1;
		}
		return success;
	}
	void newVote(string subject, int itemNum) {
		int i;

		howManyItems = itemNum;
		voteSubject = subject;
		for (i = 0; i < MAX_NUM_VOTEITEM; i++) {
			if (i < itemNum)
				voteNum[i] = 0;
			else
				voteNum[i] = -1;
		}
		check = 1;
	}
	void showListVote() {
		int i;

		for (i = 0; i < howManyItems; i++) {
			cout << voteItem[i] << ": " << voteNum[i] << " "; fflush(stdout);
		}
	}
	void doVote(int item) {
		if (voteNum[item - 1] == -1)
			cout << "��Ͽ� ���� �׸� ��ǥ�ϼ̽��ϴ�." << endl;
		else
			voteNum[item - 1]++;
	}
};

class listOfVoters {
private:
	string voterList[MAX_NUM_MEMBER];
public:
	void iniVoterList() {
		int i;
		for (i = 0; i < MAX_NUM_MEMBER; i++) {
			voterList[i] = "";
		}
	}
	void logVoter(string RRN) {
		int i;
		int index;

		for (i = 0; i < MAX_NUM_MEMBER; i++) { // �迭�� ����ִ� ĭ�� ã�´�.
			if (voterList[i] == "") {
				index = i;
				break;
			}
		}
		voterList[index] = RRN;
	}
	int isVote(string &RRN) {
		int i;
		int success = 0;

		for (i = 0; i < MAX_NUM_MEMBER; i++) {
			if (voterList[i] == RRN) {
				success = 1; // �̹� ��ǥ�� RRN�̴�.
			}
		}
		return success;
	}
};

void join(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void withdraw(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void login(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void logout(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);

void delVote(vote * votes, memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void addVote(vote * votes, memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void viewVotes(vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens);
void castVote(listOfVoters &vteList, vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens);




//�޴� 1��, �ߺ� �˻�         *************Ż���ϰ� �ٽ� ���鶧�� ����ؾ��� ���� �ʼ�
int overlapTest(memberCollection memList, string RRN, string ID)
{
	int success = 1;
	int i;
	string tempRRN, tempID, tempPassword;

	for (i = 0; i < MAX_NUM_MEMBER; i++) {
		if (memList.isRegister(i)) {
			memList.whatMemListValues(i, tempRRN, tempID, tempPassword);
			if (tempRRN == RRN || tempID == ID) {
				success = 0;
				break;
			}
		}
	}
	return success;
}
// ���̵�� ��й�ȣ�� index ã��
int findIndex(memberCollection memList, string ID, string password)
{
	int index = -1;
	int i;
	string cmpRRN, cmpID, cmpPassword;

	for (i = 0; i < MAX_NUM_MEMBER; i++) {
		memList.whatMemListValues(i, cmpRRN, cmpID, cmpPassword);
		if (ID == cmpID && password == cmpPassword) {
			index = i;
		}
	}
	return index; //�������� �ʴ� ������ -1����
}
// �α����� ������� index ã��
int findIndex(memberCollection memList)
{
	int index = -1;
	int i;

	for (i = 0; i < MAX_NUM_MEMBER; i++) {
		if (memList.isLogin(i)) {
			index = i;
			break;
		}
	}
	return index; //�α����� ����ڰ� ������ -1����
}
// votes[]�� ����ִ� ĭ�� index�� ã�´�.
int findIndex(vote * votes)
{
	int index = -1;
	int i;

	for (i = 0; i < MAX_NUM_VOTE; i++) {
		if (!votes[i].isCheck()) {
			index = i;
			break;
		}
	}
	return index; // ����ִ� ĭ�� ������ -1����
}



int printMenu1()
{
	string line;
	int loadMode;
	cout << "Load log file?(1:yes, 0:no (log will be deleted)):"; fflush(stdout);
	//cin >> line;
	getline(cin, line);
	loadMode = atoi(line.c_str());
	const char* tmp = line.c_str();
	return loadMode;
}
void printMenu2(int num)
{
	cout << "\n\n=======================" << endl; fflush(stdout);
	cout << "Num:" << num << endl; fflush(stdout);
	cout << "n=======================" << endl; fflush(stdout);
	cout << "1. Register as a Member" << endl; fflush(stdout);
	cout << "2. Unsubscribe from System" << endl; fflush(stdout);
	cout << "3. Login" << endl; fflush(stdout);
	cout << "4. Logout" << endl; fflush(stdout);
	cout << "5. Delete Existing Vote Item" << endl; fflush(stdout);
	cout << "6. Add a New Vote Item" << endl; fflush(stdout);
	cout << "7. List All Vote Items" << endl; fflush(stdout);
	cout << "8. Cast a Vote" << endl; fflush(stdout);
	cout << "9. Program Exit" << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "Select Menu:"; fflush(stdout);
}
void clearTokens(string * tokens)
{
	for (int i = 0; i < 4; i++)
		tokens[i].clear();
}

void doTask()
{

	int menu = 0;
	int num = 1;
	int loadMode;
	ofstream inLogWrite;
	ifstream inLogRead;
	string tokens[4], line;
	stringstream stream;
	int nTokens = 0; //number of tokens in string
	int tmp = 10;

	memberCollection memList;
	int isLoginUser = 0; //�α����� ������ ������ 1, ������ 0
	string userID, userPassword; //�α����� ������ ���̵�, ��й�ȣ
	vote votes[MAX_NUM_VOTE];
	listOfVoters vteList; // ��ǥ�� ������� ���
	vteList.iniVoterList(); // vteList �迭�� �ʱ�ȭ


	loadMode = printMenu1();
	if (!loadMode) {
		inLogWrite.open(COMMAND_LOG_FILE_NAME, ios::out);
	}
	else {
		inLogRead.open(COMMAND_LOG_FILE_NAME, ios::in); //read mode
		inLogWrite.open(COMMAND_LOG_FILE_NAME, ios::in | ios::app); //concat without truncation
	}

	while (1)
	{
		printMenu2(num++);
		if (loadMode == 1)
		{
			getline(inLogRead, line);
			if (line == "")
			{
				//end of file with newline
				if (inLogRead.eof())
				{
					//stop reading from logfile 
					//stdin mode starts
					inLogRead.close();
					loadMode = 0;
					getline(cin, line);
					//when first stdin input was newline
					//continue without loggin input
					if (line == "")
					{
						cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
						continue;
					}
					menu = atoi(line.c_str());
				}
				//middle of file with new line
				//continue without logging
				else
				{
					cout << "\nSelected Menu: Undefined menu selection" << endl; fflush(stdout);
					continue;
				}
			}

			//inputs != newline
			else
			{
				stream.str(line);
				nTokens = 0;
				clearTokens(tokens);
				//Read all tokens(seperated by " ")
				while (stream >> tokens[nTokens])
					nTokens++;
				stream.clear();
				menu = atoi(tokens[0].c_str());
				cout << menu << endl; fflush(stdout);
			}


		}
		//stdin mode
		else
		{
			getline(cin, line);
			if (line == "")
			{
				cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
				continue;
			}
			menu = atoi(line.c_str());
		}

		// �޴� ���� �� �ش� ���� ����
		switch (menu)
		{
		case 1:
		{
			join(memList, loadMode, inLogRead, inLogWrite, tokens, nTokens);
			break;
		}
		case 2:
		{
			withdraw(memList, loadMode, inLogRead, inLogWrite, tokens, nTokens);
			break;
		}
		case 3:
		{
			login(memList, loadMode, inLogRead, inLogWrite, tokens, nTokens);
			break;
		}
		case 4:
		{
			logout(memList, loadMode, inLogRead, inLogWrite, tokens, nTokens);
			break;
		}
		case 5:
		{
			delVote(votes, memList, loadMode, inLogRead, inLogWrite, tokens, nTokens);
			break;
		}
		case 6:
		{
			addVote(votes, memList, loadMode, inLogRead, inLogWrite, tokens, nTokens);
			break;
		}
		case 7:
		{
			viewVotes(votes, memList, loadMode, inLogWrite, tokens, nTokens);
			break;
		}
		case 8:
		{
			castVote(vteList, votes, memList, loadMode, inLogWrite, tokens, nTokens);
			break;
		}
		case 9:
		{

			inLogWrite.close();
			return;

		}
		default:
			cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
			if (!loadMode) {
				inLogWrite << menu << endl;
				continue;
			}
			break;

		}
		if (!loadMode && (menu != 4 && menu != 7)) {
			getchar();
		}
	}
	return;
}

//1. ȸ������
void join(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	//ȸ�����Կ����� ������ �Է¹��� ���ڿ�����
	string RRN, ID, password;
	cout << "Selected Menu: 1. Register as a Member" << endl; fflush(stdout);

	int index, i;

	for (i = 0; i < MAX_NUM_MEMBER; i++) {
		if (!memList.isRegister(i)) { //��� ������ ����Ǿ� ���� ���� memList�� index�� ���� ����Ϸ��� ����� ������ ������ ���̴�.
			index = i;
			break;
		}
	}

	if (!loadMode)
	{
		cout << "Resident Registration Number:"; fflush(stdout);
		cin >> RRN;
		cout << "ID:"; fflush(stdout);
		cin >> ID;
		cout << "Password:"; fflush(stdout);
		cin >> password;

		//�ߺ� �˻�
		if (!overlapTest(memList, RRN, ID)) {
			cout << "Invalid Registration Attempt!" << endl;
			inLogWrite << "1 " << RRN << " " << ID << " " << password << " " << endl;  // ���� ���̽��� ����Ѵ�. *****
			return;
		}
		memList.addMem(index, RRN, ID, password); //memList�� member �߰�
		memList.regi(index); //��ϵ����� ǥ���Ѵ�
		cout << "Registration Success!" << endl;
		inLogWrite << "1 " << RRN << " " << ID << " " << password << " " << endl;
		return;
	}
	else {
		RRN = tokens[1]; ID = tokens[2]; password = tokens[3];
		cout << "1. Resident Registration Number: " << RRN << endl; fflush(stdout);
		cout << "ID: " << ID << endl; fflush(stdout);
		cout << "Password:" << password << endl; fflush(stdout);

		//�ߺ� �˻�
		if (!overlapTest(memList, RRN, ID)) {
			cout << "Invalid Registration Attempt!" << endl;
			return;
		}

		memList.addMem(index, RRN, ID, password); //memList�� member �߰�
		memList.regi(index); //��ϵ�
		cout << "Registration Success!" << endl;
		return;
	}

	cout << "Unimplemented" << endl; fflush(stdout);
	return;
}


//2. ȸ��Ż��
void withdraw(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int index = -1;
	string cmpRRN, cmpID, cmpPassword;
	string RRN, ID, password;

	cout << "Selectd Menu: 2. Unsubscribe from System" << endl;
	if (!loadMode) {
		cout << "ID:"; fflush(stdout);
		cin >> ID;
		cout << "Password:"; fflush(stdout);
		cin >> password;

		index = findIndex(memList, ID, password); // �������Ʈ���� indexã��

		if (index == -1) { // ���Ե��� ���� �����
			cout << "Failure!" << endl;
			inLogWrite << "2 " << ID << " " << password << " " << endl;
			return;
		}

		if (memList.isLogin(index)) { //�α��� �Ǿ� �ִٸ�
			memList.delMem(index); //ȸ�� ����
			cout << "Successfully DELETE Member!" << endl;
			inLogWrite << "2 " << ID << " " << password << " " << endl;
			return;
		}
		else {
			cout << "Failure!" << endl;
			inLogWrite << "2 " << ID << " " << password << " " << endl;
			return;
		}

		
	}
	else {
		if (nTokens != 3)
		{
			cout << "invalid commandLog input format" << endl;
			return;
		}
		ID = tokens[1]; password = tokens[2];

		index = findIndex(memList, ID, password);

		cout << "ID: " << ID << endl;
		cout << "Password:" << password << endl;

		if (index == -1) { // ���Ե��� ���� �����
			cout << "Failure!" << endl;
			return;
		}

		if (memList.isLogin(index)) { //�α��� �Ǿ� �ִٸ�
			memList.delMem(index); //ȸ�� ����
			cout << "Successfully DELETE Member!" << endl;
		}
		else {
			cout << "Failure!" << endl;
			return;
		}

	}
	return;
}

//3. �α���. �ߺ� �α��� �� �ǵ��� ��������. 
void login(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	stringstream stream;
	string ID, password;
	string cmpRRN, cmpID, cmpPassword;
	string line;
	int i = 0;
	int cmp = 0; // �������Ʈ�� ����.
	int index = -1;
	int isLogin = 0; //�α��εǾ� �ִ� ������ �����ϴ°�? ������ 1, ������ 0

	cout << "Selected Menu: 3. Login" << endl;
	if (!loadMode) {
		cout << "ID:"; fflush(stdout);
		cin >> ID;
		cout << "Password:"; fflush(stdout);
		cin >> password;

		index = findIndex(memList, ID, password); // �������Ʈ���� index ã��

		for (i = 0; i < MAX_NUM_MEMBER; i++) {//�α��� �Ǿ��ִ��� Ȯ���Ѵ�.
			if (memList.isLogin(i)) {
				isLogin = 1;
				break;
			}
		}

		if (isLogin) { //�α��� �Ǿ� �ִ� ������ ������ ���� �޽��� ���.
			cout << "Failure: Already Login!" << endl;
			inLogWrite << "3 " << ID << " " << password << " " << endl;
			return;
		}

		if (index != -1) {
			cout << "Login Success!" << endl;
			memList.login(index); // �α��� ���
			inLogWrite << "3 " << ID << " " << password << " " << endl;
			return;
		}
		else {
			cout << "Login Fail!" << endl;
			inLogWrite << "3 " << ID << " " << password << " " << endl;
			return;
		}
	}
	else {
		if (nTokens != 3) {
			cout << "invalid commandLog input format" << endl;
			return;
		}

		ID = tokens[1]; password = tokens[2];

		index = findIndex(memList, ID, password); // �������Ʈ���� indexã��

		cout << "ID: " << ID << endl;
		cout << "Password:" << password << endl;

		for (i = 0; i < MAX_NUM_MEMBER; i++) {//�α��� �Ǿ��ִ��� Ȯ���Ѵ�.
			if (memList.isLogin(i)) {
				isLogin = 1;
				break;
			}
		}

		if (isLogin) { //�α��� �Ǿ� �ִ� ������ ������ ���� �޽��� ���.
			cout << "Failure: Already Login!" << endl;
			return;
		}

		if (index != -1) {
			cout << "Login Success!" << endl;
			memList.login(index); // �α��� ���

			inLogWrite << "3 " << ID << " " << password << " " << endl;
		}
		else {
			cout << "Login Fail!" << endl;
			return;
		}
	}
}

//4. �α׾ƿ�
void logout(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	string RRN, ID, password;
	int index;

	cout << "Selected Menu: 4. Logout" << endl;
	if (!loadMode) {

		index = findIndex(memList); //�α����� ����� index ã��

		if (index == -1) {//�α����� ����� ���ٸ�
			cout << "Fail to Logout - No User" << endl;
			inLogWrite << "4 " << endl; //commandLog.txt�� ����Ѵ�
			return;
		}
		else {
			memList.logout(index); //�α׾ƿ��Ѵ�
			cout << "Logout Success" << endl;

			inLogWrite << "4 " << endl; //commandLog.txt�� ����Ѵ�
			return;
		}
	}
	else {

		if (nTokens != 1) {
			cout << "invalid commandLog input format" << endl;
			return;
		}
		index = findIndex(memList);

		if (index == -1) { //�α����� ����� ���ٸ�
			cout << "Fail to Logout - No User" << endl;
			return;
		}
		else {
			memList.logout(index);//�α׾ƿ��Ѵ�
			cout << "Logout Success" << endl;
		}
	}

	
}

//5. ��ǥ ����
void delVote(vote * votes, memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	string subject;
	int i = 0;
	int success = 0;
	int success2 = 0;
	int index = -1;

	cout << "Selected Menu: 5. Delete Existing Vote Item" << endl;
	if (!loadMode) {
		cout << "Vote Subject to Delete: "; fflush(stdout);
		cin >> subject;

		for (i = 0; i < MAX_NUM_MEMBER; i++) { //�α����� ����� �ִ°�?
			if (memList.isLogin(i)) {
				success = 1; 
				break;
			}
		}

		if (!success) { // �α����� ����� ���ٸ�
			cout << "Failure: Need to Login!" << endl;
			inLogWrite << "5 " << subject << " " << endl;
			return;
		}

		for (i = 0; i < MAX_NUM_VOTE; i++) { //��ǥ ������ ������ �� ������ �ִ� �ε����� ���� �����Ѵ�.
			if (votes[i].delVote(subject)) {
				cout << "Vote Deleted!" << endl;
				inLogWrite << "5 " << subject << " " << endl;
				success2 = 1; //���� ������ ����Ѵ�.
				break;
			}
		}

		if (!success2) // ������ �����ϸ�
		{
			cout << "Failure: There is no that subject!" << endl;
			inLogWrite << "5 " << subject << " " << endl;
			return;
		}
		else // ������ �����ϸ�
		{
			return;
		}

	}
	else {
		if (nTokens != 2) {
			cout << "invalid commandLog input format" << endl;
			return;
		}
		subject = tokens[1];
		cout << "Vote Subject to Delete: " << subject << endl;

		for (i = 0; i < MAX_NUM_MEMBER; i++) { //�α����� ����� �ִ°�?
			if (memList.isLogin(i)) {
				success = 1;
				break;
			}
		}

		if (!success) { // �α����� ����� ���ٸ�
			cout << "Failure: Need to Login!" << endl;
			return;
		}

		for (i = 0; i < MAX_NUM_VOTE; i++) { //��ǥ ������ ������ �� ������ �ִ� �ε����� ���� �����Ѵ�.
			if (votes[i].delVote(subject)) {
				cout << "Vote Deleted!" << endl;
				success2 = 1; //���� ������ ����Ѵ�.
				break;
			}
		}
		if (!success2) // ������ �����ϸ�
			cout << "Failure: There is no that subject!" << endl;
		else
			return;
	}
}

//6. ��ǥ �߰�
void addVote(vote * votes, memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	string RRN, ID, password;
	string subject;
	string tempSubject;

	int i;
	int itemNum;
	int index;
	int indexVote;

	cout << "Selected Menu: 6. Add a New Vote Item" << endl;
	if (!loadMode) {
		cout << "Vote Subject: "; fflush(stdout);
		cin >> subject;
		cout << "Number of Vote Items: "; fflush(stdout);
		cin >> itemNum;

		indexVote = findIndex(votes); //��ǥ�� �ִ� �ε����� ã�´�.
		if (indexVote == -1) { //��ǥ�� ���ٸ�
			cout << "Failure: There is No blank Vote Item Storage!" << endl;
			inLogWrite << "6 " << subject << " " << itemNum << " " << endl;
			return;
		}

		index = findIndex(memList); //�α����� ����� index ã��

		if (index == -1) { //�α��� ����� ����?
			cout << "Failure: No Login User" << endl;
			inLogWrite << "6 " << subject << " " << itemNum << " " << endl;
			return;
		}
		else { //�α����� ����� �ִٸ�
			for (i = 0; i < MAX_NUM_VOTE; i++) { // �ߺ��� �������� �˻��Ѵ�.
				votes[i].whatSubject(tempSubject);
				if (tempSubject == subject) {
					cout << "Failure: Duplicated Subject!" << endl;
					inLogWrite << "6 " << subject << " " << itemNum << " " << endl;
					return;
				}
			}
			votes[indexVote].newVote(subject, itemNum); //��ǥ�� �߰��Ѵ�
			cout << "Vote Added!" << endl;

			inLogWrite << "6 " << subject << " " << itemNum << " " << endl;
			return;
		}
	}
	else {
		if (nTokens != 3) {
			cout << "invalid commandLog input format" << endl;
			return;
		}
		subject = tokens[1]; itemNum = atoi(tokens[2].c_str());

		indexVote = findIndex(votes); //��ǥ�� �ִ� �ε����� ã�´�.
		if (indexVote == -1) { //��ǥ�� ���ٸ�
			cout << "Failure: There is No blank Vote Item Storage!" << endl;
			return;
		}

		index = findIndex(memList); //�α����� ����� index ã��
		if (index == -1) { //�α��� ����� ����?
			cout << "Failure: No Login User" << endl;
			return;
		}
		else { //�α����� ����� �ִٸ�
			cout << "Vote Subject: " << subject << endl;
			cout << "Number of Vote Items: " << itemNum << endl;

			for (i = 0; i < MAX_NUM_VOTE; i++) { // �ߺ��� �������� �˻��Ѵ�.
				votes[i].whatSubject(tempSubject);
				if (tempSubject == subject) {
					cout << "Failure: Duplicated Subject!" << endl;
					return;
				}
			}
			votes[indexVote].newVote(subject, itemNum); //��ǥ�� �߰��Ѵ�
			cout << "Vote Added!" << endl;
		}
	}
}

//7. ��ǥ ��� �����ֱ�
void viewVotes(vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens)
{
	int success = 0;
	int i;
	string tempSub;

	cout << "Selected Menu: 7. List All Vote Items." << endl;
	if (!loadMode) {
		for (i = 0; i < MAX_NUM_MEMBER; i++) {
			if (memList.isLogin(i)) //�α��� �Ǿ��ִ°�
				success = 1;
		}
		if (success == 0) { // �α��� �� �Ǿ����� ��
			cout << "Failure: Is Not Log In" << endl;
			inLogWrite << "7 " << endl;
			return;
		}
		else { //�α��� �Ǿ����� ��, ���������� �����ϴ� ���
			for (i = 0; i < MAX_NUM_MEMBER; i++) {
				if (!votes[i].isCheck())
					continue;

				votes[i].whatSubject(tempSub);
				cout << "Vote Subject: " << tempSub << ", " << "Vote Counts per Item - ";
				votes[i].showListVote();
				cout << endl;
			}
			inLogWrite << "7 " << endl;
			return;
		}
	}
	else {
		if (nTokens != 1) {
			cout << "invalid commandLog input format" << endl;
			return;
		}
		for (i = 0; i < MAX_NUM_MEMBER; i++) {
			if (memList.isLogin(i)) //�α��� �Ǿ��ִ°�
				success = 1;
		}
		if (success == 0) { // �α��� �� �Ǿ����� ��
			cout << "Failure: Is Not Log In" << endl;
			return;
		}
		else { //�α��� �Ǿ����� ��, ���������� �����ϴ� ���
			for (i = 0; i < MAX_NUM_MEMBER; i++) {
				if (!votes[i].isCheck())
					continue;

				votes[i].whatSubject(tempSub);
				cout << "Vote Subject: " << tempSub << ", " << "Vote Counts per Item - ";
				votes[i].showListVote();
				cout << endl;
			}
		}
	}
}

//8. ��ǥ�ϱ�
void castVote(listOfVoters &vteList, vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens)
{
	string subject; //��ǥ�� ����
	string tempSub;
	string tempRRN, tempID, tempPassword;
	int item; // ��ǥ�� �׸��� ��ȣ
	int i;
	int index = -1;
	int memIndex = -1;
	int success = 0;
	int success2 = 0;

	cout << "Selected Menu: 8. Cast a Vote" << endl;
	if (!loadMode) { //�ε��尡 �ƴ϶��

		cout << "Vote Subject: "; fflush(stdout);
		cin >> subject;
		cout << "Vote for: "; fflush(stdout);
		cin >> item;

		for (i = 0; i < MAX_NUM_MEMBER; i++) { //�α��� �Ǿ��ֳ�?
			if (memList.isLogin(i))
			{
				success = 1;
				memIndex = i; // �α����� ����� �����ΰ�?
				break;
			}
		}
		if (!success) { // �α��� �� �Ǿ� ������ ���� �޽��� ��� �� ����
			cout << "Failure: Need to Login!" << endl;
			inLogWrite << "8 " << subject << " " << item << " " << endl;
			return;
		}
		else { // �α��� �Ǿ� �ִٸ�
			for (i = 0; i < MAX_NUM_VOTE; i++) { //�Է¹��� ������ �����ϴ��� �˻�
				votes[i].whatSubject(tempSub);
				if (tempSub == subject) {
					success2 = 1;
					index = i; // ������ �����ϴ� ĭ�� ����ΰ�?
					break;
				}
			}
			if (!success2) { // ���� ��ǥ ������� ���� �޽��� ��� �� ����
				cout << "Failure: There is no Vote Subject!" << endl;
				inLogWrite << "8 " << subject << " " << item << " " << endl;
				return;
			}
			else { // �ִ� ��ǥ �������
				memList.whatMemListValues(memIndex, tempRRN, tempID, tempPassword); // ��ǥ�ϴ� ����� ����(RRN)�� �޾ƿ´�.
				if (vteList.isVote(tempRRN)) { // �̹� ��ǥ�� RRN �̶��
					cout << "Failure: RRN already has been voted!" << endl;
					inLogWrite << "8 " << subject << " " << item << " " << endl;
					return;
				}
				else {
					votes[index].doVote(item); // ��ǥ�Ѵ�.
					vteList.logVoter(tempRRN); // ��ǥ�� ����� RRN�� ����Ѵ�.
					inLogWrite << "8 " << subject << " " << item << " " << endl;
					cout << "Request processed successfully!" << endl;
					return;
				}
			}
		}
	}
	else { //�ε�����
		if (nTokens != 3) {
			cout << "invalid commandLog input format" << endl;
			return;
		}
		subject = tokens[1]; item = atoi(tokens[2].c_str()); //���� ����
		cout << "Vote Subject: " << subject << endl;
		cout << "Vote for: " << item << endl;
	
		for (i = 0; i < MAX_NUM_MEMBER; i++) { //�α��� �Ǿ��ֳ�?
			if (memList.isLogin(i))
			{
				success = 1;
				memIndex = i; // �α����� ����� �����ΰ�?
				break;
			}
		}
		if (!success) { // �α��� �� �Ǿ� ������ ���� �޽��� ��� �� ����
			cout << "Failure: Need to Login!" << endl;
			return;
		}
		else { // �α��� �Ǿ� �ִٸ�
			for (i = 0; i < MAX_NUM_VOTE; i++) { //�Է¹��� ������ �����ϴ��� �˻�
				votes[i].whatSubject(tempSub);
				if (tempSub == subject) {
					success2 = 1;
					index = i; // ������ �����ϴ� ĭ�� ����ΰ�?
					break;
				}
			}
			if (!success2) { // ���� ��ǥ ������� ���� �޽��� ��� �� ����
				cout << "Failure: There is no Vote Subject!" << endl;
				return;
			}
			else { // �ִ� ��ǥ �������
				memList.whatMemListValues(memIndex, tempRRN, tempID, tempPassword); // ��ǥ�ϴ� ����� ����(RRN)�� �޾ƿ´�.
				if (vteList.isVote(tempRRN)) { // �̹� ��ǥ�� RRN �̶��
					cout << "Failure: RRN already has been voted!" << endl;
					return;
				}
				else {
					votes[index].doVote(item); // ��ǥ�Ѵ�.
					vteList.logVoter(tempRRN); // ��ǥ�� ����� RRN�� ����Ѵ�.
					cout << "Request processed successfully!" << endl;
				}//RRN üũ
			}//��ǥ ���� ���� ����
		}//�α��� ����
	}//�ε��� else
}
