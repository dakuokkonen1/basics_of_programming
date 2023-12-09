#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

class Animal
{

public:

    Animal(string name, int age, string tall , string activity, string residence, string food)
        : name(name), age(age), tall(tall) ,activity(activity), residence(residence), food(food), info(" ") {}

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        name = name;
    }


    void Sleep()
    {
        cout << name << " is sleeping" << endl;
    }


    void Play()
    {
        cout << name << " is playing" << endl;
    }
    void Jump()
    {
        cout << name << " is jumping" << endl;
    }
    void Dance()
    {
        cout << name << " is dancing" << endl;
    }

    void Feed()
    {
        cout << name << " is fed" << endl;
    }
    void Stroke()
    {
        cout << name << " is stroking" << endl;
    }


    virtual void MakeSound()
    {
        cout << "" << endl;
    }

    virtual string Ability() {
        return "";
    }

    virtual string Fur_Colour()
    {
        return "";
    }
    virtual string Animal_Weight()
    {
        return "";
    }
    void setInfo(string info)
    {
        info = info;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Tall: " << tall << endl;
        cout << "Activity: " << activity << endl;
        cout << "Residence: " << residence << endl;
        cout << "Favourite food: " << food << endl;
        cout << Ability() << endl;
        cout << Fur_Colour() << endl;
        cout << Animal_Weight() << endl;
        cout << endl;
    }


protected:
    string name;
    string tall;
    string info;
    string activity;
    string residence;
    string food;
    double age;
};

class Zoo
{
private:
    vector<Animal*> animals;
public:

    void deleteAnimal(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals.erase(animals.begin() + i);
                break;
            }
        }

    }

    void addAnimal(Animal* animal)
    {
        animals.push_back(animal);
    }

    void feedAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->Feed();
        }
    }
    void Stroke(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->Stroke( );
        }
    }
    void JumpSmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->Jump();
                break;
            }
        }
    }
    
    void MakeSoundSmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->MakeSound();
                break;
            }
        }
    }

    void PlaySmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->Play();
                break;
            }
        }
    }

    void DanceSmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->Dance();
                break;
            }
        }
    }
    void randompositionAll()
    {
        srand(time(0));
        int x;
        x = rand() % 3 + 1;

        if (x == 2)
        {
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->Sleep();
            }
        }
        else
        {
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->Jump();
            }
        }

    }
    void infoAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->getInfo();
        }
    }
};

class Parrot : public Animal
{
public:

    Parrot(string name, int age, string tall ,string activity, string residence, string food, string body_colour, string fur_colour, string animal_weight)
        : Animal(name, age,tall, activity, residence, food), body_colour(body_colour), fur_colour(fur_colour), animal_weight(animal_weight) {}

    void sleep()
    {
        cout << name << " is sleeping" << endl;
    }
    void MakeSound() override
    {
        cout << name << ": zzz" << endl;
    }
    string Ability() override
    {
        return name + "'s body colour is " + body_colour;
    }
    string Fur_Colour() override
    {
        return name + "'s fur colour is " + fur_colour;
    }
    string Animal_Weight() override
    {
        return name + "'s weight is " + animal_weight;
    }
private:
    string body_colour;
    string fur_colour;
    string  animal_weight;
};

class Giraffe : public Animal
{
public:

    Giraffe(string name, int age, string tall, string activity, string residence, string food, string eyes_colour, string fur_colour, string animal_weight)
        : Animal(name, age, tall, activity, residence, food), eyes_colour(eyes_colour), fur_colour(fur_colour), animal_weight(animal_weight){}

    void look()
    {
        cout << name << " is watching";
    }

    void MakeSound() override {
        cout << name << ": urrrr" << endl;
    }
    string Ability() override {
        return name + "'s eyes colour is " + eyes_colour;
    }
    string Fur_Colour() override {
        return name + "'s fur colour is " + fur_colour;
    }
    string Animal_Weight() override {
        return name + "'s weight is " + animal_weight;
    }

private:
    string eyes_colour;
    string fur_colour;
    string animal_weight;
};

class Panda : public Animal {
public:
    Panda(string name, int age, string tall,  string activity, string residence, string food, string eyes_colour, string fur_colour, string animal_weight)
        : Animal(name, age, tall, activity, residence, food), eyes_colour(eyes_colour), fur_colour(fur_colour), animal_weight(animal_weight){}

    void tell()
    {
        cout << name << "keep silence" << endl;
    }
    void MakeSound() override {
        cout << name << ": ..." << endl;
    }
    string Ability() override {
        return name + "'s eyes colour is " + eyes_colour;
    }
    string Fur_Colour() override {
        return name + "'s fur colour is " + fur_colour;
    }
    string Animal_Weight() override {
        return name + "'s weight is " + animal_weight;
    }
private:
    string eyes_colour;
    string fur_colour;
    string animal_weight;
    
};
class Cat : public Animal {
public:
    Cat(string name, int age,string tall,  string activity, string residence, string food, string eyes_colour, string fur_colour, string animal_weight)
        : Animal(name, age, tall, activity, residence, food), eyes_colour(eyes_colour), fur_colour(fur_colour), animal_weight(animal_weight){}

    void tell()
    {
        cout << name << "playing" << endl;
    }
    void MakeSound() override {
        cout << name << ": meeww" << endl;
    }
    string Ability() override {
        return name + "'s eyes colour is " + eyes_colour;
    }
    string Fur_Colour() override {
        return name + "'s fur colour is " + fur_colour;
    }
    string Animal_Weight() override {
        return name + "'s weight is " + animal_weight;
    }
private:
    string eyes_colour;
    string fur_colour;
    string animal_weight;

};

int main() {

    Zoo zoo;



    Parrot a("Kesha", 4,"1m", "eating", "Ottawa, Canada", "nuts", "blue", "green and yellow", "42kg");
    Giraffe b("Boris", 6,"3,5m", "looking for a victim", "Dubai, UAE", "leaves and eucalyptus", "brown", "orange", "1769kg");
    Panda c("Bob", 3, "3m", "working", "Tokio, Japan", "bamboo", "black", "black and white", "88kg");
    Cat d("Marusya", 1,"24cm", "studying", "Joensuu, Finland", "fish", "green", "gray", "3,8kg");



    zoo.addAnimal(&a);
    zoo.addAnimal(&b);
    zoo.addAnimal(&c);
    zoo.addAnimal(&d);



    zoo.infoAll();
    cout << "" << endl;
    zoo.feedAll();

    zoo.MakeSoundSmb("Kesha");
    cout << "" << endl;
   
    zoo.DanceSmb("Boris");
    zoo.JumpSmb("Giraffe");

    cout << endl;

    zoo.deleteAnimal("Kesha");

    zoo.feedAll();
    zoo.Stroke("Marusya");

    zoo.addAnimal(&a);
    zoo.PlaySmb("Kesha");

    zoo.deleteAnimal("Bob");
    zoo.MakeSoundSmb("Marusya");
   

    return 0;

}