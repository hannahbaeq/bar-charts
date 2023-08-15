/******************************************************
 ** Name: Hannah Baeq
 ** Date: 4/25/23
 ** Section: 24
 ** Email: hbaeq1@umbc.edu
 ** Desc: This file contains the function definitions
 **       of the Bar.h file.
 *****************************************************/
//including the header file
#include "Bar.h"

// Name: Bar (Default Constructor) (not used)
// Preconditions: Input file has correctly formatted input
// Postconditions: Returns list of items and their frequency (stored in LL)
Bar::Bar(){
  //default file name
  m_fileName = "test.txt";
  //dynamically allocating m_data for strings
  m_data = new LL<string>();
}

// Name: Bar (Overloaded Constructor)
// Preconditions: Input file
// Postconditions: m_data is allocated, m_fileName populated
Bar::Bar(string filename){
  //passes filename for m_fileName
  m_fileName = filename;
  //dynamically allocating m_data for strings
  m_data = new LL<string>();
}

// Name: ~Bar (Destructor)
// Preconditions: m_data has been dynamically allocated
// Postconditions: m_data is empty
Bar::~Bar(){
  //deallocating m_data
  delete m_data;
}

// Name: Start
// Preconditions: None (filename is available)
// Postconditions: None
void Bar::Start(){
  //Calling all the functions
  LoadFile();
  RemoveCommon();
  RemoveSingles();
  SortData();
  DisplayBars();
  Export();
}

// Name: LoadFile()
// Preconditions: m_fileName is populated with good data
// Postconditions: m_data is populated
void Bar::LoadFile(){
  ifstream inputStream;
  inputStream.open(m_fileName);
  //opening the file
  //initializing variables
  string word;
  int count = 0;
  //if file is open
  if(inputStream.is_open()){
    //while data is being grabbed
    //only grabs till the next space since no getline
    while(inputStream >> word){
      //increase count of words
      count++;
      //remove the punctuation
      RemovePunct(word);
      //add the word into a linked list
      m_data->Insert(word);
    }
    //tell user how many words loaded
    cout << count << " loaded" << endl;
  }else{
    cout << "File could not be opened." << endl;
  }
  inputStream.close();
}

// Name: RemovePunct (passed a string)
// Preconditions: Strings to be evaluated
// Postconditions: Punctuation is removed from string
void Bar::RemovePunct(string& word){
  //initializing variables
  int wordLength = int(word.length());
  //if first
  if(ispunct(word[0])){
    word.erase(0, 1);
  }
  //if last
  if(ispunct(word[wordLength-1])){
    word.pop_back();
  }
  //make everything lower
  int count = 0;
  for(string::iterator it = word.begin(); it != word.end(); ++it){
    word[count] = tolower(word[count]);
    count++;
  }
}

// Name: RemoveCommon
// Preconditions: m_data is populated and EXCLUDE_LIST is populated
// Postconditions: m_data will have no words from EXCLUDE_LIST
void Bar::RemoveCommon(){
  string answer;
  //asking the user if they want to remove
  cout << "Would you like to remove all common words (Only use with essays)?" << endl;
  cin >> answer;
  //validation
  while(answer != "YES" && answer != "Y" && answer != "y" && answer != "yes" && answer != "NO" && answer != "N" && answer \
!= "n" && answer != "no"){
    cout << "Would you like to remove all common words (Only use with essays)?" << endl;
    cin >> answer;
  }
  //cane take four types of yes answers
  if(answer == "YES" || answer == "Y" || answer == "y" || answer == "yes"){
    int j = 0;
    //using an iterator
    for(vector<string>::const_iterator it = EXCLUDE_LIST.begin(); it != EXCLUDE_LIST.end(); ++it){
      //if its not nullptr that means the node was returned back and it exists
      if(m_data->Find(EXCLUDE_LIST[j]) != nullptr){
        //remove the word
        m_data->RemoveAt(EXCLUDE_LIST[j]);
      }
      //iterate the index
      j++;
    }
    //telling user
    cout << "All common words removed." << endl;
  }
}

// Name: RemoveSingles
// Preconditions: m_data is populated
// Postconditions: m_data will have no words with a frequency of 1
void Bar::RemoveSingles(){
  string answer;
  //asking user
  cout << "Would you like to remove all words with the frequency of 1?" << endl;
  cin >> answer;
  //validation
  while(answer != "YES" && answer != "Y" && answer != "y" && answer != "yes" && answer != "NO" && answer != "N" && a\
nswer != "n" && answer != "no"){
    cout << "Would you like to remove all words with the frequency of 1?" << endl;
    cin >> answer;
  }
  //if its one of the yes
  if(answer == "YES" || answer == "Y" || answer == "y" || answer == "yes"){
    //initializing variables
    int count = 0;
    int size = m_data->GetSize();
    for(int i = 0; i < size; i++){
      //if the freq is 1
      if((*m_data)[i].second == 1){
        //remove the node
        m_data->RemoveAt((*m_data)[i].first);
        //remove count increments
        count++;
        //index and size of iteration decrement
        //since we removed the data, we need to
        //redo the same index
        i--;
        size--;
      }
    }
    //telling user
    cout << count << " words removed." << endl;
  }
}

// Name: SortData
// Preconditions: m_data is populated
// Postconditions: m_dataSorted is populated and sorted based on frequency
void Bar::SortData(){
  //for every single node
  for(int i = 0; i < m_data->GetSize(); i++){
    //add the data to multimap in flipped order
    m_dataSorted.insert(make_pair((*m_data)[i].second, (*m_data)[i].first));
  }
}

// Name: DisplayBars
// Preconditions:  m_dataSorted is populated
// Postconditions: Bar charts are displayed
void Bar::DisplayBars(){
  int num;
  //iterating using iterator
  for(multimap<int, string>::reverse_iterator it = m_dataSorted.rbegin(); it != m_dataSorted.rend(); it++){
    //setw to make it pretty
    cout << setw(20);
    //cout the word:
    cout << it->second << ": ";
    num = it->first;
    //for each iteration until the number
    for(int i = 0; i < num; i++){
      //print the barChar
      cout << barChar;
    }
    //end the line after barChars are done
    cout << endl;
  }
}

// Name: Export
// Preconditions: m_dataSorted is populated
// Postconditions: New export file is created and populated with a formatted bar chart
void Bar::Export(){
  //initializing variable
  string fileName;
  //asing user for a name
  cout << "What would you like to call the export file?" << endl;
  cin >> fileName;
  //grabing name and creating an ofstream using the name
  ofstream outFile(fileName);
  int num;
  //same thing as display bars but instead of cout, it goes out to the outFile
  for(multimap<int, string>::reverse_iterator it = m_dataSorted.rbegin(); it != m_dataSorted.rend(); it++){
    outFile << setw(20);
    outFile << it->second << ": ";
    num = it->first;
    for(int i = 0; i < num; i++){
      outFile << barChar;
    }
    outFile << endl;
  }
  //always close it after youre done!!
  outFile.close();
}
