/* Irfan Ahmad, 11-06-2018
This program opens an existing file that contains people's names as well as
their height.  The function of this program is to calculate the ideal weight
for each person based on their height.  This program is not restricted to
only the names on the text file, more people can be added and it will
calculate it for them too. */


#include <iostream>
#include <fstream> // File stream library in order to use ifstream or ofstream

using namespace std;

int main()
{
    string firstName, lastName; //A persons full name will be outputted
    int heightInFeet, heightInInches, additionalInches, weight;
    /* Additional inches accounts for any height taller than 5 feet.
    This variable will be useful for heights above 6 feet. */
    ifstream inFile;
    inFile.open ("names-1.txt");
    // The file already exists so ifstream is used

    /* The text file provides information in the order of
    first name, last name, feet, and then inches.
    The while loop must use that exact order of reading so it can come back
    after the first person and calculate the weight for everyone else. */
    while ( inFile >> firstName )
    {
        inFile >> lastName >> heightInFeet >> heightInInches;

        if ( heightInFeet == 5 )
        /* If the height is 5 feet then the additional inches equals
        heightInInches. Multiply that value by 5 to calculate
        the extra weight. */
        {
        int weight = 110 + ( heightInInches * 5 );
            cout << "The ideal body weight for ";
            cout << firstName << " " << lastName;
            cout << " is " << weight << " pounds.\n";
        }

            else if ( heightInFeet > 5 )
        /* If the height is greater than 5 feet then the additional
        inches is 12 inches times the amount of feet between the height and 5.
        Subtracting 5 from height finds this. */
        {
            additionalInches = 12 * ( heightInFeet - 5 ) + heightInInches;
        int weight = 110 + ( additionalInches * 5 );
            cout << "The ideal body weight for ";
            cout << firstName << " " << lastName;
            cout << " is " << weight << " pounds.\n";
        }
                else
        {
            cout << "I cannot calculate a body weight for ";
            cout << firstName << " ";
            cout << lastName << ".\n";
        }
/* If someone is not larger than 6 feet or equal to 5 feet,
he/she is shorter than 5 feet and the formula can't calculate their weight. */



    }

    inFile.close (); // Closes file after opening it.
    return 0;
}
