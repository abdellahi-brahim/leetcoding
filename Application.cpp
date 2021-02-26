#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve(vector<int>guests, int n){
    sort(guests.begin(), guests.end());
    
    for(int i  = 0; i < n - 2; ++i){
        int start = i + 1;
        int end = n - 1;
        int a = guests[i];
        
        while(start < end){
            int b = guests[start];
            int c = guests[end];

            if(a + b + c == 0){
                cout << "Fair" << endl;
                return;
            }
            else if(a + b + c < 0){
                start++;
            }
            else{
                end--;
            }
        }
    }
    cout << "Rigged" << endl;
}

int main(){
    int n;

    while(cin >> n){
        vector<int>guests;
        int el;

        for(int i  = 0; i < n; ++i){
            cin >> el;
            guests.push_back(el);
        }

        cin >> el;
        
        solve(guests, n);
    }
}
