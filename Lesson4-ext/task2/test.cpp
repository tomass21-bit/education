
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include "task1.h"


TEST_CASE("test_list", "[List]") {
	List des;
	
	des.PushBack(2);
	des.PushBack(23);
	des.PushFront(10);
	des.PushFront(50);
	CHECK(des.Size()==4 );
	des.
	des.PushFront(1);
	des.Clear();
	des.PushFront(1); //специально добавлено для проверки работы Clear
	CHECK(des.Empty() == true);
	CHECK(des.Size()==0);

}

int main()
{
	
	return Catch::Session().run();
	
}