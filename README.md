# Exploration Manifold

## Purpose
This library stores a 3D mesh manifold used to track exploration and pathfinding of an unknown environment.

## Mesh Storage Implementation
This is implemented via a half-edge method of storing mesh data. Additionally, polygons are explicitly modeled so that they can contain exploration specific data.

## Path Finding Implementation
The path finding is implemented Control RRT.
