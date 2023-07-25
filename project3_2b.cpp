#include <iostream>
#include <cmath>
using namespace std;

int verifyInput()
{
    string user;
    bool checkNum = true, isFloat = true;
    int inpt;
    while (checkNum) {
        cout << "Enter a positive integer :";
        cin >> user;
        for (int i = 0; i < user.length(); i++)
        {

            if (user[i] == '.' || !isdigit(user[i])) // if input has . or a letter ask for another input
            {
                isFloat = true;
                break;

             }
            else {
                isFloat = false; // input does not have . or letter move on 
            }


        }
        if (!isFloat)
        {   
            
            inpt = stoi(user); // convert string to int
                checkNum = false; // stop the while loop
               return inpt; //return num 
            }
        else{
            cout << "Incorrect input \n";
        }
            
        }
}

int equation3(int n){
    if(n <=1)
    {
        return n;
    }

   return  (pow(1+sqrt(5),n)-pow(1-sqrt(5),n))/(pow(2,n) * sqrt(5));
}
int equation4(int fp, int p, int n)
{
    return fp* (pow(1.61803,n-p));
}
int equation5(int fn)
{
    return fn*1.61803;
}

int main() {
int user, nEquation4;
user = verifyInput();
cout << "enter n:";
cin >> nEquation4;

cout<< "Equation 4: " << equation4(equation3(user),user, nEquation4) << "\n";
cout << "Equation 5: " <<equation5(equation3(user));


//Code above is for usage of equation4 and equation5


//This code is for printing the first 20 terms using equation 4 and equation 5 
/*
cout << "Equation 4    Equation 5\n";

for(int i = 0; i < 20; i++)
{
    cout << i << ":" << " " << equation4(equation3(i),i,i-1) << "                 " << equation5(equation3(i))<< "\n";

}
*/



//This code was used for confirming the maxim
/*
cout << equation5(equation3(3))/ equation5(equation3(2)) << " ";
cout << equation5(equation3(30))/ equation5(equation3(29));
*/
}