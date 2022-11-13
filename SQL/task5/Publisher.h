#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Book.h"
class Book;
class Publisher {
public:
	std::string name = "";
	Wt::Dbo::collection< Wt::Dbo::ptr<Book> > books;
	template<class Action>
	void persist(Action& a);
	
};