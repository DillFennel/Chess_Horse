#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int n = 8;
bool chessboard [n][n];
vector <pair <int, int>> moves = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
bool chessboard_check(){
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            if(chessboard[y][x] == false){
                return false;
            }
        }
    }
    return true;
}
string horse(int y, int x){
    chessboard[y][x] = true;
    int new_y, new_x;
    for(pair<int, int> move : moves){
        new_y = y+move.first;
        new_x = x+move.second;
        if(new_y>=0 and new_x>=0 and new_y<n and new_x<n and chessboard[new_y][new_x] == false){
            string path = horse(new_y, new_x);
            if(not(path.empty())){
                return to_string(y)+' '+to_string(x)+", "+ path;
            }
        }
    }
    if(chessboard_check()){
        return to_string(y)+' '+to_string(x);
    }
    return "";
}
int main()
{
    cout<<"Получившийся путь коня: "<<horse(0,0);
    return 0;
}