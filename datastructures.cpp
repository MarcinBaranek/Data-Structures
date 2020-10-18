#include "datastructures.h"

Element::Element(float content,
                 Element *consequent = nullptr,
                 Element *predecessor = nullptr){

    this->content = content;
    this->consequent  = consequent;
    this->predecessor = predecessor;
}

Element::~Element() {
    this->predecessor->consequent = nullptr;
    this->consequent->predecessor = nullptr;
    this->predecessor = nullptr;
    this->consequent = nullptr;
}

float Element::get_content() {
    return this->content;
}

int Stack::get_length() {
    return this->length;
}

bool Stack::is_empty() {
    if(this->length == 0)
        return true;
    else
        return false;
}

void Stack::push(Element element) {
    if(this->is_empty()){
        element.predecessor = nullptr;
        element.consequent = nullptr;
        this->length ++;
    } else{
        peak->consequent = &element;
        element.predecessor = peak;
        element.consequent = nullptr;
        this->peak = &element;
        this->length ++;
    }
}

void Stack::push(float content) {
    Element element(content);
    return push(element);
}

void Stack::pop() {
    if(this->is_empty())
        return;
    else{
        this->peak = this->peak->predecessor;
        this->peak->consequent->~Element();
        this->length --;
    }
}

float Stack::get_value() {
    return this->peak->get_content();
}

Element Stack::get_element() {
    return *this->peak;
}