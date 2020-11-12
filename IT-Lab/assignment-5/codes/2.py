def nonFibonacci(n): 
  
    
    prevPrev = 1
    prev = 2
    curr = 3
  
    
    while n > 0: 
        prevPrev = prev 
        prev = curr 
        curr = prevPrev + prev 
          
        
        n = n - (curr - prev - 1) 
      
    
    return prev + n 

li = list(int(input("Enter the numbers")))
i=0
while(i<li[1]):
  nonFibonacci(i)
  i+=1