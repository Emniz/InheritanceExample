#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class ComputerGameObject
{
private:
	string name;
protected:
	ComputerGameObject(const string& _name) :name(_name) {}
	ComputerGameObject(const ComputerGameObject& obj) : name(obj.name) {}
	virtual ~ComputerGameObject()
	{
		cout << "Computer game object deleted" << endl; 
	}
	virtual void  _print() const
	{ 
		cout << "\nName: " << name; 
	}
public:
	void  print() const
	{
		cout << typeid(*this).name() << ": ";
		_print();
		cout <<endl;
	}
	virtual void position() = 0;
};

class Creature :public ComputerGameObject
{
private:
	int health;
	int mana;
	int endurance;
	int moveX;
	int moveY;
public:
	Creature(const string& _name, int _health,int _mana, int _endurance) :ComputerGameObject(_name), health(_health), mana(_mana), endurance(_endurance), moveX(0), moveY(0) {}
	Creature(const Creature& obj) :
		ComputerGameObject(obj), health(obj.health), mana(obj.mana), endurance(obj.endurance), moveX(obj.moveX), moveY(obj.moveY){}
	Creature(const string& _name, int _health, int _mana, int _endurance, int _moveX, int _moveY) :
		ComputerGameObject(_name), health(_health), mana(_mana), endurance(_endurance), moveX(_moveX), moveY(_moveY) {}
	void _move(int x, int y) 
	{
		moveX += x;
		moveY += y;
	}
	int getX() 
	{
		return moveX; 
	}
	int getY() 
	{ 
		return moveY;
	}
	~Creature() 
	{ 
		cout << "Creature deleted" << endl; 
	}
protected:
	virtual void move(int x, int y) = 0;
	void  _print() const override
	{
		ComputerGameObject::_print();
		cout << "\nHealth: " << health <<"\nMana: "<< mana << "\nEndurance: " << endurance <<"\nX: " << moveX << "\nY: " << moveY ;
	}
};

class MythicalAnimal :public Creature
{
private:
	string animal;
public:
	MythicalAnimal(const string& _name, int _mana, int _health, int _endurance, string _animal) :Creature(_name, _health, _mana, _endurance), animal(_animal){}
	MythicalAnimal(const MythicalAnimal& obj) : Creature(obj), animal(obj.animal) {}
	MythicalAnimal(const string& _name, int _health, int _mana, int _endurance,  string _animal, int _moveX, int _moveY) :
		Creature(_name, _health, _mana, _endurance, _moveX, _moveY), animal(_animal) {}
	~MythicalAnimal() {}
	void move(int x, int y) override 
	{
		Creature::_move(x, y);
		cout << "Mythical animal moves on: " << getX() << ";" << getY() << endl;
	}
	void position()
	{
		cout << "Position mythical animal: " << getX() << ";" << getY() <<endl;
	}
protected:
	void _print()const override
	{
		Creature::_print();
		cout << "\nMythical animal: " << animal;
	}
};

int main()
{
	MythicalAnimal dragon("Deathwing",100, 100, 200, "Dragon");
	dragon.position();
	dragon.move(20, 50);
	dragon.print();
}