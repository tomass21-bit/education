#include <iostream>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include "task1.h"


TEST_CASE("test_list", "[List]") {
	List des;

	CHECK (des.Empty() == true);

}

int main()
{
	
	Catch::Session().run();
	
}