#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Shop.h"
#include "Book.h"
#include "Sale.h"
class Shop;
class Book;
class Sale;
class Stock {
public:
	Wt::Dbo::collection< Wt::Dbo::ptr<Sale> > sales;
	Wt::Dbo::ptr<Shop> id_shop;
	Wt::Dbo::ptr<Book> id_book;
	int count = 0 ;

	template<class Action>
	void persist(Action& a);

};