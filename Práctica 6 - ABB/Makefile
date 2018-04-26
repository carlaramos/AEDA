MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
DNI = src/dni/
DNI_FILES = $(DNI)*.cpp
OUT = bin/
OUT_FILE = $(OUT)abb

dafault:

	g++  -std=c++11 $(MAIN_FILE) $(DNI_FILES) -o $(OUT_FILE)
	
app:

	$(OUT_FILE)
	
run: default app
