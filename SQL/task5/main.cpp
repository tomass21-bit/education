#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Book.h"

#include "Publisher.h"

#include "Shop.h"

#include "Sale.h"

#include "Stock.h"


int main() {
	try {
		std::string connectionString = "host=localhost"
			" port=5432"
			" dbname=task5"
			" user=postgres"
			" password=postgres";
		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Stock>("stock");
		session.mapClass<Sale>("sale");
		session.mapClass<Shop>("shop");


		session.createTables();
	/*	Wt::Dbo::Transaction transaction{ session }; 
		std::unique_ptr<Publisher> publisher{ new Publisher() };
		publisher->name = "Stiven King";
		
		Wt::Dbo::ptr<Publisher> publisherPtr = session.add(std::move(publisher));*/

		/*std::unique_ptr<Publisher> publisher{ new Publisher() };
		Wt::Dbo::ptr<Book> book = session.add(std::unique_ptr<Book>{new Book()});
		book.modify()->id_publisher = ;*/

		/*transaction.commit();*/
		
	}
	catch (const Wt::Dbo::Exception& e) {
	std::cout << e.what() << std::endl; }

	return 0;

}