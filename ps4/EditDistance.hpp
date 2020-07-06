//Zachary Palmer and Scott Giorlando
#ifndef EDITDISTANCE_HPP_INCLUDED
#define EDITDISTANCE_HPP_INCLUDED

#include <string>

class ED
{
public:
  ED(std::string str_1, std::string str_2);
  int optimal();
  std::string alignTable();
  ~ED();

private:
  std::string s1, s2;
  int s1L, s2L;
  int **Matrix;
};

#endif
