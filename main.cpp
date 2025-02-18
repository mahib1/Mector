#include <iostream>
#include <unordered_map>
#include <vector>
#include "arrayBuilder.h"

#define str std::string
#define upi std::unique_ptr<int>

ArrayClassBuilder_M(upi);

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

ArrayClassBuilder_N(str);
ArrayClassBuilder_N(myType);
ArrayClassBuilder_N(myType2); 
ArrayClassBuilder_N(umii);

int main() {
  ArrayN(str) stringArray;
  stringArray.push_back("HEHEHE");
  ArrayN(str) stringArray2;


  for(int i = 0; i < 32; i++) {
    stringArray.push_back("hehehe" + std::to_string(i));
  }

  stringArray2 = stringArray;

  stringArray2.reverse();

  for(int i = 0; i < stringArray2.size(); i++) {
    std::cout << stringArray2[i] << std::endl;
  }

  for(auto i = stringArray.begin(); i != stringArray.end(); i++) {
    std::cout << *i << std::endl;
  }

  stringArray[0] = "MAHIB";
  std::cout << stringArray[0] << std::endl;


  ArrayN(myType) myType1Array;
  char d[] = "MAHIB";
  myType1Array.push_back({5, 6, "hehehe", d});
  std::cout << myType1Array[0].d << std::endl;


  ArrayN(myType2) myTypeArray2;
  myType ele = {7, 8, "eheheheh", d};
  myTypeArray2.push_back({5, 6, "HEHEHHEHE", d, &ele});

  std::cout << myTypeArray2[0].mt->d << std::endl;

  ArrayN(umii) mapArray;
  umii hehe1 = umii ( {{1,2} , {3,4}});
  mapArray.push_back(hehe1);

  std::vector<std::unordered_map<int, int>> m;
  m.push_back(hehe1);

  return 0;
}
