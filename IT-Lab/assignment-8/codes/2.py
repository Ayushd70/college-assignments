def student_info(student_name, student_clss, student_subjects, student_dic):
    student_dic[student_name] = [student_clss, student_subjects]
    return student_dic


stu = dict()

while True:

    s = input(
        "Enter 'n' if you want to add a new student,enter 'any key 'if you want to finish: "
    )
    if s == "n":
        name = input("Student name: ")
        clss = input("Class: ")
        subjects = input("Subjects: ")
        print(student_info(name, clss, subjects, stu))
    else:
        break
