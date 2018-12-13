target := lm.bin
all: $(target)

CC := g++
LIBS += -lpthread
CPPFLAGS += -std=c++11 -g
cppsrc := $(shell find -name "*.cpp")
csrc += $(shell find -name "*.c")

dep := $(src:.cpp=.d)
-include $(dep)
%.d: %.cpp
	$(CC) -MM $< > $@

obj := $(cppsrc:.cpp=.o)


$(target): $(obj) cJSON.o
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm *.o $(target) -rf
