// Definition of a petrol pump with petrol and distance attributes
struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    // Function to find the starting point where the truck can complete the circle
    // without exhausting its petrol in between.
    int tour(petrolPump p[], int n) {
        int deficit = 0;  // To track the deficit of petrol
        int balance = 0;  // To track the current balance of petrol
        int start = 0;    // To store the potential starting point

        // Iterate through each petrol pump
        for (int i = 0; i < n; i++) {
            // Calculate the balance of petrol at the current petrol pump
            balance += p[i].petrol - p[i].distance;

            // If the balance becomes negative, update the deficit and reset the balance
            if (balance < 0) {
                deficit += balance;  // Update the deficit with the current balance
                start = i + 1;       // Update the potential starting point to the next petrol pump
                balance = 0;         // Reset the balance to zero
            }
        }

        // If the total balance plus deficit is non-negative, return the starting point
        if (balance + deficit >= 0) {
            return start;
        }

        // If the total balance plus deficit is negative, return -1 (impossible to complete the circle)
        return -1;
    }
};
