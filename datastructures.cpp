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
        if (peak->predecessor){
            this->peak = this->peak->predecessor;
            this->peak->consequent->~Element();
            this->length --;
        } else{
                peak->~Element();
                peak = nullptr;
                length --;
            }
    }
}

float Stack::get_content(){
    if (!is_empty()){
        return peak->get_content();
    } else{
        return false;
    }
}

Element Stack::get_element() {
    return *this->peak;
}

bool Queue::is_empty() {
    if(this->length == 0)
        return true;
    else
        return false;
}

Element Queue::get_first_element() {
    return *this->first_element;
}

Element Queue::get_last_element() {
    return *this->last_element;
}

float Queue::get_first_content() {
    if (is_empty()){
        return false;
    } else
        return this->first_element->get_content();
}

float Queue::get_last_content() {
    if (is_empty()){
        return false;
    } else
        return this->last_element->get_content();
}

void Queue::pop() {
    if(this->is_empty())
        return;
    else{
        if (first_element->predecessor){
            first_element = first_element->predecessor;
            first_element->consequent->~Element();
            length --;
        } else{
            first_element->~Element();
            length --;
        }
    }
}

void Queue::append(Element element) {
    if (is_empty()){
        first_element = &element;
        last_element = &element;
        element.consequent = nullptr;
        element.predecessor = nullptr;
        length ++;
    } else{
        last_element->predecessor = &element;
        element.consequent = last_element;
        last_element = last_element->predecessor;
        last_element->predecessor = nullptr;
    }
}

void Queue::append(float content) {
    Element element(content);
    return append(element);
}
