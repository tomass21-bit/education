#include "Stock.h"

template<class Action>

void Stock::persist(Action& a)
{
	Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "id_stock");
	Wt::Dbo::belongsTo(a, id_shop, "id_shop");
	Wt::Dbo::belongsTo(a, id_book, "id_book");
	Wt::Dbo::field(a, count, "count");
}