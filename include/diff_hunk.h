#ifndef GITDIFFHUNK_H
#define GITDIFFHUNK_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitDiffHunk : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_hunk *GetValue();
    git_diff_hunk **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffHunk(git_diff_hunk *raw, bool selfFreeing);
    ~GitDiffHunk();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(OldStart);
    static NAN_METHOD(OldLines);
    static NAN_METHOD(NewStart);
    static NAN_METHOD(NewLines);
    static NAN_METHOD(HeaderLen);
    static NAN_METHOD(Header);
    git_diff_hunk *raw;
};

#endif
