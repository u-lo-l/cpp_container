#include <iostream>
#include <string>
#include <list>
#include <ctime>

#include "container_tester.hpp" // for value_creator

# include "../include/ft_vector.hpp"
# include "../include/ft_stack.hpp"
# include "../include/ft_map.hpp"
# include "../include/ft_set.hpp"
# include <deque>
# include <vector>
# include <stack>
# include <map>
# include <set>

# include "VectorTestFunctor.hpp"
# include "StackTestFunctor.hpp"
# include "MapTestFunctor.hpp"
# include "SetTestFunctor.hpp"

void vector_time();
void stack_time();
void map_time();
void set_time();

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage [./prog_name] [container_type]" << std::endl;
		return (1);
	}
	if ((std::string)av[1] == "vector")
		vector_time();
	else if ((std::string)av[1] == "stack")
		stack_time();
	else if ((std::string)av[1] == "map")
		map_time();
	else if ((std::string)av[1] == "set")
		set_time();
	else
		return (1);
	return (0); 
}


void vector_time()
{
	std::cout << "============================================" << std::endl;
	std::cout << "====--------------[vector]--------------====" << std::endl;
	std::cout << "============================================" << std::endl;
	VectorTestFunctor<TESTING_NAMESPACE::vector<TYPE>, TYPE> vec_test;
	vec_test();
	std::cout << "====           ===============           ===" << std::endl;
}

void stack_time()
{
	std::cout << "============================================" << std::endl;
	std::cout << "====------[stack with std::vector]------====" << std::endl;
	std::cout << "============================================" << std::endl;
	StackTestFunctor<TESTING_NAMESPACE::stack<TYPE, std::vector<TYPE> >, TYPE> stack_test1;
	stack_test1();
	std::cout << "====------[stack with std::deque ]------====" << std::endl;
	StackTestFunctor<TESTING_NAMESPACE::stack<TYPE, std::deque<TYPE> >, TYPE> stack_test2;
	stack_test2();
	std::cout << "====------[stack with ft::vector ]------====" << std::endl;
	StackTestFunctor<TESTING_NAMESPACE::stack<TYPE, ft::vector<TYPE> >, TYPE> stack_test3;
	stack_test3();
	std::cout << "====------[stack with std::list ]------====" << std::endl;
	StackTestFunctor<TESTING_NAMESPACE::stack<TYPE, std::list<TYPE> >, TYPE> stack_test4;
	stack_test4();

	std::cout << "====           ===============           ===" << std::endl;
}

void map_time()
{
	std::cout << "============================================" << std::endl;
	std::cout << "====--------------[ map  ]--------------====" << std::endl;
	std::cout << "============================================" << std::endl;
	MapTestFunctor<TESTING_NAMESPACE::map<TYPE, int>, TYPE> map_test;
	map_test();
	std::cout << "====           ===============           ===" << std::endl;
}

void set_time()
{
	std::cout << "============================================" << std::endl;
	std::cout << "====--------------[ set  ]--------------====" << std::endl;
	std::cout << "============================================" << std::endl;
	SetTestFunctor<TESTING_NAMESPACE::set<TYPE>, TYPE> set_test;
	set_test();
	std::cout << "====           ===============           ===" << std::endl;
}