CC = g++ 
OBJS = Tree.o BPlusTree.o main.o
TARGET = test 
 
.SUFFIXES : .cpp .o
  
all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	rm -f $(OBJS)
