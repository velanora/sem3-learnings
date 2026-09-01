# Lab 3
# Question 3
member_type = "premimum"
bill = 3000
discount = 0.0
coupons = "SAVE10"
shipping = 0

match coupons:
    case "SAVE10":
        discount = 0.12
        bill -= (bill * discount)
    case "SUPER50":
        discount = 50.0;
    case _:
        discount = 0
        print("Invalid coupon code ")

if(member_type == "premimum" and bill>=1000):
    shipping = 0;
    print("Free shipping")
else:
    shipping = 100

total_bill = bill+ shipping

print(f"Total bill:{total_bill}")

