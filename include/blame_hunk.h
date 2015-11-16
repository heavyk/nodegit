#ifndef GITBLAMEHUNK_H
#define GITBLAMEHUNK_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/signature.h"

using namespace node;
using namespace v8;

class GitBlameHunk : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_blame_hunk *GetValue();
    git_blame_hunk **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitBlameHunk(git_blame_hunk *raw, bool selfFreeing);
    ~GitBlameHunk();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(LinesInHunk);
    static NAN_METHOD(FinalCommitId);
    static NAN_METHOD(FinalStartLineNumber);
    static NAN_METHOD(FinalSignature);
    static NAN_METHOD(OrigCommitId);
    static NAN_METHOD(OrigPath);
    static NAN_METHOD(OrigStartLineNumber);
    static NAN_METHOD(OrigSignature);
    git_blame_hunk *raw;
};

#endif
