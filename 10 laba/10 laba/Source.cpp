#include<stdio.h>
#include<locale.h>
#include<string.h>

int menu();
char probel();
char Name();
char palindrom();
char exe();
char a_na_b();
char sosednie();
char a();
char fio();
char imya();
char slova();

int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		switch (menu())
		{
		case 1: probel(); break;
		case 2:Name(); break;
		case 3:palindrom(); break;
		case 4:exe(); break;
		case 5: a_na_b(); break;
		case 6:sosednie(); break;
		case 7: a(); break;
		case 8: fio();  break;
		case 9: imya(); break;
		case 10: slova(); break;
		case 11: return 0;
		default: printf("\n�������� �����\n");
		}
	}

}

int menu() {
	printf("\n�������:\n");
	printf("1. ����� ������� �� ������ ������ �������\n");
	printf("2. ����� � ������ �������� 'Name' �� 'Name1' � ��������\n");
	printf("3. ����� ������, �������� �� �������� ������ �����������\n");
	printf("4. ����� �������� ���������� ��������� ����� �� .exe\n");
	printf("5. ����� �������� � ������ ��� a �� b\n");
	printf("6. ����� �������� ������� �������� ������� � ������\n");
	printf("7. ����� ������, ������� ���� � ������ ������������� �� �\n");
	printf("8. ����� ������ ��� � �������� ����������� ���� '������, ��� ��������!'\n");
	printf("9. ����� ������ ��� � �������� ����������� ���� '������, ���!'\n");
	printf("10. ����� ��������� �������� � ����������� �����\n");
	printf("11. ��� ������\n");
	int nomer;
	scanf_s("%d", &nomer);
	getchar();
	return nomer;
}
//�������� ������ ��������
char probel() {
	char str[100];
	printf("������� ������\n");
	fgets(str, 100, stdin);
	fflush(stdin);

	int n = strlen(str);
	int k = 0;
	while (k != n - 1)
	{
		if (str[k] == ' ' && str[k + 1] == ' ')
		{
			for (int j = k; j < n; j++)
			{
				str[j] = str[j + 1];
			}

		}
		else k++;
	}
	if (str[0] == ' ') {
		for (int j = 0; j < n; j++)
		{
			str[j] = str[j + 1];
		}
	}
	puts(str);

	return *str;
}

//��������� Name �� Name1 � ��������
char Name() {
	char str[100];
	printf("������� ������\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	int n = strlen(str) - 1;
	//printf("%d", n);
	for (int i = 0; i <= n - 3; i++) {
		if (str[i] == 'N' && str[i + 1] == 'a' && str[i + 2] == 'm' && str[i + 3] == 'e' && str[i + 4] != '1') {
			for (int k = n - 1; k >= i + 4; k--) {
				str[k + 1] = str[k];
			}
			str[i + 4] = '1';
			i++;
		}

		if (str[i] == 'N' && str[i + 1] == 'a' && str[i + 2] == 'm' && str[i + 3] == 'e' && str[i + 4] == '1') {

			str[i + 4] = ' ';
			for (int k = i + 5; k < 100 - i - 5; k++) {
				str[k] = str[k + 1];
			}
		}
	}
	str[n + 1] = '\0';
	puts(str);
	return *str;
}

//��������, �������� �� ������ �����������
char palindrom() {
	char str[100];
	printf("������� ������\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	int n = strlen(str) - 1;
	int count = 0;
	for (int i = 0; i <= n / 2; i++) {
		if (str[i] == str[n - i - 1]) {
			count++;
		}
	}
	if (count == (n / 2) + 1) {
		printf("�������� ������ � ���������\n");
	}
	else printf("�������� ������ �� �������� �����������\n");
	return *str;
}

//��������� ���������� �� .exe
char exe() {
	char str[30];
	printf("������� ��� �����\n");
	fgets(str, 30, stdin);
	fflush(stdin);
	int  n = strlen(str) - 1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '.') {
			count++;
		}
	}
	if (count == 0 || count > 2) {
		printf("������������ ����� �����\n");
	}
	else {
		if (count == 1) {
			char str1[] = ".exe";
			int count = 0;
			for (int i = 0; str[i] != 0; i++) {
				count++;
			}
			count--;
			int i;
			for (i = 0; str[i] != 0; i++) {
				str[i + count] = str1[i];
			}

			str[i + count] = '\0';
			printf("��������� ����:\n");
			puts(str);

		}
		if (count == 2) {
			int k;
			for (int i = n; i > 0; i--) {
				if (str[i] == '.') {
					k = i;
					break;
				}
			}
			str[k + 1] = 'e';
			str[k + 2] = 'x';
			str[k + 3] = 'e';
			str[k + 4] = '\0';
			printf("��������� ����:\n");
			puts(str);
		}
	}
}

//������ � �� �
char a_na_b() {
	char str[100];
	printf("������� ������\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'a') {
			str[i] = 'b';
		}
		if (str[i] == 'A') {
			str[i] = 'B';
		}
	}
	puts(str);
	return *str;
}

//����������� ��������
char sosednie() {
	char str[80];
	printf("������� ������, ����� �������� ������� �������� �����\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	int n = strlen(str) - 1;
	char buf;
	for (int i = 0; i < n; i += 2) {
		buf = str[i];
		str[i] = str[i + 1];
		str[i + 1] = buf;
	}
	puts(str);
	return *str;
}

//���������� ����, ��������������� �� �
char a() {
	char str[100];
	printf("������� ������, ����� ������� ���������� ���� � ���, ��������������� �� �\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	int n = strlen(str);
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a' && str[i + 1] == ' ') {
			count++;
		}
	}
	if (str[n - 2] == 'a') count++;

	if (count == 0) {
		printf("� ������ ��� ����, ��������������� �� �\n");
	}
	else {
		printf("\n���������� ����, ��������������� �� �, ����� %d", count);
	}
	return *str;
}

//������, ���!
char fio() {
	char str[100];
	printf("������� ���\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	int n = strlen(str) - 1;
	int k;

	for (int i = 0; i < n; i++) {
		if (str[i] == ' ' && str[i - 1] != ' ') {
			k = i + 1;
			break;
		}
	}
	int x = k;
	int i = 0;
	while (k < n) {
		while (i < n) {
			str[i] = str[k];
			i++;
			k++;
		}
	}
	str[n - x] = '!';
	printf("������, %s", str);
	return *str;
}

//������, ���!
char imya() {
	char str[100];
	printf("������� ���\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	int n = strlen(str) - 1;
	str[n] = '!';
	printf("������, %s", str);
	return *str;
}

//��������� ����
char slova() {
	char str[100];
	printf("������� ������, ����� ������� � �� ������\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			if (str[i] == ' ' && str[i + 1] == ' ') {
				continue;
			}
			else {
				str[i] = '\n';
			}
		}

	}
	puts(str);
	return *str;
}
