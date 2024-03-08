class c1:
    '''Calling class 1'''
    def x(self):
        print("c1.x")
    
    def __str__(self):
        return str(45)
    
class c2():
    def x(self):
        print("c2.x")
class c3(c2,c1):
    def x(self):
        print("c2.x")



class c2(c1):
    def x(self):
        print("c2.x")


o = c2()
print(c3.__bases__)
