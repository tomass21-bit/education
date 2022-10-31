#include <pqxx/pqxx>
#include <iostream>
#include <windows.h>

class Client {
public:

	Client(pqxx::work& w);

	void create_table() {
		try {
			pqxx::result r1 = w.exec("CREATE TABLE IF NOT EXISTS Client (id SERIAL PRIMARY KEY, first_name VARCHAR(40) NOT NULL, last_name VARCHAR(40) NOT NULL, email VARCHAR(40) NOT NULL)");
			pqxx::result r2 = w.exec("CREATE TABLE IF NOT EXISTS Telephon (id SERIAL PRIMARY KEY, number VARCHAR(13), client_id integer NOT NULL REFERENCES Client (id) ON DELETE CASCADE )");
		}

		catch (pqxx::sql_error e)
		{
			std::cout << e.what() << std::endl;

		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	void add_number(const std::string& first_name_in, const std::string& last_name_in, const std::string& number_in) {
		std::string cli("SELECT id FROM Client  WHERE first_name ='" + first_name_in + "' AND last_name = '" + last_name_in + " '");

		try {
			auto id = w.query_value<std::string>(cli);
			std::string cli1 = "INSERT INTO Telephon (number, client_id) VALUES ( '" + number_in + " ', ' " + id + " ')";
			pqxx::result r1 = w.exec(cli1);


		}

		catch (pqxx::sql_error e)
		{
			std::cout << e.what() << std::endl;

		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

	}
	
	void new_client(const std::string& first_name_in, const std::string& last_name_in, const std::string& email_in) {
		
		std::string cli ("INSERT INTO Client (first_name , last_name , email ) VALUES ('" +  first_name_in + "', '" + last_name_in + " ', ' " + email_in + " ')");
		

		try {
			pqxx::result r1 = w.exec(cli);
			
			
			
			
		}

		catch (pqxx::sql_error e)
		{
			std::cout << e.what() << std::endl;

		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}

	void delete_client(const std::string& first_name_in, const std::string& last_name_in) {
		std::string cli("DELETE FROM Client  WHERE first_name ='" + first_name_in + "' AND last_name = '" + last_name_in + " '");
		

		try {
			pqxx::result r1 = w.exec(cli);

			
		}

		catch (pqxx::sql_error e)
		{
			std::cout << e.what() << std::endl;

		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	void delete_number(const std::string& first_name_in, const std::string& last_name_in, const std::string& number_in) {
		std::string cli("SELECT id FROM Client  WHERE first_name ='" + first_name_in + "' AND last_name = '" + last_name_in + " '");

		try {
			auto id = w.query_value<std::string>(cli);
			std::string cli1 = "DELETE FROM Telephon  where number ='" + number_in + " 'AND client_id= ' " + id + " '";
			pqxx::result r1 = w.exec(cli1);


		}

		catch (pqxx::sql_error e)
		{
			std::cout << e.what() << std::endl;

		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	/*template <typename Type>
	void find(Type f, Type l) {
		std::string cli("SELECT id FROM Client  WHERE first_name ='" + f + "' AND last_name = '" + l + " '");

		try {
			auto id = w.query_value<std::string>(cli);



		}

		catch (pqxx::sql_error e)
		{
			std::cout << e.what() << std::endl;

		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

		template<>
		void find(Type e) {
			std::string cli("SELECT first_name,last_name,Email FROM Client  WHERE email ='" + e + "' "+"");

			
			try {
				for[auto first_name, last_name, email, telephon] : w.query_value<std::string, std::string, std::string, std::string>(cli);



			}

			catch (pqxx::sql_error e)
			{
				std::cout << e.what() << std::endl;

			}
			catch (std::exception e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	void find_client(const std::string& first_name_in, const std::string& last_name_in, const std::string& number_in) {}*/
	
	
	
	
	



protected:
	pqxx::work& w;
	
};
Client::Client(pqxx::work& in_w) : w(in_w) {}








int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=task4 "
			"user=postgres "
			"password=postgres "

		);
		
		

		pqxx::work w{ c };
		
		std::shared_ptr<Client> client = std::make_shared<Client>(w);
		/*client->create_table();*/
		
		
		client->new_client("Arthem", "Bliznyk","xaker321@ukr.net");
		/*client->delete_client("Alex", "Bliznyk");*/

		w.commit();

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