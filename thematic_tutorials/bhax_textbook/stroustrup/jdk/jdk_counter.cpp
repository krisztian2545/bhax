// g++ jdk_counter.cpp -o jdk_counter -lboost_system -lboost_filesystem

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <fstream>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

long long counter;
std::vector<std::string> exclude = {"module-info.java", "package-info.java"};

void countJavaFiles(path pathh){

  recursive_directory_iterator p(pathh);
  recursive_directory_iterator end;
  while(p != end){

    if( !is_directory(p->path()) && (std::find(exclude.begin(), exclude.end(), p->path().filename()) == exclude.end()) ){
      counter++;
      std::cout << p->path().string() << " : " << counter << std::endl;
    }

    ++p;

  }

}

int main(){

  std::string root = "/home/krisztiann/Downloads/javalib/src";
  counter = 0;

  path p (root);
  countJavaFiles(p);
  std::cout << "counted java files: " << counter << std::endl;

}
