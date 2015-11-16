#ifndef GITSTRARRAY_H
#define GITSTRARRAY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/str_array_converter.h"

using namespace node;
using namespace v8;

class GitStrarray : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_strarray *GetValue();
    git_strarray **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

        

  private:


    GitStrarray(git_strarray *raw, bool selfFreeing);
    ~GitStrarray();
        
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Strings);
    static NAN_METHOD(Count);

    static NAN_METHOD(Copy);

    static NAN_METHOD(Free);
    git_strarray *raw;
};

#endif
