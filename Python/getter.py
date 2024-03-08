class Myclass:
    def __init__(self, value):
        self._value = value
    
    def show(self):
        print(f"value is {self._value}")
    
    @property
    def ten_value(self):
        print("Inside getter function")
        return 10*self._value
    
    @ten_value.setter
    def ten_value(self,new_value):
        print("Inside setter function")
        self._value = new_value/10

obj = Myclass(10)
# obj.ten_value = 67
print(obj.ten_value)
# obj.show()