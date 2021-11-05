//#include <iostream>
//#include <conio.h>
//using namespace std;

//
//struct Stek {
//	int data;
//	Stek* prev;
//};
//
//Stek* CreateStek(Stek* Top);
//Stek* Push(Stek* Top, int data);
//Stek* Pop(Stek* Top);
//Stek* Show(Stek* Top);
//void menu();
//
//int main() {
//	setlocale(LC_ALL, "");
//	Stek* Stek = NULL;
//	int data, countOfElements;
//	char c;
//	do {
//		system("cls");
//		menu();
//		c = _getch();
//		system("cls");
//		switch (c) {
//		case '1': {
//			Stek = CreateStek(Stek);
//			break;
//		}
//		case '2':
//			Stek = Show(Stek);
//			break;
//		case '3':
//			Stek = Pop(Stek);
//			break;
//		case '4':
//			//Stek = findSum(Stek);
//			break;
//		default:
//			break;
//		}
//		system("pause");
//	} while (c != 27);
//	while (Stek != NULL)
//		Stek = Pop(Stek);
//	delete Stek;
//	return 0;
//}
//
//
//Stek* CreateStek(Stek* Top) {
//	int data; char c;
//	do {
//		cout << "Введите значение: "; cin >> data;
//		Top = Push(Top, data);
//		cout << "Продолжаем ввод? ESC - нет. ";
//		c = _getch();
//		cout << endl;
//	} while (c != 27);
//	return Top;
//}
//
//Stek* Push(Stek* Top, int data) {
//	Stek* temp = new Stek;
//	if (Top == NULL)
//		temp->prev = NULL;
//	else
//		temp->prev = Top;
//	temp->data = data;
//	return temp;
//}
//
//Stek* Pop(Stek* Top) {
//	Stek* temp = Top;
//	if (Top != NULL) {
//		Top = Top->prev;
//		delete temp;
//	}
//	return Top;
//}
//
//Stek* Show(Stek* Top) {
//	Stek* temp = NULL;
//	if (Top == NULL)
//		cout << "Стек пустой." << endl;
//	while (Top != NULL) { //Прошли по элементам, вывели и удалили их
//		cout << "Значение: " << Top->data << "\tТекущий адрес: " << Top << "\tАдрес предыдущего: " << Top->prev << endl;
//		temp = Push(temp, Top->data);
//		Top = Pop(Top);
//	}
//	while (temp != NULL) {
//		Top = Push(Top, temp->data);
//		temp = Pop(temp);
//	}
//	return Top;
//}
//
//void menu() {
//	cout << "1 - add element to stack" << endl;
//	cout << "2 - show elements of stack" << endl;
//	cout << "3 - delete element of stack" << endl;
//	cout << "4 - summa" << endl;
//}

/*#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
struct queue
{
	int data;
	queue* next;
} *head, * tail;
void Create();
void add(int);
void Delete(void);
void showqueue();
bool isEmpty(queue*);
int main()
{
	setlocale(LC_ALL, "ukr");
	char a;
	bool flag = true;
	while (flag)
	{
		puts("Меню:");
		puts("0 - Exit");
		puts("1 - Add");
		puts("2 - Delete");
		puts("3 - Print");
		a = _getch();
		switch (a)
		{
		case '0': flag = false; break;
		case '1': Create(); break;
		case '2': Delete(); break;
		case '3': showqueue(); break;
		default: cout << "Ще раз! \n\n";
		}
	};
};
void add(int data)
{
	queue* temp = new queue;
	temp->data = data;
	temp->next = NULL;
	if (isEmpty(head))
		head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
}
void Create()
{
	int par;
	queue* tmp = NULL;
	puts("Введiть елемент");
	cin >> par;
	add(par);
	cout << "Елемент " << par << " додано до черги " << endl;
};
void Delete()
{
	if (head == NULL)
	{
		puts("Неможливо видалити. Черга - порожня! ");
	}
	else
	{
		queue* tmp;
		int tint;
		tmp = head;
		head = head->next;
		tint = tmp->data;
		delete tmp;
	}
};
bool isEmpty(queue* head)
{
	return (head == NULL) ? true : false;
}
void showqueue()
{
	queue* Head = NULL;
	queue* tempQueue = new queue;
	queue* tempHead = NULL;
	Head = head;
	if (isEmpty(head))
	{
		cout << "Черга порожня!" << endl;
		return;
	}
	tempQueue->data = NULL;
	tempQueue->next = NULL;
	tempHead = tempQueue;
	while (head != NULL)
	{
		cout << "data: " << head->data << "\t Adress: " << head << "\t Adress next: " << head->next << endl;
		tempQueue->next = new queue;
		tempQueue->next->data = head->data;
		tempQueue->next->next = NULL;
		tempQueue = tempQueue->next;
		Delete();
	}
	tempQueue = tempHead->next;
	while (tempQueue)
	{
		add(tempQueue->data);
		tempQueue = tempQueue->next;
	}
	Head = tempHead->next;
	while (Head)
	{
		tempQueue = Head;
		Head = Head->next;
		delete tempQueue;
	}
}*/

