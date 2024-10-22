class Solution
{
public:
 uint32_t reverseBits(uint32_t n)
 {
  uint32_t rev = 0;
  for (int i = 0; i < 32; i++)
  {
   rev = (rev << 1) | (n & 1);
   n = n >> 1;
  }
  return rev;
 }
};

/*
Detailed Explanation of the Code:
Initialization:

uint32_t rev = 0; initializes a variable rev to store the reversed bits.
Loop through Each Bit:

The for loop runs 32 times to cover all bits of the 32-bit integer.
Extract the Least Significant Bit: (n & 1) extracts the least significant bit of n.
Add to rev: rev = (rev << 1) | (n & 1); shifts rev left by one bit and adds the extracted bit to it.
Shift n: n >>= 1; right shifts n to process the next bit in the next iteration.
Return Reversed Bits:

After the loop, rev holds the bits of n in reverse order. The function returns rev.
*/