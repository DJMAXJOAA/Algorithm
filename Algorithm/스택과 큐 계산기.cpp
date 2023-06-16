#include "stack.h"
#include "queue.h"
#include <cctype>

using namespace std;

double cal(vector<double>& temp, char oper);

int main()
{
	char x = 0;
	string calculate = { "-2*(-1-1)-3.9+6/((3+3)/6.0)" };
	cin >> calculate;
	IntStack stack;
	if (Initialize(&stack, 64) == -1)
	{
		puts("���� ������ �����߽��ϴ�.");
		return 1;
	}
	IntQueue queue(100);

	for (int i = 0; i < calculate.size(); i++)
	{
		/* �����϶� */
		if (isdigit(calculate[i]) >= 1 || calculate[i] == '.')
		{
			queue.Enque(calculate[i]);
			queue.Print();
			PrintStack(&stack);
			continue;
		}

		/* ���� �ƴϸ� �����ϳ� �߰� */
		queue.Enque(' ');
		Peek(&stack, &x);

		/* �� Ȥ�� ������ */
		if (calculate[i] == '*' || calculate[i] == '/')
		{
			if (x != '(' && x != ')' && x != '+' && x != '-' && x != '\0')
			{
				Pop(&stack, &x);
				queue.Enque(x);
			}
			Push(&stack, calculate[i]);
		}

		/* �ܷ��� */
		else if (calculate[i] == '+')
		{
			if (x != '(' && x != ')' && x != '\0')
			{
				Pop(&stack, &x);
				queue.Enque(x);
			}
			Push(&stack, calculate[i]);
		}

		/* ���� */
		else if (calculate[i] == '-')
		{
			Peek(&stack, &x);
			if (x == '(' || x == ')')
			{
				if (isdigit(calculate[i - 1]) == 0)
				{
					queue.Enque('~');
					continue;
				}
				Push(&stack, calculate[i]);
			}
			/* ù ������ -�̸�(stack.peek�ߴµ� '\0' ��ȯ�Ǹ�) */
			else if (x == '\0')
			{
				queue.Enque('~');
				Push(&stack, ' ');
			}

			else
			{
				Pop(&stack, &x);
				queue.Enque(x);
				Push(&stack, calculate[i]);
			}
		}

		/* ��ȣ */
		else if (calculate[i] == '(')
		{
			Push(&stack, calculate[i]);
		}
		else if (calculate[i] == ')')
		{
			while (1)
			{
				Peek(&stack, &x);
				if (x == '(')
				{
					Pop(&stack, &x);
					break;
				}
				else
				{
					Pop(&stack, &x);
					queue.Enque(x);
				}
			}
		}
		queue.Print();
		PrintStack(&stack);
	}
	/* ���� ������ ��� ť�� �ֱ� */
	while(Size(&stack) > 0)
	{
		queue.Enque(' ');
		Pop(&stack, &x);
		queue.Enque(x);
	}
	queue.Print();

	string temp1 = "\0";
	vector<double> temp2(0);
	int minus = 1;

	/* ��� ���� */
	while (queue.Size() >= 1)
	{
		queue.Deque(&x);
		/* �����ߴ� �ӽ� ��Ʈ���� int������ ��ȯ �� int�� ����(operand stack)�� Ǫ�� */
		if (x == ' ' && temp1 != "\0")
		{
			temp2.push_back(minus*stod(temp1));
			temp1 = "\0";
			minus = 1;
		}
		/* �ӽ� ��Ʈ�� ���� */
		else if (isdigit(x) >= 1 || x == '.')
		{
			temp1 += x;
		}
		/* ~(���� - ��ü����) */
		else if (x == '~')
		{
			minus = -1;
		}

		/* ������ �ǵڶ� �ǵ��� ���� ��� */
		else if (x == '*') temp2.push_back(cal(temp2, '*'));
		else if (x == '/') temp2.push_back(cal(temp2, '/'));
		else if (x == '+') temp2.push_back(cal(temp2, '+'));
		else if (x == '-') temp2.push_back(cal(temp2, '-'));

		cout << queue.Size() << "��° : " << x << " : ";
		for (int i = 0; i < temp2.size(); i++)
		{
			cout << temp2[i] << ",";
		}
		cout << endl;
	}
	cout << "���� ��� : " << temp2[0];


	return 0;
}

double cal(vector<double>& temp, char oper)
{
	double a = temp.back();
	temp.pop_back();
	double b = temp.back();
	temp.pop_back();
	if (oper == '+')
		return b + a;
	if (oper == '-')
		return b - a;
	if (oper == '*')
		return b * a;
	if (oper == '/')
		return b / a;
}