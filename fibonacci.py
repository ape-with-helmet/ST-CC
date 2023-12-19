def fib(a):
    i=a
    if i==0 or i==1:
        return 1
    else:
        return fib(i-1)+fib(i-2)
a=int(input("Enter the limit: "))
i=0
while i>=0:
    r=fib(i)    
    if r>a:
        break
    print(r)
    i=i+1
    