#include <iostream>
#include <vector>
using namespace std;

// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int n = gas.size();
//     for(int i = 0; i < n; i++) {
//         int gasLeft = 0;
//         int j = i;
//         while(true) {
//             gasLeft += gas[j] - cost[j];
//             if(gasLeft < 0) {
//                 break;
//             }
//             j = (j + 1) % n;
//             if(j == i) {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {//O(n)
    int n = gas.size();
    int totalGas = 0;
    int totalCost = 0;

    int currentGas = 0;
    int start = 0;

    for(int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas += (gas[i] - cost[i]);
        if(currentGas < 0) {
            start = i + 1;
            currentGas = 0;
        }
    }
    return totalGas >= totalCost ? start : -1;
}

int main() {
    vector<int> gas = {1,2,4,5,9};
    vector<int> cost = {3,4,1,10,1};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
