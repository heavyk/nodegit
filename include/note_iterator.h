#ifndef GITNOTEITERATOR_H
#define GITNOTEITERATOR_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitNoteIterator : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_note_iterator *GetValue();
    git_note_iterator **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitNoteIterator(git_note_iterator *raw, bool selfFreeing);
    ~GitNoteIterator();
 
    static NAN_METHOD(JSNewFunction);

    git_note_iterator *raw;
};

#endif
