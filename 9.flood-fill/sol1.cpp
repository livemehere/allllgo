#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int targetColor = image[sr][sc];
            if(targetColor == color) return image;
            adjacent(image,sr,sc,targetColor,color);
            return image;
        }

        void adjacent(vector<vector<int>>& image,int sr, int sc,int targetColor, int changeColor) {
            if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
            int v = image[sr][sc];
            if(v != targetColor)return;
            image[sr][sc] = changeColor;
            adjacent(image,sr-1,sc,targetColor,changeColor);
            adjacent(image,sr+1,sc,targetColor,changeColor);
            adjacent(image,sr,sc-1,targetColor,changeColor);
            adjacent(image,sr,sc+1,targetColor,changeColor);
        };

        
    };


int main(){
    return 0;
}