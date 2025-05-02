from collections import defaultdict

# hash map stores key-pair values O(1)

# key is mapped to index - immutable keys

city_map = {"Canada": ["Calgary", "Toronto", "Vancouver"]}
print(city_map)

# an awesome way to do it using defaultdic
city_map = defaultdict(list)
cities = ["Manila", "Cebu", "Butuan"]       
city_map["Philippines"] += cities

print(city_map)

city_map = {"Canada": ["Calgary", "Toronto", "Vancouver"],
            "Philippines": ["Manila", "Cebu", "Butuan"],
            "USA": ["Houston", "New York", "Los Angeles"]}     


city_map.keys()
city_map.values()