#pragma once
class Arithmetic
{
private:
	float a;
	float b;
public:
	Arithmetic();
	Arithmetic(float, float);
	float Calculate(void);
};

class Sum:public Arithmetic{
public:
	Sum(){};
};
class Sub:public Arithmetic{
public:
	Sub();	
};

class Mul:public Arithmetic{
public:
	Mul(){}
};
class Div:public Arithmetic{
public:
	Div();
};