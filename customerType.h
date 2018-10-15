#ifndef CUSTOMERTYPE_H
#define CUSTOMERTYPE_H

#include "PersonType.h"
#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

//Used in the function 'generateAccountNumber() to create a unique accountNumber for each customer.
//This value is static, meaning that there won't be an instance of it in every object.
//If you change this value, it's changed for all objects of this class until the program ends, which is a good thing.
string uniqueAccount = {'0','0','0','\0'};

class customerType : public personType
{
    public:
        //default constructor
        customerType();

        //Overloaded constructor
        customerType(string first, string last);

        //Overloaded constructor
        customerType(string first, string last, string video);


        //Function to add a video to the rentedVideos vector for a customer.
        void rentVideo(const string& video);

        //Function to remove specified video from the rentedVideos vector for a customer.
        void returnVideo(const string& video);

        //Function to search for a video within the customer's rented video list.
        bool searchVideo(const string& video);

        //Function to return accountNumber;
        string showAcccountNumber() const;

        //Function to print the customer's first name, last name, account number
        //and list of rented videos.
        void printInfo() const;

        //Destructor
        ~customerType();


    private:

        //This function generates a unique account number
        //as a string. Then this function
        //places it in accountNumber within the customerType instance.
        void generateAccountNumber();

        string accountNumber;   //Customer's account number.
        vector<string> rentedVideos;    //The list of rented videos.
        int rentedVideosCounter;      //The number of videos currently being rented.

};

//This constructor does not assign a name. If you use this, you must also call setName() function from personType class.
customerType::customerType()
    : personType()
{
    generateAccountNumber();    //Gives the new customer a unique accountNumber. This is an attribute in the class.
    rentedVideos.resize(0);     //List of rented movies has nothing in it yet.
    rentedVideosCounter = 0;    //The number of movies this customer has rented = 0.
}

//This constructor accepts a first and last name as parameters.
customerType::customerType(string first, string last)
    : personType(first, last)
{
    generateAccountNumber();
    rentedVideos.resize(0);
    rentedVideosCounter = 0;
}

//This constructor accepts first name, last name, and one rented video.
customerType::customerType(string first, string last, string video)
    : personType(first, last)
{
    generateAccountNumber();
    rentedVideos.push_back(video);
    rentedVideosCounter = 1;
}

//This function is used when a customer rents a video.
void customerType::rentVideo(const string& video)
{
    rentedVideos.push_back(video);  //The rented video goes in the rented Videos list for the customer.
    rentedVideosCounter++;  //The number of movies the customer rented is incremented.
}

void customerType::returnVideo(const string& video)
{
    bool videoRemoved = false;

    if(searchVideo(video) == false) //If the video to be returned is not found in the customer's list.
    {
        cout<< "\n\nSorry, " << firstName << " " << lastName << "Does Not Have The Video In Question." << endl << endl;
    }
    else    //If the video to be returned is in the customer's list.
    {
        for(int i = 0; i < rentedVideosCounter; i++)
        {
            if(rentedVideos[i] == video)    //Find where the video is stored.
            {
                rentedVideos.erase(rentedVideos.begin()+i); //Delete it from the list.
                rentedVideosCounter--;  //Decrement the number of videos the customer has rented.
                videoRemoved = true;
            }
            //This is to ensure that if, for some reason, the customer has rented the same movie twice,
            //Only one instance of said movie is erased, or returned, from the list.
            if(videoRemoved == true)
            {
                return;
            }
        }
    }
}

bool customerType::searchVideo(const string& video)
{
    for(int i = 0; i < rentedVideosCounter; i++) //Searches for the video in the customer's rented movies list
    {
        if(rentedVideos[i] == video)
        {
            return true;
        }
    }

    return false;
}

void customerType::printInfo() const    //Prints customer name, account #, and videos rented.
{
    cout<< "-------------------------------------------------------" << endl;
    cout<< "Name         : " << firstName << " " << lastName << endl;
    cout<< "Account#     : " << accountNumber << endl;
    cout<< "Rented Videos: ";
    if(rentedVideosCounter == 0)    //If no videos have been rented.
    {
        cout<< "NO RENTED VIDEOS" << endl;
    }
    else    //If at least one video has been rented/
    {
        for(int i = 0; i < rentedVideosCounter; i++)
        {
            cout<< rentedVideos[i];
            if(i != rentedVideosCounter -1)
            {
                cout << ", ";
            }
            else    //This is to make sure a comma is not placed after the last movie in the rented list.
            {
                cout<< " " << endl;
            }
        }
    }

    cout<< "-------------------------------------------------------" << endl;
}

string customerType::showAcccountNumber() const
{
    return accountNumber;
}


void customerType::generateAccountNumber()
{

    //Since mathematical operations don't apply to account numbers,
    //I felt as though it should be a string. If this becomes
    //problematic, we can just change accountNumber to integer.
    if(uniqueAccount[2] < '9')  //If the last used account number looks like this: "008"
    {
        uniqueAccount[2] = char(int(uniqueAccount[2] + 1)); //Turn the '8' in the 2nd element to its ASCII value, add 1,
                                                            //then turn that value back into its character equivalent,
                                                            //and assign to element 2.
    }
    else if(uniqueAccount[2] == '9' && uniqueAccount[1] < '9')//If the last used account number looks like this: "089"
    {
        uniqueAccount[1] = char(int(uniqueAccount[1] + 1)); //Turn the '8' in the 1st element to its ASCII value, add 1,
                                                            //then turn that value back into its character equivalent,
                                                            //and assign to element 1.
        uniqueAccount[2] = '0';                             //element 2 should now hold '0', so the full account number
                                                            //would look like: "090"
    }
    else if(uniqueAccount[1] == '9' && uniqueAccount[0] < '9')
    {
        uniqueAccount[0] = char(int(uniqueAccount[0] + 1));
        uniqueAccount[1] = '0';
        uniqueAccount[2] = '0';
    }

    accountNumber = uniqueAccount;  //Assign this character array to accountNumber.

    if(accountNumber > "999")   //If accountNumber goes passed "999"
    {
        cout<< "Sorry, No More Unique Account Numbers Are Available." << endl;
        assert(accountNumber < "999");  //Terminate the program.

    }

}


customerType::~customerType()
{

}
#endif // CUSTOMERTYPE_H
