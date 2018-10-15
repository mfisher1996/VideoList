#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class VideoList{
private:
    struct node{
        int copies;
        string name;
        string descripton;
        node * right;
        node * left;
    };
    int len;
    node * cur;
    node * first;
    node * last;
    node * find(string i){
		cur = first;
		while(cur!=NULL){
			if(cur->name==i)
				return cur;
			else 
				cur=cur->right;
			}
			return nullptr;
		};
public:
    // VideoList constructor
    // Initializes first and last to be pointing at nulls and custCount and len to 0
    VideoList(){first = nullptr;last= nullptr; len=0;};
    
    // VideoList destructor
    // Deletes each member of the linked list.
    ~VideoList();
    
    // insert(int)
    // inserts an int into the linked list.
    void insert(string insertItem);
    
    // remove (int)
    // deletes the first element of the linked list that is the same as insertItem
    void remove(string deleteItem);
    
    // print()
    // Outputs the movies that are in the list.
    void print(); 
    
    // size()
    // an accessor for the len private member. returns the number of elements in the list.
    int size(){return len;};
    
    // search(int)
    // returns true if the int passed is in the list.
    bool search(string searchItem);
    
    // printCust()
    // outputs each customer in the customer vector
    void printCust();
    
    // describe(string, string)
    // a modifier for node.description. assignes des to find(movie)->description.
    void describe(string movie, string des){find(movie)->descripton=des;};
    
    // getDescrib(int)
    // An accessor of the private describe array. returns a description of a movie when passed 0-4.
    string getDescrib(string i){return find(i)->descripton;};
    
    // returnMovie(int)
    // a modifier for the list. Inserts it into the linked list and sends the appropriate message to cout.
    void returnMovie(string returnItem){cout << "You returned "<< returnItem << " to the Video Store.\n";insert(returnItem);};
    
    
    // incCount(string)
    // a modifier for the copies int in a node with the name 'movie'. increment copies.
    void incCount(string movie){cur=find(movie); if(cur==NULL){cout << movie <<" was not found in the list.\n";return;}cur->copies++;};
    
    // decCount(string)
    // a modifier for the copies int in a node with the name 'movie'. deincrements copies.
    void decCount(string movie){cur=find(movie); if(cur==NULL){cout << movie <<" was not found in the list.\n";return;}if(cur->copies>0)cur->copies--;else cout << "There are no copies to rent\n";};
    
    // printInStore()
    // an accessor for the movies nodes in videoList. prints the name if copies is greater than 0.
    void printInStore(){cur = first;while(cur!=NULL){if(cur->copies>0)cout << "Copies: " << cur->copies << "\tMovie: " << cur->name << endl;cur=cur->right;}};
};

void VideoList::insert(string insertItem){
    node * nNode;
    nNode= new node;
    nNode->name = insertItem;
    nNode->right = nullptr;
    nNode->left = nullptr;
    nNode->copies = 0;
    if(find(insertItem)!=NULL){
		find(insertItem)->copies++;
		delete nNode;
	}else{
		if(first==NULL){ // if list is empty
			first = nNode;
			last = nNode;
			len++;
		}
		else{ // any other insert
			last->right= nNode;
			nNode->left = last;
			last = nNode;
			len++;
		}
	}//sort();
}

bool VideoList::search(string searchItem){
    cur = first;
    while(cur->right != NULL){
        if(cur-> name == searchItem)
            return true;
        cur=cur->right;
    }
    return false;
}

void VideoList::remove(string deleteItem){
    node * trail;
    bool found;
    if (first == NULL)
        cout << "Cannot remove from an empty list.\n";
    else if (first->name == deleteItem){
        cur=first;
        first = first->right;
        if(first!=NULL)
            first->left = nullptr;
        else
            last= nullptr;
        len--;
        delete cur;
        
    }else{
        found = false;
        cur = first;
        while (cur!=NULL && !found)
            if (cur->name>=deleteItem)
                found = true;
            else
                cur = cur->right;
        if(cur==NULL)
            cout << "The item to be deleted is not in the list.\n";
        else if (cur->name == deleteItem){
            trail = cur->left;
            trail->right = cur->right;
            if(cur->right != NULL)
                cur->right->left = trail;
            if(cur==last)
                last = trail;
            len--;
            delete cur;
        }else
            cout << "The item to be deleted is not in the list.\n";
        
    }
}// end remove




