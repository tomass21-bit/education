#include <iostream>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include "task1.h"


TEST_CASE("test_list", "[List]") {
	List des;

	
	des.PushFront(15);

	CHECK (des.Empty() == 1);

}

int main()
{
	
	Catch::Session().run();
	
}