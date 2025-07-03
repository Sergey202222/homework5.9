#include "big_integer.hpp"

big_integer::big_integer::big_integer(std::string _number) : number{ _number } {};

big_integer::big_integer::big_integer(big_integer&& move)
{
	this->number = std::move(move.number);
}

big_integer::big_integer& big_integer::big_integer::operator=(big_integer&& move)
{
	this->number = std::move(move.number);
	return *this;
}

big_integer::big_integer big_integer::big_integer::operator+(const big_integer& integer) const
{
	std::string _integer{}, one_num{}, two_num{};
	int _number{}, one{};
	int _size1{}, _size2{};
	if (this->number.length() > integer.number.length())
	{
		_size1 = this->number.length();
		_size2 = integer.number.length();
		one_num = this->number;
		two_num = integer.number;
	}
	else
	{
		_size1 = integer.number.length();
		_size2 = this->number.length();
		one_num = integer.number;
		two_num = this->number;
	}

	--_size1;
	--_size2;
	while (_size1 >= 0)
	{
		if (_size2 >= 0)
		{
			_number = (one_num[_size1] - '0') + (two_num[_size2] - '0') + one;
			one = _number / 10;
			_number %= 10;
			_integer.push_back(_number + '0');
			--_size2;
		}
		else
		{
			_number = one_num[_size1] - '0' + one;
			one = _number / 10;
			_number %= 10;
			_integer.push_back(_number + '0');
		}
		--_size1;
	}

	if (one == 1)
	{
		_integer.push_back(one + '0');
	}

	std::string _reverse_integer{};
	for (int index{ static_cast<int>(_integer.length() - 1) }; index >= 0; --index)
	{
		_reverse_integer.push_back(_integer[index]);
	}

	return big_integer{ _reverse_integer };
}

std::ostream& big_integer::operator<<(std::ostream& out, const big_integer& integer)
{
	out << integer.number;
	return out;
}