/*
 * @Description: Do not edit
 * @Date: 2020-04-27 14:10:26
 * @LastEditors: dylatos
 * @LastEditTime: 2020-04-27 16:38:23
 */
#include <string>
#include <iostream>

using namespace std;



string minSubStr(string str1,string str2, string &substr){
  int n1 = str1.size();
  int n2 = str2.size();
  if(n1!=0 && n2 !=0){
    // char eptChar = (char)"";
    char lastChar1 = str1[n1-1];
    char lastChar2 = str2[n2-1];
    if(lastChar1 == lastChar2){
      substr += lastChar1;
      str1 = str1.substr(0,n1-1);
      str2= str2.substr(0,n2-1);
      // minSubStr(str1,)
    }else{
    }
  }else{
    cout<<substr<<endl;
  }
  

}