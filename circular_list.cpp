#include "circular_list.h"

namespace myproject {

struct CircularList::Implementation {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    size_t list_size;

    Implementation() : head(nullptr), list_size(0) {}

    ~Implementation() {
        clear();
    }

    void clear() {
        while (list_size > 0) {
            remove(head->data);
        }
    }

    void add(int value) {

        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        ++list_size;
    }

    void remove(int value) {
        if (!head) {
            throw MyProjectException("Cannot remove from an empty list");
        }

        Node* current = head;
        for (size_t i = 0; i < list_size; ++i) {
            if (current->data == value) {
                if (list_size == 1) {
                    delete head;
                    head = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if (current == head) {
                        head = current->next;
                    }
                    delete current;
                }
                --list_size;
                return;
            }
            current = current->next;
        }

        throw MyProjectException("Value not found in the list");
    }

    bool contains(int value) const {
        Node* current = head;
        for (size_t i = 0; i < list_size; ++i) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void update(int oldValue, int newValue) {
        if (!contains(oldValue)) {
            throw MyProjectException("Old value not found");
        }

        Node* current = head;
        for (size_t i = 0; i < list_size; ++i) {
            if (current->data == newValue) {
                current->data = oldValue;
                return;
            }
            current = current->next;
        }
    }

    void print() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        for (size_t i = 0; i < list_size; ++i) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    size_t size() const {
        return list_size;
    }

    int get(size_t index) const {
        if (index >= list_size) {
            throw out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }
};

CircularList::CircularList() : impl(new Implementation()) {}

CircularList::CircularList(const CircularList& other) : impl(new Implementation()) {
    for (size_t i = 0; i < other.size(); ++i) {
        impl->add(other[i]);
    }
}

CircularList& CircularList::operator=(const CircularList& other) {
    if (this == &other) return *this;

    clear();
    for (size_t i = 0; i < other.size(); ++i) {
        impl->add(other[i]);
    }
    return *this;
}

CircularList::~CircularList() {
    delete impl;
}

CircularList& CircularList::operator+=(int value) {
    add(value);
    return *this;
}

CircularList& CircularList::operator-=(int value) {
    remove(value);
    return *this;
}

bool CircularList::operator==(const CircularList& other) const {
    if (size() != other.size()) return false;
    for (size_t i = 0; i < size(); ++i) {
        if ((*this)[i] != other[i]) return false;
    }
    return true;
}

bool CircularList::operator!=(const CircularList& other) const {
    return !(*this == other);
}

int CircularList::operator[](size_t index) const {
    return impl->get(index);
}

void CircularList::operator!() {
    clear();
}

void CircularList::add(int value) { 
    impl->add(value);
}

void CircularList::remove(int value) {
    impl->remove(value);
}

void CircularList::clear() {
    impl->clear();
}

void CircularList::update(int oldValue, int newValue) {
    impl->update(oldValue, newValue);
}

size_t CircularList::size() const {
    return impl->size();
}

bool CircularList::contains(int value) const {
    return impl->contains(value);
}

void CircularList::print() const {
    impl->print();}

}