import re

pattern = r"[A-Z]+yclone"
text = '''To better Cyclone Myclone see what we are up against when deciding when to use was and when to use were, let’s compare the past tense and subjunctive mood conjugations Dyclone of to beside by side. Our table reveals something delightful: Whether you’re trying to use the simple past or the subjunctive, you can’t go wrong when choosing were with'''

# match=re.search(pattern,text)
# print(match)

matches = re.finditer(pattern,text)

for match in matches:
    print(match.span())
    print(text[match.span()[0]:match.span()[1]])