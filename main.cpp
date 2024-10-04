// COSM 210 | LAB - 17 - starter | Robert Stoenmetz

#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node* next;
};

// Function prototypes
void output(Node* head);
Node* addToFront(Node* head, float value);
Node* addToTail(Node* head, float value);
Node* deleteNode(Node* head, int position);
Node* insertNode(Node* head, int position, float value);
void deleteList(Node*& head);
int getListSize(Node* head);

int main() {
    Node* head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addToFront(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    Node* current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    head = insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

Node* addToFront(Node* head, float value) {
    Node* newVal = new Node;
    newVal->value = value;
    newVal->next = head;
    return newVal;
}

Node* addToTail(Node* head, float value) {
    Node* newVal = new Node;
    newVal->value = value;
    newVal->next = nullptr;

    if (!head) {
        return newVal;
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newVal;
    return head;
}

Node* deleteNode(Node* head, int position) {
    if (!head) return nullptr;

    Node* current = head;
    Node* prev = nullptr;

    if (position == 1) {
        head = current->next;
        delete current;
        return head;
    }

    for (int i = 0; i < (position - 1) && current; i++) {
        prev = current;
        current = current->next;
    }

    if (current) {
        prev->next = current->next;
        delete current;
    }

    return head;
}

Node* insertNode(Node* head, int position, float value) {
    Node* newnode = new Node;
    newnode->value = value;

    if (position == 0 || !head) {
        newnode->next = head;
        return newnode;
    }

    Node* current = head;
    Node* prev = nullptr;
    for (int i = 0; i < position && current; i++) {
        prev = current;
        current = current->next;
    }

    newnode->next = current;
    prev->next = newnode;
    return head;
}

void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int getListSize(Node* head) {
    int size = 0;
    Node* current = head;
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

void output(Node* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}