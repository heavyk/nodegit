#ifndef GITGITERR_H
#define GITGITERR_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/error.h"

using namespace node;
using namespace v8;

class GitGiterr : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

              

  private:


              
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(GiterrClear);

    static NAN_METHOD(GiterrDetach);

    static NAN_METHOD(GiterrLast);

    static NAN_METHOD(GiterrSetOom);

    static NAN_METHOD(GiterrSetStr);
};

#endif
