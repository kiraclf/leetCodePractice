using namespace std;

class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small) {
    bigCount = big;
    mediumCount = medium;
    smallCount = small;
  }

  bool addCar(int carType) {
    switch (carType)
    {
    case 1:
      return addCarAction(bigCount);
      break;
    case 2:
      return addCarAction(mediumCount);
      break;
    case 3:
      return addCarAction(smallCount);
      break;
    default:
      break;
    }
    return false;
  }

  bool addCarAction(int &totalCount) {
    if (totalCount > 0) {
      totalCount--;
      return true;
    }
    return false;
  }

 private:
  int bigCount;
  int mediumCount;
  int smallCount;
};