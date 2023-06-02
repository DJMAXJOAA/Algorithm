#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int size;
	int search;


	cout << "데이터 갯수 설정 :";
	cin >> size;

	vector<int> data(size + 1);

	cout << "데이터 입력 :";
	for (int i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		data[i] = temp;
	}

	cout << "검색 데이터 :";
	cin >> search;


	data[size] = search;

	cout << "\t |";
	for (int i = 0; i <= search; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "---------+----------------------------------" << endl;

	int i = 0;

	while (1)
	{
		cout << "\t" << " |";
		for (int j = 0; j < i; j++)
		{
			cout << "  ";
		}
		cout << "*" << endl;

		cout << "\t" << i << "|";
		for (int j = 0; j <= size; j++)
		{
			cout << data[j] << " ";
		}
		cout << endl;

		if (data[i] == search)
		{
			cout << endl;
			if (i == size)
			{
				cout << "자료중에 " << search << "가 없습니다." << endl;
			}
			else
			{
				cout << "자료중에 " << search << "가 있습니다." << endl;
			}
			return 1;
		}
		i++;
	}
}

///* 1번 : 선형탐색 */
//int main()
//{
//	int size;
//	int search;
//	vector<int> data;
// 
//	cout << "데이터 갯수 설정 :";
//	cin >> size;
//	
//	cout << "데이터 입력 :";
//	for (int i = 0; i < size; i++)
//	{
//		int temp;
//		cin >> temp;
//		data.push_back(temp);
//	}
//
//	cout << "검색 데이터 :";
//	cin >> search;
//
//	int i = 0;
//
//	while (1)
//	{
//		if (i == size)
//		{
//			cout << "자료중에 " << search << "가 없습니다." << endl;
//			return 0;
//		}
//		if (data[i] == search)
//		{
//			cout << "자료중에 " << search << "가 있습니다." << endl;
//			return 1;
//		}
//		i++;
//	}
//}
//
///* 2번 : 보초법 */
//int main()
//{
//	int size;
//	int search;
//	
//
//	cout << "데이터 갯수 설정 :";
//	cin >> size;
//
//	vector<int> data(size+1);
//
//	cout << "데이터 입력 :";
//	for (int i = 0; i < size; i++)
//	{
//		int temp;
//		cin >> temp;
//		data[i] = temp;
//	}
//
//	cout << "검색 데이터 :";
//	cin >> search;
//
//	int i = 0;
//	data[size] = search;
//
//	while (1)
//	{
//		if (data[i] == search)
//		{
//			if (i == size)
//			{
//				cout << "자료중에 " << search << "가 없습니다." << endl;
//			}
//			else
//			{
//				cout << "자료중에 " << search << "가 있습니다." << endl;
//			}
//			return 1;
//		}
//		i++;
//	}
//}
//
