
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include "task1.h"


TEST_CASE("test_list", "[List]") {
	List des;
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
	//���������� ��������� ��� �������� ������ Clear
	CHECK(des.Empty() == true);
	CHECK(des.Size()==0);

}

int main()
{
	
	return Catch::Session().run();
	
}