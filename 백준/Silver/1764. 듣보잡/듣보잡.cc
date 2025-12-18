#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::map<std::string, int> ma;
	std::vector<std::string> vt;

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n+m; ++i)
	{
		std::string str;
		std::cin >> str;
		ma[str]++;
		if (ma[str] > 1)
		{
			vt.push_back(str);
		}
	}
	std::sort(vt.begin(), vt.end());
	std::cout << vt.size() << "\n";
	for (auto re : vt)
	{
		std::cout << re << "\n";
	}
}