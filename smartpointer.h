#ifndef C11CONCEPTS
#define C11CONCEPTS
#include <iostream>
#include <memory>
using namespace std;
class Dog{
    string name;
public:
    weak_ptr<Dog> pDog;

    Dog(string pname): name(pname){
        cout<< "Dog()=" << name << endl;
    }
    Dog(){
        cout<< "Dog()\n";
    }
    ~Dog(){
        cout<< name << "~Dog()\n";
    }
    void funOut()
    {
        cout << name << "funOut()\n";
    }
    void setPDog(shared_ptr<Dog> argPDog)
    {
        pDog = argPDog;
    }

    void testUniqueArg(unique_ptr<Dog> argUDog)
    {
        argUDog->funOut();
    }
    Dog& operator =(Dog&&) = default;

};

class A{};

void uniquePointer()
{
    unique_ptr<Dog> uDogJack = make_unique<Dog>("uJack");
    unique_ptr<Dog> uDogTom = make_unique<Dog>("uTom");
//    uDogJack->testUniqueArg(move(uDogTom));
    uDogJack = move(uDogTom);
    if ( uDogTom)
        cout << "uDogTom valid" << endl;
    else
        cout << "uDogTom invalid" << endl;
    unique_ptr<A> a= make_unique<A>();
    unique_ptr<A> b= make_unique<A>();
//    a=b; // will not compile unique_ptr has to be move()
}

void sharedPointer()
{
    shared_ptr<Dog> spDogTom = make_shared<Dog>("Tom");
    shared_ptr<Dog> spDogJack = make_shared<Dog>("Jack");
    spDogTom->funOut();
    spDogJack->funOut();

    //weak pointer
    spDogJack->setPDog(spDogTom);
    spDogTom->setPDog(spDogJack);
    // weak pointer has to be lock before usage which gives shared_ptr
    if (auto spJackChild = spDogJack->pDog.lock())
    {
        spJackChild->funOut();
    }
}



#endif // C11CONCEPTS

