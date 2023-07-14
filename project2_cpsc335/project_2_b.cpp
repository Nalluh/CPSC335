#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(){

ifstream input_file;
string readInput,tempInput, tempTest, cityOptions[4], final ="";
int singleQuoteTracker = 1, index =0, secondIndex =0;
bool inQuote = false, updateCity = true, test = false;
char firstLetter;
vector<string> findCityArray, cityOptionsArray, foundCity;
vector<int> output_array;

input_file.open("in2a.txt"); 

if (!input_file.is_open()) {

    cout << "Failed to open the file. \n";
    return 1;

}

while (input_file >> readInput) {
if(readInput[1] == '"') // input equals " means start of string
{                       // getLine returns [] and " "
    for(int i = 2; i <readInput.length()-2;i++) // return the string excluding [] and ""
    {
        tempInput+= readInput[i];
    }
   findCityArray.push_back(tempInput); // adds line of words to vector
    tempInput = ""; // resets variable for new input 
}

// above code reads in string that we will look at

// code below will read in cities we are looking for
for(int i = 0; i <readInput.length()-1;i++){
   
if (readInput[i] == '\''){
    singleQuoteTracker++;           // mod == 0 means we are at first single quote 
    if(singleQuoteTracker % 2 ==0){ // when we reach second single quote we will increment
        inQuote = true;             // and mod will != 0 meaning we are done reading in the option
    }                               
    else{                           // when mod != 0 we update the flag and add option to array and reset temp
        cityOptionsArray.push_back(tempInput);
       inQuote = false;
       tempInput = "";
    }

    }
     if(inQuote) // when we reach the first quote start reading in chars
    {
        if (readInput[i] != '\'') // add char to temp when its a single quote
        {
        tempInput +=readInput[i];
        }
    }

}
}


// b m c f o i m
    
for(int i = 0; i < tempInput.length()-1; i++)
{    
    if(updateCity){
    tempInput = findCityArray[index];
    }
    updateCity = false;
    

if (tempInput[i] == 'b' || tempInput[i] == 'm' || tempInput[i] == 'c' || tempInput[i] == 'f' || tempInput[i] == 'o' || tempInput[i] == 'i')
 {
   firstLetter = tempInput[i];
   
    //read tempinput string to see if letter match then if match
    // create tempstring that will hold option and compare char
    // if first char no match update temp string to next option
   for(int k = 0; k < 4; k++)
   {

    tempTest = cityOptionsArray[k];
    if(tempTest[0] == firstLetter)
    {
        test = true;    // test if word is valid 
      break;
     }
        }
       if(test)
       {
        secondIndex = i;
        for(int p = 0; p < tempTest.length(); p++)
        {
            if(tempTest[p] == tempInput[secondIndex]) // compare original string to words
            {
                if(tempTest[p] == 'c' && tempInput[secondIndex+1] == 'o') // clovis and corona both start with c
                {                                                         // clovis comes first when checking first chat
                    tempTest = "corona";                                  // so we check if char after c is o if so
                }                                                         // we update our test string to be corona
                final += tempTest[p];   //adding chars together
                secondIndex++; //variable used to update i
            }
            else{
                break; // if chars dont match stop comparing break out  
            }
        }
        if(final == tempTest) // if final string matches city in our array
        {                     // city has been found 
            foundCity.push_back(final);     // adds city name to vector
            output_array.push_back(i);      // adds index # to array 
            final ="";                      // resets final for next word 
        }
        else{
            final =""; // if chars dont match reset final to keep looking 
        }
       }
    
    

   }
}

for(int i =0; i < output_array.size(); i++){
 cout << output_array[i] << " " ;
}
cout << "\n";
for(int i =0; i < output_array.size()*2; i++){
  cout<< foundCity[i] << " ";
}
input_file.close();


}