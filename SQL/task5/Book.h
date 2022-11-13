#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Publisher.h"
#include "Stock.h"
class Stock;
class Publisher;
class Book {
public:
	std::string title = "";
	Wt::Dbo::ptr<Publisher> id_publisher;
	Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stocks;
	template<class Action>
	void persist(Action& a);
	
};