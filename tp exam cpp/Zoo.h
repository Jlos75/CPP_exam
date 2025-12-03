//
// Created by jeann on 02/12/2025.
//

#ifndef TP_EXAM_CPP_ZOO_H
#define TP_EXAM_CPP_ZOO_H
#include <string>
#include <vector>
#include "Zoo.h"
#include "Animal.h"

class Animal;
using namespace std;

class Zoo {
private:
    string name;
    static int MAX_CAPACITY;
    vector<Animal*> animals;
public:
    Zoo() = default;
    Zoo(string name);

    void setName(const string &newName);
    string getName() const;

    void addAnimal(Animal *animal);
    void listAnimals() const;
    int searchAnimalByName(string name) const;
    void removeAnimalByName(string name);
    double averageAgForType(string type) const;

    void predictTypeWithKNN(const Animal &unknownAnimal, int k, string informationType) const;
};


#endif //TP_EXAM_CPP_ZOO_H