//Zachary Palmer and Scott Giorlando
#include "EditDistance.hpp"
#include <iostream>
#include <string>
#include <sstream>

ED::ED(std::string str_1, std::string str_2)
{
  s1 = str_1;
  s2 = str_2;
  s1L = s1.length();
  s2L = s2.length();
  Matrix = new int*[s1L+1];
  for(int i = 0; i < s1L+1; ++i)
  {
    Matrix[i] = new int[s2L+1];
  }
}

ED::~ED()
{
  if(Matrix != NULL)
  {
    for(int i = 0; i < s1L+1 ; i++)
    {
      delete[] Matrix[i];
    }
    delete[] Matrix;
  }
  Matrix = NULL;
  s1L = 0;
  s2L = 0;
}

int ED::optimal()
{
  int num = 0;
  for(int i = s1L; i >= 0; i--)
  {
    Matrix[i][s2L] = num;
    num = num + 2;
  }

  for(int i = s2L - 1; i >= 0; i--)
  {
    Matrix[s1L][i] = Matrix[s1L][i+1]+2;
  }

  for(int i = s1L - 1; i >= 0; i--)
  {
    for (int e = s2L - 1; e >= 0; e--)
    {
      if (s1[i] == s2[e])
      {
        Matrix[i][e] = std::min(std::min(Matrix[i+1][e+1], Matrix[i][e+1]+2), Matrix[i+1][e]+2);
      } else
      {
        Matrix[i][e] = std::min(std::min(Matrix[i+1][e+1]+1, Matrix[i][e+1]+2), Matrix[i+1][e]+2);
      }
    }
  }
  return Matrix[0][0];
}

std::string ED::alignTable()
{
  int row = 0;
  int col = 0;
  int x = std::max(s1L, s2L);
  std::stringstream output;

  for (int i = 0; i < x; i++)
  {
  if (Matrix[row][col] == Matrix[row+1][col+1] && s1[row] == s2[col])
    {
      output << s1[row] << " " << s2[col] << " 0\n";
      row++;
      col++;
    }
    else if(Matrix[row][col] == Matrix[row+1][col+1]+1 && s1[row] != s2[col])
    {
      output << s1[row] << " " << s2[col] << " 1\n";
      row++;
      col++;
    }
    else if(Matrix[row][col] == Matrix[row+1][col]+2)
    {
      output << s1[row] << " - 2\n";
      row++;
    }
    else if(Matrix[row][col] == Matrix[row][col+1]+2)
    {
      output << "- " << s2[col] << " 2\n";
      col++;
    }
  }

  while(row < s1L && col < s2L)
  {
    output << s1[row] << " " << s2[col] << " 0\n";
    row++;
    col++;
  }

  if(col < s2L)
  {
    for(int i = col; i < s2L; i++)
    output << "- " << s2[i] << " 2\n";
  }

  if(row < s1L)
  {
    for(int i = row; i < s1L; i++)
    output << s1[i] << " - 2\n";

  }
  return output.str();
}
