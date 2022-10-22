gcc -Wall -g -c DataFactory.c
gcc -Wall -g -c DataFactory.c
gcc -Wall -g -c MainDriver.c 
gcc -Wall -g -c PosterPrinter.c
gcc -Wall -g DataFactory.o DataFactory.h MainDriver.o PosterPrinter.c PosterPrinter.h -o Go
gcc -Wall -g -c MainDriver.c 
gcc -Wall -g DataFactory.o DataFactory.h MainDriver.o PosterPrinter.c PosterPrinter.h -o Go

clear

echo "PLease Run the ./Go file"
