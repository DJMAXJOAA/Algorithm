#include "queue.h"

using namespace std;

enum
{
	EXIT, ENQUE, DEQUE, PEEK, PRINT, SEARCH, CLEAR
};

int main()
{
	IntQueue que(64);

	while (1)
	{
		int m, x;
		cout << "���� ������ �� : " << que.Size() << " / " << que.Capacity() << endl;
		cout << "(1)��ť (2)��ť (3)��ũ (4)��� (5)�˻� (6)Ŭ���� (0)���� : ";
		cin >> m;

		if (m == EXIT) break;
		switch (m)
		{
		case ENQUE:
			cout << "������ : ";
			cin >> x;
			if (que.Enque(x) == 0)
			{
				cout << "��ť�� �����߽��ϴ�.\n";
			}
			break;
		case DEQUE:
			if (que.Deque(&x) == 0)
			{
				cout << "��ť�� �����߽��ϴ�.\n";
			}
			else
			{
				cout << "��ť ������ : " << x << endl;
			}
			break;
		case PEEK:
			if (que.Peek(&x) == 0)
			{
				cout << "��ũ�� �����߽��ϴ�.\n";
			}
			else
			{
				cout << "��ũ ������ : " << x << endl;
			}
			break;
		case PRINT:
			que.Print();
			break;
		case SEARCH:
			cout << "�˻� ������ : ";
			cin >> x;
			if (que.Search(x) == -1)
			{
				cout << "�˻� ����� �����ϴ�.\n";
			}
			else
			{
				cout << que.Search(x) << "��°�� �˻� ����� �ֽ��ϴ�.\n";
			}
			break;
		case CLEAR:
			que.Clear();
			break;
		}
		cout << endl;
	}
	return 0;
}