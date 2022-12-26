//
//  pascal.cpp
//
//  Created by Arteen Abrishami on 12/25/22.
//

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal(numRows);

    for (int i = 0 ; i < numRows ; i++){
        pascal[i] = vector<int>(i+1, 1);
        for (int j = 1 ; j < i ; j++){      // only the middle ones
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
    
    return pascal;
}

int main()
{
    int numRows = 0;
    cout << "How many rows of Pascal's Triangle would you like generated? ";
    cin >> numRows;
    cout << endl;

    /*
     need i + i - 1 spaces at bottom
     1
     3
     5
     7
     9
     */
    vector<vector<int>> pascal = generate(numRows);

    int count = numRows-1;
    for (int i = 0 ; i < numRows ; i++){
        int n = (int) pascal[i].size();
        for (int k = 0 ; k < count ; k++) cout << " ";
        for (int j = 0 ; j < n ; j++){
                cout << pascal[i][j] << " ";
        }
        cout << endl; count--;
    }
    // outputs prettily up to and including row 5

    cout << endl;
}
