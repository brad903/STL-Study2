#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<int> shape = {1};

class CantorDust {
    public:
    int occurrenceNumber(vector<string> pattern, int time){
        // make shape depending on time
        for(int i=0; i<time; i++){
            makeshape();
        }
        
        // make 2d array
        int shapeLength = shape.size();
        vector<vector<int>> sqaShape;
        for(int i=0; i<shapeLength; i++){
            vector<int> rowShape;
            for(int j=0; j<shapeLength; j++){
                rowShape.push_back(shape[i] & shape[j]);
            }
            sqaShape.push_back(rowShape);
        }
        vector<vector<int>> sqaPattern;
        for(int i=0; i<pattern.size(); i++){
            vector<int> rowShape;
            for(int j=0; j<pattern[i].length(); j++){
                if(pattern[i][j] == 'X'){
                    rowShape.push_back(1);
                }else{
                    rowShape.push_back(0);
                }
            }
            sqaPattern.push_back(rowShape);    
        }

        // compare
        int rowLength = sqaShape.size() - sqaPattern.size() + 1;
        int colLength = sqaShape.size() - sqaPattern[0].size() + 1;
        int result = 0;
        for(int i=0; i<rowLength; i++){
            for(int j=0; j<colLength; j++){
                bool flag = true;
                for(int k=0; k<sqaPattern.size(); k++){
                    for(int l=0; l<sqaPattern[k].size(); l++){
                        if(sqaShape[i+k][j+l] != sqaPattern[k][l]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(flag) result++; 
            }
        }

        return result;
    }

    void makeshape(){
        vector<int> copyShape = shape;
        shape.clear();
        for(int i=0; i<3; i++){
            for(int j=0; j<copyShape.size(); j++){
                if(i==0 || i==2){
                    shape.push_back(copyShape[j]);
                }else {
                    shape.push_back(0);
                }
            }
        }
    }
};

int main(){
    CantorDust cantorDust;

    vector<string> pattern;
    pattern.push_back(".X");
    pattern.push_back("..");
    int time = 1;
    
    int result = cantorDust.occurrenceNumber(pattern, time);
    printf("result : %d\n", result);

    return 0;
}