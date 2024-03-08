class emp:
    company_name = "TCS"
    def __init__(self,nm,sal):
        self.name = nm
        self.salary = sal
    
    @classmethod
    def dc(cls,e):
        print(cls.company_name)
        print("Inside class",e.name)

e1 = emp(input("Enter the name of e1\t"),input("Enter salary for e1\n"))
print("The name is ",e1.name," and salary is ",e1.salary)
emp.dc(e1)

