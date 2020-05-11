/*
 * @Description: Do not edit
 * @Date: 2020-04-25 20:34:51
 * @LastEditors: dylatos
 * @LastEditTime: 2020-04-25 22:30:32
 */
// #include "bubble.cpp"

// void swap(int & before,int & after){
//     int tmp;
//     tmp = after;
//     after = before;
//     before = tmp;
// }
void swap(int & before,int & after);
void reserve(int array[],int low,int high){
  if(low<high){
    swap(array[low],array[high]);
    reserve(array,low+1,high-1);
  }
}
