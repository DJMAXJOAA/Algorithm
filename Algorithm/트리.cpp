#include <iostream>
using namespace std;

enum Direction
{
	LEFT, RIGHT,
};

struct Node
{
	int data;
	Node* parent; // �� ����� �θ� ���
	Node* left;
	Node* right;
	Node() : data(0), left(nullptr), right(nullptr), parent(nullptr) {}
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
	while (1) // �˻����� �� �ڸ��� nullptr�϶����� ����
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

		else // ������ �� -> ��� ����
		{
			cout << "�ߺ��� ���� �Է��� �� �����ϴ�" << endl;
			delete temp;
			return;
		}
	}
}

void Tree::Delete(int data)
{
	if (head == nullptr)
	{
		cout << "����Ʈ�� ����ֽ��ϴ�" << endl;
		return;
	}

	Node* current = head; // current = �˻��� = ������� ��
	int direction; // �˻����� �θ��� ���� ��忴��? ������ ��忴��?
	while (1)
	{
		// �˻� �Ϸ�
		if (data == current->data)
			break;

		// �˻� ����
		else if (current->left == nullptr && current->right == nullptr)
		{
			cout << "����Ʈ�� ������� ���� �����ϴ�" << endl;
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
		if (head == current) // ����ϰ��(��� �Ѱ�)
		{
			head = nullptr;
			delete current;
			return;
		}
		if (direction == LEFT)
			current->parent->left = nullptr;
		if (direction == RIGHT)
			current->parent->right = nullptr;
		delete current;
		return;
	}

	// 2. �ڽ��� �ϳ��� �ִ� ���
	if (current->left != nullptr && current->right == nullptr) // ����
	{
		if (head == current) // ����ϰ��
		{
			current->left->parent = nullptr;
			head = current->left;
			delete current;
			return;
		}
		current->left->parent = current->parent;
		if (direction == LEFT)
			current->parent->left = current->left;
		if (direction == RIGHT)
			current->parent->right = current->left;
		delete current;
		return;
	}
	else if (current->left == nullptr && current->right != nullptr) // ������
	{
		if (head == current) // ����ϰ��
		{
			current->right->parent = nullptr;
			head = current->right;
			delete current;
			return;
		}
		current->right->parent = current->parent;
		if (direction == LEFT)
			current->parent->left = current->right;
		if (direction == RIGHT)
			current->parent->right = current->right;
		delete current;
		return;
	}

	// 3. �ڽ��� �ΰ� �ִ� ��� -> �˻����� �����ʿ� �ִ� ���� �߿� ���� ���� ���� ���
	Node* temp = current->right;

	while (temp->left != nullptr) // �˻����� ������ ����� ���� ���ʳ�� �˻�(���� �������)
	{
		temp = temp->left;
	}

	// �˻����� ������ ���� ���Ƴ���� ����
	if (temp != current->right) 
		temp->parent->left = nullptr; // �θ��� ���� ��� ����ֱ�
	temp->parent = current->parent;
	temp->left = current->left;
	current->left->parent = temp; // �˻����� ���� ����� �θ� -> ���� �ٲ��� �˻����� ������ ����

	if (current == head) // �˻����� ����� ����� �˻������� ���� ���
		head = temp;
	else                 // �˻��� ��ġ -> ������ ���� �ٲ��ش�
		current->parent->right = temp;

	if (temp != current->right) // �˻����� ������ ��尡 �ѹ��� ã��������(while�� �Ȱ�ġ��) �� ���ǽ��� �ǳʶ�
	{
		while (temp->right != nullptr) // ����߿� ���� ū ��� ã��
		{
			temp = temp->right;
		}
		current->right->parent = temp;
		temp->right = current->right;
	}
	delete current;
	return;
}

void Tree::PrintAll(Node* pt)
{
	if (pt == nullptr)
		return;
	PrintAll(pt->left);
	cout << pt->data << " / ";
	PrintAll(pt->right);
}

int main()
{
	Tree tree;
	int select, data;
	while (1)
	{
		cout << "\n1�� ���, 2�� ����, 3�� ��� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << " ��� �����Ͱ� : ";
			cin >> data;
			tree.Insert(data);
			break;
		case 2:
			cout << " ���� �����Ͱ� : ";
			cin >> data;
			tree.Delete(data);
			break;
		case 3:
			tree.PrintAll(tree.GetHead());
			cout << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}