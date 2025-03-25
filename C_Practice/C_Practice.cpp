// Thalia Stafford
//Linked Lists

#include <iostream>
using namespace std; 

//define struct
struct StudentNode {
    int id;
    string name;
    float gpa;
    StudentNode* next; //pointer

    //constructor for studentnote
    StudentNode(int studentId, string studentName, float studentGpa) {
        id = studentId;
        name = studentName;
        gpa = studentGpa;
        next = nullptr;
    }
};

//define class
class LinkedList {
private: //private because only linkedlist can access or modify. nothing outside of class can modify
    StudentNode* head; //Pointer to first node
public:
    LinkedList();  // Constructor declaration
    ~LinkedList(); // Destructor 

    //declare functions
    void AddStudent(int id, string name, float gpa);
    void RemoveStudent(int id);
    void SearchStudent(int id);
    void DisplayAll();
};

// Constructor definition - intializes everything
LinkedList::LinkedList() {
    head = nullptr; // Initialize head to nullptr, meaning the list is initially empty.
}

// Destructor definition - Deletes everything
LinkedList::~LinkedList() {
    StudentNode* current = head; // Start at the head of the linked list.

    // Iterate through the list and delete each node
    while (current != nullptr) { //while current node is not empty
        StudentNode* temp = current; // Store the current node in a temporary pointer.
        current = current->next; // Move to the next node in the list.
        delete temp; // Free memory allocated for the current node.
}

    cout << "All students deleted. Memory cleaned up." << endl; // Confirm deletion of all nodes.
}

//FUNCTIONS

//Add Student
void LinkedList::AddStudent(int id, string name, float gpa) {
    // Create a new node with the given student details
    StudentNode* newNode = new StudentNode(id, name, gpa);

    //check if list is empty (head is nullptr_
    if (head == nullptr) {
        head = newNode;// If empty, set head to the new node (first student in the list)
    }
    else {// Otherwise, traverse the list to find the last node
        StudentNode* temp = head; // Start at the head
        while (temp->next != nullptr) { // Traverse until the last node (where next is nullptr)
            temp = temp->next; // Move to the next node
        }
        temp->next = newNode; // Set the last node’s next pointer to the new node
    }
    // Print confirmation message
    cout << "Student added successfully!" << endl;
}

// Function to remove a student by ID
void LinkedList::RemoveStudent(int id) {
    //check if list empty
    if (head == nullptr) {
        cout << "List is empty. Cannot remove student." << endl;
        return;
    }

    StudentNode* prev = nullptr;
    StudentNode* current = head;

    // Traverse the list until we find the node with the matching ID
    while (current != nullptr) {
        if (current->id == id) { // If the current node matches the given ID
            if (prev == nullptr) {
                // This means the node to remove is the head
                head = current->next; // Update head to the next node
            }
            else {
                // This means the node is not the head; update the previous node's next pointer
                prev->next = current->next;
            }
            delete current; // Free the memory of the node being removed
            cout << "Student with ID " << id << " removed." << endl;
            return;
        }
        prev = current;           // Move prev to current node
        current = current->next;  // Move current to the next node
    }

    // If we reach this point, the student with the given ID was not found
    cout << "Student with ID " << id << " not found." << endl;
}

void LinkedList::SearchStudent(int id) {
    StudentNode* temp = head;

    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Student Found: ID=" << temp->id << ", Name=" << temp->name << ", GPA=" << temp->gpa << endl;
            return;
        }
        else {
            temp = temp->next;
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
}

// Function to display all students
void LinkedList::DisplayAll() {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    StudentNode* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
}

//MAIN
int main()
{
    LinkedList studentList;
    int choice, id;
    string name;
    float gpa;

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n2. Remove Student\n3. Search Student\n4. Display All Students\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;

            // Use cin to capture the name, allowing spaces
            cout << "Enter Student Name (without using spaces): ";
            cin >> ws;  // This removes any leading whitespace
            cin >> name; // This will capture the name word by word, without spaces

            cout << "Enter Student GPA: ";
            cin >> gpa;
            studentList.AddStudent(id, name, gpa);
            break;

        case 2:
            cout << "Enter Student ID to remove: ";
            cin >> id;
            studentList.RemoveStudent(id);
            break;

        case 3:
            cout << "Enter Student ID to search: ";
            cin >> id;
            studentList.SearchStudent(id);
            break;

        case 4:
            cout << "List of Students:\n";
            studentList.DisplayAll();
            break;

        case 5:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
