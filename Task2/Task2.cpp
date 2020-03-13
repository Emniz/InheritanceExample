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
	int lvl;
public:
	MythicalAnimal(const string& _name, int _health, int _mana, int _endurance, string _animal) :Creature(_name, _health, _mana, _endurance), animal(_animal){}
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

class Human :public Creature
{
private:
	string weapone;
	int lvl;
public:
	Human(const string& _name, int _health, int _mana, int _endurance, string _weapone, int _lvl) :Creature(_name, _health, _mana, _endurance), weapone(_weapone), lvl(_lvl) {}
	Human(const Human& obj) : Creature(obj), weapone(obj.weapone), lvl(obj.lvl) {}
	Human(const string& _name, int _health, int _mana, int _endurance, int moveX, int moveY, string _weapone, int _lvl) :
		Creature(_name, _health, _mana, _endurance), weapone(_weapone), lvl(_lvl) {}
	~Human() {}
	void move(int x, int y) override 
	{
		Creature::_move(x, y);
		cout << "Human character moves on: " << getX() << ";" << getY() << endl;
	}
	void position() override
	{
		cout << "Human position: " << getX() << ";" << getY() << endl;
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << "\nHuman weapon: " << weapone << "\nlevel: " << lvl;
	}
};

class MagicCharacter :public Creature
{
private:
	string magichelper;
public:
	MagicCharacter(const string& _name, int _health, int _mana, int _endurance, string _magichelper) :Creature(_name, _health, _mana, _endurance), magichelper(_magichelper) {}
	MagicCharacter(const MagicCharacter& obj) : Creature(obj), magichelper(obj.magichelper) {}
	MagicCharacter(const string& _name, int _health, int _mana, int _endurance, int _moveX, int _moveY, string _magichelper) :
		Creature(_name, _health, _mana, _endurance, _moveX, _moveY), magichelper(_magichelper) {}
	~MagicCharacter() {}
	void move(int x, int y) override
	{
		Creature::_move(x, y);
		cout << "Magic character moves on: " << getX() << ";" << getY() << endl;
	}
	void position() override
	{
		cout << "Magic Character position: " << getX() << ";" << getY()<<endl;
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << "\nMagic Character: " << magichelper;
	}
};

class MagicItem :public ComputerGameObject
{
private:
	int damage;
	int strength;
public:
	MagicItem(const string& _name, int _damage, int _strength) :ComputerGameObject(_name), damage(_damage), strength(_strength) {}
	MagicItem(const MagicItem& obj) :ComputerGameObject(obj), damage(obj.damage), strength(obj.strength) {}
	~MagicItem()
	{
		cout << "Magic item deleted\n";
	}
protected:
	void position() override
	{
		cout << "Human has a magic item";
	}
	void _print()const override
	{
		ComputerGameObject::_print();
		cout << "\nDamage: " << damage << "\nStrength: " << strength;
	}
};

int main()
{
	MythicalAnimal dragon("Deathwing",1300, 250, 400, "Dragon");
	dragon.position();
	dragon.move(20, 50);
	dragon.print();
	cout << endl;
	Human Warrior("Dovakin", 100, 80, 150, "Glass sword", 11);
	Warrior.position();
	Warrior.move(10, 35);
	Warrior.print();
	cout << endl;
	MagicCharacter character("Ingrit", 100, 30, 300, "Ghost horse");
	character.position();
	character.move(10, 35);
	character.print();
	cout << endl;
	MagicItem item("Nightingale bow", 350, 100);
	item.print();
	cout << "\n\n";
}