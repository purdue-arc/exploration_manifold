struct mapHalfEdge
{
  mapVertex * baseVertex;
  mapQuad * parentQuad;

  mapHalfEdge * prevEdge;
  mapHalfEdge * twinEdge;
  mapHalfEdge * nextEdge;
};
struct mapVertex
{
  double position_x;
  double position_y;
  double position_z;
};
struct mapQuad
{
  double normalAngle_rad;
  double variance;
  double certainty;
};
