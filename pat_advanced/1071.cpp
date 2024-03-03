#include <cstdio>
#include <iostream>
#include <map>
#include <string>

bool check(char c){
  if(c >= '0' && c<='9') return true;
  if(c >= 'a' && c<='z') return true;
  if(c >= 'A' && c<='Z') return true;
  return false;
}

int main (int argc, char *argv[]) {
  std::map<std::string, int> mp;
  std::string line;
  std::getline(std::cin, line);

  std::string word;
  for(int i = 0; i<line.length(); i++){
    if(word == "" && !check(line[i]))
      continue;
    if(check(line[i])){
      char c = line[i];
      if(c >= 'A' && c <= 'Z'){
        c += 'a'-'A';
      }
      word += c;
    } else {
      if(mp.find(word) == mp.end())
        mp[word] = 0;
      mp[word]++;
      word = "";
    }
  }
  mp[""] = 0;
  std::string res;
  int count = -1;
  for(std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++){
    if(it->second >= count){
      res = it->first;
      count = it->second;
    }
  }
  printf("%s %d", res.c_str(), count);
  return 0;
}
