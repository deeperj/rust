#pragma once
class Arithmetic
{
protected:
	float a;
	float b;
public:
	Arithmetic();
	Arithmetic(float, float);
	float Calculate(void);
};

class Sum:public Arithmetic{
public:
	Sum(float, float);
	float Calculate(void);
};
class Sub:public Arithmetic{
public:
	Sub(float, float);	
	float Calculate(void);
};

class Mul:public Arithmetic{
public:
	Mul(float a, float);
	float Calculate(void);
};

class Div:public Arithmetic{
public:
	Div(float a, float b);
	float Calculate(void);
};