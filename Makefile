CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
<<<<<<< HEAD
OBJS += Common/Control.o \
	Common/EventEngine.o \
	Common/Graphics.o \
	FinalProject/Source.o \
	Common/Label.o \
	Common/Panel.o \
	Common/TextBox.o \
	Common/Logger.o \
	Common/CheckList.o \
	Common/Button.o \
	Common/SingleLineBorder.o \
	Common/DoubleLineBorder.o \
	Common/BorderType.o \
	Common/Combobox.o \
=======
OBJS += Common/Control.o Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Common/Label.o Common/Panel.o Common/TextBox.o Common/NumericBox.o Common/MessageBox.o Common/RadioBox.o Common/CheckList.o
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe
