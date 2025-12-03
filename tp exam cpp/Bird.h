//
// Created by jeann on 02/12/2025.
//

#ifndef TP_EXAM_CPP_BIRD_H
#define TP_EXAM_CPP_BIRD_H
#include "Animal.h"
using namespace std;

class Bird : public Animal{
private:
    double wingspan;
public:
    // Constructeur : doit passer les arguments Animal au constructeur de la base
    Bird(string name,
           string color,
           string diet,
           string habitat,
           string sounds,
           bool isPet,
           int age,
           double weight,
           double height,
           double wingspan);

    double getWingspan() const;
    void setWingspan(double);
    void printInfo() const;
};


#endif //TP_EXAM_CPP_BIRD_H