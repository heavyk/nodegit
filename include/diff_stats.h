#ifndef GITDIFFSTATS_H
#define GITDIFFSTATS_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_diff_stats {
};

using namespace node;
using namespace v8;

class GitDiffStats : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_stats *GetValue();
    git_diff_stats **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffStats(git_diff_stats *raw, bool selfFreeing);
    ~GitDiffStats();
 
    static NAN_METHOD(JSNewFunction);

    git_diff_stats *raw;
};

#endif
