#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data;        // Pointer to the array of integers
    size_t capacity;  // Total capacity of the array
    size_t size;      // Current number of elements in the array

    // Resize the array to a new capacity
    void resize(size_t new_capacity) {
        int* new_data = new int[new_capacity]; // Allocate new array
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i]; // Copy old elements to new array
        }
        delete[] data; // Free old array
        data = new_data; // Point to new array
        capacity = new_capacity; // Update capacity
    }

public:
    // Constructor
    DynamicArray() : data(nullptr), capacity(0), size(0) {}

    // Destructor
    ~DynamicArray() {
        delete[] data; // Free allocated memory
    }

    // Add an element to the end of the array
    void push_back(int value) {
        if (size >= capacity) {
            // If the array is full, double the capacity
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            resize(new_capacity);
        }
        data[size++] = value; // Add the new element and increment size
    }

    // Get the element at a specific index
    int at(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Get the current size of the array
    size_t getSize() const {
        return size;
    }

    // Get the current capacity of the array
    size_t getCapacity() const {
        return capacity;
    }

    // Remove the last element from the array
    void pop_back() {
        if (size > 0) {
            --size; // Decrease size
        }
    }

    // Print the elements of the array
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray arr;

    // Adding elements to the dynamic array
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    // Print the elements
    std::cout << "Elements in the dynamic array: ";
    arr.print();

    // Accessing elements
    std::cout << "Element at index 2: " << arr.at(2) << std::endl;

    // Remove the last element
    arr.pop_back();
    std::cout << "After popping last element: ";
    arr.print();

    return 0;
}