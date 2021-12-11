#include <iostream>
#include "tree.h"

//#define _CRTDBG_MAP_ALLOC 
//#include <stdlib.h>
//#include <crtdbg.h> 

using namespace std;


int capacity = 0;

//проверка ввода



int main() {

	setlocale(LC_ALL, "rus");
	tree* root = nullptr;

	int key = -1;

	while (key != 0) {

		cout << "Выберете действие:" << endl
			<< "[1] Вывод дерева на экран " << endl
			<< "[2] Добавление элементов" << endl
			<< "[3] Удаление элемента по его значению" << endl
			<< "[4] Поиск элемента по его значению" << endl
			<< "[5] Выполнить задание варианта 6" << endl
			<< "[0] Завершить выполнение программы" << endl << ">>> ";
		cin >> key;

		if (cin.get() != '\n') {
			cin.clear();
			while (cin.get() != '\n');
			key = -1;
			system("cls");
			cout << "Ошибка ввода. Введите число повторно." << endl;
			continue;
		}

		switch (key) {
		case 1: {
			system("cls");
			key = -1;
			if (capacity == 0) {
				cout << "Дерево пустое" << endl << endl;
				break;
			}
			print(root, 0);
			cout << endl;
			break;
		}
		case 2: {
			system("cls");
			key = -1;
			while (key == -1) {
				cout << "Введите количество вводимых элементов, либо [0] для выхода в меню:" << endl << endl << ">>> ";
				cin >> key;

				if (cin.get() != '\n') {
					cin.clear();
					while (cin.get() != '\n');
					key = -1;
					system("cls");
					cout << "Ошибка ввода. Введите число повторно." << endl;
					continue;
				}

				if (key < 0) {
					key = -1;
					system("cls");
					cout << "Ошибка ввода. Введите положительное число повторно." << endl;
					continue;
				}

				if (key == 0) {
					system("cls");
					key = -1;
					break;
				}

				system("cls");
				int buffer;
				cout << "Введите значения элементов" << endl << endl;
				for (int i = 0; i < key; i++) {
					cout << ">>> ";
					cin >> buffer;
					if (cin.get() != '\n') {
						cin.clear();
						while (cin.get() != '\n');
						cout << "Ошибка ввода. Введите число повторно." << endl;
						i--;
						continue;
					}
					if (search(root, buffer, -1) != nullptr) {
						cout << "Ошибка! Элементы АВЛ-дерева не могут повторяться" << endl;
						i--;
						continue;
					}
					root = push(root, buffer);
					buffer = 0;
					capacity++;
				}
				system("cls");
				cout << "Элементы были добавлено в дерево" << endl << endl;
				key = -2;
			}

			break;
		}
		case 3: {
			system("cls");
			key = -1;
			if (capacity == 0) {
				cout << "Дерево пустое" << endl << endl;
				break;
			}
			while (key == -1) {
				cout << "Введите значение элемента:" << endl << endl << ">>> ";
				cin >> key;

				if (cin.get() != '\n') {
					cin.clear();
					while (cin.get() != '\n');
					key = -1;
					system("cls");
					cout << "Ошибка ввода. Введите число повторно." << endl;
					continue;
				}
				system("cls");

				if (search(root, key, -1) == nullptr)
					cout << "Этого элемента в дереве нет" << endl << endl;
				else {
					cout << "Элемент " << key << " удалён" << endl << endl;

					root = remove(root, key);
					capacity--;
				}

				key = -2;				
				break;
			}

			break;
		}
		case 4: {
			system("cls");
			key = -1;
			if (capacity == 0) {
				cout << "Дерево пустое" << endl << endl;
				break;
			}
			while (key == -1) {
				cout << "Введите значение элемента:" << endl << endl << ">>> ";
				cin >> key;

				if (cin.get() != '\n') {
					cin.clear();
					while (cin.get() != '\n');
					key = -1;
					system("cls");
					cout << "Ошибка ввода. Введите число повторно." << endl;
					continue;
				}
				system("cls");

				if (search(root, key, 0) == nullptr)
					cout << "Этого элемента в дереве нет" << endl << endl;
				else
					cout << "Элемент " << key << " найден в АВЛ-дереве" << endl << endl;

				key = -2;
				break;
			}

			break;
		}
		case 5: {
			system("cls");
			key = -1;
			if (capacity == 0) {
				cout << "Дерево пустое" << endl << endl;
				break;
			}
			key = -1;
			//std::queue<tree*> q = bfs(root);
			//std::queue<tree*> new_q;
			//int tmp, prev;
			//cout << "Исходное АВЛ-дерево:" << endl;
			//print(root, 0);
			//cout << endl << "Порядок обхода:" << endl;
			//while (!q.empty()) {
			//	tmp = q.front()->key;
			//	cout << tmp << " ";
			//	if (tmp < 0) {
			//		root = remove(root, tmp);
			//		capacity--;
			//		if (search(root, abs(tmp), -1) == nullptr) {
			//			root = push(root, abs(tmp));
			//			capacity++;
			//		}
			//	}
			//	tmp = q.front()->key;
			//	if((tmp % 4) == 0) {
			//		root = remove(root, tmp);
			//		capacity--;
			//		if (search(root, tmp / 2, -1) == nullptr) {
			//			root = push(root, tmp / 2);
			//			capacity++;
			//		}
			//	}
			//	q.pop();
			//}

			std::queue<tree*> q = bfs(root);
			std::queue<int> new_q;
			int tmp, prev, buf;
			cout << "Исходное АВЛ-дерево:" << endl;
			print(root, 0);
			cout << endl << "Порядок обхода:" << endl;
			while (!q.empty()) {
				tmp = q.front()->key;
				root = remove(root, tmp);
				capacity--;
				cout << tmp << " ";
				if (tmp < 0)
					tmp = abs(tmp);
				new_q.push(tmp);
				q.pop();
			}
			while (!new_q.empty()) {
				if (search(root, new_q.front(), -1) == nullptr) {
					root = push(root, new_q.front());
					capacity++;
				}
				new_q.pop();
			}

			cout << endl << endl << "Все отрицательные элементы заменены на их абсолютные величины. Повторения исключены. АВЛ-дерево:" << endl;
			print(root, 0);

			q = bfs(root);
			cout << endl << "Порядок обхода:" << endl;
			while (!q.empty()) {
				tmp = q.front()->key;
				root = remove(root, tmp);
				capacity--;
				cout << tmp << " ";
				if ((tmp % 4) == 0)
					tmp = tmp / 2;
				new_q.push(tmp);
				q.pop();
			}
			while (!new_q.empty()) {
				if (search(root, new_q.front(), -1) == nullptr) {
					root = push(root, new_q.front());
					capacity++;
				}
				new_q.pop();
			}

			cout << endl << endl << "Все элементы, делящиеся без остатка на 4 уменьшены в 2 раза. Повторения исключены. АВЛ-дерево:" << endl;
			print(root, 0);

			//cout << endl << endl << "Все отрицательные элементы заменены на их абсолютные величины. Все элементы," << endl <<
			//	"делящиеся без остатка на 4 уменьшены в 2 раза. Повторения исключены. АВЛ-дерево:" << endl;
			//print(root, 0);

			q = bfs(root);
			prev = q.back()->key;			// тут можно использовать 0?

			//cout << endl << "Порядок обхода:" << endl;
			//while (!q.empty()) {
			//	tmp = q.front()->key;
			//	cout << tmp << " ";
			//	root = remove(root, tmp);
			//	capacity--;
			//	if (search(root, abs(tmp - prev), -1) == nullptr) {
			//		root = push(root, abs(tmp - prev));
			//		capacity++;
			//	}
			//	prev = tmp;
			//	q.pop();
			//}

			cout << endl << "Порядок обхода:" << endl;
			while (!q.empty()) {
				tmp = q.front()->key;
				buf = tmp;
				root = remove(root, tmp);
				capacity--;
				cout << tmp << " ";
				tmp = abs(tmp - prev);
				prev = buf;
				new_q.push(tmp);
				q.pop();
			}
			while (!new_q.empty()) {
				if (search(root, new_q.front(), -1) == nullptr) {
					root = push(root, new_q.front());
					capacity++;
				}
				new_q.pop();
			}

			cout << endl << endl << "Все элементы заменены на модуль разницы с предыдущим элементом. Повторения исключены." << endl <<
				"АВЛ-дерево:" << endl;
			print(root, 0);
			cout << endl;

			break;
		}

		case 0: {
			system("cls");
			cout << "Завершение работы программы" << endl;
			key = 0;
			delete_tree(root);
			//_CrtDumpMemoryLeaks();
			break;
		}

		default:
			system("cls");
			key = -1;
			cout << "Ошибка ввода. Введите число повторно." << endl;
			break;
		}
	}


		

	

	return 0;
}