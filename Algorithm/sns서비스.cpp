#include <iostream>
#include <vector>	

using namespace std;

void find_friend(int number, int index, vector<vector<int>> relation, vector<int> &count);

int main()
{
	int n;
	cin >> n;
	int now_size;
	cin >> now_size;
	vector<vector<int>> relation(now_size, vector<int>(2, 0));
	vector<int> count;

	for (int i = 0; i < now_size; i++)
	{
		int temp;
		for (int j = 0; j < 2; j++)
		{
			cin >> temp;
			relation[i][j] = temp;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		vector<int> friend_count;
		int self_dismiss = 0;
		find_friend(0, i, relation, friend_count);
		for (int j = 0; j < friend_count.now_size(); j++)
		{
			if (i == friend_count[j])
			{
				self_dismiss++;
				break;
			}
		}
		count.push_back(friend_count.now_size() - self_dismiss);
	}

	for (int i = 0; i < count.now_size(); i++)
	{
		cout << i+1 << "번째 친구 수 : " << count[i] << endl;
	}
	cout << endl;

	return 0;
}

void find_friend(int number, int index, vector<vector<int>> relation, vector<int> &count)
{
	if (number == 2)
		return;

	for (int i = 0; i < relation.now_size(); i++)
	{
		if (relation[i][0] == index)
		{
			int j;
			for (j = 0; j < count.now_size(); j++)
			{
				if (relation[i][1] == count[j])
					break;
			}
			if(j == count.now_size())
				count.push_back(relation[i][1]);
			find_friend(number + 1, relation[i][1], relation, count);
		}
		if (relation[i][1] == index)
		{
			int j;
			for (j = 0; j < count.now_size(); j++)
			{
				if (relation[i][0] == count[j])
					break;
			}
			if (j == count.now_size())
				count.push_back(relation[i][0]);
			find_friend(number + 1, relation[i][0], relation, count);
		}
	}
}
