#include "Book.h"
template<class Action>

void Book::persist(Action& a)
{
	Wt::Dbo::field(a, title, "title");
	Wt::Dbo::belongsTo(a, id_publisher, "id_publisher");
	Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "id_book");
}