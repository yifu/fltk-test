#include <FL/Fl.H>
#include <FL/Fl_Window.H>
// #include <FL/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Input.H>
#include <iostream>
#include <Fl/Fl_Text_Editor.H>
#include <Fl/Fl_Text_Buffer.H>

using namespace std;

// eval $(fltk-config --compile test.cpp)

void changed_cb(int pos, int nInserted, int nDeleted,
                int nRestyled, const char* deletedText,
                void* cbArg)
{
    Fl_Text_Buffer *buf = (Fl_Text_Buffer*)cbArg;
    buf->savefile("/tmp/test.txt");
}

int main(int argc, char *argv[])
{
   Fl_Window w (600, 400);

   Fl_Text_Editor *ed = new Fl_Text_Editor(5, 5, 590, 390, "editor");
   Fl_Text_Buffer *textBuf = new Fl_Text_Buffer();
   textBuf->add_modify_callback(changed_cb, textBuf/*cbArg*/);
   ed->buffer(textBuf);
   ed->textfont(FL_COURIER);

   w.end();
   w.show(argc, argv);
   Fl::run();
   cout << textBuf->text() << endl;
   return 0;
}