void VideoList::print(){
    cur = first;
    while(cur->right != NULL){
        cout << cur->name << ", ";
        cur=cur->right;
    }// end while
    cout << cur->name << endl;
}// end print
/*
void VideoList::sort(){
    node * sort;
    cur=first;
    while(cur!=last){
        if(cur->info <= cur->right->info)
            cur=cur->right;
        else if(cur->info > cur->right->info){
            if(cur->right!=last){
                sort=cur->right;
                cur = cur-> left;
                while(cur->info > sort->info)
                    cur = cur->left;
                sort->left = cur;
                sort->right = cur->right;
                cur -> right = sort;
                sort->right->left= sort;
                cur= cur->right;
                last->right=nullptr;
            }else{
                last=cur;
                sort=cur->right;
                cur = cur-> left;
                while(cur->info > sort->info)
                    cur = cur->left;
                sort->left = cur;
                sort->right = cur->right;
                cur -> right = sort;
                sort->right->left= sort;
                cur= cur->right;
                last->right=nullptr;
            }
        }else{
            cout << 4<<endl;
            cur=cur->right;
        }
        
    }
}
*/
VideoList::~VideoList(){
    while(first!= NULL)
        remove(last->name);
    
}


#include <fstream>




class Validation{
public:
    /**
     Author: MASON FISHER
     
     Validation constructor
     
     Perameters: none
     
     */
    Validation();
    /**
     Author: MASON FISHER
     
     Validation destructor
     
     Perameters: none
     
     
     */
    ~Validation();
    /**
     Author: MASON FISHER
     
     Validation yOn()
     
     Yes or no input validation.
     Returns true if user types Y or Yes and false if user inputs N or no
     
     Perameters: none
     
     Returns: true if 'Y' is input and false if 'N' is input
     
     */
    bool yOn();
    
    /**
     Author: MASON FISHER
     
     Validation numb(int)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
        -int num
     
     Returns: an integer from input
     
     */
    int numb(int);
    /**
     Author: MASON FISHER
     
     Validation numb(int, int, int)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
        -int num
        -int high
        -int low
    
     Returns: an integer below high and above low
     
     */
    int numb(int, int, int);
    /**
     Author: MASON FISHER
     
     Validation numb(double)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
        -double num
     
     Returns: a double
     
     */
    double numb(double);
    /**
     Author: MASON FISHER
     
     Validation numb(double, double, double)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
        -double num     // Number to be validated. Also passed to disabiguate function call.
        -double high    // Number that should not be exceded by num
        -double low     // Number that should not exced num
     
     Returns: a double below high and above low
     
     */
    double numb(double, int, int);
    /**
     Author: MASON FISHER
     
     Validation numb(float)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
        -float num
     
     Returns: a float
     
     */
    float numb(float);
    /**
     Author: MASON FISHER
     
     Validation numb(float, float, float)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
        -float num      // Number to be validated. Also passed to disabiguate function call.
        -float high     // Number that should not be exceded by num
        -float low      // Number that should not exced num
     
    Returns: a float below high and above low
     
     */
    float numb(float, int, int);
    /**
     Author: MASON FISHER
     
     Validation word()
     
     Discribtion:
     gets a line from input and asks the user if that is what they meant to type.
     
     Perameters: none
     
     Returns: a string that the user confirms
     */
    std::string word();
    /**
     Author: MASON FISHER
     
     Validation clear()
     
     Description:
     clears the input buffer. Used in input functions invloving numbers or anything not including strings.
     
     Perameters: none
     
     
     */
    void clear(){std::cin.clear(); std::cin.ignore(40,'\n');};
    void open(std::fstream *, std::string);
    void out();
    std::string get_s(std::fstream *);
    
};

