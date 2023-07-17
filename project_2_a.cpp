#include <iostream>
#include <vector>


using namespace std;

struct node{
string data;
node *next; 
};

node* head = NULL;

void push(char n)
{
node* temp = new node;
temp->data = n;
temp->next = head;
head = temp;
}





bool isPalindrome(node* head)
{
    vector<string> test; 
    string checkLL;
    node* temp = head;
    int counter;

    while(temp != NULL)
    {
        // iterate through temp LL and add elements to vector
        test.push_back(temp->data);
        temp = temp->next;
    }

    counter = test.size();
    while(head != NULL)
    {
       // if LL = water
       // head will iterate r -> e -> t -> a -> w
       // by checking vector[size-1] it will iterate w -> a -> t -> e -> r
       // we then compare head to vector[size-1]
       //if they match go to next node
       // else return false 
        if(head->data != test[counter-1]) 
        {
            return false;
        }
        counter--;
        head = head->next; 

    }
    return true;
}

int main(){
string test ="a"; // "456514" "02455410", "23788732"
for(int i = 0; i < test.length(); i++)
{
    push(test[i]); // populate LL 
}
cout << "Is " << test << " a Palindrome?: " << isPalindrome(head) << "\n";

}