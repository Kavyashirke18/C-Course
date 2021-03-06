#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
  
bool isInside(int circle_x, int circle_y, 
                   int rad, int x, int y) 
{ 
    // Compare radius of circle with distance  
    // of its center from given point 
    if ((x - circle_x) * (x - circle_x) + 
        (y - circle_y) * (y - circle_y) <= rad * rad) 
        return true; 
    else
        return false; 
} 
  
int main() 
{ 
    int x = 1, y = 1; 
    int circle_x = 0, circle_y = 1, rad = 2; 
    isInside(circle_x, circle_y, rad, x, y) ?  
    cout << "Inside" : cout << "Outside"; 
} 
