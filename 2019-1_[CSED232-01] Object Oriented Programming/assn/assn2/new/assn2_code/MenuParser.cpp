#include "default.h"
using namespace std;
void join(int loadMode, ifstream & inLogRead, ofstream & inLogWrite,string *tokens, int nTokens);
void logout(int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens);
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
	cout << "\n\n=======================" << endl;fflush(stdout);
	cout << "Num:"<<num << endl;fflush(stdout);
	cout << "n=======================" << endl;fflush(stdout);
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
	
	int menu = 0;
	int num=1;
	int loadMode;
	ofstream inLogWrite;
	ifstream inLogRead;
	string tokens[4], line; 
	stringstream stream;
	int nTokens=0; //number of tokens in string
	int tmp=10;
	
	
	
	loadMode = printMenu1();
	if (!loadMode) {
		inLogWrite.open(COMMAND_LOG_FILE_NAME, ios::out);
	}
	else {
		inLogRead.open(COMMAND_LOG_FILE_NAME,ios::in); //read mode
		inLogWrite.open(COMMAND_LOG_FILE_NAME, ios::in|ios::app); //concat without truncation
	}
	
	while (1)
	{
		printMenu2(num++);
		if (loadMode==1)
		{
			getline(inLogRead, line);
			if(line =="")
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
						cout<<"Selected Menu: Undefined menu selection" << endl;fflush(stdout);
						continue;
					}
					menu = atoi(line.c_str());
				}
				//middle of file with new line
				//continue without logging
				else
				{
					cout<<"\nSelected Menu: Undefined menu selection" << endl;fflush(stdout);
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
				cout <<menu << endl; fflush(stdout);
			}
			
			
		}
		//stdin mode
		else
		{
			getline(cin, line);
			if (line == "")
			{
				cout<<"Selected Menu: Undefined menu selection" << endl;fflush(stdout);
				continue;
			}
			menu = atoi(line.c_str());
		}
		
		// 메뉴 구분 및 해당 연산 수행
		switch (menu)
		{
		case 1:
		{	
			join(loadMode,inLogRead,inLogWrite,tokens,nTokens);
			break;
		}
		case 4:
		{
			logout(loadMode, inLogRead, inLogWrite, tokens, nTokens);
			break;
		}

		case 9:
		{
			
			inLogWrite.close();
			return;
		
		}
		default:
			cout<<"Selected Menu: Undefined menu selection" << endl;fflush(stdout);
			if (!loadMode) {
				inLogWrite << menu<< endl;
				continue;
			}
			break;
			
		}
		if (!loadMode &&(menu!=4 && menu!=7)) {
			getchar();
		}
	}
	return;
}

//1. 회원가입
void join(int loadMode,ifstream & inLogRead, ofstream & inLogWrite,string *tokens,int nTokens)
{
	//회원가입에대한 정보를 입력받을 문자열변수
	string RRN, ID, password;
	cout << "Selected Menu: 1. Register as a Member" << endl;fflush(stdout);

	if (!loadMode)
	{
		cout<<"Resident Registration Number:"; fflush(stdout);
		cin >> RRN;
		cout<<"ID:";fflush(stdout);
		cin >> ID;
		cout << "Password:";fflush(stdout);
		cin >> password;
		inLogWrite << "1 " << RRN << " " << ID << " " << password << " " << endl;
	}
	else {
		RRN = tokens[1]; ID = tokens[2]; password = tokens[3];
		cout << "1. Resident Registration Number: " << RRN << endl;fflush(stdout);
		cout << "ID: " << ID << endl;fflush(stdout);
		cout << "Password:" << password << endl;fflush(stdout);
	}

	cout <<"Unimplemented"<<endl;fflush(stdout);
	return;
	/*
	
	Fill this in
	
	
	*/
}
void logout(int loadMode, ifstream & inLogRead, ofstream & inLogWrite, string *tokens, int nTokens)
{
	//회원가입에대한 정보를 입력받을 문자열변수
	string RRN, ID, password;
	cout << "Selected Menu: 4. Logout" << endl;fflush(stdout);

	if (!loadMode)
	{
		inLogWrite << "4" << endl;
	}
	else {
		
	}
	cout << "Unimplemented!" << endl;fflush(stdout);
	return;
	/*
	
	Fill this in
	
	*/
	

}