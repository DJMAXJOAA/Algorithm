#include <iostream>
using namespace std;

struct Node
{
	int data;
	int next;
	int free_next;
};

class List
{
private:
	Node* node_list;
	int max_size;
	int now_size;
	int head;		// 현재 리스트의 커서
	int free_head;	// 현재 프리리스트를 가리키는 커서
	int last_index;
	
public:
	void Insert(int n);
	void Delete(int n);
	int Search(int n);
	void PrintAll();
	void FreeInsert(int n);
	void FreeDelete(int n);

public:
	List();
	~List();
};

int main()
{
	List list;

	int select;

	while (1)
	{
		
	}
	list.PrintAll();
	list.Delete(8);
	list.PrintAll();
	list.Delete(4);
	list.PrintAll();
	list.Insert(6);
	list.PrintAll();
	list.Delete(5);
	list.PrintAll();
	list.Insert(9);
	list.PrintAll();
	list.Insert(5);
	list.PrintAll();
	return 0;
}

List::List()
	: max_size(6)
	, now_size(6)
	, head(0)
	, free_head(-1)
{
	node_list = new Node[max_size];
	node_list[0].data = 2;
	node_list[1].data = 4;
	node_list[2].data = 5;
	node_list[3].data = 8;
	node_list[4].data = 3;
	node_list[5].data = 1;

	for (int i = 0; i < max_size - 1; i++)
	{
		node_list[i].next = i + 1;
		node_list[i].free_next = -1;
	}
	node_list[max_size - 1].next = -1;
	node_list[max_size - 1].free_next = -1;
	last_index = max_size - 1;
}

List::~List()
{
	delete node_list;
}

void List::Insert(int n)
{
	// 1. 배열의 크기가 다차면
	if (now_size == max_size)
	{
		cout << "용량 꽉참" << endl;
		return;
	}
	now_size++;
	cout << n << " 추가 = ";

	// 2. 배열의 크기가 꽉 안차면
	node_list[free_head].data = n;
	node_list[free_head].next = -1;
	node_list[last_index].next = free_head;
	last_index = free_head;

	// 프리리스트 갱신
	FreeDelete(free_head);
}

void List::Delete(int n)
{
	int index = Search(n);
	// 1. 검색 실패
	if (index == -1)
	{
		cout << "지울 요소를 찾지 못했습니다" << endl;
		return;
	}
	now_size--;
	cout << n << " 제거 = ";

	// 2. 찾음
	node_list[index].next = -1;
	FreeInsert(index);
}

int List::Search(int n)
{
	int index = head;

	// 0. 요소가 없으면
	if (head == -1)
		return -1;

	// 1. 처음 가리키는 index가 검색값일때
	if (n == node_list[head].data)
	{
		head = node_list[head].next;
		return index;
	}

	while (node_list[index].next != -1)
	{
		if (n == node_list[node_list[index].next].data)
		{
			// 3. 마지막 요소
			if (node_list[node_list[index].next].next == -1)
			{
				int temp = node_list[index].next;
				node_list[node_list[index].next].next = -1;
				node_list[index].next = -1;
				return temp;
			}
			
			// 2. 중간
			else
			{
				int temp = node_list[index].next;
				node_list[index].next = node_list[node_list[index].next].next;
				return temp;
			}
		}
		index = node_list[index].next;
	}

	// 4. 못찾았을때
	return -1;
}

// 리스트에서 빠져서 -> 프리리스트에 추가되는거
void List::FreeInsert(int n)
{
	// 1. 프리리스트 헤드가 없을 때 추가
	if (free_head == -1)
	{
		free_head = n;

		return;
	}

	int temp_head = free_head;
	// 2. 프리리스트 헤드가 있는데 추가
	while (node_list[temp_head].next != -1)
	{
		temp_head = node_list[free_head].next;
	}
	node_list[temp_head].free_next = n;
}

// 프리리스트에서 빠져서 -> 리스트에 추가되는거
void List::FreeDelete(int n)
{
	// 1. 프리리스트 지워버리면 요소 안남음
	if (node_list[free_head].free_next == -1)
	{
		free_head = -1;
	}

	// 2. 프리리스트 지워버려도 요소 남음
	free_head = node_list[free_head].free_next;
}



void List::PrintAll()
{
	int index = head;
	while (node_list[index].next != -1)
	{
		cout << node_list[index].data << " ";
		index = node_list[index].next;
	}
	cout << node_list[index].data << endl;
}