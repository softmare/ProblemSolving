currectPair = {')':'(', ']':'['}
methodsForChar = {}
pushing = lambda c, stack : stack.append(c)
popping = lambda c, stack : True if len(stack) != 0 and currectPair[c] == stack.pop() else False
nothing = lambda c, stack : True
matching = lambda key, value, dict : dict.setdefault(key, value)
[matching(c, pushing, methodsForChar) for c in ['(','[']]
[matching(c, popping, methodsForChar) for c in [')',']']]

def isWellPairedSentance(sentance : str) -> bool :
    stack = []
    for c in sentance:
        if methodsForChar.get(c, nothing)(c, stack) == False:
            return False
    if len(stack) != 0:
        return False
    return True

while True:
    line = input()
    if line == '.':
        break
    if isWellPairedSentance(line):
        print("yes")
    else:
        print("no")

