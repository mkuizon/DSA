#include <iostream>
#include "Deque.h"
 
using namespace std;
int main()
{
   Deque<int> intDeque;
   Deque<string> stringDeque;
   Deque<float> floatDeque;

   intDeque.PushBack(3);
   intDeque.PushFront(2);
   intDeque.PushBack(4);

   stringDeque.PushFront("Make The");
   stringDeque.PushBack("First Things");
   stringDeque.PushBack("First");
   
   floatDeque.PushFront(2.5);
   floatDeque.PushBack(3.5);
   floatDeque.PushFront(1.5);
   floatDeque.PushBack(4.5);

   cout << "Emptying the queues:" << endl;
   while(!intDeque.IsEmpty()){
      cout << intDeque.PopFront() << endl;
   }
   
   while(!stringDeque.IsEmpty()){
      cout << stringDeque.Front() << endl;
      stringDeque.PopFront();
   }
   
   while(!floatDeque.IsEmpty()){
      cout << floatDeque.PopBack() << endl;
   }
   
   return 0;
}
