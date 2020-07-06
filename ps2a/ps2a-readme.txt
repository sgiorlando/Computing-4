1.) Name: Scott Giorlando

2.) For my representation of the bits I took a private string variable and stored the seed into that new string.  Once I did that I used a if statement to check and see if the bits were a '1' or '0' using the string.at() command.
Once I found out if the specific bits on the leftmost bit and the tap bit were a '1' or '0' I stored the integer values into new integer variables separate for both the tap and leftmost bit.  Then I Xor'ed those bits together into a new integer and used
that for my bit that would be placed on the right side.  I used this method because I originally wanted to use a array or vector for the specific bits, then I realized that I could implement this in a much simpler and easier manner, so I decided to use
this method as my way of registering the bits.  It was also a lot easier to debug and start my unit testing this way.

3.) In my two additional Boost tests I'm using the Princeton University examples that were mentioned and checking to see if the Constructor and Step function work properly.  The first one checks the specific bit in the step function and compares to see
if the bit is a one or a zero, if the bit doesn't match the specific comparison then it fails the test case.
The second boost test is to see if the Constructor and Generate functions work properly.  This test is to see if the Generate function creates the specific generation provided in the comparison.
For example the first generate should be 25, if it isn't 25 then the test fails.
