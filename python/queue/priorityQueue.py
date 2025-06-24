class PriorityQueueBase:

    class _Item:
        __slots__ = '_key', '_value' # composition design pattern

        def __init__(self, k, v): #key and value
            self._key = k
            self._value = v

        def __It(self, other):
            return self._key <other._key # comparing items based on their key