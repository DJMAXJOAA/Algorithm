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


	cout << "������ ���� ���� :";
	cin >> size;

	vector<int> data(size + 1);

	cout << "������ �Է� :";
	for (int i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		data[i] = temp;
	}

	cout << "�˻� ������ :";
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
				cout << "�ڷ��߿� " << search << "�� �����ϴ�." << endl;
			}
			else
			{
				cout << "�ڷ��߿� " << search << "�� �ֽ��ϴ�." << endl;
			}
			return 1;
		}
		i++;
	}
}

///* 1�� : ����Ž�� */
//int main()
//{
//	int size;
//	int search;
//	vector<int> data;
// 
//	cout << "������ ���� ���� :";
//	cin >> size;
//	
//	cout << "������ �Է� :";
//	for (int i = 0; i < size; i++)
//	{
//		int temp;
//		cin >> temp;
//		data.push_back(temp);
//	}
//
//	cout << "�˻� ������ :";
//	cin >> search;
//
//	int i = 0;
//
//	while (1)
//	{
//		if (i == size)
//		{
//			cout << "�ڷ��߿� " << search << "�� �����ϴ�." << endl;
//			return 0;
//		}
//		if (data[i] == search)
//		{
//			cout << "�ڷ��߿� " << search << "�� �ֽ��ϴ�." << endl;
//			return 1;
//		}
//		i++;
//	}
//}
//
///* 2�� : ���ʹ� */
//int main()
//{
//	int size;
//	int search;
//	
//
//	cout << "������ ���� ���� :";
//	cin >> size;
//
//	vector<int> data(size+1);
//
//	cout << "������ �Է� :";
//	for (int i = 0; i < size; i++)
//	{
//		int temp;
//		cin >> temp;
//		data[i] = temp;
//	}
//
//	cout << "�˻� ������ :";
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
//				cout << "�ڷ��߿� " << search << "�� �����ϴ�." << endl;
//			}
//			else
//			{
//				cout << "�ڷ��߿� " << search << "�� �ֽ��ϴ�." << endl;
//			}
//			return 1;
//		}
//		i++;
//	}
//}
//
