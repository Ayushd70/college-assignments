package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type DFA struct {
	state_numbers int
	Alphabets     []string
	t             map[string]string
	q0            string
	final_states  []string
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	dfa := &DFA{}
	dfa.createDfa()

	for {
		fmt.Println("Enter a string to test, -1 to exit.")
		scanner.Scan()
		test_str := scanner.Text()
		if test_str == "-1" && dfa.isValid(test_str) {
			os.Exit(1)
		} else {
			dfa.check(test_str, dfa)
		}
	}
}

func (d *DFA) createDfa() *DFA {
	state := map[string]string{}
	scanner := bufio.NewScanner(os.Stdin)

	fmt.Println("Enter total no. of states in DFA.")
	scanner.Scan()
	d.state_numbers, _ = strconv.Atoi(scanner.Text())

	fmt.Println("Enter total no. of alphabets in DFA.")
	scanner.Scan()
	na, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < na; i++ {
		fmt.Println("Enter alphabet " + strconv.Itoa((i + 1)) + ": ")
		scanner.Scan()
		d.Alphabets = append(d.Alphabets, scanner.Text())
	}

	for i := 1; i < d.state_numbers+1; i++ {
		fmt.Println("--- For State " + strconv.Itoa(i) + " ---")
		for _, alpha := range d.Alphabets {
			fmt.Println("Next state when input is " + alpha + ": ")
			scanner.Scan()
			state[strconv.Itoa(i)+alpha] = scanner.Text()
		}
	}

	d.t = make(map[string]string)
	for k, v := range state {
		d.t[k] = v
	}

	fmt.Println("Enter the start state: ")
	scanner.Scan()
	d.q0 = scanner.Text()

	fmt.Println("Enter the number of final states: ")
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < n; i++ {
		fmt.Println("Enter final state ", i+1)
		scanner.Scan()
		d.final_states = append(d.final_states, scanner.Text())
	}

	fmt.Println("----DFA created successfully!----")

	return d
}

func (d *DFA) isValid(test string) bool {
	for _, l := range test {
		for _, v := range d.Alphabets {
			if string(l) != v {
				test = "0"
				break
			}
		}
	}
	if test == "0" {
		os.Exit(0)
	}
	return true
}

func (d *DFA) check(s string, dfa *DFA) {
	transitions := d.t
	current_state := d.q0
	fmt.Println("Current state: ", current_state)

	accepted := false

	for _, l := range s {
		current_state = transitions[current_state+string(l)]
	}

	for _, val := range d.final_states {
		if current_state == val {
			print("Accepted")
			accepted = true
		}
	}

	if accepted == false {
		fmt.Println("REJECTED")
	}

}
