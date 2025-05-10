
def gradingStudents(grades):
    # Write your code here
    rounded_grades = []
    for grade in grades:
        if grade < 38:
            rounded_grades.append(grade)
        else:
            next_multiple_of_5 = ((grade // 5) + 1) * 5
            if next_multiple_of_5 - grade < 3:
                rounded_grades.append(next_multiple_of_5)
            else:
                rounded_grades.append(grade)
    return rounded_grades
