#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestRectangleArea(int heights[], int n) {
    if (n == 0) return 0;
    
    vector<int> lessFromLeft(n);
    vector<int> lessFromRight(n);
    
    lessFromLeft[0] = -1;
    lessFromRight[n - 1] = n;

    for (int i = 1; i < n; i++) {
        int p = i - 1;
        while (p >= 0 && heights[p] >= heights[i]) {
            p = lessFromLeft[p]; 
        }
        lessFromLeft[i] = p;
    }

    for (int i = n - 2; i >= 0; i--) {
        int p = i + 1;
        while (p < n && heights[p] >= heights[i]) {
            p = lessFromRight[p]; 
        }
        lessFromRight[i] = p;
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int area = heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1);
        if (area > maxArea) maxArea = area; 
    }

    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);
    cout << "Largest rectangle area: " << largestRectangleArea(heights, n) << endl;
    return 0;
}

