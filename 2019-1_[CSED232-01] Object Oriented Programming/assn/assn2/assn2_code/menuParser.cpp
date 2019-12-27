#include "default.h"
using namespace std;

//class 생성
/*
class memberInfo {
private:
	string RRN;
	string ID;
	string password;
public:
	getRRN()


}; */








void join(int loadMode, ifstream & inLogRead, ofstream & inLogWrite,string *tokens, int nTokens); // 함수 내용 수정하기 *******************@%#$@#$^******************************************%^$%^#$^@#$%@










int printMenu1()
{
	string line;
	int loadMode;
	cout << "Load log file?(1:yes, 0:no (log will be deleted)):"; fflush(stdout);
	getline(cin, line);
	loadMode = atoi(line.c_str());
	return loadMode;
}
void printMenu2()
{
	cout << "\n\n=======================" << endl;fflush(stdout);
	cout << "1. Register as a Member" << endl;fflush(stdout);
	cout << "2. Unsubscribe from System" << endl;fflush(stdout);
	cout << "3. Login" << endl;fflush(stdout);
	cout << "4. Logout" << endl;fflush(stdout);
	cout << "5. Delete Existing Vote Item"<<endl;fflush(stdout);
	cout << "6. Add a New Vote Item" << endl;fflush(stdout);
	cout << "7. List All Vote Items" << endl;fflush(stdout);
	cout << "8. Cast a Vote" << endl;fflush(stdout);
	cout << "9. Program Exit" << endl;fflush(stdout);
	cout << "=======================" << endl;fflush(stdout);
	cout << "Select Menu:";fflush(stdout);
}
void clearTokens(string * tokens)
{
	for (int i = 0; i < 4; i++)
		tokens[i].clear();
}

void doTask()
{
	//설명: 메인함수의 작업부분이다. 메뉴를 파싱하여 명령에 맞는 작업을 진행한다.
	// 메뉴 파싱을 위한 변수
	int menu = 0;
	int loadMode;
	ofstream inLogWrite;
	ifstream inLogRead;
	string tokens[4], line; 
	stringstream stream;
	int nTokens=0; //number of tokens in string

	/*

		멤버 콜렉션 클래스 인스턴스에대한 선언,및 할당,
		현재작업중인 멤버를 생성 등 필요한 코드 작성

	*/


	loadMode = printMenu1();
	if (!loadMode) {
		inLogWrite.open(COMMAND_LOG_FILE_NAME, ios::out);
	}
	else {
		inLogRead.open(COMMAND_LOG_FILE_NAME,ios::in); //read mode
		inLogWrite.open(COMMAND_LOG_FILE_NAME, ios::in|ios::app); //concat without truncation
	}

	// 종료 메뉴(9)가 입력되기 전까지 반복함
	while (menu !=9)
	{
		//Menu Parsing
		printMenu2();
		// 입력파일에서 메뉴 숫자 읽기
		if (loadMode==1)
		{
			if (inLogRead.eof())
			{
				inLogRead.close();
				loadMode = 0;
				getline(cin, line);
				menu = atoi(line.c_str());
				cout <<menu<<endl;
			}
			else
			{
				getline(inLogRead, line);
				stream.str(line);
				nTokens = 0;
				clearTokens(tokens);
				//Read all tokens(seperated by " ")
				while (stream >> tokens[nTokens]) {
					nTokens++;
				}

				stream.clear();
				menu = atoi(tokens[0].c_str());
				cout <<menu<<endl;
			}
		}
		else
		{
			getline(cin, line);
			menu = atoi(line.c_str());
			cout <<menu<<endl;
		}
		
		// 메뉴 구분 및 해당 연산 수행
		switch (menu)
		{
		case 1:
		{	
			join(loadMode,inLogRead,inLogWrite,tokens,nTokens);
			break;
		}
		/*

			선택된 메뉴별 기능 수행

		*/
		case 9:
		{
			
			inLogWrite.close();
			return;
		
		}
		default:
			cout << "Undefined menu selection" << endl;
			break;
			
		}
		if (!loadMode) {
			getchar();
		}
	}
	return;
}

int overlapTest(ifstream &inLogRead, string RRN, string ID, string password) //메뉴 1번, 중복 검사
{
	string line;
	char lft[300]; // Line For Tokenizing
	char *menuNumLog, *rrnLog, *idLog, *pwdLog;
	int success = 1; // 중복 검사를 통과하면 1, 중복됐으면 0

	while (!inLogRead.eof()) // 파일의 끝까지 돌리는게 이게 맞나????????????????????????      ???????      ???????        ??????????????       ????????     ??????????????????
	{
		getline(inLogRead, line); // txt파일의 첫 줄을 받는다.
		strcpy(lft, line.c_str()); // 토크나이징을 위해서

		menuNumLog = strtok(lft, " "); // 메뉴 번호
		rrnLog = strtok(lft, " "); // 주민 등록 번호
		idLog = strtok(lft, " "); // ID
		pwdLog = strtok(lft, " "); // Password

		if (atoi(menuNumLog) == 1) {
			if (RRN == rrnLog || ID == idLog) { // string과 char[] 비교 가능???????????????????????      ???????      ???????        ??????????????       ????????     ??????????????????
				success = 0;
			}
		}
	}
	return success;
}

//1. 회원가입
void join(int loadMode,ifstream & inLogRead, ofstream & inLogWrite,string *tokens,int nTokens)
{
	//회원가입에대한 정보를 입력받을 문자열변수
	string RRN, ID, password;
	//commandLog파일로 부터 한 줄 씩 정보를 입력받을 문자열 변수
	string line;


	cout << "Selected Menu: 1. Register as a Member" << endl;
	if (!loadMode)
	{
		

		cout<<"Resident Registration Number:"; fflush(stdout);
		cin >> RRN;
		
		cout<<"ID:";fflush(stdout);
		cin >> ID;

		cout << "Password:";fflush(stdout);
		cin >> password;

		//중복 검사
		if (!overlapTest(inLogRead, RRN, ID, password)) {
			cout << "invalid registration attempt!" << endl;
			return;
		}

		inLogWrite << "1 " << RRN << " " << ID << " " << password << " " << endl;
	}
	else {
		if (nTokens != 4)
		{
			cout << "invalid commandLog input format" << endl;
			return;
		}
		RRN = tokens[1]; ID = tokens[2]; password = tokens[3];
		
		//중복 검사
		if (!overlapTest(inLogRead, RRN, ID, password)) {
			cout << "invalid registration attempt!" << endl;
			return;
		}
		cout << "1. Resident Registration Number: " << RRN << endl;
		cout << "ID: " << ID << endl;
		cout << "Password:" << password << endl;
	}

	//cout << "Not Implemented" << endl;
	
}

//2. Unsubscribe from system

