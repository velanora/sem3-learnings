x = 1.2
n=7
S=0
for i in range(1,n+1):
    power =2*i-1
    j=1
    fac = 1
    while(j<=power):
        fac *= j
        j+= 1

    term = (x**power)/fac
    if(i%2== 1):
        S += term
    else:
        S -=term

print("Final value of sin ", S)