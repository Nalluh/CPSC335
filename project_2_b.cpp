#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> findKeywords(string findWords, vector<string>  key)
{
    vector<string> answer;
    string temp, final;
    int counter =0, index;
    
    for(int i = 0; i < findWords.length(); i++)
    {
        for(int j = 0; j < key.size(); j++)
        {
            temp = key[j]; // temp stores city options
            if(temp[0] == findWords[i]) // check if first letter of city option matches char in long string
            {
                counter = i; // get index #
                for(int k =0; k < temp.length(); k++)
                {
                    if(temp[k] == findWords[counter])// if subsequent chars are equal to each other
                    {                                // add to final
                        final +=findWords[counter];
                        counter++;
                        if(temp == final) // when final is completely populated means we found word
                        {
                            answer.push_back(final);   // add word to array
                          answer.push_back(to_string(i));   // add index where it was found 
                            i = counter -1 ; // set i to new index number so we dont read over twice
                                             }
                        }
                    else
                    {
                        final = ""; // if a char stops matching the word reset final for next entry
                    }
                }
        
                
            }
        }
            final =""; // reset final so we can put in next word 
            
    }
    return answer;
}
int main(){
ifstream input_file;
string readInput,tempInput, findWord;
int singleQuoteTracker = 1;
bool inQuote = false;
vector<string> findCityArray, cityOptionsArray, final; 

input_file.open("in2a.txt"); 

if (!input_file.is_open()) {

    cout << "Failed to open the file. \n";
    

}

while (input_file >> readInput) {
if(readInput[1] == '"') // input equals " means start of string
{                       // getLine returns [] and " "
    for(int i = 2; i <readInput.length()-2;i++) // return the string excluding [] and ""
    {
        tempInput+= readInput[i];
    }
                        // when mod != 0 we update the flag and add option to array and reset temp

   findWord =tempInput; // adds line of words to vector
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
    else{             
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
// code above reads in from the file and propely places them into vectors 


final = findKeywords(findWord, cityOptionsArray);
for(int i =0; i <=final.size(); i ++)
{
    cout << final[i] << " " ;
}
input_file.close();
}