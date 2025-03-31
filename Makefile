CC = g++
CFLAGS = -Wall -Wextra -std=c++11
TARGET_LIB = circular_list.o
TARGET_DEMO = demo
TARGET_TEST = test
TEST_LOG = testlog.txt

all: build_lib build_demo build_test

build_lib: circular_list.o

circular_list.o: circular_list.cpp circular_list.h
	$(CC) $(CFLAGS) -c circular_list.cpp -o circular_list.o

build_demo: build_lib demo.o
	$(CC) $(CFLAGS) demo.o circular_list.o -o $(TARGET_DEMO)

demo.o: demo.cpp circular_list.h
	$(CC) $(CFLAGS) -c demo.cpp -o demo.o

build_test: build_lib test.o
	$(CC) $(CFLAGS) test.o circular_list.o -o $(TARGET_TEST)

test.o: test.cpp circular_list.h
	$(CC) $(CFLAGS) -c test.cpp -o test.o

run_test: build_test
	./$(TARGET_TEST) > $(TEST_LOG) 2>&1
	cat $(TEST_LOG)

clean:
	rm -f *.o $(TARGET_DEMO) $(TARGET_TEST) $(TEST_LOG)

rebuild: clean all