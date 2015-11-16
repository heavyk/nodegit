#ifndef GITDIFFFILE_H
#define GITDIFFFILE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"

using namespace node;
using namespace v8;

class GitDiffFile : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_file *GetValue();
    git_diff_file **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffFile(git_diff_file *raw, bool selfFreeing);
    ~GitDiffFile();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Id);
    static NAN_METHOD(Path);
    static NAN_METHOD(Size);
    static NAN_METHOD(Flags);
    static NAN_METHOD(Mode);
    git_diff_file *raw;
};

#endif
