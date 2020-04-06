namespace sort {

class Quicksort {
public:
	Quicksort( void );
	void sort( void );
private:
	std::uint16_t pivot_index;
	std::uint16_t high_val;
	std::uint16_t low_val;

	void seed_rng( void );
	std::uint16_t select_pivot_index( void );
	std::uint16_t find_low_val( void );
	std::uint16_t find_high_val( void );

	void display_array( void );

};

class Quicksort_btb {
public:
	void quicksort( std::uint16_t a[], std::uint16_t low_index, std::uint16_t high_index );
private:
	std::uint16_t pivot_index;
	std::uint16_t pivot;
	std::uint16_t partition( std::uint16_t a[], std::uint16_t low_index, std::uint16_t high_index );

	void display_array( std::uint16_t a[] );
};
}
