#include <iostream>
#include <unordered_map>
#include "arrayBuilder.h"

#define str std::string

typedef struct {
  int a;
  int b;
  std::string c;
  char *d;
} myType;

typedef struct {
  int a;
  int b;
  std::string c;
  char *d;
  myType *mt;
} myType2;

#define umii std::unordered_map<int,int>

ArrayClassBuilder(str);
ArrayClassBuilder(myType);
ArrayClassBuilder(myType2); 
ArrayClassBuilder(umii);

int main() {
  Array(str) stringArray;
  stringArray.push_back("HEHEHE");

  for(int i = 0; i < 32; i++) {
    stringArray.push_back("hehehe" + std::to_string(i));
  }

  for(int i = 0; i < stringArray.size(); i++) {
    std::cout << stringArray[i] << std::endl;
  }

  for(auto i = stringArray.begin(); i != stringArray.end(); i++) {
    std::cout << *i << std::endl;
  }

  stringArray[0] = "MAHIB";
  std::cout << stringArray[0] << std::endl;


  Array(myType) myType1Array;
  char d[] = "MAHIB";
  myType1Array.push_back({5, 6, "hehehe", d});
  std::cout << myType1Array[0].d << std::endl;


  Array(myType2) myTypeArray2;
  myType ele = {7, 8, "eheheheh", d};
  myTypeArray2.push_back({5, 6, "HEHEHHEHE", d, &ele});

  std::cout << myTypeArray2[0].mt->d << std::endl;

  Array(umii) mapArray;
  umii hehe1 = umii ( {{1,2} , {3,4}});
  mapArray.push_back(hehe1);
  return 0;
}
