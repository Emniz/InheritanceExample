#include "stdafx.h"
#include <iostream>
using namespace std;

class B1 {
	int a;
public:
	B1() { cout << "object of " << typeid(*this).name() << " was created" << endl; }
	B1(int x) :B1() { a = x; }
	~B1() { cout << "object of " << typeid(*this).name() << " was destroyed" << endl; }
};
class D1 : public B1{
	int b;
public:
	D1(int x, int y) : B1(y)
	{
		b = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	};
	~D1() { cout << "object of " << typeid(*this).name() << " was destroyed" << endl; }
};
class D2 : private B1 {
	int c;
public:D2(int x, int y) :B1(y)
{
	c = x;
    cout << "object of " << typeid(*this).name() << " was created\n";
}
	~D2() { cout << "object of " << typeid(*this).name() << " was destroyed" << endl; }
};
class B2 {
	int d;
public:
	B2() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B2(int z)
	{
		d = z;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~B2() { cout << "object of " << typeid(*this).name() << " was destroyed" << endl; }
};
class D4 : public D1, public D2, public B2{
	int e;
public:
	D4(int x, int y, int z, int i, int j, int k) :D1(y,z),D2(i,j),B2(k)
	{
		e = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D4() { cout << "object of " << typeid(*this).name() << " was destroyed" << endl; }
};
int main()
{
	D4(2,3,5,6,7,9);
}

