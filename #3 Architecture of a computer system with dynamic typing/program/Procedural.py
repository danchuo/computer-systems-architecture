import random
def Read(procedural, strArray, i):
    if i >= len(strArray) - 2:
        return 0
    procedural.append("procedural")
    procedural.append(float(strArray[i]))
    procedural.append(int(strArray[i+1]))
    procedural.append(strArray[i+2] == 'True')
    i += 3
    return i

def GetRandom(procedural):
    procedural.append("procedural")
    procedural.append(round(random.randint(0,100)*0.1 + 1, 2))
    procedural.append(1920 + random.randint(0,100))
    procedural.append(random.random() == 1)
    pass

def Print(procedural):
    print("It is Procedural: are abstract types present = ", procedural[3],  
    ", popularity = ", procedural[1],", year of creation = ", procedural[2], ", GeneralFunction = ", GeneralFunction(procedural))
    pass

def Write(procedural, ostream):
    ostream.write("It is Procedural: are abstract types present = {}, popularity = {}, year of creation = {}, GeneralFunction = {}".format(procedural[3], procedural[1], procedural[2], GeneralFunction(procedural)))
    pass

def GeneralFunction(procedural):
    return round(float(procedural[2] / procedural[1]), 4)
    pass
