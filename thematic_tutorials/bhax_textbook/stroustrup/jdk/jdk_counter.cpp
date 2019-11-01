// g++ jdk_counter.cpp -o jdk_counter -lboost_system -lboost_filesystem

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::filesystem;

long long counter;
std::vector<std::string> exclude = {"module-info.java", "package-info.java"};

void padding(int x){
  for(int i = 0; i < x; i++)
    std::cout << "   ";
}

void countJavaFiles(path pathh){

  recursive_directory_iterator p(pathh);
  recursive_directory_iterator end;

  while(p != end){

    std::vector<std::string> result;
    boost::split(result, p->path().string(), boost::is_any_of("/"));
    std::string j = ".java";

    if( is_directory(p->path()) ){

      padding(result.size()-1);
      std::cout << "/" << result[result.size()-1] << std::endl;

    } else if( (std::find(exclude.begin(), exclude.end(), p->path().filename()) == exclude.end()) && (j.compare(p->path().extension().string()) == 0) ){

      counter++;
      padding(result.size()-1);
      std::cout << result[result.size()-1] << std::endl;

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
