#ifndef GITFETCH_H
#define GITFETCH_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/fetch_options.h"

using namespace node;
using namespace v8;

class GitFetch : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

     

  private:


     
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(InitOptions);
};

#endif
