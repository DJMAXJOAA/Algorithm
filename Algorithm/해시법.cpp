#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "tree.h"
using namespace std;

class Hashing
{
private:
	int value;
	vector<Tree*> table;

public:
	Hashing() : value(13), table{} {
		for (int i = 0; i < value; i++)
		{
			Tree* temp = new Tree;
			table.push_back(temp);
		}
	}
	~Hashing() {}

public:
	void Insert(int data);
	void Delete(int data);
	void PrintAll();
};

void Hashing::Insert(int data)
{
	Node* temp = new Node;
	int key = data % value;
	temp->data = data;
	temp->key = key;

	table[key]->Insert(temp);
}

void Hashing::Delete(int data)
{
	int key = data % value;
	if (table[key] == nullptr) // 해시테이블 없으니까 삭제 불가
	{
		cout << "검색 결과 없음" << endl;
		return;
	}
	else
	{
		table[key]->Delete(data);
	}
}

void Hashing::PrintAll()
{
	for (int i = 0; i < value; i++)
	{
		cout << i << "번째 배열 : ";
		if (table[i] == nullptr)
			continue;
		else
			table[i]->PrintAll(table[i]->GetHead());
		cout << endl;
	}
}

int main()
{
	Hashing hash;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);

	for (int i = 0; i < 100; i++)
		hash.Insert(dis(gen));

	hash.PrintAll();

	cout << "11값 지우기" << endl;
	hash.Delete(11);

	hash.PrintAll();


	return 0;
}