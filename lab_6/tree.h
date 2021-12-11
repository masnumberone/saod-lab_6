#pragma once
#include <queue>
#include <stack>

struct tree {
	int key;							// содержание узла
	int h = 1;							// высота узла
	bool visited = false;
	tree* left = nullptr;				// указатель на младшего потомка
	tree* right = nullptr;				// указатель на старшего потомка
};

void print(tree*, int);					// печать дерева
int height(tree*);						// возвращает h высоту узла
int bfactor(tree*);						// вычисляет фактор баланса узла
void fixheight(tree*);					// вычисляет высоту узла (calc)
tree* rotate_r(tree*);					// малое правое вращение
tree* rotate_l(tree*);					// малое левое вращение
tree* balance(tree*);					// балансировка узла
tree* push(tree*, int);					// добавление нового узла в дерево (принимает корень)
tree* search(tree*&, int, int);			// поиск по значению (принимает корень, ключ, счётчик)
tree* remove(tree*, int);				// удаление по значению (принимает корень, ключ)
std::queue <tree*> bfs(tree*);			// возвращает очередь обхода дерева в ширину
void delete_tree(tree*);				// удаление всего дерева с освобождением памяти

