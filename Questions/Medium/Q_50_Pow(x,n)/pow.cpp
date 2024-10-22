// 1 -------- works but gives TLE error
class Solution
{
public:
 double myPow(double x, int n)
 {
  if (n == 0)
   return 1;
  if (n < 0)
  {
   x = 1 / x;
   n = -n;
  }
  double res = 1;
  for (int i = 0; i < n; i++)
  {
   res *= x;
  }
  return res;
 }
};

// Time Complexity: O(log(n))

#include <iostream>
using namespace std;

double pow(double n, int p)
{
 if (p == 0)
 {
  return 1; // n^0 = 1
 }
 if (p < 0)
 {
  n = 1 / n; // For negative exponent, invert the base
  p = -p;    // Make p positive
 }

 double res = 1;
 for (int i = 0; i < p; i++)
 { // Loop runs exactly p times
  res = res * n;
  cout << "Res after iteration " << i + 1 << ": " << res << endl;
 }
 return res;
}

int main()
{
 double num;
 int p;

 cout << "Enter base: ";
 cin >> num;
 cout << "Enter exponent: ";
 cin >> p;

 double res = pow(num, p);
 cout << "Result: " << res << endl;

 return 0;
}

// Optimized approach by squaring

/*
A more efficient method for implementing pow ( x , n ) pow(x,n) is known as exponentiation by squaring. This technique reduces the time complexity to O ( log ⁡ n ) O(logn) instead of O ( n ) O(n) by breaking down the power calculations into smaller parts and using the properties of exponents. Here's how it works: If n n is 0, return 1 (because any number raised to the power of 0 is 1). If n n is negative, convert n n to positive and take the reciprocal of x x. Use a loop that repeatedly squares x x and reduces n n by half. If n n is even, square x x and halve n n. If n n is odd, multiply the result by x x and decrement n n.


Explanation: Base Case: If n n is 0, return 1. Negative Exponent: If n n is negative, invert x x and make n n positive. Main Loop: Use a loop that runs while n n is greater than 0. If n n is odd, multiply the current result by current_product. Regardless of whether n n was odd or even, square current_product and divide n n by 2. Finally, return the computed result. Efficiency This algorithm reduces the number of multiplications needed, making it efficient even for large values of n n. The time complexity is O ( log ⁡ n ) O(logn) in the worst case, which solves the issue of time limits exceeded in your initial approach.

*/
class Solution
{
public:
 double myPow(double x, int n)
 {
  if (n == 0)
   return 1;
  if (n < 0)
  {
   x = 1 / x;
   n = -n;
  }

  double result = 1.0;
  double current_product = x;

  while (n > 0)
  {
   if (n % 2 == 1)
   {
    result *= current_product;
   }
   current_product *= current_product;
   n /= 2;
  }

  return result;
 }
};

// O(log(N))
/*

The runtime error you're encountering in your myPow function is due to the way you’re handling the negation of the minimum int value. In C++, the minimum integer value, -2147483648, cannot be represented as a positive integer if you simply negate it (-(-2147483648)), leading to undefined behavior because it exceeds the maximum positive value for a signed integer (2147483647).

To resolve this issue, you can check if n is equal to INT_MIN (which is -2147483648) and handle that case specifically. This way, you avoid the direct negation. Here's how you can modify the implementation:



Explanation of Changes:
Handling n == INT_MIN:

Instead of directly negating n, we handle the case where n is INT_MIN separately. The solution is to increment n by 1 before negating it to avoid overflow.
When you set n = -(n + 1), you ensure you convert n from -2147483648 to 2147483647, which is safely representable.
Final Return:

For the case of n = INT_MIN, we multiply the result by x after adjusting n, as you need to account for the extra multiplication by reversing the effect of the x adjustment.
This adjustment should fix the runtime error you encountered when n is the smallest possible integer. The rest of the logic for exponentiation by squaring remains unchanged, ensuring the overall complexity remains
O
(
log
⁡
n
)
O(logn).
*/
#include <limits.h> // for INT_MIN

class Solution
{
public:
 double myPow(double x, int n)
 {
  if (n == 0)
   return 1; // Any number raised to the power 0 is 1

  // Handle the case when n is INT_MIN
  if (n == INT_MIN)
  {
   x = 1 / x;              // Change x to 1/x
   n = -(n + 1);           // Convert n to its opposite value except for the smallest int
   return x * myPow(x, n); // Call the function for n-1 and multiply with x
  }

  // If n is negative, convert it to positive
  if (n < 0)
  {
   x = 1 / x; // Change x to 1/x
   n = -n;    // Make n positive
  }

  double result = 1.0;
  double current_product = x;

  // Exponentiation by squaring
  while (n > 0)
  {
   if (n % 2 == 1)
   {                           // If n is odd
    result *= current_product; // Multiply result by current_product
   }
   current_product *= current_product; // Square the current_product
   n /= 2;                             // Divide n by 2
  }

  return result; // Return the final result
 }
};