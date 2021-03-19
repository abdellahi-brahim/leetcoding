#include <iostream>
#include <algorithm>

using namespace std;

//recursive solution
int rpath(int *matrix, int *sum, int size, int x, int y){
    if(x == 0 || y == 0 || y > x)
        return 0;

    if(sum[x + y*size] > 0)
        return sum[x + y*size];

    sum[x + y*size] = matrix[x + y*size] + max(rpath(matrix, sum, size, x-1, y-1), rpath(matrix, sum, size, x-1, y));

    return sum[x + y*size];
}

//iterative solution
void ipath(int *matrix, int* sum, int size){
    for(int x = 0; x < size; ++x){
        for(int y = 0; y < x; ++y){
            sum[x + y*size] = matrix[x + y*size] + max(sum[x-1 + (y-1)*size], sum[x-1 + y*size]);
        }
    }
}

int main(){
    int cases;

    cin >> cases;

    for(int i = 0; i < cases; ++i){
        int size;
        cin >> size;
        
        size++;

        int *matrix = new int[size*size];
        int *sum = new int[size*size];

        for(int x = 0; x < size; ++x){
            for(int y = 0; y < size; ++y){
                sum[x + y*size] = 0;

                if(x == 0 || y == 0 || x < y){
                    matrix[x + y*size] = 0;
                    continue;
                }

                cin >> matrix[x + y*size];
            }   
        }

        //recursive
        for(int i = 0; i < size; ++i)
            rpath(matrix, sum, size, size-1, i);

        int max = 0;

        for(int y = 0; y < size; ++y){
            if(max < sum[(size-1) + y*size])
                max = sum[(size-1) + y*size];
        }

        cout << max << "\n";

        delete[] matrix;
        delete[] sum;
    }
    return 0;
}
