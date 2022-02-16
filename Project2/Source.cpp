#include<iostream>
#include<string>

std::string func(std::string str)
{
	while (str.find_first_of("()*/+-") != std::string::npos)
	{
		if (size_t left = str.find("(") != std::string::npos)
		{
			size_t right = str.rfind(")");
			if (right == std::string::npos) return "error";
			str.replace(left - 1, right + 1, func(str.substr(left, right - 1)));
			continue;
		}
		size_t pos = str.find_first_of("*/");
		if (pos == std::string::npos) pos = str.find_first_of("+-");

		auto left = str.begin() + pos;
		while (true) // first character of first num
		{
			left--;
			if (left == str.begin()) break;
			if (!isdigit(*left))
			{
				left++;
				break;
			}
		}
		auto right = str.begin() + pos;
		while (true) // last character of second num
		{
			right++;
			if (right == str.end() - 1) break;
			if (!isdigit(*right))
			{
				right--;
				break;
			}
		}
		int firstNum = std::stoi(str.substr(std::distance(str.begin(), left), pos));
		int secondNum = std::stoi(str.substr(pos + 1, std::distance(str.begin(), right)));
		int result = 0;
		if (str[pos] == '*') result = firstNum * secondNum;
		else if (str[pos] == '/') result = firstNum / secondNum;
		else if (str[pos] == '+') result = firstNum + secondNum;
		else result = firstNum - secondNum;
		str.replace(left, right + 1, std::to_string(result));
	}
	return str;
}

int main()
{
	std::cout << func(std::string("(12+12*2)*2"));
}