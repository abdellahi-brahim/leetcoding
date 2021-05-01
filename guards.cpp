#include <iostream>
#include <algorithm>

using namespace std;

int solve(int *objects, int *guards, int n, int range){
    sort(objects, objects + n);

    int i = 0;

    guards[0] = objects[0] + range;

    for(int j = 1; j < n; ++j){
        if(objects[j] > guards[i] + range){
            i++;
            guards[i] = objects[j] + range;
        }
    }

    return i+1;
}

int main(){
    int cases;
    
    cin >> cases;

    while(cases--){
        int range, n;

        cin >> n >> range;

        int *objects = new int[n];
        int *guards = new int[n];
        
        for(int i = 0; i < n; ++i)
            cin >> objects[i];

        for(int i = 0; i < n; ++i)
            guards[i] = 0;

        cout << solve(objects, guards, n, range) << endl;
    }
}
