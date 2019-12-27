/*
�й�: 20180551
�̸�: ���ؼ�
povis ID: ljs9904ljs

������(Honor code)

������ �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.��
*/

#include "default.h"


//�޴� ��� ���

int printMenu1()
{
	string line;
	int loadMode;
	cout << "Load log file?(1:yes, 0:no (log will be deleted)):"; fflush(stdout);
	cin >> loadMode; getchar();
	//cin >> line;
	//getline(cin, line);
	//loadMode = atoi(line.c_str());
	//const char* tmp = line.c_str();
	return loadMode;
}
void printMenu2(int num)
{
	cout << "\n\n=======================" << endl; fflush(stdout);
	cout << "Num:" << num << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "1.1 Register as a Member" << endl; fflush(stdout);
	cout << "1.2 Login" << endl; fflush(stdout);
	cout << "1.3 Program Exit" << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "Select Menu:"; fflush(stdout);
}

void printMenu3(int num)
{
	cout << "\n\n=======================" << endl; fflush(stdout);
	cout << "Num:" << num << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "2.1 Logout" << endl; fflush(stdout);
	cout << "2.2 Unsubscribe from System" << endl; fflush(stdout);
	cout << "2.3 Delete Existing Vote Item" << endl; fflush(stdout);
	cout << "2.4 Add a Vote Item" << endl; fflush(stdout);
	cout << "2.5 List All Vote Items" << endl; fflush(stdout);
	cout << "2.6 Cast a Vote" << endl; fflush(stdout);
	cout << "2.7 Join Group" << endl; fflush(stdout);
	cout << "2.8 Create a Group" << endl; fflush(stdout);
	cout << "2.9 Program Exit" << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "Select Menu:"; fflush(stdout);
}

void printMenu4(int num)
{
	cout << "\n\n=======================" << endl; fflush(stdout);
	cout << "Num:" << num << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "3.1 Logout" << endl; fflush(stdout);
	cout << "3.2 Unsubscribe from System" << endl; fflush(stdout);
	cout << "3.3 Delete Existing Vote Item" << endl; fflush(stdout);
	cout << "3.4 Add a New Vote Item" << endl; fflush(stdout);
	cout << "3.5 List All Vote Items" << endl; fflush(stdout);
	cout << "3.6 Cast a Vote" << endl; fflush(stdout);
	cout << "3.7 Unsubscribe from Group" << endl; fflush(stdout);
	cout << "3.8 Program Exit" << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "Select Menu:"; fflush(stdout);
}

void printMenu5(int num)
{
	cout << "\n\n=======================" << endl; fflush(stdout);
	cout << "Num:" << num << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "4.1 Logout" << endl; fflush(stdout);
	cout << "4.2 Delete Existing Vote Item" << endl; fflush(stdout);
	cout << "4.3 Add a New Vote Item" << endl; fflush(stdout);
	cout << "4.4 List All Vote Items" << endl; fflush(stdout);
	cout << "4.5 Cast a Vote" << endl; fflush(stdout);
	cout << "4.6 List All Group Members" << endl; fflush(stdout);
	cout << "4.7 Ban a Member from Group" << endl; fflush(stdout);
	cout << "4.8 Program Exit" << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "Select Menu:"; fflush(stdout);
}

void clearTokens(string * tokens)
{
	for (int i = 0; i < 6; i++)
		tokens[i].clear();
}

//�޸𸮰� �۾Ƽ� �۷ι� ������ ������.
votelist memVotes;
group_votelist grpVotes[MAX_GROUP_VOTE];

