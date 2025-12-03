#include <iostream>
#include "Animal.h"
#include "Mammal.h"
#include "Zoo.h"
#include "Reptile.h"
#include "Bird.h"
using namespace std;

int main() {
    Zoo myZoo("ZooParc 2 Beauval");

    // Partie 1 :
    Animal flash("Flash", "black", "Carnivore", "Mountains", "Grrr", false, 9, 9.9, 1.8);
    flash.printInfo();
    cout << endl;

    Mammal leo("Leo", "Golden", "Carnivore", "Grassland", "Roar", false, 5, 180.5, 3.5, "Tawny");
    leo.printInfo();
    cout << endl;


    // Mammifères
    myZoo.addAnimal(new Mammal("Elephant", "Gris", "Herbivore", "Savane", "Frrr", false, 30, 5500.0, 3.2, "no fur"));
    myZoo.addAnimal(new Mammal("Panda", "Noir et Blanc", "Herbivore", "Montagnes", "arrrh", false, 15, 110.0, 1.5, "whit and black"));
    myZoo.addAnimal(new Mammal("Dauphin", "Gris", "Carnivore", "Océan", "HIHIHI", false, 25, 150.0, 2.5, "no fur"));

    // --- Oiseaux ---
    myZoo.addAnimal(new Bird("Manchot", "Noir et Blanc", "Carnivore", "Arctique", "ahahah", false, 10, 35.0, 1.1, 0.6));
    myZoo.addAnimal(new Bird("Aigle", "Brun", "Carnivore", "Montagnes", "Criii", false, 12, 6.0, 0.9, 2.0));
    myZoo.addAnimal(new Bird("Canard", "Blanc", "Omnivore", "Étang", "Coin", true, 5, 2.5, 0.4, 0.7));

    // --- Reptiles ---
    myZoo.addAnimal(new Reptile("Crocodile", "Vert", "Carnivore", "Eau douce", "Rrrr", false, 45, 800.0, 5.5, "Ostéodermes"));
    myZoo.addAnimal(new Reptile("Serpent", "Jaune et Noir", "Carnivore", "Désert", "Ssss", true, 8, 1.5, 3.0, "Chevauchantes"));
    myZoo.addAnimal(new Reptile("Tortue", "Vert-brun", "Herbivore", "Terre/Mer", "mhh", true, 80, 30.0, 0.6, "Carapace"));

    // List animaux
    myZoo.listAnimals();

    // Prediction  KNN
    Animal unknownAnimal("Unknown", "vert", "Herbivore", "Jungle",
                                    "Chirp", false, 2, 2.0, 0.4);
    myZoo.predictTypeWithKNN(unknownAnimal, 3, "numerical");
    myZoo.predictTypeWithKNN(unknownAnimal, 3, "categorical");

    return 0;
}