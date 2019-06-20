#include <iostream>

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "usage: nibbler [width] [height]" << std::endl;
  } else {
    std::cout << *argv << std::endl;
  }
  return (0);
}