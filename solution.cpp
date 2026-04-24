#include<iostream>
#include<cstdio>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    int size;
    
    LinkedList() : head(nullptr), size(0) {}
    
    void initialize() {
        int n;
        scanf("%d", &n);
        int *a = new int[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        if(n > 0) {
            head = new Node(a[0]);
            Node* current = head;
            size = 1;
            for(int i = 1; i < n; i++) {
                current->next = new Node(a[i]);
                current = current->next;
                size++;
            }
        }
        
        delete[] a;
    }
    
    void insert(int i, int x) {
        if(i <= 0 || i > size) return;
        
        Node* current = head;
        for(int j = 1; j < i; j++) {
            current = current->next;
        }
        
        Node* newNode = new Node(x);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    void erase(int i) {
        if(i <= 0 || i > size) return;
        
        if(i == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        
        Node* current = head;
        for(int j = 1; j < i - 1; j++) {
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
    
    void swap() {
        if(size < 2) return;
        
        Node* prev = nullptr;
        Node* first = head;
        Node* second = head->next;
        
        head = second;
        
        while(first != nullptr && second != nullptr) {
            Node* nextPair = second->next;
            
            second->next = first;
            first->next = nextPair;
            
            if(prev != nullptr) {
                prev->next = second;
            }
            
            prev = first;
            
            if(nextPair == nullptr) break;
            first = nextPair;
            second = first->next;
        }
    }
    
    void moveback(int i, int x) {
        if(i <= 0 || i > size || x <= 0 || i + x > size) return;
        
        if(i == 0 || x == 0) return;
        
        Node* beforeFirst = nullptr;
        Node* first = head;
        Node* lastOfFirst = head;
        
        for(int j = 1; j < i; j++) {
            lastOfFirst = lastOfFirst->next;
        }
        
        Node* beforeTarget = lastOfFirst;
        for(int j = 0; j < x; j++) {
            beforeTarget = beforeTarget->next;
        }
        
        Node* afterTarget = beforeTarget->next;
        
        Node* newHead = lastOfFirst->next;
        lastOfFirst->next = afterTarget;
        beforeTarget->next = first;
        
        head = newHead;
    }
    
    int query(int i) {
        if(i <= 0 || i > size) return -1;
        
        Node* current = head;
        for(int j = 1; j < i; j++) {
            current = current->next;
        }
        return current->data;
    }
    
    void printAll() {
        Node* current = head;
        bool first = true;
        while(current != nullptr) {
            if(!first) printf(" ");
            printf("%d", current->data);
            first = false;
            current = current->next;
        }
        printf("\n");
    }
    
    void ClearMemory() {
        Node* current = head;
        while(current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }
};

int main() {
    LinkedList List;
    int m, op, i, x;
    List.initialize();
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &i, &x);
            List.insert(i, x);
        }
        else if(op == 2) {
            scanf("%d", &i);
            List.erase(i);
        }
        else if(op == 3) {
            List.swap();
        }
        else if(op == 4) {
            scanf("%d%d",&i, &x);
            List.moveback(i, x);
        }
        else if(op == 5) {
            scanf("%d", &i);
            printf("%d\n", List.query(i));
        }
        else if(op == 6) {
            List.printAll();
        }
    }
    List.ClearMemory();
    return 0;
}
