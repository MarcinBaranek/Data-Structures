//
// Created by Marcin on 18.10.2020.
//

#ifndef PROGRAMS_DATASTRUCTURES_H
#define PROGRAMS_DATASTRUCTURES_H

#endif //PROGRAMS_DATASTRUCTURES_H

class Element{
protected:
    float content;
    Element *consequent;
    Element *predecessor;

    explicit Element(float, Element *, Element *);
    float get_content();
    ~Element();

    friend class Stack;
    friend class Queue;
};

class Stack{
    int length = 0;
    Element *peak;

    void push(Element);
    void push(float);
    void pop();
    Element get_element();
    float get_value();
    bool is_empty();
    int get_length();
};

class Queue{
    int length = 0;
    Element *first_element;
    Element *last_element;

    void append(Element);
    void append(float);

};

class Dict{

};

class Edge{

};

class Three{

};

class Graph{

};

