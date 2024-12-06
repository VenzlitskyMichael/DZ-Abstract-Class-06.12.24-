#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    string sp;
    string continent;
    double kg;
public:
    Animal() {}
    Animal(string nm, string s, string cont, double k)
        : name(nm), sp(s), continent(cont), kg(k) {}

    virtual void Eat() const = 0;
    virtual void Sound() const = 0;
    virtual ~Animal() {}
    virtual void Print() const {
        cout << name << "\t\t" << sp << "\t" << continent << "\t" << kg << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string nm, string s, string cont, double k)
        : Animal(nm, s, cont, k) {}

    void Eat() const override {
        cout << "Cat is the predator\n";
    }

    void Sound() const override {
        cout << "Myu Myu!!\n";
    }
};

class Elephant : public Animal {
public:
    Elephant(string nm, string s, string cont, double k)
        : Animal(nm, s, cont, k) {}

    void Eat() const override {
        cout << "Elephant omnivore\n";
    }

    void Sound() const override {
        cout << "Go to the zoo and hear this voice\n";
    }
};

class Dog : public Animal {
public:
    Dog(string nm, string s, string cont, double k)
        : Animal(nm, s, cont, k) {}

    void Eat() const override {
        cout << "Dog omnivore\n";
    }

    void Sound() const override {
        cout << "Sound of dog hear like GAV GAV\n";
    }
};

class Parrot : public Animal {
public:
    Parrot(string nm, string s, string cont, double k)
        : Animal(nm, s, cont, k) {}

    void Eat() const override {
        cout << "Parrot herbivores\n";
    }

    void Sound() const override {
        cout << "Sound of Parrot are different\n";
    }
};

int main() {
    Animal* animals[] = {
        new Cat("Black cat", "Cat", "most part of world", 5),
        new Elephant("Indian Elephant", "Elephant", "India", 5000),
        new Dog("Chihuahua", "Dog", "most part of world", 3),
        new Parrot("Red Parrot", "Parrot", "South America", 0.5)
    };

    for (int i = 0; i < 4; ++i) {
        animals[i]->Print();
        animals[i]->Eat();
        animals[i]->Sound();
        cout << endl;
    }
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }
    return 0;
}
