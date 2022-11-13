
#include "Publisher.h"

template<class Action>
void Publisher::persist(Action& a)
{ Wt::Dbo::field(a, name, "name");
Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "id_publisher");
 } 



