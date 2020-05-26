CXXFLAGS = -Wall
CXX = g++
all:testAircrew scheduling
testAircrew: Aircrew.o testAircrew.o
	$(CXX) -o $@ $^
scheduling: Aircrew.o scheduling.o
	$(CXX) -o $@ $^
clean:
	rm -f scheduling testAircrew *.o