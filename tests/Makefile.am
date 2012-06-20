AM_CPPFLAGS = -I$(prefix)/include -I/usr/include

AM_CXXFLAGS = -Wall \
	-Werror \
	-g

writer_LDFLAGS = -L$(prefix)/lib -L/usr/lib
writer_LDADD = $(GLUE_LIBS)
writer_SOURCES = $(prefix)/src/serial.cc \
	app_writer.cc

reader_LDFLAGS = -L$(prefix)/lib -L/usr/lib
reader_LDADD = $(GLUE_LIBS)
reader_SOURCES = $(prefix)/src/serial.cc \
	app_reader.cc

cipher_LDFLAGS = -L$(prefix)/lib -L/usr/lib
cipher_LDADD = $(GLUE_LIBS)
cipher_LIBS = -lcrypto++ -lpthread
cipher_SOURCES = $(prefix)/src/cipher.cc \
	app_cipher.cc

bin_PROGRAMS = writer reader cipher
