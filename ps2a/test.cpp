//Scott Giorlando
#include <iostream>
#include <string>
#include <sstream>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR lfsr1("001", 1);
  std::stringstream buffer;
  buffer << lfsr1;

  if(buffer.str().compare("001") == 0)
  {
    std::cout << "Yeah!\n";
  }
  else
  {
    std::cout << "Argh!\n";
  }

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}

/*
  This test makes sure the Constructor and Step function work properly, this follows the Princeton University test examples that were explained on their website.
  Basically what it does is it checks the specifc bit in the step function and compares to see if the bit is a one or a zero, if the bit doesn't match the specifc comparison then it fails the test case.
*/
BOOST_AUTO_TEST_CASE(ConstructorAndStep)
{
  LFSR l("01101000010", 8);

  int test_bit = l.step();
  BOOST_CHECK(test_bit == 1);
  int test_bit2 = l.step();
  BOOST_CHECK(test_bit2 == 1);
  int test_bit3 = l.step();
  BOOST_CHECK(test_bit3 == 0);
  int test_bit4 = l.step();
  BOOST_CHECK(test_bit4 == 0);
  int test_bit5 = l.step();
  BOOST_CHECK(test_bit5 == 1);
  int test_bit6 = l.step();
  BOOST_CHECK(test_bit6 == 0);
  int test_bit7 = l.step();
  BOOST_CHECK(test_bit7 == 0);
  int test_bit8 = l.step();
  BOOST_CHECK(test_bit8 == 1);
  int test_bit9 = l.step();
  BOOST_CHECK(test_bit9 == 0);
  int test_bit10 = l.step();
  BOOST_CHECK(test_bit10 == 0);
}

/*
  This function also follows the Princeton University example for a test case.  This tests the Constructor and Generate functions to see if they work properly.
  The idea behind this test is to see if the Generate function creates the specific generation provided in the comparison.  For example the first generate should be 25, if it isn't 25 then the test fails.
*/
BOOST_AUTO_TEST_CASE(ConstructorAndGenerate)
{
  LFSR l1("01101000010", 8);

  int num1 = l1.generate(5);

  BOOST_CHECK(num1 == 25);

  int num2 = l1.generate(5);
  BOOST_CHECK(num2 == 4);

  int num3 = l1.generate(5);
  BOOST_CHECK(num3 == 30);

  int num4 = l1.generate(5);
  BOOST_CHECK(num4 == 27);

  int num5 = l1.generate(5);
  BOOST_CHECK(num5 == 18);

  int num6 = l1.generate(5);
  BOOST_CHECK(num6 == 26);

  int num7 = l1.generate(5);
  BOOST_CHECK(num7 == 28);

  int num8 = l1.generate(5);
  BOOST_CHECK(num8 == 24);

  int num9 = l1.generate(5);
  BOOST_CHECK(num9 == 23);

  int num10 = l1.generate(5);
  BOOST_CHECK(num10 == 29);
}
