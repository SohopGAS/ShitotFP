CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Common/Control.o Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Common/Label.o Common/Panel.o Common/TextBox.o Common/Logger.o

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe
