
class Complex{
private:
double mReal;
double mImag;
public:
Complex(double r, double i){
mReal=r;
mImag=i;
}
Complex add(Complex no);
Complex sub(Complex no);
Complex multiply(Complex no);
Complex division(Complex no);
double Real(){return mReal;}
double Imag(){return mImag;}
};