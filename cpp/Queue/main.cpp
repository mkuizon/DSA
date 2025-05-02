#include <iostream>
#include "queue.h"
 
using namespace std;
int main()
{
   Queue<int> intQueue;
   Queue<string> stringQueue;

   intQueue.Enqueue(2);
   intQueue.Enqueue(3);
   intQueue.Enqueue(4);

   stringQueue.Enqueue("Make The");
   stringQueue.Enqueue("First Things");
   stringQueue.Enqueue("First");

   cout << "Emptying the queues:" << endl;
   while(!intQueue.IsEmpty()){
      cout << intQueue.Dequeue() << endl;
   }
   
   while(!stringQueue.IsEmpty()){
      cout << stringQueue.Front() << endl;
      stringQueue.Dequeue();
   }
   
   return 0;
}
