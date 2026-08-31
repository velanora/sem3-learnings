# lab 3
# Question 1
units = int(input("Enter units:"))
temp=units bill =0 
if(units <= 100): 
    bill = units * 5 
elif (units <=200): 
    bill = (100 * 5) + ( (units-100)*8 ) 
else : 
    bill = (100 * 5) + (200 * 8)+ ( (units-200)*12 ) 
    
if( bill>2000): 
    bill *= 0.15 
    
print(f"Total Electricity bill: {bill}")
