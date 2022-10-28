#include <pqxx/pqxx>
#include <iostream>


class Client {
public:
	
	void create_table() {
		
		for (auto : w.exec("CREATE TABLE IF NOT EXISTS Genre(
			id SERIAL PRIMARY KEY,
			first_name VARCHAR(40) NOT NULL,
			last_name VARCHAR(40) NOT NULL,
			email VARCHAR(40) NOT NULL);)


	}

	
protected:
	pqxx::work& w{ c }

};








int main()
{
	try {
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=task4 "
			"user=postgres "
			"password=postgres ");

		pqxx::work w{c};
		std::shared_ptr<Client> client = std::make_shared<Client>(w);
		client->create_table();
		
	}
	catch (pqxx::sql_error e)
	{
		std::cout << e.what() << std::endl;

	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;

}