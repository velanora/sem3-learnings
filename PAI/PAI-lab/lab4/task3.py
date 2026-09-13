max_start = 0
max_stepcounts = 0
for start in range (1,41):
    m = start
    stepcount =0
    while(m!=1):
        if(m%2 == 0): 
            m //= 2
        else:
            m = 3*m+1
        stepcount +=1 

    if(max_stepcounts < stepcount):
        max_stepcounts = stepcount
        max_start = start
  
       
print("starting value:", max_start)
print("maximum stepcount : ", max_stepcounts)
    
