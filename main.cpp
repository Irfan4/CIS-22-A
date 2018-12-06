/* Irfan Ahmad, 11-29-2018.
This program takes 20 inputted question choices and runs them through
the grading system, determining whether the student passed or failed,
how many incorrect and correct answers were detected, and as well as
which specific questions were incorrect. */

#include <iostream>

using namespace std;

void input (char[], int);
void checkAnswers (char[], char[], int&, int&, int);

int main()
{
    int size1 = 20;

    char submitted [20];
    char correctA [20] = {'A','D','B','B','C','B','A','B','C','D','A','C','D'
                        ,'B','D','C','C','A','D','B'};
    // Array to be passed on to input.
    input(submitted, size1);
    // Calls input to pass on values.
}

void input (char input [20], int size2)
{
    int correct = 0;
    int incorrect = 0;

    // Initializing both correct/incorrect to 0 before incrementing.

    char correctB [20] = {'A','D','B','B','C','B','A','B','C','D','A','C','D'
                        ,'B','D','C','C','A','D','B'};

    cout << "Please enter the student's answers for each of the questions.\n";
    cout << "Press ENTER after typing each answer\n";
    cout << "Please enter only A,B,C,D or a,b,c,d for each question.\n";

        for ( int i = 0; i < size2; i++)
        {
            cout << "Question " << i + 1 << ": ";
            cin >> input [i];
            input [i] = (char) toupper(input [i]);
    // toupper is used so the same letter can be accepted even when lowercase.

            cout << endl;

        while (input [i] != 'A' && input [i] != 'B' && input [i] != 'C' &&
               input [i] != 'D' && input [i] != 'a' && input [i] != 'b' &&
               input [i] != 'c' && input [i] != 'd')
            {

             cout << "Use only A,B,C,D or a,b,c,d!\n" << "Please try again.\n";
             cout << "Question " << i + 1 << ": ";

                cin >> input [i];
                input [i] = (char) toupper(input [i]);
                continue;
            }
/* Continue is used so after the input is corrected the loop will go back to
the beginning of the loop and resume the remaining questions. */

        }
        checkAnswers( input, correctB, correct, incorrect, size2);
/* checkAnswers is called to pass on the input array, element size,
answers array, and correct/incorrect variables. */
}

void checkAnswers( char given [20], char answers [20],
                  int& valid, int& invalid, int size3)
{
    valid = 0;
    invalid = 0;
/* valid and invalid are declared outside of the for loop
so that it's increments can be remembered when it exits the loop. */
    cout << "Questions that were answered wrong:\n";

    for ( int i = 0; i < size3; i++ )
    {
        if (given [i] != answers [i])
        cout << i + 1 << endl;
    }
/* Since the index starts at 0, the question number needs to be incremented
by one to be shown properly. */
    for ( int i = 0; i < size3; i++ )
    {
        if (given [i] != answers [i])
            invalid +=1;
    }
// Every time the input array is incorrect, invalid will add one to itself.

/* The minimum score to pass is 15, if invalid surpasses that the student will fail.
Invalid is subtracted from 20 to find out how many answers are correct. */
    if ( invalid > 5)
    {
        cout << "The student failed the exam.\n";
        cout << "Correct Answers: " << 20 - invalid << endl;
        cout << "Incorrect Answers: " << invalid;
    }

    else
    {
        cout << "The student passed the exam.\n";
        cout << "Correct Answers: " << 20 - invalid << endl;
        cout << "Incorrect Answers: " << invalid;
    }
}

/*
Please enter the student's answers for each of the questions.
Press ENTER after typing each answer
Please enter only A,B,C,D or a,b,c,d for each question.
Question 1: A

Question 2: C

Question 3: B

Question 4: B

Question 5: a

Question 6: d

Question 7: d

Question 8: d

Question 9: a

Question 10: b

Question 11: v

Use only A,B,C,D or a,b,c,d!
Please try again.
Question 11: a
Question 12: F

Use only A,B,C,D or a,b,c,d!
Please try again.
Question 12: d
Question 13: a

Question 14: A

Question 15: C

Question 16: B

Question 17: A

Question 18: D

Question 19: B

Question 20: C

Questions that were answered wrong:
2
5
6
7
8
9
10
12
13
14
15
16
17
18
19
20
The student failed the exam.
Correct Answers: 4
Incorrect Answers: 16
Process returned 0 (0x0)   execution time : 39.653 s
Press any key to continue.
*/
