INPUT=c.cpp
OUTPUT=XScreenShow
FLAGS=-o
LINKS=-llept -ltesseract -lX11 -lXtst -lopencv_core -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_imgcodecs
CC=g++ -fconcepts -Wall
c: $(INPUT)
	$(CC) $(INPUT) $(FLAGS) $(OUTPUT) $(LINKS)
