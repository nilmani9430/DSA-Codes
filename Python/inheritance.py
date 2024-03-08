class Employee:
    def __init__(self, name, id):
        self.name = name
        self.id = id
    
    def showDetails(self):
        print(f"The name of the employee: {self.id} is {self.name}")

    @staticmethod
    def add(a,b):
        return a+b

class Programmer(Employee):
    def showLanguage(self):
        print("The default language is python")

# Creating objects for employees
e = Employee("Rohan Das",420)
e.showDetails()
print(Employee.add(2,3))