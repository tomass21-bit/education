
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include "task1.h"


TEST_CASE("test_list", "[List]") {
	List des;
<<<<<<< HEAD

	CHECK (des.Empty() == true);
=======
	CHECK (des.Empty() == true);
	CHECK(des.Size() == 0);
	des.PushBack(2);
	des.PushFront(10);
	CHECK(des.Size() == 2);
	des.PushBack(23);
	des.PushFront(10);
	des.PushFront(50);
	CHECK(des.Size()==5 );
	des.PopFront();
	des.PopBack();
	CHECK(des.Size() == 3);
	des.Clear();
	des.PushFront(50);
	SECTION("empty_list") {
		
		des.PopFront();
		des.PopBack();
	}
	//специально добавлено для проверки работы Clear
	CHECK(des.Empty() == true);
	CHECK(des.Size()==0);
>>>>>>> a3107273d8365e6ddef67c88fca41908136ecc4f

}

int main()
{
	
	return Catch::Session().run();
	
}