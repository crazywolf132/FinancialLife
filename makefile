CC=g++
CFLAGS=-I.

all: account.o expense.o income.o financiallife.o
	$(CC) -o account.o expense.o income.o financiallife.o

clean:
	rm -rf ./*.o
	rm -rf ./finance