#include <iostream>
#include <string>

using namespace std;

struct Student
{
	int no;
	string name;
	Student* next;
};

void Add();
void Delete();
void PrintAll();

class List
{
public:
	List() { head = nullptr; }
	~List() {}
	void Add(int no, string name);
	void Delete(int no);
	void PrintAll();

private:
	Student* head;
};

// 전역 객체
List list;

int main()
{
	int input;
	bool out = true;

	while (out)
	{
		cout << "1번 : 등록, 2번 : 삭제, 3번 : 전체출력 : ";
		cin >> input;
		switch (input)
		{
		case 1:
			Add();
			break;
		case 2:
			Delete();
			break;
		case 3:
			PrintAll();
			break;
		default:
			out = false;
			break;
		}
	}

	return 0;
}

void List::Add(int no, string name)
{
	Student* temp = new Student;
	temp->name = name;
	temp->no = no;

	// 요소 없을때
	if (head == nullptr)
	{
		temp->next = nullptr;
		head = temp;

		return;
	}

	temp->next = head;
	head = temp;

	return;
}

void List::Delete(int no)
{
	if (head == nullptr)
	{
		cout << "목록없음" << endl;
		return;
	}

	Student* temp = head;

	if (temp->no == no) // 첫 요소
	{
		head = temp->next;
		temp->next = nullptr;
		delete temp;

		return;
	}

	Student* prev = temp;
	temp = temp->next;

	while (temp != nullptr)
	{
		if (temp->no == no)
		{
			if (temp->next == nullptr) // 맨 마지막 요소일때
			{
				prev->next = nullptr;
				temp->next = nullptr;
				delete temp;

				return;
			}
			prev->next = temp->next; // 중간 요소일때
			temp->next = nullptr;
			delete temp;

			return;
		}

		prev = temp;
		temp = temp->next;
	}

	// 못찾음 (지울거없음)
	cout << " 못찾음" << endl;
	return;
}

void List::PrintAll()
{
	Student* temp = head;
	if (temp == nullptr)
	{
		cout << "리스트에 학생들이 없습니다." << endl;
		return;
	}

	while (temp != nullptr)
	{
		cout << temp->no << endl;
		cout << temp->name << endl << endl;
		temp = temp->next;
	}
}

void Add()
{
	int no;
	string name;

	cout << "번호 입력 :";
	cin >> no;
	cout << "이름 입력 : ";
	cin >> name;
	list.Add(no, name);
}

void Delete()
{
	int no;

	cout << "지울 번호 입력 : ";
	cin >> no;
	list.Delete(no);
}

void PrintAll()
{
	cout << "모든 요소를 출력합니다" << endl;
	list.PrintAll();
}