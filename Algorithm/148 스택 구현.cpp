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
		puts("스택 생성에 실패했습니다.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		cout << "현재 데이터 수 : " << Size(&s) << " / " << Capacity(&s) << endl;
		cout << "(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6)초기화 (0)종료" << endl;
		cin >> menu;

		if (menu == TERMINATE)
			break;
		switch (menu)
		{
		case PUSH:
			cout << "푸시 데이터 입력 : ";
			cin >> x;
			if (Push(&s, x) == -1)
				puts("\a오류 : 푸시에 실패했습니다.");
			break;
		case POP:
			if (Pop(&s, &x) == -1)
				puts("\a오류 : 팝에 실패했습니다.");
			cout << "팝 값 : " << x << endl;
			break;
		case PEEK:
			if (Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			cout << "피크 값 : " << x << endl;
			break;
		case PRINT:
			Print(&s);
			break;
		case SEARCH:
			cout << "검색 값 입력 : ";
			cin >> x;
			if (Search(&s, x) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
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