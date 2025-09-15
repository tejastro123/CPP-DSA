/*The span of the stock's price in one day is the maximum number of consecutive days 
(starting from that day and going backward) for which the stock price was less than 
or equal to the price of that day.*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {

    vector<int> price = {100,80,60,70,60,75,85};

    vector<int> ans(price.size(), 0);
    stack<int> s;

    //solution
    for( int i = 0; i < price.size(); i++ ) {
        while( !s.empty() && price[i] >= price[s.top()] ) {
            s.pop();
        }
        if( s.empty() ) {
            ans[i] = i + 1;
        } else {
            ans[i] = i - s.top();//i-prevHigh
        }
        s.push(i);
    }
    //print ans values
    for( int i = 0; i < price.size(); i++ ) {
        cout << ans[i] << " ";
    }
    return 0;

}// tc: O(n), sc: O(n) for stack space