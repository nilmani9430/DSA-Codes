class person:
    def __init__(self,n,o):
        # print("Hey I am person")
        self.name=n
        self.occupation = o

    name = ""
    occupation = ""
    networth = 10
    def info(self):
        print(f"{self.name} is a {self.occupation}")

a=person("Harry","Developer")
b=person("Divya","HR")
a.info()
b.info()

# a.name="Nil"
# a.occupation = "Accountant"
# a.info()                  