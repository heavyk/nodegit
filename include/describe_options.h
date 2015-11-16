#ifndef GITDESCRIBEOPTIONS_H
#define GITDESCRIBEOPTIONS_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitDescribeOptions : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_describe_options *GetValue();
    git_describe_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDescribeOptions(git_describe_options *raw, bool selfFreeing);
    ~GitDescribeOptions();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Version);
    static NAN_METHOD(MaxCandidatesTags);
    static NAN_METHOD(DescribeStrategy);
    static NAN_METHOD(Pattern);
    static NAN_METHOD(OnlyFollowFirstParent);
    static NAN_METHOD(ShowCommitOidAsFallback);
    git_describe_options *raw;
};

#endif
