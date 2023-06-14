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
		cout << "현재 데이터 수 : " << que.Size() << " / " << que.Capacity() << endl;
		cout << "(1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색 (6)클리어 (0)종료 : ";
		cin >> m;

		if (m == EXIT) break;
		switch (m)
		{
		case ENQUE:
			cout << "데이터 : ";
			cin >> x;
			if (que.Enque(x) == 0)
			{
				cout << "인큐에 실패했습니다.\n";
			}
			break;
		case DEQUE:
			if (que.Deque(&x) == 0)
			{
				cout << "디큐에 실패했습니다.\n";
			}
			else
			{
				cout << "디큐 데이터 : " << x << endl;
			}
			break;
		case PEEK:
			if (que.Peek(&x) == 0)
			{
				cout << "피크에 실패했습니다.\n";
			}
			else
			{
				cout << "피크 데이터 : " << x << endl;
			}
			break;
		case PRINT:
			que.Print();
			break;
		case SEARCH:
			cout << "검색 데이터 : ";
			cin >> x;
			if (que.Search(x) == -1)
			{
				cout << "검색 결과가 없습니다.\n";
			}
			else
			{
				cout << que.Search(x) << "번째에 검색 결과가 있습니다.\n";
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