#include "gnuplot-iostream.h"
#include <array>
#include <string>

class Plot3D{
public:
  struct Polygon
  {
    std::array<double, 3> vertex_1;
    std::array<double, 3> vertex_2;
    std::array<double, 3> vertex_3;
    std::array<double, 3> vertex_4;
    Polygon(std::array<double, 3> v1, std::array<double, 3> v2, std::array<double, 3> v3, std::array<double, 3> v4)
    {
      vertex_1 = v1;
      vertex_2 = v2;
      vertex_3 = v3;
      vertex_4 = v4;
    }
  };

  Plot3D();
  ~Plot3D();

  void addPolygon(Polygon poly);
  void clearPlot();
  void closePlot();

private:
  void updatePlot();
  bool updateRanges(std::array<double, 3> vertex);
  void sendRanges();
  std::string formatVertex(std::array<double, 3> vertex);

  Gnuplot plot;
  unsigned int numObjects;
  double max_x;
  double max_y;
  double max_z;
  double min_x;
  double min_y;
  double min_z;
};
