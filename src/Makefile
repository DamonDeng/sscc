# Makefile of cpp program
#

CC = g++
INCLUDES:=.

all: sscc_all


sscc_all: sscc_build
	../bin/sscc

sscc_build: *.cpp *.h
	$(CC) -lglog -lcurl -Iinclude *.cpp -o ../bin/sscc
