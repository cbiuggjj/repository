CC := g++
LIBS += -lpthread
CPPFLAGS += -std=c++11 -g
cppsrc := $(shell find -name "*.cpp")
csrc += $(shell find -name "*.c")

obj := $(cppsrc:.cpp=.o)
obj += $(csrc:.c=.o)

target := lm.bin

all: $(target)

$(target): $(obj)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm *.o $(target) -rf
