//
// Created by brigidoalvarado on 16/12/24.
//

#ifndef ASSET_H
#define ASSET_H

#include <iostream>
using namespace std;

class Asset
{
  private:
  string name;
  string description;
  string id;
  int rentTime;
  bool rented;

  public:
  Asset();
  void setName(string name);
  void setDescription(string description);
  void setId(string id);
  void setRentTime(int rentTime);
  void setRented(bool rented);

  string getName();
  string getDescription();
  string getId();
  int getRentTime();
  bool getRented();
};
#endif //ASSET_H