#
# Makefile för plot
#
# Fungerar även för -std=c++98. Använder inget som på IDAs Solarissystem annars
# kan kräva att LDFLAGS också anger -L/sw/gcc-${GCC4_V}/lib och -static-libstdc++.
#
CCC      = g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
LDFLAGS += -lcurses

# Kommandot 'make', eller 'make info', ger information om alternativen.
info:
	@ echo "Kommandot 'make plot' komplierar plot.cc"
	@ echo "Kommandot 'make clean' tar bort exekverbara program och objektkodsfiler"
	@ echo "Kommandot 'make zap' tar dessutom bort reservkopior (~ sist i namnet)"

# Kommandot 'make plot' kompilerar plot.cc och producerar 'plot'.
plot: plot.cc Direction.h Direction.cc
	$(CCC) $(CCFLAGS) -o plot plot.cc Direction.cc $(LDFLAGS)
	@ echo "Exekvera programmet med kommandot './plot <indatafil>'"

# Kommandot 'make clean' ta bort 'plot', 'a.out' och objektkodsfiler (suffix .o).
clean:
	@ \rm -f plot a.out *.o

# Kommandot 'make zap' tar även bort reservkopior (filnamn med ~ sist).
zap: clean
	@ \rm -f *~
