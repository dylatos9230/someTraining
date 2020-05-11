/*
 * @Description: Do not edit
 * @Date: 2020-04-26 16:29:55
 * @LastEditors: dylatos
 * @LastEditTime: 2020-04-27 13:46:58
 */
#include <map>
#include "head.h"

using namespace std;
int fib(int i)
{
  int f = 1, g = 1;
  if (i > 0 && i < 3)
    return 1;
  i = i - 2;
  while (0 < i--)
  {
    g = f + g;
    f = g - f;
  }
  return g;
}


int fib2(int n, FibMap &fibMap)
{
  int result, beforeOne, beforeTwo, itemOne, itemTwo;
  
  // Figure out the first two items
  if (n <= 0)
    return 0;
  if (n > 0 && n < 3)
    return 1;
  // Judgments for making sure whether the item exist in
  // the map
  itemOne = n - 1;
  itemTwo = n - 2;
  if(fibMap.count(itemOne)){
    beforeOne = fibMap[itemOne];
  }
  else{
    beforeOne = fib2(itemOne,fibMap);
    fibMap[itemOne] = beforeOne;
  }
  
  if (fibMap.count(itemTwo))
    beforeTwo = fibMap[itemTwo];
  else{
    beforeTwo = fib2(itemTwo,fibMap);
    fibMap[itemTwo] = beforeTwo;
  }
  result = beforeOne + beforeTwo;
  return result;
}