void doTask()
{
	int menu = 0;
	int menu2 = 0;
	int num = 1;
	int loadMode;
	ofstream inLogWrite;
	ifstream inLogRead;
	string tokens[6], line;
	string _tokens[6], _line; // �޴� �����ϱ�!!
	stringstream stream;
	stringstream stream2; // �޴� �����ϱ�!!
	int nTokens = 0; //number of tokens in string
	int _nTokens = 0; // �޴� �����ϱ�!!
	int tmp = 10;

	//�źп� ���� �ٸ� �޴� ����ϰ� ����� ���� ����, ���� �̿����� �ź�.
	// 1�� nonMem, 2�� generalMem, 3�� groupMem, 4�� leaderMem 
	int userGrade = 1;

	//���� ��µǰ� �ִ� �޴�
	int curMenu = 1;


	//�̿��� ������Ʈ ����
	nonMember NM;
	//Member M;
	Group G;




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
		//�޴� �������̽� ���
		if (userGrade == 1) {
			printMenu2(num++);
			curMenu = 1;
		}
		else if (userGrade == 2) {
			printMenu3(num++);
			curMenu = 2;
		}
		else if (userGrade == 3) {
			printMenu4(num++);
			curMenu = 3;
		}
		else if (userGrade == 4) {
			printMenu5(num++);
			curMenu = 4;
		}
		else {
			printMenu2(num++); //�⺻������ ��µǴ� �� non-Member�� �޴��̴�.
			curMenu = 1;
		}
		//�α� ���� �о� ����
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
					/*/
					if (line == "")
					{
						cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
						continue;
					}
					menu = atoi(line.c_str());
					//
					*/
					//�޴� �����ϱ�
					stream2.str(line);
					nTokens = 0;
					clearTokens(tokens);
					//Read all tokens(seperated by " ")
					while (stream2 >> tokens[nTokens])
						nTokens++;
					stream2.clear();
					menu = atoi(tokens[0].c_str());
					menu2 = atoi(tokens[1].c_str());
					if ((menu != curMenu) && (menu != 0)) {
						cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
						continue;
					}


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
				//�޴� �����ϱ�
				stream2.str(line);
				nTokens = 0;
				clearTokens(tokens);
				//Read all tokens(seperated by " ")
				while (stream2 >> tokens[nTokens])
					nTokens++;
				stream2.clear();
				menu = atoi(tokens[0].c_str());
				menu2 = atoi(tokens[1].c_str());
				if ((menu != curMenu) && (menu != 0)) {
					cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
					continue;
				}
				//
				/*
				stream.str(line);
				nTokens = 0;
				clearTokens(tokens);
				//Read all tokens(seperated by " ")
				while (stream >> tokens[nTokens])
					nTokens++;
				stream.clear();
				menu = atoi(tokens[0].c_str());
				cout << menu << endl; fflush(stdout);
				*/
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
			//�޴� �����ϱ�
			stream2.str(line);
			nTokens = 0;
			clearTokens(tokens);
			//Read all tokens(seperated by " ")
			while (stream2 >> tokens[nTokens])
				nTokens++;
			stream2.clear();
			menu = atoi(tokens[0].c_str());
			menu2 = atoi(tokens[1].c_str());
			if ((menu != curMenu) && (menu != 0)) {
				cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
				continue;
			}

		}

		//�޴� ����
		//�źп� ���� �޴� �����ϱ�

		if (menu == 0) {
			if (menu2 == 0) {
				menu00(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);
			}
		}
		else if (menu == 1) {

			switch (menu2)
			{
			case 1:
			{
				nm11(NM, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 2:
			{
				nm12(NM, G, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 3:
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

		}
		else if (menu == 2) {

			switch (menu2)
			{
			case 1:
			{
				m21(NM, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 2:
			{
				m22(NM, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 3:
			{
				m23(NM, memVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 4:
			{
				m24(NM, memVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 5:
			{
				m25(NM, memVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 6:
			{
				m26(NM, memVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 7:
			{
				m27(G, NM, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 8:
			{
				m28(grpVotes, G, NM, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);

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

		}

		else if (menu == 3) {

			switch (menu2)
			{
			case 1:
			{
				gm31(NM, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 2:
			{
				gm32(NM, G, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 3:
			{
				gm33(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 4:
			{
				gm34(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 5:
			{
				gm35(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 6:
			{
				gm36(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 7:
			{
				gm37(NM, G, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 8:
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

		}

		else if (menu == 4) {

			switch (menu2)
			{
			case 1:
			{
				gl41(NM, userGrade, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 2:
			{
				gl42(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 3:
			{
				gl43(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 4:
			{
				gl44(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 5:
			{
				gl45(NM, G, memVotes, grpVotes, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 6:
			{
				gl46(NM, G, loadMode, inLogRead, inLogWrite, tokens, nTokens);

				break;
			}
			case 7:
			{
				gl47(NM, G, loadMode, inLogRead, inLogWrite, tokens, nTokens);
				break;
			}
			case 8:
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
		}

		//�̰� ����� *************************************************************************************************

		if (!loadMode) {
			getchar();
		}

	}
	return;
}