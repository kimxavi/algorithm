CC = g++ 
OBJS = main.o LinkedList.o ArrayList.o List.o Stack.o Queue.o
TARGET = test 
 
.SUFFIXES : .cpp .o
  
all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	rm -f $(OBJS)
