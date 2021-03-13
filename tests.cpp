#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
TEST_CASE("countChar"){
    CHECK(countChar("Hello, World!", 'e') == 1);
    CHECK(countChar("ABCDEFGHIJKLMNOPQRSTUVWXYZ", '1') == 0);
    CHECK(countChar("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 'A') == 1);
    CHECK(countChar("Pineapple on Pizza is bad", 'a') == 3);
}

TEST_CASE("removeLeadingSpaces"){
    CHECK(removeLeadingSpaces("             Hello, World!").compare("Hello, World!") == 0);
    CHECK(removeLeadingSpaces("    ").compare("") == 0);
    CHECK(removeLeadingSpaces("             only leading spaces are bad.").compare("only leading spaces are bad.") == 0);
    CHECK(removeLeadingSpaces("                 Ending spaces and new \n lines are fine \t").compare("Ending spaces and new \n lines are fine \t") == 0);
}
