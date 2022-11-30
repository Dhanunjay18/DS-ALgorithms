import re

s = "Hi this is Dhanunjay9089"

x = '[a-zA-Z\d]+'

match = re.findall(x, s)

ss = "".join(match)
print(ss)




# ^ -> Starting Word 
# $ -> Ending Word
# . ^ $ * + ? { } [ ] \ | ( ) => METACHARACTERS

# x = re.compile('[a-zA-Z0-9\d]+')
# print(x)


# if(x.search(s)):
#     print('Yes')
# else:
#     print(x.search(s))
