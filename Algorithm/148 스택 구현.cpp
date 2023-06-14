#include "stack.h"

using namespace std;

enum {
	TERMINATE, PUSH, POP, PEEK, PRINT, SEARCH, CLEAR
};

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("���� ������ �����߽��ϴ�.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		cout << "���� ������ �� : " << Size(&s) << " / " << Capacity(&s) << endl;
		cout << "(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�˻� (6)�ʱ�ȭ (0)����" << endl;
		cin >> menu;

		if (menu == TERMINATE)
			break;
		switch (menu)
		{
		case PUSH:
			cout << "Ǫ�� ������ �Է� : ";
			cin >> x;
			if (Push(&s, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����߽��ϴ�.");
			break;
		case POP:
			if (Pop(&s, &x) == -1)
				puts("\a���� : �˿� �����߽��ϴ�.");
			cout << "�� �� : " << x << endl;
			break;
		case PEEK:
			if (Peek(&s, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			cout << "��ũ �� : " << x << endl;
			break;
		case PRINT:
			Print(&s);
			break;
		case SEARCH:
			cout << "�˻� �� �Է� : ";
			cin >> x;
			if (Search(&s, x) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			break;
		case CLEAR:
			Clear(&s);
		default:
			break;
		}
	}
	Terminate(&s);
	return 0;
}