#include <pqxx/pqxx>
#include <iostream>
#include <windows.h>


class Find
{
public:
	Find(pqxx::work& in_w);
	
    void find_name(const std::string& first, const std::string& last) {
		std::string cli("SELECT id FROM Client  WHERE first_name ='" + first + "' AND last_name = '" + last + "' "); 

		try {
			auto id = w.query_value<std::string>(cli);
			std::cout << "Код \t" << id;

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
	
	void find_email(const std::string& emai) {
			std::string cli("SELECT first_name, last_name, email, number FROM Client c JOIN telephon t on (c.email = '"+ emai +"' and c.id = t.client_id)");

			
			try {
				for (auto [first_name, last_name, email, telephon] : w.query<std::string, std::string, std::string, std::string> (cli)) {
					std::cout << "Имя: " << first_name<<"\t" << " Фамилия: " << last_name << "\t" << " email: " << email << "\t" << "Телефон: " << telephon;
				}



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
	void find_num(const std::string& num) {
		std::string cli("SELECT first_name, last_name, Email, number FROM Client  c join telephon t on(t.number = '" + num + "' and c.id = t.client_id)");


		try {
			for (auto [first_name, last_name, email, telephon] : w.query<std::string, std::string, std::string, std::string>(cli))
				std::cout << "Имя: " << first_name << "\t" << " Фамилия: " << last_name << "\t" << " email: " << email << "\t" << "Телефон: " << telephon;


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



protected:
	pqxx::work& w;
	

};
Find::Find(pqxx::work& in_w) : w(in_w) {}


class Client {
public:

	Client(pqxx::work& in_w);
	
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

	void add_number(const std::string& first_name_in, const std::string& last_name_in, const std::string& number_in) const {
		std::string id = find_id (first_name_in, last_name_in);

		try {
			
			std::string cli1 = "INSERT INTO Telephon (number, client_id) VALUES ( '" + number_in + "', '" + id + "')";
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
		
		std::string cli ("INSERT INTO Client (first_name , last_name , email ) VALUES ('" +  first_name_in + "', '" + last_name_in + "', '" + email_in + "')");
		

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
		

		try {
			std::string id = find_id(first_name_in, last_name_in);
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

	
	
	void update_first(const std::string& first_name_in, const std::string& last_name_in, const std::string& first_name_new ) {
		std::string cli("UPDATE client SET first_name = '" + first_name_new + "' where first_name = '" + first_name_in + "' and last_name='" + last_name_in + "'");


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
	void update_last(const std::string& first_name_in, const std::string& last_name_in, const std::string& last_name_new) {
		std::string cli("UPDATE client SET last_name = '" + last_name_new + "' where first_name = '" + first_name_in + "' and last_name='" + last_name_in + "'");


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
	void update_email(const std::string& email, const std::string& new_email) {
		std::string cli("UPDATE client SET email = '" + new_email + "' where email = '" + email  + "'");


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
	void update_telephone(const std::string& telephon, const std::string& telephon_new) {
		
		std::string cli("UPDATE telephon SET number = '" + telephon_new + "' where number = '" + telephon  + "'");


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

	
	
	
	
	



protected:
	pqxx::work& w;
	std::shared_ptr<Find> find;
	std::string find_id(const std::string& first, const std::string& last)const {

		std::string fin("SELECT id FROM Client  WHERE first_name ='" + first + "' AND last_name = '" + last + "' ");

		try {
			auto id = w.query_value<std::string>(fin);


			return id;
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
		std::shared_ptr<Find> find = std::make_shared<Find>(w);

		/*client->create_table();*/
		
		
		/*client->new_client("Alex", "Bliznyk","netuschd@ukr.net");*/
		
		/*client->add_number("Alex", "Bliznyk", "864857454345");*/
		client->update_telephone("864857454345", "892844367812");
		
		/*find->find_name("Alex", "Bliznyk");*/
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