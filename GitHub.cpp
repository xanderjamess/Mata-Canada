#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
public:
    // Display heap
    void displayHeap(const vector<int>& heap) {
        cout << "Heap: [ ";
        for (int val : heap) cout << val << " ";
        cout << "]\n";
    }

    // Heapify (max or min) to maintain heap property
    void heapify(vector<int>& heap, int index, bool isMaxHeap) {
        int extreme = index, left = 2 * index + 1, right = 2 * index + 2;
        if (left < heap.size() && (isMaxHeap ? heap[left] > heap[extreme] : heap[left] < heap[extreme])) extreme = left;
        if (right < heap.size() && (isMaxHeap ? heap[right] > heap[extreme] : heap[right] < heap[extreme])) extreme = right;
        if (extreme != index) {
            swap(heap[index], heap[extreme]);
            heapify(heap, extreme, isMaxHeap);
        }
    }

    // Insert element
    void insert(vector<int>& heap, int value, bool isMaxHeap) {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0 && (isMaxHeap ? heap[index] > heap[(index - 1) / 2] : heap[index] < heap[(index - 1) / 2])) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Delete root
    void deleteRoot(vector<int>& heap, bool isMaxHeap) {
        if (heap.empty()) { cout << "Heap is empty!\n"; return; }
        heap[0] = heap.back(); heap.pop_back();
        heapify(heap, 0, isMaxHeap);
    }

    // Build heap from array
    void buildHeap(vector<int>& heap, bool isMaxHeap) {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) heapify(heap, i, isMaxHeap);
    }

    // Convert Max-Heap to Min-Heap
    void convertMaxToMinHeap(vector<int>& heap) {
        buildHeap(heap, false);
    }
};

int main() {
    Heap missionControlHeap;
    vector<int> missionHeap;

    // Insert tasks into Max-Heap
    missionControlHeap.insert(missionHeap, 70, true);
    missionControlHeap.insert(missionHeap, 90, true);
    missionControlHeap.insert(missionHeap, 50, true);
    missionControlHeap.insert(missionHeap, 100, true);
    missionControlHeap.insert(missionHeap, 30, true);

    // Display heap after insertion
    missionControlHeap.displayHeap(missionHeap);

    // Convert Max-Heap to Min-Heap
    missionControlHeap.convertMaxToMinHeap(missionHeap);
    missionControlHeap.displayHeap(missionHeap);

    // Heapify random mission difficulties into Max-Heap
    vector<int> randomMissions = {40, 80, 20, 60, 10};
    missionControlHeap.buildHeap(randomMissions, true);
    missionControlHeap.displayHeap(randomMissions);

    return 0;
}
