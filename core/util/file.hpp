#ifndef CORE_FILE_HPP
#define CORE_FILE_HPP

#include "../core.hpp"

namespace ac
{
	__A_CORE_API__ std::string read_file(const std::filesystem::path& path);
}

#endif