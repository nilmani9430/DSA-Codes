def greet(fx):
    def mfx(*args,**kwargs):
        print("Good Morning")
        fx(*args,**kwargs)
        print("Thank for using this function")
    return mfx

@greet
def hello():
    print("Hello world")

# hello()
# greet(hello)()

@greet
def add(a,b):
    print(a+b)
    

add(2,3)