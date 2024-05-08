#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "address_book.hpp"

TEST_CASE("entries can be added and removed") {
	address_book ab;
	CHECK_FALSE(ab.has_entry("Jane Doe"));
	ab.add_entry("Jane Doe");
	CHECK(ab.has_entry("Jane Doe"));
	ab.remove_entry("Jane Doe");
	CHECK_FALSE(ab.has_entry("Jane Doe"));
}


// Test case for name string length validation
TEST_CASE("Name String Length Validation") {
	address_book ab;

		CHECK_THROWS_WITH(ab.add_entry(""), "Name may not be empty");
  // Name with invalid length (more than 100 characters)
    std::string invalid_name_long(101, 'a'); // 101-character long string
		CHECK_THROWS_WITH(ab.add_entry(invalid_name_long), "Name too long");

}

// just a simple change here