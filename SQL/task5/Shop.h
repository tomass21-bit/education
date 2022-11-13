#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Stock.h"
class Stock;
class Shop {
public:
	std::string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;
	template<class Action>
	void persist(Action& a);
	
};