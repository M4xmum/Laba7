#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
void rec(int ver, int* v, int n, int** matr) {

	v[ver] = 1;
	printf("%d \t", ver + 1);
	for (int i = 0; i < n; i++) {
		if (matr[ver][i] == 1 && v[i] == 0)
			rec(i, v, n, matr);
	}
}



int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n = 0;
	printf("������� ���������� ������: ");
	scanf_s("%d", &n);
	int** matr1 = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr1[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr1[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			matr1[i][j] = rand() % 2;
			matr1[j][i] = matr1[i][j];
			if (i == j)
				matr1[i][j] = 0;
		}

	}


	printf("\n   ������� M1:    \n�  ");
	for (int i = 0; i < n; i++) {
		printf(" %d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < n; i++) {
		printf("__");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < n; ++j)
				printf("%d ", matr1[i][j]);
			printf("\n");
		}
	}

	int ver = 0, op = 0;
	while (1) {
		printf("\n������� ����� ��������:\n1)������� ������� ��� ������ 2)�����\n");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
		{
			int* v = (int*)malloc(sizeof(int) * n);
			for (int i = 0; i < n; i++)
				v[i] = 0;

			printf("�������� �������, � ������� �������� �����:");
			scanf_s("%d", &ver);
			if (ver <= n && ver > 0) {
				ver -= 1;
				for (int i = 0; i < n; i++) {
					while (matr1[ver][i] == 1 && v[i] == 0) {
						rec(ver, v, n, matr1);
					}
				}
			}
			else
				printf("��� �������!");

			free(v);
			break;
		}
		case 2:
			for (int i = 0; i < n; i++) {
				free(matr1[i]);
			}
			free(matr1);

			return 0;
		}
	}

}