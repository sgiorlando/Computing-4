//Scott Giorlando
#ifndef LFSR_HPP
#define LFSR_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class LFSR
{
public:
  //Constructor LFSR takes in two parameters, a string and a int.  The String represents the bit sequence that is going to be used in the step function.  The int tap represents that bit that is going to be Xor'ed with the left most bit.
  //The Constructor stores the seed into a private string variable so it can be used later.  The same is for the tap bit.
  LFSR(std::string seed, int t);
  //Function step takes in no parameters, but the function is meant to take the bit sequence and grab the left most bit and Xor it with the specific tap bit.  The tap bit refers to the specific bit in the sequence that is going to be Xor'ed.
  //This function takes the Xor'ed bit as the return value, it's either a 0 or 1.
  int step();
  //Function generate takes in one int as it's parameter, the int k is meant to be how many times the generate function calls the step function.  The return value for this is each Xor'ed bit from the step function at the current time.
  int generate(int k);
  //Overloaded ostream operator<< basically just takes in an ostream object and the created LFSR object and just converts it to a string for output, it takes the converted object into a string for output as it's return value.
  friend std::ostream& operator<<(std::ostream& out, const LFSR &lfsr);

private:
  std::string bit_seed;//A string to store the seed in the Constructor.
  int tap;//A regular int to take the tap value.
  int XorBit;//An int to store the value of the left most bit Xor'ed with the tap bit.
};

#endif
