#ifndef GITDIFFDELTA_H
#define GITDIFFDELTA_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/diff_file.h"

using namespace node;
using namespace v8;

class GitDiffDelta : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_delta *GetValue();
    git_diff_delta **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffDelta(git_diff_delta *raw, bool selfFreeing);
    ~GitDiffDelta();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Status);
    static NAN_METHOD(Flags);
    static NAN_METHOD(Similarity);
    static NAN_METHOD(Nfiles);
    static NAN_METHOD(OldFile);
    static NAN_METHOD(NewFile);
    git_diff_delta *raw;
};

#endif
