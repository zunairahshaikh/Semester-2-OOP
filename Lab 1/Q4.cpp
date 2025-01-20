/*Q4: You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.*/

#include <iostream>
using namespace std;

int main(){
    int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);

    int startPos =0, endPos = size -1, maxArea = 0, currArea;

    while(startPos < endPos){
        int width = endPos - startPos;
        if(height[startPos] < height[endPos]){
            currArea = height[startPos] * width;
        }
        else if(height[startPos] > height[endPos]){
            currArea = height[endPos] * width;
        }

         if (currArea > maxArea) {
            maxArea = currArea;
        }

        if (height[startPos] < height[endPos]) {
            startPos++;
        } else {
            endPos--;
        }
    }

    cout << "Area: " << maxArea;
}