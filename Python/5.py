class Book:
    def __init__(self,title,pages):
        self.title = title
        self.pages = pages
    
    def __add__(self,others):
        t = Book("all books",self.pages+others.pages)
        return t
    
    def __str__(self):
        return str(self.pages)
    
b1 = Book("One indian girl",300)
b2 = Book("Making india awesome",200)
b3 = Book("Half girlfriend ",400)

print("Total number of pages",b1+b2+b3)