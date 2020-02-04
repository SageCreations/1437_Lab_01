/* Edward Cruz 
 * 01/22/2020
 * 
 * Lab_01
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

void make_Magic_Square(int a[3][3])
{
    int length = 3;
    //resets the previous 3x3 array.
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            a[i][j] = 0;
        }
    }
    //logic for adding in a random number in the array.
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            a[i][j] = std::rand() % 9 + 1;
        }
    } 
}

bool determine_if_Magic_Square(int a[3][3])
{
    int length = 3;
    int sum = 0;
    //loop that goes through the 3x3 array and adds each element to sum.
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
           sum += a[i][j];
        }
    }
    //divides sum by 3 and if equal to 15 is true otherwise false.
    return ((sum / 3) == 15) ? true : false;
}

int main()
{
    //Initializations and Declarations
    int magSq[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int counter = 0;
    int numOfChecks = 1000000;
    std::srand (std::time(0));
    //the loop for how many sqaures to check and counter of magic square confirmations
    for (int i = 0; i < numOfChecks; i++)
    {
        make_Magic_Square(magSq);
        if (determine_if_Magic_Square(magSq))
        {
            counter++;
        }
    }
    //console output
    std::cout << "\n\nThe number of Magic Squares is " << counter << ".\n" 
              << "The number of trials that were conducted are " 
              << numOfChecks << ".\n\n";

    return 0;
}