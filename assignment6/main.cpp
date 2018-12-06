/* Irfan Ahmad, 11-14-2018
This program will take 4 user inputted numbers as judge's scores
and calculate a final score from it.  It will remove the highest and
lowest scores and then average the values in between to find the score.*/

#include <iostream>
#include <iomanip> // So setprecision can be used.

using namespace std;
//Prototypes for calculating score and judge scores.
void getJudgeData (double &num1, double &num2, double &num3, double &num4);
void calcScore (double &num1, double &num2, double &num3, double &num4);
//Prototypes for the functions that find the highest and lowest values.
double findLowest (double &num1, double &num2, double &num3, double &num4);
double findHighest (double &num1, double &num2, double &num3, double &num4);

int main()
{
    /* All used variables except for score are declared in main along with
    referencing the other functions.  This will allow the main function to
    retrieve values already calculated from the other functions. */

    double num1, num2, num3, num4;
    // References to other functions
    getJudgeData(num1, num2, num3, num4);

    cout << "The final score is: ";
    calcScore (num1, num2, num3, num4);
    /* The calcScore function's result is a cout statement in itself,
    so there is no need to add it to the cout statement in main. It can stand
    by itself on a separate line. */
}

void getJudgeData (double &num1, double &num2, double &num3, double &num4)
{
    cout << "Enter the judge's score: ";
    cin >> num1;

    /* A while loop is used to keep prompting the user to input a score
    when the entered value is less than 0 or greater than 20.
    It will keep looping until the value is satisfactory, after that it will
    continue on to do the same for the next 3 scores.*/

    while ( num1 < 0 || num1 > 20 )
    {
        cout << "That is an invalid score. Please try again.";
        cout <<  " The score must be from 0 to 20.\n";
        cout << "Enter the judge's score: ";
        cin >> num1;
    }

    cout << "Enter the judge's score: ";
    cin >> num2;

    while ( num2 < 0 || num2 > 20 )
    {
        cout << "That is an invalid score. Please try again.";
        cout <<  " The score must be from 0 to 20.\n";
        cout << "Enter the judge's score: ";
        cin >> num2;
    }

    cout << "Enter the judge's score: ";
    cin >> num3;

    while ( num3 < 0 || num3 > 20 )
    /* Anything less than 0 or more than 20 cannot be used,
    so an or function is used in the if statement */

    {
        cout << "That is an invalid score. Please try again.";
        cout <<  " The score must be from 0 to 20.\n";
        cout << "Enter the judge's score: ";
        cin >> num3;
    }

    cout << "Enter the judge's score: ";
    cin >> num4;

    while ( num4 < 0 || num4 > 20 )
    {
        cout << "That is an invalid score. Please try again.";
        cout <<  " The score must be from 0 to 20.\n";
        cout << "Enter the judge's score: ";
        cin >> num4;
    }
}

double findLowest (double &num1, double &num2, double &num3, double &num4)
{
    if ( num1 < num2 && num1 < num3 && num1 < num4 )
        return num1;
    else if ( num2 < num1 && num2 < num3 && num2 < num4 )
        return num2;
    else if ( num3 < num1 && num3 < num2 && num3 < num4 )
        return num3;
    else if ( num4 < num1 && num4 < num2 && num4 < num3 )
        return num4;
    else
        return 0;

}

double findHighest (double &num1, double &num2, double &num3, double &num4)
{
    if ( num1 > num2 && num1 > num3 && num1 > num4 )
        return num1;
    else if ( num2 > num1 && num2 > num3 && num2 > num4 )
        return num2;
    else if ( num3 > num1 && num3 > num2 && num3 > num4 )
        return num3;
    else if ( num4 > num1 && num4 > num2 && num4 > num3 )
        return num4;
    else
        return 0;
    /* There are several other combinations of results after
    the second if else statement, so only using else cannot be
    assigned to the last conditional.  However an "else"
    is still required, so a return value of 0 is assigned to it. */

}

void calcScore(double &num1, double &num2, double &num3, double &num4)
{
    findLowest (num1, num2, num3, num4);
    findHighest (num1, num2, num3, num4);

    double score;
    /* The if statements are nested because there are sub conditions to the
    4 main conditions. */
    if (num1 == findLowest (num1, num2, num3, num4))
    {
        if (findHighest (num1, num2, num3, num4) == num2)
        score = (num3 + num4) / 2;

        else if (findHighest (num1, num2, num3, num4) == num3)
        score = (num2 + num4) / 2;

        else
        score = (num2 + num3) / 2;

    }

    if (num2 == findLowest (num1, num2, num3, num4))
    {
        if (findHighest (num1, num2, num3, num4) == num1)
        score = (num3 + num4) / 2;

        else if (findHighest (num1, num2, num3, num4) == num3)
        score = (num1 + num4) / 2;

        else
        score = (num1 + num3) / 2;

    }

    if (num3 == findLowest (num1, num2, num3, num4))
    {
        if (findHighest (num1, num2, num3, num4) == num1)
        score = (num2 + num4) / 2;

        else if (findHighest (num1, num2, num3, num4) == num2)
        score = (num1 + num4) / 2;

        else
        score = (num1 + num2) / 2;

    }
    /*Since this is a void function, return cannot be used.
    The result of this is an output statement so it can be used again
    through main. */
    cout << std::fixed << std::setprecision(1) << score;
    // Using setprecision limits the amount of spaces shown after the decimal.
}

/* Sample Run
Enter the judge's score: 5.4
Enter the judge's score: 23
That is an invalid score. Please try again. The score must be from 0 to 20.
Enter the judge's score: 17
Enter the judge's score: 6
Enter the judge's score: 11.2
The final score is: 8.6
Process returned 0 (0x0)   execution time : 13.521 s
Press any key to continue.
*/