/**
 Validation constructor
 -parameters: none
 */
Validation :: Validation()
{
}

/**
 Validation destructor
 -perameters: none
 */
Validation :: ~Validation()
{

}

/**
 MASON FISHER
 Validation yOn()
 Yes or no input validation.
 Returns true if user types Y or Yes and false if user inputs N or no
 -perameters: none
 */
bool Validation :: yOn()
{

    std::string str ="";
    out();
    do
    {
        std::cout << "Enter 'Y' for yes or 'N' for No: ";
        std::cin >> str;
        clear();
        if(toupper(str[0]) == 'Y')
            return true;
        else if(toupper(str[0]) == 'N')
            return false;
        else
        {
            out();
            std::cout << "Invalid input, Please ";
        }

    }
    while((toupper(str[0]) != 'N'&&(toupper(str[0]) != 'Y')));
    return false;
}

/**
 Validation numb(int)
 integer validation.
 Returns true if user types an integer and returns false if the user does not
 -perameters: int
 */
int Validation :: numb(int num)
{
    clear();
    std::cin >> num;

    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(int,int,int)
 ranged integer validation.
 Returns true if user types an integer equal to or between the low high variables
 returns false if int value is below the low value or above the high value
 -perameters: int, min int, max int
 */
int Validation :: numb(int num, int low, int high)
{
    std::cin >> num;

    while(!num||!(num<=high&&num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(double)
 double validation.
 Returns true if user types a double value and returns false if the user does not
 -perameters: double
 */
double Validation :: numb(double num)
{
    clear();
    std::cin >> num;

    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(double,int,int)
 ranged double validation.
 Returns true if user types an double that is equal to or between the low and high values
 returns false if double is below low value or above high value
 -perameters: double,min int,max int
 */
double Validation :: numb(double num, int low, int high)
{
    std::cin >> num;

    while(!num||!(num<=high||num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(float)
 float validation.
 Returns true if user types a float value and returns false if the user does not
 -perameters: float
 */
float Validation :: numb(float num)
{
    std::cin >> num;

    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(float,int,int)
 ranged float validation.
 Returns true if user types a float that is equal to or between the low and high values
 returns false if float is below low value or above high value
 -perameters: float,min int,max int
 */
float Validation :: numb(float num, int low, int high)
{
    std::cin >> num;

    while(!num||!(num<=high||num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation word()
 string validation.
 takes in string value
 -perameters: ~none~
 */
std::string Validation :: word()
{
    std::string strW = "";
    do{
	out();
    getline(std::cin, strW,'\n');
    out();
    std::cout << "You typed " << strW << ". Is this what you meant?\n";
    if(yOn())
        return strW;
    else
        strW = "";
    out();
    std::cout << "Please re-type your input: ";
    }while(strW == "");
    return strW;
}

/**
 Validation out()
 indents
 -perameters: ~none~
 */
void Validation::out()
{
    std::string INDENT = "          ";
    for(int i=0;i<2;i++)
        std::cout << INDENT;
}

void Validation::open(std::fstream * file, std::string name){

	file->open(name.c_str());
	while(!file->is_open()){
		out();
		std::cout << "The file could not be found with the name: " << name << ". \n";
		out();
		std::cout << "Please input a new name to check or type -99 to cancel: ";
		name = word();
		if(name == "-99")
			break;
		file->open(name.c_str());
	}
	if(name != "-99")
	{
		out();
		std::cout << "The file " << name << " was succesfully opened.\n";
	}
	
	
}


std::string Validation::get_s(std::fstream * in){
	char output[100];
	in -> getline(output, 100);
	if(strlen(output)>0)
		return output;
	else get_s(in);
	return output;
}
