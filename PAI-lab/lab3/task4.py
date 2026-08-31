# lab 3
# Question 4
correct_pin = 12345
entered_pin = 12345
balance = 4000
withdraw_amount = 1000
daily_limit = 1000

if(correct_pin == entered_pin):
    print("Correct Pin!!")
    if(withdraw_amount < balance):
        if(withdraw_amount > daily_limit):
            print("Daily with drawal limit exceed")
        else:
            balance -= withdraw_amount
            print(f"Withdrawal Amount {withdraw_amount}")
    else:
        print("Insufficent balance")
else:
    print("Incorrect Pin \nAccess denied")

print(f"Balance {balance}")

