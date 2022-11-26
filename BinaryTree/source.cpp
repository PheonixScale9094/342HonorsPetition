#include <stdio.h>

template <typename T>
struct BinaryNode{
    T val;
    BinaryNode<T>* left;
    BinaryNode<T>* right;

    BinaryNode(T val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    void addNode(T val){
        if(val > this->val){
            if(right != nullptr){
                right->addNode(val);
            }
            else{
                right = new BinaryNode(val);
            }
        }
        else{
            if(left != nullptr){
                left->addNode(val);
            }
            else{
                left = new BinaryNode(val);
            }
        }
    }
};

template <typename T>
void printInOrder(BinaryNode<T>* head, const char* format_specifier){

    if(head->left != nullptr){
        printInOrder(head->left, format_specifier);
    }
    printf(format_specifier, head->val);
    if(head->right != nullptr){
        printInOrder(head->right, format_specifier);
    }

}

int main(){
    BinaryNode<float> node(2.1f);
    node.addNode(3.0f);
    node.addNode(2.3f);
    node.addNode(2.4f);
    node.addNode(1.8f);
    node.addNode(1.3f);
    node.addNode(3.4f);
    node.addNode(1.0f);
    node.addNode(2.0f);

    printInOrder(&node, "%.1f\n");

    return 0;
};