#include <iostream>
#include <string>

using namespace std;

bool findPath(int board[][5], int visited[][5], int posX, int posY) {
    if (posX < 0 || posY < 0) return false; // bounds
    if (posX > 4 || posY > 4) return false; // bounds
    if (board[posX][posY] == 1) return false; // walls
    if (visited[posX][posY] == 1) return false;
    else visited[posX][posY] = 1;
    if (posX == 4 && posY == 4) return true; // found
    return 
        findPath(board, visited, posX+1, posY) ||
        findPath(board, visited, posX, posY+1) ||
        findPath(board, visited, posX-1, posY) ||
        findPath(board, visited, posX, posY-1);
}   

int main() {
    int T;
    string trash;
    
    cin >> T;
    // cin >> trash; //whitespace
    
    for (int t=0; t<T; t++) {
        int arr[5][5];
        int visited[5][5];

        for(int i=0; i<5;i++){
            for (int j=0; j<5; j++) {
                cin >> arr[i][j];
                visited[i][j] = 0;
            }
        }
        // cin >> trash;

        if (findPath(arr, visited, 0, 0)) cout << "COPS";
        else cout << "ROBBERS";
        
        cout << endl;
    }

    return 0;
}