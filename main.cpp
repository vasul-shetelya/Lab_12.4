#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Функція для створення нового елемента
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Функція для додавання елемента в кінець списку
void addNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для виведення списку
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція для розділення списку на два списки L1 та L2
void splitList(Node* L, Node*& L1, Node*& L2) {
    Node* current = L;
    while (current != nullptr) {
        if (current->data > 0) {
            addNode(L1, current->data);
        } else {
            addNode(L2, current->data);
        }
        current = current->next;
    }
}

int main() {
    // Створення вихідного списку L
    Node* L = nullptr;
    addNode(L, 1);
    addNode(L, -2);
    addNode(L, 3);
    addNode(L, -4);
    addNode(L, 5);

    // Виведення початкового списку L
    cout << "Початковий список L: ";
    printList(L);

    // Створення списків L1 та L2
    Node* L1 = nullptr;
    Node* L2 = nullptr;

    // Розділення списку L на L1 та L2
    splitList(L, L1, L2);

    // Виведення списку L1
    cout << "Список L1 (додатні значення): ";
    printList(L1);

    // Виведення списку L2
    cout << "Список L2 (від'ємні значення): ";
    printList(L2);

    // Видалення списків L, L1 та L2
    while (L != nullptr) {
        Node* temp = L;
        L = L->next;
        delete temp;
    }
    while (L1 != nullptr) {
        Node* temp = L1;
        L1 = L1->next;
        delete temp;
    }
    while (L2 != nullptr) {
        Node* temp = L2;
        L2 = L2->next;
        delete temp;
    }

    return 0;
}

