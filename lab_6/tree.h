#pragma once
#include <queue>
#include <stack>

struct tree {
	int key;							// ���������� ����
	int h = 1;							// ������ ����
	bool visited = false;
	tree* left = nullptr;				// ��������� �� �������� �������
	tree* right = nullptr;				// ��������� �� �������� �������
};

void print(tree*, int);					// ������ ������
int height(tree*);						// ���������� h ������ ����
int bfactor(tree*);						// ��������� ������ ������� ����
void fixheight(tree*);					// ��������� ������ ���� (calc)
tree* rotate_r(tree*);					// ����� ������ ��������
tree* rotate_l(tree*);					// ����� ����� ��������
tree* balance(tree*);					// ������������ ����
tree* push(tree*, int);					// ���������� ������ ���� � ������ (��������� ������)
tree* search(tree*&, int, int);			// ����� �� �������� (��������� ������, ����, �������)
tree* remove(tree*, int);				// �������� �� �������� (��������� ������, ����)
std::queue <tree*> bfs(tree*);			// ���������� ������� ������ ������ � ������
void delete_tree(tree*);				// �������� ����� ������ � ������������� ������

