// Helen fomula: get the 3 edges of a triangle,
// and calculate the area of the triangle.
double Halen(double a, double b, double c) {
  double p = (a + b + c) / 2;                       // temporary variable
  double area = sqrt(p*(p - a)*(p - b)*(p - c));    // use the formula
  return area;
}
