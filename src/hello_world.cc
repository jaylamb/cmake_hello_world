#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>

#include "../include/sort.h"

using namespace sort;

class Base {
public:
	virtual void say_something( void ) { printf("Base\n\r"); }

	virtual void collect_input( void ) = 0;

	virtual void calculate_average( void )
	{
		average = static_cast<float>( sum ) / static_cast<float>( how_many_numbers );
	}
	
	void print_output( void )
	{
		std::cout << "Number of entries:      " << how_many_numbers << std::endl;
		std::cout << "Sum of all numbers:     " << sum     << std::endl;
		std::cout << "Average of all numbers: " << average << std::endl;
	}

protected:
	std::int16_t how_many_numbers = 0;

	std::int16_t sum = 0;

	float average = 0.0; 
};

class Derived : public Base {
public:
	void say_something( void ) { 
		std::cout << "I'm a funciton in a derived class" << std::endl;
	}

	void collect_input( void ) {
		std::cout << "How many numbers are there? ";
		std::cin >> how_many_numbers;

		if ( how_many_numbers <= 0  || how_many_numbers >= std::numeric_limits<size_t>::max()) {
			std::cout << "Invalid input, aborting" << std::endl;
			return;
		}

		std::cout << "There are " << how_many_numbers << " numbers" << std::endl;

		std::int16_t entered_numbers[ how_many_numbers ];

		for ( std::int16_t i = 0; i < how_many_numbers; ++i ){
			std::cout << "Enter number " << i+1 << ": ";
			std::cin  >> entered_numbers[ i ];
			sum += entered_numbers[ i ];
		} // for
	}
};

class Confusing_Math {
public:
	std::uint16_t fib ( std::uint16_t N ) {
		if( N <= 1) return 1;

		return fib( N - 1 ) + fib( N - 2 );
	}
};

void find_missing ( void ) {

	std::uint16_t numbers[10] {0, 1, 2, 3, 4, 5, 6, 8, 9, 10};
	bool located { false };

	for( std::int16_t i = 0; i < ( sizeof( numbers ) / sizeof( numbers[0] )); ++i ) {

		located = false;
		
		for( std::int16_t j = 0; j < sizeof( numbers ) / sizeof( numbers[0] ); ++j ) {
			if( i == numbers[j] ){
				located = true;
				break;
			}
		}// for
		if ( !located )	
			std::cout << "MISSING: " << i << std::endl;

	} // for
}

void find_duplicate ( void ) {

	std::array<std::uint16_t, 10> to_search {0, 1, 2, 3, 3, 5, 5, 8, 3, 10};

	std::uint16_t instances;
	std::uint16_t candidate = to_search.front();

	for ( auto search_target_a : to_search ) 
	{
		instances = 0;
		for ( auto search_target_b : to_search ) 
		{
			if( search_target_a == search_target_b ){
				instances++;
			}
		}// for
		if ( instances > 1 ){
			std::cout << "Duplicate located: " << search_target_a << std::endl;
		}// if

	}// for
}

void find_extrema ( void ) {

	std::array<std::uint16_t, 10> to_search {7, 4, 22, 33, 3, 5, 52, 0, 14, 9};

	std::uint16_t extreme = to_search.front();

	for( auto candidate : to_search ) {
		if ( candidate < extreme ) {
			extreme = candidate;
		} // if
	}// for
	std::cout << "Minimum value is " << extreme << std::endl;

	extreme = to_search.front();
	for( auto candidate : to_search ) {
		if ( candidate > extreme ) {
			extreme = candidate;
		} // if
	}// for
	std::cout << "Maximum value is " << extreme << std::endl;
}

void find_pairs_with_sum( std::uint16_t target ) {
	
	std::array<std::uint16_t, 10> to_search {0, 1, 2, 3, 3, 5, 6, 8, 9, 10};

	auto index_b = 1;
	auto sum = 0;

	for( auto index_a = 0; index_a < to_search.size(); index_a ++ ){
		index_b = index_a + 1;
		while( index_b < to_search.size() ){

			sum = to_search.at( index_a ) + to_search.at( index_b );	
			if( sum == target ){
				std::cout << "Target (" << target << ") found (" << to_search.at( index_a ) << " + " << to_search.at( index_b ) << ")   [" << index_a << "]" << "[" << index_b << "]" << std::endl;
			}
			index_b++;

		}// while
	}// for
}

void remove_duplicates ( void ) {
	std::vector<std::uint16_t> to_search { 14, 54, 23, 5, 1, 3, 14, 22, 44, 5, 54 };

	std::cout << "Original" << std::endl;
	for ( auto element : to_search ) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::sort( to_search.begin(), to_search.end());
	std::cout << "Sorted" << std::endl;
	for ( auto element : to_search ) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	auto last = std::unique( to_search.begin(), to_search.end());

	to_search.erase( last, to_search.end());
	std::cout << "Modified" << std::endl;
	for ( auto element : to_search ) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

void test_swap( void )
{
	std::array<std::uint16_t, 3> test { 0, 1, 2 };

	std::cout << "Before" << std::endl;
	for ( auto element : test )
		std::cout << element << " ";
	std::cout << std::endl;

	std::swap(test.at(0), test.at(1));

	std::cout << "\nAfter" << std::endl;
	for ( auto element : test )
		std::cout << element << " ";
	std::cout << std::endl;
	
}

int main( int argc, char** argv )
{
    printf("program started with %d arguments \n\n\r", argc);

	std::uint16_t to_sort[] = { 2, 6, 5, 3, 8, 7, 1, 47 };

	//Base *b = new Derived{};
	//b->say_something();

	//b->collect_input();
	//b->calculate_average();
	//b->print_output();

	//Confusing_Math cm;

	//std::cout << cm.fib(5) << std::endl;
	//std::cout << cm.fib(8) << std::endl;
	
	//find_missing();
	
	//find_duplicate();

	//find_extrema();

	//find_pairs_with_sum ( 3 );

	//remove_duplicates();

	//test_swap();

	sort::Quicksort_btb qs{};
	qs.quicksort( to_sort, 0, 7 );
	
	printf("\nprogram end\n\r");
	return 0;
}
