/******************************************************
 ** Name: Hannah Baeq
 ** Date: 4/25/23
 ** Section: 24
 ** Email: hbaeq1@umbc.edu
 ** Desc: This file contains the template T and the Linked-List class definitions.
 *****************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//DO NOT ADD ANY CONSTANTS OR FUNCTIONS TO ANY CLASS
// Templated Node class
// Normal node except that each node can hold a pair <T,int>
// where the first value is templated and the second value is the frequency
// (or quantity) of the first
// For example, if T was a string then it would hold string,int
template <class T>
class Node {
public:
  Node( const T& data ); //Node Constructor - Assume each quan
  pair<T,int>& GetData(); //Node Data Getter
  void SetData( const pair<T,int>& ); //Node Data Setter
  Node<T>* GetNext(); //Node m_next getter
  void SetNext( Node<T>* next ); //Node m_next setter
private:
  pair <T,int> m_data; //Holds templated data
  Node<T>* m_next; //Pointer to next node
};

template <class T>
Node<T>::Node( const T& data ) {
  m_data = make_pair(data,1);
  m_next = nullptr;
}

template <class T>
pair<T,int>& Node<T>::GetData() {
   return m_data;
}

template <class T>
void Node<T>::SetData( const pair<T,int>& data ) {
   m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

//Templated Linked List class
template <class T>
class LL {
 public:
  // Name: LL() (Linked List) - Default Constructor
  // Desc: Used to build a new linked list
  // Preconditions: None
  // Postconditions: Creates a new linked list where m_head points to nullptr
  LL();
  // Name: ~LL() - Destructor
  // Desc: Used to destruct a LL
  // Preconditions: There is an existing LL with at least one node
  // Postconditions: A LL is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~LL();
  // Name: LL (Copy Constructor)
  // Desc: Creates a copy of existing LL
  //       Requires a LL - REQUIRED to be implemented even if not used
  // Preconditions: Source LL exists
  // Postconditions: Copy of source LL
  LL(const LL&);
  // Name: operator= (Overloaded Assignment Operator)
  // Desc: Makes two LL of the same type have identical number of nodes and values
  // Preconditions: Requires two linked lists of the same templated type
  //                REQUIRED to be implemented even if not used
  // Postconditions: Two idenetical LL
  LL<T>& operator= (const LL&);
  // Name: Find
  // Desc: Iterates through LL and returns node if data found
  // Preconditions: LL Populated
  // Postconditions: Returns nullptr if not found OR Node pointer if found
  Node<T>* Find(const T& data);
  // Name: Insert
  // Desc: Either inserts a node to the linked list OR increments frequency of first
  //       Takes in data. If "first" (of pair) NOT in list, adds node
  //       If "first" (of pair) is already in list, increments quantity
  //       Inserts "first" in order with no duplicates
  // Preconditions: Requires a LL.
  // Postconditions: Node inserted in LL based on first value (or quantity incremented)
  void Insert(const T&);
  // Name: RemoveAt
  // Desc: Removes a node at a particular position based on data passed (matches first)
  // Preconditions: LL with at least one node.
  // Postconditions: Removes first node with passed value (in first)
  void RemoveAt(const T&);
  // Name: Display
  // Desc: Display all nodes in linked list
  // Preconditions: Outputs the LL
  // Postconditions: Displays the pair in each node of LL
  void Display();
  // Name: GetSize
  // Desc: Returns the size of the LL
  // Preconditions: Requires a LL
  // Postconditions: Returns m_size
  int GetSize();
  // Name: operator<< (Overloaded << operator)
  // Desc: Returns the ostream of the data in each node
  // Preconditions: Requires a LL
  // Postconditions: Returns an ostream with the data from each node on different line
  template <class U>
  friend ostream& operator<<(ostream& output, const LL<U>&);
  // Name: Overloaded [] operator
  // Desc: When passed an integer, returns the data at that location
  // Precondition: Existing LL
  // Postcondition: Returns pair from LL using []
  pair<T,int>& operator[] (int x);//Overloaded [] operator to pull data from LL
private:
  Node <T> *m_head; //Node pointer for the head
  int m_size; //Number of nodes in queue
};

//starter code until line 129
//*****************************************************************
// Name: LL() (Linked List) - Default Constructor
// Preconditions: None
// Postconditions: Creates a new linked list where m_head points to nullptr
template <class T>
LL<T>::LL(){
  //Default size and m_head
  m_size = 0;
  m_head = nullptr;
}

// Name: ~LL() - Destructor
// Preconditions: There is an existing LL with at least one node
// Postconditions: A LL is deallocated (including dynamically allocated nodes) to have no memory leaks!
template <class T>
LL<T>::~LL(){
  //Using curr to iterate
  Node<T> *curr = m_head;
  while(curr != nullptr){
    //"Moving" nodes in linked list by one
    m_head = curr;
    curr = curr->GetNext();
    //Deleting "current" node
    delete m_head;
  }
  //Resetting default values
  m_head = nullptr;
  m_size = 0;
}

// Name: LL (Copy Constructor)
// Preconditions: Source LL exists
// Postconditions: Copy of source LL
template <class T>
LL<T>::LL(const LL& source){
  //If size is 0, there are no nodes
  if (source.m_size == 0) {
    //Set default values
    m_head = nullptr;
    m_size = 0;
  }else{
    //If nodes exist
    //m_head is a new node with the same member variables
    //    as source.m_head
    m_head = new Node<T>(*source.m_head);
    //Setting size
    m_size = source.m_size;
    //Keeping track of two nodes, m_head and source.m_head
    Node<T>* curr = m_head;
    Node<T>* newCurr = source.m_head->GetNext();
    while (newCurr != nullptr){
      //Creating a new node with the same data as "next"
      Node<T> *newNode = new Node<T>(newCurr->GetData().first);
      newNode->SetData(newCurr->GetData());
      //Setting the "new" linked list node as the next node
      curr->SetNext(newNode);
      //Grabbing next
      curr = curr->GetNext();
      newCurr = newCurr->GetNext();
    }
  }
}

// Name: operator= (Overloaded Assignment Operator)
// Preconditions: Requires two linked lists of the same templated type
// Postconditions: Two idenetical LL
template <class T>
LL<T>& LL<T>::operator= (const LL& source){
  if(this == &source){
    //If they are the same, return
    return *this;
  }else{
    //If they are not the same, deallocate
    //   the current linked list
    Node<T> *del = m_head;
    while(del != nullptr){
      m_head = del;
      del = del->GetNext();
      delete m_head;
    }
    m_head = nullptr;
    //Setting size
    m_size = source.m_size;
    if(m_size == 0){
      //If size is 0, no nodes therefore, default
      m_head = nullptr;
    }else{
      //Same exact idea as copy constructor
      Node<T> *curr = source.m_head;
      Node<T> *newCurr = source.m_head;
      m_head = new Node<T>(*source.m_head);
      while(curr->GetNext() != nullptr){
        curr = curr->GetNext();
        Node<T> *newNode = new Node<T>(curr->GetData().first);
        newNode->SetData(curr->GetData());
        newCurr->SetNext(newNode);
        newCurr = newCurr->GetNext();
      }
    }
  }
  //Returning the copied linked list
  return *this;
}

// Name: Find
// Preconditions: LL Populated
// Postconditions: Returns nullptr if not found OR Node pointer if found
template <class T>
Node<T>* LL<T>::Find(const T& data){
  //Iterating using new node curr
  Node<T> *curr = m_head;
  while(curr != nullptr){
    if(curr->GetData().first == data){
      //If the data matches, return the node
      return curr;
    }
    //If not, keep iterating
    curr = curr->GetNext();
  }
  //If nothing matches, return nullptr
  return nullptr;
}

// Name: Insert
// Preconditions: Requires a LL.
// Postconditions: Node inserted in LL based on first value (or quantity incremented)
template <class T>
void LL<T>::Insert(const T& data){
  //If size is 0, it doesnt matter where we palce node
  if(m_size == 0){
    //Creating new node using the data
    Node<T> *node = new Node<T>(data);
    //set m_head
    m_head = node;
    m_size++;
    //size increments
  }else{
    //Check if the data exists in the linked list
    Node<T> *find = Find(data);
    if(find != nullptr){
      //If it exists, increment the frequency
      //Not incrementing size since the size of the linked
      //   list doesn't increase. Only frequency.
      find->GetData().second++;
    }else{
      //If it doesn't exist, we need to find where to place it
      Node<T> *curr = m_head;
      //Creating new node
      Node<T> *node = new Node<T>(data);
      if(data < m_head->GetData().first){
        //If the data is smaller than m_head
        node->SetNext(m_head);
        //Becomes the new m_head
        m_head = node;
      }else{
        //Now we need to keep track of two values
        Node<T> *prev = m_head;
        while(curr != nullptr){
          //If its less than current and greater than previous
          if(data < curr->GetData().first && data > prev->GetData().first){
            //Add it right between!
            prev->SetNext(node);
            node->SetNext(curr);
          }
          //If not, increment
          prev = curr;
          curr = curr->GetNext();
        }
        //If the data is bigger than the last node
        if(data > prev->GetData().first){
          //The data becomes the last node
          prev->SetNext(node);
        }
      }
      //Incrementing size since we added a whole new node
      m_size++;
    }
  }
}

// Name: RemoveAt
// Preconditions: LL with at least one node.
// Postconditions: Removes first node with passed value (in first)
template <class T>
void LL<T>::RemoveAt(const T& data){
  //We need two nodes to keep track of prev and curr
  Node<T> *prev = m_head;
  Node<T> *curr = m_head;
  while(curr != nullptr && curr->GetData().first != data){
    //Iterates until data is the same or curr == nullptr
    prev = curr;
    curr = curr->GetNext();
  }
  //If the data is the same
  if(curr->GetData().first == data){
    if(curr == m_head){
      //If removing m_head, the new m_head is the next node
      m_head = curr->GetNext();
    }else{
      //Else, the prev's next is the next of curr
      prev->SetNext(curr->GetNext());
    }
    //Decrementing size since were removing a whole node
    m_size--;
    //deallocating node
    delete curr;
  }else{
    //If the data is not the same then curr == nullptr and
    //   doesn't exist
    cout << data << " does not exist..." << endl;
  }
}

// Name: Display
// Preconditions: Outputs the LL
// Postconditions: Displays the pair in each node of LL
template <class T>
void LL<T>::Display(){
  //Iterating using curr node
  Node<T> *curr = m_head;
  while(curr != nullptr){
    //cout
    cout << curr->GetData().first << ": " << curr->GetData().second << endl;
    //Grab next values
    curr = curr->GetNext();
  }
  //Once the loop terminates, End
  cout << "END" << endl;
}

// Name: GetSize
// Preconditions: Requires a LL
// Postconditions: Returns m_size
template <class T>
int LL<T>::GetSize(){return m_size;}

// Name: operator<< (Overloaded << operator)
// Preconditions: Requires a LL
// Postconditions: Returns an ostream with the data from each node on different line
template <class U>
ostream&operator<<(ostream& output, const LL<U>& link){
  //Iterating like display
  Node<U> *curr = link.m_head;
  while(curr != nullptr){
    output << curr->GetData().first << ": " << curr->GetData().second << endl;
    curr = curr->GetNext();
  }
  //returning output
  return output;
}

// Name: Overloaded [] operator
// Precondition: Existing LL
// Postcondition: Returns pair from LL using []
template <class T>
pair<T,int>& LL<T>::operator[](int x){
  //Using curr node to iterate
  Node<T> *curr = m_head;
  //"index" starts at 0
  int count = 0;
  while(curr->GetNext() != nullptr){
    //If the "index" matches
    if(count == x){
      //Return the data as a pair
      return curr->GetData();
    }
    //else, increment and go next
    curr = curr->GetNext();
    count++;
  }
  //If data doesnt exist, return last data
  return curr->GetData();
}
