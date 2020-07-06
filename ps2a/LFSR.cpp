//Scott Giorlando
#include "LFSR.hpp"

//Constructor LFSR takes in two parameters, a string and a int.  The String represents the bit sequence that is going to be used in the step function.  The int tap represents that bit that is going to be Xor'ed with the left most bit.
//The Constructor stores the seed into a private string variable so it can be used later.  The same is for the tap bit.
LFSR::LFSR(std::string seed, int t)
{
  bit_seed = seed;
  tap = seed.length() - 1 - t;//Set tap value to the total length of the seed minus 1 minus the given tap value to get the right position.
}

//Function step takes in no parameters, but the function is meant to take the bit sequence and grab the left most bit and Xor it with the specific tap bit.  The tap bit refers to the specific bit in the sequence that is going to be Xor'ed.
//This function takes the Xor'ed bit as the return value, it's either a 0 or 1.
int LFSR::step()
{
  int leftBit, tapBit;
  char charXorBit;

  //If statement compares the specific character at the leftmost bit to see if its a 1 or 0.  The variable leftBit will either be a 1 or 0 depending on what the character equals.
  if(bit_seed.at(0) == '0')
  {
    leftBit = 0;
  }
  else if(bit_seed.at(0) == '1')
  {
    leftBit = 1;
  }

//If statement compares the specific character at the tap bit to see if its a 1 or 0.  The variable tap will either be a 1 or 0 depending on what the character equals.
  if(bit_seed.at(tap) == '0')
  {
    tapBit = 0;
  }
  else if(bit_seed.at(tap) == '1')
  {
    tapBit = 1;
  }

  //XorBit xor's the variable leftBit and tapBit together, it can only equal one or zero.
  XorBit = leftBit ^ tapBit;

  //Shifts the bits in the seed to the left.
  for(unsigned int i = 0; i < bit_seed.length() - 1; i++)
  {
    bit_seed.at(i) = bit_seed.at(i + 1);
  }

  //Comparison to see if the XorBit equals a one or zero, depending on the value of XorBit a new char variable named charXorBit will store either a character 1 or character 0.
  if(XorBit == 0)
  {
    charXorBit = '0';
  }
  else if(XorBit == 1)
  {
    charXorBit = '1';
  }

  //Assigns the rightmost bit to the value of charXorBit.
  bit_seed.at(bit_seed.length() - 1) = charXorBit;

  //Finally returns the value of XorBit.
  return XorBit;
}

//Function generate takes in one int as it's parameter, the int k is meant to be how many times the generate function calls the step function.  The return value for this is each Xor'ed bit from the step function at the current time.
int LFSR::generate(int k)
{
  int x = 0;
  for(int i = 0; i < k; i++)
  {
    int newBit = step();
    x *= 2;
    if(newBit == 1)
    {
      x += 1;
    }
  }
  return x;
}

//Overloaded ostream operator<< basically just takes in an ostream object and the created LFSR object and just converts it to a string for output, it takes the converted object into a string for output as it's return value.
std::ostream& operator<<(std::ostream& out, const LFSR &lfsr)
{
  out << lfsr.bit_seed;
  return out;
}
