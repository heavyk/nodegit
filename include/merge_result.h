#ifndef GITMERGERESULT_H
#define GITMERGERESULT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_merge_result {
};

using namespace node;
using namespace v8;

class GitMergeResult : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_merge_result *GetValue();
    git_merge_result **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitMergeResult(git_merge_result *raw, bool selfFreeing);
    ~GitMergeResult();
 
    static NAN_METHOD(JSNewFunction);

    git_merge_result *raw;
};

#endif
