#include <iostream>
#include "tree.h"

//#define _CRTDBG_MAP_ALLOC 
//#include <stdlib.h>
//#include <crtdbg.h> 

using namespace std;


int capacity = 0;

//�������� �����



int main() {

	setlocale(LC_ALL, "rus");
	tree* root = nullptr;

	int key = -1;

	while (key != 0) {

		cout << "�������� ��������:" << endl
			<< "[1] ����� ������ �� ����� " << endl
			<< "[2] ���������� ���������" << endl
			<< "[3] �������� �������� �� ��� ��������" << endl
			<< "[4] ����� �������� �� ��� ��������" << endl
			<< "[5] ��������� ������� �������� 6" << endl
			<< "[0] ��������� ���������� ���������" << endl << ">>> ";
		cin >> key;

		if (cin.get() != '\n') {
			cin.clear();
			while (cin.get() != '\n');
			key = -1;
			system("cls");
			cout << "������ �����. ������� ����� ��������." << endl;
			continue;
		}

		switch (key) {
		case 1: {
			system("cls");
			key = -1;
			if (capacity == 0) {
				cout << "������ ������" << endl << endl;
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
				cout << "������� ���������� �������� ���������, ���� [0] ��� ������ � ����:" << endl << endl << ">>> ";
				cin >> key;

				if (cin.get() != '\n') {
					cin.clear();
					while (cin.get() != '\n');
					key = -1;
					system("cls");
					cout << "������ �����. ������� ����� ��������." << endl;
					continue;
				}

				if (key < 0) {
					key = -1;
					system("cls");
					cout << "������ �����. ������� ������������� ����� ��������." << endl;
					continue;
				}

				if (key == 0) {
					system("cls");
					key = -1;
					break;
				}

				system("cls");
				int buffer;
				cout << "������� �������� ���������" << endl << endl;
				for (int i = 0; i < key; i++) {
					cout << ">>> ";
					cin >> buffer;
					if (cin.get() != '\n') {
						cin.clear();
						while (cin.get() != '\n');
						cout << "������ �����. ������� ����� ��������." << endl;
						i--;
						continue;
					}
					if (search(root, buffer, -1) != nullptr) {
						cout << "������! �������� ���-������ �� ����� �����������" << endl;
						i--;
						continue;
					}
					root = push(root, buffer);
					buffer = 0;
					capacity++;
				}
				system("cls");
				cout << "�������� ���� ��������� � ������" << endl << endl;
				key = -2;
			}

			break;
		}
		case 3: {
			system("cls");
			key = -1;
			if (capacity == 0) {
				cout << "������ ������" << endl << endl;
				break;
			}
			while (key == -1) {
				cout << "������� �������� ��������:" << endl << endl << ">>> ";
				cin >> key;

				if (cin.get() != '\n') {
					cin.clear();
					while (cin.get() != '\n');
					key = -1;
					system("cls");
					cout << "������ �����. ������� ����� ��������." << endl;
					continue;
				}
				system("cls");

				if (search(root, key, -1) == nullptr)
					cout << "����� �������� � ������ ���" << endl << endl;
				else {
					cout << "������� " << key << " �����" << endl << endl;

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
				cout << "������ ������" << endl << endl;
				break;
			}
			while (key == -1) {
				cout << "������� �������� ��������:" << endl << endl << ">>> ";
				cin >> key;

				if (cin.get() != '\n') {
					cin.clear();
					while (cin.get() != '\n');
					key = -1;
					system("cls");
					cout << "������ �����. ������� ����� ��������." << endl;
					continue;
				}
				system("cls");

				if (search(root, key, 0) == nullptr)
					cout << "����� �������� � ������ ���" << endl << endl;
				else
					cout << "������� " << key << " ������ � ���-������" << endl << endl;

				key = -2;
				break;
			}

			break;
		}
		case 5: {
			system("cls");
			key = -1;
			if (capacity == 0) {
				cout << "������ ������" << endl << endl;
				break;
			}
			key = -1;
			//std::queue<tree*> q = bfs(root);
			//std::queue<tree*> new_q;
			//int tmp, prev;
			//cout << "�������� ���-������:" << endl;
			//print(root, 0);
			//cout << endl << "������� ������:" << endl;
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
			cout << "�������� ���-������:" << endl;
			print(root, 0);
			cout << endl << "������� ������:" << endl;
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

			cout << endl << endl << "��� ������������� �������� �������� �� �� ���������� ��������. ���������� ���������. ���-������:" << endl;
			print(root, 0);

			q = bfs(root);
			cout << endl << "������� ������:" << endl;
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

			cout << endl << endl << "��� ��������, ��������� ��� ������� �� 4 ��������� � 2 ����. ���������� ���������. ���-������:" << endl;
			print(root, 0);

			//cout << endl << endl << "��� ������������� �������� �������� �� �� ���������� ��������. ��� ��������," << endl <<
			//	"��������� ��� ������� �� 4 ��������� � 2 ����. ���������� ���������. ���-������:" << endl;
			//print(root, 0);

			q = bfs(root);
			prev = q.back()->key;			// ��� ����� ������������ 0?

			//cout << endl << "������� ������:" << endl;
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

			cout << endl << "������� ������:" << endl;
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

			cout << endl << endl << "��� �������� �������� �� ������ ������� � ���������� ���������. ���������� ���������." << endl <<
				"���-������:" << endl;
			print(root, 0);
			cout << endl;

			break;
		}

		case 0: {
			system("cls");
			cout << "���������� ������ ���������" << endl;
			key = 0;
			delete_tree(root);
			//_CrtDumpMemoryLeaks();
			break;
		}

		default:
			system("cls");
			key = -1;
			cout << "������ �����. ������� ����� ��������." << endl;
			break;
		}
	}


		

	

	return 0;
}