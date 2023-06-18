#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <list>
#include <sstream>
#include <functional>
void print(std::map < std::string, std::set < int>>map)
{
	for (auto& i : map)
	{
		std::cout << i.first << " - ";
		for (auto it = i.second.begin(); it != i.second.end(); ++it)
			std::cout <<* it << " ";
		std::cout << std::endl;
	}
}
void task(std::ifstream& file, std::function<bool(std::string, std::string)> lambda)
{
	std::string line;
	int count = 1;
	std::string word;
	std::map < std::string, std::set <int>>map;
	while (std::getline(file, line))
	{
		std::istringstream is(line);
		std::string word;
		while (is >>word)
		{
			if (lambda("q", word))
				map[word].insert(count);
		}
		++count;
	}
	print(map);
}
int main()
{
	std::ifstream file("file1234.txt");
	auto lambda = [](std::string letter, std::string let)
	{
		bool flag = false;
		for (size_t i = 0; i < letter.size(); i++)
		{
			if (let[i] == letter[i])
				flag = true;
			else
				flag = false;
		}
		return flag;
	};
	task(file, lambda);
	return 0;
}