#ifndef CORE_ENTITY_TYPE_HPP
#define CORE_ENTITY_TYPE_HPP

#include "../../core.hpp"

namespace ac
{
	// Needs a seperate file to prevent circular dependency
	__A_CORE_API__ using entity = uint64_t;
}

#endif