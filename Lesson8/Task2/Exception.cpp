#include "Exception.h"
#include <string>
#include <iostream>
#include "Figura.h"

 Bad_figure::Bad_figure(const std::string& _Message) : std::domain_error(_Message.c_str()){ }
 