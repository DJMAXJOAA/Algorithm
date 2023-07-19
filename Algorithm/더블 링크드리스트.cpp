#include <iostream>
using namespace std;

enum class Direction
{
	FORWARD, REVERSE
};

struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node() : next(nullptr), prev(nullptr) {}
};

class List
{
private:
	Node* head;
	Node* tail;

public:
	void Insert(int data)
	{
		// ��Ұ� �ƿ� ������
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			tail = head;

			return;
		}

		// 1. �����Ͱ� �� ���� �� ó���϶�
		if (data < head->data)
		{
			Node* temp = new Node;
			temp->data = data;
			temp->next = head;
			head->prev = temp;
			head = temp;

			return;
		}

		Node* temp = new Node;
		temp = head;

		// 2. �����Ͱ� �� ���� �߰��϶�
		while (temp->next != nullptr)
		{
			if (data < temp->next->data)
			{
				Node* temp2 = new Node;
				temp2->data = data;
				temp2->next = temp->next;
				temp2->prev = temp;

				temp->next->prev = temp2;
				temp->next = temp2;

				return;
			}
			temp = temp->next;
		}

		// 3. �����Ͱ� �� ���� �������϶�
		Node* temp2 = new Node;
		temp2->data = data;
		temp2->prev = temp;
		temp->next = temp2;
		tail = temp2;

		return;
	}
	void Remove(int data)
	{
		Node* temp = new Node;
		temp = head;

		while (temp!= nullptr)
		{
			if (data == temp->data)
			{
				// 1. ������°��� �� ó���϶�
				if (temp->prev == nullptr)
					head = temp->next;
				else
					temp->prev->next = temp->next;

				// 2. ������°��� �� �������϶�
				if (temp->next == nullptr)
					tail = temp->prev;
				else
					temp->next->prev = temp->prev;

				delete temp;
				return;
			}
			temp = temp->next;
		}

		// 3. �߰� ������ ��
		cout << "������� ���� �����ϴ�." << endl;
		return;
	}
	void PrintAll(Direction dir)
	{
		Node* temp = new Node;
		temp = head;

		if (dir == Direction::FORWARD)
			temp = head;
		if (dir == Direction::REVERSE)
			temp = tail;

		while (temp != nullptr)
		{
			cout << temp->data << " ";
			if (dir == Direction::FORWARD)
				temp = temp->next;
			if (dir == Direction::REVERSE)
				temp = temp->prev;
		}
		cout << endl;

		delete temp;
	}

public:
	List() : head(nullptr), tail(nullptr) {}
	~List() {}
};

int main()
{
	List list;
	int select;
	int data;

	while (1)
	{
		cout << "1. �߰� / 2. ���� / 3. ��ü��� / 4. �������" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "������ �� �Է� : ";
			cin >> data;
			list.Insert(data);
			break;
		case 2:
			cout << "������ �� �Է� : ";
			cin >> data;
			list.Remove(data);
			break;
		case 3:
			list.PrintAll(Direction::FORWARD);
			break;
		case 4:
			list.PrintAll(Direction::REVERSE);
			break;
		default:
			break;
		}
	}

	return 0;
}