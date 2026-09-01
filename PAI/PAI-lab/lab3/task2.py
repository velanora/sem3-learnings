# Lab 3 
# Question 2
has_disciplinary_issues = False 
marks = 90 
attendance = 85 
scholarship = 0 
is_sport_student = True 
if( not has_disciplinary_issues): 
    if(marks >= 90 and attendance>= 85):
        scholarship = 100 
        print(f"Full Scholarship : {scholarship}%") 
    elif ( (marks>= 75 and attendance>= 80 ) or (is_sport_student == True and attendance >=75)): 
        scholarship = 50 
        print(f"Half Scholarship : {scholarship}%") 
    else : 
        print("No scholarship granted!") 
else: print(" Scholarship denied due to disciplinary Record")
