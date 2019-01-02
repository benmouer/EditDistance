/*Benjamin Mouer
*222 - lab 3
*11/18/2019
*/


#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include <queue>
using namespace std;
int editDistance(char i[] , char j[], int x, int y);
int diff(char i[] , char j[], int x, int y);



int main() {

    /*This is the input of the two words*/
    string word1;
    string word2;
    cout << "intput  the first word, to test the edit distance algorithm: " << endl;
    cin >> word1;
    cout << endl;
    cout << "Input the second word: " << endl;
    cin >> word2;
    cout << endl;

    /*here i am just turning the strings into char arrays and outputting the arrays to make sure there were no errors in the conversion.*/

    int l1 = word1.length();
    char i[l1+1];
    strcpy(i, word1.c_str());

    int l2 = word2.length();
    char j[l2+1];
    strcpy(j, word2.c_str());


    for (int x=0; x<l1; x++)
        cout << i[x];

    cout << endl;

    for (int x=0; x<l2; x++)
        cout << j[x];

    /*This is needed to find the initial x and y that the algorithm works on.*/
    /*Visually, we are working from the bottom right of the matrix and working up and to the left to find our base case and then going back down to fill in the actual values of each of the cells*/
    int x = sizeof(i);
    int y = sizeof(j);



    int result = editDistance(i, j, x, y);

    cout << endl << "Edit Distance: " << result << endl;
}

/*This is the actual algorithm for editdistance, at the moment it just computed the actual distance but not the specific alignment.*/
/*I made sure to use char arrays becuase it was easier to find [i-1] or [j-1] if they were actual arryas.*/
/*x and y just represent the current letters that the algorithm is working on*/
int editDistance(char i[] , char j[], int x, int y) {

    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }



    /*I need to use two min functions because there isnt a function to find the min of three ints (or atleast, i cant find it)*/
    /*The rest of the algorithm comes directly from the book, even the diff function.*/
    return min(min(1 + editDistance(i, j, x - 1, y),
                   1 + editDistance(i, j, x, y - 1)),
               diff(i, j, x, y) + editDistance(i, j, x - 1, y - 1));
}


/*the diff function is used to determine if two letters x and y are equal, if they are then you wouldnt add anything to E([i-1][j-1]) otherwise you add 1*/
int diff(char i[] , char j[], int x, int y){
    if(i[x-1] == j[y-1]){
        return 0;
    } else {
        return 1;
    }
}

