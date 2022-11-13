#include "Shop.h"


template<class Action>
void Shop::persist(Action& a)
{
	Wt::Dbo::field(a, name, "name");
	Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "id_shop");
}