#include "exploration_manifold/Plot3D.h"
#include <sstream>

Plot3D::Plot3D()
{
  numObjects = 0;
  max_x = 10;
  max_y = 10;
  max_z = 10;
  min_x = -10;
  min_x = -10;
  min_x = -10;

  plot << "set xyplane at 0\n";

  sendRanges();
  updatePlot();
}

Plot3D::~Plot3D() = default;

void Plot3D::addPolygon(Polygon poly){
  numObjects++;
  plot << "set object " << numObjects << " polygon from "
    << formatVertex(poly.vertex_1) << " to "
    << formatVertex(poly.vertex_2) << " to "
    << formatVertex(poly.vertex_3) << " to "
    << formatVertex(poly.vertex_4) << " to "
    << formatVertex(poly.vertex_1) << " fillstyle transparent solid 0.5\n";

  if( updateRanges(poly.vertex_1) || updateRanges(poly.vertex_2) || updateRanges(poly.vertex_3) || updateRanges(poly.vertex_4)){
    sendRanges();
  }
  updatePlot();
}

void Plot3D::updatePlot(){
  plot << "splot " << numObjects << "/0 notitle" << std::endl;
}

void Plot3D::clearPlot(){
  plot << "clear" << std::endl;
  numObjects = 0;
}

bool Plot3D::updateRanges(std::array<double, 3> vertex){
  bool change = false;
  if (vertex[0] > max_x)
  {
    max_x = vertex[0];
    change = true;
  }
  else if (vertex[0] < min_x)
  {
    min_x = vertex[0];
    change = true;
  }
  if (vertex[1] > max_y)
  {
    max_y = vertex[1];
    change = true;
  }
  else if (vertex[1] < min_y)
  {
    min_y = vertex[1];
    change = true;
  }
  if (vertex[2] > max_z)
  {
    max_z = vertex[2];
    change = true;
  }
  else if (vertex[2] < min_z)
  {
    min_z = vertex[2];
    change = true;
  }
  return change;
}

void Plot3D::sendRanges(){
  plot << "set xrange [" << min_x << ":" << max_x << "]\n";
  plot << "set yrange [" << min_y << ":" << max_y << "]\n";
  plot << "set zrange [" << min_z << ":" << max_z << "]\n";
}

std::string Plot3D::formatVertex(std::array<double, 3> vertex)
{
  std::ostringstream oss;
  oss << vertex[0] << ", " << vertex[1] << ", " << vertex[2];
  return oss.str();
}
