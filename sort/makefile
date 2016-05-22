CC = g++ 
OBJS = main.o Sort.o 
TARGET = test 
 
.SUFFIXES : .cpp .o
  
all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	rm -f $(OBJS)
