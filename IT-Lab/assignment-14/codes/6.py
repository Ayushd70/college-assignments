userinput = input(" Enter Comma separated numbers\n > ")
ui_list = userinput.split(",")
ui_list_int = []
for i in ui_list:
    ui_list_int.append(int(i))


def separate(seq, num):
    avg = len(seq) / float(num)
    out = []
    last = 0.0
    while last < len(seq):
        out.append(seq[int(last) : int(last + avg)])
        last += avg
    return out


final_input = separate(ui_list_int, 3)

matrix = final_input

transpose = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        transpose[j][i] = matrix[i][j]

for r in transpose:
    print(r)