from enum import Enum
import random
def Read(functional, strArray, i):
    if i >= len(strArray) - 3:
        return 0
    functional.append("functional")
    functional.append(float(strArray[i]))
    functional.append(int(strArray[i+1]))
    functional.append(Typification.STRICT if (int(strArray[i+2])) == 1 else Typification.DYNAMIC)
    functional.append(strArray[i+3] == 'True')
    i += 4
    return i

def GetRandom(functional):
    functional.append("functional")
    functional.append(round(random.randint(0,100)*0.1 + 1, 2))
    functional.append(1920 + random.randint(0,100))
    functional.append(Typification.STRICT if random.random() == 1 else Typification.DYNAMIC)
    functional.append(random.random() == 1)
    pass  

def Print(functional):
    print("It is Functional: typification = ", functional[3].name, ", is lazy calculations support = ", functional[4], 
    ", popularity = ", functional[1], ", year of creation = ", functional[2], ", GeneralFunction = ", GeneralFunction(functional))
    pass

def Write(functional, ostream):
    ostream.write("It is Functional: typification = {}, is lazy calculations support = {}, popularity = {}, year of creation = {}, GeneralFunction = {}".format(functional[3].name, functional[4], functional[1], functional[2], GeneralFunction(functional)))
    pass


def GeneralFunction(functional):
    return round(float(functional[2] / functional[1]), 4)
    pass
    
class Typification(Enum):
	STRICT = 1
	DYNAMIC = 2
