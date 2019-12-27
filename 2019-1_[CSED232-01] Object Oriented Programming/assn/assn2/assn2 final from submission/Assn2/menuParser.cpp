/*
학번: 20180551
이름: 이준석
povis ID: ljs9904ljs

명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
*/



#include "default.h"
using namespace std;

class memberInfo { // 멤버 개개인의 정보를 저장하는 class
private:
	string RRN = "";
	string ID = "";
	string password = "";
	int login = 0; // 로그인 되어 있으면 1, 안 되어 있으면 0
	int reg = 0; // 등록 되어 있으면 1, 안 되어 있으면 0
	int isVote = 0; // 투표 했으면 1, 안 했으면 0
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

class memberCollection { // 멤버들의 집합을 관리하는 class
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
	void whatMemListValues(int index, string & RRN, string & ID, string & password) { // 저장되어 있는 rrn, id, password를 알려준다.
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
	int isLogin(int index) { // 로그인 1, 로그아웃 0
		if (index == -1) {
			cout << "목록에 없는 사람입니다." << endl;
			return 0;
		}
		else
			return memberList[index].logState();

	}
	int isRegister(int index) { // 사람 정보가 있으면 1, 없으면 0
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

class vote {//투표 자체에 관련한 정보를 처리하는 class
private:
	string voteSubject = ""; // 투표 주제
	string voteItem[MAX_NUM_VOTEITEM] = { "item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10" }; // 투표 항목
	int voteNum[MAX_NUM_VOTEITEM]; // 투표 항목 당 투표 수
	int howManyItems = 0; // 투표 항목의 수
	int check = 0; // 투표가 존재하나 안 하나? 0이면 없고 1이면 있다
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
	int delVote(string subject) { 
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
			cout << "목록에 없는 항목에 투표하셨습니다." << endl;
		else
			voteNum[item - 1]++;
	}
};

class listOfVoters { // 투표한 사람의 RRN을 기록하는 class
private:
	string voterList[MAX_NUM_MEMBER]; // 최대 멤버 수만큼의 크기를 갖는 배열 생성
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

		for (i = 0; i < MAX_NUM_MEMBER; i++) { // 배열의 비어있는 칸을 찾는다.
			if (voterList[i] == "") {
				index = i;
				break;
			}
		}
		voterList[index] = RRN; //비어있는 칸에 RRN 저장
	}
	int isVote(string &RRN) {
		int i;
		int success = 0;

		for (i = 0; i < MAX_NUM_MEMBER; i++) {
			if (voterList[i] == RRN) {
				success = 1; // 이미 투표한 RRN이다.
			}
		}
		return success;
	}
};

//순서대로 1번 메뉴부터 8번 메뉴까지
void join(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void withdraw(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void login(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void logout(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void delVote(vote * votes, memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void addVote(vote * votes, memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
void viewVotes(vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens);
void castVote(listOfVoters &vteList, vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens);




//메뉴 1번, RRN과 ID로 중복 검사         
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
// 아이디랑 비밀번호로 index 찾기
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
	return index; //존재하지 않는 멤버라면 -1리턴
}
// 로그인한 사용자의 index 찾기
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
	return index; //로그인한 사용자가 없으면 -1리턴
}
// votes[]의 비어있는 칸의 index를 찾는다.
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
	return index; // 비어있는 칸이 없으면 -1리턴
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
	int isLoginUser = 0; //로그인한 유저가 있으면 1, 없으면 0
	string userID, userPassword; //로그인한 유저의 아이디, 비밀번호
	vote votes[MAX_NUM_VOTE];
	listOfVoters vteList; // 투표한 사람들의 목록
	vteList.iniVoterList(); // vteList 배열의 초기화


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

		// 메뉴 구분 및 해당 연산 수행
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

//1. 회원가입
void join(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	//회원가입에대한 정보를 입력받을 문자열변수
	string RRN, ID, password;
	cout << "Selected Menu: 1. Register as a Member" << endl; fflush(stdout);

	int index, i;

	for (i = 0; i < MAX_NUM_MEMBER; i++) {
		if (!memList.isRegister(i)) { //사람 정보가 저장되어 있지 않은 memList의 index로 가서 등록하려는 사람의 정보를 저장할 것이다.
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

		//중복 검사
		if (!overlapTest(memList, RRN, ID)) {
			cout << "Invalid Registration Attempt!" << endl;
			inLogWrite << "1 " << RRN << " " << ID << " " << password << " " << endl;  // 실패 케이스도 기록한다. *****
			return;
		}
		memList.addMem(index, RRN, ID, password); //memList에 member 추가
		memList.regi(index); //등록됐음을 표시한다
		cout << "Registration Success!" << endl;
		inLogWrite << "1 " << RRN << " " << ID << " " << password << " " << endl;
		return;
	}
	else {
		RRN = tokens[1]; ID = tokens[2]; password = tokens[3];
		cout << "1. Resident Registration Number: " << RRN << endl; fflush(stdout);
		cout << "ID: " << ID << endl; fflush(stdout);
		cout << "Password:" << password << endl; fflush(stdout);

		//중복 검사
		if (!overlapTest(memList, RRN, ID)) {
			cout << "Invalid Registration Attempt!" << endl;
			return;
		}

		memList.addMem(index, RRN, ID, password); //memList에 member 추가
		memList.regi(index); //등록됨
		cout << "Registration Success!" << endl;
		return;
	}

	cout << "Unimplemented" << endl; fflush(stdout);
	return;
}


//2. 회원탈퇴
void withdraw(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	int index = -1;
	string cmpRRN, cmpID, cmpPassword;
	string RRN, ID, password;

	cout << "Selectd Menu: 2. Unsubscribe from System" << endl;
	if (!loadMode) {//loadmode가 아니라면
		cout << "ID:"; fflush(stdout);
		cin >> ID;
		cout << "Password:"; fflush(stdout);
		cin >> password;

		index = findIndex(memList, ID, password); // ID와 password를 가지고 멤버리스트에서 index찾기

		if (index == -1) { // 가입되어 있지 않은 사용자라면
			cout << "Failure!" << endl;
			inLogWrite << "2 " << ID << " " << password << " " << endl;
			return;
		}

		if (memList.isLogin(index)) { //로그인 되어 있다면
			memList.delMem(index); //회원 탈퇴한다.
			cout << "Successfully DELETE Member!" << endl;
			inLogWrite << "2 " << ID << " " << password << " " << endl;
			return;
		}
		else { // 로그인이 되어 있지 않으면
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

		if (index == -1) { // 가입되어 있지 않은 사용자
			cout << "Failure!" << endl;
			return;
		}

		if (memList.isLogin(index)) { //로그인 되어 있다면
			memList.delMem(index); //회원 탈퇴
			cout << "Successfully DELETE Member!" << endl;
		}
		else {
			cout << "Failure!" << endl;
			return;
		}

	}
	return;
}

//3. 로그인. 이미 한 사람이 로그인 되어 있다면 또 로그인을 할 수 없다.
void login(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	stringstream stream;
	string ID, password;
	string cmpRRN, cmpID, cmpPassword;
	string line;
	int i = 0;
	int cmp = 0; // 멤버리스트에 없다.
	int index = -1; // index가 -1이라면 찾지 못한 것이거나 없는 것이다.
	int isLogin = 0; //로그인되어 있는 유저가 존재하는가? 있으면 1, 없으면 0

	cout << "Selected Menu: 3. Login" << endl;
	if (!loadMode) {
		cout << "ID:"; fflush(stdout);
		cin >> ID;
		cout << "Password:"; fflush(stdout);
		cin >> password;

		index = findIndex(memList, ID, password); // ID와 password로 멤버리스트에서 index 찾기

		for (i = 0; i < MAX_NUM_MEMBER; i++) {//로그인 되어있는지 확인한다.
			if (memList.isLogin(i)) {
				isLogin = 1;
				break;
			}
		}

		if (isLogin) { //로그인 되어 있는 유저가 있으면 실패 메시지 출력.
			cout << "Failure: Already Login!" << endl;
			inLogWrite << "3 " << ID << " " << password << " " << endl;
			return;
		}

		if (index != -1) {
			cout << "Login Success!" << endl;
			memList.login(index); // 로그인 기록
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

		index = findIndex(memList, ID, password); // 멤버리스트에서 index찾기

		cout << "ID: " << ID << endl;
		cout << "Password:" << password << endl;

		for (i = 0; i < MAX_NUM_MEMBER; i++) {//로그인 되어있는지 확인한다.
			if (memList.isLogin(i)) {
				isLogin = 1;
				break;
			}
		}

		if (isLogin) { //로그인 되어 있는 유저가 있으면 실패 메시지 출력.
			cout << "Failure: Already Login!" << endl;
			return;
		}

		if (index != -1) {
			cout << "Login Success!" << endl;
			memList.login(index); // 로그인 기록
		}
		else {
			cout << "Login Fail!" << endl;
			return;
		}
	}
}

//4. 로그아웃
void logout(memberCollection &memList, int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	string RRN, ID, password;
	int index;

	cout << "Selected Menu: 4. Logout" << endl;
	if (!loadMode) {

		index = findIndex(memList); //로그인한 사용자 index 찾기

		if (index == -1) {//로그인한 사람이 없다면
			cout << "Fail to Logout - No User" << endl;
			inLogWrite << "4 " << endl; //commandLog.txt에 기록한다
			return;
		}
		else { //로그인한 사람이 있다면
			memList.logout(index); //로그아웃한다
			cout << "Logout Success" << endl;

			inLogWrite << "4 " << endl; //commandLog.txt에 기록한다
			return;
		}
	}
	else {

		if (nTokens != 1) {
			cout << "invalid commandLog input format" << endl;
			return;
		}
		index = findIndex(memList);

		if (index == -1) { //로그인한 사람이 없다면
			cout << "Fail to Logout - No User" << endl;
			return;
		}
		else { //로그인한 사람이 있다면
			memList.logout(index);//로그아웃한다
			cout << "Logout Success" << endl;
		}
	}

	
}

//5. 투표 삭제
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

		for (i = 0; i < MAX_NUM_MEMBER; i++) { //로그인한 멤버가 있는가?
			if (memList.isLogin(i)) {
				success = 1; 
				break;
			}
		}

		if (!success) { // 로그인한 멤버가 없다면
			cout << "Failure: Need to Login!" << endl;
			inLogWrite << "5 " << subject << " " << endl;
			return;
		}

		for (i = 0; i < MAX_NUM_VOTE; i++) { //투표 주제를 가지고 그 주제가 있는 인덱스로 가서 삭제한다.
			if (votes[i].delVote(subject)) {
				cout << "Vote Deleted!" << endl;
				inLogWrite << "5 " << subject << " " << endl;
				success2 = 1; //삭제 성공을 기록한다.
				break;
			}
		}

		if (!success2) // 삭제를 실패하면
		{
			cout << "Failure: There is no that subject!" << endl;
			inLogWrite << "5 " << subject << " " << endl;
			return;
		}
		else // 삭제를 성공하면
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

		for (i = 0; i < MAX_NUM_MEMBER; i++) { //로그인한 멤버가 있는가?
			if (memList.isLogin(i)) {
				success = 1;
				break;
			}
		}

		if (!success) { // 로그인한 멤버가 없다면
			cout << "Failure: Need to Login!" << endl;
			return;
		}

		for (i = 0; i < MAX_NUM_VOTE; i++) { //투표 주제를 가지고 그 주제가 있는 인덱스로 가서 삭제한다.
			if (votes[i].delVote(subject)) {
				cout << "Vote Deleted!" << endl;
				success2 = 1; //삭제 성공을 기록한다.
				break;
			}
		}
		if (!success2) // 삭제를 실패하면
			cout << "Failure: There is no that subject!" << endl;
		else
			return;
	}
}

//6. 투표 추가
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

		indexVote = findIndex(votes); //투표가 있는 인덱스를 찾는다.
		if (indexVote == -1) { //투표가 없다면
			cout << "Failure: There is No blank Vote Item Storage!" << endl;
			inLogWrite << "6 " << subject << " " << itemNum << " " << endl;
			return;
		}

		index = findIndex(memList); //로그인한 사용자 index 찾기

		if (index == -1) { //로그인 사람이 없나?
			cout << "Failure: No Login User" << endl;
			inLogWrite << "6 " << subject << " " << itemNum << " " << endl;
			return;
		}
		else { //로그인한 사람이 있다면
			for (i = 0; i < MAX_NUM_VOTE; i++) { // 중복된 주제인지 검사한다.
				votes[i].whatSubject(tempSubject);
				if (tempSubject == subject) {
					cout << "Failure: Duplicated Subject!" << endl;
					inLogWrite << "6 " << subject << " " << itemNum << " " << endl;
					return;
				}
			}
			votes[indexVote].newVote(subject, itemNum); //투표를 추가한다
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

		indexVote = findIndex(votes); //투표가 있는 인덱스를 찾는다.
		if (indexVote == -1) { //투표가 없다면
			cout << "Failure: There is No blank Vote Item Storage!" << endl;
			return;
		}

		index = findIndex(memList); //로그인한 사용자 index 찾기
		if (index == -1) { //로그인 사람이 없나?
			cout << "Failure: No Login User" << endl;
			return;
		}
		else { //로그인한 사람이 있다면
			cout << "Vote Subject: " << subject << endl;
			cout << "Number of Vote Items: " << itemNum << endl;

			for (i = 0; i < MAX_NUM_VOTE; i++) { // 중복된 주제인지 검사한다.
				votes[i].whatSubject(tempSubject);
				if (tempSubject == subject) {
					cout << "Failure: Duplicated Subject!" << endl;
					return;
				}
			}
			votes[indexVote].newVote(subject, itemNum); //투표를 추가한다
			cout << "Vote Added!" << endl;
		}
	}
}

//7. 투표 목록 보여주기
void viewVotes(vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens)
{
	int success = 0;
	int i;
	string tempSub;

	cout << "Selected Menu: 7. List All Vote Items." << endl;
	if (!loadMode) {
		for (i = 0; i < MAX_NUM_MEMBER; i++) {
			if (memList.isLogin(i)) //로그인 되어있는가
				success = 1;
		}
		if (success == 0) { // 로그인 안 되어있을 때
			cout << "Failure: Is Not Log In" << endl;
			inLogWrite << "7 " << endl;
			return;
		}
		else { //로그인 되어있을 때, 성공적으로 수행하는 경우
			for (i = 0; i < MAX_NUM_MEMBER; i++) {
				if (!votes[i].isCheck())
					continue;

				votes[i].whatSubject(tempSub);
				cout << "Vote Subject: " << tempSub << ", " << "Vote Counts per Item - "; //투표 목록을 보여준다.
				votes[i].showListVote(); //투표 목록을 보여준다.
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
			if (memList.isLogin(i)) //로그인 되어있는가
				success = 1;
		}
		if (success == 0) { // 로그인 안 되어있을 때
			cout << "Failure: Is Not Log In" << endl;
			return;
		}
		else { //로그인 되어있을 때, 성공적으로 수행하는 경우
			for (i = 0; i < MAX_NUM_MEMBER; i++) {
				if (!votes[i].isCheck())
					continue;

				votes[i].whatSubject(tempSub);
				cout << "Vote Subject: " << tempSub << ", " << "Vote Counts per Item - "; //투표 목록을 보여준다
				votes[i].showListVote(); //투표 목록을 보여준다
				cout << endl;
			}
		}
	}
}

//8. 투표하기
void castVote(listOfVoters &vteList, vote*votes, memberCollection &memList, int loadMode, ofstream &inLogWrite, string *tokens, int nTokens)
{
	string subject; //투표할 주제
	string tempSub;
	string tempRRN, tempID, tempPassword;
	int item; // 투표할 항목의 번호
	int i;
	int index = -1;
	int memIndex = -1;
	int success = 0;
	int success2 = 0;

	cout << "Selected Menu: 8. Cast a Vote" << endl;
	if (!loadMode) { //로드모드가 아니라면

		cout << "Vote Subject: "; fflush(stdout);
		cin >> subject;
		cout << "Vote for: "; fflush(stdout);
		cin >> item;

		for (i = 0; i < MAX_NUM_MEMBER; i++) { //로그인 되어있나?
			if (memList.isLogin(i))
			{
				success = 1;
				memIndex = i; // 로그인한 사람이 누구인가?
				break;
			}
		}
		if (!success) { // 로그인 안 되어 있으면 오류 메시지 출력 후 종료
			cout << "Failure: Need to Login!" << endl;
			inLogWrite << "8 " << subject << " " << item << " " << endl;
			return;
		}
		else { // 로그인 되어 있다면
			for (i = 0; i < MAX_NUM_VOTE; i++) { //입력받은 주제가 존재하는지 검사
				votes[i].whatSubject(tempSub);
				if (tempSub == subject) {
					success2 = 1;
					index = i; // 주제가 존재하는 칸이 어디인가?
					break;
				}
			}
			if (!success2) { // 없는 투표 주제라면 오류 메시지 출력 후 종료
				cout << "Failure: There is no Vote Subject!" << endl;
				inLogWrite << "8 " << subject << " " << item << " " << endl;
				return;
			}
			else { // 있는 투표 주제라면
				memList.whatMemListValues(memIndex, tempRRN, tempID, tempPassword); // 투표하는 사람의 정보(RRN)를 받아온다.
				if (vteList.isVote(tempRRN)) { // 이미 투표한 RRN 이라면
					cout << "Failure: RRN already has been voted!" << endl;
					inLogWrite << "8 " << subject << " " << item << " " << endl;
					return;
				}
				else {
					votes[index].doVote(item); // 투표한다.
					vteList.logVoter(tempRRN); // 투표한 사람의 RRN을 기록한다.
					inLogWrite << "8 " << subject << " " << item << " " << endl;
					cout << "Request processed successfully!" << endl;
					return;
				}
			}
		}
	}
	else { //로드모드라면
		if (nTokens != 3) {
			cout << "invalid commandLog input format" << endl;
			return;
		}
		subject = tokens[1]; item = atoi(tokens[2].c_str()); //값을 저장
		cout << "Vote Subject: " << subject << endl;
		cout << "Vote for: " << item << endl;
	
		for (i = 0; i < MAX_NUM_MEMBER; i++) { //로그인 되어있나?
			if (memList.isLogin(i))
			{
				success = 1;
				memIndex = i; // 로그인한 사람이 누구인가?
				break;
			}
		}
		if (!success) { // 로그인 안 되어 있으면 오류 메시지 출력 후 종료
			cout << "Failure: Need to Login!" << endl;
			return;
		}
		else { // 로그인 되어 있다면
			for (i = 0; i < MAX_NUM_VOTE; i++) { //입력받은 주제가 존재하는지 검사
				votes[i].whatSubject(tempSub);
				if (tempSub == subject) {
					success2 = 1;
					index = i; // 주제가 존재하는 칸이 어디인가?
					break;
				}
			}
			if (!success2) { // 없는 투표 주제라면 오류 메시지 출력 후 종료
				cout << "Failure: There is no Vote Subject!" << endl;
				return;
			}
			else { // 있는 투표 주제라면
				memList.whatMemListValues(memIndex, tempRRN, tempID, tempPassword); // 투표하는 사람의 정보(RRN)를 받아온다.
				if (vteList.isVote(tempRRN)) { // 이미 투표한 RRN 이라면
					cout << "Failure: RRN already has been voted!" << endl;
					return;
				}
				else {
					votes[index].doVote(item); // 투표한다.
					vteList.logVoter(tempRRN); // 투표한 사람의 RRN을 기록한다.
					cout << "Request processed successfully!" << endl;
				}//RRN 체크
			}//투표 주제 존재 여부
		}//로그인 여부
	}//로드모드 else
}

