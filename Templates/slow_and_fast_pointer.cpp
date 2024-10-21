#include <vector>  
#include <iostream>  

int fn(std::vector<int>& arr) {  
    int slow = 0; // Slow pointer initializer  
    int ans = 0;  // Result variable  
    int fast = 1; // Fast pointer initializer  

    // Ensure the fast pointer doesn't go out of bounds  
    while (fast < arr.size()) {  
        // Replace CONDITION with your specific logic  
        if (/* CONDITION */) {  
            slow += 1;                      // Move slow pointer forward  
            arr[slow] = arr[fast];          // Optional, depending on your logic  
            ans++;                           // Update result if needed  
        }  
        fast += 1; // Always move fast pointer forward  
    }  

    return ans; // Return the result  
}  

int main() {  
    std::vector<int> arr = {1, 3, 2, 2, 3, 4, 4}; // Example input  
    int result = fn(arr);  
    std::cout << "Result: " << result << std::endl;  
    return 0;  
}