1. Overview
  In this project, you will:
     Practice basic C++ syntax including branching structures
     Write classes and instantiate those classes using a constructor
     Create a templated data structure (linked list)
     Implement copy constructor and assignment operators
     Use simple file input
     Use overloaded operators to access templated data structure

2. Background
  When you search for something online or when you click on an advertisement in an email 
  you got, that action is tracked. This data is being aggregated and used to target marketing 
  campaigns specifically catering to your history and projected interests. Companies then 
  use data visualizations (like charts, graphs, infographics, and more) to communicate 
  important information at a glance. The action of visualizing the data is something that 
  helps us try and make sense of it.
  For this project, we are going to aggregate the data for a simple data visualization. A bar 
  chart is a simple type of data visualization that highlights important textual data points by 
  analyzing the frequency of a word. Given some text, formatted in a specific way, we should
  be able to generate a list of all words and their frequency in the text. Our tool will be able 
  to process strings, chars, or even numbers (although we will consider all of them strings).
  To help reduce the inconsequential words, we will remove all common words (such as ‘a’, 
  ‘the’, etc.) and any words with a frequency of 1.

3. Assignment Description
  Class 1 – LL – This is a very important class. The project uses a linked list to hold 
    templated pairs. The Nodes of the linked list hold a pair (T,int) meaning whatever T is and 
    always an integer. It templated so that it could store the information about whatever it is 
    designed to hold (our project will only hold strings) and a corresponding quantity. The LL 
    works like a set though – everything in the LL is sorted and whatever the “T” is will always 
    be the key. You cannot have duplicate keys in the linked list. When you insert a new node 
    into the LL, you will need to insert it in order. Therefore, the insert function is by far the 
    most complicated of the project. After a word is inserted into the linked list, if any additional
    instances of that word are found, instead of adding the word again, the quantity is 
    increased.
    You must implement the copy constructor and assignment operator in this class (even if 
    we don’t use them for this project). See the LL.cpp file for additional details for other 
    functions that you need to implement including remove. There should be absolutely NO
    references to anything about bar charts or words in this LL! 
    You should implement this class by itself and then test it completely before using it.
    There is sample test code at the bottom of LL.cpp. You can uncomment it as you 
    code functions to test it incrementally. Do not forget how we must implement templated
    classes! 
  Class 2: Bar – For this project, a Bar will read in a single file and process it. The 
    processing involves reading all words from a file and inserting them into the linked list. If a 
    word already exists in the linked list, then the quantity of that word is increased instead of 
    adding it again. All punctuation must be removed from the words except if the word 
    requires additional punctuation such as a contraction. Additionally, the user is asked if they
    would like to remove all common words. There is a list of common words (such as “the”, 
    “and”, or “us”) included in the Bar.h that needs to be removed from the bar charts (if 
    requested). Finally, the user is asked if they would like to remove all words with a 
    frequency of 1. If they respond with YES, Y, yes, or y all words with a frequency (quantity) 
    of 1 are removed from the linked list.
    Extra File: LL_test.cpp – As a large part of this project requires the linked list 
    itself(LL.cpp), there is a provided test file that you can use to test your LL as you go. After 
    you have the constructor, destructor, Insert, and Display coded, you can start to use 
    the LL_test.cpp file. You can just comment out tests 2-4 and run just test 1. This will be 
    good to make sure that the Insert function works correctly. Then as you complete 
    additional functions, you can continue to use the test to make sure that everything works 
    as expected. Even if the rest of the project does not use a function, all functions must be 
    implemented in LL.cpp. To run the test, just do “make LL_test” then run make valLL 
    which will run it with valgrind.
4. Requirements:
  This is a list of the requirements of this application. For you to earn all the points you will 
  need to meet all the defined requirements.
     You must follow the coding standard as defined in the CMSC 202 coding standards 
    (found on Blackboard under course materials). This includes comments as required.
     The project must be turned in on time by the deadline listed above.
     The project must be completed in C++. You may not use any libraries or data 
    structures that we have not learned in class. Libraries we have learned include 
    <iostream>, <fstream>, <iomanip>, <vector>, <map>, <cmath>, 
    <ctime>, <cstdlib>, <sstream>, and <string>. You should only use 
    namespace std.
     You may use toupper, tolower, or ispunct for evaluating individual characters.
    All words in the LL and the output files should be lower case.
     Using the provided files, LL.cpp, Bar.h, proj5.cpp, makefile, 
    LL_test.cpp, proj5_test1.txt, proj5_test2.txt, 
    proj5_test3.txt, and proj5_test4.txt (and a variety of sample
    runs) write the program as described. 
     As a reminder, LL.cpp is templated and all functions must exist in ONE file 
    (LL.cpp). Class uses LL to manage the pair (strings and int) but could easily be 
    modified to use practically any type of data. LL must include a functioning copy
    constructor and assignment operator. The LL must insert based on the key of the 
    pair (first). While the LL class COULD hold anything where the comparison 
    operators are overloaded, this project will really only hold strings (even when the 
    input files hold things that look like numbers or chars).
     Class member variables must be private for project 5.
     All loops for vectors or strings must use iterators.
     All user input must be validated. For example, if a menu allows for 1, 2, or 3 to be 
    entered and the user enters a 4, it will re-prompt the user. However, the user is 
    expected to always enter the correct data type. i.e. If the user is asked to enter an 
    integer, they will. If they are asked to enter a character, they will. You do not need 
    to worry about checking for correct data types.
     The code must not have memory leaks, warnings, or errors
