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
		// 요소가 아예 없을때
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			tail = head;

			return;
		}

		// 1. 데이터가 들어갈 곳이 맨 처음일때
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

		// 2. 데이터가 들어갈 곳이 중간일때
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

		// 3. 데이터가 들어갈 곳이 마지막일때
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
				// 1. 지우려는곳이 맨 처음일때
				if (temp->prev == nullptr)
					head = temp->next;
				else
					temp->prev->next = temp->next;

				// 2. 지우려는곳이 맨 마지막일때
				if (temp->next == nullptr)
					tail = temp->prev;
				else
					temp->next->prev = temp->prev;

				delete temp;
				return;
			}
			temp = temp->next;
		}

		// 3. 발견 못했을 때
		cout << "지우려는 값이 없습니다." << endl;
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
		cout << "1. 추가 / 2. 제거 / 3. 전체출력 / 4. 역순출력" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "데이터 값 입력 : ";
			cin >> data;
			list.Insert(data);
			break;
		case 2:
			cout << "데이터 값 입력 : ";
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