#include <iostream>
#include <array>

#include "../include/sort.h"

namespace sort {

	std::array<std::uint16_t, 8> to_sort { 2, 6, 5, 3, 8, 7, 1, 0 };

	Quicksort::Quicksort() {
		low_val = 0;
		high_val = 1;
		std::cout << "\nQUICKSORT" << std::endl;

		std::cout << "seeding rng... ";
		seed_rng();
		std::cout << "done." << std::endl;
	}

	void Quicksort::sort( void ){
		display_array();

		pivot_index = select_pivot_index();
		std::cout << "pivot: " << to_sort.at( pivot_index ) << " (to_sort[" << pivot_index << "])" << std::endl;
		std::swap( to_sort.at( pivot_index ), to_sort.back());
		display_array();

		while( low_val < high_val ) {	
			//find itemfromleft (first item starting from .front() larger than pivot)
			low_val = find_low_val();
			std::cout << "low val:  " << to_sort.at( low_val ) << " (to_sort[" << low_val << "])" << std::endl;
		
			//find itemfromright (first item starting from .back()-1 smaller than pivot)
			high_val = find_high_val();
			std::cout << "high val: " << to_sort.at( high_val ) << " (to_sort[" << high_val << "])" << std::endl;

			//swap high and low values
			if( low_val < high_val ){
				std::swap( to_sort.at( low_val ), to_sort.at( high_val ));
				std::cout << "swapping " << to_sort.at( low_val ) << " and " << to_sort.at( high_val ) << std::endl;
				display_array();
			}// if
			else{
				std::cout << "low index > high index, swapping low index and pivot" << std::endl;
				std::swap( to_sort.at( low_val ), to_sort.back());
				display_array();
			}
	
		}// while
	}

	void Quicksort::seed_rng( void ){
		srand( time(NULL));
	}

	std::uint16_t Quicksort::select_pivot_index( void ){
		//return rand() % to_sort.size();
		return 3;
	}

	std::uint16_t Quicksort::find_low_val( void ){
		std::uint16_t candidate_index = 0;

		for( std::uint16_t candidate_index = 0; candidate_index < to_sort.size(); ++candidate_index ){
			if( to_sort.at( candidate_index ) > to_sort.back()){
				return candidate_index;
			} // if
		}// for
		
	// shouldn't get here
	std::cout << "No low val found" << std::endl;
	return 0;
	};

	std::uint16_t Quicksort::find_high_val( void ){
		std::uint16_t candidate_index = 0;

		for( std::uint16_t candidate_index = ( to_sort.size() - 1 ); candidate_index > 0; --candidate_index ){
			if( to_sort.at( candidate_index ) < to_sort.back()){
				return candidate_index;
			} // if
		}// for
		
	// shouldn't get here
	std::cout << "No high val found" << std::endl;
	return 0;
	};

	void Quicksort::display_array( void ){
		for( auto element : to_sort )
			std::cout << element << " ";
		std::cout << std::endl << std::endl;
	}

	void Quicksort_btb::quicksort( std::uint16_t a[], std::uint16_t low_index, std::uint16_t high_index ){
		display_array( a );
		std::cout << "qs( array, "<< low_index << " , " << high_index << ")\n" << std::endl;

		if( low_index < high_index ){
			pivot_index = partition( a, low_index, high_index );
			quicksort( a, low_index, pivot_index );
			quicksort( a, ( pivot_index + 1 ), high_index );
		} // if
	} 	

	std::uint16_t Quicksort_btb::partition( std::uint16_t a[], std::uint16_t low_index, std::uint16_t high_index ){
		pivot = a[ low_index ];
		std::uint16_t i = low_index;

		for( std::uint16_t j = ( low_index + 1 ); j < high_index; j++ ){
			if( a[ j ] <= pivot ){
				i++;
				std::swap( a[ i ], a[ j ] );
			} // if
		} // for
		std::swap( a[ i ], a[ low_index ] );
		std::cout << "partition returning: " << i << std::endl;
		return i;
	}

	void Quicksort_btb::display_array( std::uint16_t a[] ){
		for( std::uint16_t i = 0; i < 8; ++i)
			std::cout << a[ i ] << " ";
		std::cout << std::endl;
		return;
	}

} // namespace sort
