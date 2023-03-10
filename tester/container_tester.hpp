#ifndef MYTESTER_HPP
# define MYTESTER_HPP

# ifndef TESTING_NAMESPACE
#  define TESTING_NAMESPACE ft
# endif


# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <utility>
# include <vector>
# include "../include/ft_pair.hpp"

# ifndef TYPE
#  define TYPE	int
# endif

# define T_SIZE_TYPE	size_t

template < class _Tp >
class value_creator
{
private :
	value_creator() {};
};

template <>
class value_creator<int>
{
public:
	value_creator() {};
	int operator() (unsigned int seed)
	{
		return (seed);
	}
};

template <>
class value_creator<float>
{
public:
	value_creator() {};
	float operator() (unsigned int seed)
	{
		seed++;
		return (seed * 10 + (float)(seed) * 0.0001f);
	}
};

template <>
class value_creator<std::string>
{
public:
	value_creator() {};
	std::string operator() (unsigned int seed)
	{
		std::ostringstream oss;
		oss << "sample_str#_" << std::setw(6) << std::setfill('0')<< seed;
		return (oss.str());
	}
};

template <class K , class V >
class value_creator<ft::pair<K, V> >
{
public:
	explicit value_creator() {};
	ft::pair<K, V> operator() (unsigned int seed)
	{
		value_creator<K> K_creator;
		value_creator<V> V_creator;
		return ft::make_pair(K_creator(seed), V_creator(seed));
	}
};

template <class K, class V>
std::ostream & operator<<(std::ostream & os, const std::pair<K, V> & p)
{
	os << "<" << p.first << ", " << p.second << ">";
	return (os);
}

template <class Cont >
void
printContainer
(
	const std::string & title ,
	const Cont & cont, 
	bool show_content = true
)
{
	if (show_content)
	{
		std::cout << "==[" << title << "]==" << std::endl;
		const T_SIZE_TYPE size = cont.size();
		const T_SIZE_TYPE max_size = cont.max_size();
		const T_SIZE_TYPE capacity = cont.capacity();
		const std::string isCapacityOK = (capacity >= size) ? "OK" : "KO";

		std::cout << "size: " << size << std::endl;
		std::cout << "max_size: " << max_size << std::endl;
		std::cout << "capacity: " << isCapacityOK << "(" << capacity << ")" << std::endl;
		typename Cont::const_iterator it = cont.begin();
		typename Cont::const_iterator ite = cont.end();
		std::cout << std::endl << "Content is: " << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
		std::cout << "------------------------" << std::endl;
	}
}

#endif
