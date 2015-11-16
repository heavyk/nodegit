#ifndef GITDIFFPERFDATA_H
#define GITDIFFPERFDATA_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/sys/diff.h>
}


using namespace node;
using namespace v8;

class GitDiffPerfdata : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_perfdata *GetValue();
    git_diff_perfdata **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffPerfdata(git_diff_perfdata *raw, bool selfFreeing);
    ~GitDiffPerfdata();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Version);
    static NAN_METHOD(StatCalls);
    static NAN_METHOD(OidCalculations);
    git_diff_perfdata *raw;
};

#endif
