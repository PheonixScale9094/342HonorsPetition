#include <stdio.h>

template <typename T>
struct LinkNode{
    T val;
    LinkNode<T>* next;

    LinkNode(T val, LinkNode<T>* next = nullptr){
        this->val = val;
        this->next = next;
    }
};

template <typename T>
bool sequentialSearch(LinkNode<T>* start, T val){
    LinkNode<T>* next = start;
    do{
        if(next->val == val){
            delete next;
            return true;
        }
        else{
            next = next->next;
        }
    }while(next != nullptr && next != start);

    delete next;
    return false;
};

int main(){
    LinkNode<int>* integers = new LinkNode<int>(1, new LinkNode<int>(2,new LinkNode<int>(5)));
    LinkNode<char>* characters = new LinkNode<char>('1', new LinkNode<char>('2',new LinkNode<char>('5')));

    puts(sequentialSearch(integers, 5)?"True":"False");
    puts(sequentialSearch(characters, 'a')?"True":"False");

    return 0;
};