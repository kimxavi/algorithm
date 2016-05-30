LN = ln
AR = ar
CP = cp
CC = g++

GOMTV_HOME = /home/devel/gomtv
GOMTV_INC = -I $(GOMTV_HOME)/include

INCLUDE = $(GOMTV_INC)

#CFLAGS = -c -Wall -g
CFLAGS = -c -Wall -O2 -D_REENTRANT
OFLAGS =
ARCMD = rv
OBJ_DIR = OBJS

OBJS_ = dateTime.o intStack.o intArray.o longArray.o 
OBJS_+= intWArray.o int2WArray.o intLArray.o intQueue.o 
OBJS_+= intSArray.o intSHash.o
OBJS_+= intHash.o intWHash.o int2WHash.o longWArray.o
OBJS_+= charArray.o strArray.o strQueue.o cpArray.o
OBJS_+= strWArray.o strLArray.o strWHash.o strSArray.o strSHash.o 
OBJS_+= strIntArray.o idStrArray.o idVoidArray.o idVoidHash.o 
OBJS_+= intTimeArray.o intTimeHash.o ptrArray.o argList.o 
OBJS_+= popio.o configMan.o weekCount.o 
OBJS_+= regCheck.o regCheckMan.o safeBuffer.o textProto.o textEncoder.o 
OBJS_+= spaceProto.o fileCache.o nameValue.o nvList.o
OBJS_+= line.o postStr.o date.o procTime.o dateUtil.o bin.o binQueue.o
OBJS_+= ddArray.o dddArray.o dsArray.o dssArray.o ddsArray.o ddssArray.o ddsssArray.o dsssArray.o
OBJS_+= ddddddddArray.o dddddddArray.o ddddddArray.o dddddArray.o ddddArray.o ddList.o dddList.o
OBJS_+= ddtArray.o dddsArray.o ddddssArray.o ddddsArray.o ssArray.o sstrArray.o sstArray.o intOrder.o 
OBJS_+= dddddsArray.o dddssArray.o dddsssArray.o ddddsssArray.o ddddddssArray.o
OBJS_+= ddddddsArray.o dddddddsArray.o ddddddsssArray.o dddddssArray.o ddddddddsArray.o dddddddddArray.o dddddddddsArray.o ddddddddddsArray.o ddddddlArrray.o
OBJS_+= strUtil.o scriptMan.o errLog.o GString.o mystrtok.o 
OBJS_+= postReader.o postDecoder.o postEncoder.o csvDecoder.o blowfish.o 
OBJS_+= urlDecoder.o urlUtil.o urlEncoder.o eastStr.o dbdataArray.o porterstem.o
OBJS_+= lfArray.o llArray.o lllArray.o ddllArray.o ddlllArray.o ddllllArray.o sssArray.o ssssArray.o lsArray.o lllsArray.o dlllArray.o dllArray.o dlArray.o llllArray.o 
OBJS_+= checkValue.o strJaso.o

#OBJS_+= popErr.o
#OBJS_+= duoIntArray.o GList.o duoStrArray.o Date.o SLSource.o ddstrArray.o dstrArray.o popStr.o 

OBJS = ${OBJS_:%=${OBJ_DIR}/%}

all: libgen.a

libgen.a : $(OBJS)
	$(AR) $(ARCMD) $@ $?
	$(CP) -f $@ ../../lib/$@

.SUFFIXES:
.SUFFIXES: .o .cc .c

#.cc.o:
#	$(CC) $(CFLAGS) $(INCLUDE) $<

$(OBJ_DIR)/%.o : %.cc
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $<

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $<


clean:
	rm -f libgen.a
	rm -f ./OBJS/*.o
