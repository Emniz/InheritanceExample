#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class creature
{
private:
	string title;
	double mass; //kg
protected:
	creature() : mass(0.0) {}
	creature(const creature& obj) : title(obj.title), mass(obj.mass) {}
	creature(const string& _title, double _mass) : title(_title), mass(_mass) {}
	// ���������� (�������� ��� �����������)
	virtual ~creature() { cout << "creature deleted" << endl << endl; }
	// ����������� ������� ��� ������ ���������� �� ������� 
	virtual void _print() const { cout << "title: " << title << ", mass: " << mass; }
public:
	// �������� ������� ��� ������ ���������� �� �������
	void print() const
	{
		cout << typeid(*this).name() << ": (";
		// ����� ����������� �������
		// �.�. ������� _print �����������, ���������� ��� �����
		// �� ������ �� �������� ������, �� � �� �����������,
		// � ����������� �� ����, ��� ������ ������� �������������� �����
		_print();
		cout << ")" << endl;
	}
	double get_mass() const
	{
		return mass;
	}
};

// ����� animal ����������� �� ������ creature
class animal : public creature
{
private:
	double speed; //m/s
public:
	animal() : creature() {}
	animal(const animal& obj) : creature(obj), speed(obj.speed) {}
	animal(const string& _title, double _mass, double _speed)
		: creature(_title, _mass), speed(_speed) {}
	~animal() { cout << "animal deleted" << endl; }
protected:
	// ����������� ������� _print ���������������� � ����������� //������
	void _print() const
	{
		creature::_print();
		cout << ", speed: " << speed;
	}
public:
	double get_speed() const
	{
		return speed;
	}
};

// ����� bird ����������� �� ������ animal
class bird : virtual public animal
{
private:
	double topfly; //km
public:
	bird() : animal() {}
	bird(const bird& obj) : animal(obj), topfly(obj.topfly) {}
	bird(const string& _title, double _mass, double _speed, double _topfly)
		: animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() { cout << "bird deleted" << endl; }
protected:
	// ����������� ������� _print ���������������� � ������ bird
	void _print() const
	{
		animal::_print();
		cout << ", topfly: " << topfly;
	}
};

// ����� fish ����������� �� ������ animal
class fish : public animal
{
private:
	double maxdeep; //km
public:
	fish() : animal() {}
	fish(const fish& obj) : animal(obj), maxdeep(obj.maxdeep) {}
	fish(const string& _title, double _mass, double _speed, double _maxdeep)
		: animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish() { cout << "fish deleted" << endl; }
protected:
	// ����������� ������� _print ���������������� � ������ fish
	void _print() const
	{
		animal::_print();
		cout << ", maxdeep: " << maxdeep;
	}
};
class predator : virtual public animal
{
protected:
	predator() {}
public:
	~predator() {}
	// ����� ����������� ������� hunt ����� ���������� 
	// ����������� ����������� �������,
	// ������� �� ������� ����������� �� ������ (obj)
	virtual bool hunt(const animal& obj) = 0;
	// �.�. hunt ����� �����������, ����� predator �������� �����������
};

// ������������ ������������� ������������, �.�. ���� � � �����, � ������
class eagle : public bird, public predator
{
public:
	eagle() : bird() {}
	eagle(const eagle& obj)
		: bird(obj),
		// ��-�� ������������ ������������, ��� �������� ����������
		// � ����������� ������ animal, ��� ���������� ������� ����
		animal(obj) {}
	eagle(double _mass, double _speed, double _topfly)
		: bird("", 0, 0, _topfly),
		// ����������
		animal("����", _mass, _speed) {}
	bool hunt(const animal& obj)
	{
		return obj.get_mass() < get_mass()
			&& obj.get_speed() < get_speed();
	}
};

int main()
{
	setlocale(0, "Rus");
	bird raven("������", 0.3, 10, 0.1);
	fish hammerhead("���� - �����", 150, 5, 0.5);
	raven.print();
	hammerhead.print();
	// ������������ �������� ������� ������ eagle,
	// ������ ������������ ��� ������ �� ������ ������ predator,
	// �������� ��������, �.�. eagle �������� ����������� ��� predator
	predator &eagle1 = *new eagle(1, 100, 1);
	cout << "Eagle vs raven : " << eagle1.hunt(raven) << endl;
	cout << "Eagle vs hammerhead : " << eagle1.hunt(hammerhead) << endl;
	cout << endl;
	// �������� ����������� ���������� ������
	delete &eagle1;
	return 0;
}