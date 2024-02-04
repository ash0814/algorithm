str = input()
ret = ""
for c in str :
    if c.islower() == True:
        ret += c.upper()
    else:
        ret += c.lower()
    
print(ret)