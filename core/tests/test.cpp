#include "test.hpp"

namespace ac
{
	namespace test
	{

        TEST(test_test)
        {
			return true;
        }

        TEST(test_error)
        {
            return false;
        }

        bool core_test_main()
        {
            bool all_passed = true;

            for (const auto& test : test_register::get_tests())
            {
                bool result = test.function();

                if (!result)
                {
                    A_CORE_ERROR("[TEST FAILED]: " << test.name);
                    all_passed = false;
                }

                // Have to use curly braces here because this macro is goofy
                else
                {
                    A_CORE_INFO("[TEST SUCCESS]: " << test.name);
                }
            }

            return all_passed;
        }
	}
}