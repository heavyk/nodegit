#ifndef GITDIFFLINE_H
#define GITDIFFLINE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitDiffLine : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_line *GetValue();
    git_diff_line **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffLine(git_diff_line *raw, bool selfFreeing);
    ~GitDiffLine();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Origin);
    static NAN_METHOD(OldLineno);
    static NAN_METHOD(NewLineno);
    static NAN_METHOD(NumLines);
    static NAN_METHOD(ContentLen);
    static NAN_METHOD(ContentOffset);
    static NAN_METHOD(Content);
    git_diff_line *raw;
};

#endif
