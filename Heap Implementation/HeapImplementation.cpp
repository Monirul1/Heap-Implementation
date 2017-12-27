#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> items;
    
    void swap(int child, int parent);
    int getLeftChild(int parent);
    int getRightChild(int parent);
    int getParent(int child);
    void bubbleUp();
    void bubbleDown(int parent);
    
public:
    Heap();
    int peekFront();
    void insert(int data);
    void remove();
    bool isEmpty();
    int getSize();
};

Heap::Heap() {
}

void Heap::swap(int child, int parent) {
    int temp = items[child];
    items[child] = items[parent];
    items[parent] = temp;
}

int Heap::getLeftChild(int parent) {
    return 2 * parent + 1;
}

int Heap::getRightChild(int parent) {
    return 2 * parent + 2;
}

int Heap::getParent(int child) {
    return (child - 1)/2;
}

void Heap::bubbleUp() {
    int child = items.size() - 1;
    int parent = getParent(child);
    while (child >= 0 && parent >=0 && items[child] > items[parent]) {
        swap(child, parent);
        child = parent;
        parent = getParent(child);
    }
}

void Heap::insert(int data) {
    items.push_back(data);
    bubbleUp();
}

void Heap::remove() {
    int child = items.size() - 1;
    swap(0, child);
    items.pop_back();
    bubbleDown(0);
}

int Heap::peekFront() {
    return items[0];
}

bool Heap::isEmpty() {
    return items.size() == 0;
}


void Heap::bubbleDown(int parent) {
    int length = items.size();
    int left = getLeftChild(parent);
    int right = getRightChild(parent);
    int larger = parent;
    if (left < length && items[left] > items[larger]) {
        larger = left;
    }
    if (right < length && items[right] > items[larger]) {
        larger = right;
    }
    if (larger != parent) {
        swap(parent, larger);
        bubbleDown(larger);
    }
}

int main() {
    int arr[] = {4, 2, 3, 1, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    Heap heap;
    for (int i = 0; i < size; i++) {
        heap.insert(arr[i]);
    }
    cout << "The elements in heap ";
    while (!heap.isEmpty()) {
        cout << heap.peekFront() << " ";
        heap.remove();
    }
    cout << endl;
}