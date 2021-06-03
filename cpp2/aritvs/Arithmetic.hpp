#pragma once
class Arithmetic
{
protected:
	float a;
	float b;
public:
	Arithmetic(float, float);
	float Calculate(void);
};

class Add:public Arithmetic{
public:
	Add(float a, float b) :Arithmetic(a, b) {}
};

class Sub :public Arithmetic {
public:
	Sub(float a, float b) :Arithmetic(a, b) {}
};
class Div :public Arithmetic {
public:
	Div(float a, float b) :Arithmetic(a, b) {}
};
class Mul :public Arithmetic {
public:
	Mul(float a, float b) :Arithmetic(a, b) {}
};
