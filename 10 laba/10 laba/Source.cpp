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
		default: printf("\nНеверный выбор\n");
		}
	}

}

int menu() {
	printf("\nВведите:\n");
	printf("1. Чтобы удалить из строки лишние пробелы\n");
	printf("2. Чтобы в строке заменить 'Name' на 'Name1' и наоборот\n");
	printf("3. Чтобы узнать, является ли введённая строка палиндромом\n");
	printf("4. Чтобы изменить расширение введённого файла на .exe\n");
	printf("5. Чтобы заменить в строке все a на b\n");
	printf("6. Чтобы поменять местами соседние символы в строке\n");
	printf("7. Чтобы узнать, сколько слов в строке заканчиваются на а\n");
	printf("8. Чтобы ввести ФИО и вывелось приветствие вида 'Привет, имя отчество!'\n");
	printf("9. Чтобы ввести имя и вывелось приветствие вида 'Привет, имя!'\n");
	printf("10. Чтобы разделить введённые в предложении слова\n");
	printf("11. Для выхода\n");
	int nomer;
	scanf_s("%d", &nomer);
	getchar();
	return nomer;
}
//удаление лишних пробелов
char probel() {
	char str[100];
	printf("Введите строку\n");
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

//изменение Name на Name1 и наоборот
char Name() {
	char str[100];
	printf("Введите строку\n");
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

//проверка, является ли строка палиндромом
char palindrom() {
	char str[100];
	printf("Введите строку\n");
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
		printf("Введённая строка — палиндром\n");
	}
	else printf("Введённая строка не является палиндромом\n");
	return *str;
}

//изменение расширения на .exe
char exe() {
	char str[30];
	printf("Введите имя файла\n");
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
		printf("Неправильный адрес файла\n");
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
			printf("Изменённый файл:\n");
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
			printf("Изменённый файл:\n");
			puts(str);
		}
	}
}

//замена а на б
char a_na_b() {
	char str[100];
	printf("Введите строку\n");
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

//перемещение соседних
char sosednie() {
	char str[80];
	printf("Введите строку, чтобы поменять местами соседние буквы\n");
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

//количество слов, заканчивающихся на а
char a() {
	char str[100];
	printf("Введите строку, чтобы вывести количество слов в ней, заканчивающихся на а\n");
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
		printf("В строке нет слов, заканчивающихся на а\n");
	}
	else {
		printf("\nКоличество слов, заканчивающихся на а, равно %d", count);
	}
	return *str;
}

//Привет, ФИО!
char fio() {
	char str[100];
	printf("Введите ФИО\n");
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
	printf("Привет, %s", str);
	return *str;
}

//Привет, имя!
char imya() {
	char str[100];
	printf("Введите имя\n");
	fgets(str, 100, stdin);
	fflush(stdin);
	int n = strlen(str) - 1;
	str[n] = '!';
	printf("Привет, %s", str);
	return *str;
}

//Разбиение слов
char slova() {
	char str[100];
	printf("Введите строку, чтобы разбить её по словам\n");
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
