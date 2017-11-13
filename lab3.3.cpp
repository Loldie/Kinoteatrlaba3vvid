

#include "stdafx.h" 
#include <stdio.h> 
#include <math.h> 
#include <clocale> 
#include <stdlib.h> 
#include <time.h> 
#include <memory.h> 
#include <crtdbg.h> 
#include <conio.h> 

int menu();
int VvodRyad();
int VvodMesto();
int **addMass(int **mass, int ryad, int mesto);
int decide();
void delMass(int **mass, int ryad);
void fillMass(int **mass, int ryad, int mesto);
void printMass(int **mass, int ryad, int mesto);
void ticket(int **mass, int ryad, int mesto);
void ticket2(int **mass, int ryad, int mesto);
void buyticket(int **mass, int ryad, int mesto);
void sellticket(int **mass, int ryad, int mesto);

int _tmain(int argc, _TCHAR* argv[])
{
	int **mass = NULL;
	int ryad, mesto, m, y = 0, t;
	setlocale(0, "");
	do
	{
		m = menu();
		switch (m)
		{
		case 1:
			if (y == 0)
			{
				ryad = VvodRyad();
				mesto = VvodMesto();
				mass = addMass(mass, ryad, mesto);
				fillMass(mass, ryad, mesto);
				y = 1;
			}
			else
			{
				t = decide();
				switch (t)
				{
				case 1:
					delMass(mass, ryad);
					ryad = VvodRyad();
					mesto = VvodMesto();
					mass = addMass(mass, ryad, mesto);
					fillMass(mass, ryad, mesto);
					break;
				case 2:
					fillMass(mass, ryad, mesto);
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			if (y == 0)
			{
				printf("�� ��� �� ����� ������, ��������� �������.\n");
			}
			else
			{
				printMass(mass, ryad, mesto);
			}
			break;
		case 3:
			if (y == 0)
			{
				printf("�� ��� �� ����� ������, ��������� �������.\n");
			}
			else
			{
				ticket(mass, ryad, mesto);
			}
			break;
		case 4:
			if (y == 0)
			{
				printf("�� ��� �� ����� ������, ��������� �������.\n");
			}
			else
			{
				ticket2(mass, ryad, mesto);
			}
			break;
		case 5:
			if (y == 0)
			{
				printf("�� ��� �� ����� ������, ��������� �������.\n");
			}
			else
			{
				buyticket(mass, ryad, mesto);
			}
			break;
		case 6:
			if (y == 0)
			{
				printf("�� ��� �� ����� ������, ��������� �������.\n");
			}
			else
			{
				sellticket(mass, ryad, mesto);
			}
			break;
		case 0:
			if (y == 1)
			{
				delMass(mass, ryad);
			}
			break;
		default:
			printf("�� ����� ������������ ��������, ��������� �������.\n");
			break;
		}
	} while (m != 0);
	return 0;
}

int menu()
{
	int m;
	printf("���������.\n");
	printf("1 - ������ ���������� � ��������� �������.\n");
	printf("2 - ������� ���� � ��������� �������.\n");
	printf("3 - ��������� ���-�� ��������� �������.\n");
	printf("4 - ��������� ���-�� ��������� ������� � ����������� ����.\n");
	printf("5 - ������������� �����.\n");
	printf("6 - �������� ������������.\n");
	printf("0 - ����� �� ���������.\n");
	printf("��������: ");
	scanf_s("%d", &m);
	system("cls");
	return m;
}

int VvodRyad()
{
	int ryad;
	do
	{
		printf("������� ���-�� �����: ");
		scanf_s("%d", &ryad);
		if (ryad <= 0)
		{
			system("cls");
			printf("�� ����� ������������ ��������, �������� �������.\n ");
		}
	} while (ryad <= 0);
	system("cls");
	return ryad;
}

int VvodMesto()
{
	int mesto;
	do
	{
		printf("������� ���-�� �����: ");
		scanf_s("%d", &mesto);
		if (mesto <= 0)
		{
			system("cls");
			printf("�� ����� ������������ ��������, �������� �������.\n ");
		}
	} while (mesto <= 0);
	system("cls");
	return mesto;
}

int **addMass(int **mass, int ryad, int mesto)
{
	int i;
	mass = new int*[ryad];
	for (int i = 0; i < ryad; i++)
	{
		mass[i] = new int[mesto];
	}
	return mass;
}

int decide()
{
	int change;
	do
	{
		printf("�������� �������� ���-�� ����� � ����?\n");
		printf("1 - ��.\n");
		printf("2 - ���.\n");
		printf("��������: ");
		scanf_s("%d", &change);
		system("cls");
		if (change != 1 && change != 2)
		{
			printf("�� ����� ������������ ��������, ��������� �������\n");
		}
	} while (change != 2 && change != 1);
	return change;
}

void fillMass(int **mass, int ryad, int mesto)
{
	int sposob, i, j;





	do
	{
		printf("��� �� ������ ��������� ����������?\n");
		printf("1 - � ������.\n");
		printf("2 - ��������.\n");
		printf("3 - ����.\n");
		printf("��������: ");
		scanf_s("%d", &sposob);
		system("cls");

		switch (sposob)
		{
		case 1:
			for (i = 0; i < ryad; i++)
			{
				for (j = 0; j < mesto; j++)
				{
					while (mass[i][j] != 1 && mass[i][j] != 0)
					{
						printf("������� 1, �� ������� 0\n");
						printf("a[%d][%d] = ", i + 1, j + 1);
						scanf_s("%d", &mass[i][j]);
						if (mass[i][j] != 1 && mass[i][j] != 0)
						{
							printf("�� ����� �������� ��������, ��������� �������.");
						}
						printf("\n");
					}

				}
			}
			system("cls");
			break;
		case 2:
			for (i = 0; i < ryad; i++)
			{
				for (j = 0; j < mesto; j++)
				{
					mass[i][j] = rand() % 2;
				}
			}
			break;
		case 3:
			for (i = 0; i < ryad; i++)
			{
				for (j = 0; j < mesto; j++)
				{
					mass[i][j] = 0;
				}
			}
			break;
		default:
			printf("�� ����� ������������ ��������, ��������� �������.\n");
			break;
		}
	} while (sposob < 1 || sposob > 3);
}

void delMass(int **mass, int ryad)
{
	int i;
	for (i = 0; i < ryad; i++)
	{
		delete[] mass[i];
	}
	delete[] mass;
}

void printMass(int **mass, int ryad, int mesto)
{
	int k, j, i, space = 0, b, l;
	for (k = ryad; k > 9; k /= 10)
	{
		space = space + 1;
	}
	k = space;
	while (space != 0)
	{
		printf(" ");
		space = space - 1;
	}
	printf("�����| ");
	for (j = 0; j < mesto; j++)
	{
		printf("%d ", j + 1);
	}
	printf("\n");
	space = k;
	while (space != 0)
	{
		printf("_");
		space = space - 1;
	}
	printf("_______");
	for (j = 0; j < mesto; j++)
	{
		space = 2;
		for (l = j; l > 9; l /= 10)
		{
			space = space + 1;
		}
		while (space != 0)
		{
			printf("_");
			space = space - 1;
		}
	}
	printf("\n");
	for (i = ryad - 1; i >= 0; i�)
	{
		b = 0;
		for (space = i + 1; space > 9; space /= 10)
		{
			b = b + 1;
		}
		space = k - b;
		while (space != 0)
		{
			printf(" ");
			space = space - 1;
		}
		printf("��� %d| ", i + 1);
		for (j = 0; j < mesto; j++)
		{
			for (b = j + 1; b > 9; b /= 10)
			{
				space = space + 1;
			}
			while (space != 0)
			{
				printf(" ");
				space = space - 1;
			}
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
}

void ticket(int **mass, int ryad, int mesto)
{
	int i, j, ticket = 0, p;
	for (i = 0; i < ryad; i++)
	{
		for (j = 0; j < mesto; j++)
		{
			if (mass[i][j] == 1)
			{
				ticket = ticket + 1;
			}
		}
	}
	p = ticket % 100;
	switch (p)
	{
	case 11:
	case 12:
	case 13:
	case 14:
		printf("%d ������� �������\n", ticket);
		break;
	default:
		p = ticket % 10;
		switch (p)
		{

		case 1:
			printf("%d ����� ������\n", ticket);
			break;
		case 2:
		case 3:
		case 4:
			printf("%d ������ �������\n", ticket);
			break;
		default:
			printf("%d ������� �������\n", ticket);
			break;
		}
		break;
	}
	ticket = 0;
}

void ticket2(int **mass, int ryad, int mesto)
{
	printMass(mass, ryad, mesto);
	int n, j, i, p, ticket2 = 0;
	do
	{
		printf("������� ����� ����: ");
		scanf_s("%d", &n);
		if (n < 1 || n > ryad)
		{
			system("cls");
			printf("������ ���� ����\n");
		}
	} while (n < 1 || n > ryad);
	system("cls");
	for (j = 0; j < mesto; j++)
	{
		if (mass[n - 1][j] == 1)
		{
			ticket2 = ticket2 + 1;
		}
	}
	p = ticket2 % 100;
	switch (p)
	{
	case 11:
	case 12:
	case 13:
	case 14:
		printf("%d ������� ������� � %d ����\n", ticket2, n);
		break;
	default:
		p = ticket2 % 10;
		switch (p)
		{
		case 1:
			printf("%d ����� ������ � %d ����\n", ticket2, n);
			break;
		case 2:
		case 3:
		case 4:
			printf("%d ������ ������� � %d ����\n", ticket2, n);
			break;
		default:
			printf("%d ������� ������� � %d ����\n", ticket2, n);
			break;
		}
		break;
	}
	ticket2 = 0;
}

void buyticket(int **mass, int ryad, int mesto)
{
	printMass(mass, ryad, mesto);
	int x, y;
	do
	{





		printf("������ ���\n");
		scanf_s("%d", &x);
		if (x <= 0 || x > ryad)
		{
			printf("�� ����� ����������� �����\n");
		}
	} while (x <= 0 || x > ryad);
	system("cls");
	do
	{
		printf("������ �����\n");
		scanf_s("%d", &y);
		if (y <= 0 || y > ryad)
		{
			printf("�� ����� ����������� �����\n");
		}
	} while (y <= 0 || y > ryad);
	system("cls");
	mass[x - 1][y - 1] = 1;
}
void sellticket(int **mass, int ryad, int mesto)
{
	printMass(mass, ryad, mesto);
	int x, y;
	do
	{
		printf("������ ���\n");
		scanf_s("%d", &x);
		if (x <= 0 || x > ryad)
		{
			printf("�� ����� ����������� �����\n");
		}
	} while (x <= 0 || x > ryad);
	system("cls");
	do
	{
		printf("������ �����\n");
		scanf_s("%d", &y);
		if (y <= 0 || y > ryad)
		{
			printf("�� ����� ����������� �����\n");
		}
	} while (y <= 0 || y > ryad);
	system("cls");
	mass[x - 1][y - 1] = 0;
}