#include <iostream>
#include <conio.h>
using namespace std;

struct Dek {
	int data;
	Dek* prev;
	Dek* next;
};

Dek* CreateDek(int data);
Dek* AddRight(Dek* dek, int data);
Dek* AddLeft(Dek* dek, int data);
Dek* DelRight(Dek* dek);
Dek* DelLeft(Dek* dek);
void PrintDek(Dek* dek);

bool IsEmpty(Dek* dek) {
	if (dek == NULL) return true;
	return false;
}

int main()
{
	setlocale(LC_ALL, "ukr");
	int data;
	cout << "Введiть перший елемент деку = ";
	cin >> data;
	Dek* dek = CreateDek(data);
	cout << "Додати злiва = ";
	cin >> data;
	dek = AddLeft(dek, data);
	cout << "Додати зправа = ";
	cin >> data;
	dek = AddRight(dek, data);
	cout << "Додати злiва = ";
	cin >> data;
	dek = AddLeft(dek, data);
	cout << "\n Дек: ";
	PrintDek(dek);
	cout << "\n\n Елемент злiва: \n";
	dek = DelLeft(dek);
	cout << "\n Елемент зправа: \n";
	dek = DelRight(dek);
	cout << "\n\n Поточний дек: ";
	PrintDek(dek);
	//cout << "\n\n Очищення деку...\n";
	//dek = ClearDek(dek);
	//cout << "\n Дек порожнiй ? ";
	//if (IsEmpty(dek) == true)
		//cout << "Yes" << endl; else cout << "No" << endl;
	system("pause");
	return 0;
}

Dek* CreateDek(int data) {
	Dek* temp = new Dek;
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

Dek* AddRight(Dek* dek, int data) {
	Dek* temp = new Dek;
	while (dek->next != 0)
		dek = dek->next;
	temp->data = data;
	temp->prev = dek;
	temp->next = NULL;
	dek->next = temp; // Меняем адресацию в предыдущем элементе
	return temp;
}

Dek* AddLeft(Dek* dek, int data) {
	Dek* temp = new Dek;
	while (dek->prev != 0)
		dek = dek->prev;
	temp->data = data;
	temp->prev = NULL;
	temp->next = dek;
	dek->prev = temp;
	return temp;
}

Dek* DelRight(Dek* dek) {
	while (dek->next != 0)
		dek = dek->next;
	Dek* temp = dek;
	dek = dek->prev;
	dek->next = NULL;
	delete temp;
	return dek;
}

Dek* DelLeft(Dek* dek) {
	while (dek->prev != 0)
		dek = dek->prev;
	Dek* temp = dek;
	dek = dek->next;
	dek->prev = NULL;
	delete temp;
	return dek;
}

void PrintDek(Dek* dek) {//Здесь двусвязный список, не дек!
	while (dek->prev != 0)
		dek = dek->prev;
	do
	{
		cout << dek->data << " ";
		dek = dek->next;
	} while (dek != NULL);
}
