#include "exploration_manifold/Plot3D.h"

Plot3D::Plot3D()
{
  numObjects = 0;
  max_x = 10;
  max_y = 10;
  max_z = 10;
  min_x = -10;
  min_x = -10;
  min_x = -10;

  sendRanges();
  updatePlot();
}

~Plot3D::Plot3D() = default;

void Plot3D::addPolygon(Polygon poly){
  numObjects++;
  plot << "set object " << numObjects << " polygon from '-' to '-' to '-' to '-' to '-' fillsytle transparent solid 0.5\n";
  gp.send1d(poly.v1);
  gp.send1d(poly.v2);
  gp.send1d(poly.v3);
  gp.send1d(poly.v4);
  gp.send1d(poly.v1);

  if( updateRanges(poly.v1) || updateRanges(poly.v2) || updateRanges(poly.v3) || updateRanges(poly.v4)){
    sendRanges();
  }
  updatePlot();
}

void Plot3D::updatePlot(){
  plot << "splot " << numObjects << "/0 notitle\n";
}

void Plot3D::clearPlot(){
  plot << "clear\n";
  numObjects = 0;
}

bool Plot3D::updateRanges(std::array<double, 3> vertex){
  bool change = false;
  if (vertex[0] > x_max)
  {
    x_max = vertex[0];
    change = true;
  }
  else if (vertex[0] < x_min)
  {
    x_min = vertex[0];
    change = true;
  }
  if (vertex[1] > y_max)
  {
    y_max = vertex[1];
    change = true;
  }
  else if (vertex[1] < y_min)
  {
    y_min = vertex[1];
    change = true;
  }
  if (vertex[2] > z_max)
  {
    z_max = vertex[2];
    change = true;
  }
  else if (vertex[2] < z_min)
  {
    z_min = vertex[2];
    change = true;
  }
  return change;
}

void Plot3D::sendRanges(){
  plot << "set xrange [" << min_x << ":" << max_x << "]\n";
  plot << "set yrange [" << min_y << ":" << max_y << "]\n";
  plot << "set zrange [" << min_z << ":" << max_z << "]\n";
}
