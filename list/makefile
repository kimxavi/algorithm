CC = g++ 
OBJS = main.o arrayList.o list.o
TARGET = test 
 
.SUFFIXES : .cpp .o
  
all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	rm -f $(OBJS)
