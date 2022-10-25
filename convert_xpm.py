new_xpm = ""

with open("./images/p5.xpm", 'r') as f:
    li = f.readlines();
    for i in range(74):
        new_xpm += li[i]
    for i in range(74, len(li)):
        line = list(li[i])
        inside = 0
        c = "R"
        for j in range(1, len(line) - 3):
            if inside == 0 and line[j] != c:
                inside = 1
            elif inside == 1 and line[j] == c:
                inside = 2
            elif inside == 2 and line[j] != c:
                inside = 1
            if inside == 2 and line[j] == c:
                line[j] = '~'
        for j in range(len(line) - 4, 1, -1):
            if line[j] != '~':
                break
            else:
                line[j] = c
        new_xpm += "".join(line)

with open("./tp5.xpm", 'w') as f:
    f.write(new_xpm)