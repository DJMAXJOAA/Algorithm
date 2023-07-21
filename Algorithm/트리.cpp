#include <iostream>
using namespace std;

enum Direction
{
	LEFT, RIGHT,
};

struct Node
{
	int data;
	Node* parent; // 내 노드의 부모 노드
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

	// 노드가 없는 경우
	if (head == nullptr)
	{
		head = temp;
		return;
	}

	Node* current = head;
	while (1) // 검색값이 들어갈 자리가 nullptr일때까지 루프
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

		else // 동일한 수 -> 등록 오류
		{
			cout << "중복된 수는 입력할 수 없습니다" << endl;
			delete temp;
			return;
		}
	}
}

void Tree::Delete(int data)
{
	if (head == nullptr)
	{
		cout << "리스트가 비어있습니다" << endl;
		return;
	}

	Node* current = head; // current = 검색값 = 지우려는 값
	int direction; // 검색값이 부모의 왼쪽 노드였나? 오른쪽 노드였나?
	while (1)
	{
		// 검색 완료
		if (data == current->data)
			break;

		// 검색 실패
		else if (current->left == nullptr && current->right == nullptr)
		{
			cout << "리스트에 지우려는 값이 없습니다" << endl;
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
		if (head == current) // 헤더일경우(요소 한개)
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

	// 2. 자식이 하나만 있는 경우
	if (current->left != nullptr && current->right == nullptr) // 왼쪽
	{
		if (head == current) // 헤더일경우
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
	else if (current->left == nullptr && current->right != nullptr) // 오른쪽
	{
		if (head == current) // 헤더일경우
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

	// 3. 자식이 두개 있는 경우 -> 검색값의 오른쪽에 있는 노드들 중에 제일 작은 수를 등록
	Node* temp = current->right;

	while (temp->left != nullptr) // 검색값의 오른쪽 노드중 제일 왼쪽노드 검색(제일 작은노드)
	{
		temp = temp->left;
	}

	// 검색값을 오른쪽 노드로 갈아끼우는 과정
	if (temp != current->right) 
		temp->parent->left = nullptr; // 부모의 왼쪽 노드 비워주기
	temp->parent = current->parent;
	temp->left = current->left;
	current->left->parent = temp; // 검색값의 왼쪽 노드의 부모를 -> 새로 바꿔줄 검색값의 오른쪽 노드로

	if (current == head) // 검색값이 헤더면 헤더를 검색값으로 새로 등록
		head = temp;
	else                 // 검색값 위치 -> 오른쪽 노드로 바꿔준다
		current->parent->right = temp;

	if (temp != current->right) // 검색값의 오른쪽 노드가 한번에 찾아졌으면(while문 안거치면) 이 조건식은 건너뜀
	{
		while (temp->right != nullptr) // 노드중에 제일 큰 노드 찾기
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
		cout << "\n1번 등록, 2번 제거, 3번 출력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << " 등록 데이터값 : ";
			cin >> data;
			tree.Insert(data);
			break;
		case 2:
			cout << " 제거 데이터값 : ";
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