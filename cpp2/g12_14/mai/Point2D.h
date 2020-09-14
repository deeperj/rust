
class Point2D {
  private:
  
  double mx;
  double my;
  
  public:
  
  Point2D(double X = 0, double Y = 0);
  double getValuemx() const;
  void setValuemx(double X);
  double getValuemy() const;
  void setValuemy(double Y);
  Point2D(Point2D &p1);
  Point2D midPoint(Point2D &p2);
};
