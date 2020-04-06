#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <array>

using namespace std;

class Sorting{
public:

	void quicksort( void ){
		find_pivot();
	} 

private:
	array<uint16_t, 10> to_sort { 5, 4, 2, 1, 8, 7, 6, 0, 9, 3 };

	void find_pivot( void ){
		cout << "locating pivot...";
		uint16_t index  = rand() % to_sort.size();

		cout << to_sort[ index ] << " (to_sort[ " << index << " ])" << endl; 
	}

};

int main( int argc, char** argv )
{
	srand( time( NULL ));

	Sorting s{};
	s.quicksort();

    return 0;
}
