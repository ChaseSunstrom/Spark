#ifndef CORE_TEST_HPP
#define CORE_TEST_HPP

#include "../core.hpp"

#include "../logging/log.hpp"

namespace ac
{
    namespace test
    {
		class test_register
        {
        public:

            struct test
            {
				test() = default;
				test(const std::string& name, std::function<bool()> function) : name(name), function(function) {}

                std::string name;
                std::function<bool()> function;
            };

            static void add_test(const std::string& name, std::function<bool()> function) 
            {
                get_tests().emplace_back(test(name, function));
            }

            static std::vector<test>& get_tests() 
            {
                static std::vector<test> tests;
                return tests;
            }
        };

#define CONCAT_INTERNAL(x,y) x##y
#define CONCAT(x,y) CONCAT_INTERNAL(x,y)

#define TEST(name) \
             bool name(); \
             namespace { \
                struct CONCAT(test_register_, name) { \
                    CONCAT(test_register_, name)() { \
                        test_register::add_test(#name, name); \
                    } \
                } CONCAT(test_register_instance_, name); \
             } \
             bool name()

        bool core_test_main();
    }
}

#endif // CORE_TEST_H