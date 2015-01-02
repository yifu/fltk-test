#include <FL/Fl.H>
#include <FL/Fl_Window.H>
// #include <FL/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Input.H>
#include <iostream>

using namespace std;

// eval $(fltk-config --compile test.cpp)

int main(int argc, char *argv[])
{
   Fl_Window w (200, 200);
   // new Fl_Button(100, 100, 30, 30, "Okay");
   Fl_Box *box = new Fl_Box(10,10, 60,40, "Hello");
   box->box(FL_UP_BOX);
   box->labelfont(FL_BOLD);
   Fl_Input *input = new Fl_Input(40, 50, 60, 40, "label");
   input->value("Now...");
   w.end();
   w.show(argc, argv);
   Fl::run();
   cout << input->value() << endl;
   return 0;
}
