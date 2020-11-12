def countCharacterType(str): 
  
    
    vowels = 0
    consonant = 0
    words = 0
    punctuation = 0
    
    for i in range(0, len(str)):  
          
        ch = str[i]  
  
        if ( (ch >= 'a' and ch <= 'z') or 
             (ch >= 'A' and ch <= 'Z') ):  
           
            ch = ch.lower() 
  
            if (ch == 'a' or ch == 'e' or ch == 'i' 
                        or ch == 'o' or ch == 'u'): 
                vowels += 1

            else: 
                consonant += 1
        if( ch=='!' or ch == '?' or ch == '.' or ch == ','):
            punctuation +=1
    li = str.split()
    words = len(li)
    print("Vowels:", vowels) 
    print("Consonant:", consonant)  
    print("Words:",words)
    print("Punctuation",punctuation)
stri = input("Enter the character")
countCharacterType(stri)