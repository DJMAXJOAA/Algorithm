#include <iostream>
#include <string>

using namespace std;

struct Student
{
	int no;
	string name;
	Student* next;
};

class List
{
public:
	List() { head = nullptr; current = nullptr; }
	~List() {}
	void Add(int no, string name);
	void Delete(int no);
	void PrintAll();

private:
	Student* head;
	Student* current;
};

int main()
{
	List list;

	int no;
	string name;

	int input;
	bool out = true;

	while (out)
	{
		cout << "1�� : ���, 2�� : ����, 3�� : ��ü��� : ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "��ȣ �Է� :";
			cin >> no;
			cout << "�̸� �Է� : ";
			cin >> name;
			list.Add(no, name);
			break;
		case 2:
			cout << "��ȣ �Է� : ";
			cin >> no;
			list.Delete(no);
			break;
		case 3:
			list.PrintAll();
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
	// ��� ������
	if (head == nullptr)
	{
		head = new Student;
		head->name = name;
		head->no = no;
		head->next = nullptr;

		current = head;

		return;
	}

	Student* temp = new Student;
	temp->name = name;
	temp->no = no;
	temp->next = nullptr;

	current->next = temp;
	current = temp;

	return;
}

void List::Delete(int no)
{
	if (head == nullptr)
	{
		cout << "��Ͼ�" << endl;
		return;
	}

	Student* temp = head;

	if (temp->no == no) // ��ó���̸�
	{
		head = head->next;
		delete temp;

		return;
	}

	while (temp != nullptr)
	{
		if (temp->next->no)
		{
			if (temp->next->next == nullptr) // ã���� �� �������̸�
			{
				delete temp->next;
				temp->next = nullptr;

				return;
			}
			else
			{
				Student* temp2 = temp;
				temp = temp->next;
				temp2->next = temp->next;

				delete temp;

				return;
			}
		}

		temp = temp->next;
	}
}

void List::PrintAll()
{
	Student* temp = head;
	while (temp != nullptr)
	{
		cout << temp->no << endl;
		cout << temp->name << endl << endl;
		temp = temp->next;
	}
}