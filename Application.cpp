#include <iostream>
/*

Function chess(x, y, m):

    if board [x][y] == 0 then:
        board[x][y] = 1
        v = 1

    if m = 0 then:
        return v

    else:
        return v + chess(x + 2, y + 1, m - 1)
                 + chess(x + 2, y - 1, m - 1) 
                 + chess(x - 2, y - 1, m - 1) 
                 + chess(x - 2, y + 1, m - 1)
                 + chess(x - 1, y + 2, m - 1)
                 + chess(x - 1, y + 2, m - 1)
                 + chess(x - 1, y + 2, m - 1)
                 + chess(x - 1, y + 2, m - 1)


*/

int chess(bool *board, int size, int x, int y, int m){
    int visited = 0;

    if(!board[x+ y*size]){
        board[x+ y*size] = true;
        visited = 1;
    }

    if(m == 0)
        return visited;

    else 
        return visited  + chess(board, size, x + 2, y + 1, m - 1)
                        + chess(board, size, x + 2, y - 1, m - 1) 
                        + chess(board, size, x - 2, y - 1, m - 1) 
                        + chess(board, size, x - 2, y + 1, m - 1)
                        + chess(board, size, x - 1, y - 2, m - 1)
                        + chess(board, size, x - 1, y + 2, m - 1)
                        + chess(board, size, x + 1, y + 2, m - 1)
                        + chess(board, size, x + 1, y - 2, m - 1);
}
int main() {
    int size = 400;
    bool *board = new bool[size*size];

    int n, sum = 0;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        int x, y, m;
        std::cin >> x >> y >> m;
        sum += chess(board, size, x + 200, y + 200, m);
    }
    std::cout << sum << std::endl;

    delete[] board;
    return 0;
}