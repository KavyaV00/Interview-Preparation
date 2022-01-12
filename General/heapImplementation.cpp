#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    Initialize current element as largest. Take left and right child. 
    Comppare their values. Set the value of largest after comparing the three values.
    If current element != largest, then swap elements at position i and largest. 
    Call heapify on largest(newly created subtree).
*/
void heapify(vector<int> &ht, int i) {
    int size = ht.size();
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    if(leftChild < size && ht[leftChild]>ht[largest])
        largest = leftChild;
    if(rightChild < size && ht[rightChild]>ht[largest])
        largest = rightChild;
    if(i != largest) {
        swap(&ht[i], &ht[largest]);
        heapify(ht, largest);
    }
}

/*
    If leaf, push the node. Else, push the node and call heapify on all nodes from  
    i = n/2-1 to 0 (all parent nodes).
*/
void insert(vector<int> &ht, int num) {
    int length = ht.size();
    if(length==0)
        ht.push_back(num);
    else {
        ht.push_back(num);
        for(int i=length/2-1; i>=0; i--)
            heapify(ht, i);
    }
}

/*
    Find position of number to be deleted. Then swap the index with the last node. 
    Delete the last node. Call heapify on the tree.
*/
void deleteNode(vector<int> &ht, int num) {
    int size = ht.size();
    int i;
    for(i=0; i<size; i++) {
        if(ht[i] == num)
            break;
    }
    swap(&ht[i], &ht[size-1]);
    ht.pop_back();
    for(int i=size/2-1; i>=0; i--) 
        heapify(ht, i);
}

void printHeap(vector<int> &ht) {
    for(int i=0; i<ht.size(); i++) 
        cout<< ht[i] << " ";
    cout<<endl;
}

int main() {
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);
    cout<< "Max Heap :\n";
    printHeap(heapTree);
    deleteNode(heapTree, 4);
    cout<< "Max heap after deletion: \n";
    printHeap(heapTree);
}
