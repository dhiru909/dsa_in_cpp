def stringConstruction(s):
    p=''
    c=0
    for i in s:
        if i not in p:
            c+=1
            p=p+i
            
    return c
print(stringConstruction("aeae"))