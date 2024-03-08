import time
class Emloyee:
    def __init__(self,name,salary):
        self.name = name
        self.salary = salary
    
    def display(self):
        print(f"name is {self.name}\nsalary is {self.salary}")
    
    def __del__(self):
        print("Destructor is called")

e1 = Emloyee("Shantanu",50000)
print(__dict__(Emloyee))
# e2=e1

# del e1
# print("After deleting object e1")

# time.sleep(5)
    

