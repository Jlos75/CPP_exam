//
// Created by jeann on 02/12/2025.
//

#ifndef TP_EXAM_CPP_REPTILE_H
#define TP_EXAM_CPP_REPTILE_H
#include "Animal.h"


class Reptile : public Animal {
private:
    string scalePattern;
public:
    // Constructeur : doit passer les arguments Animal au constructeur de la base
    Reptile(string name,
           string color,
           string diet,
           string habitat,
           string sounds,
           bool isPet,
           int age,
           double weight,
           double height,
           string scalePattern);

    string getScalePattern() const;
    void setScalePattern(const string&);
    void printInfo()const;

};


#endif //TP_EXAM_CPP_REPTILE_H