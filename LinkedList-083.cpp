#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;   
public:
    LinkedList() : head(nullptr) {}
    // Insert a new node with a given value at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    // Insert a new node with a given value at a specified position in the list
    void insertAtN(int value, int position) {
        Node* newNode = new Node(value);
        // If position is 1, insert at the beginning
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        // Traverse to the node at position-1
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }
        // If position is invalid, print an error message
        if (!temp) {
            cout << "Invalid position." << endl;
            return;
        }
        // Insert the new node at the specified position
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Delete the node at the beginning of the list
    void deleteFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "List is empty." << endl;
        }
    }
    // Delete the node at the end of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
       // If there is only one node, delete it and set head to null
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        // Traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        // Delete the last node and update the next pointer of the second-to-last node
        delete temp->next;
        temp->next = nullptr;
    }
    // Delete the node at a specified position in the list
    void deleteFromN(int position) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        // If position is 1, delete the first node
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // Traverse to the node at position-1
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }
        // If position is invalid or the next node is null, print an error message
        if (!temp || !temp->next) {
            cout << "Invalid position." << endl;
            return;
        }
        // Delete the node at the specified position
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    // Search for a value in the list and print its position
    void search(int value) {
        Node* temp = head;
        int position = 1;
        // Traverse the list to find the value
        while (temp) {
            if (temp->data == value) {
                cout << "Value " << value << " found at position " << position << "." << endl;
                return;
            }
            temp = temp->next;
            ++position;
        }
        // If value is not found, print a message
        cout << "Value " << value << " not found in the list." << endl;
    }
    // Update the value at a specified position in the list
    void updateAtN(int value, int position) {
        Node* temp = head;
        // Traverse to the node at the specified position
        for (int i = 1; i < position && temp; ++i) {
            temp = temp->next;
        }
        // If position is invalid, print an error message
        if (!temp) {
            cout << "Invalid position." << endl;
            return;
        }
        // Update the data of the node at the specified position
        temp->data = value;
    }
    // Display the elements of the list
    void display() {
        Node* temp = head;
        // Traverse the list and print each element
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        // Print a newline at the end to separate output
        cout << endl;
    }
};
// Main function
int main() {
    // Create a LinkedList object
    LinkedList list;
    // Perform various operations on the linked list
    list.insertAtBeginning(5);
    list.insertAtBeginning(3);
    list.insertAtN(4, 2);
    list.insertAtN(8, 4);
    list.display();
    list.search(3);
    list.updateAtN(10, 3);
    list.display();
    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteFromN(2);
    list.display();
    // Return 0 to indicate successful execution
    return 0;
}