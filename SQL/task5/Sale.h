#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Stock.h"
#include "Sale.h"
class Stock;

class Sale {
public:
	
	double price = 0.0; 
	std::string date_sale = "";
	Wt::Dbo::ptr<Stock> id_stock;
	int count = 0;

	template<class Action>
	void persist(Action& a);

};

