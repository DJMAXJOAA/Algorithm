#include <iostream>
using namespace std;

enum Direction
{
	LEFT, RIGHT,
};

struct Node
{
	int data;
	Node* parent; // �θ� ���
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
	// ��尡 ���� ���
	if (head == nullptr)
	{
		head = temp;
		return;
	}

	Node* current = head;
	while (1)
	{
		// ����
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

		// ������
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

		else // ������ �� -> ����
			return;
	}
		
}

void Tree::Delete(int data)
{
	// �˻�
	Node* current = head;
	int direction = LEFT;
	while (1)
	{
		// �˻� �Ϸ�
		if (data == current->data)
			break;

		// �˻� ����
		else if (current->left == nullptr && current->right == nullptr)
		{
			cout << "�˻� ����" << endl;
			return;
		}

		// ����
		else if (data < current->data)
		{
			current = current->left;
			direction = LEFT;
		}

		// ������
		else if (data > current->data)
		{
			current = current->right;
			direction = RIGHT;
		}
	}

	// 1. �ڽ��� ���� ���
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

	// 2. �ڽ��� �ϳ��� �ִ� ���
	if (current->left != nullptr) // ����
	{
		current->left->parent = current->parent;
		current->parent->left = current->left;
		delete current;
		return;
	}
	else if (current->right != nullptr) // ������
	{
		current->right->parent = current->parent;
		current->parent->right = current->right;
		delete current;
		return;
	}
	

	// 3. �ڽ��� �ΰ� �ִ� ���
	Node* temp = current->left;
	while (1)
	{
		if (temp->right == nullptr)
		{
			// ���� ����, �θ� ����
			if (temp->left != nullptr)
				temp->parent->right = temp->left;
			else
				temp->parent->right = nullptr;
			temp->parent = current->parent;

			// ����
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
		cout << "����" << endl;
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