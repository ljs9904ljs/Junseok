#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(float*** table, int identity[26], char* print_name, int rowcol[26][2], FILE* input, FILE* output, char text1[100], char text2[100]);
void printsize(float*** table, int identity[26], char* print_name, int rowcol[26][2], FILE* input, FILE* output, char text1[100], char text2[100]);


int main()
{
	//use
	char* word_use;
	char* use_num;

	//vector
	char* word_vector;
	char* vector_name;
	char* vector_dimension;
	char vector_ini[100];
	char* vec[100];

	//matrix
	char* word_matrix;
	char* matrix_name;
	char* row;
	char* col;
	char matrix_ini[100][100];
	char* mat[100][100];

	//add
	char* word_add;
	char* add_var1, *add_var2, *add_tot;

	//elemmul
	char* word_elemmul;
	char* ele_var1, *ele_var2, *ele_tot;

	//matmul
	char* word_matmul;
	char* mul_var1, *mul_var2, *mul_tot;

	//vectorize
	char* word_vectorize;
	char* vectorize_name;
	int vector_line;
	int row1;
	int col1;

	//resizemat
	float* temp123;
	char* word_resizemat;
	char* resizemat_name;
	char* rsz_row;
	char* rsz_col;
	int p = 0, q = 0, x = 0, y = 0;

	//transpose
	char* word_transpose;
	char* transpose_name;
	int row_tps;
	int col_tps;
	float tempm[100][100];
	float tempv[100][100];

	//print
	char* print_name;

	//printsize
	char* printsize_name;

	int i = 0, j = 0, k = 0;
	int checkpoint = 0;

	int identity[26]; // 예를 들어, a가 벡터라면 [0]에 1저장, b가 행렬이라면 [1]에 2저장
					  // identity배열 안에 저장되어 있는 숫자에 따라 벡터와 행렬을 구분한다
	int rowcol[26][2] = { 0 }; //벡터와 행렬의 행의 수와 열의 수를 저장한다

	FILE* input;
	FILE* output;

	input = stdin;
	output = stdout;


	char cmd[100];
	char* cmd_head = NULL;

	char text1[100];
	char text2[100];
	int using;

	printf("Enter input file <default=stdin>: ");
	gets(text1);
	printf("Enter output file <default=stdout>: ");
	gets(text2);

	if (strcmp(text1, ""))
		input = fopen(text1, "r");

	if (strcmp(text2, ""))
		output = fopen(text2, "w");


	while (1)
	{
		fgets(cmd, 100, input); //처음으로 명령어 받는 부분
		cmd_head = strtok(cmd, " ");

		if (!strcmp(cmd_head, "USE"))
		{
			use_num = strtok(NULL, " "); // 이것에 저장된 수에 의해 앞으로 내가 쓸 수 있는 변수의 갯수가 결정된다.

			using = atoi(use_num);
			float*** table = (float***)calloc(sizeof(float**), using);  // 모든 명령어의 근원인 동적할당

			while (1)
			{
				while (1)
				{
					fgets(cmd, 100, input); //USE명령어 이후에, 명령어를 받는 부분
					if (!strcmp(cmd, "END\n")) //end에 있는 \n로 인해 아래의 if문이 실행되서 오류가 나는 것을 방지하기 위해 \n을 \0으로 바꿔준다.
					{
						cmd[3] = '\0';
					}

					if (!strcmp(cmd, "\n")) //엔터키를 입력받았을 때 무시하기 위해서
						continue;

					cmd_head = strtok(cmd, " ");

					if (!strcmp(cmd_head, "VECTOR")) //VECTOR 명령어
					{

						vector_name = strtok(NULL, " ");
						vector_dimension = strtok(NULL, " ");

						identity[(vector_name[0] - 'a')] = 1; // identity배열 안에 1을 저장함으로써 이후에 벡터라는 것을 알 수 있도록 한다

						if (table[vector_name[0] - 'a'] == 0)
						{
							table[(vector_name[0] - 'a')] = (float**)calloc(sizeof(float*), (atoi(vector_dimension))); //행을 할당
						}
						else
						{
							fprintf(stderr, "The variable to define is already defined\n");

							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
							break;
						}

						for (int i = 0;i < (atoi(vector_dimension));i++) //몇 번 할당할 것인가? (행의 갯수 만큼)
						{
							table[(vector_name[0] - 'a')][i] = (float*)calloc(sizeof(float), (atoi(vector_dimension))); //열을 할당
						}

						fgets(vector_ini, 100, input); //벡터의 초기값 입력

						printf("\n");

						vec[0] = strtok(vector_ini, " ");
						j = 0;
						while (vec[j] != NULL)
						{
							vec[++j] = strtok(NULL, " "); //입력된 초기값을 띄어쓰기 단위로 쪼개서 저장
						}

						for (int i = 0;i < atoi(vector_dimension);i++)
						{
							table[(vector_name[0] - 'a')][i][0] = atof(vec[i]); //벡터의 값 문자열을 숫자로 바꿔서 저장
						}

						rowcol[(vector_name[0] - 'a')][0] = atoi(vector_dimension); //벡터가 몇 차원인지 저장해둔다
						rowcol[(vector_name[0] - 'a')][1] = 1; //벡터의 열은 1열이므로 1을 저장한다
						break;


					}

					else if (!strcmp(cmd_head, "MATRIX")) //MATRIX 명령어
					{
						matrix_name = strtok(NULL, " ");
						row = strtok(NULL, " ");
						col = strtok(NULL, " ");

						identity[(matrix_name[0] - 'a')] = 2; // identity배열 안에 2를 저장함으로써 이후에 행렬이라는 것을 알 수 있도록 한다

						if (table[(matrix_name[0] - 'a')] == 0) {
							table[(matrix_name[0] - 'a')] = (float**)calloc(sizeof(float*), (atoi(row)*atoi(col))); // 행렬의 행
						}
						else {
							fprintf(stderr, "The variable to define is already defined\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;

							break;
						}
						for (int i = 0;i < (atoi(row)*atoi(col));i++) //행렬의 열
						{
							table[(matrix_name[0] - 'a')][i] = (float*)calloc(sizeof(float), (atoi(col)*atoi(row)));
						}


						for (int i = 0;i < atoi(row);i++) //행렬의 초기값을 한 줄 단위로 입력
						{
							fgets(matrix_ini + i, 100, input);
						}

						printf("\n");


						for (int i = 0;i < atoi(row);i++) //행렬의 초기값 문자열을 하나씩 쪼개서 저장
						{
							mat[i][0] = strtok(matrix_ini[i], " ");
							for (int j = 1;j < atoi(col);j++)
							{
								mat[i][j] = strtok(NULL, " ");
							}
						}

						for (int i = 0;i < atoi(row);i++)
						{
							for (int j = 0;j < atoi(col);j++)
							{
								table[(matrix_name[0] - 'a')][i][j] = atof(mat[i][j]); //저장된 문자열을 숫자로 바꿔서 저장
							}
						}

						rowcol[(matrix_name[0] - 'a')][0] = atoi(row); // 행렬의 행의 갯수 저장
						rowcol[(matrix_name[0] - 'a')][1] = atoi(col); // 행렬의 열의 갯수 저장

						break;

					}

					else if (!strcmp(cmd_head, "ADD")) //ADD명령어
					{
						add_var1 = strtok(NULL, " "); //1번째로 입력받은 변수
						add_var2 = strtok(NULL, " "); //2번째로 입력받은 변수
						add_tot = strtok(NULL, " "); // 덧셈 결과를 저장할 변수

						if (table[add_var1[0] - 'a'] == 0 || table[add_var2[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
							break;
						}

						if ((rowcol[add_var1[0] - 'a'][0] == rowcol[add_var2[0] - 'a'][0] && rowcol[add_var1[0] - 'a'][1] == rowcol[add_var2[0] - 'a'][1]) || (rowcol[add_var1[0] - 'a'][0] == rowcol[add_var2[0] - 'a'][0])) //덧셈을 할 수 있는 조건식
						{

							if (identity[add_var1[0] - 'a'] == 1) // 벡터에서의 덧셈
							{
								for (int i = 0;i < rowcol[(add_var1[0] - 'a')][0];i++)
								{
									table[(add_tot[0] - 'a')][i][0] = table[(add_var1[0] - 'a')][i][0] + table[(add_var2[0] - 'a')][i][0];
								}
							}
							else if (identity[add_var1[0] - 'a'] == 2) //행렬에서의 덧셈
							{
								for (int i = 0; i < rowcol[add_var1[0] - 'a'][0];i++)
								{
									for (int j = 0;j < rowcol[add_var1[0] - 'a'][1];j++)
									{
										table[(add_tot[0] - 'a')][i][j] = table[(add_var1[0] - 'a')][i][j] + table[(add_var2[0] - 'a')][i][j];
									}
								}
							}
						}
						else
						{
							fprintf(stderr, "The sizes of variables should match.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
						}

						break;
					}

					else if (!strcmp(cmd_head, "ELEMMUL")) //ELEMMUL명령어
					{
						ele_var1 = strtok(NULL, " "); //1번째로 입력받은 변수
						ele_var2 = strtok(NULL, " "); //2번째로 입력받은 변수
						ele_tot = strtok(NULL, " "); //elemmul결과를 저장할 변수

						if (table[ele_var1[0] - 'a'] == 0 || table[ele_var2[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
							break;
						}

						if ((rowcol[ele_var1[0] - 'a'][0] == rowcol[ele_var2[0] - 'a'][0] && rowcol[ele_var1[0] - 'a'][1] == rowcol[ele_var2[0] - 'a'][1]) || (rowcol[ele_var1[0] - 'a'][0] == rowcol[ele_var2[0] - 'a'][0])) //elemmul을 할 수 있는 조건식
						{
							if (identity[ele_var1[0] - 'a'] == 1) //벡터일 때
							{
								for (int i = 0;i < rowcol[(ele_var1[0] - 'a')][0];i++)
								{
									table[(ele_tot[0] - 'a')][i][0] = table[(ele_var1[0] - 'a')][i][0] * table[(ele_var2[0] - 'a')][i][0];
								}
							}
							else if (identity[ele_var1[0] - 'a'] == 2) //행렬일 때
							{
								for (int i = 0; i < rowcol[ele_var1[0] - 'a'][0];i++)
								{
									for (int j = 0;j < rowcol[ele_var1[0] - 'a'][1];j++)
									{
										table[(ele_tot[0] - 'a')][i][j] = table[(ele_var1[0] - 'a')][i][j] * table[(ele_var2[0] - 'a')][i][j];
									}
								}
							}
						}
						else
						{
							fprintf(stderr, "The sizes of variables should match.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
						}

						break;
					}

					else if (!strcmp(cmd_head, "MATMUL")) //MATMUL명령어
					{
						mul_var1 = strtok(NULL, " "); //1번째로 입력받은 변수
						mul_var2 = strtok(NULL, " "); //2번째로 입력받은 변수
						mul_tot = strtok(NULL, " "); //결과를 저장할 변수

						if (table[mul_var1[0] - 'a'] == 0 || table[mul_var2[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
							break;
						}

						if (rowcol[mul_var1[0] - 'a'][1] == rowcol[mul_var2[0] - 'a'][0]) //matmul을 할 수 있는 조건식
						{
							for (int i = 0; i < rowcol[mul_var1[0] - 'a'][0];i++)
							{
								for (int j = 0;j < rowcol[mul_var2[0] - 'a'][1];j++)
								{
									for (int k = 0;k < rowcol[mul_var1[0] - 'a'][1];k++)
									{
										table[(mul_tot[0] - 'a')][i][j] += table[(mul_var1[0] - 'a')][i][k] * table[(mul_var2[0] - 'a')][k][j];
									}
								}
							}
						}
						else
						{
							fprintf(stderr, "The sizes of variables should match.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
						}

						break;
					}

					else if (!strcmp(cmd_head, "VECTORIZE")) //VECTORIZE 명령어
					{
						vectorize_name = strtok(NULL, " "); //vectorize할 변수를 저장한다

						if (table[vectorize_name[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
							break;
						}
						vector_line = rowcol[(vectorize_name[0] - 'a')][0] * rowcol[(vectorize_name[0] - 'a')][1]; //vectorize할 행렬의 행과 열을 곱함
						row1 = rowcol[(vectorize_name[0] - 'a')][0]; //vectorize할 행렬의 행
						col1 = rowcol[(vectorize_name[0] - 'a')][1]; //vectorize할 행렬의 열


						float** temp1 = (float**)calloc(sizeof(float*), vector_line); //임시로 값을 저장해둘 곳
						for (int i = 0; i < vector_line;i++)
						{
							temp1[i] = (float*)calloc(sizeof(float), vector_line);
						}

						k = 0;
						for (int i = 0; i < row1;i++)
						{
							for (int j = 0;j < col1;j++)
							{
								temp1[k++][0] = table[(vectorize_name[0] - 'a')][i][j]; //값을 임시로 저장
							}
						}
						for (int i = 0;i < vector_line;i++) //값 바꾸기 전에 원래 것을 비워준다
						{
							free(table[(vectorize_name[0] - 'a')][i]);
						}
						free(table[(vectorize_name[0] - 'a')]);

						table[(vectorize_name[0] - 'a')] = temp1; //바꾼 것을 원래의 것에 저장

						rowcol[(vectorize_name[0] - 'a')][0] = k;
						rowcol[(vectorize_name[0] - 'a')][1] = 1;
						identity[(vectorize_name[0] - 'a')] = 1; //행렬이었으니 벡터라고 바꿔 저장.

						break;
					}

					else if (!strcmp(cmd_head, "RESIZEMAT")) //RESIZEMAT 명령어
					{
						resizemat_name = strtok(NULL, " "); //resizemat할 변수
						rsz_row = strtok(NULL, " "); //resizemat할 행
						rsz_col = strtok(NULL, " "); //resizemat할 열

						p = rowcol[resizemat_name[0] - 'a'][0];
						q = rowcol[resizemat_name[0] - 'a'][1];
						x = atoi(rsz_row);
						y = atoi(rsz_col);

						rowcol[resizemat_name[0] - 'a'][0] = x;
						rowcol[resizemat_name[0] - 'a'][1] = y;
						identity[resizemat_name[0] - 'a'] = 2; //벡터가 행렬이 될 수도 있으니까 행렬이라고 저장해준다

						if (table[resizemat_name[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
							break;
						}

						temp123 = (float*)calloc(sizeof(float), (p*q));
						k = 0;
						if ((p * q) == (x * y)) // 명령어를 수행하기에 적절한 변수의 원소 수인가?
						{
							for (int i = 0; i < p;i++) //일차원배열에 모든 값을 일단 저장해둔다
							{
								for (int j = 0;j < q;j++)
								{
									temp123[k++] = table[resizemat_name[0] - 'a'][i][j];
								}
							}
							for (int i = 0; i < x;i++) //원하는 만큼 쪼개서 저장한다
							{
								for (int j = 0;j < y;j++)
								{
									table[resizemat_name[0] - 'a'][i][j] = temp123[(x*y) - k--];
								}
							}

							free(temp123);

							break;
						}
						else // 에러메시지, 인자로 주어진 변수의 원소 수가 명령어를 수행하기에 부적절 할 때)
						{
							fprintf(stderr, "The numbers of elements in the variables do not match.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //행을 free
							{
								if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
									free(table[i]);
							}

							free(table); //변수 저장된 곳 free
							return 0;
							break;
						}
					}

					else if (!strcmp(cmd_head, "TRANSPOSE")) //TRANSPOSE 명령어
					{
						transpose_name = strtok(NULL, " "); //transpose할 변수

						if (identity[transpose_name[0] - 'a'] == 2) //행렬이라면
						{
							row_tps = rowcol[transpose_name[0] - 'a'][0]; //transpose할 행
							col_tps = rowcol[transpose_name[0] - 'a'][1]; //transpose할 열

							if (table[transpose_name[0] - 'a'] == 0)
							{
								fprintf(stderr, "The variables should be defined before use.\n");
								for (int i = 0;i < using;i++)
								{
									if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
									{
										for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
										{
											free(table[i][j]);
										}
									}
								}

								for (int i = 0;i < using;i++) //행을 free
								{
									if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
										free(table[i]);
								}

								free(table); //변수 저장된 곳 free
								return 0;
								break;
							}

							for (i = 0; i < row_tps; i++) //원래의 값을 임시로 저장
							{
								for (j = 0; j < col_tps; j++)
								{
									tempm[i][j] = table[transpose_name[0] - 'a'][i][j];
								}
							}

							for (i = 0; i < row_tps; i++) //transpose해서 값을 저장
							{
								for (j = 0; j < col_tps; j++)
								{
									table[transpose_name[0] - 'a'][j][i] = tempm[i][j];
								}
							}
							rowcol[transpose_name[0] - 'a'][0] = col_tps; //원래의 열이 행이 된다
							rowcol[transpose_name[0] - 'a'][1] = row_tps; //원래의 행이 열이 된다
						}

						else if (identity[transpose_name[0] - 'a'] == 1) //벡터라면
						{
							row_tps = rowcol[transpose_name[0] - 'a'][0]; //벡터 행
							col_tps = 1; //벡터 열

							if (table[transpose_name[0] - 'a'] == 0)
							{
								fprintf(stderr, "The variables should be defined before use.\n");
								for (int i = 0;i < using;i++)
								{
									if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
									{
										for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
										{
											free(table[i][j]);
										}
									}
								}

								for (int i = 0;i < using;i++) //행을 free
								{
									if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
										free(table[i]);
								}

								free(table); //변수 저장된 곳 free
								return 0;
								break;
							}

							for (int i = 0; i < row_tps; i++) //원래의 값을 임시로 저장
							{
								for (int j = 0; j < col_tps; j++)
								{
									tempv[i][j] = table[transpose_name[0] - 'a'][i][j];
								}
							}

							for (int i = 0; i < row_tps; i++) //transpose해서 값을 저장
							{
								for (int j = 0; j < col_tps; j++)
								{
									table[transpose_name[0] - 'a'][j][i] = tempv[i][j];
								}
							}
							rowcol[transpose_name[0] - 'a'][0] = 1; // 열이 행이 된다
							rowcol[transpose_name[0] - 'a'][1] = row_tps; //행이 열이 된다
							identity[transpose_name[0] - 'a'] = 2; //행렬이 되었으므로

						}
						break;
					}

					else if (!strcmp(cmd_head, "END")) //END 명령어, 뭔가 부족해 첫 동적할당에서, abcde~ 쭉 다 검사해야되지않을까
					{
						for (int i = 0;i < using;i++)
						{
							if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
							{
								for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
								{
									free(table[i][j]);
								}
							}
						}

						for (int i = 0;i < using;i++) //행을 free
						{
							if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
								free(table[i]);
						}

						free(table); //변수 저장된 곳 free

						checkpoint = -1; //end하면 이걸 통해서 while문을 다 빠져나간다.
						break;
					}

					else if (!strcmp(cmd_head, "PRINT")) //PRINT 명령어
					{
						print_name = strtok(NULL, " ");
						print(table, identity, print_name, rowcol, input, output, text1, text2);
					}

					else if (!strcmp(cmd_head, "PRINTSIZE")) //PRINTSIZE 명령어
					{
						printsize_name = strtok(NULL, " ");
						printsize(table, identity, printsize_name, rowcol, input, output, text1, text2);
					}

					else
					{
						fprintf(stderr, "Incorrect command entered.\n");

						for (int i = 0;i < using;i++)
						{
							if (rowcol[i][0] != 0) // 0차원이 아니면 뭔가 할당이 있다는 뜻
							{
								for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //열을 free
								{
									free(table[i][j]);
								}
							}
						}

						for (int i = 0;i < using;i++) //행을 free
						{
							if (table[i] != 0) //동적할당 되어있는 부분만 free해야되므로
								free(table[i]);
						}

						free(table); //변수 저장된 곳 free
						return 0;
					}
				}//while(1)에 대한 중괄호

				if (checkpoint == -1) //end명령어 입력받으면
					break;
			}//while(1) 하나 더
		}//USE와 관련된 if문의 중괄호
		else // USE의 if문에 대한 else
		{
			fprintf(stderr, "The first command should be always USE n\n"); //use가 아닌 명령어로 시작한 경우

			return 0;

		}
		if (checkpoint == -1) //end명령어 입력받으면
			break;
	} // while(1)

	fclose(input); //파일 닫기
	fclose(output); //파일 닫기

	return 0;
}


void print(float*** table, int identity[26], char* print_name, int rowcol[26][2], FILE* input, FILE* output, char text1[100], char text2[100])
{
	//PRINT 명령어

	fprintf(output, "\n");

	if (identity[(print_name[0]) - 'a'] == 1)
	{
		fprintf(output, "[ ");
		fprintf(output, "%7.2f,\n", table[(print_name[0] - 'a')][0][0]);
		for (int i = 1; i < (rowcol[print_name[0] - 'a'][0] - 1);i++)
		{
			fprintf(output, " %8.2f,\n", table[(print_name[0] - 'a')][i][0]);
		}
		fprintf(output, " %8.2f", table[(print_name[0] - 'a')][(rowcol[print_name[0] - 'a'][0] - 1)][0]);
		fprintf(output, " ]\n");
	}
	if (identity[(print_name[0]) - 'a'] == 2)
	{
		fprintf(output, "[");

		for (int i = 0; i < rowcol[print_name[0] - 'a'][0];i++)
		{
			if (i == 0)
				fprintf(output, "[");
			else
				fprintf(output, " [");

			for (int j = 0; j < (rowcol[print_name[0] - 'a'][1] - 1);j++)
			{
				fprintf(output, " %8.2f,", table[(print_name[0] - 'a')][i][j]);
			}
			fprintf(output, " %8.2f", table[(print_name[0] - 'a')][i][(rowcol[print_name[0] - 'a'][1] - 1)]);

			fprintf(output, "]");
			if (i != (rowcol[print_name[0] - 'a'][0] - 1))
			{
				fprintf(output, ",");
				fprintf(output, "\n");
			}
		}
		fprintf(output, "]\n");
	}

}

void printsize(float*** table, int identity[26], char* printsize_name, int rowcol[26][2], FILE* input, FILE* output, char text1[100], char text2[100])
{
	//PRINTSIZE 명령어

	if (identity[printsize_name[0] - 'a'] == 1)
	{
		fprintf(output, " '%c' is a %d-dimensional vector.\n", printsize_name[0], rowcol[printsize_name[0] - 'a'][0]);
	}
	else if (identity[printsize_name[0] - 'a'] == 2)
	{
		fprintf(output, " '%c' is a %d X %d matrix.\n", printsize_name[0], rowcol[printsize_name[0] - 'a'][0], rowcol[printsize_name[0] - 'a'][1]);
	}
}