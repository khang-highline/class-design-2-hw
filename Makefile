CC = cl.exe
CFLAGS = /EHsc /c
LINK = link.exe
LDFLAGS = 
RM = rm -rf
SHELL = cmd.exe
.PHONY = all clean linecount

all: demo.exe

demo.exe: demo.obj web_url.obj camera_image.obj store.obj
	$(LINK) $(LDFLAGS) demo.obj web_url.obj camera_image.obj store.obj

demo.obj: demo.cpp
	$(CC) $(CFLAGS) demo.cpp

web_url.obj: web_url.cpp web_url.h
	$(CC) $(CFLAGS) web_url.cpp

camera_image.obj: camera_image.cpp camera_image.h
	$(CC) $(CFLAGS) camera_image.cpp

store.obj: store.cpp store.h
	$(CC) $(CFLAGS) store.cpp

linecount:
	wc -l *.cpp *.h

clean:
	$(RM) *.exe *.obj
