AM_CPPFLAGS = -I$(prefix)/include -I/usr/include -I../include

AM_CXXFLAGS = -Wall \
	-Werror \
	-g

glue_LDFLAGS = -L$(prefix)/lib -L/usr/lib
glue_LDADD = $(GLUE_LIBS)

glue_SOURCES =	serial.cc \
	app.cc

bin_PROGRAMS = glue
