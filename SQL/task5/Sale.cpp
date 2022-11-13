#include "Sale.h"
template<class Action>

void Sale::persist(Action& a)
{
	Wt::Dbo::field(a, price, "price");
	Wt::Dbo::field(a, date_sale, "date_sale");
	
	Wt::Dbo::belongsTo(a, id_stock, "id_stock");
	
	Wt::Dbo::field(a, count, "count");
}