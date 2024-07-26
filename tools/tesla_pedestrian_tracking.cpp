/*
  Question description:
    Suppose vehicle and pedestrian are moving at a constant speed.
    Out job is to track all pedestrians with respect to vehicle frame and 
    detect if there any collision happens.
 */

#include <math.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Vehicle {
  float x_speed;
  float y_speed;
};

struct Pedestrian {
  float x_coord;
  float y_coord;
  float x_speed;
  float y_speed;
  const float radius = 3.f;  // 1 meter
  Pedestrian(float x_coord, float y_coord, float x_speed, float y_speed)
      : x_coord(x_coord),
        y_coord(y_coord),
        x_speed(x_speed),
        y_speed(y_speed) {}

  bool isCollide() const {
    return sqrt(x_coord * x_coord + y_coord * y_coord) < radius;
  }

  void updateCoord(float veh_x_speed, float veh_y_speed) {
    /* Regardless of whether the vehicle and pedestrian are moving in the same
     * direction or not, we can update the relative coordinates using the
     * following expression.
     */
    x_coord += (x_speed - veh_x_speed);
    y_coord += (y_speed - veh_y_speed);
  }

  float getDist() const { return x_coord * x_coord + y_coord * y_coord; }
  float getCollideRadius() const { return radius; }
};
float randomFloat(float low, float high) {
  return float(rand()) / float((RAND_MAX)) * (high - low) + low;
}
class PedestrianTracker {
 public:
  PedestrianTracker(int num_ped, float veh_x_speed, float veh_y_speed) {
    // init pedestrian objects
    for (int i = 0; i < num_ped; i++) {
      float x_speed = randomFloat(-1.f, 1.f);  // -1 to 1
      float y_speed = randomFloat(-1.f, 1.f);
      float x_coord = randomFloat(-10.f, 10.f);
      float y_coord = randomFloat(-10.f, 10.f);
      Pedestrian ped(x_coord, y_coord, x_speed, y_speed);
      pedestrians.push_back(ped);
    }

    // init vehicle object
    vehicle = {veh_x_speed, veh_y_speed};
  }
  void track() {
    for (int i = 0; i < pedestrians.size(); i++) {
      pedestrians[i].updateCoord(vehicle.x_speed, vehicle.y_speed);

      // Check if the distance between the pedestrian and the car is smaller
      // than the safety radius.
      if (pedestrians[i].isCollide()) {
        cout << "dist: " << setprecision(3) << pedestrians[i].getDist()
             << " meters => "
             << "ped id: " << i << " relative pedx: " << pedestrians[i].x_coord
             << ", relative pedy: " << pedestrians[i].y_coord << endl;
      }
    }
  }

 private:
  Vehicle vehicle;
  vector<Pedestrian> pedestrians;
};

int main() {
  PedestrianTracker ped_tracker(100, 2.f, 2.f);

  // run 20 iterations for testing
  for (int i = 0; i < 20; i++) ped_tracker.track();

  return 0;
}