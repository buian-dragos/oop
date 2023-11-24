#pragma once
#include "string"
#include "iostream"
#include "typeinfo"
#include "../domain/event.h"

template <class T>
class DynamicArray{
private:
    T* array;
    int capacity;
    int size;

//    doubles the size of the array when needed
    void resize(){
        int new_size = capacity * 2;
        T* new_arr = new T[new_size];

        for(int i = 0; i < size; i++){
            new_arr[i] = array[i];
        }

        capacity = new_size;
        delete[] array;
        array = new_arr;
    }

public:
    DynamicArray(){
        array = new T[20]();
        capacity = 5;
        size = 0;
    }
    ~DynamicArray(){
        //delete[] this->array;
    }

//    resizes if it has to and then adds a new element to the array
    void add(const T& new_elem){
        if (size == capacity)
            resize();
        array[size] = new_elem;
        size++;
    }

//    adds an event at an index
//  used for adding events to a users list
    void add_id(int id,const Event& new_elem){
        array[id].add_event(new_elem);
    }

//    removes the element from a given index
    void remove(int index){
        for (int i = index; i < size; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    int get_size(){
        return size;
    }

//    update element at a given index
    void update(T elem, int index){
        array[index] = elem;
    }

    int index(T elem){
        for (int i = 0; i < size; i++)
            if (array[i].is_equal(elem))
                return i;
        return -1;
    }

//    returns the item from an index
    T get_item(int index){
        return array[index];
    }

//    string representation of the elements in the array
    std::string list(){
        std::string rs;
        for (int i = 0; i < size; i++)
            rs.append(array[i].to_string());
        return rs;
    }

//    calls the remove function for a certain event
//    used for removing events from a users list
    void remove_at_index(int index, Event elem){
        array[index].remove(elem);
    }

//    decrements the size idk why i have this
    void dec_size(){
        size--;
    }


//    sets the elem at a given index
    void set_elem(int index, T elem){
        array[index] = elem;
    }

};