//
class Solution
{
public:
 int maximumWealth(vector<vector<int>> &accounts)
 {
  int maxWealth = 0;

  for (int i = 0; i < accounts.size(); i++)
  {

   int sum = 0;

   for (int j = 0; j < accounts[i].size(); j++)
   {
    sum += accounts[i][j];
   }
   if (sum > maxWealth)
   {
    maxWealth = sum;
   }
  }
  return maxWealth;
 }
};

// leetcode solution
class Solution
{
public:
 int maximumWealth(int[][] accounts)
 {
  int maxWealthSoFar = 0;

  for (int[] customer : accounts)
  {
   int currentCustomerWealth = 0;

   for (int bank : customer)
   {
    currentCustomerWealth += bank;
   }
   maxWealthSoFar = Math.max(maxWealthSoFar, currentCustomerWealth);
  }
  return maxWealthSoFar;
 }
}

// full solution
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
 int maximumWealth(vector<vector<int>> &accounts)
 {
  int maxWealth = 0;
  // cout << "Accounts.size: " << accounts.size() << endl; //  no of customers
  for (int i = 0; i < accounts.size(); i++)
  {

   int sum = 0;
   // cout << "Accounts[i].size: " << accounts[i].size() << endl; // no of banks
   for (int j = 0; j < accounts[i].size(); j++)
   {
    sum += accounts[i][j];
   }
   if (sum > maxWealth)
   {
    maxWealth = sum;
   }
  }
  return maxWealth;
 }
};

int main()
{
 int numOfCustomers, numOfBanks, richestCustomer;
 Solution sol;
 vector<vector<int>> accounts;

 cout << "Number of Customers: ";
 cin >> numOfCustomers;
 cout << "Number of Banks: ";
 cin >> numOfBanks;

 // Dynamically sets the size of the accounts vector based on user input for the number of customers and banks.
 accounts.resize(numOfCustomers, vector<int>(numOfBanks));

 // taking input for accounts vector
 for (int i = 0; i < numOfCustomers; i++)
 {
  for (int j = 0; j < numOfBanks; j++)
  {
   cin >> accounts[i][j];
  }
  cout << endl;
 }

 richestCustomer = sol.maximumWealth(accounts);

 cout << "Richest Customer Wealth: " << richestCustomer << endl;

 return 0;
}