#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(NULL), tail(NULL) {}

    void addNode(int n) {
        Node* newNode = new Node;
        newNode->data = n;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void deleteNode(int n) {
        if (head == NULL) return;

        if (head->data == n) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            if (temp->next->data == n) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    std::cout << "Elements of the list are: ";
    list.printList();

    list.deleteNode(2);

    std::cout << "Elements of the list are: ";
    list.printList();

    return 0;
}
