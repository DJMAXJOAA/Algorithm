#include <iostream>
using namespace std;

enum Direction
{
	LEFT, RIGHT,
};

struct Node
{
	int data;
	Node* parent; // 부모 노드
	Node* left;
	Node* right;
	Node() : left(nullptr), right(nullptr), parent(nullptr) {}
};

class Tree
{
private:
	Node* head;

public:
	Node* GetHead() { return head; }

public:
	void Insert(int data);
	void Delete(int data);
	void PrintAll(Node* pt);

public:
	Tree() : head(nullptr) {}
	~Tree() {}
};

void Tree::Insert(int data)
{
	Node* temp = new Node;
	temp->data = data;
	// 노드가 없는 경우
	if (head == nullptr)
	{
		head = temp;
		return;
	}

	Node* current = head;
	while (1)
	{
		// 왼쪽
		if (data < current->data)
		{
			if (current->left == nullptr)
			{
				temp->parent = current;
				current->left = temp;
				return;
			}
			current = current->left;
		}

		// 오른쪽
		else if (data > current->data)
		{
			if (current->right == nullptr)
			{
				temp->parent = current;
				current->right = temp;
				return;
			}
			current = current->right;
		}

		else // 동일한 수 -> 오류
			return;
	}
		
}

void Tree::Delete(int data)
{
	// 검색
	Node* current = head;
	int direction = LEFT;
	while (1)
	{
		// 검색 완료
		if (data == current->data)
			break;

		// 검색 실패
		else if (current->left == nullptr && current->right == nullptr)
		{
			cout << "검색 실패" << endl;
			return;
		}

		// 왼쪽
		else if (data < current->data)
		{
			current = current->left;
			direction = LEFT;
		}

		// 오른쪽
		else if (data > current->data)
		{
			current = current->right;
			direction = RIGHT;
		}
	}

	// 1. 자식이 없는 경우
	if (current->left == nullptr && current->right == nullptr)
	{
		if (direction == LEFT)
		{
			current->parent->left = nullptr;
		}
		else if (direction == RIGHT)
		{
			current->parent->right = nullptr;
		}
		delete current;
		return;
	}

	// 2. 자식이 하나만 있는 경우
	if (current->left != nullptr) // 왼쪽
	{
		current->left->parent = current->parent;
		current->parent->left = current->left;
		delete current;
		return;
	}
	else if (current->right != nullptr) // 오른쪽
	{
		current->right->parent = current->parent;
		current->parent->right = current->right;
		delete current;
		return;
	}
	

	// 3. 자식이 두개 있는 경우
	Node* temp = current->left;
	while (1)
	{
		if (temp->right == nullptr)
		{
			// 끊어 놓기, 부모 변경
			if (temp->left != nullptr)
				temp->parent->right = temp->left;
			else
				temp->parent->right = nullptr;
			temp->parent = current->parent;

			// 스왑
			Node* swap = temp;
			temp = current;
			current = swap;

			return;
		}
		temp = temp->right;
	}
}

void Tree::PrintAll(Node* pt)
{
	if (pt == nullptr)
		return;
	PrintAll(pt->left);
	PrintAll(pt->right);
	cout << pt->data << " / ";
}

int main()
{
	Tree tree;
	int select, data;
	while (1)
	{
		cout << "ㄱㄱ" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cin >> data;
			tree.Insert(data);
			break;
		case 2:
			cin >> data;
			tree.Delete(data);
			break;
		case 3:
			tree.PrintAll(tree.GetHead());
			break;
		default:
			break;
		}
	}
	return 0;
}