#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first == p2.first)
		return p1.second > p2.second;
	return p1.first < p2.first;
}

int main()
{
	vector<pair<int, int>> points;
	string str;
	cin >> str;
	int f1, f2,n1,n2,n;
	f1 = f2 = n = n1 = n2 = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '[')
		{
			f1++;
			f2 = 0;
		}
		else if (str[i] == ',')
		{
			if (f1)
			{
				n1 = n;
				n = 0;
			}
		}
		else if (str[i] == ']')
		{
			if (!f1)
				continue;
			n2 = n;
			n = 0;
			f1 = f2 = 0;
			pair<int, int> p(n1, n2);
			points.push_back(p);
		}
		else if ('0' <= str[i] && str[i] <= '9')
		{
			n *= 10;
			n += (str[i] - '0');
			continue;
		}
		else continue;

	}
	int len = points.size();
	sort(points.begin(), points.end(), cmp);

	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		int y1 = points[i].second;
		int y2 = INT_MIN;

		for (int j = i + 1; j < len; j++)
		{
			if (points[j].second > y1)
				continue;
			if (points[j].second <= y2)
				continue;
			sum++;
			y2 = points[j].second;

		}
	}
	cout << sum;
}