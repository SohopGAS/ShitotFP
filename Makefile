CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Common/BorderType.o \
	Common/Button.o \
	Common/CheckList.o \
	Common/Combobox.o \
	Common/Control.o \
	Common/DoubleLineBorder.o \
	Common/EventEngine.o \
	Common/Graphics.o \
	Common/Label.o \
	Common/NumericBox.o \
	Common/Panel.o \
	Common/SingleLineBorder.o \
	Common/TextBox.o \
	FinalProject/Source.o \
	Common/RadioBox.o \
	Common/Message.o \
	#Common/MessageBox.o \
	Common/Logger.o \

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe
