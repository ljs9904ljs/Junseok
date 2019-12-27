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

	int identity[26]; // ���� ���, a�� ���Ͷ�� [0]�� 1����, b�� ����̶�� [1]�� 2����
					  // identity�迭 �ȿ� ����Ǿ� �ִ� ���ڿ� ���� ���Ϳ� ����� �����Ѵ�
	int rowcol[26][2] = { 0 }; //���Ϳ� ����� ���� ���� ���� ���� �����Ѵ�

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
		fgets(cmd, 100, input); //ó������ ��ɾ� �޴� �κ�
		cmd_head = strtok(cmd, " ");

		if (!strcmp(cmd_head, "USE"))
		{
			use_num = strtok(NULL, " "); // �̰Ϳ� ����� ���� ���� ������ ���� �� �� �ִ� ������ ������ �����ȴ�.

			using = atoi(use_num);
			float*** table = (float***)calloc(sizeof(float**), using);  // ��� ��ɾ��� �ٿ��� �����Ҵ�

			while (1)
			{
				while (1)
				{
					fgets(cmd, 100, input); //USE��ɾ� ���Ŀ�, ��ɾ �޴� �κ�
					if (!strcmp(cmd, "END\n")) //end�� �ִ� \n�� ���� �Ʒ��� if���� ����Ǽ� ������ ���� ���� �����ϱ� ���� \n�� \0���� �ٲ��ش�.
					{
						cmd[3] = '\0';
					}

					if (!strcmp(cmd, "\n")) //����Ű�� �Է¹޾��� �� �����ϱ� ���ؼ�
						continue;

					cmd_head = strtok(cmd, " ");

					if (!strcmp(cmd_head, "VECTOR")) //VECTOR ��ɾ�
					{

						vector_name = strtok(NULL, " ");
						vector_dimension = strtok(NULL, " ");

						identity[(vector_name[0] - 'a')] = 1; // identity�迭 �ȿ� 1�� ���������ν� ���Ŀ� ���Ͷ�� ���� �� �� �ֵ��� �Ѵ�

						if (table[vector_name[0] - 'a'] == 0)
						{
							table[(vector_name[0] - 'a')] = (float**)calloc(sizeof(float*), (atoi(vector_dimension))); //���� �Ҵ�
						}
						else
						{
							fprintf(stderr, "The variable to define is already defined\n");

							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
							break;
						}

						for (int i = 0;i < (atoi(vector_dimension));i++) //�� �� �Ҵ��� ���ΰ�? (���� ���� ��ŭ)
						{
							table[(vector_name[0] - 'a')][i] = (float*)calloc(sizeof(float), (atoi(vector_dimension))); //���� �Ҵ�
						}

						fgets(vector_ini, 100, input); //������ �ʱⰪ �Է�

						printf("\n");

						vec[0] = strtok(vector_ini, " ");
						j = 0;
						while (vec[j] != NULL)
						{
							vec[++j] = strtok(NULL, " "); //�Էµ� �ʱⰪ�� ���� ������ �ɰ��� ����
						}

						for (int i = 0;i < atoi(vector_dimension);i++)
						{
							table[(vector_name[0] - 'a')][i][0] = atof(vec[i]); //������ �� ���ڿ��� ���ڷ� �ٲ㼭 ����
						}

						rowcol[(vector_name[0] - 'a')][0] = atoi(vector_dimension); //���Ͱ� �� �������� �����صд�
						rowcol[(vector_name[0] - 'a')][1] = 1; //������ ���� 1���̹Ƿ� 1�� �����Ѵ�
						break;


					}

					else if (!strcmp(cmd_head, "MATRIX")) //MATRIX ��ɾ�
					{
						matrix_name = strtok(NULL, " ");
						row = strtok(NULL, " ");
						col = strtok(NULL, " ");

						identity[(matrix_name[0] - 'a')] = 2; // identity�迭 �ȿ� 2�� ���������ν� ���Ŀ� ����̶�� ���� �� �� �ֵ��� �Ѵ�

						if (table[(matrix_name[0] - 'a')] == 0) {
							table[(matrix_name[0] - 'a')] = (float**)calloc(sizeof(float*), (atoi(row)*atoi(col))); // ����� ��
						}
						else {
							fprintf(stderr, "The variable to define is already defined\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;

							break;
						}
						for (int i = 0;i < (atoi(row)*atoi(col));i++) //����� ��
						{
							table[(matrix_name[0] - 'a')][i] = (float*)calloc(sizeof(float), (atoi(col)*atoi(row)));
						}


						for (int i = 0;i < atoi(row);i++) //����� �ʱⰪ�� �� �� ������ �Է�
						{
							fgets(matrix_ini + i, 100, input);
						}

						printf("\n");


						for (int i = 0;i < atoi(row);i++) //����� �ʱⰪ ���ڿ��� �ϳ��� �ɰ��� ����
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
								table[(matrix_name[0] - 'a')][i][j] = atof(mat[i][j]); //����� ���ڿ��� ���ڷ� �ٲ㼭 ����
							}
						}

						rowcol[(matrix_name[0] - 'a')][0] = atoi(row); // ����� ���� ���� ����
						rowcol[(matrix_name[0] - 'a')][1] = atoi(col); // ����� ���� ���� ����

						break;

					}

					else if (!strcmp(cmd_head, "ADD")) //ADD��ɾ�
					{
						add_var1 = strtok(NULL, " "); //1��°�� �Է¹��� ����
						add_var2 = strtok(NULL, " "); //2��°�� �Է¹��� ����
						add_tot = strtok(NULL, " "); // ���� ����� ������ ����

						if (table[add_var1[0] - 'a'] == 0 || table[add_var2[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
							break;
						}

						if ((rowcol[add_var1[0] - 'a'][0] == rowcol[add_var2[0] - 'a'][0] && rowcol[add_var1[0] - 'a'][1] == rowcol[add_var2[0] - 'a'][1]) || (rowcol[add_var1[0] - 'a'][0] == rowcol[add_var2[0] - 'a'][0])) //������ �� �� �ִ� ���ǽ�
						{

							if (identity[add_var1[0] - 'a'] == 1) // ���Ϳ����� ����
							{
								for (int i = 0;i < rowcol[(add_var1[0] - 'a')][0];i++)
								{
									table[(add_tot[0] - 'a')][i][0] = table[(add_var1[0] - 'a')][i][0] + table[(add_var2[0] - 'a')][i][0];
								}
							}
							else if (identity[add_var1[0] - 'a'] == 2) //��Ŀ����� ����
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
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
						}

						break;
					}

					else if (!strcmp(cmd_head, "ELEMMUL")) //ELEMMUL��ɾ�
					{
						ele_var1 = strtok(NULL, " "); //1��°�� �Է¹��� ����
						ele_var2 = strtok(NULL, " "); //2��°�� �Է¹��� ����
						ele_tot = strtok(NULL, " "); //elemmul����� ������ ����

						if (table[ele_var1[0] - 'a'] == 0 || table[ele_var2[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
							break;
						}

						if ((rowcol[ele_var1[0] - 'a'][0] == rowcol[ele_var2[0] - 'a'][0] && rowcol[ele_var1[0] - 'a'][1] == rowcol[ele_var2[0] - 'a'][1]) || (rowcol[ele_var1[0] - 'a'][0] == rowcol[ele_var2[0] - 'a'][0])) //elemmul�� �� �� �ִ� ���ǽ�
						{
							if (identity[ele_var1[0] - 'a'] == 1) //������ ��
							{
								for (int i = 0;i < rowcol[(ele_var1[0] - 'a')][0];i++)
								{
									table[(ele_tot[0] - 'a')][i][0] = table[(ele_var1[0] - 'a')][i][0] * table[(ele_var2[0] - 'a')][i][0];
								}
							}
							else if (identity[ele_var1[0] - 'a'] == 2) //����� ��
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
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
						}

						break;
					}

					else if (!strcmp(cmd_head, "MATMUL")) //MATMUL��ɾ�
					{
						mul_var1 = strtok(NULL, " "); //1��°�� �Է¹��� ����
						mul_var2 = strtok(NULL, " "); //2��°�� �Է¹��� ����
						mul_tot = strtok(NULL, " "); //����� ������ ����

						if (table[mul_var1[0] - 'a'] == 0 || table[mul_var2[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
							break;
						}

						if (rowcol[mul_var1[0] - 'a'][1] == rowcol[mul_var2[0] - 'a'][0]) //matmul�� �� �� �ִ� ���ǽ�
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
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
						}

						break;
					}

					else if (!strcmp(cmd_head, "VECTORIZE")) //VECTORIZE ��ɾ�
					{
						vectorize_name = strtok(NULL, " "); //vectorize�� ������ �����Ѵ�

						if (table[vectorize_name[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
							break;
						}
						vector_line = rowcol[(vectorize_name[0] - 'a')][0] * rowcol[(vectorize_name[0] - 'a')][1]; //vectorize�� ����� ��� ���� ����
						row1 = rowcol[(vectorize_name[0] - 'a')][0]; //vectorize�� ����� ��
						col1 = rowcol[(vectorize_name[0] - 'a')][1]; //vectorize�� ����� ��


						float** temp1 = (float**)calloc(sizeof(float*), vector_line); //�ӽ÷� ���� �����ص� ��
						for (int i = 0; i < vector_line;i++)
						{
							temp1[i] = (float*)calloc(sizeof(float), vector_line);
						}

						k = 0;
						for (int i = 0; i < row1;i++)
						{
							for (int j = 0;j < col1;j++)
							{
								temp1[k++][0] = table[(vectorize_name[0] - 'a')][i][j]; //���� �ӽ÷� ����
							}
						}
						for (int i = 0;i < vector_line;i++) //�� �ٲٱ� ���� ���� ���� ����ش�
						{
							free(table[(vectorize_name[0] - 'a')][i]);
						}
						free(table[(vectorize_name[0] - 'a')]);

						table[(vectorize_name[0] - 'a')] = temp1; //�ٲ� ���� ������ �Ϳ� ����

						rowcol[(vectorize_name[0] - 'a')][0] = k;
						rowcol[(vectorize_name[0] - 'a')][1] = 1;
						identity[(vectorize_name[0] - 'a')] = 1; //����̾����� ���Ͷ�� �ٲ� ����.

						break;
					}

					else if (!strcmp(cmd_head, "RESIZEMAT")) //RESIZEMAT ��ɾ�
					{
						resizemat_name = strtok(NULL, " "); //resizemat�� ����
						rsz_row = strtok(NULL, " "); //resizemat�� ��
						rsz_col = strtok(NULL, " "); //resizemat�� ��

						p = rowcol[resizemat_name[0] - 'a'][0];
						q = rowcol[resizemat_name[0] - 'a'][1];
						x = atoi(rsz_row);
						y = atoi(rsz_col);

						rowcol[resizemat_name[0] - 'a'][0] = x;
						rowcol[resizemat_name[0] - 'a'][1] = y;
						identity[resizemat_name[0] - 'a'] = 2; //���Ͱ� ����� �� ���� �����ϱ� ����̶�� �������ش�

						if (table[resizemat_name[0] - 'a'] == 0)
						{
							fprintf(stderr, "The variables should be defined before use.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
							break;
						}

						temp123 = (float*)calloc(sizeof(float), (p*q));
						k = 0;
						if ((p * q) == (x * y)) // ��ɾ �����ϱ⿡ ������ ������ ���� ���ΰ�?
						{
							for (int i = 0; i < p;i++) //�������迭�� ��� ���� �ϴ� �����صд�
							{
								for (int j = 0;j < q;j++)
								{
									temp123[k++] = table[resizemat_name[0] - 'a'][i][j];
								}
							}
							for (int i = 0; i < x;i++) //���ϴ� ��ŭ �ɰ��� �����Ѵ�
							{
								for (int j = 0;j < y;j++)
								{
									table[resizemat_name[0] - 'a'][i][j] = temp123[(x*y) - k--];
								}
							}

							free(temp123);

							break;
						}
						else // �����޽���, ���ڷ� �־��� ������ ���� ���� ��ɾ �����ϱ⿡ ������ �� ��)
						{
							fprintf(stderr, "The numbers of elements in the variables do not match.\n");
							for (int i = 0;i < using;i++)
							{
								if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
								{
									for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
									{
										free(table[i][j]);
									}
								}
							}

							for (int i = 0;i < using;i++) //���� free
							{
								if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
									free(table[i]);
							}

							free(table); //���� ����� �� free
							return 0;
							break;
						}
					}

					else if (!strcmp(cmd_head, "TRANSPOSE")) //TRANSPOSE ��ɾ�
					{
						transpose_name = strtok(NULL, " "); //transpose�� ����

						if (identity[transpose_name[0] - 'a'] == 2) //����̶��
						{
							row_tps = rowcol[transpose_name[0] - 'a'][0]; //transpose�� ��
							col_tps = rowcol[transpose_name[0] - 'a'][1]; //transpose�� ��

							if (table[transpose_name[0] - 'a'] == 0)
							{
								fprintf(stderr, "The variables should be defined before use.\n");
								for (int i = 0;i < using;i++)
								{
									if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
									{
										for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
										{
											free(table[i][j]);
										}
									}
								}

								for (int i = 0;i < using;i++) //���� free
								{
									if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
										free(table[i]);
								}

								free(table); //���� ����� �� free
								return 0;
								break;
							}

							for (i = 0; i < row_tps; i++) //������ ���� �ӽ÷� ����
							{
								for (j = 0; j < col_tps; j++)
								{
									tempm[i][j] = table[transpose_name[0] - 'a'][i][j];
								}
							}

							for (i = 0; i < row_tps; i++) //transpose�ؼ� ���� ����
							{
								for (j = 0; j < col_tps; j++)
								{
									table[transpose_name[0] - 'a'][j][i] = tempm[i][j];
								}
							}
							rowcol[transpose_name[0] - 'a'][0] = col_tps; //������ ���� ���� �ȴ�
							rowcol[transpose_name[0] - 'a'][1] = row_tps; //������ ���� ���� �ȴ�
						}

						else if (identity[transpose_name[0] - 'a'] == 1) //���Ͷ��
						{
							row_tps = rowcol[transpose_name[0] - 'a'][0]; //���� ��
							col_tps = 1; //���� ��

							if (table[transpose_name[0] - 'a'] == 0)
							{
								fprintf(stderr, "The variables should be defined before use.\n");
								for (int i = 0;i < using;i++)
								{
									if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
									{
										for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
										{
											free(table[i][j]);
										}
									}
								}

								for (int i = 0;i < using;i++) //���� free
								{
									if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
										free(table[i]);
								}

								free(table); //���� ����� �� free
								return 0;
								break;
							}

							for (int i = 0; i < row_tps; i++) //������ ���� �ӽ÷� ����
							{
								for (int j = 0; j < col_tps; j++)
								{
									tempv[i][j] = table[transpose_name[0] - 'a'][i][j];
								}
							}

							for (int i = 0; i < row_tps; i++) //transpose�ؼ� ���� ����
							{
								for (int j = 0; j < col_tps; j++)
								{
									table[transpose_name[0] - 'a'][j][i] = tempv[i][j];
								}
							}
							rowcol[transpose_name[0] - 'a'][0] = 1; // ���� ���� �ȴ�
							rowcol[transpose_name[0] - 'a'][1] = row_tps; //���� ���� �ȴ�
							identity[transpose_name[0] - 'a'] = 2; //����� �Ǿ����Ƿ�

						}
						break;
					}

					else if (!strcmp(cmd_head, "END")) //END ��ɾ�, ���� ������ ù �����Ҵ翡��, abcde~ �� �� �˻��ؾߵ���������
					{
						for (int i = 0;i < using;i++)
						{
							if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
							{
								for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
								{
									free(table[i][j]);
								}
							}
						}

						for (int i = 0;i < using;i++) //���� free
						{
							if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
								free(table[i]);
						}

						free(table); //���� ����� �� free

						checkpoint = -1; //end�ϸ� �̰� ���ؼ� while���� �� ����������.
						break;
					}

					else if (!strcmp(cmd_head, "PRINT")) //PRINT ��ɾ�
					{
						print_name = strtok(NULL, " ");
						print(table, identity, print_name, rowcol, input, output, text1, text2);
					}

					else if (!strcmp(cmd_head, "PRINTSIZE")) //PRINTSIZE ��ɾ�
					{
						printsize_name = strtok(NULL, " ");
						printsize(table, identity, printsize_name, rowcol, input, output, text1, text2);
					}

					else
					{
						fprintf(stderr, "Incorrect command entered.\n");

						for (int i = 0;i < using;i++)
						{
							if (rowcol[i][0] != 0) // 0������ �ƴϸ� ���� �Ҵ��� �ִٴ� ��
							{
								for (int j = 0;j < rowcol[i][0] * rowcol[i][1];j++) //���� free
								{
									free(table[i][j]);
								}
							}
						}

						for (int i = 0;i < using;i++) //���� free
						{
							if (table[i] != 0) //�����Ҵ� �Ǿ��ִ� �κи� free�ؾߵǹǷ�
								free(table[i]);
						}

						free(table); //���� ����� �� free
						return 0;
					}
				}//while(1)�� ���� �߰�ȣ

				if (checkpoint == -1) //end��ɾ� �Է¹�����
					break;
			}//while(1) �ϳ� ��
		}//USE�� ���õ� if���� �߰�ȣ
		else // USE�� if���� ���� else
		{
			fprintf(stderr, "The first command should be always USE n\n"); //use�� �ƴ� ��ɾ�� ������ ���

			return 0;

		}
		if (checkpoint == -1) //end��ɾ� �Է¹�����
			break;
	} // while(1)

	fclose(input); //���� �ݱ�
	fclose(output); //���� �ݱ�

	return 0;
}


void print(float*** table, int identity[26], char* print_name, int rowcol[26][2], FILE* input, FILE* output, char text1[100], char text2[100])
{
	//PRINT ��ɾ�

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
	//PRINTSIZE ��ɾ�

	if (identity[printsize_name[0] - 'a'] == 1)
	{
		fprintf(output, " '%c' is a %d-dimensional vector.\n", printsize_name[0], rowcol[printsize_name[0] - 'a'][0]);
	}
	else if (identity[printsize_name[0] - 'a'] == 2)
	{
		fprintf(output, " '%c' is a %d X %d matrix.\n", printsize_name[0], rowcol[printsize_name[0] - 'a'][0], rowcol[printsize_name[0] - 'a'][1]);
	}
}