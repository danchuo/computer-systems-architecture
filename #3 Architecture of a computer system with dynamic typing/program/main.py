import sys
import string
import timeit
from Extender import *

#----------------------------------------------

def isInt(value):
    try:
        int(value)
        return True
    except:
        return False

if __name__ == '__main__':
    if len(sys.argv) == 4:
        isRandomGeneration = False
        if (not isInt(sys.argv[1])):
            inputFileName  = sys.argv[1]
            outputFileName = sys.argv[2]
            sortedOutputFileName = sys.argv[3]
        else:
             numberOfRandom = int(sys.argv[1])
             if (numberOfRandom < 1 or numberOfRandom > 10000):
                 print("Number must be > 0 and < 10001")
                 exit()    
             else:
                 isRandomGeneration = True
                 outputFileName = sys.argv[2]
                 sortedOutputFileName = sys.argv[3]
    else:
        print("Incorrect command line! You must write: python main <inputFileName> <outputFileName> <sortedOutputFileName> or python main <numberOfRandomLanguages> <outputFileName> <sortedOutputFileName>")
        exit()

    if (not isRandomGeneration):
        ifile = open(inputFileName)
        str = ifile.read()
        ifile.close()
        strArray = str.replace("\n", " ").split(" ")
        
    cont = []
    
    if (isRandomGeneration):
        Container.RandomFill(cont, numberOfRandom)
    else:
        figNum = Container.Read(cont, strArray)
    
    Container.Print(cont)

    ofile = open(outputFileName, 'w')
    Container.Write(cont, ofile)
    ofile.close()
    
    ofile = open(sortedOutputFileName, 'w')
    Container.Write(Container.Quicksort(cont), ofile)
    ofile.close()
    
