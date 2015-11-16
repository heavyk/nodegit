#ifndef GITDIFFBINARY_H
#define GITDIFFBINARY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/diff_binary_file.h"

using namespace node;
using namespace v8;

class GitDiffBinary : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_binary *GetValue();
    git_diff_binary **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffBinary(git_diff_binary *raw, bool selfFreeing);
    ~GitDiffBinary();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(OldFile);
    static NAN_METHOD(NewFile);
    git_diff_binary *raw;
};

#endif
