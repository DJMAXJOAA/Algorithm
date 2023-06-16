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
		puts("스택 생성에 실패했습니다.");
		return 1;
	}
	IntQueue queue(100);

	for (int i = 0; i < calculate.size(); i++)
	{
		/* 숫자일때 */
		if (isdigit(calculate[i]) >= 1 || calculate[i] == '.')
		{
			queue.Enque(calculate[i]);
			queue.Print();
			PrintStack(&stack);
			continue;
		}

		/* 숫자 아니면 공백하나 추가 */
		queue.Enque(' ');
		Peek(&stack, &x);

		/* 곱 혹은 나누기 */
		if (calculate[i] == '*' || calculate[i] == '/')
		{
			if (x != '(' && x != ')' && x != '+' && x != '-' && x != '\0')
			{
				Pop(&stack, &x);
				queue.Enque(x);
			}
			Push(&stack, calculate[i]);
		}

		/* 쁠러스 */
		else if (calculate[i] == '+')
		{
			if (x != '(' && x != ')' && x != '\0')
			{
				Pop(&stack, &x);
				queue.Enque(x);
			}
			Push(&stack, calculate[i]);
		}

		/* 빼기 */
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
			/* 첫 계산부터 -이면(stack.peek했는데 '\0' 반환되면) */
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

		/* 괄호 */
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
	/* 스택 마지막 요소 큐에 넣기 */
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

	/* 계산 과정 */
	while (queue.Size() >= 1)
	{
		queue.Deque(&x);
		/* 저장했던 임시 스트링을 int형으로 변환 후 int형 벡터(operand stack)로 푸쉬 */
		if (x == ' ' && temp1 != "\0")
		{
			temp2.push_back(minus*stod(temp1));
			temp1 = "\0";
			minus = 1;
		}
		/* 임시 스트링 저장 */
		else if (isdigit(x) >= 1 || x == '.')
		{
			temp1 += x;
		}
		/* ~(음수 - 대체문자) */
		else if (x == '~')
		{
			minus = -1;
		}

		/* 스택의 맨뒤랑 맨뒤의 앞을 계산 */
		else if (x == '*') temp2.push_back(cal(temp2, '*'));
		else if (x == '/') temp2.push_back(cal(temp2, '/'));
		else if (x == '+') temp2.push_back(cal(temp2, '+'));
		else if (x == '-') temp2.push_back(cal(temp2, '-'));

		cout << queue.Size() << "번째 : " << x << " : ";
		for (int i = 0; i < temp2.size(); i++)
		{
			cout << temp2[i] << ",";
		}
		cout << endl;
	}
	cout << "최종 계산 : " << temp2[0];


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