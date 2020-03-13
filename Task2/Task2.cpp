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
	virtual ~ComputerGameObject() { cout << "Computer game object deleted" << endl; }
	virtual void  _print() const { cout << "name: " << name; }
public:
	virtual void draw() = 0;
	void  print() const
	{
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")"<<endl;
	}
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
	Creature(const string& _title, int _health,int _mana, int _endurance) :ComputerGameObject(_title), health(_health), mana(_mana), endurance(_endurance), moveX(0), moveY(0) {}
	Creature(const Creature& obj) :
		ComputerGameObject(obj), health(obj.health), mana(obj.mana), endurance(obj.endurance), moveX(obj.moveX), moveY(obj.moveY){}
	Creature(const string& _title, int _health, int _mana, int _endurance, int _moveX, int _moveY) :
		ComputerGameObject(_title), health(_health), mana(_mana), endurance(_endurance), moveX(_moveX), moveY(_moveY) {}
	void _move(int X, int Y) 
	{
		moveX = X;
		moveY = Y;
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
		cout << ", health: " << health <<", mana: "<< mana << ", endurance: " << endurance <<", X: " << moveX << ", Y: " << moveY ;
	}
};


int main()
{

	return 0;
}