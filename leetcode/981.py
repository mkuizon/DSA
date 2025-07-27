# 981. Time Base Key-Value Store
from collections import defaultdict
class TimeMap:

    def __init__(self):
        # [key, [value, time], [value, time]]
        '''
        k = {}
        "key" = [[value, time], [value, time]]

        '''
        self.k = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.k[key].append([value,timestamp])

    def binary(self,arr,low, high, target):
        if low > high:
            print(f"low: {low}, high: {high}")
            return high
        mid = low + (high - low) // 2
     
        if arr[mid][1] == target:
            return mid
        
        if arr[mid][1] < target:
            return self.binary(arr, mid+1, high, target)
        else:
            return self.binary(arr, low, mid-1, target)



    def get(self, key: str, timestamp: int) -> str:
        if key not in self.k.keys():
            return ""

        idx = self.binary(self.k[key], 0, len(self.k[key])-1, timestamp)
        
        if idx == -1:
            return ""

        
        return self.k[key][idx][0]
    

obj = TimeMap()
obj.set("animal", "monkey", 1)
print(obj.get("animal", 1))
obj.set("animal","wolf", 3)
print(obj.get("animal",2))