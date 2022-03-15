/**
 * @file Test.cpp
 * @author Sean Peer (SeanPeer@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "doctest.h"
#include "mat.hpp" 

using namespace ariel;

#include <string>
#include <algorithm>

using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
	CHECK(nospaces(mat(11, 7, '@', '-')) == nospaces("@@@@@@@@@@@\n@---------@\n@-@@@@@@@-@\n@-@-----@-@\n@-@@@@@@@-@\n@---------@\n@@@@@@@@@@@"));
	CHECK(nospaces(mat(13, 9, '#', '*')) == nospaces("#############\n#***********#\n#*#########*#\n#*#*******#*#\n#*#*******#*#\n#*#*******#*#\n#*#########*#\n#***********#\n#############"));
	CHECK(nospaces(mat(13, 5, '#', '*')) == nospaces("#############\n#***********#\n#*#########*#\n#***********#\n#############"));	
	CHECK(nospaces(mat(3, 5, '$', '*')) == nospaces("$$$\n$*$\n$*$\n$*$\n$$$"));	
	CHECK(nospaces(mat(5, 5, '&', '^')) == nospaces("&&&&&\n&^^^&\n&^^^&\n&^^^&\n&&&&&"));											 
	CHECK(nospaces(mat(1, 1, '(', '^')) == nospaces("("));
	CHECK(nospaces(mat(1, 3, '(', '^')) == nospaces("(\n(\n("));
	CHECK(nospaces(mat(1, 5, '@', '-')) == nospaces("@\n@\n@\n@\n@"));
	CHECK(nospaces(mat(3, 1, '$', '*')) == nospaces("$$$"));
	CHECK(nospaces(mat(3, 1, '@', '^')) == nospaces("@@@"));	
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(10, 5, '%', '+'));
}

TEST_CASE("Bad input - Same symbol") {
    CHECK_THROWS(mat(9, 7, '#', '#'));
    CHECK_THROWS(mat(13, 5, '$', '$'));
    CHECK_THROWS(mat(3, 5, '!', '!'));
    CHECK_THROWS(mat(9, 17, '@', '@'));
}

TEST_CASE("Bad input - even numbers") {
    CHECK_THROWS(mat(2, 4, '+', '#'));
    CHECK_THROWS(mat(10, 4, '-', '$'));
}

TEST_CASE("Bad input - even row number") {
    CHECK_THROWS(mat(2, 5, '+', '#'));
    CHECK_THROWS(mat(10, 7, '-', '$'));
    CHECK_THROWS(mat(8, 13, '!', '$'));
}

TEST_CASE("Bad input - Even col number") {
    CHECK_THROWS(mat(3, 4, '+', '#'));
    CHECK_THROWS(mat(5, 8, '-', '$'));
    CHECK_THROWS(mat(7, 16, '*', '!'));
}

TEST_CASE("Bad input - Both even number") {
    CHECK_THROWS(mat(8, 4, '%', '#'));
    CHECK_THROWS(mat(10, 6, '!', '$'));
}

TEST_CASE("Bad input - not given a number") {
    CHECK_THROWS(mat(0, 0, '+', '#'));
}

TEST_CASE("Bad input - missing an input number") {
    CHECK_THROWS(mat(0, 5, '+', '#'));
    CHECK_THROWS(mat(7, 0, '!', '$'));
}

TEST_CASE("Bad input - missing an input symbol") {
    CHECK_THROWS(mat(7, 5, ' ', '#'));
    CHECK_THROWS(mat(7, 3, '!', ' '));
    CHECK_THROWS(mat(3, 9, ' ', ' '));
}