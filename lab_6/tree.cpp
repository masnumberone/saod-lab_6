#include "tree.h"
#include <iostream> 

using namespace std;


int height(tree* R) {
	if (R != nullptr) return R->h;
	else return 0;
}

int bfactor(tree* R) {
	return height(R->right) - height(R->left);
}

void fixheight(tree* R) {
	int hl = height(R->left);
	int hr = height(R->right);
	if (hl > hr) R->h = hl + 1;
	else R->h = hr + 1;
}

tree* rotate_r(tree* p) {
	tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

tree* rotate_l(tree* q) {
	tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}



tree* balance(tree* R) {
	fixheight(R);
	if (bfactor(R) == 2) {
		if (bfactor(R->right) < 0)
			R->right = rotate_r(R->right);
		return rotate_l(R);
	}
	if (bfactor(R) == -2) {
		if (bfactor(R->left) > 0)
			R->left = rotate_l(R->left);
		return rotate_r(R);
	}
	return R; // балансировка не нужна
}

//tree* push(tree* &R, int val) {
//	if (R == nullptr) {
//		tree* root = new tree;
//		root->key = val;
//		root->right = nullptr;
//		root->left = nullptr;
//		R = root;
//		return R;
//	}
//	if (val < R->key) push(R->left, val);
//	else push(R->right, val);
//	balance(R);
//}

tree* push(tree* R, int val) {
	if (R == nullptr) {
		tree* root = new tree;
		root->key = val;
		root->right = nullptr;
		root->left = nullptr;
		R = root;
		return R;
	}
	if (val < R->key)
		R->left = push(R->left, val);
	else 
		R->right = push(R->right, val);
	return balance(R);
}

tree* search(tree*& R, int val, int k) {
	if (R == nullptr) return nullptr;
	if (val == R->key) {
		if (k>-1)
			cout << " оличествово шагов: " << k++ << endl;
		return R;
	}
	if (k>-1) k++;
	if (val < R->key) {
		if (R->left == nullptr)
			return nullptr;
		search(R->left, val, k);
	}
	else {
		if (R->right == nullptr)
			return nullptr;
		search(R->right, val, k);
	}
}

tree* find_min(tree* R) {
	if (R->left == nullptr) return R;
	else find_min(R->left);
}

tree* remove_min(tree* R) {
	if (R->left == NULL) return R->right;
	R->left = remove_min(R->left);
	return balance(R);
}

tree* remove(tree* R, int val) {
	if (R == nullptr) return 0;
	if (val < R->key)
		R->left = remove(R->left, val);
	else if (val > R->key)
		R->right = remove(R->right, val);
	else {
		tree* l = R->left;
		tree* r = R->right;
		delete R;
		if (r == nullptr) return l;
		tree* min = find_min(r);
		min->right = remove_min(r);
		min->left = l;
		return balance(min);
	}
	return balance(R);
}


void print(tree* R, int l) {
	if (R != nullptr) {
		print(R->right, l + 1);
		for (int i = 1; i <= l; i++) cout << "   ";
		cout << R->key << endl;
		print(R->left, l + 1);
	}
}



std::queue <tree*> bfs(tree* R) {
	std::queue <tree*> q, res;
	q.push(R);
	tree* tmp;
	while (!q.empty()) {
		res.push(q.front());
		q.pop();
		if (res.back()->left) {
			q.push(res.back()->left);
		}
		if (res.back()->right) {
			q.push(res.back()->right);
		}
	}
	return res;
}

void delete_tree(tree* R) {
	queue<tree*> q = bfs(R);
	stack<tree*> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while (!s.empty()) {
		R = remove(R, s.top()->key);
		s.pop();
	}
}