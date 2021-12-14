from Extender import *
import random
def Read(cont, strArray):
    arrayLen = len(strArray)
    i = 0
    figNum = 0
    while i < arrayLen:
        str = strArray[i]
        if str == "procedural": 
            i += 1
            procedural = []   
            i = Procedural.Read(procedural, strArray, i)   
            cont.append(procedural)     
        elif str == "functional": 
            i += 1
            functional = []   
            i = Functional.Read(functional, strArray, i)  
            cont.append(functional)    
        elif str == "objectOriented": 
            i += 1
            objectOriented = []   
            i = ObjectOriented.Read(objectOriented, strArray, i)
            cont.append(objectOriented)
        else:
            return figNum
        if i == 0:
            return figNum
        figNum += 1
    return figNum

def RandomFill(cont, number):
	for i in range(number):
           key = random.randint(1,3)
           if key == 1:
               procedural = []   
               Procedural.GetRandom(procedural)   
               cont.append(procedural) 
           elif key == 2:
               functional = []   
               Functional.GetRandom(functional)   
               cont.append(functional) 
           elif key == 3:
               objectOriented = []   
               ObjectOriented.GetRandom(objectOriented)   
               cont.append(objectOriented) 
	pass


def Print(cont):
    print("Container stores", len(cont), "languages:")
    for language in cont:
        if language[0] == "procedural":
            Procedural.Print(language)
        elif language[0] == "functional":
            Functional.Print(language)
        elif language[0] == "objectOriented":
            ObjectOriented.Print(language)
        else:
            print("Incorrect figure ", language)
    pass

def Write(cont, ostream):
    ostream.write("Container stores {} languages:\n".format(len(cont)))
    for language in cont:
        if language[0] == "procedural":
            Procedural.Write(language, ostream)
        elif language[0] == "functional":
            Functional.Write(language, ostream)
        elif language[0] == "objectOriented":
            ObjectOriented.Write(language, ostream)    
        else:
            ostream.write("Incorrect figure ")
            ostream.write(language)
        ostream.write("\n")
    pass

def Quicksort(cont):
    if cont: 
        pivot = cont[0]
        below = [i for i in cont[1:] if Procedural.GeneralFunction(i) < Procedural.GeneralFunction(pivot)] 
        above = [i for i in cont[1:] if Procedural.GeneralFunction(i) >= Procedural.GeneralFunction(pivot)]
        return Quicksort(below) + [pivot] + Quicksort(above)
    else: 
        return cont        
