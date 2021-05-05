def input_dfa():
    q = int(input("\nEnter the total no. of states in the DFA: "))
    a = int(input("\nEnter the total no. of alphabets used: "))
    A = []
    for i in range(a):
        A.append(input(f"Enter alphabet {i+1}: "))

    t = {}
    for state in range(1, q+1):
        print(f"\n---For State {state}---")
        for alphabet in A:
            t[f"{state}{alphabet}"] = input(f"Next State when input is '{alphabet}': ")
    
    q0 = input("\nEnter the Start State: ")
    
    n = int(input("\nEnter the no. of final states: "))
    f = []
    for i in range(n):
        f.append(input(f"Enter final state {i+1}: "))

    print("\n----DFA created successfully!----")
    dfa = (q, A, t, q0, f)
    # print(dfa)
    return dfa


def check(s, dfa):
    transitions = dfa[2]
    current_state = dfa[3]
    for letter in s:
        current_state = transitions[current_state+letter]

    if current_state in dfa[4]: print("ACCEPTED")
    else: print("REJECTED")


def is_valid(test):
    for letter in test:
        if letter not in DFA[1]:
            print(f"Invalid input!")
            test = 0 
            break
    if test == 0: return False
    else : return True   


DFA = input_dfa()
test_str = '1'
while test_str != '-1':
    test_str = input("\nEnter a string to test, -1 to exit: ")
    if test_str != '-1' and is_valid(test_str):
        check(test_str, DFA)
print("\nTHANK YOU!\n")