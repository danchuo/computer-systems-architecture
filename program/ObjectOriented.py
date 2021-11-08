from enum import Enum
import random
def Read(objectOriented, strArray, i):
    if i >= len(strArray) - 2:
        return 0
    objectOriented.append("objectOriented")
    objectOriented.append(float(strArray[i]))
    objectOriented.append(int(strArray[i+1]))
    objectOriented.append(Inheritance.SINGLE if (int(strArray[i+2])) == 1 else (Inheritance.MULTIPLE if (int(strArray[i+2])) == 2 else Inheritance.INTERFACE))
    i += 3
    return i
    
def GetRandom(objectOriented):
    objectOriented.append("objectOriented")
    objectOriented.append(round(random.randint(0,100)*0.1 + 1, 3))
    objectOriented.append(1920 + random.randint(0,100))
    randomTemp = random.randint(1,3)
    objectOriented.append(Inheritance.SINGLE if randomTemp == 1 else (Inheritance.MULTIPLE if randomTemp == 2 else Inheritance.INTERFACE))
    pass       

def Print(objectOriented):
    print("It is ObjectOriented: inheritance = ", objectOriented[3].name,  
    ", popularity = ", objectOriented[1],", year of creation = ", objectOriented[2], ", GeneralFunction = ", GeneralFunction(objectOriented))
    pass

def Write(objectOriented, ostream):
    ostream.write("It is ObjectOriented: inheritance = {}, popularity = {}, year of creation = {}, GeneralFunction = {}".format(objectOriented[3].name, objectOriented[1], objectOriented[2], GeneralFunction(objectOriented)))
    pass

def GeneralFunction(objectOriented):
    return round(float(objectOriented[2] / objectOriented[1]), 4)
    pass
    
class Inheritance(Enum):
	SINGLE = 1
	MULTIPLE = 2
	INTERFACE = 3
