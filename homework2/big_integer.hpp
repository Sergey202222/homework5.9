#pragma once
#include <iostream>

namespace integer
{
	class big_integer
	{
	public:
		big_integer(std::string);
		big_integer(big_integer&&) noexcept;
		big_integer& operator=(big_integer&&) noexcept;
		big_integer operator+(const big_integer&) const;
		big_integer operator*(const int&) const;
		friend std::ostream& operator<<(std::ostream&, const big_integer&);
	private:
		std::string number;
	};
}