
class Point2D{
  public:
    int mx, my;
    Point2D(int x, int y):mx(x),my(y){}

    Point2D midPoint(Point2D p2){
      return Point2D((p2.mx+mx)/2, (p2.my+my)/2);

    }
    double gradient(Point2D p2){

      return (p2.my-my)/(p2.mx-mx);
    }
};