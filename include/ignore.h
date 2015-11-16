#ifndef GITIGNORE_H
#define GITIGNORE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"

using namespace node;
using namespace v8;

class GitIgnore : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

             

  private:


             
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(AddRule);

    static NAN_METHOD(ClearInternalRules);

    static NAN_METHOD(PathIsIgnored);
};

#endif
