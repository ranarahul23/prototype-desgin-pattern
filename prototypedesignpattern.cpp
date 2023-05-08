#include <iostream>
#include <string>

using namespace std;


class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void setName(string name) = 0;
    virtual string getName() = 0;
};

class ConcretePrototype : public Prototype {
public:
    ConcretePrototype() {}
    ConcretePrototype(const ConcretePrototype& other) {
        name = other.name;
    }
    virtual Prototype* clone() {
        return new ConcretePrototype(*this);
    }
    virtual void setName(string name) {
        this->name = name;
    }
    virtual string getName() {
        return name;
    }
private:
    string name;
};

int main() {
    ConcretePrototype original;
    original.setName("adam");

    ConcretePrototype* clone = dynamic_cast<ConcretePrototype*>(original.clone());
    clone->setName("aram");

    cout << "Original name: " << original.getName() << endl;
    cout << "Clone name: " << clone->getName() << endl;

    delete clone;

    return 0;
}