//04_simple linked list
//!!!SOLUTION!!
/*
 * contribution : Miguel GOmex, Omar Alaniz, Elizabeth Huang, Saengduean Calderaz
 */
//note : always consider the possibility of NULL list, first, middle , last
#include <iostream>

using namespace std;

//recursive function link list accept node * go through all list and add up all items



struct Node {
  int data;
  Node *next;
};

//a recursive function go through all the data , and add up all value
int foo(Node* n){
    /*Node* current = n;
    int sum = 0;
    //base case
    if(current== nullptr) return 0;
    while(current!= nullptr){
        sum += foo(current->next);
    }*/
    if(n->next==nullptr){
        return n->data;
    }else{
        return(n->data+foo(n->next));
    }

}

void reverse(Node* n) { //a function reverse the entire linked list

}
/**
 * This is only for the 1st Node
 * @param head - pointer to the head of the list
 * @param n - data that the first element should hold
 */
void initNode(struct Node *head, int n) {
  //TODO: Initiliaze the node data to n and the next pointer to..?
    head->data = n;
    head->next= nullptr;
}

/**
 * This funtion addes a node to the end of the list.
 * @param head - pointer to the head of the list
 * @param n - data that the new node should hold
 */
void addNode(struct Node *head, int n) {
  //TODO - Implement this function.
    Node* curr = head;
    Node* newNode = new Node();
    /*
     * Node* newNode <<not working, since it only creates the pointer without object
     * new Node() : new an object for the pointer
     */
    newNode->data = n;
    /*
     * newNode is a structure pointer(Node is a structure), and it points to the object ( created by new Node() )
     * newNode ->data: newNode points to the data inside the structure
     * newNode ->data = n : assign n to the data inside the object newNode is point to
     */
    //iterate to the node before the last node
    while(curr->next!= nullptr){
        curr = curr->next;
    }
    curr->next=newNode;
    //
}

/**
 * This funtion addes a node to the front of the list.
 * @param head - pointer to the head of the list
 * @param n - data that the new node should hold
 */
void insertFront(struct Node **head, int n) {
  //since we're going to modify the head pointer
    Node* newHead = new Node();
    newHead->data = n;
    newHead->next = *head;
    *head = newHead;

}

/**
 * This function displayes the nodes in the list
 * @param head  - pointer to the head of the list
 */
void display(struct Node *head) {
    Node* current = head;
    if(head== nullptr){
        std::cout<<"empty list";
        return;
    }
    do{
        std::cout<<current->data<<' ';
        current=current->next;
    }while(current!= nullptr);
    std::cout<<endl;
  //TODO
}

/**
 * This function searches for a node holding n and returns a pointer to it.
 * @param head - pointer to the head of the list
 * @param n - data to search nodes for
 * @return - pointer to the node found.
 */
struct Node *searchNode(struct Node *head, int n) {
  //TODO
    Node* current = head;
    while(current!= nullptr){
        if(current->data ==n ) return current;

        //flash the iterator
        current = current->next;
    }
  return NULL;
}

/**
 * This function deletes a node
 * @param head - pointer to the head of the list
 * @param ptrDel - pointer to the node that is to be deleted
 * @return - boolean that indicates if the deletion was successful
 */
bool deleteNode(struct Node **head, Node *ptrDel){
    Node* current = *head;
    if(current==nullptr) return false;
    while(current!=ptrDel){
        if(!current) return false;
        current = current->next;
    }
    current = current ->next;
    return true;
}

/* reverse the list */
struct Node *reverse(struct Node **head) {
    /*
     * o(chain first,head)-->o(stack first)-->o(stack second)-->...
     */
    //set up model for stack and chain
    Node* chainFirst = *head;
    Node* stackFirst = chainFirst->next;
    Node* stackSecond = stackFirst->next;

    chainFirst->next = nullptr; //make the first node as the last
    /*
    * chain: o(chain first,head)-->
    * stack: o(stack first)-->o(stack second)-->o-->o-->...
    */
    while(stackSecond){
        stackFirst->next = chainFirst; //move the first element in stack to first element in chain
        /*
        * chain: o(stack first)-->o(chain first)-->o-->o-->......o(head)-->
        * stack: o(stack second)-->o-->o-->...
        */

        //change the tag of element
        chainFirst=stackFirst;
        stackFirst=stackSecond;
        stackSecond=stackFirst->next;
    }
    /* after the loop
    * chain: o(chain first)-->o-->o-->......o(head)-->
    * stack: o(stack first)-->    (stack second)
    */
    stackFirst->next=chainFirst;
    /* after the loop
    * chain: o(stack first)-->o(chain first)-->o-->o-->......o(head)-->
    * stack:     (stack second)
    */
    *head=stackFirst;
    /* after the loop
    * chain: o(stack first,head)-->o(chain first)-->o-->o-->......o-->
    * stack:     (stack second)
    */
    return *head;
}

/* Creating a copy of a linked list */
void copyLinkedList(struct Node *node, struct Node **pNew) {
    /*
     * we consider a list, n element, has n sub-list
     * every element is a new sub-list's head
     * e.g: (element1, head1)-->(element2,head2)-->(element3,head3)-->...(elementn, head n)-->
     * **pNew is consider as container to create head
     */
    //using recursive
    if(node!=NULL){ //assume the head is not the last element of parent list
        *pNew = new Node; /
        //if the sub-list exist, then we copy the head
        (*pNew)->data = node->data;
        copyLinkedList(node->next,&((*pNew)->next));
        //pass the sub-list and corresponding position
    }
}

/* Compare two linked list */
/* return value: same(1), different(0) */
int compareLinkedList(struct Node *node1, struct Node *node2) {
}

void deleteLinkedList(struct Node **node) {

}

int main() {
  struct Node *newHead;
  struct Node *head = new Node;


  initNode(head,10);
  display(head);

  addNode(head,20);
  display(head);

  addNode(head,30);
  display(head);

  addNode(head,35);
  display(head);

  addNode(head,40);
  display(head);

    std::cout<<foo(head);
/*
  insertFront(&head,5);
  display(head);

  int numDel = 5;
  Node *ptrDelete = searchNode(head,numDel);
  if(deleteNode(&head,ptrDelete))
      cout << "Node "<< numDel << " deleted!\n";
  display(head);

  cout << "The list is reversed\n";
  reverse(&head);
  display(head);

  cout << "The list is copied\n";
  copyLinkedList(head,&newHead);
  display(newHead);

  cout << "Comparing the two lists...\n";
  cout << "Are the two lists same?\n";
  if(compareLinkedList(head,newHead))
      cout << "Yes, they are same!\n";
  else
      cout << "No, they are different!\n";
  cout << endl;

  numDel = 35;
  ptrDelete = searchNode(newHead,numDel);
  if(deleteNode(&newHead,ptrDelete)) {
      cout << "Node "<< numDel << " deleted!\n";
      cout << "The new list after the delete is\n";
      display(newHead);
  }
  cout << "Comparing the two lists again...\n";
  cout << "Are the two lists same?\n";
  if(compareLinkedList(head,newHead))
      cout << "Yes, they are same!\n";
  else
      cout << "No, they are different!\n";

  cout << endl;
  cout << "Deleting the copied list\n";

  deleteLinkedList(&newHead);
  display(newHead);
*/
  return 0;
}