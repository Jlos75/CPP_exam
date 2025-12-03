//
// Created by jeann on 02/12/2025.
//

#ifndef TP_EXAM_CPP_MAMMAL_H
#define TP_EXAM_CPP_MAMMAL_H

#include "Animal.h" // ⬅️ IL FAUT INCLURE L'EN-TÊTE DE LA CLASSE DE BASE
#include <string>

using namespace std;

// ➡️ Mammal hérite publiquement d'Animal
class Mammal : public Animal {
private:
    string furColor;
public:
    // Constructeur : doit passer les arguments Animal au constructeur de la base
    Mammal(string name,
           string color,
           string diet,
           string habitat,
           string sounds,
           bool isPet,
           int age,
           double weight,
           double height,
           string furColor);

    string getFurColor() const;
    void setFurColor(const string&);
    void printInfo()const;

};

#endif //TP_EXAM_CPP_MAMMAL_H